import sys,os,socket,traceback,threading



destaddr=("192.168.133.54",12000)

class threadWork(threading.Thread):
  def __init__(self):
    threading.Thread.__init__(self)
    
  def run(self):
    c=0
    while True:
      try:
        sock = socket.socket()
        sock.connect(destaddr)
        print 'connected server....'
        #raise 100
        while True:
          sock.sendall('\x08\x09'*1002)
          r = sock.recv(1,socket.MSG_PEEK)
          if len(r):
            sock.recv(1024)
          #print 'sending...',c
          c+=1
      except:
        print traceback.print_exc()
        
for n in range(1000):
  t = threadWork()
  t.start()