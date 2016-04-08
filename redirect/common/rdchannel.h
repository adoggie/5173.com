
#ifndef _RD_CHANNEL_H
#define _RD_CHANNEL_H

#include "base.h"
#include "stream.h"	 
#include "socket.h"
#include "thread.h"

typedef swUInt32 RedirectChannelID_t;
typedef swlib::SocketAddr RedirectAddress_t;

enum ConnectionStatus_t{
	DISCONNECTED,
	CONNECTED,
	APPROVING,
	APPROVED,
};

enum ConnectionMessage_t{
	CNM_HELO,			 //rdServer -> rdFront
	CNM_AUTH,				//rdFront -> rdServer
	CNM_ACCEPT,			// rdServer -> rdFront
	CNM_REJECT,			// rdServer -> rdFront
	CNM_HEARTBEAT,	// rdFront -> rdServer 
	CNM_SYSQUERY,		// rdpinger->rdServer 版本查询
	CNM_SYSQUERY_RESULT, //rdserver->rdpinger
	CNM_UPDATE,			// rdPinger->rdserver 版本升级
	CNM_REBOOT,			// rdPinger->rdserver 请求重新启动
	CNM_CHANNEL,		// rdfront <-> rdserver 通道消息
	CNM_ECHOIP_REQ=0x100,		 //rdserver -> dispatcher
	CNM_ECHOIP_RESP, // dispatcher ->rdserver
	CNM_RDSERVER_STATUS,	//rdserver->dispatcher 定时上报状态
	CNM_RDSERVER_SET,		//dispatcher -> rdserver 设置参数
};

struct ConnectionMessageBase{
	ConnectionMessageBase(swUInt16 id_){
		cnmid = (swUInt16)id_;
	}
	virtual swByteArray final();		//
	virtual bool decode(swByteStream& stream);
	virtual swUInt32	size();	//计算长度
	virtual swByteArray encode();
	virtual	~ConnectionMessageBase() {}
																																			 

	
	bool decodeShortString(swByteStream& stream,std::string& str){
		 
		if( stream.leftBytes() <1){
			return false;
		}
		swUInt8 len;
		stream.readValue(len);
		if( stream.leftBytes()<len){
			return false;
		}
		str.assign((char*)stream.current(),len);
		stream.forward(len);	 // forward nbytes
		return true;
	}
	


	bool decodeByteArray(swByteStream& stream,swByteArray& r){		
		if(stream.leftBytes()<4){
			return false;
		}
		swUInt32 len;
		stream.readValue(len);
		if(stream.leftBytes()<len){
			return false;
		}
		r.resize(len);
		memcpy(&r[0],stream.current(),len);
		stream.forward(len);
		return true;
	}

	


	swUInt16 cnmid;	
};
//////////////////////////////////////////////////////////////////////////
struct CNM_Helo_t:ConnectionMessageBase{
	CNM_Helo_t():ConnectionMessageBase(CNM_HELO){
		
	}
	//swByteArray final();		//
	bool decode(swByteStream& stream);
	swUInt32	size();	//计算长度
	swByteArray encode();

	std::string  helo;			//服务器发送回来
//	std::string  secureKey;
};
//////////////////////////////////////////////////////////////////////////
struct CNM_Auth_t:ConnectionMessageBase{
	CNM_Auth_t():ConnectionMessageBase(CNM_AUTH){

	}
	//swByteArray final();		//
	bool decode(swByteStream& stream);
	swUInt32	size();	//计算长度
	swByteArray encode();

	swByte		secureKey[16];	// key + Helo = this
	swUInt8				requester;	//请求者类型
};
//系统查询返回结果
struct CNM_SystemQueryResult:ConnectionMessageBase{
	CNM_SystemQueryResult():ConnectionMessageBase(CNM_SYSQUERY_RESULT){

	}
	//swByteArray final();		//
	bool decode(swByteStream& stream);
	swUInt32	size();	//计算长度
	swByteArray encode();

	swUInt32		ver;	//系统版本
	swUInt32		tick; //时钟
};

struct CNM_SystemUpdate:ConnectionMessageBase{
	CNM_SystemUpdate():ConnectionMessageBase(CNM_UPDATE){

	}
	//swByteArray final();		//
	bool decode(swByteStream& stream);
	swUInt32	size();	//计算长度
	swByteArray encode();

	swByteArray		medias;	//新系统程序 4字节长度+变长数据
};

//////////////////////////////////////////////////////////////////////////


