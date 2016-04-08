// rdfront.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../common/codec.h"
#include "rdfront.h"
#include "rpcFront.h"
#include "lsp.h"



//get from dispatcher
shared_ptr<swlib::SocketAddr> RdFront::getRdserverAddr(){
	shared_ptr<swlib::SocketAddr> addr;
	
	rd::RdFrontInfoT front;
	try{
		rd::RdServerInfoListT addrlist = _dispPrx->getBastRdServers(_worksheet.areaName,1,front);
		if(addrlist.size()){
			rd::RdServerInfoT server = addrlist[0];
			addr = new swlib::SocketAddr;
			addr->set_host(server.ip.c_str());
			addr->set_port((swUInt16)server.port);
		}
	}catch(const std::exception& e){
		getLogger().Debug(e.what());
	}
	return addr;
}


void RdFront::getRdserverAddrList(){
	_rdserverlist.clear();
	rd::RdFrontInfoT front;
	try{
		rd::RdServerInfoListT addrlist = _dispPrx->getBastRdServers(_worksheet.areaName,3,front);
		for(size_t n=0;n<addrlist.size();n++){
			rd::RdServerInfoT server = addrlist[0];
			swlib::SocketAddr addr ;
			addr.set_host(server.ip.c_str());
			addr.set_port((swUInt16)server.port);
			//_rdserverlist.push_back(addr);
			getLogger().Debug("get rdserver:%s",addr.toString().c_str());
		}
		_rdserverlist = addrlist;
	
	}catch(const std::exception& e){
		getLogger().Debug(e.what());
	}
 
	
}

