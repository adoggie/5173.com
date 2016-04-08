#pragma once

#ifndef _WIN32_WINNT
#   define _WIN32_WINNT 0x400
#endif

#include <vector>
#include "gtr_api.h"
#include "gtrapiwrap.h"

using namespace std;

static const int MASK_ISEXIST = 0x01;
static const int MASK_MOVETO = 0x02;
static const int MASK_TALK = 0x04;
static const int MASK_OPEN = 0x08;

extern swlib::swLogger& appLogger();

class robot_error
{
public:
	string message;	// text information
	int code;		// error code defined for business logical 
	int ret;		// return value of core-dll

	robot_error(int ret, int err, string msg)
	{
		ret = ret;
		code = err;
		message = msg;

	}
	robot_error(int err, string msg)
	{
		ret = -1;
		code = err;
		message = msg;

	}
};
robot_error  make_error( int returnvalue);

enum eNPCType
{
	NPC_MAILBOX,							//” œ‰
	NPC_WAREHOUSE,							//≤÷ø‚
	NPC_BANK,								//«Æ◊Ø
	NPC_GUILDWAREHOUSE,						//∞Ô≈…≤÷ø‚
	NPC_GROCER,								//‘”ªı
	NPC_CONVEY								//¥´ÀÕ
};

struct ItemData 
{
	int type;
	INT64 price;
	INT64 num;

	ItemData(){type=0; price=0; num=0;}
};

class ICheck
{
public:
	virtual GT_RESULT Do(GT_RESULT ret, int npc) = 0;
};

enum
{
	AUTH_UNKNOWN,
	AUTH_NORMAL,
	AUTH_TIMEOUT,
	AUTH_ABORT,
};

class AnswerStub	:	public GtrChecker
{
	struct AnswerError
	{
		int code;
		int timeouts;
		string name;
		string message;
		AnswerError(){ code = 0; timeouts = 0x7FFFFFF; name = "Œ¥÷™µƒ¥Ã‚¿‡–Õ";}
	} ;
	map<int, AnswerError> _errors;
	void checkException(int type);
	void setError(int type, int ret);

public:
	AnswerStub();
	void Do();
	void doCheck(int type, string secret);
	void setMask(int type, int mask);

};

class NPC
{
protected:
	int _maskAction;
	string _password;
	eNPCType _npcType;
	GtrApiWrap* _wrap;

public:
	NPC(GtrApiWrap* wrap, int npcType);
	bool Create();
	void WaitUnLocked();
	void setActionMask(int mask);

private:
	GT_RESULT Open();						
	GT_RESULT MoveToNpc();	
	GT_RESULT IsExistNPC();
	GT_RESULT Talk();
};

class WithDrawMethod	:	public NPC
{
public:
	static const int WD_WAREHOUSE = 1;
	static const int WD_BANK = 2;
	static const int WD_EXCHANGE = 3;
	static const int WD_MAILBOX = 4;

	int _type;
	string _name;

	map<int, ItemData> _items;

	WithDrawMethod(GtrApiWrap* wrap, int type);
	void Do(INT64 delta);
	void Collect(ItemData &ingot, ItemData &bullion, ItemData &brick, INT64 &gold);

public:
	GT_RESULT WithdrawItems(Gt_GameItemT item, ICheck *check=NULL);
	GT_RESULT QueryItems(Gt_GameItemT item);
	INT64 getNumber(Gt_GameItemT item);
	void setName(string name);
	void setWithdrawNum(INT64 num);
};

