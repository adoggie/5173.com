# -*- coding:utf-8 -*-

import sys, traceback,threading,time,struct,base64,zlib
import psycopg2
import socket

CNM_BASE_ID =0x100
CNM_ECHOIP_REQ=CNM_BASE_ID		 		#rdserver -> dispatcher
CNM_ECHOIP_RESP=CNM_BASE_ID+1 		#dispatcher ->rdserver
CNM_RDSERVER_STATUS=CNM_BASE_ID+2	#rdserver->dispatcher 定时上报状态
CNM_RDSERVER_SET=CNM_BASE_ID+3		#dispatcher ->rdserver 


class MessageBase:
	def __init__(self,id):
		self.id=id
	
	def decode(self,msg):
		try:
			(self.id,) = struct.unpack('H',msg[:2])
		except:
			print traceback.print_exc()
			return False
		return True
	
	def encode(self):
		#序列化
		bytes= struct.pack('H',self.id)
		return bytes
	
	def final(self):
		bytes = struct.pack('I',len(self.encode()))
		bytes+=self.encode()
		return bytes

	@staticmethod
	def size():
		return 2

class MessageEchoIpReq(MessageBase):
	def __init__(self):
		MessageBase.__init__(self,CNM_ECHOIP_REQ)

class MessageEchoIpResp(MessageBase):
	def __init__(self):
		MessageBase.__init__(self,CNM_ECHOIP_RESP)
		self.ip=0	#公网地址(网络字节)
	
	def encode(self):
		bytes = MessageBase.encode(self)
		bytes+=self.ip		
		return bytes
	
	@staticmethod
	def size():		
		return 4+MessageBase.size()

class MessageRdServerStatus(MessageBase):
	def __init__(self):
		MessageBase.__init__(self,CNM_RDSERVER_STATUS)
		self.tick=0	#公网地址(网络字节)
		self.conNum=0 #当前连接数
		self.ipaddr=0
		self.port=0
		self.rptinterval=0
		self.mac=''		
		self.hostname=''
		self.vendor=''  #发布者 
		
	def decode(self,msg):
		try:
			MessageBase.decode(self,msg)
			msg=msg[2:]
			self.tick,self.conNum,\
			self.ipaddr,self.port,\
			self.rptinterval = struct.unpack('IIIHH',msg[:16])
			msg = msg[16:]
			(len,) = struct.unpack('B',msg[0])
			self.mac= msg[1:len+1]
			msg = msg[len+1:]
			(len,) = struct.unpack('B',msg[0])
			self.hostname = msg[1:len+1]
			msg = msg[len+1:]
			(len,) = struct.unpack('B',msg[0])
			self.vendor = msg[1:len+1]
			print self.mac,self.hostname,self.vendor
		except:
			print traceback.print_exc()
			return False
		return True

class MessageRdServerSet(MessageBase):
	def __init__(self):
		self.mask=0
		self.rptInterval=0		#定时状态上报间隔
	
	def encode(self):
		bytes = MessageBase.encode(self)
		bytes+=struct.pack('II',self.mask,self.rptInterval)		
		return bytes

##==========================================================================

class ProcessThread(threading.Thread):
	def __init__(self,server):
		threading.Thread.__init__(self)
		self.mtx = threading.Lock()
		self.server = server
		
	#thread Entry...
	def run(self):
		#self.mtx.acquire()
		#ProcessThread.NO+=1
		#print 'Udp Thread <%s> Started!'%ProcessThread.NO
		#self.mtx.release()
		while True:
			self.server.process(self)
		
	NO=0
	

class UdpServer:
	def __init__(self,server):
		self.server = server
		self.msglist = []
		self.threads=[]
		self.mtx_thread = threading.Lock()
		self.sock=None
		
	def getDBConn(self):	return self.server.getDBConn()
	def resetDBConn(self): return self.server.resetDBConn()
	def getLogger(self): return self.server.getLogger()
	
	def start(self):
		try:
			self.sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
			listenport = self.server.getPropertyIntValue('udpserver.port')
			host = self.server.getPropertyValue('udpserver.host')
			if host=='any': host=''		
			self.sock.bind((host,listenport))
			
			numThreads = self.server.getPropertyIntValue('udpserver.threadnum')
			for n in range(numThreads):
				t = ProcessThread(self)
				t.start()
		except:
			self.getLogger().error(traceback.format_exc())
			return False
		return True
	
	def decrypt(self,data):
		return data
	
	def encrypt(self,data):
		return data

	def process(self,t):
		#处理数据入口
		
		self.mtx_thread.acquire()
		dgram,addr = self.sock.recvfrom(1024)
		self.mtx_thread.release()
		data = self.decrypt(dgram)
		self.parseMessage(data,addr)
	
	def parseMessage(self,data,peerAddr):
		
		if not data: return
		try:
			
			print data,peerAddr
			
			(size,) = struct.unpack('I',data[:4])
			if len(data)!=size+4:
				return
			data=data[4:]
			(msgid,) = struct.unpack('H',data[:2])
			print msgid
			msg = None
			if msgid == CNM_ECHOIP_REQ:
				msg = MessageEchoIpReq()
				
				if msg.decode(data):
					print 'CNM_ECHOIP_REQ'
					resp = MessageEchoIpResp()
					ip = socket.inet_aton(peerAddr[0])
					resp.ip = ip #struct.pack('I',ip)
					
					bytes = resp.final()
					#print len(bytes)
					
					self.sock.sendto(bytes,peerAddr) # Echo Ip Response
			if msgid == CNM_RDSERVER_STATUS:
				msg = MessageRdServerStatus()
				if msg.decode(data):
					print 'CNM_RDSERVER_STATUS'
					#记录转发服务器的信息到数据
					self.process_RdSeerverMessage(msg)
					
		except:
			self.getLogger().error(traceback.format_exc())
	
	#更新Rdserver状态信息
	def process_RdSeerverMessage(self,msg):
		try:
			cr = self.getDBConn().cursor()
			sql="select count(*) from rdserver where mac=%s"
			cr.execute(sql,(msg.mac,))
			rs = cr.fetchone()
			print 'ip:',msg.ipaddr
			ipstr = socket.inet_ntoa(struct.pack('I',msg.ipaddr))
			
			port = socket.ntohs(msg.port)
			
			if rs[0]:
				#do update
				sql="UPDATE rdserver SET ip=%s, ipnum=%s port=%s,  \
								status_tick=%s, conn_num=%s, \
								hostname=%s, status_interval=%s ,vendor=%s \
								WHERE mac = %s;"
				cr.execute(sql,(ipstr,msg.ipaddr,port,int(time.time()),msg.conNum,msg.hostname,msg.rptinterval,msg.mac,msg.vendor,))
			else:
				sql="INSERT INTO rdserver(\
							mac, ip, ipnum, port, qos, qos_tick, status_tick, conn_num, hostname,\
							status_interval,vendor) \
							VALUES (%s,%s,%s,0,0,%s,%s,%s,%s,%s);"
				cr.execute(sql,(msg.mac,ipstr,msg.ipaddr,port,int(time.time()),msg.conNum,msg.hostname,msg.rptinterval,msg.vendor,))
				#cr.execute(sql,(msg.mac,ipstr,))
			sql ="INSERT INTO rdserver_status(mac, ip, port, status_tick, conn_num, status_interval) VALUES (%s, %s, %s, %s, %s, %s);"
			cr.execute(sql,(msg.mac,ipstr,port,int(time.time()),msg.conNum,msg.rptinterval,))
			self.getDBConn().commit()
		except:
			self.resetDBConn()
			self.getLogger().error(traceback.format_exc())
	
	