/*
sockRdserver断开必须关闭与客户的socket，因为客户的数据可能有部分通过sockRdserver发送了，导致不完整
*/
bool RdFront::doSelect(){
	
	if( _connRdserver_corrupt ){
		getLogger().Debug("Prepare Contact Rdserver...");
		swlib::ScopeLocker l1(_mtx_socks);	
		_sock_rdserver.create();
		_socks.clear();		//删除所有客户连接 
		Sleep(1000*2);
		while( _serverRunning){
// 			getLogger().Debug("get Rdserver from Dispatcher..");
// 			shared_ptr<swlib::SocketAddr> addrserver = getRdserverAddr();
// 			if(!addrserver.get()){
// 				getLogger().Debug("Have no Rdserver can be served! Wait for senconds...");
// 				Sleep(1000*5);//
// 				continue;
// 			}
// 			getLogger().Debug("ready to connect rdserver:%s",addrserver->toString().c_str());
// 			if(!_sock_rdserver.do_connect(*addrserver.get())){		 //需要修改成超时链接
// 				Sleep(1000*5); //连接rdserver失败
// 				continue;
// 			}
			bool connected = false;
			_connection_auth_passed = false;
			//std::vector<swlib::SocketAddr> rdservers;
			rd::RdServerInfoListT rdservers;
			
			{
				swlib::ScopeLocker ll(_mtx_servers);
				rdservers = _rdserverlist;
			}
			for(size_t n=0;n<rdservers.size();n++){
				//getLogger().Debug("attempt to connect server:%s",rdservers[n].toString().c_str());
				getLogger().Debug("attempt to connect server:%s",rdservers[n].ip.c_str());
				swlib::SocketAddr addr;
				addr.set_host(rdservers[n].ip.c_str());
				addr.set_nport((swUInt16)rdservers[n].port);
				connected = _sock_rdserver.do_connect(addr,5); //
				if(connected){
					//report to dispacher
					rd::RdServerInfoT* server = new rd::RdServerInfoT;
					*server = rdservers[n];
					_sock_rdserver.setData(1000,server);
					connectedRdServer(*server);
					break;
				}
			}
			if( !connected){
				Sleep(100*2);  //尽量小，保证prepareWorkSheet()的及时反应 
				continue;
			}
			getLogger().Debug("connected to server ,next...");
			_connRdserver_corrupt = false;
			swlib::ScopeLocker l(_mtx_msg_incoming);
			_mq_incoming.reset();

			return true;
		}
	}
// 	if(_connection_auth_passed == false){
// 		Sleep(200);
// 		return true;
// 	}
	if( !_serverRunning){
		getLogger().Debug("serverRuning is false ,break!");
		return false;
	}
	//////////////////////////////////////////////////////////////////////////
	shared_ptr<swlib::TcpSocket> readsock;
	//////////////////////////////////////////////////////////////////////////
	std::map<RedirectChannelID_t, shared_ptr<swlib::TcpSocket> >::iterator itr;
	std::map<RedirectChannelID_t, shared_ptr<swlib::TcpSocket> > socks;
	{
		swlib::ScopeLocker l1(_mtx_socks);	
		for(size_t n=0;n<_closedChannels.size();n++){
			itr = _socks.find(_closedChannels[n]);
			if(itr!=_socks.end()){
				readsock = itr->second;
				MessageQueue* mq = (MessageQueue*)readsock->data(stt_BUFFER);
				delete mq;		//删除缓冲队列
				_socks.erase(itr);
				getLogger().Debug("clear one Incoming Sock client");
			}		
		}
		_closedChannels.clear();
		
// 		for(int n=0;n<_halfclosedChannels.size();n++){
// 			itr = _socks.find(_halfclosedChannels[n]);
// 			if(itr!=_socks.end()){
// 				readsock = itr->second;
// 				MessageQueue* mq = (MessageQueue*)readsock->data(stt_BUFFER);
// 				delete mq;		//删除缓冲队列
// 				_socks.erase(itr);
// 			}		
// 		}
		_halfclosedChannels.clear();
		socks = _socks;
	}
	//////////////////////////////////////////////////////////////////////////
	
	{
		//swlib::ScopeLocker l(_mtx_select);
		fd_set  fds;
		FD_ZERO(&fds);
		
		for(itr=_socks.begin();itr!=_socks.end();itr++){
			swBool enable = (swBool)itr->second->data(stt_ENABLED);
			if(enable == swTrue){
				FD_SET(itr->second->get_handle(),&fds);			
			}
		}
		
		FD_SET(_sock_rdserver.get_handle(),&fds);
		FD_SET(_listensock->get_handle(),&fds);
		timeval tv;
		tv.tv_sec = 0;
		tv.tv_usec =1000*200;
		int r = select(0,&fds,NULL,NULL,&tv);
		if( r ==0){	// timeout
		//	getLogger().Debug("select timeout,no data traverse");
			return true;
		}
		if( r<0){ // exception	 非可用socket参与了select
			//Sleep(500);	 //套接字被显式的关闭，然后又参与了select
			getLogger().Error("select socket error! breaking...");
			return false;
		}
		//////////////////////////////////////////////////////////////////////////
		//游戏进程连接进入
		if( FD_ISSET(_listensock->get_handle(), &fds) ){ //新连接到达
			swlib::TcpSocket * insock = _listensock->accept();
			if(insock){
				getLogger().Debug("Incoming Client:%s",insock->get_addr().toString().c_str());
				insock->setData((void*)INCOMING_SOCKET);
				RedirectChannelID_t cid;
				cid = newChannelID();
				insock->setData(stt_CHANNELID,(void*)cid);
				insock->setData(stt_ENABLED,(void*)swFalse); // 
				insock->setData(stt_CLOSED,(void*)swFalse);
				insock->setData(stt_BUFFER,(void*)new MessageQueue());
				//insock->setData(stt_MSGQUEUE_BACK,(void*)new std::list<shared_ptr<ConnectionMessageBase> >());
				
				//
				shared_ptr<RedirectAddress_t> raddr = getRedirectAddress();
				if(raddr.get()){	// 发送通道打开请求
					shared_ptr<CM_ConnectOpen_t> msg(new CM_ConnectOpen_t);
					getLogger().Debug("Next Destination Address:%s",raddr->toString().c_str());
					msg->addr = raddr->get_naddr();
					msg->port = raddr->get_port();
					msg->timeout = 5; //5秒超时
					msg->cid = cid;
					swlib::ScopeLocker l2(_mtx_msg_outgoing);
					_msglist_outgoing.push_back(msg);
					_cond_msg_outgoing.set();
					swlib::ScopeLocker l1(_mtx_socks);	
					_socks[cid] = shared_ptr<swlib::TcpSocket>(insock);
					//getLogger().Debug("made channel Open request into sending queue ...");
				}				
			}
		}
		//////////////////////////////////////////////////////////////////////////
		//检测游戏进程发送的数据
		swByteArray bytes;
		bytes.resize(1024*6);
		int size;
		
		for(itr=socks.begin();itr!=socks.end();itr++){
			if( FD_ISSET(itr->second->get_handle(),&fds)){
				readsock = itr->second;
				//////////////////////////////////////////////////////////////////////////
				size = readsock->read((char*)&bytes[0],bytes.size());
				if( size <= 0){
					RedirectChannelID_t cid = (RedirectChannelID_t)readsock->data(stt_CHANNELID);
					swlib::ScopeLocker l1(_mtx_socks);	
					_closedChannels.push_back(cid);
					shared_ptr<ChannelMessageBase> msgclose = new ChannelMessageBase(CM_CONNECT_CLOSE);
					msgclose->cid = cid;
					swlib::ScopeLocker l2(_mtx_msg_outgoing);
					_msglist_outgoing.push_back(msgclose);
					getLogger().Debug("Incoming Client Sock lost:%s,push into Erase queue...",readsock->get_addr().toString().c_str());
				}else{
					MessageQueue *mq= (MessageQueue*)readsock->data(stt_BUFFER);
					swBool ok = (swBool)readsock->data(stt_ENABLED) ;
					if(ok == swFalse){ //未得到服务器应答要缓冲数据						
						mq->queueIn((char*)&bytes[0],size);	
						getLogger().Debug("client sock havn't got Accept answer,so recved data will be cached into socket's message-queue...");
					}else{
						mq->getBuffer().insert(mq->getBuffer().end(),bytes.begin(),bytes.begin()+size);						
						CM_StreamData* stream = new CM_StreamData;
						stream->cid = (swInt32) readsock->data(stt_CHANNELID);
						stream->data = mq->getBuffer();
						shared_ptr<ConnectionMessageBase> msg(stream);						
						swlib::ScopeLocker l2(_mtx_msg_outgoing);
						_msglist_outgoing.push_back(msg);
						mq->reset();
						getLogger().Debug("client sock incoming data will be queue into sending buffer for sending to Rdserver!");
					}
				}
			}
		}	// -- end for
		//////////////////////////////////////////////////////////////////////////
		if( FD_ISSET(_sock_rdserver.get_handle(), &fds) ){ 
			size = _sock_rdserver.read((char*)&bytes[0],bytes.size());
			if( size <= 0){
				_connRdserver_corrupt = true;
				getLogger().Debug("Rdserver lost connection!");
				rd::RdServerInfoT* server=NULL;
				server =(rd::RdServerInfoT*)_sock_rdserver.data(1000);
				disconnectedRdServer(*server);
				delete server;
				return true;
			}else{
				getLogger().Debug("data recved from rdserver will be queue into backing buffer...");
				swlib::ScopeLocker l(_mtx_msg_incoming);
				_mq_incoming.queueIn((char*)&bytes[0],size);
				_cond_msg_incoming.set();
			}
		}
		//////////////////////////////////////////////////////////////////////////
	}
	recieveMessage();
	return true;
}

