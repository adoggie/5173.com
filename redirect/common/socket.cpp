
// #ifndef _NVSOCKET_H
// #define  _NVSOCKET_H

#include "socket.h"
#include "util.h"

//////////////////////////////////////////////////////////////////////////
//SocketAddr
//////////////////////////////////////////////////////////////////////////
swlib::SocketAddr::SocketAddr(){
	_saddr.sin_family =AF_INET;
	_saddr.sin_addr.s_addr =INADDR_ANY; 
}

swlib::SocketAddr::SocketAddr(const char *host,swUInt16 port){
//	hostent* h;
	_saddr.sin_family =AF_INET;
	_saddr.sin_port = htons(port);
	set_host(host);

}

void swlib::SocketAddr::set_naddr(swUInt32 naddr){
	_saddr.sin_family =AF_INET;
	_saddr.sin_addr.s_addr = naddr;
}
// swlib::SocketAddr::SocketAddr(unsigned int naddr,swUInt16 nport){
// 	_saddr.sin_family = AF_INET;
// 	_saddr.sin_addr.s_addr = naddr;
// 	_saddr.sin_port = nport;
// }

swlib::SocketAddr::SocketAddr(sockaddr_in *saddr){
	_saddr = *saddr;
}

void swlib::SocketAddr::set_addr(const sockaddr_in *saddr){
	_saddr = *saddr;
}

const sockaddr_in * swlib::SocketAddr::get_addr() const {
	return &_saddr;
}

in_addr	* swlib::SocketAddr::get_inaddr(){
	return &_saddr.sin_addr;
}

void swlib::SocketAddr::operator =(const SocketAddr& saddr){
	_saddr = saddr._saddr;
}

void swlib::SocketAddr::set_host(const char * host){
	hostent* h;
	if( host=="" || host == NULL){
		_saddr.sin_addr.s_addr = INADDR_ANY;
		return ;
	}
	if( isalpha(host[0])){
		h = gethostbyname(host);
		if( h){
			_saddr.sin_addr.s_addr = *((swUInt32*)h->h_addr_list[0]);
			//in_addr ia;
			//ia.s_addr = _saddr.sin_addr.s_addr;
			std::string str = inet_ntoa(_saddr.sin_addr);
		}
	}else{
		_saddr.sin_addr.s_addr = inet_addr(host);
	}
	//inet_ntop(hptr->h_addrtype, *pptr, str, sizeof(str)));
	//remoteHost = gethostbyaddr((char *) &addr, 4, AF_INET);
}



void swlib::SocketAddr::set_port(unsigned short port){
	_saddr.sin_port = htons(port);
}

void swlib::SocketAddr::set_nport(unsigned short nport){
	_saddr.sin_port = nport;
}

std::string swlib::SocketAddr::get_host(){
	std::string str = inet_ntoa(_saddr.sin_addr);
	return str;
}

swUInt16 swlib::SocketAddr::get_port(){
	return (swUInt16)ntohs(_saddr.sin_port);
}

std::vector<unsigned char> swlib::SocketAddr::toBytes(){
	std::vector<unsigned char> bytes;
	swUInt32 addr = (swUInt32)_saddr.sin_addr.s_addr;
	 
	bytes.resize(6);
	memcpy(&bytes[0],&addr,4);
	swUInt16 port = (swUInt16)_saddr.sin_port;
	memcpy(&bytes[4],&port,2);
	return bytes;
}

swlib::SocketAddr swlib::SocketAddr::fromBytes(const swByte* bytes){
	SocketAddr saddr;
	swUInt32 addr;
	swUInt16 port;
	memcpy(&addr,bytes,4);memcpy(&port,bytes+4,2);
	saddr._saddr.sin_port = port;
	saddr._saddr.sin_addr.s_addr = addr;
	return saddr;
}

std::string swlib::SocketAddr::toString(swUInt32 naddr){
	in_addr inaddr;
	inaddr.s_addr = (ULONG)naddr;
		std::string str = inet_ntoa(inaddr);
		return str;
}

std::string swlib::SocketAddr::toString(){
	return swlib::SocketAddr::toString(_saddr.sin_addr.s_addr)+":"+ ::swlib::int2str(get_port());
}

//////////////////////////////////////////////////////////////////////////
//Socket
//////////////////////////////////////////////////////////////////////////
swlib::Socket::Socket(){
	_socket = SWINVALIDE_SOCKET;
}

swlib::Socket::~Socket(){
	this->close();
}


std::string swlib::Socket::getHostName(){
	char name[256];
	memset(name,0,sizeof name);
	gethostname(name,sizeof(name)-1);
	return name;
}

std::vector<swUInt32> swlib::Socket::getIpAddrList(const std::string & host){
	std::vector<swUInt32> addrs;
	hostent* h;
	h = gethostbyname(host.c_str());
	sockaddr_in saddr;
	if( h){
		while(*h->h_addr_list){
			saddr.sin_addr.s_addr = *((swUInt32*)*h->h_addr_list);
			h->h_addr_list++;
			addrs.push_back(swUInt32(saddr.sin_addr.s_addr));
			//std::string str = inet_ntoa(_saddr.sin_addr);
		}
	}
	return addrs;
}

