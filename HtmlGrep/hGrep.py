# -*- coding:utf-8 -*-
#扫描xunbao173.com web页面记录到数据库
import sys,os

import traceback,threading,time,struct,os,os.path,zlib,struct
import copy,socket,select
#import psycopg2
import httplib,re

import log,config


#function Paging(total) {
#	this.pageSize = 10;//每页显示记录数
#	this.step = 5;//最多显示分页页数
#	this.total = total; //总记录数
#}

'''

CREATE DATABASE htmlgrep
  WITH OWNER = postgres
       ENCODING = 'UTF8';
			 
			 
CREATE TABLE htmlGrep
(
   id integer, 
   item_name character(60) NOT NULL, 
   price_s character(40),
	 rank integer,
   appear_time integer NOT NULL, 
   disappear_time integer NOT NULL
) WITH (OIDS=TRUE)
;

'''

g_conf = config.SimpleConfig()
g_conf.open('grep.conf')
g_dbconn = None
g_logger = log.Logger('hgrep.log')
g_flog = None

g_cookie = ''

#def getDBConn():
#	global g_dbconn
#	try:
#		if g_dbconn == None:
#			dbhost=g_conf.getPropertyValue('dbhost','localhost')
#			dbname='gamegrep'
#			dbuser=g_conf.getPropertyValue('dbuser','postgres')
#			dbpasswd=g_conf.getPropertyValue('dbpasswd','111111')
#			g_dbconn = psycopg2.connect(host=dbhost,database=dbname,user=dbuser,password=dbpasswd)
#	except:
#		g_logger.error(traceback.format_exc())
#	return g_dbconn
	
#检索页数量

'''
<input type="hidden" id="currentPage" value="1"/>
<input type="hidden" id="orderBy" value=""/>
<input type="hidden" id="pageTotal" value="24"/>
'''

def getPageNum(html):
	ms = re.findall("id=\"pageTotal\" value=\"(.*?)\"",html,re.S)
	if len(ms)==0:
		pass
		#return 0
	return ms[0]

def getPageHtml(game,idx):
	html =''
	url = "/%s/getServerList"%(game)
	gamesite=g_conf.getPropertyValue('root.site')
	conn = httplib.HTTPConnection(gamesite)
	
	hdr={'Cookie':g_cookie,
					 'Accept':'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
					 'Accept-Charset':'GB2312,utf-8;q=0.7,*;q=0.7',
					 'Accept-Language':'zh-cn,zh;q=0.5',
					 'Keep-Alive':'300',
					 'Connection':'keep-alive',
					 'Accept-Encoding':'gzip,deflate'
					 }
			
	conn.request("GET", "/%s/buy.gsp?keyWord=&groupName=&orderBy=&page=%s"%(game,idx),'',hdr)
	r1 = conn.getresponse()
	html = r1.read()
	return html


def scanRecordsOfHtml(f,html,serverid,serverName):
	
	regex = '''<span class="realName">(.*?)</span>.*?rank.*?>(.*?)</dd>.*?price.*?>(.*?)</dd>.*?linkTo\('(.*?)','''
	ms = re.findall(regex,html,re.S)
	#f = open('hgrep.rec.txt','w')
	#conn = getDBConn()
	for n in ms:
		f.write("%s,%s,%s,%s,%s,%s\n"%(n[0],n[1],n[2],n[3],serverid,serverName))


#扫描游戏服务器 [{name,url}]
def scanGameServers(game):
	global g_cookie
	url = "/%s/getServerList"%(game)
	gamesite=g_conf.getPropertyValue('root.site')
	conn = httplib.HTTPConnection(gamesite)
	conn.request("GET", url)
	r1 = conn.getresponse()
	html = r1.read()
	#print html
	ms = re.findall("<div class=\"ser_area_list\">(.*?)</div>",html,re.S)
	if len(ms)!=2:
		print 'Html content invalid!'
		return
	html = ms[1]
	#ms = re.findall("<a href=\"(.*?)\">.*?title=\"(.*?)\".*?</a>",html,re.S)
	#"getServerList?aid=15&id=1136"
	ms = re.findall("<a href=\".*?aid=(.*?)&id=(.*?)\">.*?title=\"(.*?)\".*?</a>",html,re.S)
	
	if len(ms) == 0:
		print 'Game:%s is null!'%(game)
		return
	print '%s servers Found'%len(ms)
	#print r1.getheader('set-cookie')
	cookie = r1.getheader('set-cookie').split(';')[0]
	g_cookie =  cookie
	#进入游戏区服
	scanedserver =[]
	
	for server in ms:
		try:
			
			#if scanedserver.count(server[1])!=0:
			#	continue
			#scanedserver.append(server[1])
			print server
			f = open(server[2].decode('utf-8').encode('gb2312')+'.txt','w')
			print "/%s/%s"%(game,server[0])
			url = "getServerList?aid=%s&id=%s"%(server[:2])
			print url
			#return url
			conn = httplib.HTTPConnection(gamesite)
			
			#conn.request("GET", "/%s/%s/"%(game,server[0]),None,{'Cookie':cookie})
			hdr={'Cookie':cookie,
					 'Accept':'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
					 'Accept-Charset':'GB2312,utf-8;q=0.7,*;q=0.7',
					 'Accept-Language':'zh-cn,zh;q=0.5',
					 'Keep-Alive':'300',
					 'Connection':'keep-alive',
					 'Accept-Encoding':'gzip,deflate'
					 }
			
			#conn.request("GET", "/%s/%s"%(game,server[0]),'',hdr)
			conn.request("GET", "/%s/%s"%(game,url),'',hdr)
			r1 = conn.getresponse()
			html = r1.read()
			print 'have a sleep...'
			time.sleep(.2)
			
			conn = httplib.HTTPConnection(gamesite)
			conn.request("GET", "/%s/%s"%(game,'buy.gsp'),'',hdr)
			r1 = conn.getresponse()
			html = r1.read()
			
			PAGE_SIZE =10
			PAGE_COUNT =  int(getPageNum(html))/PAGE_SIZE + 1
			
			for page in range(1,PAGE_COUNT+1):
				print 'attempt to grep Game=%s Page=%s...'%(game,page)
				html = getPageHtml(game,page)
				g_flog.write( html)
				
				scanRecordsOfHtml(f,html,server[1],server[2])
			f.close()	
			
		except:
			g_logger.error(traceback.format_exc())
	
		
	
