#ifndef __gtrcI_h__
#define __gtrcI_h__

#include <gtrc.h>

namespace gtr
{

class IServiceI : virtual public IService
{
public:

    virtual ::Ice::Int getType(const Ice::Current&);

    virtual ::gtr::ServiceIdentifyT getId(const Ice::Current&);

    virtual ::Ice::Int getTimestamp(const Ice::Current&);

    virtual void shutdown(const Ice::Current&);

    virtual void heartbeat(const ::std::string&,
                           const ::std::string&,
                           const Ice::Current&);
};

class IAnswerEndpointI : virtual public IAnswerEndpoint,
                         virtual public ::gtr::IServiceI
{
public:

    virtual ::Ice::Int getRemains(const Ice::Current&);

    virtual ::Ice::Int addQuestion(const ::gtr::IQuestionServerPrx&,
                                   const ::std::string&,
                                   const ::std::string&,
                                   const ::gtr::QuestionContentT&,
                                   const Ice::Current&);
};

class IQuestionAskerI : virtual public IQuestionAsker
{
public:

    virtual void answerResult(const ::std::string&,
                              const ::std::string&,
                              const Ice::Current&);
};

class IQuestionServerI : virtual public IQuestionServer
{
public:

    virtual void answer(const ::gtr::IQuestionAskerPrx&,
                        const ::std::string&,
                        const ::gtr::QuestionContentT&,
                        const Ice::Current&);

    virtual void answerResult(const ::std::string&,
                              const ::gtr::QuestionResultT&,
                              const Ice::Current&);

    virtual ::gtr::CallReturnT login(const ::gtr::IAnswerEndpointPrx&,
                                     const ::std::string&,
                                     const ::std::string&,
                                     const Ice::Current&);

    virtual void logout(const ::gtr::IAnswerEndpointPrx&,
                        const ::std::string&,
                        const Ice::Current&);

    virtual void verifyAnswer(const ::std::string&,
                              ::Ice::Int,
                              bool,
                              const Ice::Current&);
};

class ILoggerI : virtual public ILogger
{
public:

    virtual void gameMsg(const ::gtr::GameIdentifyT&,
                         ::Ice::Int,
                         const ::gtr::LogMessageT&,
                         const Ice::Current&);

    virtual void gameImage(const ::gtr::GameIdentifyT&,
                           ::Ice::Int,
                           const ::std::string&,
                           const ::gtr::ImageDataT&,
                           const Ice::Current&);
};

class ILogServerI : virtual public ILogServer,
                    virtual public ::gtr::ILoggerI,
                    virtual public ::gtr::IServiceI
{
public:
};

class IGameHostI : virtual public IGameHost,
                   virtual public ::gtr::IQuestionAskerI,
                   virtual public ::gtr::IServiceI,
                   virtual public ::gtr::ILoggerI
{
public:

    virtual ::gtr::GameTaskletT getTask(const Ice::Current&);

    virtual void completeTask(const ::gtr::GameTaskResultT&,
                              const Ice::Current&);

    virtual ::std::string answer(const ::gtr::QuestionContentT&,
                                 const Ice::Current&);

    virtual void verifyAnswer(::Ice::Int,
                              bool,
                              const Ice::Current&);
};

class IGtrServerI : virtual public IGtrServer,
                    virtual public ::gtr::IServiceI,
                    virtual public ::gtr::IQuestionServerI
{
public:

    virtual ::gtr::GameTaskletT getTask(const ::gtr::GameRobotInfoT&,
                                        const Ice::Current&);

    virtual void completeTask(const ::gtr::GameTaskResultT&,
                              const Ice::Current&);
};

}

#endif
