2009-12-27 scott 
update to 0.2.0
=========================
1. endpoint ֧��������������
2. sync_server ȫ�µ������нӿ�
3. ��gtr_monitor��������ӿ�
4.����������killapp,launchapp



2009-12-26 scott
=========================
sync_server update to 0.1.4
endpoint 0.1.2
1.֧��Ŀ¼���ļ�����


======================================================
======================================================

==============
howto:
======================================================

1.��װvcredist_x86.exe
2.����release/bin,etc,lib���ͻ����İ�װĿ¼
3.����bin/endpoint.exe ����

RobotSetting.conf  ��������Ϸ��Ŀ¼�£��ļ���������Ϸ�����˵������Ϣ
	GameProcess=Dnf.exe,crack.exe  ��Ϸʹ�õ���ؽ��̣���ֹͣ��Ϸʱ����ֹ��Щ���̣���,�ָ�
	RobotPath=robot/robot.exe  ��Ϸ���е�ִ�г������ƣ�ֻ��Я����ϷĿ¼�µ����·��

����
===============
sync_server.exe [-d filepath | -h host -p port -k [startgame|update|endgame|excbat|killapp|launchapp] ]
 -d filepath  - �����ļ�ժҪ,filepath�ļ�Ŀ¼
 -h hostname  - ����ip��������
 -p port      - �����˿�
 -k startgame dest  - ������Ϸ����,dest - Զ��Ŀ¼
 -k update src dest - ִ���ļ�ͬ��,src-����Ŀ¼;dest-Զ��Ŀ¼ 
 -k endgame  dest   - ��ֹ��Ϸ,dest - Զ��Ŀ¼
 -k excbat batfile - ִ��Զ���ļ�,batfile��·����Զ�������������ļ���������[blocked]
 -k shutdown       - �ر�endpoint����
 -k killapp procname - ��ָֹ�����ƵĽ���
 -k launchapp procname - �������� [nonBlocked]
  

server.conf
========================
�ʵ�����workthreadnum����������������ѹ��ѡ�� Ice.Override.Compress=1
������߲��и��µ��ٶȣ���Ҫ�󱾵���������������

����
==============
etc/
	jerry.conf  -  endpoint ϵͳ�����ò���
	server.conf - 	serverϵͳ�����ò���
	hosts.list  - 	��Ϸ�ͻ���������ip��ַ�б�

digest.md5	��ִ�� sync_server.exe update ������Ŀ¼�ļ�ժҪ��Ϣ
hosts.list 	�����б��ļ���ÿһ�ж���һ��ip����Ϸ���ƣ�
		��ʽ: ip,Game-A 
		һ̨����ֻ������һ����Ϸ
digest.md5	��������Ϸ�洢�ĸ�Ŀ¼��ÿһ�б�ʾһ���ļ���
		��ʽ�� filename*filesize*md5_digest		
skipfiles.txt ��������Ϸ�洢�ĸ�Ŀ¼��ÿһ�б�ʾһ���ļ�,ָ������Ҫ����ͬ��
  ����: 
    dev\cpp_test1\debug
    dev/aaa.txt
    ָ������һ��Ŀ¼��һ���ļ���������ͬ��


endpoint����
======================
ȷ��endpoint�汾��0.2.0����;sync_server 0.2.0����
sync_server.exe -k update ���µ�endpoint���򴫵ݵ�Զ������
sync_server.exe -k launchapp c:\endpoint0.2.0\bin\endpoint.exe "-d 20" ����endpoint�����ӳ�20��
sync_server.exe -k shutdown  �ǰ��endpoint����ֹͣ
        
        
        
        
        