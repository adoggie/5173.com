#include "StdAfx.h"
#include "HostService.h"
#include <string>
#include <sstream>
using namespace std;
using namespace client;

HostService HostService::_instance;
extern void showlog(string msg);
#define SHOWLOG(a) ;

HostService::HostService(void)
{
	_started = false;

}

UINT HostService::RunAskerProxy(LPVOID lpUser)
{
	HostService *phost = (HostService*) lpUser;
	phost->RunAsProxy();
	return TRUE;
}

UINT HostService::RunGameHost(LPVOID lpUser)
{
	HostService *phost = (HostService*) lpUser;
	phost->RunAsHost();
	return TRUE;
}

#include <winsock.h>

void HostService::Start()
{
	_LoggorWrap.UnInitialize();
	if(! _LoggorWrap.Initialize("ILogServer.Proxy") )
	{
		showlog("Warning: log server connect failed");
		_LoggorWrap.UnInitialize();
	}
	else
	{
		showlog("Log: log server connected");
	}

#if 0
	_ServerWrap.UnInitialize();
	_QuestionSvrWrap.UnInitialize();
	if(! _ServerWrap.Initialize("IGtrServer.Proxy") )
	{
		showlog("Warning: GTR server connecte failed");
		_ServerWrap.UnInitialize();
	}
	if(! _QuestionSvrWrap.Initialize("IQeustionServer.Proxy") )
	{
		showlog("Warning: question server connecte failed");
		_QuestionSvrWrap.UnInitialize();
	}
#endif

	CWinThread* p = AfxBeginThread(RunGameHost,this);
	WaitForSingleObject(p->m_hThread, 0);

#if 0
	AfxBeginThread(RunAskerProxy, this);
#endif
}

HostService::~HostService(void)
{
	_LoggorWrap.UnInitialize();
	_ServerWrap.UnInitialize();
	_QuestionSvrWrap.UnInitialize();
}

void HostService::RunAsProxy()
{

	stringstream log;

	Ice::CommunicatorPtr _ic;

	try
	{
		int argc;	
		char* argv[]={"this","--Ice.Config=config.client"};
		argc = 2;
		_ic = Ice::initialize(argc, argv);
		//Ice::ObjectAdapterPtr adapter = _ic->createObjectAdapter("HostAskerAdapter");
		Ice::ObjectAdapterPtr adapter = _ic->createObjectAdapterWithEndpoints("HostAskerAdapter", "default -p 9999" );
		adapter->add( _host , _ic->stringToIdentity("QuestionAskerEndPoint"));
		adapter->activate();
		showlog("Log: AskerProxy Start OK");
		_QuestionSvrWrap._askerPrx = gtr::IQuestionAskerPrx::uncheckedCast(
			adapter->createProxy(_ic->stringToIdentity("AnswerEndpoint"))
			);
		_ic->waitForShutdown();
	}
	catch (const Ice::Exception& e) 
	{  
		log << e << endl;  //status = 1; 
	} 
	catch (const char* msg) 
	{ 
		log << msg << endl;  //status = 1; 
	} 

	if (_ic) 
	{  
		try 
		{   _ic->destroy();  
		} 
		catch (const Ice::Exception& e) 
		{   
			cerr << e << endl;  // status = 1;  
		} 
	}


}

int  HostService::RunAsHost()
{ 
	stringstream log;
	int status = 0; 
	Ice::CommunicatorPtr ic; 
	try 
	{  
		int argc = 0;
		char** argv = NULL;
		ic = Ice::initialize(argc, argv); 
		Ice::ObjectAdapterPtr adapter   = ic->createObjectAdapterWithEndpoints(   "GameHostAdapter", "default -p 10001");  
		_host = new gtr::IGameHostI;  
		adapter->add(_host, ic->stringToIdentity("GameHost"));  
		adapter->activate();  
		showlog("Log: Host Start OK");
		_started = true;
		ic->waitForShutdown(); 
	} 
	catch (const Ice::Exception& e) 
	{  
		log << e << endl;  status = 1; 
	} 
	catch (const char* msg) 
	{ 
		log << msg << endl;  status = 1; 
	} 

	if (ic) 
	{  
		try 
		{   ic->destroy();  
		} 
		catch (const Ice::Exception& e) 
		{   
			cerr << e << endl;   status = 1;  
		} 
	}

	return status;
}

IceWrap::IceWrap(void)
{
}

IceWrap::~IceWrap(void)
{

}

bool  IceWrap::Initialize(const char* proxyName)
{
	try 
	{  
		int argc;	
		char* argv[]={"this","--Ice.Config=config.client"};
		argc = 2;
		_ic = Ice::initialize(argc, argv); 
		
		//Ice::PropertiesPtr properties = _ic->getProperties();
		//properties->load("config.client");

		Ice::ObjectPrx object = _ic->propertyToProxy(proxyName);

		//Ice::ObjectPrx object = _ic->stringToProxy("ILogServer:tcp -h 192.168.133.55 -p 12360");  
		std::string str = _ic->proxyToString(object) ;

		if(!proxyCast(object))
			return false;

		return true;

	} 
	catch (const Ice::Exception& e) 
	{  
		cerr << e << endl; 
	} 
	catch (const char* msg) 
	{ 
		cerr << msg << endl; 
	} 

	return false;
}

