# -*- coding:utf-8 -*-

import sys,os

if len(sys.argv)<2 or sys.argv[1]=='help':
	print 'usage: \n\tdist-sign.exe help|printid|writeid|printserver|writeserver execfile [id] [output-file]'
	sys.exit()

f = open(sys.argv[2],'rb')
bytes= f.read()
f.close()

IDMARKER='Vendor:'

IDSERVER='DISPSERVER:'

IDPLACE=20
SERVERPLACE=30


if sys.argv[1] =='printid':
	pos = bytes.find(IDMARKER)
	if pos ==-1: sys.exit()
	id = bytes[pos+len(IDMARKER):pos+len(IDMARKER)+IDPLACE]
	print id
elif sys.argv[1] =='writeid':
	pos = bytes.find(IDMARKER)
	if pos ==-1: sys.exit()
	newid = sys.argv[3][:IDPLACE]
	newid = newid + ' '* (IDPLACE -len(newid))
	print len(newid)
	bytes = bytes[:pos+len(IDMARKER)]+newid+bytes[pos+len(IDMARKER)+IDPLACE:]
	#f = open(sys.argv[2],'wb')
	f = open(sys.argv[4],'wb')
	f.write(bytes)
	f.close()
elif sys.argv[1] =='printserver':
	pos = bytes.find(IDSERVER)
	if pos ==-1: sys.exit()
	id = bytes[pos+len(IDSERVER):pos+len(IDSERVER)+SERVERPLACE]
	print id
elif sys.argv[1] =='writeserver':
	pos = bytes.find(IDSERVER)
	if pos ==-1: sys.exit()
	newid = sys.argv[3][:SERVERPLACE]
	newid = newid + ' '* (SERVERPLACE -len(newid))
	print len(newid)
	bytes = bytes[:pos+len(IDSERVER)]+newid+bytes[pos+len(IDSERVER)+SERVERPLACE:]
	#f = open(sys.argv[2],'wb')
	f = open(sys.argv[4],'wb')
	f.write(bytes)
	f.close()
	