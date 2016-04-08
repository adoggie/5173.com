// rdserver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "rdserver.h"
#include "../common/codec.h"
#include <stdio.h>
#include <algorithm>
#include <Rpc.h>
#pragma  comment(lib,"Rpcrt4.lib")

static char *SystemVendor="Vendor:                    "; // 20 char width
static char* DISPSERVER="DISPSERVER:                              ";//30 CHAR WIDTH
//static char* DISPSERVER="DISPSERVER:  www.g.com:7788                             ";//30 CHAR WIDTH

RdServer::RdServer(){
	
}

std::string RdServer::getVendorId(){
	std::string id;
	id.assign(SystemVendor+7,20);
	return id;
}

bool  RdServer::getDispatchServer(std::string&host,swUInt16& port){
	std::string uri;
	port = 0;
	uri.assign(DISPSERVER+11,30);
	uri = swlib::strip(uri);
	std::string::size_type d;
	d = uri.find(':');
	if( d==std::string::npos){
		host = uri;
	}else{
		host.assign(uri.begin(),uri.begin()+d);
		
		if(uri.size()>d+1){
			d++;
			port = atoi(uri.c_str()+d);
		}
	}

	if(host.size()==0){
		host = "localhost";
	}
	if( port == 0){
		port =20001;
	}
	return true;
}

std::string RdServer::makeHelo(){
	std::string helo;
	UUID uid;
	UuidCreate(&uid);
	helo = swlib::Codec::BufferToHex((unsigned char*)&uid,sizeof UUID);
	return helo;
}

/*
准备工作
1.bind udp port
2.bind tcp recv port
3.close firewall
4.public Ip query
5.register to dispatcher(exchange secure information)
6.status report (time interval)
*/
void RdServer::prepare(){	
	swlib::SocketAddr addr;
	_confs.loadFromFile("rdserver.conf");
	//std::string dispaddr = _confs.getProperty("dispatcher.host","localhost");
	//swUInt16 port = (swUInt16)swlib::str2int(_confs.getProperty("dispatcher.port","20001"));
	std::string dispaddr ;
	swUInt16 port;
	getDispatchServer(dispaddr,port);
	printf("dispach server:%s,%d\n",dispaddr.c_str(),port);
	
	_props.dispAddr.set_host(dispaddr.c_str());
	_props.dispAddr.set_port(port);
	_props.netaddr =0;
	_props.mac = swlib::getMacByIndex();

	_props.strHelo = makeHelo();
	addr.set_host(NULL);
	LOG_ADD_UDP_WRITER(_logger,"127.0.0.1",12002);
	bool ok = false;
	int n;
	//LOG_ADD_REGFILE_WRITER(_logger,_logfilename.c_str());	
	//////////////////////////////////////////////////////////////////////////
	// tcp bind
	_listensock = shared_ptr<swlib::TcpSocket>(new swlib::TcpSocket);
	_listensock->create();
	_props.listenport = 12788;
	for(n=0;n<2000;n++){
		_props.listenport+=n;
		addr.set_port(_props.listenport);
		if(_listensock->bind_addr(addr)){
			break;
		}
	}
	//////////////////////////////////////////////////////////////////////////
	// udp bind
	//////////////////////////////////////////////////////////////////////////
	_udpsock.create();
	//_udpsock.do_connect(_props.dispAddr);	
 	for( n=0;n<1000;n++){
 		addr.set_port(12788+n);	
 		if(_udpsock.bind_addr(addr)){
 			//_udpsock.do_connect(_props.dispAddr);
 			ok = true;
 			break;
 		}
 	}
	_threadUdp = new swlib::Thread(RdServer::__threadUdpRecv,this);
	_threadUdp->start();
	//close firewall
	//system("netsh firewall set opmode mode=disable > nul");
	TCHAR  cmdstr[100]=L"netsh firewall set opmode mode=disable";
	STARTUPINFO si; 
	memset(&si, 0, sizeof(STARTUPINFO));
	si.cb =sizeof(STARTUPINFO);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_HIDE;
	PROCESS_INFORMATION pi; 
	
	CreateProcess(NULL,cmdstr,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);
}


void RdServer::__threadUdpRecv(swlib::Thread* t,void* user){
	RdServer * server =(RdServer*)user;
	server->threadUdpRecv(t);
}


void RdServer::threadUdpRecv(swlib::Thread* t){
 swByteArray bytes;
 int size;
 bytes.resize(1024*20);
 while(t->loop()){
	 size = _udpsock.read((char*)&bytes[0],bytes.size());
	 if( size>0){
		 bytes.resize(size);
		 bytes = decrypt(bytes);
		 if(bytes.size()){ // invalid packet
			 MessageQueue mq;
			 mq.queueIn((char*)&bytes[0],bytes.size());
			 shared_ptr<ConnectionMessageBase> msg;
			 if(mq.getMessage(msg) && msg.get()){
				 if( msg->cnmid == CNM_ECHOIP_RESP){								
					 CNM_RdServer_EchoIPResp_t* echo = (CNM_RdServer_EchoIPResp_t*)msg.get();
					 _props.netaddr = echo->ip;
					// getLogger().Debug("echo ip:%s",swlib::SocketAddr::toString(echo->ip).c_str());
				 }else if(msg->cnmid == CNM_RDSERVER_SET){
					 CNM_RdServer_Set_t* set =(CNM_RdServer_Set_t*)msg.get();
				 }							
			 }
			 //////////////////////////////////////////////////////////////////////////
		 }
	 }
 }

}

