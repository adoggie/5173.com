# -*- coding:utf-8 -*-




import traceback,threading,time,struct,os,os.path,shutil,distutils.dir_util,array,base64,zlib,struct,binascii
import copy,socket,select,base64,string


BASE64ENC=0

sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)


msg="GRL,1.0,0,7,%s,%s"%(int(time.time()),BASE64ENC)
params= msg +",1,JN1000-A100,1,1,0,game log,5,,"
#params='0,JN1000-A100,1,192.168.33.22,1264587397,game_log'

if BASE64ENC:
	params=params.split(',')
	for n in range(len(params)):
		params[n] = base64.b64encode(params[n])
	params = string.join(params,',')
	
msg = msg +","+params

dest=('localhost',6510)
sock.sendto(msg,dest)
