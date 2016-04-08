#pragma once

#include "vendor.h"
//#include "task.h"

#include <map>
using namespace std;

namespace client
{
	class Dispatcher;
}

class serverCfg
{
public:
	string id;
	string ip;
	int port;
};

class GtMessageBase;
class client::Dispatcher
{
	static const int NO_FEEDBACK = 0;

	map<string, client::Vendor*> _vendors;
	map<int, string> _mapsid;

	map<string, GtMessageBase*> _feedback;
	serverCfg _server;
	bool _bBusy;
	bool _isdianxin;

	void Scan();
	client::Vendor* AddVendor(int nId, const _VendorInfo& vi);
	void setFeedback(string no, GtMessageBase* pFD);

	Dispatcher(void);
	Dispatcher(const Dispatcher& disp);
	~Dispatcher(void);
	static Dispatcher _dispatcher;
	static client::Vendor* _vendor;

	gtr::GameRobotInfoT getRobot();
	void notifySupportedGames();
	void requestTask();
	CRITICAL_SECTION _cs;

public:
	bool isStop();
	static Dispatcher& Instance(){return _dispatcher;}
	static client::Vendor* findVendor(string gameId);
	const map<string, client::Vendor*>& getVendors() const { return _vendors;}

	void Initialize();
	void UnInitialize();
	int RunAsClient();
	int RunAsClientForIce();
	void Abort();
	
	void completeTask();

	GtMessageBase* SendToServer(GtMessageBase* pMsg, string taskNo, int nFeedBack = NO_FEEDBACK);

	Vendor* taskAssign(int gameId, GtMessageBase *pmsg);
	Vendor* taskAssign(gtr::GameTaskletT task);
	client::Vendor* find(string gameId);
	string getGameIdArr();
};

#define DISPATCHER Dispatcher::Instance()

