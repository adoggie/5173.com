# -*- coding:utf-8 -*-

# revisions:
##wait udp income
# recieve datagram
# split fields with colon 
# write to regular file and database
# redirect to monitor app
#      format:  (GRL,IP,BASE64MSG)
#  分发到Monitor需以(GRL,IP,BASE64MSG)编码



import traceback,threading,time,struct,os,os.path,shutil,distutils.dir_util,array,base64,zlib,struct,binascii
import copy,socket,select,string
import config
import pymssql
import setclock

VERSION=''

'''
SQL
-------
CREATE TABLE [dbo].[GRL_RESULT] (
  [id] bigint IDENTITY(1, 1) NOT NULL,
  [no] varchar(32) NOT NULL,
  [gameid] int NOT NULL,
  [type] int NOT NULL,
  [result] int NOT NULL,
  [detail] varchar(max) NULL,
  [ip] char(32) NOT NULL,
  [time] datetime NOT NULL,
  [elapsed] int NOT NULL,
  PRIMARY KEY CLUSTERED ([id])
)
GO

CREATE TABLE [dbo].[GRL_UNKNOWN] (
  [id] bigint IDENTITY(1, 1) NOT NULL,
  [no] varchar(32) NOT NULL,[gameid] int NOT NULL,
  [detail] varchar(max) NULL,
  [ip] char(32) NOT NULL,
  [time] datetime NOT NULL,
  PRIMARY KEY CLUSTERED ([id])
)
GO
'''

PACKETHDR=['SIGN','VERSION','TYPE','PERSIST','TIME','ENCODE']
#
class GtrLogPacket:	
	def __init__(self,app,msg,peer):
		self.app = app
		self.msg = msg
		self.peer = peer
		self.peerip = peer[0]
		
	
	def errMsg(self):
		print 'invalid packet(%s):%s'%(str(self.peer),self.msg)
	
	def parse(self):
		r = False
		try:
			self.attrs={}
			self.tokens=[]
			self.tokens = self.msg.split(',')
			self.tokens = map(string.strip,self.tokens)
			if len(self.tokens) < len(PACKETHDR):
				self.errMsg();return False
			#verify header
			if self.getPacketField('SIGN')!='GRL':
				self.errMsg();return False
			if self.getPacketField('VERSION')!='1.0':
				self.errMsg();return False
			if int(self.getPacketField('TYPE') ) > 2:
				self.errMsg();return False
			self.persist = int(self.getPacketField('PERSIST'))
			self.time = int(self.getPacketField('TIME'))
			self.encode = int(self.getPacketField('ENCODE'))
			if self.encode == 1 and len(self.tokens) > len(PACKETHDR):
				#base64 decode
				for n in range(len(PACKETHDR),len(self.tokens)):
					if self.tokens[n]:
						self.tokens[n] = base64.b64decode(self.tokens[n])
			r = True
		except:
			self.errMsg()
			print traceback.print_exc()
		return r
	
	def getDataFields(self):
		return self.tokens[len(PACKETHDR):]
	
	def getPacketField(self,name):
		val =''
		try:
			name=name.upper().strip()
			if PACKETHDR.count(name) ==0:
				return val
			val = self.tokens[PACKETHDR.index(name)]
		except:
			print traceback.print_exc()
		return val

