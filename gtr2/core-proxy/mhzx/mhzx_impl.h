#pragma once

#ifndef _WIN32_WINNT
#   define _WIN32_WINNT 0x400
#endif

#include "../idl/gtr_api.h"
#include <gtrc.h>
#include "service.h"
#include "general.h"
#include "role.h"
#include "mailbox.h"
#include "warehouse.h"

/*
�λ�����ר��NPC����
*/
enum eZX2NPCType
{
	MHZX_SELF,
	MHZX_NPC_WAREHOUSE,							//�ֿ�
	MHZX_NPC_MAILBOX,							//����
	MHZX_NPC_BANK,								//Ǯׯ
	MHZX_NPC_CONVEY								//����
};

/*
�λ�����ר��item��ö��
*/
enum eZX2ItemType
{
	MHZX_GOLD = GT_ITEM_1,				//���
};

class withdraw_check	:	public ICheck
{
public:
	withdraw_check(Role* role);
	GT_RESULT Do(GT_RESULT ret, int npc);
	void errorCheck();

private:
	Role* _role;
	int _fatel_error;
	void setWithdrawError(int err, int npc);

};

class mhzx_impl : public GameRobotInstance
{
	Role _role;
	WithDrawMethod _exchange;
	Warehouse _warehouse;
	WithDrawMethod _shop;
	MailBox _mailbox;
	GtrApiWrap _wrap;
	AnswerStub _answerStub;

	withdraw_check _withdrawCheck;

public:
	mhzx_impl(void);
	~mhzx_impl(void);

	inline virtual std::string getGameDll(){
		return "RootControl.dll";
	}

	inline virtual std::string getGamePath(){
		return configdata.sGamePath;
	}

	virtual void task_MailPost(gtr::GameTaskResultT& result);
	void auth_validate(int type, std::string secret);

private:
	void validating();
	void doPost(gtr::GameTaskResultT& result);
	void doPostCheck(gtr::GameTaskResultT& result);

	void doBusiness(gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	void moveToShop();
	void moveToWarehouse();
	int roleAtWhichMap();
	void _sendMail(gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);

	void _withdrawFromMailbox(INT64 withdraw);
	void _withdrawFromShop(INT64 withdraw);
	void _withdrawFromExchange(INT64 withdraw, string passwd);
	void _withdrawFromWarehouse(INT64 withdraw, string passwd);

};
