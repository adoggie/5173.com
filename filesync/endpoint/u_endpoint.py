# -*- coding:utf-8 -*-

# revisions:
# 2009.11.05 scott
# 1. created
#	2. 实现c++版本全部接口，保持调用一致性

import sys,os
#sys.path.insert(0,'C:\Ice-3.3.1-VC90\python')
#sys.path.append('../lib')

import traceback,threading,time,struct,os,os.path,shutil,distutils.dir_util,array,base64,zlib,struct,binascii
import copy,socket,select,hashlib
import codec,log,config

import Ice

Ice.loadSlice('-I../idl -I../idl/slice ../idl/sync.ice')
from games  import *

##############################################################

class SyncServiceEndpoint(ISyncEndpoint):
	def __init__(self,app):
		self._app = app
		self._fwh = None
		self._seqno = 0
		pass
	def invokeOneway(self, value, stream, current=None):
		pass
	
	def getSequence(self, current=None):
		self._seqno+=1
		return self._seqno
	
	def getType(self, current=None):
		return 'GRT_UPDATER'
	
	def getId(self, current=None):
		return self._app.getPropertyValue('server.id')
	
	def getTimestamp(self, current=None):
		return int(time.time())
	
	#--------------
	#获取指定路径下所有文件信息

	def getFileDescList(self, path, current=None):
		rs=[]
		try:
			print "calc digest and return..."
			#print ">>getFileDescList:%s"%path
			path = path.decode('utf-8')
			print path
			for root, dirs, files in os.walk(path, topdown=False):
				for name in files:
					root = root.decode('utf-8')
					name = name.decode('utf-8')
					#file = os.path.join(root, name)
					file = "%s/%s"%(root,name)
					print file
					#file = file.encode('utf-8')
					fe = FileEntryT()					
					fe.size = os.stat(file).st_size
					fe.timestamp = 0
					fe.digest = codec.calcFileMd5Digest(file)
					
					idx = file.index(path)
					file = file[idx+len(path):]
					fe.filename = file
					rs.append(fe)
					print fe
		except:
			print traceback.print_exc()
			pass
		#print str(rs)
		print rs
		return rs
	
	#取单个文件的摘要信息
	def getFileDigest(self, file, current=None):
		digest=''
		try:
			digest = codec.calcFileMd5Digest(file)
		except:
			pass
		return digest
	
	
	#文件同步开始
	def syncFileStart(self, file, current=None):
		r={}
		filename = file.decode('utf-8')
		#deep create dir
		#print filename
		r['succ'] = 'true'
		try:
			path = os.path.dirname(filename)
			distutils.dir_util.mkpath(path)
			self._fwh = open(filename,'wb')
		except:
			r['succ']='false'
		return r
	
	def syncFileData(self, bytes, current=None):
		r={'succ':'true'}
		try:
			self._fwh.write(bytes)
			self._fwh.flush()
		except:
			r['succ']='false'
		return r
	
	def syncFileEnd(self,current=None):
		r={'succ':'true','digest':''}
		try:
			self._fwh.close()								
		except:
			r['succ']='false'
		return r
	
	#执行本地程序
	def launchApp(self, params, current=None):
		pass
		
	#---------------------------------------
	

#################################################
#################################################

class sepApp(Ice.Application):
	def	__init__(self):
		self._conf = config.SimpleConfig()
		
		self.service = SyncServiceEndpoint(self)
	
	def run(self, args):
		#self._adapter = self.communicator().createObjectAdapterWithEndpoints("SyncEndPoint")
		self._log = log.Logger(self.getPropertyValue('logfile','endpoint.log'))
		self._adapter = self.communicator().createObjectAdapter("SyncEndPoint")
		self._adapter.add( self.service, self.communicator().stringToIdentity('endpoint')) #服务入口接口对象 
		self._adapter.activate()
		self._log.debug( 'endpoint service start!')
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
	sys.exit(server.main(sys.argv, "../etc/jerry.conf"))
	
	
		
	