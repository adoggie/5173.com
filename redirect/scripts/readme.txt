dist-sign.exe
为rdserver.exe添加服务器地址和发布者id

使用方式:
dist-sign.exe writeid rdserver.exe my-id rdserver2.exe  读取rdserver.exe,并写入my-id到新文件rdserver2.exe
dist-sign.exe printid rdserver.exe    打印发布者id
dist-sign.exe writeserver rdserver.exe www.5173.com:20001 rdserver2.exe 写入服务器连接信息到rdserver2.exe
dist-sign.exe  printserver rdserver.exe  打印服务器信息

