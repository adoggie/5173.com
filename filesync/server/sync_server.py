# -*- coding:utf-8 -*-

# revisions:
# 2009.11.05 scott
# 1. created
# 2009.12.25 scott
# 1. 添加忽略同步文件功能，创建skipfiles.txt到同步目录下，添加相对文件路径即可
# 2. 检测游戏存储路径名称，不要求尾端必须不能携带路径分隔符
# 3. 取消update文件时显示文件名称，只显示 主机-游戏-总文件数-已完成数

import sys,os
sys.path.insert(0,'C:\Ice-3.3.1-VC90\python')
sys.path.append('../lib')
import traceback,threading,time,struct,os,os.path,shutil,distutils.dir_util,array,base64,zlib,struct,binascii
import copy,socket,select
import codec,log,config

import Ice

Ice.loadSlice('-I../idl -IC:\Ice-3.2.1\slice ../idl/sync.ice')
from games  import *

DELIMITER='*'
##############################################################

def getFileDescList(self, path, current=None):
	rs=[]
	try:
		for root, dirs, files in os.walk(path, topdown=False):
			for name in files:
				file = os.path.join(root, name)
				fe = FileEntryT()
				fe.filename = file
				fe.size = os.stat(file).st_size
				fe.timestamp = 0
				fe.digest = codec.calcFileMd5Digest(file)
				rs.append(fe)
	except:
		pass
	return rs
#################################################
class gameInfoT:
	def __init__(self,name_=''):
		self.name=name_
		self.path=''
		self.dest_path=''
		self.launch_app=''
		self.launch_params=''
