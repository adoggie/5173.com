
#ifndef _RD_SERVER_H
#define _RD_SERVER_H

#include "../common/rd.h"
#include "../common/rdserverbase.h"
#include "rdconnection.h"

typedef swUInt32 RdServerVersion_t;


struct RdServerProperties_t{
	std::string secureKey;	
	swUInt32	version;
	swUInt32 netaddr;		//������ַ
	swUInt16 listenport;
	swUInt16 rptInterval;	//��ʱ�ϱ����
	std::string mac;			//������ַ
	std::string hostname;
	swlib::SocketAddr dispAddr;	//���ȷ�������ַ
	std::string strHelo;
	
};

class RdServer:public RedirectServerBase{
public:
	RdServer();
	RdServerProperties_t& getProps(){	return _props;}
	bool start();
	int mainloop();
	void prepare();
	CNM_SystemQueryResult getSystemInfo();
	swUInt32 getPublicNetAddr();	//��ȡ������ַ
	void lostConnection(RedirectConnection*);	//���Ӷ�ʧ
	swByteArray encrypt(swByteArray& data);  //�������ݰ�
	swByteArray decrypt(swByteArray& data);		//�������ݱ� 
	bool reachable(); //����Ƿ������
	static void __threadUdpRecv(swlib::Thread* t,void* user);
	void threadUdpRecv(swlib::Thread* t);
	void removeConnection(const RedirectConnection* rc);
	std::string makeHelo();
	std::string getVendorId();
	bool getDispatchServer(std::string&host,swUInt16& port);
private:
	RdServerProperties_t	_props;
	std::vector<RedirectConnection*> _connlist;
	swlib::UdpSocket	_udpsock;
	swlib::Mutex _mtx_cnn;
	shared_ptr<swlib::Thread> _threadUdp;
};

#define RD_MAKEVERSION(m1,m2,m3,m4) (m1<<24|m2<<16|m3<<8|m4) 

#define RD_SERVERVERSION			RD_MAKEVERSION(0,1,0,1)

#endif

