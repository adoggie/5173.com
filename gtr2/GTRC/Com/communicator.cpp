
#include "communicator.h"
#include "messagemanager.h"
#include "Crypt.h"
#include <stdio.h>
#include <assert.h>

#define MAX_MESSAGE_SIZE 4096

GtCommMessageT* GtCommunicator::GetRecvListBegin()
{
	if (recvlist.size()==0)
		return NULL;

	std::list<GtCommMessageT*>::iterator p = recvlist.begin();
	GtCommMessageT* get = (*p);
	recvlist.pop_front();

	if (recvlist.size()==0)
	{
		SetEvent(0);
	}

	return get;
}

bool GtCommunicator::StartConnect()
{
	if (m_sock.Open()!=0)
	{
		//WSACleanup();
		printf("网络套接字打开失败\n");
		m_sock.Close();
		return false;
	}

	if (m_sock.Connect(m_props.server.c_str(),m_props.port)!=0)
	{
		//WSACleanup();
		printf("连接服务器失败\n");
		return false;
	}

	GtCommMessageT* commmessage = new GtCommMessageT;
	commmessage->event = EVENT_COMM_CONNECTED;
	commmessage->msg = NULL;

	InitializeThread();

	printf("startconnect开始进入临界区对象\n");
	EnterCriticalSection(&g_recv);
	recvlist.push_back(commmessage);
	SetEvent(RecvEvent);
	LeaveCriticalSection(&g_recv);
	printf("startconnect开始离开临界区对象\n");

	return true;
}

bool GtCommunicator::CloseConnect()
{
	m_sock.Close();

	GtCommMessageT* commmessage = new GtCommMessageT;
	commmessage->event = EVENT_COMM_DISCONNECTED;
	commmessage->msg = NULL;

	printf("closeconnect开始进入临界区对象\n");
	EnterCriticalSection(&g_recv);
	recvlist.push_back(commmessage);
	SetEvent(RecvEvent);
	LeaveCriticalSection(&g_recv);
	printf("closeconnect开始离开临界区对象\n");
	return true;
}

bool GtCommunicator::CleanUpList()
{
	printf("CleanUpList开始进入临界区对象\n");
	EnterCriticalSection(&g_recv);

	std::list<GtCommMessageT*> backup;
	std::list<GtCommMessageT*>::iterator it;
	for ( it = recvlist.begin(); it != recvlist.end(); ++it)
	{
		if ((*it)->event = EVENT_COMM_MESSAGE)
		{
			delete (*it);
		}
		else
		{
			backup.push_back(*it);
		}
	}
	recvlist = backup;

	if (recvlist.size()==0)
	{
		SetEvent(0);
	}

	LeaveCriticalSection(&g_recv);
	printf("CleanUpList开始离开临界区对象\n");
	return true;
}

extern void showmsg(string msg);
bool GtCommunicator::ReStartConnect()
{
	CloseConnect();
	CleanUpList();
	bool success = false;
	while (!success)
	{
		showmsg("GtCommunicator::ReStartConnect!");
		success = StartConnect();
		Sleep(1000);
	}
	return true;
}

bool GtCommunicator::init(const GtCommProps& props)
{
	m_props = props;

	printf("初始化临界区对象\n");
	InitializeCriticalSection(&g_recv);

	WSADATA wsaData;

	if ( WSAStartup(MAKEWORD(2, 2), &wsaData) != 0 )
	{
		printf("启动socket服务失败了\n");
		return false;
	}

	return true;
}
bool GtCommunicator::start()
{
	return StartConnect();
}
void GtCommunicator::shutdown()
{
	if (m_sock.IsValid())
	{
		m_sock.Close();
	}

	LeaveThread = true;

	GtCommMessageT* commmessage = new GtCommMessageT;
	commmessage->event = EVENT_COMM_SHUTDOWN;
	commmessage->msg = NULL;

	EnterCriticalSection(&g_recv);
	recvlist.push_back(commmessage);
	SetEvent(RecvEvent);
	LeaveCriticalSection(&g_recv);
}

void GtCommunicator::cleanup()
{
	WSACleanup();
}

GtCommMessageT*	GtCommunicator::getMessage()
{
	WaitForSingleObject(RecvEvent,0);

	GtCommMessageT* buffer = NULL;

	EnterCriticalSection(&g_recv);
	buffer = GetRecvListBegin();
	LeaveCriticalSection(&g_recv);

	if (buffer==NULL||buffer->msg==NULL)
	{
		return buffer;
	}

	return buffer;
}

bool GtCommunicator::sendMessage(GtMessageBase* msg)
{
	GtStreamBytes gtstr = msg->encBytes();
	if(msg->getSize()==0)
	{
		return false;
	}

	int nSend = 0;
	while(nSend < (int)msg->getSize())
	{
		int nOneSend = send(m_sock.GetHandle(),&gtstr[nSend],(int)(msg->getSize()-nSend),0);

		if ( SOCKET_ERROR == nOneSend || 0 == nOneSend )
		{
			return false;
		}

		nSend += nOneSend;
	}
	return true;
}