class sepApp:
	def	__init__(self):
		self._conf = config.SimpleConfig()
		self.rdrlist=[] # {'host','port'}
		
	
	#与时间服务器同步
	def syncTime(self):
		setclock.syncTime()
	
	def initDB(self):
		host=self.getPropertyValue('db.host')
		port =self.getPropertyIntValue('db.port')
		name =self.getPropertyValue('db.name')
		user =self.getPropertyValue('db.user')
		passwd=self.getPropertyValue('db.passwd')
		r = False
		try:
			self.dbconn = pymssql.connect(host=host,user=user,password=passwd,database=name)
			r = True
			
			#sql="select * from grl_unknown"
			cr = self.dbconn.cursor()
			
			#sql = "insert into grl_unknown values('no',1,'tetail','ip',cast('2010-1-1' as datetime))"
			sql = "insert into grl_unknown values('no',1,'tetail',%s,cast('2010-1-1' as datetime))"
				
			
			#cr.execute(sql,("'192.168'"))
			#self.dbconn.commit()
			#print cr.fetchall()
		except:
			print traceback.print_exc()
			pass
		
		return r
			
	
	def getDBConn(self):
		return self.dbconn

	def log_normal(self,datas,packet):
		try:
			no,gameid,ip,_time,detail = datas[1:]
			gameid = int(gameid)
			if not ip:
				ip = packet.peerip
			#if not
			_time = int(time.time())
			_time = "%s-%s-%s %s:%s:%s"%time.localtime(_time)[:6]			
			
			sql="insert into grl_unknown values(%s,%s,%s,%s,cast('"+_time+"' as datetime))"
			dbconn = self.getDBConn()
			cr=dbconn.cursor()
			cr.execute(sql,(no,gameid,ip,detail))
			dbconn.commit()
			
		except:
			print traceback.print_exc()
		
	
	def make_insert(self,dbconn,table,fields):
		r = False
		try:
			sql = ''
			ss=[]			
			vs = []
			ff =[]
			for f in fields:
				ss.append('?')
				ff.append(f[0])
				vs.append(f[1])
			ss = string.join(ss,',')
			ff = string.join(ff,',')
			sql ="insert into %s (%s) values(%);"%(table,ff,ss)
			cr = dbconn.cursor()
			cr.execute(sql,vs)
			r = True
		except:
			print traceback.print_exc()
			r = False
		return r
	

	#张建平要求的日志记录需求
	
	def log_result(self,datas,packet):
		#  {fieldname,value}
		try:
			no,gameid,type,result,detail,elapsed,ip,_time=datas[1:]
			gameid = int(gameid)
			type = int(type)
			result = int(result)
			elapsed = int(elapsed)
			if not ip:				
				ip = packet.peerip
				
			#if not _time:
			_time = int(time.time())
			
				
			_time = "%s-%s-%s %s:%s:%s"%time.localtime(_time)[:6]
			sql="insert into grl_result values(%s,%s,%s,%s,%s,%s,cast('"+_time+"' as datetime),%s)"
			
			dbconn = self.getDBConn()
			cr = dbconn.cursor()
			cr.execute(sql,(no,gameid,type,result,detail,ip,elapsed))
			dbconn.commit()
			cr.close()
		except:
			print traceback.print_exc()
		
	
	def doPacket(self,msg,peer):
		print 'recv msg:',msg
		pkt = GtrLogPacket(self,msg,peer)
		if not pkt.parse():
			return 
		datas = pkt.getDataFields()
		if len(datas) == 0:
			return
		if datas[0] == '0': #常规日志信息
			self.log_normal(datas,pkt)
		if datas[0] =='1': #游戏处理交易
			self.log_result(datas,pkt)
		# redirect to
		ip = peer[0] #直接是从socket获取发送者的地址
		detail= base64.b64encode(str(datas))
		msg="GRL,%s,%s"%(ip,detail)
		sock = None
		#print msg
		try:
			sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
			for rdr in self.rdrlist:
				#print 'redirect:'+ str(rdr)
				dest = (rdr['host'],int(rdr['port']))
				sock.sendto(msg,dest)	
			sock.close()
		except:
			print traceback.print_exc()
		sock = None
	
	def run(self):
		self._conf.open('troll.conf')
		setclock.syncTime()
		self.initRedirectList()
		if not self.initDB():
			print 'DB Init Failed!'
			return
		try:
			self.sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
			addr = ('',self.getPropertyIntValue('GRL.udp.port'))
			self.sock.bind(addr)
			while True:
				(msg,peer) = self.sock.recvfrom(1024*10)
				self.doPacket(msg,peer)
		except:
			print traceback.print_exc()
		return 0

	def initRedirectList(self):
		try:
			redirects=  self.getPropertyValue('redirect.list').split(',')
			self.rdrlist =[]
			for r in redirects:
				rdr = {}
				rdr['host']= self.getPropertyValue("%s.host"%r)
				rdr['port']= self.getPropertyValue("%s.port"%r)
				self.rdrlist.append(rdr)			
		except:
			pass
		
		
		
	def getPropertyValue(self,propName,default=''):
		return self._conf.getPropertyValue(propName,default)
	
	def getPropertyIntValue(self,propName,default=0):
		return self._conf.getPropertyValueAsInt(propName,default)
	


##############################################################
##############################################################

if __name__=='__main__':	
	server = sepApp()
	server.run()
	
	
		
	