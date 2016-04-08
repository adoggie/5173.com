# -*- coding:utf-8 -*-
import socket
import os
import sys
import struct

import time
lchost="192.168.133.55"
lcport=12345
ret=None
sData = 'JS245-20100315-86671346,2,w/vX1jp0cmFpdG9yaGI1LLXIvLY6NDEssbOw/L3wsdI6NTEyMDkzNyzTys/kvfCx0joyNzA3MDgwMA=='
#ss = struct.pack('<8scIi106s7s', '<GRL>1.0','\0', 0x4B9DC621,106, sData, '</GRL>\0')
ss1 = struct.pack('<8scIi106s8s', '<GRL>1.0','\0', 0x4B9DC621,106, sData, '</GRL>\0<')
ss2 = struct.pack('<7scIi106s7s', 'GRL>1.0','\0', 0x4B9DC621,106, sData, '</GRL>\0')	
ss3 = struct.pack('<8scIi106s7s', '<GRL>1.0','\0', 0x4B9DC621,106, sData, '</GRL>\0')
try:
	s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

	s.connect((lchost, lcport))
	i=0
	s.send(ss1)
	s.send(ss2)
	s.send(ss3)
#	while True:
#		b = 0
#	while True:
#		i+=1
#		if ( i == 30000 ):
#			i = 0
#		s.send(ss)	
#		time.sleep(.01)		
	s.close()
except:
	print "socket error %s"%ret
	
