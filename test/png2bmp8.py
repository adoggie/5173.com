import sys,os
import Image

img = Image.open('00.png')

>>> img2 = img.convert('P')
>>> img2.save('00.bmp')
>>> img2.mode
'P'
>>> ss = img2.tostring()
>>> len(ss)
262144
>>> f = open('00.256.bmp','wb')
>>> f.write(ss)
>>> f.close()