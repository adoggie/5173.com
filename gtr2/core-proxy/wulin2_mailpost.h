#ifndef _WULIN2_MAILPOST_
#define _WULIN2_MAILPOST_

#ifndef _WIN32_WINNT
#   define _WIN32_WINNT 0x400
#endif

#include "../idl/gtr_api.h"
#include <gtrc.h>
#include "service.h"

/*
武林专用NPC类型
*/
enum eNPCType
{
	NPC_MAILBOX,							//邮箱
	NPC_WAREHOUSE,							//仓库
	NPC_BANK,								//钱庄
	NPC_GUILDWAREHOUSE,						//帮派仓库
	NPC_GROCER,								//杂货
	NPC_CONVEY								//传送
};

/*
武林专用item的枚举
*/
enum eWulin2ItemType
{
	WULIN2_GOLD = GT_ITEM_1,				//金币
	WULIN2_GOLDINGOT = GT_ITEM_2,			//金条
	WULIN2_GOLDBULLION,						//金块
	WULIN2_GOLDBRICK						//金砖
};

enum eMapId
{
	MAP_QIXIAZHEN							//七侠镇
};

struct ItemData 
{
	int itemtype;
	INT64 itemprice;
	INT64 itemnum;
};

class Wulin2_Mailpost : public GameRobotInstance
{
public:
	Wulin2_Mailpost()
	{
		goldingot.itemtype = WULIN2_GOLDINGOT;
		goldbullion.itemtype = WULIN2_GOLDBULLION;
		goldbrick.itemtype = WULIN2_GOLDBRICK;
		goldingot.itemprice = 2000 * 10000;
		goldbullion.itemprice = 10000 * 10000;
		goldbrick.itemprice = 5000 * 10000;
		goldingot.itemnum = 0;
		goldbullion.itemnum = 0;
		goldbrick.itemnum = 0;

		warehouseRvalue = GT_UNKNOWN;
		bankRvalue = GT_UNKNOWN;
	}
	virtual ~Wulin2_Mailpost(){}

	inline virtual std::string getGameDll(){
		return "game-core.dll";
	}

	inline virtual std::string getGamePath(){
		return configdata.sGamePath;
	}

	inline void SetTimeOut( int timeout ){ _gamectx.timeout = timeout; }
	inline int	GetTimeOut(){ return _gamectx.timeout; }

	void run(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	virtual void task_MailPost(gtr::GameTaskResultT& result);

private:
	void sellItemprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	void sendMailprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	void backhomeSkillprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	void backhomeItemprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);

	void checkReturnvalueprocess( int returnvalue, gtr::GameTaskResultT& taskresult );

	inline INT64 calculate_allinbag()
	{
		return (baggold + goldingot.itemprice * goldingot.itemnum + goldbullion.itemnum * goldbullion.itemprice + goldbrick.itemprice * goldbrick.itemnum);
	}

	inline INT64 calculate_buyermoney()
	{
		return (_tasklet.post.buyerMoney);
	}

	ItemData	goldingot;
	ItemData	goldbullion;
	ItemData	goldbrick;
	INT64		baggold;

	int			warehouseRvalue;
	int			selectroleRvalue;
	std::string realSecondPwd;
	int			bankRvalue;
};

#endif