void IceWrap::UnInitialize()
{
	if (_ic) 
	{  
		try 
		{   
			_ic->destroy();  
		} 
		catch (const Ice::Exception& e) 
		{   
			cerr << e << endl;
		} 
	}
}

LoggorWrap::LoggorWrap(void)
{
}

LoggorWrap::~LoggorWrap(void)
{

}

bool LoggorWrap::proxyCast(Ice::ObjectPrx object)
{
	try
	{
		_logger = ILogServerPrx::checkedCast(object);
		if(!_logger)
			return false;
		return true;
	}
	catch (const Ice::Exception& e) 
	{  
		cerr << e << endl; 
	} 
	catch (const char* msg) 
	{ 
		cerr << msg << endl; 
	} 

	return false;
}

void LoggorWrap::gameMsg(const ::gtr::GameIdentifyT& gameId, ::Ice::Int timetick, const ::gtr::LogMessageT& msg)
{
	try 
	{   
		if(_logger)
			_logger->gameMsg(gameId, timetick, msg);
		else
			SHOWLOG("logger server not exist");
		
	} 
	catch (const Ice::Exception& e) 
	{  
		cerr << e << endl; 
	} 
	catch (const char* msg) 
	{ 
		cerr << msg << endl; 
	} 
}

void LoggorWrap::gameImage(const ::gtr::GameIdentifyT& gameId, ::Ice::Int timetick, const ::std::string& opName, const ::gtr::ImageDataT& image)
{
	try 
	{   
		if(_logger)
			_logger->gameImage(gameId, timetick, opName, image);
		else
			SHOWLOG("logger server not exist");
	} 
	catch (const Ice::Exception& e) 
	{  
		cerr << e << endl; 
	} 
	catch (const char* msg) 
	{ 
		cerr << msg << endl; 
	} 
}

void LoggorWrap::heartbeat(const ::std::string& senderType,const ::std::string& senderId)
{
	try 
	{   
		if(_logger)
			_logger->heartbeat(senderType, senderId);
		else
			SHOWLOG("logger server not exist");
	} 
	catch (const Ice::Exception& e) 
	{  
		cerr << e << endl; 
	} 
	catch (const char* msg) 
	{ 
		cerr << msg << endl; 
	} 
}

ServerWrap::ServerWrap(void)
{

}
ServerWrap::~ServerWrap(void)
{

}

::gtr::GameTaskletT ServerWrap::getTask(const ::gtr::GameRobotInfoT& robot)
{
	try
	{
		if(_server)
			return _server->getTask(robot);
		else
			SHOWLOG("gtr server not exist");
	}
	catch (const Ice::Exception& e) 
	{  
		const TCHAR *s = e.what();
		cerr << e << endl; 
	} 
	catch (const char* msg) 
	{ 
		cerr << msg << endl; 
	} 
	GameTaskletT tasklet;
	return tasklet;
}

void ServerWrap::completeTask(const ::gtr::GameTaskResultT& result)
{
	try
	{
		if(_server)
			_server->completeTask(result);
		else
			SHOWLOG("gtr server not exist");
	}
	catch (const Ice::Exception& e) 
	{  
		cerr << e << endl; 
	} 
	catch (const char* msg) 
	{ 
		cerr << msg << endl; 
	} 
}

QuestionSvrWrap::QuestionSvrWrap(void)
{

}

QuestionSvrWrap::~QuestionSvrWrap(void)
{

}

bool QuestionSvrWrap::proxyCast(Ice::ObjectPrx object)
{
	try
	{
		_questionSvr = IQuestionServerPrx::checkedCast(object);
		if(!_questionSvr)
			return false;
		return true;
	}
	catch (const Ice::Exception& e) 
	{  
		cerr << e << endl; 
	} 
	catch (const char* msg) 
	{ 
		cerr << msg << endl; 
	} 

	return false;
}

bool ServerWrap::proxyCast(Ice::ObjectPrx object)
{
	try
	{
		_server = IGtrServerPrx::checkedCast(object);
		if(!_server)
			return false;
		return true;
	}
	catch (const Ice::Exception& e) 
	{  
		cerr << e << endl; 
	} 
	catch (const char* msg) 
	{ 
		cerr << msg << endl; 
	} 
	return false;
}

void QuestionSvrWrap::answer(const ::std::string& no, const ::gtr::QuestionContentT& question)
{
	try
	{
		if(_questionSvr)
			_questionSvr->answer(_askerPrx, no, question);
		else
			SHOWLOG("question server not exist");
	}
	catch (const Ice::Exception& e) 
	{  
		cerr << e << endl; 
	} 
	catch (const char* msg) 
	{ 
		cerr << msg << endl; 
	} 
}

void QuestionSvrWrap::verifyAnswer(const ::std::string& no,int type,bool succ)
{
	try
	{
		if(_questionSvr)
			_questionSvr->verifyAnswer(no, type, succ);
		else
			SHOWLOG("question server not exist");
	}
	catch (const Ice::Exception& e) 
	{  
		cerr << e << endl; 
	} 
	catch (const char* msg) 
	{ 
		cerr << msg << endl; 
	} 
}

