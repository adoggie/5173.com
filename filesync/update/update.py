# -*- coding:utf-8 -*-

# revisions:


import sys,os
#sys.path.insert(0,'C:\Ice-3.3.1-VC90\python')
#sys.path.append('../lib')

import traceback,time,struct,os,os.path,shutil,distutils.dir_util,array,base64,zlib,struct,binascii
import copy,win32process,win32api,win32con
#import win32com.client
#from xml.dom import minidom
import config
##############################################################
##############################################################
print u'开始升级...'
time.sleep(2)
conf = config.SimpleConfig()
conf.open('update.conf')
epappdir =  conf.getPropertyValue('endpoint.install')
epupdir =  conf.getPropertyValue('endpoint.update')
#拷贝 $epupdr/endpoint/*.* 到 $epappdir/下
print u'拷贝系统文件...'
print "%s >> %s"%(epupdir,epappdir)
#os.mkdir(epappdir)
distutils.dir_util.copy_tree(epupdir,epappdir)

#启动endpoint
win32process.CreateProcess("%s/endpoint.exe"%epappdir, '', None , None , 0 ,win32process.CREATE_NO_WINDOW , None , None ,
				win32process.STARTUPINFO())			

	
	
	
		
	