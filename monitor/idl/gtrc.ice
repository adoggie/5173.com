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

2010.4.7 zhangbin
1. 添加交易和验证的任务数据结构
2. 添加答题支持接口

2010.4.8 zhangbin
1.答题结果置入QuestionResultT结构

2010.4.13 zhangbin
1.GameTaskLet添加 secretKey

2010.4.15 zhangbin
1.修改 QuestionContentT结构，定义4种验证数据类型的组合方式 

2010.4.19 zhangbin
1.修改 IAnswerEndpoint.addQuestion()接口
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
	int 			type; 	// 1- 图片 ,2 - 坐标  (robot->server 不使用)
	ImageDataT image; //秘宝图片 (robot->server 不使用)
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


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

struct QuestionContentT{
	int type;								// 1- 密保卡(图片+文本坐标), 2- 密保卡(图片+图片坐标);3-验证码(图片)
	ImageDataT image;				//图片 1,2,3
	ImageDataT image2;			//密保卡坐标是图片 2
	string text;						//密保卡坐标 1
	int cookie;							//事务编号
	string gameId;					//游戏编号
};

//答题结果
struct QuestionResultT{
	string value;	//答题结果
	int cookie;	 //server用于区分答题结果的sequence
};

interface IQuestionServer;

//答题器程序
interface IAnswerEndpoint extends IService{
	/*************************************************
		getRemains()
		返回当前未处理题目数量
	**************************************************/
	int getRemains()	;	//返回当前待处理的题目数量
	/*************************************************
		addQuestion()
		添加答题内容
		@params:
			server -  答题服务器
			no - 交易单号
			createTime - 开始时间
			question- 答题内容
		@return : 返回当前未处理题目数量
	**************************************************/
	int addQuestion(IQuestionServer* server,string no ,string createTime,QuestionContentT question);	//
};

//提问者
interface IQuestionAsker{
	/*************************************************
	 answerResult()
	 答题服务器返回答题结果
	 @params:
		no -  交易单号
		result - 服务器返回认证码
	@return: 
	**************************************************/	
	void answerResult(string no,string result);
};

