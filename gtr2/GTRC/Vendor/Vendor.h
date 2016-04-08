#pragma once

#include <time.h>
#include <string>
#include <vector>
using namespace std;

#include "gtrc.h"

namespace client
{
	class Vendor;
}

struct _VendorInfo
{
	string gameID;
	string gameName;
	string robotPath;

};

class GtMessageBase;
class client::Vendor
{
	int _status;
	bool _enable;
	string _userName;
	string _answer;
	bool _wait_answer;

	time_t _start;

	_VendorInfo _vendorInfo;
	::gtr::GameTaskletT _tasklet;

public:
	void gtrcLog(std::string log);
	static const int Idle = 0;
	static const int Busy = 1;
	static const int Timeout = 2;

	Vendor(const _VendorInfo &info);
	~Vendor(void);

	string getTaskNo(){ return _tasklet.no;}
	int getTaskId();

	string getStatusHint();
	string getGameId(){return _vendorInfo.gameID;}
	string getGameName(){return _vendorInfo.gameName;}
	string getGamePath(){return _vendorInfo.robotPath;}

	void assign(GtMessageBase *pmsg);
	void assign(::gtr::GameTaskletT tasklet);

	bool isIdle();
	bool timeOut();
	bool isEnable(){return _enable;}
	void Disable(){_enable = false;}
	void Enable(){_enable = true;}

	void startRobot();
/*
below is used for RPC interface 
*/
public:
	void makeLog(string strLog);
	void makeScreenShot(string strName, void* imgData);

	string getAnswer();
	void setAnswer(string answer);
	void setAnswerWait(){_wait_answer = true;}
	void verifyAnswer(int type,bool succ);

	::gtr::GameTaskletT getTask();
	void setFinished(bool sock);
	void setResultFeedback(int nResult,string aux="");
	void heatbeat();
	string auth(int type, const vector<unsigned char>& imgData);
	string auth(string authkey);
};
