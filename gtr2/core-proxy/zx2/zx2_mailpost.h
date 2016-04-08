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
	ʹ�ûس�
	*/
	bool backHomeprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	/*
	��ʱ
	*/
	bool timeoutprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	/*
	��鷢�ʼ�
	*/
	bool checkmailpostprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	/*
	�ֿ⵽����
	*/
	bool warehouse2mailboxprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	/*
	�سǵ�����
	*/
	bool bh2mailboxprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	/*
	�سǵ����䲢��ȡ�����Ǯ
	*/
	bool bh2mailboxprocess2(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	/*
	�سǵ��ֿ�
	*/
	bool bh2warehouseprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	/*
	���ʼ�
	*/
	bool sendmailprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	/*
	����NPC��������
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