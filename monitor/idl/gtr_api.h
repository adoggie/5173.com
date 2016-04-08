/*
gtr_api.h
========================
定义与游戏逻辑交互的接口
2009.12.12 zhangbin  created
	1. 修改二进制图片的传输方式，通过context完成
	2. 定义输出接口 init()/cleanup(),其他函数通过内部登记来实现
2009.12.13 zhangbin
	1.添加日志回调

2010.3.25 zhangbin 
	1.添加 auth() 密保认证回调;captureImage()抓屏幕回调
	3.添加 Gt_CallContext.id字段
2010.3.29 zhangbin
1.修正部分声明的错误

2010.4.6 zhangbin 
1. 定义Gt_ReturnValueT各个值
2. 通过GetProcAddress动态获取game dll的接口,所以游戏dll无需关心 Gt_CallContext.apilist
3. 增加 auth_result回调

*/


#ifndef _GT_API_H
#define _GT_API_H
#include <windows.h>


enum Gt_ReturnValueT{	
	GT_FALSE=0,									//假
	GT_TRUE=1,									//真
	GT_UNABLECONNECT=2,							//无法连接
	GT_PASSWORDERROR=3,							//账号密码错误
	GT_PLAYERINLINE=4,							//玩家在线
	GT_VERSIONERROR=5,							//版本错误
	GT_UNABLEGETINFO=6,							//无法获得
	GT_VERIFYCODEERROR=7,						//验证码错误
	GT_ROLELOCK=8,								//角色被封
	GT_MBERROR=9,								//密保卡错误
	GT_ROLENEEDCHANGENAME=10,					//角色需要修改名字（DNF合服）
	GT_ROLEKICK=11,								//角色被踢下线
	GT_SECONDPWDERROR=12,						//二级密码或者仓库密码错误
	GT_UNABLEMOVETO=13,							//无法到达
	GT_UNABLETALKTO=14,							//无法对话
	GT_TIMEOUT=15,								//超时
	GT_PlAYERNOFEE=16,							//卖家游戏点卡不足
	GT_CONNECTBREAK=17,							//连接中断
	GT_NOTEXISTED=18,							//访问对象不存在 2010.3.27
	GT_SKIP_PASS=19,							//此调用无需判断，直接忽略
	GT_OK = GT_TRUE,							//成功
	GT_MAIlBOXFULL=20,							//邮箱满了
	GT_MAIlBOXLOCKED=21,						//(买家或卖家)邮箱冻结
	GT_UNKNOWN=0xffff
};

typedef int		GT_BOOL;
#define POUT
#define PIN
#define PINOUT

typedef Gt_ReturnValueT GT_RESULT;
typedef int Gt_NPCID;

enum Gt_ImageTypeT{
	GT_IMAGEJPEG =1,
	GT_IMAGEPNG,
	GT_IMAGEBMP
};

enum Gt_GameItemT{
	GT_ITEM_1,		//金币
	GT_ITEM_2,		//金砖
	GT_ITEM_MAX
};

struct Gt_ApiList;

typedef struct Gt_CallContext{
	int			timeout	;			// msec 调用超时
	void*		cookie;				// 外部使用
	void*		cookie2;			// 游戏内部使用,可用于保持状态
	char*		xdata;				// 数据交换地址,数据必须立刻复制
	int			xsize;				// 数据交换大小
	int			xtype;				// 交换数据类型
	Gt_ApiList*		apilist;	//函数入口表 游戏dll内部维持接口表，在初始化时赋值给此变量
	 void	 (__stdcall *log)  (Gt_CallContext* ctx,char* msg);						//游戏逻辑运行时日志输出
	void  (__stdcall *log2)(Gt_CallContext* ctx,char* data,int size); //游戏逻辑运行时日志输出	
	char* (__stdcall *auth_coords)(Gt_CallContext* ctx,char* coords); //坐标认证
	char* (__stdcall *auth_image)(Gt_CallContext* ctx,Gt_ImageTypeT imagetype,char* imagedata,int size,int width,int height);
	void 	(__stdcall *capture_image)(Gt_CallContext* ctx,char* excName,char* imagedata,int size,int width,int height);	
	int		id;		//游戏逻辑使用	
	int  (__stdcall *auth_result)(Gt_CallContext* ctx,int succ) ;  //返回验证码或者秘宝卡输入正确与否(succ: 0 - 错误; 1 - 正确)，用于答题员考核( type : 1 - 密保卡 ; 2 - 验证码 )
	
}CALLCTX;


