
#ifndef _GT_COMMUNICAOTR_H
#define _GT_COMMUNICAOTR_H

#include "gtr_base.h"
#include "message.h"
#include "xsocket.h"

struct GtCommProps
{
	std::string		server;
	GtUInt16		port;
};

enum GtCommunicatorEvent
{
	EVENT_COMM_CONNECTED,			//�����Ϸ�����
	EVENT_COMM_DISCONNECTED,		//�Ͽ�
	EVENT_COMM_MESSAGE,				//��Ϣ����
	EVENT_COMM_SHUTDOWN				//ͨ�����رգ��˿̶�ȡ�߳̿������˳�
};

struct GtCommMessageT
{
	GtCommunicatorEvent	event;				//�¼�����
	GtMessageBase*	msg;					//��Ϣ������
	void *	delta;							//delta
};

class GtCommunicator
{
public :
	GtCommunicator(){}
	virtual~GtCommunicator(){}
	bool	init(const GtCommProps& props);											//��ʼ��ͨ����
	bool	start();																//��������
	void	shutdown();																//ֹͣ
	void	cleanup();																//����
	GtCommMessageT*		getMessage();												//��ͨ�����ж������ݰ���ע��:�ڲ������������ݱ�������ȡ�������ڶ���߳�
	bool				sendMessage(GtMessageBase* msg);							//��������������Ϣ

	GtCommMessageT* GetRecvListBegin();
	virtual void InitializeThread() = 0;
	bool ReStartConnect();
	bool StartConnect();
	bool CloseConnect();
	bool CleanUpList();
protected:
	XSocket						m_sock;												//ͨ��socket
	GtCommProps					m_props;											//IP�Ͷ˿�
	DWORD						RecvThreadid;										//�����߳�id
	HANDLE						RecvThreadHandle;									//�����߳̾��
	HANDLE						RecvEvent;											//�����߳�event
	CRITICAL_SECTION			g_recv;												//recvlist���ٽ���
	std::list<GtCommMessageT*>	recvlist;											//�����߳���Ϣ����
	bool						LeaveThread;										//�����߳��뿪��־

};

class ServerGtCommunicator : public GtCommunicator
{
public:
	ServerGtCommunicator(){LeaveThread = false;}
	~ServerGtCommunicator(){}

	static DWORD WINAPI ServerRecvThread(ServerGtCommunicator* lpParam);
	virtual void InitializeThread();
private:
	std::string			deskey;														//�������������Ľ���Կ
};

//class LogGtCommunicator : public GtCommunicator
//{
//public:
//	LogGtCommunicator(){LeaveThread = false;}
//	~LogGtCommunicator(){}
//
//	static DWORD WINAPI LogRecvThread(ServerGtCommunicator* lpParam);
//	virtual void InitializeThread();
//};


#endif
