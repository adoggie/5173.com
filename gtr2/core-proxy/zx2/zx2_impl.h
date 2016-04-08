#pragma once


#ifndef _WIN32_WINNT
#   define _WIN32_WINNT 0x400
#endif

#include "../idl/gtr_api.h"
#include <gtrc.h>
#include "service.h"
#include "withdraw.h"

/*
诛仙2专用NPC类型
*/
enum eZX2NPCType
{
	ZX2_SELF,
	ZX2_NPC_WAREHOUSE,							//仓库
	ZX2_NPC_MAILBOX,							//邮箱
	ZX2_NPC_BANK,								//钱庄
	ZX2_NPC_CONVEY								//传送
};

/*
诛仙2专用item的枚举
*/
enum eZX2ItemType
{
	ZX2_GOLD = GT_ITEM_1,				//金币
};

enum ScriptType
{
	BH2WAREHOUSE,					//回城到仓库
	BH2MAILBOX,						//回城到邮箱
	WAREHOUSE2MAILBOX				//仓库到邮箱
};

struct ZX2ItemData 
{
	int itemtype;
	INT64 itemprice;
	INT64 itemnum;
};

class zx2_impl : public GameRobotInstance
{
	INT64 baggold;

public:
	zx2_impl(void);
	~zx2_impl(void);

	inline virtual std::string getGameDll(){
		return "BLLServicesStub.dll";
	}

	inline virtual std::string getGamePath(){
		return configdata.sGamePath;
	}

	inline void SetTimeOut( int timeout ){ _gamectx.timeout = timeout; }
	inline int	GetTimeOut(){ return _gamectx.timeout; }

	virtual void task_MailPost(gtr::GameTaskResultT& result);

private:
	void validating();
	void login(CALLCTX* call,gtr::GameTaskletT& tasklet);
	void doBusiness(CALLCTX* call,gtr::GameTaskletT& tasklet);

	robot_error  make_error( int returnvalue);
	bool backHomeprocess(CALLCTX* call);

	void _sendMail(CALLCTX *call,gtr::GameTaskletT& tasklet);
	bool _withdraw_mailbox(CALLCTX *call,gtr::GameTaskletT& tasklet);
	void _withdraw(CALLCTX *call,gtr::GameTaskletT& tasklet);

};
