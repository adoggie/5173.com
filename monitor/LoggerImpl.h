#ifndef _LOGGERIMPL_H_
#define _LOGGERIMPL_H_

#include <gtrc.h>
#include <Ice/Ice.h>
class LoggerImpl : public gtr::ILogServer {
public:
	LoggerImpl();
	~LoggerImpl();
	virtual void gameMsg(const ::gtr::GameIdentifyT&, ::Ice::Int,
		const ::gtr::LogMessageT&, const ::Ice::Current& = ::Ice::Current());

	virtual void gameImage(const ::gtr::GameIdentifyT&, ::Ice::Int,
		const ::std::string&, const ::gtr::ImageDataT&,
		const ::Ice::Current& = ::Ice::Current());

	virtual ::Ice::Int getType(const ::Ice::Current& = ::Ice::Current());


	virtual ::gtr::ServiceIdentifyT getId(const ::Ice::Current& = ::Ice::Current());


	virtual ::Ice::Int getTimestamp(const ::Ice::Current& = ::Ice::Current());

	virtual void shutdown(const ::Ice::Current& = ::Ice::Current());

	virtual void heartbeat(const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current());
};

/*
class LogServerI : public Ice::Application {
public:

	virtual int run(int, char*[]);
};
*/

#endif
