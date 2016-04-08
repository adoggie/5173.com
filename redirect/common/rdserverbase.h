
#ifndef _RD_SERVERBASE_H
#define _RD_SERVERBASE_H

#include "../common/rdchannel.h"
//#include "connection.h"
#include "../common/config.h"
#include "../common/log.h"
#include "../common/mutex.h"
#include "../common/async.h"
#include "../common/rdpacket.h"

enum SocketTagType_t{
	stt_DIRECTION,
	stt_CHANNELID,	//通道编号 
	stt_ENABLED,			//通道是否可用
	stt_BUFFER,
	stt_MSGQUEUE_BACK,	//回送到客户程序的缓存
	stt_CLOSED,			//是否被关闭 
};

#define INCOMING_SOCKET 1
#define OUTGOING_SOCKET 2

//////////////////////////////////////////////////////////////////////////
struct RedirectServerProperties{
	swUInt16 connthreadnum;	//并发连接xiancheng
	swUInt16 tcpPort;	//
	swUInt16 udpPort;	//
	swUInt16 logPort;
	std::string logServer;
};

class RedirectServerBase{
public:
	RedirectServerBase();
	virtual bool start(const std::string& confile);
	virtual int end();
	swlib::swLogger&			getLogger(){return _logger;};
	ConfigProperties& getConfig(){return _confs;}
	//virtual bool onAccepted(swlib::TcpSocket* sock);
	virtual void threadEntry(swlib::Thread* t);
private:
	
protected:
	static void multiThreadEntry(swlib::Thread* t,void * user);
	RedirectChannelID_t newChannelID();
	RedirectServerProperties _props;
	swlib::ThreadGroup	_tgConnect;	//连接线程组
	ConfigProperties		_confs;
	shared_ptr<swlib::TcpSocket>		_listensock;
	
	swlib::swLogger			_logger;
	std::string					_logfilename;

	std::map<RedirectChannelID_t, shared_ptr<swlib::TcpSocket> > _socks;
	swlib::Mutex	_mtx_socks;
};

#endif
