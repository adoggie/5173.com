#ifndef _DNF_ACCOUNTAUDIT_
#define _DNF_ACCOUNTAUDIT_

#include "../idl/gtr_api.h"
#include <gtrc.h>
#include "service.h"
#include "DNFAccountInfo.h"

class Dnf_AccountAudit : public GameRobotInstance
{
public:
	Dnf_AccountAudit(){}
	virtual ~Dnf_AccountAudit(){}

	inline virtual std::string getGameDll(){
		return "client.dll";
	}

	inline virtual std::string getGamePath(){
		return configdata.sGamePath;
	}

	void run(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult);
	virtual void task_AccountAudit(gtr::GameTaskResultT& result);
	virtual char* core_auth_image(Gt_CallContext* ctx,Gt_ImageTypeT imagetype,char* imagedata,int size,int width,int height);

	void AddDNFItemType();
	void AddDNFItemProperty();

private:
	void checkReturnvalueprocess( int returnvalue, gtr::GameTaskResultT& taskresult );
	DNFAccountInfo accountinfo;
};

#endif