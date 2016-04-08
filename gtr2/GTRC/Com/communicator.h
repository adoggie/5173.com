
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
	EVENT_COMM_CONNECTED,			//连接上服务器
	EVENT_COMM_DISCONNECTED,		//断开
	EVENT_COMM_MESSAGE,				//消息到达
	EVENT_COMM_SHUTDOWN				//通信器关闭，此刻读取线程可立刻退出
};

struct GtCommMessageT
{
	GtCommunicatorEvent	event;				//事件类型
	GtMessageBase*	msg;					//消息包数据
	void *	delta;							//delta
};

class GtCommunicator
{
public :
	GtCommunicator(){}
	virtual~GtCommunicator(){}
	bool	init(const GtCommProps& props);											//初始化通信器
	bool	start();																//启动工作
	void	shutdown();																//停止
	void	cleanup();																//清理
	GtCommMessageT*		getMessage();												//从通信器中读出数据包，注意:内部必须做好数据保护，读取可能是在多个线程
	bool				sendMessage(GtMessageBase* msg);							//往服务器发送消息

	GtCommMessageT* GetRecvListBegin();
	virtual void InitializeThread() = 0;
	bool ReStartConnect();
	bool StartConnect();
	bool CloseConnect();
	bool CleanUpList();
protected:
	XSocket						m_sock;												//通信socket
	GtCommProps					m_props;											//IP和端口
	DWORD						RecvThreadid;										//接收线程id
	HANDLE						RecvThreadHandle;									//接收线程句柄
	HANDLE						RecvEvent;											//接收线程event
	CRITICAL_SECTION			g_recv;												//recvlist的临界区
	std::list<GtCommMessageT*>	recvlist;											//接收线程消息队列
	bool						LeaveThread;										//接收线程离开标志

};

class ServerGtCommunicator : public GtCommunicator
{
public:
	ServerGtCommunicator(){LeaveThread = false;}
	~ServerGtCommunicator(){}

	static DWORD WINAPI ServerRecvThread(ServerGtCommunicator* lpParam);
	virtual void InitializeThread();
private:
	std::string			deskey;														//服务器发过来的解密钥
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