void RdFront::doChannelMessage(shared_ptr<ConnectionMessageBase>& msg){
	
	ChannelMessageBase* cm = (ChannelMessageBase*)msg.get();
	RedirectChannelID_t channelId;
	channelId = cm->cid;
	CM_StreamData* stream = (CM_StreamData*)cm;
	shared_ptr<swlib::TcpSocket> client;
	getLogger().Debug("Channel Message:%d",msg->cnmid);
	if(1){
		swlib::ScopeLocker l1(_mtx_socks);
		std::map<RedirectChannelID_t, shared_ptr<swlib::TcpSocket> >::iterator itr;
		itr = _socks.find(channelId);
		if(itr!=_socks.end()){
			client = itr->second;
		}
	}
	//////////////////////////////////////////////////////////////////////////
	if( !client.get()){
		return;
	}
	//std::list<shared_ptr<ConnectionMessageBase> >* queue = (std::list<shared_ptr<ConnectionMessageBase> >*)client->data(stt_MSGQUEUE_BACK);
	
	if( cm->cmid == CM_CONNECT_CLOSE ||cm->cmid == CM_CONNECT_REJECT || cm->cmid == CM_CONNECT_HALFCLOSE){
		swlib::ScopeLocker l1(_mtx_socks);	
		getLogger().Debug("Channel Reject/Close/HalfClose:%d",cm->cid);
		client->setData(stt_CLOSED,(void*)swTrue);
		_closedChannels.push_back(channelId);
	}else if(cm->cmid == CM_STREAM_DATA){	
		getLogger().Debug("<< CM_STREAM_DATA %d incoming(%d bytes)",cm->cid,stream->data.size());
		client->write((char*)&stream->data[0],stream->data.size());		
// 	}else if(cm->cmid == CM_CONNECT_HALFCLOSE ){
// 		swlib::ScopeLocker l1(_mtx_socks);	
// 		_halfclosedChannels.push_back(channelId);
	}else if(cm->cmid == CM_CONNECT_ACCEPT){
		 client->setData(stt_ENABLED,(void*)swTrue);
		 getLogger().Debug("Channel Accept %d",cm->cid);
		
	}
}

