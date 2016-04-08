
#ifndef _SOCKET_H
#define _SOCKET_H

#include "base.h"
#include "mutex.h"
#include "baseobj.h"

namespace swlib{


#define SWINVALIDE_SOCKET -1

#ifdef _UNIX
	#include <unistd.h>
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	#include <netdb.h>
	#include <string.h>
	typedef socklen_t SOCKLEN ;
	#define CLOSESOCKET(s)	shutdown(s,SHUT_RDWR);\
		close(s);\
		s=SWINVALIDE_SOCKET;

#endif

#ifdef WIN32
	#include <windows.h>
	#include <winsock.h>
	#pragma comment(lib,"ws2_32.lib")
	typedef int SOCKLEN;
	
	#define CLOSESOCKET(s)	shutdown(s,2);\
			closesocket(s);\
			s=SWINVALIDE_SOCKET;

#endif

enum SOCK_TYPE{
	SOCK_TCP=SOCK_DGRAM,
	SOCK_UDP=SOCK_STREAM
};

typedef int 	SOCK_HANDLE;	
typedef int		SOCK_ERROR;

#define ESocket_Bind_Another	1001	//端口已经被占用

//////////////////////////////////////////////////////////////////////////
//NetAddress

class  SocketAddr{
public:
	SocketAddr();
	SocketAddr(const char *host,swUInt16 port);
	//SocketAddr(unsigned int naddr,swUInt16 nport);
	SocketAddr(sockaddr_in *saddr);		
	const sockaddr_in * get_addr() const;
	in_addr	*get_inaddr();
	void operator =(const SocketAddr& saddr);
	void set_host(const char * host);
	
	void set_port(unsigned short port);
	void set_nport(unsigned short nport);
	void set_naddr(swUInt32 naddr);
	std::string get_host();
	swUInt16 get_port();
	swUInt32 get_naddr(){	return _saddr.sin_addr.s_addr;}
	void set_addr(const sockaddr_in *saddr);
	std::vector<unsigned char> toBytes();					//序列化
	std::string toString();
	//////////////////////////////////////////////////////////////////////////

	static SocketAddr fromBytes(const swByte* bytes); //从字节流产生
	static std::string toString(swUInt32 naddr);  //网络地址格式化
public:
	sockaddr_in _saddr;	
};





//////////////////////////////////////////////////////////////////////////
class Socket:public BaseObject{
public:
	Socket();
	virtual ~Socket()=0;
	virtual bool create();
	virtual void close();
	//virtual void destroy();					
	virtual bool do_connect( const SocketAddr& addr);	
	virtual bool do_connect(const SocketAddr& addr,unsigned int waits); //超时连接(秒)
	virtual int read(char *buff ,unsigned int len,SocketAddr * addr );
	virtual int write(char *buff,unsigned int len);
	SOCK_HANDLE & get_handle();	
	void set_handle(const SOCK_HANDLE& sock);
	SocketAddr& get_addr();
	void set_addr( const SocketAddr& addr);
	bool get_peer(SocketAddr& addr);
	SOCK_TYPE get_type();	
	virtual bool	bind_addr(const SocketAddr& addr);
	//////////////////////////////////////////////////////////////////////////
	static std::string getHostName();
	static std::vector<swUInt32> getIpAddrList(const std::string & host);
	static bool setSocketBlock(SOCK_HANDLE socket,bool block);
	static bool setLinger(SOCK_HANDLE socket,bool linger);
	static bool setAddrReuse(SOCK_HANDLE socket);
	static bool initSocket();
	static bool cleanup();	
protected:
	SOCK_HANDLE		_socket;	
	SOCK_TYPE			_type;
	SocketAddr		_addr;
};

class UdpSocket:public Socket{
public:	
	bool create();
	bool	bind_addr(const SocketAddr& addr);
	int readTimeout(char *buff ,unsigned int len,unsigned short  time_sec,SocketAddr * addr=NULL);	
	int read(char *buff ,unsigned int len,SocketAddr* addr=NULL);
	int write(char *buff,unsigned int len);
	int sendto(const SocketAddr& addr, char * buff,unsigned int len);
	//static int sendTo( SocketAddr&  addr,char *buff,unsigned int len);	
	//static SOCK_HANDLE bindRange(const char * host ,unsigned short from,unsigned short end,unsigned short *which,NVSocketHandle * socket);		
	static SOCK_HANDLE bindPort( SocketAddr& saddr);	
};


//////////////////////////////////////////////////////////////////////////
//TcpSocket
class TcpSocket:public Socket{
public:	
	TcpSocket();
	bool	bind_addr(const  SocketAddr& addr);
	bool	create();
	int		read(char *buff ,unsigned int len,SocketAddr * addr=NULL);
	int		write(char *buff,unsigned int len);
	static int sendall(int sock,char *buff,unsigned int len);
	TcpSocket* accept();
//	TcpSocket* accept(swUInt16 waits); //等待连接超时
	int peek();
public:

};

}

#endif 
