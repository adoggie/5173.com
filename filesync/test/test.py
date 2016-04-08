# -*- coding:utf-8 -*-
import os,os.path

import os
#print unicode(game.path,'gb2312')
f = open('c:/f.txt')
file = f.readlines()[0].strip()
print file
fp= open(file.decode('utf-8'),'w')