interface IQuestionServer {
	/*************************************************
		answer()
		机器人提交答题请求
		@params:
			asker - 提问者 
			no - 交易单号
			question - 题目
	**************************************************/
	void answer(IQuestionAsker* asker,string no,QuestionContentT question);
	/*************************************************
		answerResult()
		答题器返回答题结果
		@params:
			no - 交易单号
			result - 答题内容
	**************************************************/
	void answerResult(string no,QuestionResultT result);
	
	
	/*************************************************
	 registerAnswer()
	 注册答题器
	 @params:
		answer - 答题器接口
	**************************************************/
	//bool registerAnswer(IAnswerEndpoint answer);
	/*************************************************
	 login()
	 操作人员登录
	 @params:
		worker - 工号
		passwd - 密码
	@return:		
	**************************************************/
	CallReturnT login(IAnswerEndpoint* answer,string worker,string passwd);
	/*************************************************
	 logout()
	 操作人员登出
	**************************************************/
	void logout(IAnswerEndpoint* answer,string worker);
	/*************************************************
	 verfiyAnswer()
	 机器人返回答题是否正确
	 @params:
		no -  交易单号
		type - 1- 密保卡(图片+坐标), 2-验证码
		succ - 答题是否成功
	@return: 
	**************************************************/	
	void verifyAnswer(string no,int type,bool succ);
	
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

	
struct LogMessageT{
	int 					xclass;	//消息类型	
	string 				msg;	
};

//日志功能
interface ILogger {
	void gameMsg(GameIdentifyT gameId,int timetick,LogMessageT msg);  // timetick - 1970~ s
	void gameImage(GameIdentifyT gameId,int timetick,string opName,ImageDataT image);	//抓图 opName - 执行游戏步骤名称
};


//日志服务器
interface ILogServer extends ILogger,IService{
	
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//游戏工作单类型
enum GameWorkSheetTypeT{
	gwsPost,					//邮寄
	gwsAccountAudit, //帐号审核
	gwsVerify				//验证
};

//邮寄
struct GameWorkSheetPostT {
	string 	sellerActor;	// 卖家角色
	int			sellerLevel;	// 卖家等级
	long		money;			// 交易金币
	int			transactionTime;// 交易剩余时间
	string 	sellerSecondPwd;// 卖家2级密码
	string 	buyerActor;		// 买家角色
	int			buyerLevel;		// 买家等级
	long		buyerMoney;		// 买金币数
	int			sellerIndex;	// 卖家序号
	int			sellerGroup;	// 卖家阵营
	string 	bankPwd;		// 钱庄密码

};
//审核
struct GameWorkSheetAccountAuditT {
	string 	sellerActor;			// 卖家角色
	string 	sellerSecondPwd;	// 卖家2级密码
	int			sellerIndex;			// 卖家角色序号
	int			sellerGroup;			// 卖家阵营
	string 	bankPwd;					// 钱庄密码
};
//验证
struct GameWorkSheetVerifyT {
	string 	sellerActor;			// 卖家角色
	int 		level;						// 角色等级
	long 		money;						// 货币数量
	int			verifyTime; 			// 验证剩余时间
	string 	sellerSecondPwd;	// 卖家2级密码
	int			sellerIndex;			// 卖家角色序号
	int			sellerGroup;			// 卖家阵营
	string 	bankPwd;					// 钱庄密码
};

//交易任务信息
//Tasklet包含所有的业务处理类型，但同时只有一种有效
struct GameTaskletT{
	string id;			//任务编号 ,无单 id = 空
	int 	 type;		//业务类型 
	string no;			//单号
	string gameId;	//游戏编号
	string account;	//帐号
	string password;
	string area;		//区
	string server;	//服务器
	string lineName;//线路名称(为空则lineNo)
	short	 lineNo;	//线路编号
	string createTime;
	string secretKey;	//安全密钥 
	
	GameWorkSheetPostT 					post;	//邮寄
	GameWorkSheetAccountAuditT 	audit; //审核
	GameWorkSheetVerifyT				verify; //验证
};

struct GameTaskResultT{
	string id;		//任务编号
	string no;		//单号 (冗余)
	int 	 type;	//业务类型
	string gameId;	//游戏编号(冗余)
	int result;		//处理结果
	string errmsg;	//提示信息	
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//gtr控制服务端接口
interface IGameHost extends IQuestionAsker,IService,ILogger{	
	GameTaskletT					getTask();		//获取任务
	void									completeTask(GameTaskResultT result);		 //

	/*************************************************
		answer()
		游戏动态库提交答题请求
		处理要实现阻塞
		@params:			
			question - 题目
		@return: 答题结果
	**************************************************/
	string answer(QuestionContentT question);
	/*************************************************
	 verfiyAnswer()
	 机器人返回答题是否正确,必须上报到答题服务器
	 @params:		
		type - 1- 密保卡(图片+坐标), 2-验证码
		succ - 答题是否成功
	@return: 
	**************************************************/	
	void verifyAnswer(int type,bool succ);
};


//游戏信息
struct GameInfoT{
	int 	id;				//编号
	string name;		//游戏名称 
	string version;	//游戏版本
};
sequence<GameInfoT> GameInfoListT;


//
struct GameRobotInfoT{
	string id;				//机器人id
	string ip;				//机器人主机ip
	int network;			//通信线路 , 1 - 电信 ; 2 - 网通 
	GameInfoListT	supportGames;
};

//服务器接口定义
//------------------------------------
interface IGtrServer extends IService,IQuestionServer{	
	GameTaskletT	getTask(GameRobotInfoT robot);		//获取任务
	void					completeTask(GameTaskResultT result);		 //	
};



};


#endif

