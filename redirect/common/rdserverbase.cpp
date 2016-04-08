
#include "rdserverbase.h"
#include "../common/util.h"
#include "../common/rdchannel.h"
 

bool RedirectServerBase::start(const std::string& confile){
	bool r = true;
	swlib::SocketAddr addr;
	_confs.loadFromFile(confile);
	_props.connthreadnum = (swUInt16) swlib::str2int(_confs.getProperty("connthreadnum","5"));
	_props.tcpPort = (swUInt16) swlib::str2int(_confs.getProperty("tcpPort","2301"));
	_props.logServer = _confs.getProperty("logserver.host","127.0.0.1");
	_props.logPort = (swUInt16)swlib::str2int(_confs.getProperty("logserver.port","12000"));

	LOG_ADD_UDP_WRITER(_logger,_props.logServer.c_str(),_props.logPort);
	//LOG_ADD_REGFILE_WRITER(_logger,_logfilename.c_str());	

	addr.set_port(_props.tcpPort);
	_listensock = shared_ptr<swlib::TcpSocket>(new swlib::TcpSocket);
	_listensock->create();
	if(!_listensock->bind_addr(addr)){
		printf("Bind failed!(port=%d)\n",_props.tcpPort);
		//getLogger().Error("Bind failed!(port=%d)",_props.tcpPort);
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////////
	//
	//_tgConnect.create(_props.connthreadnum,RedirectServerBase::multiThreadEntry,(void*)this);

	return r;
}

// bool RedirectServerBase::onAccepted(swlib::TcpSocket* sock){
// 	return false;
// }

int RedirectServerBase::end(){
	int r = 0;

	return r;
}

void RedirectServerBase::multiThreadEntry(swlib::Thread* t,void * user){
	RedirectServerBase* server = (RedirectServerBase*)user;
	server->threadEntry(t);
}


 
RedirectChannelID_t RedirectServerBase::newChannelID(){
	static RedirectChannelID_t id=0;
	return id++;
}


RedirectServerBase::RedirectServerBase(){
	_logfilename = "rdserver.log";
}

void RedirectServerBase::threadEntry(swlib::Thread* t){
	// override
}
