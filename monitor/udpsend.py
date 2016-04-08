# -*- coding:utf-8 -*-
import socket
import os
import sys

import time
lchost="192.168.33.52"
lcport=4402
ret=None
try:
	s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
	#fr = open('./synread.txt','r')
	#text = fr.readlines()
	#fr.close()
	#k=""
	#text = k.join(text)
	text="ÖÐ ¹úsdfkasldfjlaksjdflkasdjklfjaskldjfklasdjfklsjdlkfjasdkljfklasdjflkasdjlkf"
	i=0
	while True:
		i+=1
		s.sendto(str(i)+","+text,(lchost,lcport))	
		time.sleep(.1)		
	s.close()
except:
	print "socket error %s"%ret
	