#################################################
#更新数据进程
# 4G md5计算40s
class updateThread(threading.Thread):
	def __init__(self,app):
		threading.Thread.__init__(self)
		self._app = app
	
	
	def update_file(self,hostprx,game,path):
		# game - 游戏信息
		# path - 游戏目录内的文件路径
		#
		try:
			#self._app.getLogger().debug("update:(%s)"%path)
			file = "%s/%s"%(game.path,path)
			fp = open(file,'rb')			
			#通知开始
			hostprx.syncFileStart("%s%s"%(game.dest_path,path))
			while True:
				bytes = fp.read(1024*100)
				if not bytes:
					break
				hostprx.syncFileData(bytes)
			fp.close()
			hostprx.syncFileEnd()			
			#self._app.getLogger().debug("update file succ! (%s)"%file)
		except:
			print traceback.print_exc()
			#self._app.getErrLogger().error("update file failed:(%s)"%(path))
			return False
		return True
		
	def update_game(self,hostprx,game,hostname=''):
		# hostprx - 远端主机代理
		#	filelist - 远端服务器目录清单
		#	本地目录
		
		try:			
			#读取忽略文件列表			
			skipfiles=[]
			try:
				fp = open("%s/skipfiles.txt"%game.path,'r')
				lines = fp.readlines()
				for line in lines:
					line = line.strip().lower()
					if len(line) and line[0]!='#':
						line= os.path.normpath(line)
						if line[0]!='\\':
							line = '\\'+line
						skipfiles.append(line) #添加进忽略列表
				fp.close()
				
			except:
				pass
			#**************************************
			#请求远程目录文件清单
			print u'计算远端主机数据摘要...'
			filelist = hostprx.getFileDescList(game.dest_path)
			
			#去除目录前缀
			for n in range(len(filelist)):
				idx = filelist[n].filename.index(game.dest_path)						
				filelist[n].filename = filelist[n].filename[idx+len(game.dest_path):]				
			#访问游戏列表内的文件存储信息，读取摘要信息到内存
			
			digest = "%s/digest.md5"%game.path
			fp = open(digest,'r')
			lines = fp.readlines()
			fp.close()
			##比对远端主机多余的文件,必须先删除
			removelist=[]
			#print filelist
			#print lines
			for f in filelist:
				found = False
				for line in lines:
					path,size,digest = line.split(DELIMITER)					
					if path == f.filename:
						found = True
						#print path
						break
				if found :
					continue
				#print f.filename
				#2009-12-25 忽略删除远端文件
				skipmatch = False
				for skfile in skipfiles:
					if f.filename.find(skfile)!=-1: # found
						skipmatch = True
						break
				if not skipmatch:
					removelist.append(f.filename)
				#----------------------------
				#if skipfiles.count(f.filename)!=0:
				#	removelist.append(f.filename)
			#先执行删除远端多余文件
			#print removelist
			if len(removelist):
				print u"远端共有(%s)个文件将被删除...."%(len(removelist))
			#请求删除远端主机差异文件
			for file in removelist:
				hostprx.deleteFile(game.dest_path+file)
			#
			#print filelist
			updatefiles=[]
			for line in lines:
				path,size,digest = line.split(DELIMITER)
				#比对文件是否存在和摘要,文件大小不同可即刻判别
				needup = True
				for f in filelist: #远端文件
					if f.filename == path and int(size) == f.size and digest.strip() == f.digest.strip(): #文件同名
						needup = False
						break
				#2009-12-25 忽略更新文件
				if needup:
					skipmatch = False
					for skfile in skipfiles:
						if path.find(skfile)!=-1: # found
							skipmatch = True
							break
					if skipmatch: #确定是要忽略的文件
						needup = False
						
				#if skipfiles.count(path)!=0:
				#	needup = False
				
				if needup:
					updatefiles.append(path)
			
			for n in range(len(updatefiles)):
				file = updatefiles[n]
				print "(%s/%s)%s/%s/%s".decode('utf-8')%(
					n+1,len(updatefiles),str(hostname),game.name,file)
				if not self.update_file(hostprx,game,file):
					self._app.getErrLogger().error("update file failed: host(%s),game(%s),file(%s)"%(str(hostname),game.name,file))
					return False
		except:
			print traceback.print_exc()
			return False
		return True
		
	def update(self,host):
		gamelist = self._app.getGameList()
		for game in gamelist:
			try:
				port = self._app.getPropertyValue('endpoint.port')
				servant = self._app.getPropertyValue('endpoint.servant')
				uri = "%s:tcp -p %s -h %s"%(servant,port,host['host'])
				hostprx = ISyncEndpointPrx.uncheckedCast(self._app.communicator().stringToProxy(uri))
				#self._app.getLogger().debug("prepare host:(%s)"%host)
				if not self.update_game(hostprx,game,host['host']):
					self._app.getErrLogger().error("update host(%s),game(%s)failed!"%(host['host'],game.name))
					return False
			except:
				self._app.getErrLogger().error("update host(%s),game(%s)failed!"%(host['host'],game.name))
				return False
		self._app.getLogger().debug("完成同步主机:%s.".decode('utf-8')%host['host'])
		return True
	
		
	def run(self):
		host = self._app.get_gamehost()
		while host:
			self._app.getLogger().debug("开始同步主机:%s...".decode('utf-8')%host['host'])
			self.update(host)			
			host = self._app.get_gamehost()
		
		self._app.getLogger().debug('主机列表为空,工作线程退出..'.decode('utf-8'))


	

