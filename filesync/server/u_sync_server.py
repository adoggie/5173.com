# -*- coding:utf-8 -*-

# revisions:
# 2009.12.05 scott
# 1. created
# 2. 输出数据均采用utf8存储
#			文件名处理必须转换到默认字符集 s.decode('utf-8')

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
			path = path.decode('utf-8')
			self._app.getLogger().debug("begin update:(%s)"%path)
			file = "%s/%s"%(game.path,path)
			fp = open(file,'rb')
			#通知开始
			
			hostprx.syncFileStart("%s/%s"%(game.dest_path,path))
			#print "%s/%s"%(game.dest_path,path)
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
			return False
		return True
		
	def update_game(self,hostprx,game):
		# hostprx - 远端主机代理
		#	filelist - 远端服务器目录清单
		#	本地目录
		
		try:
			#请求远程目录文件清单
			
			filelist = hostprx.getFileDescList(game.dest_path)
			
			#去除目录前缀
			#for n in range(len(filelist)):
			#	idx = filelist[n].filename.index(game.dest_path)						
			#	filelist[n].filename = filelist[n].filename[idx+len(game.dest_path):]				
			#访问游戏列表内的文件存储信息，读取摘要信息到内存
			digest = "%s/digest.md5"%game.path
			fp = open(digest,'r')
			lines = fp.readlines()
			fp.close()
			print filelist
			print lines
			for line in lines:
				
				path,size,digest = line.split(DELIMITER)
				#比对文件是否存在和摘要,文件大小不同可即刻判别
				
				needup = True
				
				for f in filelist:
					if f.filename == path:
						print path
					if f.filename == path and int(size) == f.size and digest.strip() == f.digest.strip(): #文件同名
						needup = False
						break
					
				if needup:
					if not self.update_file(hostprx,game,path):
						self._app.getLogger().error("update file failed:%s/%s"%(game.path,path))
				else:
					pass
					#self._app.getLogger().debug('no file update')
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
				uri = "%s:tcp -p %s -h %s"%(servant,port,host)
				hostprx = ISyncEndpointPrx.uncheckedCast(self._app.communicator().stringToProxy(uri))
				self._app.getLogger().debug("execute host:(%s)"%host)
				self.update_game(hostprx,game)
			except:
				print traceback.print_exc()
		self._app.getLogger().debug("host [%s] done."%host)
		pass
	
		
	def run(self):
		host = self._app.get_gamehost()
		while host:
			self.update(host)
			host = self._app.get_gamehost()
		
		self._app.getLogger().debug('have no host,thread exit...')


	

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
				self._game_hosts.append(l.strip())
		except:
			print 'Error: read game host failed!'
	
	#初始化游戏目录 
	def init_games(self):
		self._log = log.Logger(self.getPropertyValue('logfile','server.log'))
		names = self.getPropertyValue('games')
		games=names.split(',')
		for g in games:
			gi = gameInfoT()
			gi.name = g
			gi.path = self.getPropertyValue("%s.path"%g).decode('utf-8')
			gi.dest_path = self.getPropertyValue("%s.dest_path"%g).decode('utf-8')
			gi.launch_app = self.getPropertyValue("%s.launch.app"%g)
			gi.launch_params = self.getPropertyValue("%s.launch.params"%g)
			self._gamelist.append(gi)
	
	def getLogger(self):
		return self._log
	
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
			if sys.argv[1]!= 'update':
				return 0
		else:
			return 0
			pass
			
		self.getLogger().debug('service started!')
		# init threads		
		threadnum = self.getPropertyIntValue('workthread.num',1)
		threadList=[]
		self.getLogger().debug("preparing threads...(%s)"%threadnum)
		for n in range(threadnum):
			thread = updateThread(self)
			threadList.append(thread)
		for t in threadList:
			t.start()
		
		for t in threadList:
			t.join()
			self.getLogger().debug('work thread exit!')
		#
		self.getLogger().debug('update service completed!')
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
		gamelist = self.getGameList()
		for game in gamelist:
			try:
				#game.path = game.path.decode('utf-8') #还原为默认utf16编码
				file = "%s/digest.md5"%game.path
				fp = open(file,'w')
				self.getLogger().debug("scan game(%s,%s)..."%(game.name,game.path))
				#扫描游戏目录
				#不能记录game.path前缀
				
				for root, dirs, files in os.walk(game.path, topdown=False):
					for name in files:
						if name =='digest.md5':
							continue
						file = os.path.join(root, name)
						size = os.stat(file).st_size
						digest = codec.calcFileMd5Digest(file)
						if size == 0:
							#print file,size,digest
							#return
							pass
						#print file
						idx = file.index(game.path)						
						file = file[idx+len(game.path):]
						file = file.encode('utf-8') #存储时写入utf8编码
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
	
	
		
	