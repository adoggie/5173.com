#!/usr/bin/python
from socket import *
import struct,os,time,sys

time_server = ('time.apple.com', 123)

TIME1970 = 2208988800L    

def syncTime(server='time.apple.com',port=123):
	r = False
	if not server:
		server='time.apple.com'
	time_server = (server,port)
	try:
		client = socket( AF_INET, SOCK_DGRAM )
		data = '\x1b' + 47 * '\0'
		client.sendto(data, time_server)
		data, address = client.recvfrom( 1024 )
		if data:
			pass #print 'Response received from', address,'\n'
		t = struct.unpack('!12I', data )[10]
		
		if t == 0:
			return False
			#ct = time.ctime(t - TIME1970)
		ct = time.localtime(t - TIME1970)
		os.system("date %s-%s-%s"%ct[:3])
		os.system("time %s:%s:%s"%ct[3:6])
		print ct
		r = True
	except:
		print 'failed!'
		r = False
	return r
	
if __name__=='__main__':
	syncTime()
