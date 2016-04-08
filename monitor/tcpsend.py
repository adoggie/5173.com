# -*- coding:utf-8 -*-
import socket
import os
import sys,base64,traceback,time

import time
lchost="192.168.33.52"
lcport=4402
ret=None

try:
	s = socket.socket()
	s.connect(('192.168.133.177',12345))	
	
	while True:
		text="GRL,1.0,0,7,1264415233,%s,%s,%s,%s,%s,%s\0"%(
					base64.b64encode('0'),
					base64.b64encode('JS-90921'),
					base64.b64encode('001'),
					base64.b64encode('192.168.133.55'),
					base64.b64encode(str(time.time())),
					base64.b64encode('how manay doggies in zootkac?')
					)	
		
		text = text * 10
		print text
		s.sendall(text)
		time.sleep(0.51)
		
	s.close()
except:
	print traceback.print_exc()
	
