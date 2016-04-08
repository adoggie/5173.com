#ifndef _MHZX_MAILPOST_
#define _MHZX_MAILPOST_

#include "../idl/gtr_api.h"
#include <gtrc.h>
#include "service.h"

/*
梦幻诛仙专用NPC类型
*/
enum eMHZXNPCType
{
};

/*
武林专用item的枚举
*/
enum eWulin2ItemType
{
};

enum eMapId
{
	MAP_QIXIAZHEN							//七侠镇
};

class MHZX_Mailpost : public GameRobotInstance
{
public:
	MHZX_Mailpost(){}
	virtual ~MHZX_Mailpost(){}

	inline virtual std::string getGameDll(){
		return "RootControl.dll";
	}

	inline virtual std::string getGamePath(){
		return configdata.sGamePath;
	}

	virtual void task_MailPost(gtr::GameTaskResultT& result);
	void run(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
private:
	void checkReturnvalueprocess( int returnvalue, gtr::GameTaskResultT& taskresult );
};

#endif