struct Gt_ApiList{	
	GT_RESULT (__stdcall *SelectServer)(char *,CALLCTX*);						//选大区	订单中大区信息	OK	无法连接					SelectServer		char*
	GT_RESULT (__stdcall *SelectArea)(char*,CALLCTX*);							//选小区	订单中小区信息	OK	无法连接					SelectArea		char*
	// null 自动选择线路
	GT_RESULT (__stdcall *SelectLineByName)(char* line,CALLCTX*);		// 		选线路	Ping值较低	OK	无法连接					SelectLine		void
	// -1 自动选择线路
	GT_RESULT (__stdcall *SelectLineByIndex)(int line,CALLCTX*);		// 		选线路	Ping值较低	OK	无法连接					SelectLine		void	
	GT_RESULT (__stdcall *Login)(char* usr,char* passwd,CALLCTX*);	// 		账号密码输入	订单中账号密码信息	OK	账号密码错误	玩家在线		版本错误		Login		char* account, char* pwd
	GT_RESULT (__stdcall *IsExistDynMB)(CALLCTX*);									// 		查询动态密保		有	无					IsExistDynMB		void	
	GT_RESULT (__stdcall *IsRightClass)(int,CALLCTX* );							// 		查询角色阵营	订单中卖家阵营	是	否					IsRightClass		int	
	GT_RESULT (__stdcall *IsExistBackHomeSkill)(CALLCTX*);					// 		查询回城技能		是	否					IsExistBackHomeSkill		void
	GT_RESULT (__stdcall *UseBackHomeSkill)(CALLCTX*);							// 		使用回城技能		OK	失败					UseBackHomeSkill		void
	GT_RESULT (__stdcall *IsExistBackHomeItem)(CALLCTX*);					// 		查询是否存在回城物品		是	否					
	GT_RESULT (__stdcall *UseBackHomeItem)(CALLCTX*);							// 		使用回城物品		OK	失败						
	GT_RESULT (__stdcall *QueryRoleLevel)(char* ,POUT int *,CALLCTX*); // 		查询卖家角色等级		OK	失败					QuerySellerLevel		char*, int*
	GT_RESULT (__stdcall *SelectRoleByName)(char*,CALLCTX*);				// 		角色选择	订单中的角色名信息	OK	角色名不存在	角色需要修改名字（DNF合服）				SelectRoleByName		char*
	GT_RESULT (__stdcall *SelectRoleByIndex)(int,CALLCTX*);					// 		序号选择	订单中的角色序号信息	OK	无法登陆该序号角色					SelectRoleByIndex		int
	GT_RESULT (__stdcall *IsExistRoleByName)(char* ,CALLCTX*);			// 		查询买家角色名	订单中买家角色名信息	有	无					IsExistBuyerByName		char*
	GT_RESULT (__stdcall *AddRoleToFriend)(char*,CALLCTX*);				// 		加买家为好友	订单中买家角色名信息	OK	无该玩家					AddBuyerToFriend		char*		
	GT_RESULT (__stdcall *QuerySafeTime)(POUT int* ,CALLCTX*);						// 		获取安全时间			安全时间					QuerySafeTime		int*		
	GT_RESULT (__stdcall *IsExistNPC)(Gt_NPCID ,CALLCTX*);								// 		判定指定NPC是否在附近	NPCID	是	否					IsExistNPC		int	
	GT_RESULT (__stdcall *OpenWarehouse)(char* passwd,CALLCTX*);						// 		打开仓库	订单中的仓库密码信息	OK	密码错误					OpenWarehouse		char*
	GT_RESULT (__stdcall *OpenMailBox)(char* passwd,CALLCTX*);						//邮箱  二级密码
	GT_RESULT (__stdcall *OpenBank)(char* passwd,CALLCTX*);							//银行 二级密码
	GT_RESULT (__stdcall *OpenExchange)(char* passwd,CALLCTX*); 					//交易所 二级密码	
	GT_RESULT (__stdcall *OpenGrocer)(char* passwd,CALLCTX*); 					//杂货商 二级密码
	
	GT_RESULT (__stdcall *MoveToByNpcID)(Gt_NPCID,CALLCTX*);							// 		跑地图	NPCID	OK	无法到达					MoveToByNpcID		int NPCID
	GT_RESULT (__stdcall *Talk)(Gt_NPCID,CALLCTX*);											// 		与邮箱NPC对话	NPCID	OK	无法对话					Talk		int NPCID
	//查询物品数量 ,  item - 具体的游戏可交易的对象(金币、元宝、金砖。。。)
	GT_RESULT (__stdcall *QueryItemsInBag)(Gt_GameItemT item,POUT INT64*,CALLCTX*);				//背包
	GT_RESULT (__stdcall *QueryItemsInWarehouse)(Gt_GameItemT item,POUT INT64*,CALLCTX*);	//仓库
	GT_RESULT (__stdcall *QueryItemsInBank)(Gt_GameItemT item,POUT INT64*,CALLCTX*);				// 银行
	GT_RESULT (__stdcall *QueryItemsInExchange)(Gt_GameItemT item,POUT INT64*,CALLCTX*);		//交易所
	//邮件特例处理
	GT_RESULT (__stdcall *IsEnoughItemsInMailbox)(Gt_GameItemT item,PINOUT INT64*,CALLCTX*);		// 邮箱金币是否满足差额
	//获得指定物品数量 
	GT_RESULT (__stdcall *WithdrawItemsInWarehouse)(Gt_GameItemT item,PINOUT INT64*,CALLCTX*);	// 		获取仓库金币信息			返回仓库中金币数额	无法获取				QueryGoldsInWarehouse		int64*
	GT_RESULT (__stdcall *WithdrawItemsInBank)(Gt_GameItemT item,PINOUT INT64*,CALLCTX*);				// 		获取仓库金币信息			返回仓库中金币数额	无法获取				QueryGoldsInWarehouse		int64*
	GT_RESULT (__stdcall *WithdrawItemsInExchange)(Gt_GameItemT item,PINOUT INT64*,CALLCTX*);		// 		获取仓库金币信息			返回仓库中金币数额	无法获取				QueryGoldsInWarehouse		int64*
	GT_RESULT (__stdcall *WithdrawItemsInMailbox)(Gt_GameItemT item,PINOUT  INT64*,CALLCTX*);		// 		邮箱金币是否满足差额
	//发送邮件
	GT_RESULT (__stdcall *SendMail)(char* reciever,char* title,char* content,INT64,CALLCTX*);	
	//兑换给Npc
	GT_RESULT (__stdcall *SellItem)(int item,int itemNum,CALLCTX*);							// 		兑换银票，金砖	金币数额		返回兑换后金币数额	无法获取				SellItem		int64

