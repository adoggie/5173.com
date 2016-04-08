/*

2010.3.25 zhangbin 
1.create,定义game-core的网络接口

协定:
	1.数据类型名称尾部添加T

2010.3.27 zhangin

2010.3.29 zhangbin
1. 取消工作单GameWorkSheetT结构
2. 修改 ISecureService.auth()安全认证的数据类型
2010.3.30 zhangbin 
1. heartbeat()移动到IService接口
*/


#ifndef _GTR_ICE
#define _GTR_ICE


module gtr {

dictionary<string,string>	HashValueSet;
dictionary<string,string>	ReturnValueT;
sequence<byte> 				ByteStreamT;
sequence<string>			StringListT;
sequence<HashValueSet>	HashValueListT;
sequence<int>					IntListT;
sequence<StringListT>	StringListListT;

struct CallReturnT{
	bool	succ;
	string msg;
	HashValueSet props;
};

const int IMAGEJPEG = 1;
const int IMAGEPNG =2 ;
const int IMAGEBMP = 3 ;


//图像数据
struct ImageDataT{
	int type;
	ByteStreamT	bytes;
	int width;
	int height;	
};

struct GameAuthDataT{
	int 			type; 	// 1- 图片 ,2 - 坐标
	ImageDataT image; //秘宝图片
	string seckey;  	//秘宝坐标
};


struct GameIdentifyT{
	string id;			//游戏编号
	string tradeNo;	//交易单号
};

struct ServiceIdentifyT{
	string id;
	string version;
};


interface IService{
	int			getType();	 		//  
	ServiceIdentifyT	getId();				//service module id
	int 							getTimestamp();		//获取系统时钟  1970之后秒数
	void 							shutdown();
	void 							heartbeat(string senderType,string senderId);  //发送者类型和Id
};

/*
enum LogMsgLevelT{
	logDEBUG,
	logINFO,
	logCRITICAL,
	logERROR
};
*/
	
struct LogMessageT{
	int 					xclass;	//消息类型	
	string 				msg;	
};

//日志功能
interface ILogger {
	void gameMsg(GameIdentifyT gameId,int timetick,LogMessageT msg);  // timetick - 1970~ s
	void gameImage(GameIdentifyT gameId,int timetick,string opName,ImageDataT image);	//抓图 opName - 执行游戏步骤名称
};

//安全管理，包括秘宝认证等
interface ISecure {
	string auth(GameIdentifyT gameId,GameAuthDataT data); 
};

//日志服务器
interface ILogServer extends ILogger,IService{
	
};

interface ISecureServer extends ISecure,IService{
};


//一个游戏任务相关的信息
enum GameWorkSheetTypeT{
	gwsPost,					//邮寄
	gwsAccountAudit, //帐号审核
	gwsVerify				//验证
};


//邮寄
struct GameWorkSheetPostT {
	long money;		
};
//审核
struct GameWorkSheetAccountAuditT {
	string any;
};
//验证
struct GameWorkSheetVerifyT {
	string any;
};

//交易任务信息
//Tasklet包含所有的业务处理类型，但同时只有一种有效
struct GameTaskletT{
	string id;							//任务编号
	int 	 type;							//处理类型
	string no;			//单号
	string gameId;	//游戏编号
	string account;	//帐号
	string password;
	string area;		//区
	string server;	//服务器
	string lineName;//线路名称(为空则lineNo)
	short	 lineNo;	//线路编号
	string createTime;
	
	GameWorkSheetPostT post;	//邮寄
	GameWorkSheetAccountAuditT audit;
	GameWorkSheetVerifyT		verify;
};

struct GameTaskResultT{
	string id;		//任务编号
	string no;		//单号 (冗余)
	string gameId;	//游戏编号(冗余)
	int result;		//处理结果
	string errmsg;	//提示信息	
};

//gtr控制服务端接口
interface IGameHost extends IService,ILogger,ISecure{	
	GameTaskletT					getTask();		//获取任务
	void									completeTask(GameTaskResultT result);		 //
	
};



};


#endif

