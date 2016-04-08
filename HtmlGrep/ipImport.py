# -*- coding:utf-8 -*-
#导入ip网段库记录

import sys,os

import traceback,threading,time,struct,os,os.path,zlib,struct,string
import psycopg2

import log,config

'''

CREATE DATABASE IpRedirect
  WITH OWNER = postgres
       ENCODING = 'UTF8';

CREATE TABLE IpRepository
(
  endip bigint NOT NULL,
  startip bigint NOT NULL,
  name character varying(40) NOT NULL
)
WITH (OIDS=TRUE);
ALTER TABLE IpRepository OWNER TO postgres;




'''



#function Paging(total) {
#	this.pageSize = 10;//每页显示记录数
#	this.step = 5;//最多显示分页页数
#	this.total = total; //总记录数
#}

g_conf = config.SimpleConfig()
g_conf.open('grep.conf')
g_dbconn = None
g_logger = log.Logger('hgrep.log')
g_flog = open('c:/test.txt','w')

def getDBConn():
	global g_dbconn
	try:
		if g_dbconn == None:
			dbhost=g_conf.getPropertyValue('dbhost','localhost')
			dbname=g_conf.getPropertyValue('dbname','IpRedirect')
			dbuser=g_conf.getPropertyValue('dbuser','postgres')
			dbpasswd=g_conf.getPropertyValue('dbpasswd','111111')
			g_dbconn = psycopg2.connect(host=dbhost,database=dbname,user=dbuser,password=dbpasswd)
	except:
		g_logger.error(traceback.format_exc())
	return g_dbconn
	

def importIpTables():
	fp = open('ipdata.txt')
	lines = fp.readlines()
	print len(lines)
	fp.close()
	conn = getDBConn()
	cr = conn.cursor()
	for line in lines:
		parts=None
		try:
			parts = line.strip().split('_')
			parts = map(string.strip,parts)
			if len(parts) <3:
				continue
			#insert ip table by sql statements
			sql = "insert into IpRepository values(%s,%s,%s);"
			
			
			#print parts
			
			cr.execute(sql,(long(parts[0]),long(parts[1]),parts[2],))
			conn.commit() 
		except:
			cr = conn.cursor()
			g_logger.error(traceback.format_exc())
			print parts
			return 
	
		
		

if __name__=='__main__':
	importIpTables()
	#server = sepApp()
	#sys.exit(server.run())
	
	
		
	