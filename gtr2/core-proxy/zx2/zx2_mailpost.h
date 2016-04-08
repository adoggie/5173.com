#ifndef _ZX2_MAILPOST_
#define _ZX2_MAILPOST_

#ifndef _WIN32_WINNT
#   define _WIN32_WINNT 0x400
#endif

#include "../idl/gtr_api.h"
#include <gtrc.h>
#include "service.h"
#include "general.h"

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

class ZX2_Mailpost : public GameRobotInstance
{
public:
	ZX2_Mailpost(){ restarttimes = 3; }
	virtual ~ZX2_Mailpost(){}

	inline virtual std::string getGameDll(){
		return "ZHX2Services.dll";
	}

	inline virtual std::string getGamePath(){
		return configdata.sGamePath;
	}

	inline void SetTimeOut( int timeout ){ _gamectx.timeout = timeout; }
	inline int	GetTimeOut(){ return _gamectx.timeout; }

	void run(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	virtual void task_MailPost(gtr::GameTaskResultT& result);

	int Talk(Gt_NPCID,CALLCTX*);	
	int UseBackHomeSkill(CALLCTX*);

private:
	bool task_process(gtr::GameTaskResultT& result);

	/*
	使用回城
	*/
	bool backHomeprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	/*
	超时
	*/
	bool timeoutprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	/*
	检查发邮件
	*/
	bool checkmailpostprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	/*
	仓库到邮箱
	*/
	bool warehouse2mailboxprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	/*
	回城到邮箱
	*/
	bool bh2mailboxprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	/*
	回城到邮箱并且取邮箱的钱
	*/
	bool bh2mailboxprocess2(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	/*
	回城到仓库
	*/
	bool bh2warehouseprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	/*
	发邮件
	*/
	bool sendmailprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	/*
	邮箱NPC操作流程
	*/
	bool mailboxnpcprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult,eZX2NPCType npctype,bool safelock,bool withdrawgold);

	void checkReturnvalueprocess( int returnvalue, gtr::GameTaskResultT& taskresult );

	INT64		baggold;
	int			restarttimes;
	bool		withdrawsucc;
	int			warehouseRvalue;

	time_t		_tmStart;

	bool isTimeout();
};

#endif