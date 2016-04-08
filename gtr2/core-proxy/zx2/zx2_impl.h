#pragma once


#ifndef _WIN32_WINNT
#   define _WIN32_WINNT 0x400
#endif

#include "../idl/gtr_api.h"
#include <gtrc.h>
#include "service.h"
#include "withdraw.h"

/*
����2ר��NPC����
*/
enum eZX2NPCType
{
	ZX2_SELF,
	ZX2_NPC_WAREHOUSE,							//�ֿ�
	ZX2_NPC_MAILBOX,							//����
	ZX2_NPC_BANK,								//Ǯׯ
	ZX2_NPC_CONVEY								//����
};

/*
����2ר��item��ö��
*/
enum eZX2ItemType
{
	ZX2_GOLD = GT_ITEM_1,				//���
};

enum ScriptType
{
	BH2WAREHOUSE,					//�سǵ��ֿ�
	BH2MAILBOX,						//�سǵ�����
	WAREHOUSE2MAILBOX				//�ֿ⵽����
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
