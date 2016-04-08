#pragma once

#include "../idl/gtr_api.h"
#include <vector>
#include <string>
#include <map>
#include "service.h"
#include "gtrmethod.h"
using namespace std;

class GtrChecker
{
public:
	virtual void Do() = 0;
};

class GtrApiWrap
{ 
	CALLCTX* _ctx;
	int _tries;
	int _sleep;
	int _total_timeout;

	GT_RESULT _lastReturn;
	map<string, GtrMethod*> _settings;
	vector<GtrChecker*> _checkers;

	swlib::swLogger	_dbglogger;
	time_t		_tmStart;

	bool isTimeout();

	GT_BOOL Init(char * gamedir );
	void CleanUp( );

	void ParamInit(string name);
	void set_param(string name);
	void begin_core(string name);
	bool end_core(string name);
	string getDebugLogfile();


public:
	GtrApiWrap();
	~GtrApiWrap(void);
	void Initialize(CALLCTX* ctx);

	GT_RESULT SelectServer(string server);						//选大区	订单中大区信息	OK	无法连接					SelectServer		char*
	GT_RESULT SelectArea(string area);							//选小区	订单中小区信息	OK	无法连接					SelectArea		char*
	// null 自动选择线路
	GT_RESULT SelectLineByName(string line);		// 		选线路	Ping值较低	OK	无法连接					SelectLine		void
	// -1 自动选择线路
	GT_RESULT SelectLineByIndex(int line);		// 		选线路	Ping值较低	OK	无法连接					SelectLine		void	
	GT_RESULT Login(string usr,string passwd);	// 		账号密码输入	订单中账号密码信息	OK	账号密码错误	玩家在线		版本错误		Login		char* account, char* pwd
	GT_RESULT IsExistDynMB();									// 		查询动态密保		有	无					IsExistDynMB		void	
	GT_RESULT IsRightClass(int );							// 		查询角色阵营	订单中卖家阵营	是	否					IsRightClass		int	
	GT_RESULT IsExistBackHomeSkill();					// 		查询回城技能		是	否					IsExistBackHomeSkill		void
	GT_RESULT UseBackHomeSkill();							// 		使用回城技能		OK	失败					UseBackHomeSkill		void
	GT_RESULT IsExistBackHomeItem();					// 		查询是否存在回城物品		是	否					
	GT_RESULT UseBackHomeItem();							// 		使用回城物品		OK	失败						
	GT_RESULT QueryRoleLevel(string role ,POUT int *); // 		查询卖家角色等级		OK	失败					QuerySellerLevel		char*, int*
	GT_RESULT SelectRoleByName(string role);				// 		角色选择	订单中的角色名信息	OK	角色名不存在	角色需要修改名字（DNF合服）				SelectRoleByName		char*
	GT_RESULT SelectRoleByIndex(int);					// 		序号选择	订单中的角色序号信息	OK	无法登陆该序号角色					SelectRoleByIndex		int
	GT_RESULT IsExistRoleByName(string role );			// 		查询买家角色名	订单中买家角色名信息	有	无					IsExistBuyerByName		char*
	GT_RESULT AddRoleToFriend(string role);				// 		加买家为好友	订单中买家角色名信息	OK	无该玩家					AddBuyerToFriend		char*		
	GT_RESULT QuerySafeTime(POUT int* );						// 		获取安全时间			安全时间					QuerySafeTime		int*		
	GT_RESULT IsExistNPC(Gt_NPCID );								// 		判定指定NPC是否在附近	NPCID	是	否					IsExistNPC		int	
	GT_RESULT OpenWarehouse(string passwd);						// 		打开仓库	订单中的仓库密码信息	OK	密码错误					OpenWarehouse		char*
	GT_RESULT OpenMailBox(string passwd);						//邮箱  二级密码
	GT_RESULT OpenBank(string passwd);							//银行 二级密码
	GT_RESULT OpenExchange(string passwd); 					//交易所 二级密码	
	GT_RESULT OpenGrocer(string passwd); 					//杂货商 二级密码

	GT_RESULT MoveToByNpcID(Gt_NPCID);							// 		跑地图	NPCID	OK	无法到达					MoveToByNpcID		int NPCID
	GT_RESULT Talk(Gt_NPCID);											// 		与邮箱NPC对话	NPCID	OK	无法对话					Talk		int NPCID
	//查询物品数量 ,  item - 具体的游戏可交易的对象(金币、元宝、金砖。。。)
	GT_RESULT QueryItemsInBag(Gt_GameItemT item,POUT INT64*);				//背包
	GT_RESULT QueryItemsInWarehouse(Gt_GameItemT item,POUT INT64*);	//仓库
	GT_RESULT QueryItemsInBank(Gt_GameItemT item,POUT INT64*);				// 银行
	GT_RESULT QueryItemsInExchange(Gt_GameItemT item,POUT INT64*);		//交易所
	//邮件特例处理
	GT_RESULT IsEnoughItemsInMailbox(Gt_GameItemT item,PINOUT INT64*);		// 邮箱金币是否满足差额
	//获得指定物品数量 
	GT_RESULT WithdrawItemsInWarehouse(Gt_GameItemT item,PINOUT INT64*);	// 		获取仓库金币信息			返回仓库中金币数额	无法获取				QueryGoldsInWarehouse		int64*
	GT_RESULT WithdrawItemsInBank(Gt_GameItemT item,PINOUT INT64*);				// 		获取仓库金币信息			返回仓库中金币数额	无法获取				QueryGoldsInWarehouse		int64*
	GT_RESULT WithdrawItemsInExchange(Gt_GameItemT item,PINOUT INT64*);		// 		获取仓库金币信息			返回仓库中金币数额	无法获取				QueryGoldsInWarehouse		int64*
	GT_RESULT WithdrawItemsInMailbox(Gt_GameItemT item,PINOUT  INT64*);		// 		邮箱金币是否满足差额
	//发送邮件
	GT_RESULT SendMail(string reciever,string title,string content,INT64);	
	//兑换给Npc
	GT_RESULT SellItem(int item,int itemNum);							// 		兑换银票，金砖	金币数额		返回兑换后金币数额	无法获取				SellItem		int64

	//传送 返回GT_TRUE代表成功，GT_FALSE没有失败
	GT_RESULT Transport( int mapid );
	//查询解锁与否 返回GT_TRUE代表解锁，GT_FALSE没有解锁
	GT_RESULT IsUnlocked();
	//查询玩家是否在某某地图 返回GT_TRUE代表是，GT_FALSE否
	GT_RESULT IsInMap( int mapid );
	//返回选择角色画面
	GT_RESULT ReturnToSelectRole(  );
	//使用走路脚本专用(暂时诛仙2专用)
	GT_RESULT MoveTo(int type);
	//判断NPC是否在玩家可点击对话范围之内
	GT_RESULT IsNearBy(Gt_NPCID);
	//获取角色信息 参数1：数据 参数2：长度
	GT_RESULT GetAccountInfo(char**,int* );
	GT_RESULT GetRoleList(vector<string>& roles);

	GT_RESULT Begin();				//开单
	GT_RESULT End();					//结单


	void addChecker(GtrChecker* checker);
};