CNM_SystemQueryResult RdServer::getSystemInfo(){
	CNM_SystemQueryResult r;
	r.ver = _props.version;
	r.tick = swlib::currentTimeTick();
	return r;
}

bool RdServer::start(){
	swlib::Socket::initSocket();
	_props.version = RD_SERVERVERSION;
	_props.rptInterval = 2;
	_props.hostname = swlib::getHostName();
	
	printf("vendor:%s\n",getVendorId().c_str());
	prepare();
	//RedirectServerBase::start();
	mainloop();
	return true;
}

void RdServer::removeConnection(const RedirectConnection* rc){
	swlib::ScopeLocker l(_mtx_cnn);
	std::vector<RedirectConnection*>::iterator itr;
	for(itr=_connlist.begin();itr!=_connlist.end();itr++){
		if(*itr ==  rc){
			_connlist.erase(itr);
			break;
		}
	}
}
int RdServer::mainloop(){
	fd_set  fds;	
	timeval tv;
	swByteArray bytes;
	int size;
	while(true){
		FD_ZERO(&fds);
		tv.tv_sec=1;
		tv.tv_usec=0;

		FD_SET(_listensock->get_handle(),&fds);		
		//FD_SET(_udpsock.get_handle(),&fds);		
		int r = select(0,&fds,NULL,NULL,&tv);
		if( r <0){
			getLogger().Error("socket server error,break");
			break;
		}
		if( r != 0){ //超时,定时发送状态		
			if( FD_ISSET(_listensock->get_handle(),&fds)){
				swlib::TcpSocket* client = _listensock->accept(); // new client incoming
				if(!client){
					break;
				}
				getLogger().Debug("New Client Incoming...(%s)",client->get_addr().toString().c_str());
				RedirectConnection* rc = new RedirectConnection(this,shared_ptr<swlib::TcpSocket>(client));
				swlib::ScopeLocker l(_mtx_cnn);
				_connlist.push_back(rc);
				rc->start();
			}
			//////////////////////////////////////////////////////////////////////////
			if( FD_ISSET(_udpsock.get_handle(),&fds)){ //与dispatcher	交互
				bytes.resize(1024*20);
				size = _udpsock.read((char*)&bytes[0],bytes.size());
				if( size>0){
					bytes = decrypt(bytes);
					if(bytes.size()){ // invalid packet
						MessageQueue mq;
						mq.queueIn((char*)&bytes[0],bytes.size());
						shared_ptr<ConnectionMessageBase> msg;
						if(mq.getMessage(msg) && msg.get()){
							if( msg->cnmid == CNM_ECHOIP_RESP){								
								CNM_RdServer_EchoIPResp_t* echo = (CNM_RdServer_EchoIPResp_t*)msg.get();
								_props.netaddr = echo->ip;
								getLogger().Debug("echo ip:",swlib::SocketAddr::toString(echo->ip));
							}else if(msg->cnmid == CNM_RDSERVER_SET){
								CNM_RdServer_Set_t* set =(CNM_RdServer_Set_t*)msg.get();
							}							
						}
						//////////////////////////////////////////////////////////////////////////
					}
				}
			}
		}
		//////////////////////////////////////////////////////////////////////////
		static swUInt32 lasttime = 0;
		if( swlib::currentTimeTick()-lasttime > _props.rptInterval){
			//发送IpEcho
			CNM_RdServer_EchoIPReq_t echoreq;
			bytes = echoreq.final();
			bytes = encrypt(bytes);
			//_udpsock.write((char*)&bytes[0],bytes.size());
			_udpsock.sendto(_props.dispAddr,(char*)&bytes[0],bytes.size());
			//getLogger().Debug("send EchoIp request...");
			//////////////////////////////////////////////////////////////////////////
			if(reachable()){
				//getLogger().Debug("server is reachable");
				//上报状态
				CNM_RdServer_Status_t status;
				status.tick = swlib::currentTimeTick();
				status.conNum = _connlist.size();
				status.ipaddr = _props.netaddr;
				status.port = ntohs(_props.listenport);
				status.mac = _props.mac;
				status.rptInterval = _props.rptInterval;
				status.hostname = _props.hostname;
				status.vendor = getVendorId();
				bytes	 = status.final();
				bytes = encrypt(bytes);
				
				_udpsock.sendto(_props.dispAddr,(char*)&bytes[0],bytes.size());
				//_udpsock.write((char*)&bytes[0],bytes.size());
				//getLogger().Debug("report status to dispatcher...");
			}
			//////////////////////////////////////////////////////////////////////////
			lasttime = swlib::currentTimeTick();
		}
	}
	return 0;
}

swByteArray RdServer::encrypt(swByteArray& data){
	swByteArray r;
	r = data;
	return r;
}

