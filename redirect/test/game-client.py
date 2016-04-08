# -*- coding:utf-8 -*-

import sys, traceback,threading,time,struct,base64,zlib
import socket,select,time


DEST_HOST='127.0.0.1'
DEST_PORT=9000

RDFRONT_ADDR=('127.0.0.1',23000)


sock = socket.socket()
sock.connect(RDFRONT_ADDR)

print 'connected rdFront server..'
count=1
while True:
	time.sleep(0.2)
	sock.sendall(str(count)*10)
	count+=1
	rs,ws,es = select.select([sock],[],[],1)
	
	if not rs:
		print 'read timeout!'
	else:
		r = sock.recv(1024)
		if not r:
			break
		print r
	
		
	