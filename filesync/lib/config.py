#-*- coding:utf-8 -*-
#
#name: config.py
#brief:
#	系统配置文件
#author: scott
#


import os,sys,time,socket,threading,traceback,socket,select,struct,base64 
import zlib,binascii


class ConfigProperty:
	def __init__(self,owner):
		self.key=''
		self.value=''
	
	def create(self,text):
		#text -  key=value
		#@return: boolean
		pos = text.find('#')
		if(pos !=-1):
			text = text[:pos]
		pair = text.split('=')
		if len(pair) !=2:
			#print "Property Line Invalid:%s"%(text)
			return False
		k = pair[0].strip()
		v = pair[1].strip()
		self.key = k
		self.value = v		
		return True
	
	def toString(self):
		s =''
		try:			
			s = "%s=%s"%(self.key,self.value)			
		except:
			return ''
		return s
	
	def toInt(self):
		r=0
		try:
			r = int(self.value)
		except:
			r =0
		return r
	
	def toFloat(self):
		r=0.0
		try:
			r = float(self.value)
		except:
			r=0.0
		return r
	
	
#@def SimpleConfig
# 简单配置信息文件，基本格式 : key=value
class SimpleConfig:
	def __init__(self):
		self._file=''
		self._props=[]
		self._strip = True
		
	def open(self,file,strip=True):
		#打开配置文件
		#@param strip - 是否裁剪不可见首尾两端的字符
		try:
			self._strip = strip 
			self._props=[]
			fh = open(file,'r')
			lines = fh.readlines()			
			for text in lines:				
				prop = ConfigProperty(self)
				if prop.create(text) == False:					
					prop = None
				else:					
					self._props.append(prop)					
			fh.close()
		except:			
			return False
		return True

	def toString(self):
		s=''
		for p in self._props:
			s = s + p.toString() +"\n"
		return s
	
	def saveAs(self,file):
		#保存配置信息到文件
		try:
			fh = open(file,'w')
			fh.write(toString())
			fh.close()
		except:
			print "write File Failed!"
			return False
		return True
	
	def getProperty(self,name):
		#取属性值
		prop=None
		try:
			for p in self._props:
				if p.key == name:
					prop = p
					break
		except:
			pass
		return prop
	
	def getPropertyValue(self,key,default=''):
		prop = self.getProperty(key)
		if not prop:
			return default
		return prop.value
	
	def getPropertyValueAsInt(self,name,default=0):
		prop = self.getPropertyValue(name)
		if not prop:
			return default
		return prop.toInt()
	
	def getPropertyValueAsFloat(self,name,default=0.0):
		prop = self.getPropertyValue(name)
		if not prop:
			return default
		return prop.toFloat()
	
		
