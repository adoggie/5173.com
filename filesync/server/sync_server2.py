# -*- coding:utf-8 -*-

# revisions:
# 2009.11.05 scott
# 1. created

# 2009.12.26 scott created

# 2010.1.26 scott
# 1. 增加远程文件比对的操作接口

import sys,os
sys.path.insert(0,'C:\Ice-3.3.1-VC90\python')
sys.path.append('../lib')
import traceback,threading,time,struct,os,os.path,shutil,distutils.dir_util,array,base64,zlib,struct,binascii
import copy,socket,select,getopt
import codec,log,config

import Ice

Ice.loadSlice('-I../idl -IC:\Ice-3.2.1\slice ../idl/sync.ice')
from games  import *

DELIMITER='*'
##############################################################

class syncApp(Ice.Application):
	def	__init__(self):
		self._conf = config.SimpleConfig()
		
		
		self._mtx_hosts= threading.Lock()
		self._game_hosts=[]
		
		self._gamelist=[]
		################################
		
		
	def init_hosts(self):
		#初始化游戏客户机信息
		#try:
		#	fp = open('../etc/hosts.list','r')
		#	lines = fp.readlines()
		#	fp.close()
		#	for l in lines:
		#		host,game = l.strip().split(',')
		#		host = host.strip()
		#		game = game.strip()
		#		if len(host) == 0 or len(game)==0:
		#			continue
		#		self._game_hosts.append({'host':host,'game':game})
		#except:
		#	print 'Error: read game host failed!'
		#	return False
		return True
	
	#初始化游戏目录 
	def init_games(self):
		self._log = log.Logger(self.getPropertyValue('logfile','server.log'))
		self._errlog = log.Logger(self.getPropertyValue('errlogfile','error.log'))
		#names = self.getPropertyValue('games')
		#games=names.split(',')
		#for g in games:
		#	g = g.strip()
		#	if len(g) == 0:
		#		continue
		#	gi = gameInfoT()
		#	gi.name = g
		#	gi.path = self.getPropertyValue("%s.path"%g).strip().lower()
		#	gi.dest_path = self.getPropertyValue("%s.dest_path"%g).strip().lower()
		#	gi.launch_app = self.getPropertyValue("%s.launch.app"%g)
		#	gi.launch_params = self.getPropertyValue("%s.launch.params"%g)
		#	self._gamelist.append(gi)
	
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
	
	def killapp(self,host,port,procname):
		try:
			servant = self.getPropertyValue('endpoint.servant')
			uri = "%s:tcp -p %s -h %s"%(servant,port,host)
			hostprx = ISyncEndpointPrx.uncheckedCast(self.communicator().stringToProxy(uri))
			print u"终止远程进程: %s-%s"%(host,procname)
			hostprx.killProcessByName(procname)
		except:
			print traceback.print_exc()

	def launchapp(self,host,port,procname,param=''):
		try:
			servant = self.getPropertyValue('endpoint.servant')
			uri = "%s:tcp -p %s -h %s"%(servant,port,host)
			hostprx = ISyncEndpointPrx.uncheckedCast(self.communicator().stringToProxy(uri))
			print u"创建远程进程: %s-%s"%(host,procname)
			params={'app':'','param':''}
			params['app'] = procname
			params['param']=param
			hostprx.launchApp(params)
		except:
			print traceback.print_exc()
	
	
	
	#执行endpoint的更新操作
	def shutdown(self,host,port):
		try:
			servant = self.getPropertyValue('endpoint.servant')
			uri = "%s:tcp -p %s -h %s"%(servant,port,host)
			hostprx = ISyncEndpointPrx.uncheckedCast(self.communicator().stringToProxy(uri))
			print u"执行shutdown: %s"%(host)
			hostprx.shutdown()
		except:
			print traceback.print_exc()
			
		
	#通知远端主机启动游戏 
	def launchGames(self,host,port,gamepath):
		try:
			if True:
				servant = self.getPropertyValue('endpoint.servant')
				uri = "%s:tcp -p %s -h %s"%(servant,port,host)
				hostprx = ISyncEndpointPrx.uncheckedCast(self.communicator().stringToProxy(uri))
				#检索主机运行游戏的远端存储目录
				print u"启动游戏(%s) of host(%s)"%(gamepath,host)
				try:
					r = hostprx.launchGame(gamepath)
				except:
					print "Error: Endpoint Host(%s) Exception Occurred! Skipped..."%(host)
		except:
			print traceback.print_exc()
	
	def terminateGames(self,host,port,gamepath):
		try:
			if True:
				servant = self.getPropertyValue('endpoint.servant')
				uri = "%s:tcp -p %s -h %s"%(servant,port,host)
				hostprx = ISyncEndpointPrx.uncheckedCast(self.communicator().stringToProxy(uri))
				print "stop game(%s) of host(%s)"%(gamepath,host)
				try:
					r = hostprx.terminateGame(gamepath)
				except:
					print "Error: Endpoint Host(%s) Exception Occurred! Skipped..."%(host)
		except:
			print traceback.print_exc()
	
	#执行远程批处理文件
	def excbat(self,host,port,command):
		try:
			hosts = sys.argv[2]
			logfile = 'excbat.log'
			servant = self.getPropertyValue('endpoint.servant')
			uri = "%s:tcp -p %s -h %s"%(servant,port,host)
			hostprx = ISyncEndpointPrx.uncheckedCast(self.communicator().stringToProxy(uri))
			if True:
				r = hostprx.executeBatchFile(command)
				if r.has_key('verbose'): #写入执行日志
					print r['verbose']				
		except:
			print traceback.print_exc()
		
	def update_file(self,hostprx,local,remote,partfile):
		try:
			
			file = os.path.normpath(local+'/'+partfile)
			fp = open(file,'rb')						
			hostprx.syncFileStart("%s%s"%(remote,partfile))
			while True:
				bytes = fp.read(1024*100)
				if not bytes:
					break
				hostprx.syncFileData(bytes)
			fp.close()
			hostprx.syncFileEnd()						
		except:
			print traceback.print_exc()
			#self._app.getErrLogger().error("update file failed:(%s)"%(path))
			return False
		return True
		
	def update_game(self,hostprx,local,remote,hostname=''):
		#路径参数都不携带尾端的分隔符
		try:			
			#读取忽略文件列表			
			skipfiles=[]
			try:
				fp = open("%s/skipfiles.txt"%local,'r')
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
			filelist = hostprx.getFileDescList(remote)
			
			#去除目录前缀
			for n in range(len(filelist)):
				idx = filelist[n].filename.index(remote)						
				filelist[n].filename = filelist[n].filename[idx+len(remote):]				
			#访问游戏列表内的文件存储信息，读取摘要信息到内存
			
			digest = os.path.normpath("%s/digest.md5"%local)
			#print digest
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
				hostprx.deleteFile(remote + file)
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
				print "(%s/%s)%s/%s/%s"%(
					n+1,len(updatefiles),str(hostname),local,file)
				#file = os.path.normpath(local+"/"+file)				
				if not self.update_file(hostprx,local,remote,file):
					self._app.getErrLogger().error("update file failed: host(%s),game(%s),file(%s)"%(str(hostname),game.name,file))
					return False
		except:
			print traceback.print_exc()
			return False
		return True
	
	def diff_game(self,hostprx,local,remote,hostname=''):
		#路径参数都不携带尾端的分隔符
		try:			
			#读取忽略文件列表			
			skipfiles=[]
			try:
				fp = open("%s/skipfiles.txt"%local,'r')
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
			#print u'计算远端主机数据摘要...'
			filelist = hostprx.getFileDescList(remote)
			
			#去除目录前缀
			for n in range(len(filelist)):
				idx = filelist[n].filename.index(remote)						
				filelist[n].filename = filelist[n].filename[idx+len(remote):]				
			
			digest = os.path.normpath("%s/digest.md5"%local)
			#print digest
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

			if len(removelist):
				pass#print u"远端共有(%s)个文件将被删除...."%(len(removelist))
			for file in removelist:
				print "[+]"+file
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
						
				if needup:
					updatefiles.append(path)
			
			for n in range(len(updatefiles)):
				file = updatefiles[n]
				print "[-]"+file
		except:
			print traceback.print_exc()
			return False
		return True	
		
	def update(self,host,port,localpath,remotepath):		
		if True:
			try:
				
				localpath = os.path.normpath(localpath.strip().lower())
				if localpath[-1] =='\\':
					localpath = localpath[:-1]
				remotepath = os.path.normpath(remotepath.strip().lower())
				if remotepath[-1] =='\\':
					remotepath = remotepath[:-1]
					
				servant = self.getPropertyValue('endpoint.servant')
				uri = "%s:tcp -p %s -h %s"%(servant,port,host)
				hostprx = ISyncEndpointPrx.uncheckedCast(self.communicator().stringToProxy(uri))
				self.getLogger().debug(u"开始同步主机:%s..."%host)				
				if not self.update_game(hostprx,localpath,remotepath,host):
					self.getErrLogger().error("update host(%s),game(%s)failed!"%(host,localpath))
					return False
			except:
				print traceback.print_exc()
				self.getErrLogger().error("update host(%s) failed!"%(host))
				return False		
		return True
	
	#本地和远程目录比对
	#本地必须存在digest.md5,如不存在则先 syncserver2 update 生成
	def diff(self,host,port,localpath,remotepath):
		print '='*50
		print "Diff HOST:%s,PATH:%s"%(host,remotepath)
		print time.asctime()
		print '-'*50
		if True:
			try:
				localpath = os.path.normpath(localpath.strip().lower())
				if localpath[-1] =='\\':
					localpath = localpath[:-1]
				remotepath = os.path.normpath(remotepath.strip().lower())
				if remotepath[-1] =='\\':
					remotepath = remotepath[:-1]
					
				servant = self.getPropertyValue('endpoint.servant')
				uri = "%s:tcp -p %s -h %s"%(servant,port,host)
				hostprx = ISyncEndpointPrx.uncheckedCast(self.communicator().stringToProxy(uri))
				
				#self.getLogger().debug(u"开始同步主机:%s..."%host)				
				
				if not self.diff_game(hostprx,localpath,remotepath,host):
					self.getErrLogger().error("update host(%s),game(%s)failed!"%(host,localpath))
					return False
			except:
				print traceback.print_exc()
				self.getErrLogger().error("update host(%s) failed!"%(host))
				return False
		print '='*50
		return True

	def usage(self):
		msg =\
