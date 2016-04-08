#ifndef _JXSJ_MAILPOST_
#define _JXSJ_MAILPOST_

#include "../idl/gtr_api.h"
#include <gtrc.h>
#include "service.h"

/*
剑侠世界专用NPC类型
*/
enum eJXSJNPCType
{
	JXSJ_NPC_WAREHOUSE = 1
};

enum eJXSJItemType
{
	JXSJ_ITEM_GOLD = 0
};

enum eJXSJErrorMessage
{
	GT_NoGoods                = 0xF0001,	// 没有物品(需要使用物品时)
	GT_NpcNotFind             = 0xF0002,	// 找不到npc
	GT_OpenNpcFail            = 0xF0003,	// 打开ncp失败
	GT_NotEnoughMoney         = 0xF0004,	// 银两不够
	GT_PlayerOffline          = 0xF0005,	// 玩家不在线(对方不在线加不了好友);
	GT_AddFriendTimeout       = 0xF0006,	// 加好友超时
	GT_GetMapNameFail         = 0xF0007,	// 获取地图名称失败
	GT_BankFailed			  = 0xF0008,	// 钱庄取钱上限
	GT_MBOnLimit			  = 0xF0009,	// 答题次数达到上限
	GT_AddFriendOffline       = 0xF000A,    // 加好友断线
	GT_GameUncontrollable     = 0xFF000		// 游戏不可控(sendmessage超时,可能game挂了,应重启游戏)
};

class JXSJ_Mailpost : public GameRobotInstance
{
public:
	JXSJ_Mailpost(){ specialvalue = 0; }
	virtual ~JXSJ_Mailpost(){}

	inline virtual std::string getGameDll(){
		return "JXWorldModule.dll";
	}

	inline virtual std::string getGamePath(){
		return configdata.sGamePath;
	}

	virtual void task_MailPost(gtr::GameTaskResultT& result);
	virtual char* core_auth_image(Gt_CallContext* ctx,Gt_ImageTypeT imagetype,char* imagedata,int size,int width,int height);

	void run(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	void sendMailprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	void checksendMailprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	void restartprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);

	bool loginprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
private:
	void checkReturnvalueprocess( int returnvalue, gtr::GameTaskResultT& taskresult );
	INT64 getRoleMaximumGold( int level );
	INT64 baggold;
	INT64 sendmailgold;
	int specialvalue;
};
#endif