	//传送 返回GT_TRUE代表成功，GT_FALSE没有失败
	GT_RESULT (__stdcall *Transport)( int mapid, CALLCTX* );
	//查询解锁与否 返回GT_TRUE代表解锁，GT_FALSE没有解锁
	GT_RESULT (__stdcall *IsUnlocked)(CALLCTX*);
	//查询玩家是否在某某地图 返回GT_TRUE代表是，GT_FALSE否
	GT_RESULT (__stdcall *IsInMap)( int mapid, CALLCTX* );

	GT_RESULT (__stdcall *ReturnToSelectRole)( CALLCTX* );

	GT_RESULT (__stdcall *MoveTo)(int type, CALLCTX *ctx);

	GT_RESULT (__stdcall *IsNearBy)(Gt_NPCID, CALLCTX *ctx);

	GT_RESULT (__stdcall *Begin)(CALLCTX*);				//开单
	GT_RESULT (__stdcall *End)(CALLCTX*);					//结单
	GT_BOOL (__stdcall *Init)(char * gamedir,CALLCTX* ctx);
	void		(__stdcall *CleanUp)(CALLCTX* ctx);
};


//////////////////////////////////////////////////////////////////////////
//错误码
// -- --- ------  交易状态 -- --- ------ 
#define GT_ERR_1000 1000	//交易成功
#define GT_ERR_2000	2000	//账号密码错误
#define GT_ERR_2010	2010	//无角色
#define GT_ERR_2020	2020	//仓库密码二级密码错误
#define GT_ERR_2030	2030	//不足发货金币
#define GT_ERR_2040	2040	//购买方买错阵营
#define GT_ERR_2050	2050	//购买方色名错误
#define GT_ERR_2060	2060	//卖家等级不够
#define GT_ERR_2070	2070	//卖家金币上限
#define GT_ERR_2080	2080	//买家邮箱满
#define GT_ERR_2090	2090	//密保上传错误（完美系列）
#define GT_ERR_3000	3000	//大区无法连接
#define GT_ERR_3010	3010	//动态密保直接转人工
#define GT_ERR_3020	3020	//小区无法连接
#define GT_ERR_3030	3030	//安全时间大于5分钟
#define GT_ERR_3040	3040	//当前地图不在指定交易NPC城池
#define GT_ERR_3050	3050	//卖家连续顶号
#define GT_ERR_3060	3060	//邮寄次数上限（DNF）
#define GT_ERR_3070	3070	//买家邮箱满
#define GT_ERR_3080	3080	//买家等级不够（DNF）
#define GT_ERR_3090	3090	//卖家背包满了，仓库满导致无法取邮件（DNF）
#define GT_ERR_3100	3100	//卖家号游戏点数不足
#define GT_ERR_3110	3110	//卖家绑定静态密报未上传的
#define GT_ERR_3120	3120	//各种不可控因素导致的超时等(汇总)
//-- --- ------ 审核状态 -- --- ------ 
#define GT_ERR_4000	4000	//账号密码错误
#define GT_ERR_4010	4010	//角色无法登陆（无角色）
#define GT_ERR_4020	4020	//仓库密码错误
#define GT_ERR_4030	4030	//不足发货金币
#define GT_ERR_4040	4040	//密保卡错误
#define GT_ERR_4050	4050	//卖家等级不够
#define GT_ERR_4060	4060	//卖家号游戏点数不足
#define GT_ERR_5000	5000	//动态密保直接转人工
#define GT_ERR_5010	5010	//大区无法连接（服务器维护、网络延时等情况）
#define GT_ERR_5020	5020	//密保卡错误
#define GT_ERR_5030	5030	//小区无法连接
#define GT_ERR_5040	5040	//当前地图不在指定交易NPC城池
#define GT_ERR_5050	5050	//卖家连续顶号
#define GT_ERR_5060	5060	//各种不可控因素导致的超时等(汇总)
#define GT_ERR_5070	5070	//审核成功




#endif