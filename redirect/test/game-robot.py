# -*- coding:utf-8 -*-

# revisions:
# 模拟游戏人,请求rdFront开始游戏


import sys,os
sys.path.insert(0,'C:\Ice-3.3.1-VC90\python')
sys.path.insert(0,'../ice')
import traceback,threading,time,struct,os,os.path,shutil,distutils.dir_util,array,base64,zlib,struct,binascii
import copy,socket,select,getopt


import Ice

Ice.loadSlice('-I../idl  ../idl/redirect.ice')
from rd  import *

DELIMITER='*'
##############################################################
class syncApp(Ice.Application):
	def startGame(self):
		try:
			uri = "rdfront:tcp -p 9933 -h 192.168.137.63 "
			front = IRdFrontPrx.checkedCast(self.communicator().stringToProxy(uri))
			sheet = RdWorkSheetT()
			sheet.areaName='shanghai'
			front.prepare(sheet,100)
		except:
			print traceback.print_exc()
	
	def run(self, args):		
		self.startGame()
		
server = syncApp()
sys.exit(server.main(sys.argv, ""))