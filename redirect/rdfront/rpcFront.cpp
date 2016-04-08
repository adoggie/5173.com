
#include "rpcFront.h"
#include "rdfront.h"

rd::CallResultT IRdFrontServant::prepare(const ::rd::RdWorkSheetT& sheet,
											 ::Ice::Int timeout,
											 const Ice::Current& current)
{
	rd::CallResultT r;
	r.succ = true;
	RdFront::instance()->prepareWorkSheet(sheet,timeout);
	return r;
}

void IRdFrontServant::end(const Ice::Current& current){
	RdFront::instance()->endWorkSheet();
}


IRdFrontServant* IRdFrontServant::instance(){
	static IRdFrontServant* handle = NULL;
	if(!handle){
		handle = new IRdFrontServant;
	}
	return handle;
}