void RdFront::doConnectiontMessage(shared_ptr<ConnectionMessageBase>&msg_){
	//服务器发送greet消息
	if(msg_->cnmid == CNM_HELO){
		CNM_Helo_t* msg = (CNM_Helo_t*)msg_.get();
		std::string key = getConfig().getProperty("secureKey");
		swByteArray data;
		data.assign( (swByte*)msg->helo.c_str(),(swByte*)(msg->helo.c_str()+msg->helo.size()) );
		data.insert(data.end(),(swByte*)key.c_str(),(swByte*)(key.c_str()+key.size()));
		swByteArray digest = swlib::Codec::Md5Calc(&data[0],data.size());
		
		CNM_Auth_t auth;
		//auth.secureKey = digest;
		memcpy(auth.secureKey,&digest[0],16);
		getLogger().Debug("get CNM_HELO from rdServer");
		data = auth.final();
		_sock_rdserver.write((char*)&data[0],data.size());
		getLogger().Debug("send Auth Message");

	}else if(msg_->cnmid == CNM_ACCEPT){
		getLogger().Debug("<<CNM_ACCEPT");
		_connection_auth_passed = true;
	}else if(msg_->cnmid ==CNM_REJECT){
		 _connRdserver_corrupt = true;
		getLogger().Debug("<< CNM_REJECT");
	}else if(msg_->cnmid ==CNM_HEARTBEAT){
		getLogger().Debug("<< CNM_HEARTBEAT");
	}
}

void RdFront::recieveMessage(){
	while(true){
		shared_ptr<ConnectionMessageBase> msg;
		if(!_mq_incoming.getMessage(msg)){
			_connRdserver_corrupt = true;		
			_mq_incoming.reset();
			getLogger().Debug("dirty connection data, invalid rdServer connection!");
			break;
		}
		if( !msg.get()){ //没有消息包
			getLogger().Debug("incoming queue from rdserver is empty!");
			break;
		}
		if( msg->cnmid ==  CNM_CHANNEL){
			doChannelMessage(msg);
		}else{
			doConnectiontMessage(msg);
		}
	}
}

void RdFront::threadEntry(swlib::Thread* t){
	return ;
	//接收线程组，从rdserver进入的数据包
	while(t->loop()){
		//_cond_msg_incoming.wait(20);
		{
			if(!t->loop()){
				break;
			}
			//////////////////////////////////////////////////////////////////////////
			shared_ptr<ConnectionMessageBase> msg;
			{
				swlib::ScopeLocker l(_mtx_msg_incoming);
				if(!_mq_incoming.getMessage(msg)){
					//数据包错误，关闭连接
					_connRdserver_corrupt = true;		
					_mq_incoming.reset();
					getLogger().Debug("dirty connection data, invalid rdServer connection!");
					continue;
				}
			}
			if( !msg.get()){ //队列为空
				 //_cond_msg_incoming.set(false);
				 _cond_msg_incoming.wait(20);
				 //getLogger().Debug("rdserver line have no message come in!");
				 continue; // 
			}
			getLogger().Debug("mq_incoming queue size:%d",_mq_incoming.getBuffer().size());
			//////////////////////////////////////////////////////////////////////////
			if( msg->cnmid ==  CNM_CHANNEL){
				doChannelMessage(msg);
			}else{
				doConnectiontMessage(msg);
			}
			
			//_cond_msg_incoming.set(false);
		}
	}// end while
}

