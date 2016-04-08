
#include <gtrcI.h>
#include <ice\ice.h>
#include <string>
using namespace std;
#include "vendor.h"
#include "dispatcher.h"
#include "HostService.h"
using namespace client;

#include <time.h>
#include "messageManager.h"

#define gLoggorWrap HostService::_instance._LoggorWrap
#define gServerWrap HostService::_instance._ServerWrap

extern void showlog(string msg);

#define GTRICE 0

::Ice::Int
gtr::IServiceI::getType(const Ice::Current& current)
{
    return 0;
}

::gtr::ServiceIdentifyT
gtr::IServiceI::getId(const Ice::Current& current)
{
    return ::gtr::ServiceIdentifyT();
}

::Ice::Int
gtr::IServiceI::getTimestamp(const Ice::Current& current)
{
    return 0;
}

void
gtr::IServiceI::shutdown(const Ice::Current& current)
{
}

void
gtr::IServiceI::heartbeat(const ::std::string& senderType,
						  const ::std::string&  senderId,
						  const Ice::Current& current)
{
	Vendor *pVendor = Dispatcher::findVendor("");
	if(pVendor==NULL)
	{
		showlog("exception: [heartbeat] vendor is empty");
		return;
	}
	pVendor->heatbeat();
	gLoggorWrap.heartbeat(senderType, senderId);

}

void
gtr::ILoggerI::gameMsg(const ::gtr::GameIdentifyT& gameId,
                       ::Ice::Int timetick,
                       const ::gtr::LogMessageT& msg,
                       const Ice::Current& current)
{
	Vendor *pVendor = Dispatcher::findVendor(gameId.id);
	if(pVendor==NULL)
	{
		showlog("exception: [gameMsg] vendor is empty");
		return;
	}
	//pVendor->makeLog(msg.msg);
	gLoggorWrap.gameMsg(gameId, timetick, msg);
}

void
gtr::ILoggerI::gameImage(const ::gtr::GameIdentifyT& gameId,
                         ::Ice::Int timetick,
                         const ::std::string& opName,
                         const ::gtr::ImageDataT& image,
                         const Ice::Current& current)
{
	Vendor *pVendor = Dispatcher::findVendor(gameId.id);
	if(pVendor==NULL)
	{
		showlog("exception: [gameImage] vendor is empty");
		return;
	}
	pVendor->makeScreenShot(opName, (void*)&*image.bytes.begin());
	gLoggorWrap.gameImage(gameId, timetick, opName, image);
}

::gtr::GameTaskletT
gtr::IGameHostI::getTask(const Ice::Current& current)
{
	Vendor *pVendor = Dispatcher::findVendor("");
	if(pVendor==NULL)
	{
		showlog("exception: [getTask] vendor is empty");
		::gtr::GameTaskletT empty;
		return empty;
	}
	return pVendor->getTask();
}

void
gtr::IGameHostI::completeTask(const ::gtr::GameTaskResultT& result,
                              const Ice::Current& current)
{
	Vendor *pVendor = Dispatcher::findVendor(result.gameId);
	if(pVendor==NULL)
	{
		showlog("exception: [completeTask] vendor is empty");
		return;
	}
	pVendor->makeLog(result.errmsg);
#if GTRICE
	gServerWrap.completeTask(result);
	pVendor->setFinished(false);
#else
	pVendor->setResultFeedback(result.result, result.textval);
	pVendor->setFinished(true);
#endif
	
}

/*
阻塞，直到answerResult被调用
*/
::std::string 
gtr::IGameHostI::answer(const ::gtr::QuestionContentT& question,
							 const Ice::Current&)
{
	Vendor *pVendor = Dispatcher::findVendor("");
	if(pVendor==NULL)
	{
		showlog("exception: [answer] vendor is empty");
		return "";
	}
	string taskNo = pVendor->getTaskNo();

#if GTRICE
	pVendor->setAnswerWait();
	gServerWrap.answer(taskNo, question);
	return pVendor->getAnswer();

#else
	//	int type;								// 1- 密保卡(图片+文本坐标), 2- 密保卡(图片+图片坐标);3-验证码(图片)

	// 1- 图片 ,2 - 坐标
	switch(question.type)
	{
	case 1:
		return pVendor->auth(1, question.image.bytes);
		break;

	case 2:
		return pVendor->auth(question.text);
		break;

	case 3:
		return pVendor->auth(3, question.image.bytes);
		break;
	}

	return "";
#endif
}

void
gtr::IGameHostI::verifyAnswer(::Ice::Int type,
						  bool success,
						  const Ice::Current&)
{
	Vendor *pVendor = Dispatcher::findVendor("");
	if(pVendor==NULL)
	{
		showlog("exception: [verifyAnswer] vendor is empty");
		return;
	}

	string taskNo = pVendor->getTaskNo();

#if GTRICE
	gServerWrap.verifyAnswer(taskNo, type, success );
#else
	pVendor->verifyAnswer(type, success);
#endif	
}

/*
由GTR服务器回调
*/
void IQuestionAskerI::answerResult(const ::std::string& taskNo,
		const ::std::string& result,
		const Ice::Current&)
{
	Vendor *pVendor = Dispatcher::findVendor("");
	if(pVendor==NULL)
	{
		showlog("exception: [answerResult] vendor is empty");
		return;
	}

#if GTRICE
	pVendor->setAnswer(result);
#else
	assert(taskNo == pVendor->getTaskNo());
#endif

}

