#ifndef _RPC_FRONT_H
#define _RPC_FRONT_H

#include <redirect.h>


class IRdFrontServant : public rd::IRdFront{
public:
	rd::CallResultT prepare(const ::rd::RdWorkSheetT&,::Ice::Int,const Ice::Current&);
	void end(const Ice::Current&);
	static IRdFrontServant* instance();
private:

	
};


#endif