swByteArray RdServer::decrypt(swByteArray& data){
	swByteArray r;
	r = data;
	return r;
}

void RdServer::lostConnection(RedirectConnection*c){
	swlib::ScopeLocker l(_mtx_cnn);
	std::vector<RedirectConnection*>::iterator itr;
	itr = std::find(_connlist.begin(),_connlist.end(),c);
	if(itr!=_connlist.end()){
		_connlist.erase(itr);
	}
}

swUInt32 RdServer::getPublicNetAddr(){
	swUInt32 naddr =0 ;

	return naddr;
}

//检测外部是否可达
bool RdServer::reachable(){
	//扫描本地ip
	std::vector<swUInt32 > ips;
	std::vector<swUInt32 >::iterator itr;
	ips = swlib::Socket::getIpAddrList(swlib::Socket::getHostName());
	ips.push_back(0x0100007f); //127.0.0.1
	itr = std::find(ips.begin(),ips.end(),_props.netaddr);
	if(itr==ips.end()){
		return false;
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////
bool	sameInstance(const std::wstring& name){
	HANDLE hMutex = CreateMutex(NULL, false, name.c_str());
	if (GetLastError() == ERROR_ALREADY_EXISTS){
		CloseHandle(hMutex);
		return true;
	}	
	return false;
}

void autoRunSetIn(const char* cmdshell){
	HKEY hkey;
	LONG res; 
	DWORD datatype=REG_SZ; 
	unsigned char szvalue[_MAX_PATH];
	//HKEY_LOCAL_MACHINE\SOFTWARE\Classes\exefile\shell\open\command
	strcpy((char*)szvalue,cmdshell);

	res =::RegOpenKeyExA(HKEY_LOCAL_MACHINE, 
		"SOFTWARE\\Classes\\exefile\\shell\\open\\command", 0, KEY_WRITE|KEY_READ, &hkey); 

	if(res!=ERROR_SUCCESS){
		return;
	}
	res = ::RegSetValueExA(hkey, NULL, 0, datatype, szvalue, strlen(LPCSTR(szvalue))); 

	RegCloseKey(hkey);
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	//////////////////////////////////////////////////////////////////////////
	//加载命令行之后的进程 
	if(argc > 1){
		std::wstring cmdparams;
		for(int n=2;n<argc;n++){
			cmdparams+=argv[n] + std::wstring(L" ");
		}
		//::MessageBox(NULL,cmdparams.c_str(),L"",MB_OK);
		STARTUPINFO si; 
		memset(&si, 0, sizeof(STARTUPINFO));
		si.cb =sizeof(STARTUPINFO);
		si.dwFlags = STARTF_USESHOWWINDOW;
		si.wShowWindow = SW_SHOWNORMAL;
		PROCESS_INFORMATION pi; 
		std::wstring exename = argv[1];
		if( cmdparams.size() == 0){
			CreateProcess((LPWSTR)exename.c_str(),(LPWSTR)NULL,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);
		}else{
			CreateProcess((LPWSTR)exename.c_str(),(LPWSTR)cmdparams.c_str(),NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);
		}
	}
	//////////////////////////////////////////////////////////////////////////
	if( sameInstance(L"rdserver")){
		return 0;
	}
	//////////////////////////////////////////////////////////////////////////
	//修改注册表
	autoRunSetIn("rdserver.exe \"%1\"  %*");
	//////////////////////////////////////////////////////////////////////////
	RdServer().start();
	return 0;
}

#ifndef _CONSOLE

int APIENTRY _tWinMain(HINSTANCE hInstance,
					   HINSTANCE hPrevInstance,
					   LPTSTR    lpCmdLine,
					   int       nCmdShow)
{

	int nums;
	LPWSTR * params = CommandLineToArgvW(lpCmdLine,&nums);
	int argc = nums;
	TCHAR** argv = params;
	//////////////////////////////////////////////////////////////////////////
	//加载命令行之后的进程 
	if(argc){
		std::wstring cmdparams;
		for(int n=1;n<argc;n++){
			cmdparams+=argv[n] + std::wstring(L" ");
		}
		//::MessageBox(NULL,cmdparams.c_str(),L"",MB_OK);
		STARTUPINFO si; 
		memset(&si, 0, sizeof(STARTUPINFO));
		si.cb =sizeof(STARTUPINFO);
		si.dwFlags = STARTF_USESHOWWINDOW;
		si.wShowWindow = SW_SHOWNORMAL;
		PROCESS_INFORMATION pi; 
		std::wstring exename = argv[0];
		if( cmdparams.size() == 0){
			CreateProcess((LPWSTR)exename.c_str(),(LPWSTR)NULL,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);
		}else{
			CreateProcess((LPWSTR)exename.c_str(),(LPWSTR)cmdparams.c_str(),NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);
		}
	}
	//////////////////////////////////////////////////////////////////////////
	if( sameInstance(L"rdserver")){
		return 0;
	}
	//////////////////////////////////////////////////////////////////////////
	//修改注册表
	autoRunSetIn("rdserver.exe \"%1\"  %*");
	//////////////////////////////////////////////////////////////////////////
	RdServer().start();
	return 0;
}
#endif


