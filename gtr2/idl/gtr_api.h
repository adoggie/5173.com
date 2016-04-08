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
	GT_INSAFETIME=22,							//在安全时间中,操作失败
	GT_DYNAMICMB=23,							//有动态密保
	GT_RECOQNIZEREMPTY=24,						//答题器答题结果为空,放弃答题
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
	GT_IMAGEBMP,
	GT_IMAGENOHEAD,
	GT_IMAGENOHEAD_TLBB,
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
	//选大区 参数1:订单中大区信息
	GT_RESULT (__stdcall *SelectServer)(char *,CALLCTX*);
	//选大区 参数1:订单中小区信息
	GT_RESULT (__stdcall *SelectArea)(char*,CALLCTX*);
	//根据线路名称选线  参数1:订单中线路名称 另参数1为null 自动选择线路
	GT_RESULT (__stdcall *SelectLineByName)(char* line,CALLCTX*);
	//根据线路索引选线	参数1:订单中线路索引 另参数1为-1 自动选择线路
	GT_RESULT (__stdcall *SelectLineByIndex)(int line,CALLCTX*);
	//账号密码登陆 参数1:订单中账号 参数2:订单中密码
	GT_RESULT (__stdcall *Login)(char* usr,char* passwd,CALLCTX*);
	//是否存在动态密保
	GT_RESULT (__stdcall *IsExistDynMB)(CALLCTX*);
	//是否正确的阵营
	GT_RESULT (__stdcall *IsRightClass)(int,CALLCTX* );
	//是否存在回城技能
	GT_RESULT (__stdcall *IsExistBackHomeSkill)(CALLCTX*);
	//使用回城技能
	GT_RESULT (__stdcall *UseBackHomeSkill)(CALLCTX*);
	//是否存在回城物品
	GT_RESULT (__stdcall *IsExistBackHomeItem)(CALLCTX*);
	//使用回城物品
	GT_RESULT (__stdcall *UseBackHomeItem)(CALLCTX*);
	//查询角色等级 参数1:需要查询的角色名字 参数2:返回角色的等级
	GT_RESULT (__stdcall *QueryRoleLevel)(char* ,POUT int *,CALLCTX*);
	//根据名称选择角色登陆 参数1:订单中角色名字
	GT_RESULT (__stdcall *SelectRoleByName)(char*,CALLCTX*);
	//根据索引选择角色登陆 参数1:订单中角色索引
	GT_RESULT (__stdcall *SelectRoleByIndex)(int,CALLCTX*);
	//根据角色名,判断角色是否存在 参数1:角色名字(可能是卖家或者买家角色名)
	GT_RESULT (__stdcall *IsExistRoleByName)(char* ,CALLCTX*);
	//增加角色为好友 参数1:角色名字
	GT_RESULT (__stdcall *AddRoleToFriend)(char*,CALLCTX*);
	//查询安全时间 参数1:返回的安全时间(秒)
	GT_RESULT (__stdcall *QuerySafeTime)(POUT int* ,CALLCTX*);
	//查询NPC是否存在 参数1:定义的NPC类型的枚举
	GT_RESULT (__stdcall *IsExistNPC)(Gt_NPCID ,CALLCTX*);
	//打开仓库 参数1:仓库密码
	GT_RESULT (__stdcall *OpenWarehouse)(char* passwd,CALLCTX*);
	//打开邮箱 参数1:邮箱密码
	GT_RESULT (__stdcall *OpenMailBox)(char* passwd,CALLCTX*);
	//打开银行 参数1:银行密码
	GT_RESULT (__stdcall *OpenBank)(char* passwd,CALLCTX*);
	//打开交易所 参数1:交易所密码
	GT_RESULT (__stdcall *OpenExchange)(char* passwd,CALLCTX*);
	//打开杂货商 参数1:杂货商密码
	GT_RESULT (__stdcall *OpenGrocer)(char* passwd,CALLCTX*);
	//移动到指定类型的NPC位置 参数1:定义的NPC类型的枚举
	GT_RESULT (__stdcall *MoveToByNpcID)(Gt_NPCID,CALLCTX*);
	//对话指定类型的NPC位置 参数1:定义的NPC类型的枚举
	GT_RESULT (__stdcall *Talk)(Gt_NPCID,CALLCTX*);
	//查询物品数量 ,  item - 具体的游戏可交易的对象(金币、元宝、金砖。。。)
	GT_RESULT (__stdcall *QueryItemsInBag)(Gt_GameItemT item,POUT INT64*,CALLCTX*);				//背包
	GT_RESULT (__stdcall *QueryItemsInWarehouse)(Gt_GameItemT item,POUT INT64*,CALLCTX*);	//仓库
	GT_RESULT (__stdcall *QueryItemsInBank)(Gt_GameItemT item,POUT INT64*,CALLCTX*);				// 银行
	GT_RESULT (__stdcall *QueryItemsInExchange)(Gt_GameItemT item,POUT INT64*,CALLCTX*);		//交易所
	//邮件特例处理
	GT_RESULT (__stdcall *IsEnoughItemsInMailbox)(Gt_GameItemT item,PINOUT INT64*,CALLCTX*);		// 邮箱金币是否满足差额
	//获得指定物品数量 
	GT_RESULT (__stdcall *WithdrawItemsInWarehouse)(Gt_GameItemT item,PINOUT INT64*,CALLCTX*);
	GT_RESULT (__stdcall *WithdrawItemsInBank)(Gt_GameItemT item,PINOUT INT64*,CALLCTX*);
	GT_RESULT (__stdcall *WithdrawItemsInExchange)(Gt_GameItemT item,PINOUT INT64*,CALLCTX*);
	GT_RESULT (__stdcall *WithdrawItemsInMailbox)(Gt_GameItemT item,PINOUT  INT64*,CALLCTX*);
	//发送邮件
	GT_RESULT (__stdcall *SendMail)(char* reciever,char* title,char* content,INT64,CALLCTX*);	
	//售出物品给NPC
	GT_RESULT (__stdcall *SellItem)(int item,int itemNum,CALLCTX*);

	//传送 返回GT_TRUE代表成功，GT_FALSE没有失败
	GT_RESULT (__stdcall *Transport)( int mapid, CALLCTX* );
	//查询解锁与否 返回GT_TRUE代表解锁，GT_FALSE没有解锁
	GT_RESULT (__stdcall *IsUnlocked)(CALLCTX*);
	//查询玩家是否在某某地图 返回GT_TRUE代表是，GT_FALSE否
	GT_RESULT (__stdcall *IsInMap)( int mapid, CALLCTX* );
	//返回选择角色画面
	GT_RESULT (__stdcall *ReturnToSelectRole)( CALLCTX* );
	//使用走路脚本专用(暂时诛仙2专用)
	GT_RESULT (__stdcall *MoveTo)(int type, CALLCTX *ctx);
	//判断NPC是否在玩家可点击对话范围之内(暂时诛仙2专用)
	GT_RESULT (__stdcall *IsNearBy)(Gt_NPCID, CALLCTX *ctx);

	//获取角色信息 参数1：数据 参数2：长度
	GT_RESULT (__stdcall *GetAccountInfo)(char**,int*,CALLCTX* ctx);
	//保存当前位置的角色信息 参数1可认为是Gt_NPCID
	GT_RESULT (__stdcall *SaveItemInfo)(int ,CALLCTX*);
	//获得最佳的路线 用于永恒之塔
	GT_RESULT (__stdcall *GetBestNPC)(int* , int*, CALLCTX*);
	//是否需要使用回城 用于永恒之塔
	GT_RESULT (__stdcall *IsNeedBackHome)(CALLCTX*);

	//函数功能:获取角色列表 
	//参数1:角色数据的缓冲区,内存由外部分配,存储角色姓名,使用\r\n作为分隔符,末尾以\0结束
	//参数2:外部分配的缓冲区长度
	//参数3:角色数量
	//调用示例:
	// char rolelist[1024] = {0};
	// int bufsize = 1024;
	// int rolenum;
	// char* begin = rolelist;
	// GetRoleList(begin,bufsize,&rolenum,call);
	//内部核心库按照以上示例实现
	GT_RESULT (__stdcall *GetRoleList)(char*,int,int*,CALLCTX* ctx);

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
#define GT_ERR_2100 2100	//邮箱被冻结
#define GT_ERR_2110 2110	//三级密码（钱庄密码）错误
#define GT_ERR_2120 2120	//卖家挂错阵营
#define GT_ERR_2130 2130	//卖家被买家屏蔽
#define GT_ERR_2140 2140	//有一个角色，角色名不匹配，金币不足，直接取消订单（提示：角色名不匹配，且金币数不足）

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
#define GT_ERR_3130	3130	//多个角色名，无角色名匹配，直接转人工（提示：角色名不匹配）
#define GT_ERR_3140	3140	//订单信息异常
#define GT_ERR_3150	3150	//传送费用不够
#define GT_ERR_3160 3160	//答题员放弃答题
#define GT_ERR_3170 3170	//大区不存在
#define GT_ERR_3180 3180	//小区不存在
#define GT_ERR_3190 3190	//连接服务器中断
#define GT_ERR_3200 3200	//加好友失败
#define GT_ERR_3210 3210	//玩家在线无法登陆
#define GT_ERR_3220 3220	//超过一封邮件
#define GT_ERR_3230 3230	//密保卡答题超时

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
#define GT_ERR_5080 5080	//答题员放弃答题
#define GT_ERR_5090 5090	//大区不存在
#define GT_ERR_5100 5100	//小区不存在
#define GT_ERR_5110 5110	//连接服务器中断


//-- --- ------ 账号审核状态 -- --- ------
#define GT_ERR_8000 8000	//帐号审核成功
#define GT_ERR_8010 8010	//帐号密码错误
#define GT_ERR_8020 8020	//游戏内仓库密码，解锁码等错误
#define GT_ERR_8030 8030	//游戏内无人物，帐号被冻结、锁定
#define GT_ERR_8040 8040	//帐号绑订密保卡，卖家未上传或者无法解除
#define GT_ERR_8050 8050	//不可控制的因数





#endif