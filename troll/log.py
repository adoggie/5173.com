#-*- coding:utf-8 -*-
import os,time,traceback

class Logger:
	def __init__(self,file=None):
		self._output=['stdout','file']
		self._level=["debug","warning","error","critical"]
		try:
			self._file = open(file,'w')
		except:
			self._file = None
		
	def set_output(self,output):
		'''
		output : ["stdout","file"]
		'''
		self._output = output
	
	def set_level(self,l):
		'''
		level = ["debug","warning","error","critical"]
		'''
		self._level = l
		
	def write(self,msg):
		try:
			ts = time.localtime()
			ts ="%s-%s-%s %s:%s:%s "%(ts[0],ts[1],ts[2],ts[3],ts[4],ts[5])
			msg = ts+ msg 
			try:
				self._output.index('stdout')
				print msg
			except:
				pass
			if self._file:
				self._file.write( msg +'\n')
				self._file.flush()
				raise 1
		except:
			pass

		
		
	def warning(self,msg):
		try:
			self._level.index('warning')
			self.write('WARNING:	'+ msg)		
		except:
			pass
		
	
	def debug(self,msg):
		try:
			self._level.index('debug')
			self.write('DEBUG:	'+ msg)		
		except:
			pass
	
	def error(self,msg):
		try:
			self._level.index('error')			
			self.write('ERROR:	'+ msg)		
		except:
			print  'error not defined'
	
	def critical(self,msg):
		try:
			self._level.index('critical')
			self.write('CRITICAL:	'+ msg)		
		except:
			pass

#l = Logger("a.log")
#l.error('hell')