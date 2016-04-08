# -*- coding:utf-8 -*-
import socket
import os
import sys
import struct

import time
lchost="192.168.133.55"
lcport=12346
ret=None
sData = 'JS245-20100315-86671346,1,s/XKvLuvwvK80r3wsdLJz8/ese2zybmm'
ss = struct.pack('<8scIi58s7s', '<GRL>1.0','\0', 0x4B9DC621, 58, sData, '</GRL>\0')
	

try:
	s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

	s.connect((lchost, lcport))
	i=0
	s.send(ss)

	while True:
		i+=1
		if ( i == 30000 ):
			i = 0
		s.send(ss)	
		time.sleep(.01)
	s.close()
except:
	print "socket error %s"%ret
	
