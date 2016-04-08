# -*- coding:utf-8 -*-

# revisions:
# 2009.11.05 scott
# 1. created

import sys,os
sys.path.insert(0,'C:\Ice-3.3.1-VC90\python')
sys.path.append('../ice')
import traceback,threading,time,struct,os,os.path,shutil,distutils.dir_util,array,base64,zlib,struct,binascii
import copy,socket
 

import Ice

Ice.loadSlice('-I./idl  ../idl/redirect.ice')
from rd import *

 
##############################################################

class syncApp(Ice.Application):
	def	__init__(self):
		
		uri = "dispatcher:tcp -p 5000 "
		prx = IRdDispatcherPrx.uncheckedCast(self.communicator().stringToProxy(uri))
		front  = RdFrontInfoT()
		print prx.getBastRdServers(1,front)
		
##############################################################
if __name__=='__main__':
	
	server = syncApp()
	sys.exit(server.main(sys.argv, ""))
	
	
		
	