#def scanGameServers2(game):
#	url = "/%s/buy.gsp"%(game)
#	gamesite=g_conf.getPropertyValue('root.site')
#	conn = httplib.HTTPConnection(gamesite)
#	conn.request("GET", url)
#	print url
#	r1 = conn.getresponse()
#	html = r1.read()
#	#print html
#	print html
#	g_flog.write( html)
#	
#def scanRecords(file):
#	f = open(file,'r')
#	html = f.read()
#	f.close()
#	regex = '''<span class="realName">(.*?)</span>.*?rank.*?>(.*?)</dd>.*?price.*?>(.*?)</dd>.*?linkTo\('(.*?)','''
#	ms = re.findall(regex,html,re.S)
#	f = open('hgrep.rec.txt','w')
#	conn = getDBConn()
#	
#	for n in ms:
#		f.write("%s,%s,%s,%s\n"%n)
#		try:
#			cr = conn.cursor()
#			sql = "select count(*) from htmlgrep where id=%s"%(n[3])
#			cr.execute(sql)
#			
#			rs = cr.fetchone()
#			if rs[0] == 0 :
#			#if 1:
#				#cr = conn.cursor()
#				sql="insert into htmlgrep values(%s,%s,%s,%s,%s,%s);"				
#				cr.execute(sql,( int(n[3]),n[0],n[2],n[1],int(time.time()),0,))
#				conn.commit()
#			else:
#				sql = "update htmlgrep set disappear_time=0 where id=%s"%(int(n[3]))
#				cr.execute(sql)
#				conn.commit()
#			
#		except:
#			g_logger.error(traceback.format_exc())
#	#如果db内的数据不存在当前缓存内则标记为物品消失,并记录消失时间
#	cr = conn.cursor()
#	cr.execute('select id from htmlgrep order by id')
#	rs = cr.fetchone()
#	while rs:
#		found = False
#		for n in ms:
#			if int(n[3]) == rs[0]:
#				found = True
#				break
#		if not found:
#			cr2 = conn.cursor()
#			sql = "update htmlgrep set disappear_time=%s where id=%s"%(int(time.time()),rs[0])
#			cr2.execute(sql)
#		rs = cr.fetchone()
#		conn.commit()
#	f.close()
#	#print str(ms)
##############################################################
	

class sepApp:
	def	__init__(self):
		self._conf = config.SimpleConfig()		
		 
	
	def getConfig(self):
		return self._conf
	
	#def getDBConn(self):
	#	try:
	#		if self.dbconn == None:
	#			dbhost=self.getPropertyValue('dbhost','localhost')
	#			dbname=self.getPropertyValue('dbname','IpRedirect')
	#			dbuser=self.getPropertyValue('dbuser','postgres')
	#			dbpasswd=self.getPropertyValue('dbpasswd','111111')
	#			self.dbconn = psycopg2.connect(host=dbhost,database=dbname,user=dbuser,password=dbpasswd)
	#	except:
	#		self._log.error(traceback.format_exc())
	#	return self.dbconn
			
	#def resetDBConn(self):
	#	self.dbconn = None
	
	def run(self):
		pass

	def getLogger(self):
		return self._log
	
	def run(self, args):
		 
		return 0

	 

##############################################################
##############################################################

#scanRecords('c:/test - Copy.html')


'''
sql test:
---------------------
--select count(*) from htmlgrep
--select id,count(id) from htmlgrep group by id limit 100
--select * from htmlgrep where id = 2310
--delete from htmlgrep

'''
g_flog = open('c:/test.txt','w')
scanGameServers('mhzx')
sys.exit(0)
if __name__=='__main__':
	if len(sys.argv)<2:
		print 'usage: grep.py scan | build'
		sys.exit()
	if sys.argv[1]=='scan':
		g_flog = open('c:/test.txt','w')
		scanGameServers('mhzx')
	#if sys.argv[1]=='build':
	#	scanRecords('c:/test.txt')
	#server = sepApp()

	
	
		
	