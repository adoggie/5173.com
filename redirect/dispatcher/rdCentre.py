# -*- coding:utf-8 -*-

# revisions:
# 2009.11.05 scott

import sys,os
sys.path.insert(0,'C:\Ice-3.3.1-VC90\python')
#sys.path.append('../lib')

import traceback,threading,time,struct,os,os.path,zlib,struct
import copy,socket,select
import psycopg2
#import win32com.client
#from xml.dom import minidom
import log,config
import udpserver

import Ice

#Ice.loadSlice('-I../idl -I../idl/slice ../idl/redirect.ice')
Ice.loadSlice('-I../idl ../idl/redirect.ice')
from rd import *

##############################################################
VERSION='0.1.0'


class IRdDispatcherImpl(IRdDispatcher):
	def __init__(self,server):
		self.server = server
		self._seqno = 0
		pass
	
	def getSequence(self, current=None):
		return 0
	
	def getType(self, current=None):
		pass
	
	def getId(self, current=None):
		pass
	
	def getTimestamp(self, current=None):
		pass
	
	def getVersion(self, current=None):
		pass
	
#------------------------------------------------------

	def getPingList(self, pinger, current=None):
		pass
	
	def completePing(self, pinger, result, current=None):
		pass
	
	def getBastRdServers(self,areaName, reqnum, front, current=None):
		# areaName - 区域名称
		proxies=[]
		try:
			cr = self.server.getDBConn().cursor()
			proxy = RdServerInfoT()
			sql = "select ip,port from rdserver order by status_interval desc limit 1;"
			cr.execute(sql)
			rs = cr.fetchone()
			if rs:
				proxy.ip = rs[0].strip() #socket.inet_aton(rs[0])
				proxy.port = rs[1]
				proxies.append(proxy)
		except:
			self.server.resetDBConn()
			self.server.getLogger().error(traceback.format_exc())
			
		print 'Get RdServers:',str(proxies)
		return proxies
	
	def connectedRdServer(self, front, server, sheet, current=None):
		self.saveRdserverConnectStatus(0,front,server,sheet)		
	
	def disconnectedRdServer(self, front, server, sheet, current=None):
		self.saveRdserverConnectStatus(1,front,server,sheet)

###############################################################33
	# status : 0-connected, 1-disconnected
	def saveRdserverConnectStatus(self,status,front,server,sheet):
		try:
			cr = self.server.getDBConn().cursor()
			sql ="INSERT INTO rdserver_connect_status( mac, ip, port, time_tick, client_ip, game_id, trade_no, status) VALUES (%s, %s, %s, %s, %s, %s, %s, %s);"
			cr.execute(sql,(server.mac,server.ip,server.port,int(time.time()),front.ip,sheet.gameId,sheet.tradeNo,status,))
			self.server.getDBConn().commit()
		except:
			self.server.resetDBConn()
			self.server.getLogger().error(traceback.format_exc())
	

	
#################################################
#################################################

class sepApp(Ice.Application):
	def	__init__(self):
		self._conf = config.SimpleConfig()		
		self.server = IRdDispatcherImpl(self)
		self.dbconn = None
		self.udpserver = udpserver.UdpServer(self)
	
	def getConfig(self):
		return self._conf
	
	def getDBConn(self):
		try:
			if self.dbconn == None:
				dbhost=self.getPropertyValue('dbhost','localhost')
				dbname=self.getPropertyValue('dbname','IpRedirect')
				dbuser=self.getPropertyValue('dbuser','postgres')
				dbpasswd=self.getPropertyValue('dbpasswd','111111')
				self.dbconn = psycopg2.connect(host=dbhost,database=dbname,user=dbuser,password=dbpasswd)
		except:
			self._log.error(traceback.format_exc())
		return self.dbconn
			
	def resetDBConn(self):
		self.dbconn = None
		
	def test(self):
		#print self.service.getProcessIdByName('Insight3.Exe')
		#print self.service.terminateGame('c:/aaa')
		#print self.service.launchGame('c:/a')
		#print self.service.deleteFile('c:/a/NOTEPAD.EXE')
		#self.service.getProcessIdByName('hh.exe')
		#self.service.killProcess(2968)
		pass
	
	def getLogger(self):
		return self._log
	
	def run(self, args):
		self._log = log.Logger(self.getPropertyValue('logfile','dispach.log'))
		if not self.getDBConn():
			self._log.error('Init db Failed!')
			return 0
		if not self.udpserver.start():
			self._log.error('Udp service Failed!')
			return 0
		
		self._adapter = self.communicator().createObjectAdapter("dispatcher")
		self._adapter.add( self.server, self.communicator().stringToIdentity('dispatcher')) #服务入口接口对象 
		self._adapter.activate()
		self._log.debug( 'RdServer(Dispatcher - %s) Launched!'%VERSION)
		self.communicator().waitForShutdown()
		return 0

	def getPropertyValue(self,propName,default=''):
		return self.communicator().getProperties().getPropertyWithDefault(propName,default)
	
	def getPropertyIntValue(self,propName,default=0):
		try:
			default = int(default)
		except:
			default = 0 
		return self.communicator().getProperties().getPropertyAsIntWithDefault(propName,default)
	


##############################################################
##############################################################

if __name__=='__main__':

	server = sepApp()
	sys.exit(server.main(sys.argv, "dispatch.conf"))
	
	
		
	