enum ChannelMessage_t{
	CM_CONNECT_OPEN,
	CM_CONNECT_CLOSE,
	CM_CONNECT_HALFCLOSE,
	CM_CONNECT_REJECT,
	CM_CONNECT_ACCEPT,
	CM_STREAM_DATA,
	CM_DGRAM_DATA
};

struct ChannelMessageBase:ConnectionMessageBase{
	swUInt16 cmid;
	RedirectChannelID_t cid;
	ChannelMessageBase(swUInt16 id_):ConnectionMessageBase(CNM_CHANNEL){
		cmid =(swUInt16) id_ ;
	}
	//swByteArray final();		//
	bool decode(swByteStream& stream);
	swUInt32	size();	//计算长度
	swByteArray encode();
	virtual ~ChannelMessageBase(){}
};

struct CM_ConnectOpen_t: ChannelMessageBase{
	CM_ConnectOpen_t():ChannelMessageBase(CM_CONNECT_OPEN){
	}
	//swByteArray final();		//
	bool decode(swByteStream& stream);
	swUInt32	size();	//计算长度
	swByteArray encode();

	swUInt32	addr;
	swUInt16	port;
	swUInt16			timeout;	//允许连接超时,单位: seconds 
};

struct CM_ChannelData: ChannelMessageBase{
	CM_ChannelData(ChannelMessage_t cmid):ChannelMessageBase(cmid){
	}
	//swByteArray final();		//
	bool decode(swByteStream& stream);
	swUInt32	size();	//计算长度
	swByteArray encode();
	virtual ~CM_ChannelData(){}

	swByteArray data;	 // 4+data
};

struct CM_DgramData: CM_ChannelData{
	CM_DgramData():CM_ChannelData(CM_DGRAM_DATA){

	}
};

struct CM_StreamData: CM_ChannelData{
	CM_StreamData():CM_ChannelData(CM_STREAM_DATA){

	}
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//Rdserver <-> Rdserver
//////////////////////////////////////////////////////////////////////////
struct CNM_RdServer_EchoIPReq_t:ConnectionMessageBase{
	CNM_RdServer_EchoIPReq_t():ConnectionMessageBase(CNM_ECHOIP_REQ){
	}
};

struct CNM_RdServer_EchoIPResp_t:ConnectionMessageBase{
	CNM_RdServer_EchoIPResp_t():ConnectionMessageBase(CNM_ECHOIP_RESP){
	}
	//swByteArray final();		//
	bool decode(swByteStream& stream);
	swUInt32	size();	//计算长度
	swByteArray encode();

	swUInt32 ip;	//回显的公网ip地址
};

struct CNM_RdServer_Status_t:ConnectionMessageBase{
	CNM_RdServer_Status_t():ConnectionMessageBase(CNM_RDSERVER_STATUS){

	}
	//swByteArray final();		//
	bool decode(swByteStream& stream);
	swUInt32	size();	//计算长度
	swByteArray encode();

	swUInt32 tick;		//当前时间
	swUInt32 conNum;	//连接数
	swUInt32 ipaddr;  //网络字节
	swUInt16 port;		//服务端口
	swUInt16	rptInterval;	//状态上报时间间隔
	std::string	mac;	//网卡地址		1+n
	std::string hostname;//					1+n
	std::string vendor;		//发布者
};


//Dispatcher设置Rdserver运行参数
struct CNM_RdServer_Set_t:ConnectionMessageBase{
	CNM_RdServer_Set_t():ConnectionMessageBase(CNM_RDSERVER_SET){

	}
	//swByteArray final();		//
	bool decode(swByteStream& stream);
	swUInt32	size();	//计算长度
	swByteArray encode();

	enum{
		mask_Interval=0,  //上报间隔
	  
	};
	swUInt32	mask;
	swUInt16	rptInterval;	//状态上报时间间隔
};




//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/*
class RedirectConnection;

class RedirectServerBase;

class RedirectChannel:swlib::Thread{
public:
	RedirectChannel(const RedirectConnection* conn);
	//void setSockIn(shared_ptr<swlib::Socket> sockIn);
	//void setSockOut(shared_ptr<swlib::Socket> sockOut);
protected:
	void run();
protected:
	RedirectChannelID_t	_id;
	shared_ptr<swlib::Socket> _sockIn;
	shared_ptr<swlib::Socket> _sockOut;//outgoing
	RedirectConnection* _conn;
	RedirectServerBase* _server;
};

class RedirectChannel_Stream:public RedirectChannel{

};

class RedirectChannel_Dgram:public RedirectChannel{

};
*/


#endif