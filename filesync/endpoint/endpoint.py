# -*- coding:utf-8 -*-

# revisions:
# 2009.11.05 scott
# 1. created
#	2. 实现c++版本全部接口，保持调用一致性
# 2009-12.26 scott
# 1. 支持升级: 创建c:/ep_update目录存放更新文件，当升级时将新的endpoint程序传输到目标主机的d:/ep_update下
#              启动ep_update/update.exe,然后endpoint.exe自动退出; update将新的程序文件覆盖掉原来的endpoint文件
#							最后启动endpoint.exe,update.exe自动退出 


# 2009.12.27 scott
# 1. 为支持endpoint的升级，目前解决方法是在syncserver端主动停止endpoint进程，然后再加载新的enpoint
#			这就要求endpoint退出之前加载新的endpoint进程，新的进程必须delay加载，因为端口会产生冲突

import sys,os
#sys.path.insert(0,'C:\Ice-3.3.1-VC90\python')
#sys.path.append('../lib')

import traceback,threading,time,struct,os,os.path,shutil,distutils.dir_util,array,base64,zlib,struct,binascii
import copy,socket,select,hashlib,win32process,win32api,win32con,re
#import win32com.client
#from xml.dom import minidom
import codec,log,config

import Ice

Ice.loadSlice('-I../idl -I../idl/slice ../idl/sync.ice')
from games  import *

##############################################################
VERSION='v0.2.0 2009.12.27 scott'


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
	
	def getVersion(self,current=None):
		return VERSION
	
	#--------------
	#获取指定路径下所有文件信息

	def getFileDescList(self, path, current=None):
		rs=[]
		try:
			print "calc digest and return..."
			#print ">>getFileDescList:%s"%path
			for root, dirs, files in os.walk(path, topdown=False):
				for name in files:
					file = os.path.join(root, name)
					fe = FileEntryT()
					fe.filename = file.lower()
					fe.size = os.stat(file).st_size
					fe.timestamp = 0
					fe.digest = codec.calcFileMd5Digest(file)
					rs.append(fe)				
		except:
			print traceback.print_exc()
			pass
		#print str(rs)
		
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
		print "prepare file:",file
		filename = file
		#deep create dir
		r['succ'] = 'true'
		try:
			filename = os.path.normpath(filename)
			path = os.path.dirname(filename)
			#file = os.path.basename(filename)
			#print "path:",path
			#distutils.dir_util.create_tree(path,file)
			#distutils.dir_util.mkpath(path)
			self.mkpath(path)
			self._fwh = open(filename,'wb')
		except:
			#print traceback.print_exc()
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
		try:
			print u"创建进程:%s"%params['app']
			print params
			#win32process.CreateProcess(params['app'], params['param'], None , None , 0 ,win32process.CREATE_NO_WINDOW , None , None ,
			win32process.CreateProcess(None,params['app']+' '+params['param'], None , None , 0 ,win32process.CREATE_NEW_CONSOLE , None , None ,
			
				win32process.STARTUPINFO())	
		except:
			print traceback.print_exc()
	
	def deleteFile(self, file, current=None):
		r={'succ':'true'}
		try:
			if os.path.isdir(file):
				distutils.dir_util.remove_tree(file)
			if os.path.isfile(file):
				os.remove(file)
		except:
			r['succ']='false'
		return r
	
	def terminateGame(self, game, current=None):
		r={'succ':'true'}
		try:			
			#file = "%s/RobotSetting.xml"%game
			#xmldoc = minidom.parse(file)
			#root = xmldoc.documentElement
			#node = root.getElementsByTagName('GameProcess')
			#n =root.getElementsByTagName('RobotPath')			
			#path = root.getElementsByTagName('RobotPath').nodeName #nodeName,nodeType
			
			conf = config.SimpleConfig()
			if not conf.open("%s/RobotSetting.conf"%game):
				r['succ']='false'
				r['errmsg']='game config lost!'
				return r
			s = conf.getPropertyValue('GameProcess')
			processes  = s.split(',')			
			for p in processes:
				pid = self.getProcessIdByName(p)
				if pid != -1:
					print "Kill Process:(%s)%s"%(pid,p)
					self.killProcess(pid)
		except:
			print traceback.print_exc()
			r['succ']='false'
		return r
	
	#加载游戏
	#读取游戏目录下的 RobotSetting.xml 配置信息
	#
	def launchGame(self, game, current=None):
		r={'succ':'true'}
		#self.terminateGame(game)	#停止游戏运行 
		try:
			#file = "%s/RobotSetting.xml"%game
			#xmldoc = minidom.parse(file)
			#root = xmldoc.documentElement			
			#path = "%s/%s"%(game,root.getElementsByTagName('RobotPath').nodeName.strip()) # nodeName,nodeType
			conf = config.SimpleConfig()
			if not conf.open("%s/RobotSetting.conf"%game):
				r['succ']='false'
				r['errmsg']='game config lost!'
				return r
			s = conf.getPropertyValue('RobotPath')
			path = "%s/%s"%(game,s)
			print 'Execute file:',path
			win32process.CreateProcess(path, '', None , None , 0 ,win32process.CREATE_NO_WINDOW , None , None ,
				win32process.STARTUPINFO())			
		except:
			#print traceback.print_exc()
			r['succ']='false'
			#r['errmsg'] = traceback.print_exc()
		return r

	#执行批处理文件
	def executeBatchFile(self,file,current=None):
		r={'succ':'true','verbose':''}
		try:
			print 'Exceute Batch File:',file
			r['verbose']=os.popen("%s"%file).read()
		except:
			r['succ']='false'
		return r
	
	#杀掉制定进程名称
	def killProcessByName(self,procname,current=None):
		try:
			pid = self.getProcessIdByName(procname)
			if pid != -1:
				print "Kill Process:(%s)%s"%(pid,procname)
				self.killProcess(pid)
		except:
			print traceback.print_exc()
	
	#开始更新
	def startUpdate(self,current=None):		
		try:
			upfile = os.path.normpath( self._app.getPropertyValue('endpoint_updir')+'/update.exe')
			print u'启动更新进程:%s'%upfile
			win32process.CreateProcess(upfile, '', None , None , 0 ,win32process.CREATE_NO_WINDOW , None , None ,
				win32process.STARTUPINFO())		
			sys.exit(0)	
		except:
			print traceback.print_exc()
	
	def shutdown(self,c=None):
		print u'停机...'
		sys.exit(0)
	
	def getRemoteFile(self,remotefile,c=None):
		pass
	
	def getFileDesc(self,remotefile,c=None):
		pass
	
	def getRemoteFileData(self,remotefile,offset,size,c=None):
		pass
	
	#---------------------------------------
	def mkpath(self,path):
		try:
			#print '>>',path
			ls = path.split('\\')
			dirname = ls[0]
			for n in range(1,len(ls)):
				dirname = dirname+"\\"+ls[n]
				#print 'make dir:',dirname
				try:
					os.mkdir(dirname)
				except:pass
		except:
			print traceback.print_exc()
			return False
		return True
	
	#def getProcessIdByName(self,pname):
	#	pid = -1
	#	pname = pname.strip()
	#	WMI = win32com.client.GetObject('winmgmts:')
	#	rs = WMI.ExecQuery("select * from Win32_Process where name ='%s'"%pname)
	#	for r in rs: #.ProcessId,n.Name
	#		pid = r.ProcessId
	#		break
	#	return pid
	
	#def getProcessIdByName(self,pname):
	#	pid = -1
	#	pname = pname.strip()
	#	print pname
	#	allPIDs = win32process.EnumProcesses()
	#	
	#	for PID in allPIDs:
	#		try:
	#			hProcess = win32api.OpenProcess(win32con.PROCESS_TERMINATE, False, PID)
	#			hProcessFirstModule = win32process.EnumProcessModules(hProcess)[0]
	#			currentprocessname = os.path.split(win32process.GetModuleFileNameEx(hProcess, hProcessFirstModule))[1]
	#			#print currentprocessname
	#			if pname.lower() == currentprocessname.lower():
	#				pid = PID
	#		except Exception, e:
	#			pass#print traceback.print_exc()
	#	return pid
	
	def getProcessIdByName(self,pname):
		pid = -1
		pname = pname.strip().lower()
		
		try:
			lines = os.popen('tasklist').read()
			lines = lines.split('\n')
			#print len(lines)
			#return 
			#fp = open('c:/tasklist.txt','w')
			#fp.write(lines)
			#fp.close()
			#fp = open('c:/tasklist.txt')
			#lines = fp.readlines()
			#fp.close()
			for line in lines:
				try:
					line = line.strip().lower()
					pids = re.findall("^%s\s+(\d+).*"%pname,line)					
					if len(pids):
						pid = pids[0]
					
				except:pass
		except:
			pass
		print "getProcessIdByName(%s)=>%s"%(pname,pid)
		return pid
	
