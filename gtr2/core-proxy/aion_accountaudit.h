#ifndef _AION_ACCOUNTAUDIT_
#define _AION_ACCOUNTAUDIT_

#include "../idl/gtr_api.h"
#include <gtrc.h>
#include "service.h"
#include "AionAccountInfo.h"

enum eAionNpcType
{
	AION_NPC_MAILBOX  =  1,	//邮箱NPC
	AION_NPC_WAREHOUSE,		//仓库NPC
	AION_NPC_EXCHANGE,		//交易所NPC
	AION_NPC_TRANSPORT,		//传送NPC
	AION_NPC_FLY,			//飞行NPC
	AION_SELF				//角色本身
};

class Aion_AccountAudit : public GameRobotInstance
{
public:
	Aion_AccountAudit(){}
	virtual ~Aion_AccountAudit(){}

	inline virtual std::string getGameDll(){
		return "aionEngine.dll";
	}

	inline virtual std::string getGamePath(){
		return configdata.sGamePath;
	}

	void run(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	virtual void task_AccountAudit(gtr::GameTaskResultT& result);

	bool backhomeSkillprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	bool backhomeItemprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);

	void AddAionItemType();
	void AddAionItemProperty();

private:
	void checkReturnvalueprocess( int returnvalue, gtr::GameTaskResultT& taskresult );
	AionAccountInfo accountinfo;
};

#endif