bool swlib::Socket::do_connect(const  swlib::SocketAddr& addr){
 	int ret;

	//this->close();
	//_socket = socket(AF_INET,SOCK_STREAM,0);
	ret = connect(_socket,(sockaddr*)addr.get_addr(),sizeof(sockaddr));
	_addr = addr;
 	return ret==0?true:false;
}

bool swlib::Socket::do_connect(const SocketAddr& addr,unsigned int waits){
	int ret;
	timeval tv;
	fd_set rset;	
	tv.tv_sec = waits;
	tv.tv_usec =0;
	setSocketBlock(_socket,false);
	FD_ZERO(&rset);
	FD_SET(_socket,&rset);
	ret = connect(_socket,(sockaddr*)addr.get_addr(),sizeof(sockaddr));
	ret = select(_socket+1,&rset,0,0,&tv);
	setSocketBlock(_socket,true);
	if(ret <=0 ){
		return false;
	}
	return true;
}

swlib::SOCK_HANDLE& swlib::Socket::get_handle(){
	return _socket;	
}

void swlib::Socket::set_handle(const swlib::SOCK_HANDLE& fd){
	_socket = fd;
}

swlib::SocketAddr& swlib::Socket::get_addr(){
	return _addr;
}

void swlib::Socket::set_addr( const swlib::SocketAddr& addr){
	_addr = addr;
}


#ifdef _UNIX
inline
bool Socket::SetSocketBlock(SocketHandle socket,bool block){
	int ret;
    int flags = fcntl(socket, F_GETFL, 0);    
    if (flags == -1){
        return false;
    }    
    if(!block){
		flags |=O_NONBLOCK;    	
    }else{
		flags &=~O_NONBLOCK;
    }
    ret = fcntl(socket, F_SETFL, flags);    
    return ret!=0 ?false:true;	
}
#endif 


#ifdef WIN32
bool swlib::Socket::setSocketBlock(swlib::SOCK_HANDLE socket,bool block){
  unsigned long yes =block?0:1;    
	return ioctlsocket(socket,FIONBIO,&yes)==0?true:false;
}
#endif

bool swlib::Socket::setAddrReuse(swlib::SOCK_HANDLE socket){
	int rc = -1;
	int opt;
	int optsize;
	opt = 1;
	optsize = sizeof(opt);

#ifdef WIN32
	rc = setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, optsize);
#else
	rc = setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, &opt, optsize);
#endif
	if (rc < 0)
		return false;
	return true;
}

swlib::SOCK_TYPE swlib::Socket::get_type(){
	return _type;
}


void swlib::Socket::close(){
	if( _socket == SWINVALIDE_SOCKET){
		return;
	}
	CLOSESOCKET(_socket);
	_socket = SWINVALIDE_SOCKET;
}

int swlib::Socket::read(char *buff ,unsigned int len,SocketAddr * addr ){
	return 0;
}

int swlib::Socket::write(char *buff,unsigned int len){
	return 0;
}

bool swlib::Socket::create(){
	return false;
}

bool	swlib::Socket::bind_addr(const SocketAddr& addr){
	return false;
}

bool swlib::Socket::initSocket(){
	#ifdef WIN32
	WORD wVersionRequested;
	WSADATA wsaData;
	int err; 
	wVersionRequested = MAKEWORD( 2, 2 );
	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) {
		return false;
	}
#endif
	return true;
}

bool swlib::Socket::cleanup(){
#ifdef WIN32
	WSACleanup();
#endif	
	return true;
}

bool swlib::Socket::setLinger(swlib::SOCK_HANDLE socket,bool linger){
	struct linger l;
	l.l_onoff=0;
	l.l_linger=0;
	if(linger)	l.l_onoff = 1;
	return setsockopt(socket,SOL_SOCKET,SO_LINGER,(char*)&l,sizeof(linger))==0? true:false;
}


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
/*
bool UdpSocket::BindRange(unsigned short from,unsigned short end,unsigned short *which,SocketHandle * socket){
	unsigned short n;
	for(n = from ;n<=end;n++){
		if( Bind(n,socket)){
			*which = n;
			return true;
		}
	}
	return false;
}
*/


swlib::SOCK_HANDLE swlib::UdpSocket::bindPort( swlib::SocketAddr& saddr ){
	SOCK_HANDLE sock;
	int ret;
	sock = SWINVALIDE_SOCKET;
	ret= socket(AF_INET,SOCK_DGRAM,0);
	if( ret < 0){
		return false;
	}
	if( bind(ret,(sockaddr*)saddr.get_addr(),sizeof(sockaddr))){
		CLOSESOCKET(ret);
		return false;
	}	
	return sock;
}


