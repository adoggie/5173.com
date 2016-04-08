
#ifndef _RD_FRONT_H
#define  _RD_FRONT_H

#include "../common/rdserverbase.h"
#include <IceUtil/IceUtil.h>
#include <Ice/Ice.h>	 
#include <redirect.h>



class RdFront:public RedirectServerBase{ //,public swlib::Thread{
public:
	RdFront();
	void threadEntry(swlib::Thread* t);
	bool start(const std::string&);
	bool doSelect();
	static void threadRdserverConn(swlib::Thread* t,void* user);
	shared_ptr<swlib::SocketAddr> getRdserverAddr(); 
	void getRdserverAddrList();
	
	int mainloop();
	static shared_ptr<RdFront>& instance();
	shared_ptr<RedirectAddress_t>	getRedirectAddress();	
	
	bool prepareWorkSheet(const rd::RdWorkSheetT& worksheet,int to); //开始游戏交易
	void endWorkSheet();				//结束游戏交易
	
private:
	void doChannelMessage(shared_ptr<ConnectionMessageBase>& msg);
	void doConnectiontMessage(shared_ptr<ConnectionMessageBase>&msg);
	
	void run();
	static void threadRpcEntry(swlib::Thread* t,void*u);
	static void threadLspEntry(swlib::Thread* t,void*u);
	bool initRpc();
	void  recieveMessage();
	
	void connectedRdServer(const rd::RdServerInfoT& server);
	void disconnectedRdServer(const rd::RdServerInfoT& server);
	
private:
	std::vector<shared_ptr<swlib::TcpSocket> > _sockIncomings; //游戏连接进入

	bool	_connRdserver_corrupt;
	swlib::TcpSocket _sock_rdserver;			//外发连接
	swlib::Mutex _mtx_rdserverconn;

	shared_ptr<swlib::Thread>		_trRdserver;
	

	//std::list< shared_ptr<ConnectionMessageBase> > _msglist_incoming; // rdserver接收的消息包
	swlib::Condition _cond_msg_incoming;
	swlib::Mutex	_mtx_msg_incoming;
	MessageQueue	_mq_incoming;

	std::list< shared_ptr<ConnectionMessageBase> > _msglist_outgoing; //准备发送给rdserver的消息队列
	swlib::Condition _cond_msg_outgoing;
	swlib::Mutex	_mtx_msg_outgoing;

	bool	_serverRunning;

	std::vector<RedirectChannelID_t> _closedChannels;	//已经关闭的通道
	std::vector<RedirectChannelID_t>	_halfclosedChannels;//半关闭

	std::map<RedirectChannelID_t, shared_ptr<swlib::TcpSocket> > _channelsocks;

	shared_ptr<swlib::Thread> _threadOutgoning;			 
	
	rd::IRdDispatcherPrx _dispPrx;
	Ice::CommunicatorPtr _communicator;
	
	shared_ptr<swlib::Thread> _rpcThread;	//
	rd::RdWorkSheetT _worksheet;	//当前作业任务
	
	swlib::Mutex _mtx_servers;
	//std::vector<swlib::SocketAddr> _rdserverlist;  //服务器地址
	rd::RdServerInfoListT _rdserverlist;
	
	
	swlib::Mutex _mtx_nextaddr;	//需要转向的目标服务器地址
	std::deque<swlib::SocketAddr> _nextaddrlist;
	shared_ptr<swlib::Thread> _lspThread;
	
	bool _connection_auth_passed ;
	rd::RdWorkSheetT _currSheet;		//当前游戏交易单信息
};



#endif