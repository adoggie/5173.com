#ifndef _JXSJ_MAILPOST_
#define _JXSJ_MAILPOST_

#include "../idl/gtr_api.h"
#include <gtrc.h>
#include "service.h"

/*
��������ר��NPC����
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
	GT_NoGoods                = 0xF0001,	// û����Ʒ(��Ҫʹ����Ʒʱ)
	GT_NpcNotFind             = 0xF0002,	// �Ҳ���npc
	GT_OpenNpcFail            = 0xF0003,	// ��ncpʧ��
	GT_NotEnoughMoney         = 0xF0004,	// ��������
	GT_PlayerOffline          = 0xF0005,	// ��Ҳ�����(�Է������߼Ӳ��˺���);
	GT_AddFriendTimeout       = 0xF0006,	// �Ӻ��ѳ�ʱ
	GT_GetMapNameFail         = 0xF0007,	// ��ȡ��ͼ����ʧ��
	GT_BankFailed			  = 0xF0008,	// ǮׯȡǮ����
	GT_MBOnLimit			  = 0xF0009,	// ��������ﵽ����
	GT_AddFriendOffline       = 0xF000A,    // �Ӻ��Ѷ���
	GT_GameUncontrollable     = 0xFF000		// ��Ϸ���ɿ�(sendmessage��ʱ,����game����,Ӧ������Ϸ)
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