#检测进程名是否存在 
	def isProcessExist(self,pname):
		r=True
		if self.getProcessIdByName(pname) == -1:
			r = False
		return r
	
	def killProcess(self,pid):
		try:
			hProcess = win32api.OpenProcess(win32con.PROCESS_TERMINATE, False, int(pid))
			win32api.TerminateProcess(hProcess,0)
		except:
			print traceback.print_exc()
		
		#os.system("taskkill /F /PID %s"%pid)
#################################################
#################################################

class sepApp(Ice.Application):
	def	__init__(self):
		self._conf = config.SimpleConfig()		
		self.service = SyncServiceEndpoint(self)
	
	def test(self):
		#print self.service.getProcessIdByName('Insight3.Exe')
		#print self.service.terminateGame('c:/aaa')
		#print self.service.launchGame('c:/a')
		#print self.service.deleteFile('c:/a/NOTEPAD.EXE')
		#self.service.getProcessIdByName('hh.exe')
		#self.service.killProcess(2968)
		pass
	
	def run(self, args):
		#self.test()
		#return 0
		#self._adapter = self.communicator().createObjectAdapterWithEndpoints("SyncEndPoint")
		self._log = log.Logger(self.getPropertyValue('logfile','endpoint.log'))
		self._adapter = self.communicator().createObjectAdapter("SyncEndPoint")
		self._adapter.add( self.service, self.communicator().stringToIdentity('endpoint')) #服务入口接口对象 
		self._adapter.activate()
		self._log.debug( 'endpoint (%s) service start!'%VERSION)
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
	#print win32con.PROCESS_TERMINATE
	#ps = os.popen('tasklist').read()
	#f = open('c:/dump.txt','w')
	#f.write(ps)
	#f.close()
	#print ps
	#sys.exit()
	if len(sys.argv) >=3:
		if sys.argv[1] =='-d':
			delay = 5
			try:
				delay = int(sys.argv[2])
			except:
				pass
			time.sleep(delay) #延迟
	#print sys.argv
	server = sepApp()
	sys.exit(server.main(sys.argv, "../etc/jerry.conf"))
	
	
		
	