# -*- coding:utf-8 -*-

# revisions:
# 2009.11.05 scott
# 1. created

# 2009.12.26 scott created

# 2010.1.26 scott
# 1. 增加远程文件比对的操作接口

import sys,os
sys.path.insert(0,'C:\Ice-3.3.1-VC90\python')
sys.path.append('./ice')
import traceback,threading,time,struct,os,os.path,shutil,distutils.dir_util,array,base64,zlib,struct,binascii
import copy,socket,select,getopt,base64
 

import Ice

Ice.loadSlice('-I./idl -IC:\Ice-3.3.1-VC90\slice ./idl/gtrc.ice')
from gtr  import *

 
##############################################################

class syncApp(Ice.Application):
	def	__init__(self):
		
		uri = "logserver:tcp -p 12346 -h 192.168.133.177"
		hostprx = ILoggerPrx.uncheckedCast(self.communicator().stringToProxy(uri))
		gameid = GameIdentifyT()
		text="GRL,1.0,0,7,1264415233,%s,%s,%s,%s,%s,%s"%(
					base64.b64encode('0'),
					base64.b64encode('JS-90921'),
					base64.b64encode('001'),
					base64.b64encode('192.168.133.55'),
					base64.b64encode(str(time.time())),
					base64.b64encode('how manay doggies in zootkac?')
					)		
		hostprx.gameMsg(gameid,int(time.time()),text )
##############################################################
if __name__=='__main__':
	
	server = syncApp()
	sys.exit(server.main(sys.argv, ""))
	
	
		
	