'''sync_server(v0.2.1) scott
usage:\nsync_server.exe [-d filepath | -h host -p port -k [startgame|update|endgame|excbat] ]
 -d filepath  - 计算文件摘要,filepath文件目录
 -h hostname  - 主机ip或者域名
 -p port      - 主机端口
 -k startgame dest  - 加载游戏运行,dest - 远程目录
 -k update src dest - 执行文件同步,src-本地目录;dest-远程目录 
 -k endgame  dest   - 终止游戏,dest - 远程目录
 -k excbat batfile - 执行远程文件,batfile带路径的远程主机批处理文件或者命令[blocked]
 -k shutdown       - 关闭endpoint服务
 -k killapp procname - 终止指定名称的进程
 -k launchapp procname - 创建进程
 -k diff src dest  - 比对本地与远程目录,src-本地目录;dest-远程目录	
	'''
		print msg.decode('utf-8')
		
	def run(self, args):
		self.init_games()
		# init game hosts
		self.init_hosts()
		
		host='localhost'
		port=5000
		try:
			opts, args = getopt.getopt(sys.argv[1:], "h:p:d:k:", ["help", "output="])
		except getopt.GetoptError, err:
			self.usage()
			return 0
		for o, a in opts:
			if o == "-h":
				host = a
			elif o =='-p':
				port = int(a)
			elif o == '-d': # calc digest				
				if not a:										
					self.usage()				
				else:
					self.gen_digest(a) #计算摘要
				return 0
			elif o =='-k':
				if a=='startgame': #launch game, -k startgame remote_dir
					if not host or not port:self.usage();return 0						
					if len(args):
						self.launchGames(host,port,args[0]) #args[0] - 文件目录
					else:
						self.usage()
					return 0
				elif a=='endgame':
					if not host or not port:self.usage();return 0						
					if len(args):
						self.terminateGames(host,port,args[0])					
					else:
						self.usage()
					return 0
				elif a == 'update':
					if not host or not port:self.usage();return 0						
					if len(args) >=2:
						self.update(host,port,args[0],args[1])
					else:
						self.usage()
					return 0
				elif a == 'diff':
					if not host or not port:self.usage();return 0						
					if len(args) >=2:
						self.diff(host,port,args[0],args[1])
					else:
						self.usage()
					return 0
				elif a == 'excbat':
					if not host or not port:self.usage();return 0						
					if len(args):
						self.excbat(host,port,args[0])						
					else:
						self.usage()
					return 0
				elif a == 'shutdown':
					if not host or not port:self.usage();return 0						
					self.shutdown(host,port)
					return 0
				elif a == 'killapp':
					if not host or not port:self.usage();return 0						
					if len(args):
						self.killapp(host,port,args[0])						
					else:
						self.usage()
					return 0
				elif a == 'launchapp':					
					if not host or not port:self.usage();return 0					
					if len(args):
						param=''
						
						if len(args) >1:
							param = args[1]
						self.launchapp(host,port,args[0],param)						
					else:
						self.usage()
					return 0
				
			else:
				self.usage()
				return 0
		self.usage()
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
	def gen_digest(self,filepath):
		NOCARE_FILES=['digest.md5','skipfiles.txt']
		#gamelist = self.getGameList()
		#for game in gamelist:
		if True:
			try:
				filepath = filepath.strip().lower()
				filepath = os.path.normpath(filepath)
				if filepath[-1]=='\\': #rid of terminated character
					filepath=filepath[:-1]				
				file = "%s/digest.md5"%filepath
				
				fp = open(file,'w')
				self.getLogger().debug(u"扫描文件目录(%s)..."%(filepath))				
				#不能记录game.path前缀
				for root, dirs, files in os.walk(filepath, topdown=False):
					for name in files:
						if NOCARE_FILES.count(name)!=0:
							continue
						file = os.path.join(root, name).lower().strip()
						size = os.stat(file).st_size
						digest = codec.calcFileMd5Digest(file)
						if size == 0:
							#print file,size,digest
							#return
							pass
						idx = file.index(filepath)
						file = file[idx+len(filepath):] #保留\
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
	
	
		
	