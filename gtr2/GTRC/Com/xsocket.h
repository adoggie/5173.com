#ifndef _X_SOCKET_H_
#define _X_SOCKET_H_



#include <WinSock2.h>
  #include <MSTcpIP.h>
  #include <MSWSock.h>

class XSocket
{
public:
	XSocket();
	XSocket(SOCKET nSocket);
	~XSocket();

	XSocket &operator = (const SOCKET nSocket);
	operator SOCKET();

	// 获得套接字
	SOCKET GetHandle();
	// 判断套接字可用与否
	bool IsValid();

	// 打开一个socket
	int Open();
	// 关闭一个socket
	int Close();
	// 禁止套接字上数据的接受和发送
	int Shutdown(int nHow);
	// 绑定服务器的地址到ip,port
	int Bind(const char *szIP, unsigned short nPort);
	// 服务器监听
	int Listen(int nBacklog);
	// 客户端的连接ip,port
	int Connect(const char *szIP, unsigned short nPort);
	// 重用地址
	int ReuseAddr();
	// 把非0套接字变成非阻塞的
	int SetNonBlock(bool bNonBlock);
	// 若为1，就会在套接字上禁用Nagle算法，使得无延迟
	int SetNoDelay(int nNoDelay);
	// 套接字被配置成可进行广播消息的发送
	int SetSndBuf(int nSndBuf);
	// 用户异常掉线检测
	int SetKeepAlive();
	// 获取或设置与套接字上的数据接收对应的超时值
	int UpdateAcceptContext(SOCKET nListenSocket);

private:
	SOCKET m_nSocket;
};

#endif //_SOCKET_H_