class syncApp(Ice.Application):
	def	__init__(self):
		self._conf = config.SimpleConfig()
		
		
		self._mtx_hosts= threading.Lock()
		self._game_hosts=[]
		
		self._gamelist=[]
		################################
		
		
	def init_hosts(self):
		#初始化游戏客户机信息
		try:
			fp = open('../etc/hosts.list','r')
			lines = fp.readlines()
			fp.close()
			for l in lines:
				host,game = l.strip().split(',')
				host = host.strip()
				game = game.strip()
				if len(host) == 0 or len(game)==0:
					continue
				self._game_hosts.append({'host':host,'game':game})
		except:
			print 'Error: read game host failed!'
			return False
		return True
	
	#初始化游戏目录 
	def init_games(self):
		self._log = log.Logger(self.getPropertyValue('logfile','server.log'))
		self._errlog = log.Logger(self.getPropertyValue('errlogfile','error.log'))
		names = self.getPropertyValue('games')
		games=names.split(',')
		for g in games:
			g = g.strip()
			if len(g) == 0:
				continue
			gi = gameInfoT()
			gi.name = g
			gi.path = self.getPropertyValue("%s.path"%g).strip().lower()
			gi.path = os.path.normpath(gi.path)
			if gi.path[-1]=='\\':
				gi.path=gi.path[:-1]
			gi.dest_path = self.getPropertyValue("%s.dest_path"%g).strip().lower()
			gi.dest_path = os.path.normpath(gi.dest_path)
			if gi.dest_path[-1] =='\\':
				gi.dest_path = gi.dest_path[:-1]			
			gi.launch_app = self.getPropertyValue("%s.launch.app"%g)
			gi.launch_params = self.getPropertyValue("%s.launch.params"%g)
			self._gamelist.append(gi)
		
	
	def getLogger(self):
		return self._log

	def getErrLogger(self):
		return self._errlog
	
	def getGameList(self):
		return self._gamelist
	
	#return host info ,else none
	def get_gamehost(self):
		host =None
		self._mtx_hosts.acquire()
		if len(self._game_hosts):
			host = self._game_hosts.pop(0)
		self._mtx_hosts.release()
		return host
	

	def test(self):
		port = self.getPropertyValue('endpoint.port')
		servant = self.getPropertyValue('endpoint.servant')
		uri = "%s:tcp -p %s -h %s"%(servant,port,'localhost')
		hostprx = ISyncEndpointPrx.uncheckedCast(self.communicator().stringToProxy(uri))
		for i in range(100000):
			print hostprx.getTimestamp()
			time.sleep(0.5)
	
	#通知远端主机启动游戏 
	def launchGames(self):
		try:
			for host in self._game_hosts: # host is dict{host:host,game:gameName}
				port = self.getPropertyValue('endpoint.port')
				servant = self.getPropertyValue('endpoint.servant')
				uri = "%s:tcp -p %s -h %s"%(servant,port,host['host'])
				hostprx = ISyncEndpointPrx.uncheckedCast(self.communicator().stringToProxy(uri))
				#检索主机运行游戏的远端存储目录
				for g in self._gamelist:
					if g.name == host['game']:
						print "start game(%s) of host(%s):%s"%(g.name,host['host'],g.dest_path)
						try:
							r = hostprx.launchGame(g.dest_path)
						except:
							print "Error: Endpoint Host(%s) Exception Occurred! Skipped..."%(host['host'])
						#if r['succ']!='true':
						#	print r['errmsg']
		except:
			print 'host error!'
			print traceback.print_exc()
	
	def terminateGames(self):
		try:
			for host in self._game_hosts:
				port = self.getPropertyValue('endpoint.port')
				servant = self.getPropertyValue('endpoint.servant')
				uri = "%s:tcp -p %s -h %s"%(servant,port,host['host'])
				hostprx = ISyncEndpointPrx.uncheckedCast(self.communicator().stringToProxy(uri))
				for g in self._gamelist:
					if g.name == host['game']:
						print "kill game(%s) of host(%s):%s"%(g.name,host['host'],g.dest_path)
						try:
							r = hostprx.terminateGame(g.dest_path)
						except:
							print "Error: Endpoint Host(%s) Exception Occurred! Skipped..."%(host['host'])	
						#if r['succ']!='true':
						#	print r
		except:
			#print 'host error!'
			print traceback.print_exc()
	
	#执行远程批处理文件
	def excbat(self):
		try:
			hosts = sys.argv[2]
			logfile = 'excbat.log'
			if len(sys.argv) >=4:
				logfile = len[3]
			#fp = open(logfile,'a')
			
			fphosts = open(hosts) #打开主机列表
			lines = fphosts.readlines()
			fphosts.close()
			for line in lines:
				host,command = line.strip().split(',')
				host = host.strip()
				fp = open("excbat_%s.log"%host,'a')  #每个主机单独一个日志文件
				if host.strip()=='' or command.strip()=='':
					print "skip:",line
				port = self.getPropertyValue('endpoint.port')
				servant = self.getPropertyValue('endpoint.servant')
				uri = "%s:tcp -p %s -h %s"%(servant,port,host.strip())
				hostprx = ISyncEndpointPrx.uncheckedCast(self.communicator().stringToProxy(uri))
				try:
					print "execute  Batch File(%s) on Remote Host(%s)"%(command,host)
					r = hostprx.executeBatchFile(command)
					if r.has_key('verbose'): #写入执行日志
						print r['verbose']
						fp.write(r['verbose']+"\n")
				except:
					msg = "Execute BatchFile(%s) Error on Host(%s)"%(command,host)
					print msg
					fp.write(msg+"\n")
				fp.close()
			#fp.close()
		except:
			print traceback.print_exc()
		
	
	def usage(self):
		msg =\