//发送线程
void RdFront::threadRdserverConn(swlib::Thread* t,void* user){
	RdFront* server = (RdFront*)user;
	while(t->loop()){
		server->_cond_msg_outgoing.wait(200);
		{
			if(!t->loop()){
				break;
			}
			while(t->loop()){
				shared_ptr<ConnectionMessageBase> msg;
				{
					swlib::ScopeLocker l(server->_mtx_msg_outgoing);				 
					if( server->_msglist_outgoing.size()){					
						msg = server->_msglist_outgoing.front();
						server->_msglist_outgoing.pop_front();
					}
				}
				if(!msg.get()){
					break;
				}
				swByteArray bytes = msg->final();
				server->getLogger().Debug("send data to rdSever...");
				int sent = server->_sock_rdserver.write((char*)&bytes[0],bytes.size());
				if(sent == -1){ // lost connection with rdserver
					 swlib::ScopeLocker l(server->_mtx_msg_outgoing);		
					 server->_msglist_outgoing.clear();
					 server->_connRdserver_corrupt = true;
					 break;
				}
			}//-- end while
			server->_cond_msg_outgoing.set(false); //下一次需要阻塞了
		}
	}// end while
}

bool RdFront::start(const std::string& confile){
	swlib::Socket::initSocket();
	_connection_auth_passed = false;
	if(!RedirectServerBase::start(confile)){
		printf("rdFront::start() failed!\n");
		return false;
	}
	_tgConnect.create(_props.connthreadnum,RedirectServerBase::multiThreadEntry,(void*)this);
// 	swlib::SocketAddr addr ;//= getRedirectAddress();
// 	addr.set_host("127.0.0.1"); // for python gameserver.py
// 	addr.set_port(12009);
// 	swlib::TcpSocket tsock;
// 	tsock.create();
// 	tsock.do_connect(addr);
	
	//Init Ice Enviroment
	//////////////////////////////////////////////////////////////////////////
	int argc;
	//char* argv[]={"this","--Ice.Config=userver.ice.conf"};
	char* argv[]={"this","--Ice.Config=rdfront.conf"};
	argc = 2;
	std::string prxstr = getConfig().getProperty("dispatcher");
// 	_communicator = Ice::initialize(argc,argv);
// 	_dispPrx = rd::IRdDispatcherPrx::uncheckedCast(_communicator->stringToProxy(prxstr));
// 
// 	Ice::ObjectAdapterPtr adapter =_communicator->createObjectAdapter("rdfront");
// 	adapter->add( IRdFrontServant::instance() , _communicator->stringToIdentity("rdfront"));
// 	adapter->activate();
	//////////////////////////////////////////////////////////////////////////
	_threadOutgoning = new swlib::Thread(RdFront::threadRdserverConn,this);
	_threadOutgoning->start();
	_connRdserver_corrupt = true;
	//////////////////////////////////////////////////////////////////////////
	_rpcThread= new swlib::Thread(RdFront::threadRpcEntry,this);
	_rpcThread->start();
	//_rpcThread= new swlib::Thread(RdFront::threadRpcEntry,this);
	//_rpcThread->start();
	_lspThread= new swlib::Thread(RdFront::threadLspEntry,this);
	_lspThread->start();
	return true;
}

int RdFront::mainloop(){
	_serverRunning = true;
	while(true){
		if(!doSelect()){
			break;
		}
	}
	printf("do select break\n");
	return 0;
}

//获取游戏进程向外的链接
//这里有点搞脑子
shared_ptr<RedirectAddress_t>	RdFront::getRedirectAddress(){
	shared_ptr<RedirectAddress_t> addr;
	swlib::ScopeLocker l(_mtx_nextaddr);
	if( _nextaddrlist.size()){
		addr = new RedirectAddress_t;
		*addr = _nextaddrlist.front();
		_nextaddrlist.pop_front();
	}
	
// 	addr->set_host("192.168.14.3"); // for python gameserver.py
// 	addr->set_port(12009);
	return addr;
}			 

RdFront::RdFront(){
	_logfilename = "rdfront.log";
}

shared_ptr<RdFront>& RdFront::instance(){
	static shared_ptr<RdFront> server;
	if(!server.get()){
		server = new RdFront;
	}
	return server;
}

//lsp 同步线程
void  RdFront::run(){
	swlib::ScopeLocker l(_mtx_servers);
	_rdserverlist.clear();
	_connRdserver_corrupt = true;
}

//开始游戏准备
bool RdFront::prepareWorkSheet(const rd::RdWorkSheetT& worksheet,int to){
	swlib::ScopeLocker ll(_mtx_nextaddr);
	_nextaddrlist.clear();
	
	swlib::ScopeLocker l(_mtx_servers);
	getLogger().Debug("prepareWorkSheet:%s-%s",worksheet.tradeNo.c_str(),worksheet.areaName.c_str());
	getRdserverAddrList();
	if( _rdserverlist.size() == 0){
		getLogger().Debug("no more idle rdserver !");
		return false;
	}
	getLogger().Debug("got %d rdservers",_rdserverlist.size());
	{
		size_t n;
		for(n=0;n<_rdserverlist.size();n++){
			getLogger().Debug("%d. rdserver = %s",n,_rdserverlist[n].ip.c_str());
		}
	}
	_connRdserver_corrupt = true;
	_currSheet = worksheet;
	

	return true;
}