DWORD WINAPI ServerGtCommunicator::ServerRecvThread(ServerGtCommunicator* lpParam)
{
	while (1)
	{
		char buffer[MAX_MESSAGE_SIZE];
		memset(buffer,0,MAX_MESSAGE_SIZE);

		int allrecv = 0;
		int packetsize = 5;
		char type;
		do 
		{
			int nOneRecv = recv(lpParam->m_sock,&buffer[allrecv],MAX_MESSAGE_SIZE-allrecv,0);

			if ( SOCKET_ERROR == nOneRecv || 0 == nOneRecv )
			{
				break;
			}

			if ( nOneRecv < packetsize )
			{
				allrecv += nOneRecv;
				continue;
			}

			char* pTempBuffer = (char*)buffer;

			packetsize = *((int*)pTempBuffer);					pTempBuffer += sizeof(int);

			type = *((char*)pTempBuffer);						pTempBuffer += sizeof(char);
			allrecv += nOneRecv;
		} 
		while (allrecv<packetsize);

		if (lpParam->LeaveThread)
		{
			printf("主线程强制接收线程结束\n");
			break;
		}

		if (allrecv==0||packetsize==0)
		{
			printf("接收协议失败,即将重新连接服务器\n");
			lpParam->ReStartConnect();
			break;
		}

		GtMessageBase* base = NULL;
		switch(type)
		{
		case VERIFYREQUEST:
			base = new VerifyInfo;
			break;
		case TRANSACTREQUEST:
			base = new TransactionInfo;
			break;
		case YZMCONTENT:
			base = new YZMContent;
			break;
		case MBKCONTENT:
			base = new MBKContent;
			break;
		case DECRYPTIONKEY:
			base = new DecryptionKey;
			break;
		case ROBOTHEART:
			base = new RobotHeart;
			break;
		case ACCOUNTVERIFYREQUEST:
			base = new AccountVerifyInfo;
		default:
			break;
		}

		if (lpParam->LeaveThread)
		{
			printf("主线程强制接收线程结束\n");
			break;
		}

		if(!base->parse((GtByte*)buffer,allrecv))
		{
			printf("协议解析失败\n");
			lpParam->ReStartConnect();
			break;
		}

		char data[32];
		string pwd;

		switch(type)
		{
		case DECRYPTIONKEY:
			{
				/*
				获得解密钥
				*/
				lpParam->deskey = ((DecryptionKey*)base)->key;
			}
			break;
		case VERIFYREQUEST:
			{
				int datasize;
				/*
				解密卖家密码
				*/
				pwd = ((VerifyInfo*)base)->Password;
				ZeroMemory(data,32);
				decrypt(lpParam->deskey.c_str(),pwd.c_str(),data,datasize);
				((VerifyInfo*)base)->Password = string(data);

				/*
				解密卖家2级密码
				*/
				pwd = ((VerifyInfo*)base)->SellerSecondPwd;
				if (pwd!="")
				{
					ZeroMemory(data,32);
					decrypt(lpParam->deskey.c_str(),pwd.c_str(),data,datasize);
					((VerifyInfo*)base)->SellerSecondPwd = string(data);
				}

				/*
				解密卖家钱庄密码
				*/
				pwd = ((VerifyInfo*)base)->BankPwd;
				if (pwd!="")
				{
					ZeroMemory(data,32);
					decrypt(lpParam->deskey.c_str(),pwd.c_str(),data,datasize);
					((VerifyInfo*)base)->BankPwd = string(data);
				}
			}
			break;
		case TRANSACTREQUEST:
			{
				int datasize;
				/*
				解密卖家密码
				*/
				pwd = ((TransactionInfo*)base)->Password;
				ZeroMemory(data,32);
				decrypt(lpParam->deskey.c_str(),pwd.c_str(),data,datasize);
				((TransactionInfo*)base)->Password = string(data);

				/*
				解密卖家2级密码
				*/
				pwd = ((TransactionInfo*)base)->SellerSecondPwd;
				if (pwd!="")
				{
					ZeroMemory(data,32);
					decrypt(lpParam->deskey.c_str(),pwd.c_str(),data,datasize);
					((TransactionInfo*)base)->SellerSecondPwd = string(data);
				}

				/*
				解密卖家钱庄密码
				*/
				pwd = ((TransactionInfo*)base)->BankPwd;
				if (pwd!="")
				{
					ZeroMemory(data,32);
					decrypt(lpParam->deskey.c_str(),pwd.c_str(),data,datasize);
					((TransactionInfo*)base)->BankPwd = string(data);
				}
			}
			break;
		case ACCOUNTVERIFYREQUEST:
			{
				int datasize;
				/*
				解密卖家密码
				*/
				pwd = ((AccountVerifyInfo*)base)->Password;
				ZeroMemory(data,32);
				decrypt(lpParam->deskey.c_str(),pwd.c_str(),data,datasize);
				((AccountVerifyInfo*)base)->Password = string(data);

				/*
				解密卖家2级密码
				*/
				pwd = ((AccountVerifyInfo*)base)->SellerSecondPwd;
				if (pwd!="")
				{
					ZeroMemory(data,32);
					decrypt(lpParam->deskey.c_str(),pwd.c_str(),data,datasize);
					((AccountVerifyInfo*)base)->SellerSecondPwd = string(data);
				}

				/*
				解密卖家钱庄密码
				*/
				pwd = ((AccountVerifyInfo*)base)->BankPwd;
				if (pwd!="")
				{
					ZeroMemory(data,32);
					decrypt(lpParam->deskey.c_str(),pwd.c_str(),data,datasize);
					((AccountVerifyInfo*)base)->BankPwd = string(data);
				}
			}
			break;
		}

		GtCommMessageT* commmessage = new GtCommMessageT;
		commmessage->event = EVENT_COMM_MESSAGE;
		commmessage->msg = base;

		EnterCriticalSection(&lpParam->g_recv);
		lpParam->recvlist.push_back(commmessage);
		SetEvent(lpParam->RecvEvent);
		LeaveCriticalSection(&lpParam->g_recv);
	}
	return 0;
}

void ServerGtCommunicator::InitializeThread()
{
	RecvThreadHandle = CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)ServerRecvThread,LPVOID(this),0,&RecvThreadid);
	RecvEvent = CreateEvent(NULL,true,false,NULL);
}

