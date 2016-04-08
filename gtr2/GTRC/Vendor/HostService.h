#pragma once

#include <gtrcI.h>
#include <ice\ice.h>
using namespace gtr;

namespace client
{
	class HostService;
	class IceWrap;
	class LoggorWrap;
	class ServerWrap;
	class QuestionSvrWrap;
};

class client::IceWrap
{
protected:
	Ice::CommunicatorPtr _ic; 

public:
	IceWrap();
	~IceWrap();
	bool Initialize(const char* proxyName);
	void UnInitialize();
	virtual bool proxyCast(Ice::ObjectPrx object) = 0;

};

class client::LoggorWrap
	:public client::IceWrap
{
	gtr::ILogServerPrx _logger;
public:
	LoggorWrap(void);
	~LoggorWrap(void);
	virtual bool proxyCast(Ice::ObjectPrx object);
	void gameMsg(const ::gtr::GameIdentifyT& gameId, ::Ice::Int timetick, const ::gtr::LogMessageT& msg);
	void gameImage(const ::gtr::GameIdentifyT& gameId, ::Ice::Int timetick, const ::std::string& opName, const ::gtr::ImageDataT& image);
	void heartbeat(const ::std::string&,const ::std::string&);
};

class client::ServerWrap
	:public client::IceWrap
{
	gtr::IGtrServerPrx _server;

public:
	ServerWrap(void);
	~ServerWrap(void);
	virtual bool proxyCast(Ice::ObjectPrx object);
	::gtr::GameTaskletT getTask(const ::gtr::GameRobotInfoT& robot);
	void completeTask(const ::gtr::GameTaskResultT& result);

};

class client::QuestionSvrWrap
	:public client::IceWrap
{
	gtr::IQuestionServerPrx _questionSvr;
public:
	QuestionSvrWrap(void);
	~QuestionSvrWrap(void);
	virtual bool proxyCast(Ice::ObjectPrx object);
	void answer(const ::std::string& no, const ::gtr::QuestionContentT& question);
	void verifyAnswer(const ::std::string& no,int type,bool succ);
	::gtr::IQuestionAskerPrx _askerPrx;

};

class client::HostService
{
	gtr::IGameHostI* _host;
	bool _started;

private:
	HostService(void);
	~HostService(void);
	int  RunAsHost();
	void RunAsProxy();
	static UINT RunGameHost(LPVOID lpUser);
	static UINT RunAskerProxy(LPVOID lpUser);

public:
	LoggorWrap _LoggorWrap;
	ServerWrap _ServerWrap;
	QuestionSvrWrap _QuestionSvrWrap;
	static HostService _instance;

	void Start();
	bool isStarted(){return _started;}
};

