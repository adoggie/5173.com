import base64
import time
import datetime
a = ('aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa')
c = 'YWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWF\r\nhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYW\r\nFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFh'
b = base64.encodestring(a)
d = base64.decodestring(c)
#t = datetime.datetime.today() 
print b
print d
#print time.gmtime(0x4ba315b5)
#print t.microsecond
#print time.ctime(0x4B9DC621)
#print b
#print time.time()  