
#ifndef _RD_CONNECTION_H
#define _RD_CONNECTION_H

#include "../common/base.h"
#include "../common/socket.h"
#include "../common/rdchannel.h"
#include "../common/thread.h"
#include "../common/rdpacket.h"



class RdServer;

class RedirectConnection{
public:
	RedirectConnection(RdServer* server,shared_ptr<swlib::TcpSocket>& sockIn);
	~RedirectConnection();

	bool start();
	void stop();
	RdServer* getServer(){	return _server;}
protected:
	static void threadEntry(void* user);
	void run();
	bool processIncomingSocketPacket();	//����������Ϣ����,false-�Ƿ����ݰ�
	bool processOutgoingSocketPacket(RedirectChannelID_t cid,swByte* bytes,swUInt32 size); //�������������ϵĽ�����Ϣ��, false - socket lost
	void dispatch(shared_ptr<ConnectionMessageBase>& msg);
	
protected:
	shared_ptr<swlib::TcpSocket> _sockIn;
	std::map< RedirectChannelID_t,shared_ptr<swlib::TcpSocket> > _socksOut;	 //�ⷢ����
	RdServer* _server;
	shared_ptr<swlib::Thread> _threadSelect;
	MessageQueue	_mq_incoming;
};


#endif