void RdFront::endWorkSheet(){
	getLogger().Debug("endWorkSheet()");
	swlib::ScopeLocker l(_mtx_nextaddr);
	_nextaddrlist.clear();
	_connRdserver_corrupt = true;  //复位连接
}

bool RdFront::initRpc(){
	int argc;
	//char* argv[]={"this","--Ice.Config=userver.ice.conf"};
	char* argv[]={"this","--Ice.Config=rdfront.conf"};
	argc = 2;
	std::string prxstr = getConfig().getProperty("dispatcher");
	_communicator = Ice::initialize(argc,argv);
	_dispPrx = rd::IRdDispatcherPrx::uncheckedCast(_communicator->stringToProxy(prxstr));

	Ice::ObjectAdapterPtr adapter =_communicator->createObjectAdapter("rdfront");
	adapter->add( IRdFrontServant::instance() , _communicator->stringToIdentity("rdfront"));
	adapter->activate();
	_communicator->waitForShutdown();
	return true;
}

void RdFront::threadRpcEntry(swlib::Thread* t,void*u){
	RdFront * server = (RdFront*)u;
	
	
	
	server->getLogger().Debug("Rpc service Ready...");
	//server->_communicator->waitForShutdown();
	server->initRpc();
}

void RdFront::threadLspEntry(swlib::Thread* t,void*u){
	RdFront* server = (RdFront*)u;
 	char* geventName1="Global\\{8b4a1f95-3f13-4b50-b53f-a94ad165c2b2}";
 	char* geventName2="Global\\{dd16ab23-8f4e-43d1-bfcb-750a2b35922e}";
//	char* geventName1="Global{8b4a1f95-3f13-4b50-b53f-a94ad165c2b2}";
//	char* geventName2="Global{dd16ab23-8f4e-43d1-bfcb-750a2b35922e}";

	HANDLE event1 = ::CreateEvent(NULL, TRUE, FALSE, geventName1);
	HANDLE event2 = ::CreateEvent(NULL, TRUE, FALSE, geventName2);

//	int r;
	swUInt32 naddr;
	swUInt16 nport;
	while(t->loop()){
		//r = waitRedirectDestination(&naddr,&nport);
		if( WaitForSingleObject(event2,1000*2) ==WAIT_TIMEOUT){
			continue;
		}
		ResetEvent(event2);
		
		//if(r==0){
		waitRedirectDestination(&naddr,&nport);
		swlib::SocketAddr saddr;
		saddr.set_naddr(naddr);
		saddr.set_nport(nport);
		swlib::ScopeLocker l(server->_mtx_nextaddr);
		server->_nextaddrlist.push_back(saddr);
		server->getLogger().Debug(" Got Connect Redirect Address:%s,push it into queue..",saddr.toString().c_str());
		//}
		SetEvent(event1);	
	}
}
//////////////////////////////////////////////////////////////////////////
void RdFront::connectedRdServer(const rd::RdServerInfoT& server){
	rd::RdFrontInfoT front;
	try{
		_dispPrx->connectedRdServer(front,server,_currSheet);
	}catch(const std::exception& e){
		getLogger().Debug(e.what());
	}
}

void RdFront::disconnectedRdServer(const rd::RdServerInfoT& server){
	rd::RdFrontInfoT front;
	try{
		_dispPrx->disconnectedRdServer(front,server,_currSheet);
	}catch(const std::exception& e){
		getLogger().Debug(e.what());
	}
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

struct Block{
	char x[1024];
};
int _tmain(int argc, _TCHAR* argv[])
{
	/*
	for(int n=1;n<1000000;n++){
		swlib::Handle<Block> i1 (new Block);
		swlib::Handle<Block> i2 = i1;
		i2 = new Block;
		swlib::Handle<Block> i3 = i1;
		i2 = i3;
		i1 = i2;

	}	*/
	
	RdFront::instance()->start("rdfront.conf");
	
	
	RdFront::instance()->mainloop();	
	return 0;
}



