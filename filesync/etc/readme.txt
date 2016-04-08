2009-12-27 scott 
update to 0.2.0
=========================
1. endpoint 支持自我升级更新
2. sync_server 全新的命令行接口
3. 与gtr_monitor整合命令接口
4.添加命令参数killapp,launchapp



2009-12-26 scott
=========================
sync_server update to 0.1.4
endpoint 0.1.2
1.支持目录和文件过滤


======================================================
======================================================

==============
howto:
======================================================

1.安装vcredist_x86.exe
2.拷贝release/bin,etc,lib到客户机的安装目录
3.运行bin/endpoint.exe 即可

RobotSetting.conf  配置在游戏根目录下，文件定义了游戏机器人的相关信息
	GameProcess=Dnf.exe,crack.exe  游戏使用的相关进程，在停止游戏时将终止这些进程，以,分隔
	RobotPath=robot/robot.exe  游戏运行的执行程序名称，只能携带游戏目录下的相对路径

运行
===============
sync_server.exe [-d filepath | -h host -p port -k [startgame|update|endgame|excbat|killapp|launchapp] ]
 -d filepath  - 计算文件摘要,filepath文件目录
 -h hostname  - 主机ip或者域名
 -p port      - 主机端口
 -k startgame dest  - 加载游戏运行,dest - 远程目录
 -k update src dest - 执行文件同步,src-本地目录;dest-远程目录 
 -k endgame  dest   - 终止游戏,dest - 远程目录
 -k excbat batfile - 执行远程文件,batfile带路径的远程主机批处理文件或者命令[blocked]
 -k shutdown       - 关闭endpoint服务
 -k killapp procname - 终止指定名称的进程
 -k launchapp procname - 创建进程 [nonBlocked]
  

server.conf
========================
适当调整workthreadnum的数量，并打开数据压缩选项 Ice.Override.Compress=1
可以提高并行更新的速度，但要求本地主机的运算能力

配置
==============
etc/
	jerry.conf  -  endpoint 系统的配置参数
	server.conf - 	server系统的配置参数
	hosts.list  - 	游戏客户机主机的ip地址列表

digest.md5	当执行 sync_server.exe update 产生的目录文件摘要信息
hosts.list 	主机列表文件，每一行定义一个ip和游戏名称，
		格式: ip,Game-A 
		一台主机只能运行一款游戏
digest.md5	存在于游戏存储的根目录，每一行表示一个文件，
		格式： filename*filesize*md5_digest		
skipfiles.txt 存在于游戏存储的根目录，每一行表示一个文件,指定不需要进行同步
  例如: 
    dev\cpp_test1\debug
    dev/aaa.txt
    指定以上一个目录和一个文件将被忽略同步


endpoint升级
======================
确保endpoint版本在0.2.0以上;sync_server 0.2.0以上
sync_server.exe -k update 将新的endpoint程序传递到远端主机
sync_server.exe -k launchapp c:\endpoint0.2.0\bin\endpoint.exe "-d 20" 加载endpoint程序，延迟20秒
sync_server.exe -k shutdown  令当前的endpoint服务停止
        
        
        
        
        