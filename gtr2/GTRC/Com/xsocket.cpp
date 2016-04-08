
#include <string.h>

#include "XSocket.h"
#pragma comment(lib,"Ws2_32.lib")

static inline int makeaddr(const char *szIP, unsigned short nPort, struct sockaddr_in *pAddr)
{
	if ( pAddr == NULL )
	{
		return -1;
	}

	memset(pAddr, 0, sizeof(struct sockaddr_in));

	pAddr->sin_family = AF_INET;

	if ( (szIP == NULL) || (szIP[0] == 0) || (_stricmp(szIP, "localhost") == 0) )
	{
		pAddr->sin_addr.s_addr = inet_addr("127.0.0.1");
	}
	if ( strcmp(szIP, "*") == 0 )
	{
		pAddr->sin_addr.s_addr = INADDR_ANY;
	}
	else
	{
		pAddr->sin_addr.s_addr = inet_addr(szIP);
	}

	pAddr->sin_port = htons(nPort);

	return 0;
}


XSocket::XSocket()
{
	m_nSocket = INVALID_SOCKET;
}

XSocket::XSocket(SOCKET nSocket)
{
	m_nSocket = nSocket;
}

XSocket::~XSocket()
{
}

XSocket &XSocket::operator = (const SOCKET nSocket)
{
	m_nSocket = nSocket;
	return *this;
}

XSocket::operator SOCKET()
{
	return m_nSocket;
}

SOCKET XSocket::GetHandle()
{
	return m_nSocket;
}

bool XSocket::IsValid()
{
	return (m_nSocket != INVALID_SOCKET);
}

int XSocket::Open()
{
	if ( IsValid() )
	{
		return -1;
	}

	m_nSocket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);

	if ( !IsValid() )
	{
		return -1;
	}

	return 0;
}

int XSocket::Close()
{
	SOCKET nSocket = m_nSocket;

	m_nSocket = INVALID_SOCKET;
	return closesocket(nSocket);
};

int XSocket::Shutdown(int nHow)
{
	return shutdown(m_nSocket, nHow);
}

int XSocket::Bind(const char *szIP, unsigned short nPort)
{
	struct sockaddr_in localaddr;

	makeaddr(szIP, nPort, &localaddr);

	return bind(m_nSocket, (struct sockaddr *)&localaddr, sizeof(struct sockaddr_in));
}

int XSocket::Listen(int nBacklog)
{
	return listen(m_nSocket, nBacklog);
}

int XSocket::Connect(const char *szIP, unsigned short nPort)
{
	struct sockaddr_in  srvaddr;

	makeaddr(szIP, nPort, &srvaddr);

	int error = connect(m_nSocket, (struct sockaddr *)&srvaddr, sizeof(struct sockaddr));
	
	return error;
}

int XSocket::ReuseAddr()
{
	int flag = 1;
	int len = sizeof(int);

	// SOL_SOCKET选项级别，值SO_REUSEADDR，如果是TRUE，套接字就可与一个正由其他套接字使用的地址绑定到一起，或与处在TIME_WAIT状态的地址绑定到一起
	if ( setsockopt(m_nSocket, SOL_SOCKET, SO_REUSEADDR, (const char *)&flag, len) == -1 )
	{ 
		return -1;
	} 

	return 0;
}

int XSocket::SetNonBlock(bool bNonBlock)
{
	unsigned int nNonBlocking = (bNonBlock == true) ? 1 : 0;
	DWORD dwBytes = 0;

	if ( WSAIoctl(m_nSocket, FIONBIO, &nNonBlocking, sizeof(nNonBlocking), NULL, 0, &dwBytes, NULL, NULL) < 0)
	{
		return -1;
	}

	return 0;
}

int XSocket::SetNoDelay(int nNoDelay)
{
	// IPPROTO_TCP选项级别，只有一个值TCP_NODELAY，设置nNoDelay为1，禁用Nagle算法，只适用于流式套接字（Sock_Stream）
	return setsockopt(m_nSocket, IPPROTO_TCP, TCP_NODELAY, (const char *)&nNoDelay, sizeof(int));
}

int XSocket::SetSndBuf(int nSndBuf)
{
	// SOL_SOCKET选项级别，值SO_SNDBUF，如果是TRUE（非零值），意味着套接字被配置成可进行广播消息的发送
	return setsockopt(m_nSocket, SOL_SOCKET, SO_SNDBUF, (const char *)&nSndBuf, sizeof(int));
}

int XSocket::SetKeepAlive()
{
	tcp_keepalive iKeepAlive = { 1, 5000, 5000 };
	tcp_keepalive oKeepAlive = { 0, 0, 0 };
	DWORD dwBytes = 0;  

	return WSAIoctl(m_nSocket, SIO_KEEPALIVE_VALS, &iKeepAlive, sizeof(tcp_keepalive), &oKeepAlive, sizeof(tcp_keepalive), &dwBytes, NULL, NULL);
}

int XSocket::UpdateAcceptContext(SOCKET nListenSocket)
{
	// SOL_SOCKET选项级别，值SO_UPDATE_ACCEPT_CONTEXT，如果是SOCKET nListenSocket，获取或设置与套接字上的数据接收对应的超时值（以毫秒计）
	int nRet = setsockopt(m_nSocket, SOL_SOCKET, SO_UPDATE_ACCEPT_CONTEXT, (const char*) &nListenSocket, sizeof(SOCKET));
	if ( nRet == SOCKET_ERROR )
	{
		return -1;
	}

	return 0;
}

