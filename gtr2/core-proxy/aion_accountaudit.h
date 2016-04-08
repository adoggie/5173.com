#ifndef _AION_ACCOUNTAUDIT_
#define _AION_ACCOUNTAUDIT_

#include "../idl/gtr_api.h"
#include <gtrc.h>
#include "service.h"
#include "AionAccountInfo.h"

enum eAionNpcType
{
	AION_NPC_MAILBOX  =  1,	//����NPC
	AION_NPC_WAREHOUSE,		//�ֿ�NPC
	AION_NPC_EXCHANGE,		//������NPC
	AION_NPC_TRANSPORT,		//����NPC
	AION_NPC_FLY,			//����NPC
	AION_SELF				//��ɫ����
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