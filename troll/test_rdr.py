# -*- coding:utf-8 -*-




import traceback,threading,time,struct,os,os.path,shutil,distutils.dir_util,array,base64,zlib,struct,binascii
import copy,socket,select


sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
sock.bind(('',6511))
while True:
	print sock.recvfrom(1024)
