
#ifndef _REDIRECT_ICE
#define _REDIRECT_ICE


module rd {

dictionary<string,string>	HashValueSet;
dictionary<string,string>	ReturnValueT;
sequence<byte> 				StreamDataT;
sequence<string>			StringListT;
sequence<HashValueSet>	HashValueListT;
sequence<int>					IntListT;
sequence<StringListT>	StringListListT;

struct CallResultT{
	bool succ;
	int errNo;
	string msg;
};

interface IService{
	string	getSequence();
	string	getType();	 		// das ,cmc,
	string	getId();				//service module id
	int 		getTimestamp();		//获取系统时钟  1970之后秒数
  string 	getVersion();	  //系统版本 2009.12.27
};

struct PingTargetT{
	int		netaddr;	// 
};
sequence<PingTargetT> PingTargetListT;

struct PingResultT{
	int netaddr;
	int responseTime;	//
	int timetick;
};
sequence<PingResultT> PingResultListT;

struct RdPingerInfoT{
	string  id;	//pinger
	string 	ip;	//本地ip
};

struct RdServerInfoT{
	string ip;
	int 	port;
};

sequence<RdServerInfoT> RdServerInfoListT; 

struct RdFrontInfoT{
	string id;
	string ip;	//内网地址
	string mac;	//主机mac
};

interface IRdDispatcher extends IService{
	PingTargetListT getPingList(RdPingerInfoT pinger);
	void completePing(RdPingerInfoT pinger,PingResultListT result);
	
	/*====================================================
		method: getBastRdServers()
			获取最佳的rdserver列表
		params: 
			areaName - 地理区域名称(shanghai,shandong ...)
			reqnum - 返回的ip最大数
			front -  rdfront系统的基本信息
	====================================================*/
	RdServerInfoListT getBastRdServers(string areaName,int reqnum,RdFrontInfoT front);
};



struct RdWorkSheetT{
	string areaName;	//地理区域
	string tradeNo;		//交易单号
	int 	 gameId;		//游戏编号
};

//rdfront 系统
interface IRdFront {
	CallResultT prepare(RdWorkSheetT sheet,int timeout);  //为交易准备一次通信 环境
	void end();	 //结束通信 
};


};


#endif

