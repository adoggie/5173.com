# -*- coding:utf-8 -*-

import sys, traceback,threading,time,struct,base64,zlib

import socket,select


#模拟游戏服务程序,等待游戏进程连接进入,并读写一些数据

SERVER_ADDR=('',12009)
#SERVER_ADDR=('',23000) #just for testing redirection

class GameProcessThread(threading.Thread):
	def __init__(self,server,conn):
		threading.Thread.__init__(self)
		self.conn = conn
		self.start()
	
	#线程处理
	def run(self):
		print 'Client Incoming...'
		try:
			while True:
				ss = self.conn.recv(1024)
				print 'Client Incoming Data:',ss
				self.conn.sendall('GameServer send back:'+ss)
		except:
			traceback.print_exc()
		print 'Thread exiting...'


class GameServer:
	def __init__(self):
		self.serversock= socket.socket()
		self.serversock.bind(SERVER_ADDR)
		self.serversock.listen(5)
		
	
	def main(self):
		print 'Game Server Ready...'
		self.clients=[]
		while True:
			conn,addr = self.serversock.accept()
			print 'Incoming Client:',str(addr)
			gclient = GameProcessThread(self,conn)
			self.clients.append(gclient)
		
		return 0
		
if __name__=='__main__':
	server = GameServer()
	sys.exit(server.main())