int swlib::UdpSocket::read(char *buff ,unsigned int len,swlib::SocketAddr * addr){
	int ret;
	SocketAddr naddr;
	SOCKLEN socklen;
	socklen = sizeof(sockaddr);
	ret = recvfrom(_socket,buff,len,0,(sockaddr*)naddr.get_addr(),&socklen);	
	if( addr){
		*addr = naddr;
	}
	return ret;
}


int swlib::UdpSocket::readTimeout(char *buff ,unsigned int len,unsigned short  time_sec,swlib::SocketAddr * addr){
	int ret;
	SocketAddr naddr;
	timeval tv;
	fd_set rset;
	SOCKLEN socklen;
	socklen = sizeof(sockaddr);
	tv.tv_sec = time_sec;
	tv.tv_usec =0;
	
	FD_ZERO(&rset);
	FD_SET(_socket,&rset);
	ret = select(_socket+1,&rset,0,0,&tv);
	if(ret <=0 ){
		return -1;
	}
	ret = recvfrom(_socket,buff,len,0,(sockaddr*)naddr.get_addr(),&socklen);	
	if( addr){
		*addr = naddr;
	}
	return ret;
	
}

bool	swlib::UdpSocket::create(){
	if(_socket!=SWINVALIDE_SOCKET){
		CLOSESOCKET(_socket);
	}
	_socket = socket(AF_INET,SOCK_DGRAM,0);
	return _socket>=0?true:false;
} 

int swlib::UdpSocket::write(char *buff,unsigned int len){
	int ret;	
	ret = send(_socket,buff,len,0);	
	return ret;
}

int swlib::UdpSocket::sendto(const SocketAddr& addr, char * buff,unsigned int len){
	int ret = ::sendto(_socket,buff,len,0,(sockaddr*)addr.get_addr(),sizeof(sockaddr));
	return ret;
}

//--UPD server while it as binding server,don't send data on its socket
// int swlib::UdpSocket::sendTo( swlib::SocketAddr& addr,char *buff,unsigned int len){
// 	int sock,ret;
// 	sock = socket(AF_INET,SOCK_DGRAM,0);
// 	if( sock < 0) return -1;
// 	ret = sendto(sock,buff,len,0,(sockaddr*)addr.get_addr(),sizeof(sockaddr));
// 	CLOSESOCKET(sock);
// 	return ret;
// }

bool	swlib::UdpSocket::bind_addr(const SocketAddr& saddr){
	if( _socket < 0){
		return false;
	}
	if( bind(_socket,(sockaddr*)saddr.get_addr(),sizeof(sockaddr))){
		CLOSESOCKET(_socket);
		_socket = SWINVALIDE_SOCKET;
		return false;
	}	
	return true;
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//TcpSocket

swlib::TcpSocket::TcpSocket(){
	
}

bool	swlib::TcpSocket::create(){
	if(_socket!=SWINVALIDE_SOCKET){
		CLOSESOCKET(_socket);
	}
	_socket = socket(AF_INET,SOCK_STREAM,0);
	return _socket>=0?true:false;
}

int swlib::TcpSocket::read(char *buff ,unsigned int len,swlib::SocketAddr *){	
	return recv(_socket,buff,len,0);	
}

int swlib::TcpSocket::peek(){
	char szBuffer[1] ;
	return ::recv(_socket, szBuffer, 1, MSG_PEEK); 
}

int swlib::TcpSocket::write(char *buff,unsigned int len){
	ScopeLocker l(_mtx);
	return sendall(_socket,buff,len);
}

int swlib::TcpSocket::sendall(int sock,char *buff,unsigned int len){
	int ret;
	int left;
	left = len;		
	while(left>0){
		ret = send(sock,buff,left,0);
		if(ret<=0){			
			return -1;			
		}
		left-=ret;
		buff+=ret;
	}		
	return len;
}


bool	swlib::TcpSocket::bind_addr(const  swlib::SocketAddr& saddr){
	//_socket = socket(AF_INET,SOCK_DGRAM,0);
	if( _socket < 0){
		printf("socket error\n");
		return false;
	}
	if( bind(_socket,(sockaddr*)saddr.get_addr(),sizeof(sockaddr))){
		CLOSESOCKET(_socket);
		_socket = SWINVALIDE_SOCKET;
		printf("socket bind error\n");
		return false;
	}	
	if( listen(_socket,5)){
		CLOSESOCKET(_socket);
		_socket = SWINVALIDE_SOCKET;
		printf("socket listen error\n");
		return false;
	}
	return true;
}


swlib::TcpSocket* swlib::TcpSocket::accept(){
	swlib::TcpSocket* sock = NULL;
	sockaddr_in addrpeer;
	int size;
	size = sizeof(addrpeer);
	SOCK_HANDLE hsock = ::accept(_socket,(sockaddr*)&addrpeer,&size);
	if(hsock == SWINVALIDE_SOCKET){
		return NULL;
	}
	SocketAddr saddr;
	saddr.set_addr(&addrpeer);
	sock = new TcpSocket();
	sock->set_handle(hsock);
	sock->set_addr(saddr);
	return sock;
}

//END namespace 
//}
//#endif 