'''sync_server(v0.1.4)\nusage:\nsync_server.exe [digest|update|startgame|endgame|excbat] [hosts]
  digest - 计算本地文件摘要
  update - 执行文件同步
  startgame - 加载游戏运行
  endgame - 终止游戏
  excbat batfile logfile  - 执行远程文件
	**创建游戏目录下skipfiles.txt添加文件路径名称，可以忽略文件同步 
	'''
		print msg.decode('utf-8')
		
	def run(self, args):
		self.init_games()
		# init game hosts
		self.init_hosts()
		
		#self.test()
		#return 0
	
		if len(sys.argv) >=2:
			if sys.argv[1] =='digest':
				self.gen_digest()
				return 0
			if sys.argv[1] == 'startgame':#加载游戏运行
				self.launchGames()
				return 0
			
			if sys.argv[1] == 'endgame':
				self.terminateGames()
				return 0
			if sys.argv[1] =='excbat':
				if len(sys.argv) < 3:
					print '必须提供执行主机列表'.decode('utf-8')
					return 0
				self.excbat()
				return 0
			
			if sys.argv[1]!= 'update':
				return 0
		else:
			self.usage()
			return 0
			pass
			
		self.getLogger().debug(u'同步服务启动..')
		# init threads		
		threadnum = self.getPropertyIntValue('workthread.num',1)
		threadList=[]
		self.getLogger().debug("创建(%s)工作线程".decode('utf-8')%threadnum)
		for n in range(threadnum):
			thread = updateThread(self)
			threadList.append(thread)
		for t in threadList:
			t.start()
		
		for t in threadList:
			t.join()
			self.getLogger().debug('一个工作线程已经退出!'.decode('utf-8'))
		#
		self.getLogger().debug(u'同步服务结束!')
		return 0

	def getPropertyValue(self,propName,default=''):
		return self.communicator().getProperties().getPropertyWithDefault(propName,default)
	
	def getPropertyIntValue(self,propName,default=0):
		try:
			default = int(default)
		except:
			default = 0 
		return self.communicator().getProperties().getPropertyAsIntWithDefault(propName,default)
	
#在游戏目录下计算并存放摘要信息，一个游戏目录支持在一个摘要文件

	def gen_digest(self):
		NOCARE_FILES=['digest.md5','skipfiles.txt']
		gamelist = self.getGameList()
		for game in gamelist:
			try:
				file = "%s/digest.md5"%game.path
				fp = open(file,'w')
				self.getLogger().debug("scan game(%s,%s)..."%(game.name,game.path))
				#扫描游戏目录
				#不能记录game.path前缀
				for root, dirs, files in os.walk(game.path, topdown=False):
					for name in files:
						if NOCARE_FILES.count(name)!=0:
							continue
						file = os.path.join(root, name).lower()
						size = os.stat(file).st_size
						digest = codec.calcFileMd5Digest(file)
						if size == 0:
							#print file,size,digest
							#return
							pass
						idx = file.index(game.path)						
						file = file[idx+len(game.path):]
						fp.write(file+DELIMITER+str(size)+DELIMITER+digest+"\n")
				fp.close()
			except:
				print traceback.print_exc()
		pass	

##############################################################
	
##############################################################
if __name__=='__main__':
	
	server = syncApp()
	sys.exit(server.main(sys.argv, "../etc/server.conf"))
	
	
		
	