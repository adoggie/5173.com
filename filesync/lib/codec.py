#-*- coding:utf-8 -*-
#
#name: codecs.py
#brief:
#	
#author: scott
#


import os,sys,time,socket,threading,traceback,socket,select,struct,base64 
import zlib,binascii,hashlib

def calcFileMd5Digest(filename):
	digest=''
	bufsize=1024*40
	m = hashlib.md5() #.new()
	fp = None
	try:
		fp = open(filename,'rb')
		while 1:
			data = fp.read(bufsize)
			if not data:
				break
			m.update(data)			
	except IOError, msg:
		pass
		#sys.stderr.write('%s: I/O error: %s\n' % (filename, msg))
	digest = m.hexdigest()
	m = None
	fp = None
	return digest


if __name__=='__main__':
	print calcFileMd5Digest('c:/out.jpg')