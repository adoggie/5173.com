// **********************************************************************
//
// Copyright (c) 2003-2009 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.3.1
// Generated from file `gtrc.ice'

#include <gtrc.h>
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
#include <Ice/BasicStream.h>
#include <IceUtil/Iterator.h>
#include <IceUtil/ScopedArray.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 303
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

static const ::std::string __gtr__IService__getType_name = "getType";

static const ::std::string __gtr__IService__getId_name = "getId";

static const ::std::string __gtr__IService__getTimestamp_name = "getTimestamp";

static const ::std::string __gtr__IService__shutdown_name = "shutdown";

static const ::std::string __gtr__IService__heartbeat_name = "heartbeat";

static const ::std::string __gtr__IAnswerEndpoint__getRemains_name = "getRemains";

static const ::std::string __gtr__IAnswerEndpoint__addQuestion_name = "addQuestion";

static const ::std::string __gtr__IQuestionAsker__answerResult_name = "answerResult";

static const ::std::string __gtr__IQuestionServer__answer_name = "answer";

static const ::std::string __gtr__IQuestionServer__answerResult_name = "answerResult";

static const ::std::string __gtr__IQuestionServer__login_name = "login";

static const ::std::string __gtr__IQuestionServer__logout_name = "logout";

static const ::std::string __gtr__IQuestionServer__verifyAnswer_name = "verifyAnswer";

static const ::std::string __gtr__ILogger__gameMsg_name = "gameMsg";

static const ::std::string __gtr__ILogger__gameImage_name = "gameImage";

static const ::std::string __gtr__IGameHost__getTask_name = "getTask";

static const ::std::string __gtr__IGameHost__completeTask_name = "completeTask";

static const ::std::string __gtr__IGameHost__answer_name = "answer";

static const ::std::string __gtr__IGameHost__verifyAnswer_name = "verifyAnswer";

static const ::std::string __gtr__IGtrServer__getTask_name = "getTask";

static const ::std::string __gtr__IGtrServer__completeTask_name = "completeTask";

::Ice::Object* IceInternal::upCast(::gtr::IService* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::gtr::IService* p) { return p; }

::Ice::Object* IceInternal::upCast(::gtr::IAnswerEndpoint* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::gtr::IAnswerEndpoint* p) { return p; }

::Ice::Object* IceInternal::upCast(::gtr::IQuestionAsker* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::gtr::IQuestionAsker* p) { return p; }

::Ice::Object* IceInternal::upCast(::gtr::IQuestionServer* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::gtr::IQuestionServer* p) { return p; }

::Ice::Object* IceInternal::upCast(::gtr::ILogger* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::gtr::ILogger* p) { return p; }

::Ice::Object* IceInternal::upCast(::gtr::ILogServer* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::gtr::ILogServer* p) { return p; }

::Ice::Object* IceInternal::upCast(::gtr::IGameHost* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::gtr::IGameHost* p) { return p; }

::Ice::Object* IceInternal::upCast(::gtr::IGtrServer* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::gtr::IGtrServer* p) { return p; }

void
gtr::__read(::IceInternal::BasicStream* __is, ::gtr::IServicePrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::gtr::IService;
        v->__copyFrom(proxy);
    }
}

void
gtr::__read(::IceInternal::BasicStream* __is, ::gtr::IAnswerEndpointPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::gtr::IAnswerEndpoint;
        v->__copyFrom(proxy);
    }
}

void
gtr::__read(::IceInternal::BasicStream* __is, ::gtr::IQuestionAskerPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::gtr::IQuestionAsker;
        v->__copyFrom(proxy);
    }
}

void
gtr::__read(::IceInternal::BasicStream* __is, ::gtr::IQuestionServerPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::gtr::IQuestionServer;
        v->__copyFrom(proxy);
    }
}

void
gtr::__read(::IceInternal::BasicStream* __is, ::gtr::ILoggerPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::gtr::ILogger;
        v->__copyFrom(proxy);
    }
}

void
gtr::__read(::IceInternal::BasicStream* __is, ::gtr::ILogServerPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::gtr::ILogServer;
        v->__copyFrom(proxy);
    }
}

void
gtr::__read(::IceInternal::BasicStream* __is, ::gtr::IGameHostPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::gtr::IGameHost;
        v->__copyFrom(proxy);
    }
}

void
gtr::__read(::IceInternal::BasicStream* __is, ::gtr::IGtrServerPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::gtr::IGtrServer;
        v->__copyFrom(proxy);
    }
}

void
gtr::__writeHashValueSet(::IceInternal::BasicStream* __os, const ::gtr::HashValueSet& v)
{
    __os->writeSize(::Ice::Int(v.size()));
    ::gtr::HashValueSet::const_iterator p;
    for(p = v.begin(); p != v.end(); ++p)
    {
        __os->write(p->first);
        __os->write(p->second);
    }
}

void
gtr::__readHashValueSet(::IceInternal::BasicStream* __is, ::gtr::HashValueSet& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    while(sz--)
    {
        ::std::pair<const  ::std::string, ::std::string> pair;
        __is->read(const_cast< ::std::string&>(pair.first));
        ::gtr::HashValueSet::iterator __i = v.insert(v.end(), pair);
        __is->read(__i->second);
    }
}

void
gtr::__writeReturnValueT(::IceInternal::BasicStream* __os, const ::gtr::ReturnValueT& v)
{
    __os->writeSize(::Ice::Int(v.size()));
    ::gtr::ReturnValueT::const_iterator p;
    for(p = v.begin(); p != v.end(); ++p)
    {
        __os->write(p->first);
        __os->write(p->second);
    }
}

void
gtr::__readReturnValueT(::IceInternal::BasicStream* __is, ::gtr::ReturnValueT& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    while(sz--)
    {
        ::std::pair<const  ::std::string, ::std::string> pair;
        __is->read(const_cast< ::std::string&>(pair.first));
        ::gtr::ReturnValueT::iterator __i = v.insert(v.end(), pair);
        __is->read(__i->second);
    }
}

void
gtr::__writeHashValueListT(::IceInternal::BasicStream* __os, const ::gtr::HashValueSet* begin, const ::gtr::HashValueSet* end)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        ::gtr::__writeHashValueSet(__os, begin[i]);
    }
}

void
gtr::__readHashValueListT(::IceInternal::BasicStream* __is, ::gtr::HashValueListT& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->startSeq(sz, 1);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
        ::gtr::__readHashValueSet(__is, v[i]);
        __is->checkSeq();
        __is->endElement();
    }
    __is->endSeq(sz);
}

void
gtr::__writeStringListListT(::IceInternal::BasicStream* __os, const ::gtr::StringListT* begin, const ::gtr::StringListT* end)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        if(begin[i].size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            __os->write(&begin[i][0], &begin[i][0] + begin[i].size());
        }
    }
}

void
gtr::__readStringListListT(::IceInternal::BasicStream* __is, ::gtr::StringListListT& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->startSeq(sz, 1);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
        __is->read(v[i]);
        __is->endElement();
    }
    __is->endSeq(sz);
}

bool
gtr::CallReturnT::operator==(const CallReturnT& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(succ != __rhs.succ)
    {
        return false;
    }
    if(msg != __rhs.msg)
    {
        return false;
    }
    if(props != __rhs.props)
    {
        return false;
    }
    return true;
}

bool
gtr::CallReturnT::operator<(const CallReturnT& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(succ < __rhs.succ)
    {
        return true;
    }
    else if(__rhs.succ < succ)
    {
        return false;
    }
    if(msg < __rhs.msg)
    {
        return true;
    }
    else if(__rhs.msg < msg)
    {
        return false;
    }
    if(props < __rhs.props)
    {
        return true;
    }
    else if(__rhs.props < props)
    {
        return false;
    }
    return false;
}

void
gtr::CallReturnT::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(succ);
    __os->write(msg);
    ::gtr::__writeHashValueSet(__os, props);
}

void
gtr::CallReturnT::__read(::IceInternal::BasicStream* __is)
{
    __is->read(succ);
    __is->read(msg);
    ::gtr::__readHashValueSet(__is, props);
}

bool
gtr::ImageDataT::operator==(const ImageDataT& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(type != __rhs.type)
    {
        return false;
    }
    if(bytes != __rhs.bytes)
    {
        return false;
    }
    if(width != __rhs.width)
    {
        return false;
    }
    if(height != __rhs.height)
    {
        return false;
    }
    return true;
}

bool
gtr::ImageDataT::operator<(const ImageDataT& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(type < __rhs.type)
    {
        return true;
    }
    else if(__rhs.type < type)
    {
        return false;
    }
    if(bytes < __rhs.bytes)
    {
        return true;
    }
    else if(__rhs.bytes < bytes)
    {
        return false;
    }
    if(width < __rhs.width)
    {
        return true;
    }
    else if(__rhs.width < width)
    {
        return false;
    }
    if(height < __rhs.height)
    {
        return true;
    }
    else if(__rhs.height < height)
    {
        return false;
    }
    return false;
}

void
gtr::ImageDataT::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(type);
    if(bytes.size() == 0)
    {
        __os->writeSize(0);
    }
    else
    {
        __os->write(&bytes[0], &bytes[0] + bytes.size());
    }
    __os->write(width);
    __os->write(height);
}

void
gtr::ImageDataT::__read(::IceInternal::BasicStream* __is)
{
    __is->read(type);
    ::std::pair<const ::Ice::Byte*, const ::Ice::Byte*> ___bytes;
    __is->read(___bytes);
    ::std::vector< ::Ice::Byte>(___bytes.first, ___bytes.second).swap(bytes);
    __is->read(width);
    __is->read(height);
}

bool
gtr::GameAuthDataT::operator==(const GameAuthDataT& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(type != __rhs.type)
    {
        return false;
    }
    if(image != __rhs.image)
    {
        return false;
    }
    if(seckey != __rhs.seckey)
    {
        return false;
    }
    return true;
}

bool
gtr::GameAuthDataT::operator<(const GameAuthDataT& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(type < __rhs.type)
    {
        return true;
    }
    else if(__rhs.type < type)
    {
        return false;
    }
    if(image < __rhs.image)
    {
        return true;
    }
    else if(__rhs.image < image)
    {
        return false;
    }
    if(seckey < __rhs.seckey)
    {
        return true;
    }
    else if(__rhs.seckey < seckey)
    {
        return false;
    }
    return false;
}

void
gtr::GameAuthDataT::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(type);
    image.__write(__os);
    __os->write(seckey);
}

void
gtr::GameAuthDataT::__read(::IceInternal::BasicStream* __is)
{
    __is->read(type);
    image.__read(__is);
    __is->read(seckey);
}

bool
gtr::GameIdentifyT::operator==(const GameIdentifyT& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(id != __rhs.id)
    {
        return false;
    }
    if(tradeNo != __rhs.tradeNo)
    {
        return false;
    }
    return true;
}

bool
gtr::GameIdentifyT::operator<(const GameIdentifyT& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(id < __rhs.id)
    {
        return true;
    }
    else if(__rhs.id < id)
    {
        return false;
    }
    if(tradeNo < __rhs.tradeNo)
    {
        return true;
    }
    else if(__rhs.tradeNo < tradeNo)
    {
        return false;
    }
    return false;
}

void
gtr::GameIdentifyT::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(id);
    __os->write(tradeNo);
}

void
gtr::GameIdentifyT::__read(::IceInternal::BasicStream* __is)
{
    __is->read(id);
    __is->read(tradeNo);
}

bool
gtr::ServiceIdentifyT::operator==(const ServiceIdentifyT& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(id != __rhs.id)
    {
        return false;
    }
    if(version != __rhs.version)
    {
        return false;
    }
    return true;
}

bool
gtr::ServiceIdentifyT::operator<(const ServiceIdentifyT& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(id < __rhs.id)
    {
        return true;
    }
    else if(__rhs.id < id)
    {
        return false;
    }
    if(version < __rhs.version)
    {
        return true;
    }
    else if(__rhs.version < version)
    {
        return false;
    }
    return false;
}

void
gtr::ServiceIdentifyT::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(id);
    __os->write(version);
}

void
gtr::ServiceIdentifyT::__read(::IceInternal::BasicStream* __is)
{
    __is->read(id);
    __is->read(version);
}

bool
gtr::QuestionContentT::operator==(const QuestionContentT& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(type != __rhs.type)
    {
        return false;
    }
    if(image != __rhs.image)
    {
        return false;
    }
    if(image2 != __rhs.image2)
    {
        return false;
    }
    if(text != __rhs.text)
    {
        return false;
    }
    if(cookie != __rhs.cookie)
    {
        return false;
    }
    if(gameId != __rhs.gameId)
    {
        return false;
    }
    return true;
}

bool
gtr::QuestionContentT::operator<(const QuestionContentT& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(type < __rhs.type)
    {
        return true;
    }
    else if(__rhs.type < type)
    {
        return false;
    }
    if(image < __rhs.image)
    {
        return true;
    }
    else if(__rhs.image < image)
    {
        return false;
    }
    if(image2 < __rhs.image2)
    {
        return true;
    }
    else if(__rhs.image2 < image2)
    {
        return false;
    }
    if(text < __rhs.text)
    {
        return true;
    }
    else if(__rhs.text < text)
    {
        return false;
    }
    if(cookie < __rhs.cookie)
    {
        return true;
    }
    else if(__rhs.cookie < cookie)
    {
        return false;
    }
    if(gameId < __rhs.gameId)
    {
        return true;
    }
    else if(__rhs.gameId < gameId)
    {
        return false;
    }
    return false;
}

void
gtr::QuestionContentT::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(type);
    image.__write(__os);
    image2.__write(__os);
    __os->write(text);
    __os->write(cookie);
    __os->write(gameId);
}

void
gtr::QuestionContentT::__read(::IceInternal::BasicStream* __is)
{
    __is->read(type);
    image.__read(__is);
    image2.__read(__is);
    __is->read(text);
    __is->read(cookie);
    __is->read(gameId);
}

bool
gtr::QuestionResultT::operator==(const QuestionResultT& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(value != __rhs.value)
    {
        return false;
    }
    if(cookie != __rhs.cookie)
    {
        return false;
    }
    return true;
}

bool
gtr::QuestionResultT::operator<(const QuestionResultT& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(value < __rhs.value)
    {
        return true;
    }
    else if(__rhs.value < value)
    {
        return false;
    }
    if(cookie < __rhs.cookie)
    {
        return true;
    }
    else if(__rhs.cookie < cookie)
    {
        return false;
    }
    return false;
}

void
gtr::QuestionResultT::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(value);
    __os->write(cookie);
}

void
gtr::QuestionResultT::__read(::IceInternal::BasicStream* __is)
{
    __is->read(value);
    __is->read(cookie);
}

bool
gtr::LogMessageT::operator==(const LogMessageT& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(xclass != __rhs.xclass)
    {
        return false;
    }
    if(msg != __rhs.msg)
    {
        return false;
    }
    return true;
}

bool
gtr::LogMessageT::operator<(const LogMessageT& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(xclass < __rhs.xclass)
    {
        return true;
    }
    else if(__rhs.xclass < xclass)
    {
        return false;
    }
    if(msg < __rhs.msg)
    {
        return true;
    }
    else if(__rhs.msg < msg)
    {
        return false;
    }
    return false;
}

void
gtr::LogMessageT::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(xclass);
    __os->write(msg);
}

void
gtr::LogMessageT::__read(::IceInternal::BasicStream* __is)
{
    __is->read(xclass);
    __is->read(msg);
}

bool
gtr::GameWorkSheetPostT::operator==(const GameWorkSheetPostT& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(sellerActor != __rhs.sellerActor)
    {
        return false;
    }
    if(sellerLevel != __rhs.sellerLevel)
    {
        return false;
    }
    if(money != __rhs.money)
    {
        return false;
    }
    if(transactionTime != __rhs.transactionTime)
    {
        return false;
    }
    if(sellerSecondPwd != __rhs.sellerSecondPwd)
    {
        return false;
    }
    if(buyerActor != __rhs.buyerActor)
    {
        return false;
    }
    if(buyerLevel != __rhs.buyerLevel)
    {
        return false;
    }
    if(buyerMoney != __rhs.buyerMoney)
    {
        return false;
    }
    if(sellerIndex != __rhs.sellerIndex)
    {
        return false;
    }
    if(sellerGroup != __rhs.sellerGroup)
    {
        return false;
    }
    if(bankPwd != __rhs.bankPwd)
    {
        return false;
    }
    return true;
}

bool
gtr::GameWorkSheetPostT::operator<(const GameWorkSheetPostT& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(sellerActor < __rhs.sellerActor)
    {
        return true;
    }
    else if(__rhs.sellerActor < sellerActor)
    {
        return false;
    }
    if(sellerLevel < __rhs.sellerLevel)
    {
        return true;
    }
    else if(__rhs.sellerLevel < sellerLevel)
    {
        return false;
    }
    if(money < __rhs.money)
    {
        return true;
    }
    else if(__rhs.money < money)
    {
        return false;
    }
    if(transactionTime < __rhs.transactionTime)
    {
        return true;
    }
    else if(__rhs.transactionTime < transactionTime)
    {
        return false;
    }
    if(sellerSecondPwd < __rhs.sellerSecondPwd)
    {
        return true;
    }
    else if(__rhs.sellerSecondPwd < sellerSecondPwd)
    {
        return false;
    }
    if(buyerActor < __rhs.buyerActor)
    {
        return true;
    }
    else if(__rhs.buyerActor < buyerActor)
    {
        return false;
    }
    if(buyerLevel < __rhs.buyerLevel)
    {
        return true;
    }
    else if(__rhs.buyerLevel < buyerLevel)
    {
        return false;
    }
    if(buyerMoney < __rhs.buyerMoney)
    {
        return true;
    }
    else if(__rhs.buyerMoney < buyerMoney)
    {
        return false;
    }
    if(sellerIndex < __rhs.sellerIndex)
    {
        return true;
    }
    else if(__rhs.sellerIndex < sellerIndex)
    {
        return false;
    }
    if(sellerGroup < __rhs.sellerGroup)
    {
        return true;
    }
    else if(__rhs.sellerGroup < sellerGroup)
    {
        return false;
    }
    if(bankPwd < __rhs.bankPwd)
    {
        return true;
    }
    else if(__rhs.bankPwd < bankPwd)
    {
        return false;
    }
    return false;
}

void
gtr::GameWorkSheetPostT::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(sellerActor);
    __os->write(sellerLevel);
    __os->write(money);
    __os->write(transactionTime);
    __os->write(sellerSecondPwd);
    __os->write(buyerActor);
    __os->write(buyerLevel);
    __os->write(buyerMoney);
    __os->write(sellerIndex);
    __os->write(sellerGroup);
    __os->write(bankPwd);
}

void
gtr::GameWorkSheetPostT::__read(::IceInternal::BasicStream* __is)
{
    __is->read(sellerActor);
    __is->read(sellerLevel);
    __is->read(money);
    __is->read(transactionTime);
    __is->read(sellerSecondPwd);
    __is->read(buyerActor);
    __is->read(buyerLevel);
    __is->read(buyerMoney);
    __is->read(sellerIndex);
    __is->read(sellerGroup);
    __is->read(bankPwd);
}

bool
gtr::GameWorkSheetAccountAuditT::operator==(const GameWorkSheetAccountAuditT& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(sellerActor != __rhs.sellerActor)
    {
        return false;
    }
    if(sellerSecondPwd != __rhs.sellerSecondPwd)
    {
        return false;
    }
    if(sellerIndex != __rhs.sellerIndex)
    {
        return false;
    }
    if(sellerGroup != __rhs.sellerGroup)
    {
        return false;
    }
    if(bankPwd != __rhs.bankPwd)
    {
        return false;
    }
    return true;
}

bool
gtr::GameWorkSheetAccountAuditT::operator<(const GameWorkSheetAccountAuditT& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(sellerActor < __rhs.sellerActor)
    {
        return true;
    }
    else if(__rhs.sellerActor < sellerActor)
    {
        return false;
    }
    if(sellerSecondPwd < __rhs.sellerSecondPwd)
    {
        return true;
    }
    else if(__rhs.sellerSecondPwd < sellerSecondPwd)
    {
        return false;
    }
    if(sellerIndex < __rhs.sellerIndex)
    {
        return true;
    }
    else if(__rhs.sellerIndex < sellerIndex)
    {
        return false;
    }
    if(sellerGroup < __rhs.sellerGroup)
    {
        return true;
    }
    else if(__rhs.sellerGroup < sellerGroup)
    {
        return false;
    }
    if(bankPwd < __rhs.bankPwd)
    {
        return true;
    }
    else if(__rhs.bankPwd < bankPwd)
    {
        return false;
    }
    return false;
}

void
gtr::GameWorkSheetAccountAuditT::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(sellerActor);
    __os->write(sellerSecondPwd);
    __os->write(sellerIndex);
    __os->write(sellerGroup);
    __os->write(bankPwd);
}

void
gtr::GameWorkSheetAccountAuditT::__read(::IceInternal::BasicStream* __is)
{
    __is->read(sellerActor);
    __is->read(sellerSecondPwd);
    __is->read(sellerIndex);
    __is->read(sellerGroup);
    __is->read(bankPwd);
}

bool
gtr::GameWorkSheetVerifyT::operator==(const GameWorkSheetVerifyT& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(sellerActor != __rhs.sellerActor)
    {
        return false;
    }
    if(level != __rhs.level)
    {
        return false;
    }
    if(money != __rhs.money)
    {
        return false;
    }
    if(verifyTime != __rhs.verifyTime)
    {
        return false;
    }
    if(sellerSecondPwd != __rhs.sellerSecondPwd)
    {
        return false;
    }
    if(sellerIndex != __rhs.sellerIndex)
    {
        return false;
    }
    if(sellerGroup != __rhs.sellerGroup)
    {
        return false;
    }
    if(bankPwd != __rhs.bankPwd)
    {
        return false;
    }
    return true;
}

bool
gtr::GameWorkSheetVerifyT::operator<(const GameWorkSheetVerifyT& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(sellerActor < __rhs.sellerActor)
    {
        return true;
    }
    else if(__rhs.sellerActor < sellerActor)
    {
        return false;
    }
    if(level < __rhs.level)
    {
        return true;
    }
    else if(__rhs.level < level)
    {
        return false;
    }
    if(money < __rhs.money)
    {
        return true;
    }
    else if(__rhs.money < money)
    {
        return false;
    }
    if(verifyTime < __rhs.verifyTime)
    {
        return true;
    }
    else if(__rhs.verifyTime < verifyTime)
    {
        return false;
    }
    if(sellerSecondPwd < __rhs.sellerSecondPwd)
    {
        return true;
    }
    else if(__rhs.sellerSecondPwd < sellerSecondPwd)
    {
        return false;
    }
    if(sellerIndex < __rhs.sellerIndex)
    {
        return true;
    }
    else if(__rhs.sellerIndex < sellerIndex)
    {
        return false;
    }
    if(sellerGroup < __rhs.sellerGroup)
    {
        return true;
    }
    else if(__rhs.sellerGroup < sellerGroup)
    {
        return false;
    }
    if(bankPwd < __rhs.bankPwd)
    {
        return true;
    }
    else if(__rhs.bankPwd < bankPwd)
    {
        return false;
    }
    return false;
}

void
gtr::GameWorkSheetVerifyT::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(sellerActor);
    __os->write(level);
    __os->write(money);
    __os->write(verifyTime);
    __os->write(sellerSecondPwd);
    __os->write(sellerIndex);
    __os->write(sellerGroup);
    __os->write(bankPwd);
}

void
gtr::GameWorkSheetVerifyT::__read(::IceInternal::BasicStream* __is)
{
    __is->read(sellerActor);
    __is->read(level);
    __is->read(money);
    __is->read(verifyTime);
    __is->read(sellerSecondPwd);
    __is->read(sellerIndex);
    __is->read(sellerGroup);
    __is->read(bankPwd);
}

bool
gtr::GameTaskletT::operator==(const GameTaskletT& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(id != __rhs.id)
    {
        return false;
    }
    if(type != __rhs.type)
    {
        return false;
    }
    if(no != __rhs.no)
    {
        return false;
    }
    if(gameId != __rhs.gameId)
    {
        return false;
    }
    if(account != __rhs.account)
    {
        return false;
    }
    if(password != __rhs.password)
    {
        return false;
    }
    if(area != __rhs.area)
    {
        return false;
    }
    if(server != __rhs.server)
    {
        return false;
    }
    if(lineName != __rhs.lineName)
    {
        return false;
    }
    if(lineNo != __rhs.lineNo)
    {
        return false;
    }
    if(createTime != __rhs.createTime)
    {
        return false;
    }
    if(secretKey != __rhs.secretKey)
    {
        return false;
    }
    if(post != __rhs.post)
    {
        return false;
    }
    if(audit != __rhs.audit)
    {
        return false;
    }
    if(verify != __rhs.verify)
    {
        return false;
    }
    return true;
}

bool
gtr::GameTaskletT::operator<(const GameTaskletT& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(id < __rhs.id)
    {
        return true;
    }
    else if(__rhs.id < id)
    {
        return false;
    }
    if(type < __rhs.type)
    {
        return true;
    }
    else if(__rhs.type < type)
    {
        return false;
    }
    if(no < __rhs.no)
    {
        return true;
    }
    else if(__rhs.no < no)
    {
        return false;
    }
    if(gameId < __rhs.gameId)
    {
        return true;
    }
    else if(__rhs.gameId < gameId)
    {
        return false;
    }
    if(account < __rhs.account)
    {
        return true;
    }
    else if(__rhs.account < account)
    {
        return false;
    }
    if(password < __rhs.password)
    {
        return true;
    }
    else if(__rhs.password < password)
    {
        return false;
    }
    if(area < __rhs.area)
    {
        return true;
    }
    else if(__rhs.area < area)
    {
        return false;
    }
    if(server < __rhs.server)
    {
        return true;
    }
    else if(__rhs.server < server)
    {
        return false;
    }
    if(lineName < __rhs.lineName)
    {
        return true;
    }
    else if(__rhs.lineName < lineName)
    {
        return false;
    }
    if(lineNo < __rhs.lineNo)
    {
        return true;
    }
    else if(__rhs.lineNo < lineNo)
    {
        return false;
    }
    if(createTime < __rhs.createTime)
    {
        return true;
    }
    else if(__rhs.createTime < createTime)
    {
        return false;
    }
    if(secretKey < __rhs.secretKey)
    {
        return true;
    }
    else if(__rhs.secretKey < secretKey)
    {
        return false;
    }
    if(post < __rhs.post)
    {
        return true;
    }
    else if(__rhs.post < post)
    {
        return false;
    }
    if(audit < __rhs.audit)
    {
        return true;
    }
    else if(__rhs.audit < audit)
    {
        return false;
    }
    if(verify < __rhs.verify)
    {
        return true;
    }
    else if(__rhs.verify < verify)
    {
        return false;
    }
    return false;
}

void
gtr::GameTaskletT::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(id);
    __os->write(type);
    __os->write(no);
    __os->write(gameId);
    __os->write(account);
    __os->write(password);
    __os->write(area);
    __os->write(server);
    __os->write(lineName);
    __os->write(lineNo);
    __os->write(createTime);
    __os->write(secretKey);
    post.__write(__os);
    audit.__write(__os);
    verify.__write(__os);
}

void
gtr::GameTaskletT::__read(::IceInternal::BasicStream* __is)
{
    __is->read(id);
    __is->read(type);
    __is->read(no);
    __is->read(gameId);
    __is->read(account);
    __is->read(password);
    __is->read(area);
    __is->read(server);
    __is->read(lineName);
    __is->read(lineNo);
    __is->read(createTime);
    __is->read(secretKey);
    post.__read(__is);
    audit.__read(__is);
    verify.__read(__is);
}

bool
gtr::GameTaskResultT::operator==(const GameTaskResultT& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(id != __rhs.id)
    {
        return false;
    }
    if(no != __rhs.no)
    {
        return false;
    }
    if(type != __rhs.type)
    {
        return false;
    }
    if(gameId != __rhs.gameId)
    {
        return false;
    }
    if(result != __rhs.result)
    {
        return false;
    }
    if(errmsg != __rhs.errmsg)
    {
        return false;
    }
    if(textval != __rhs.textval)
    {
        return false;
    }
    return true;
}

bool
gtr::GameTaskResultT::operator<(const GameTaskResultT& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(id < __rhs.id)
    {
        return true;
    }
    else if(__rhs.id < id)
    {
        return false;
    }
    if(no < __rhs.no)
    {
        return true;
    }
    else if(__rhs.no < no)
    {
        return false;
    }
    if(type < __rhs.type)
    {
        return true;
    }
    else if(__rhs.type < type)
    {
        return false;
    }
    if(gameId < __rhs.gameId)
    {
        return true;
    }
    else if(__rhs.gameId < gameId)
    {
        return false;
    }
    if(result < __rhs.result)
    {
        return true;
    }
    else if(__rhs.result < result)
    {
        return false;
    }
    if(errmsg < __rhs.errmsg)
    {
        return true;
    }
    else if(__rhs.errmsg < errmsg)
    {
        return false;
    }
    if(textval < __rhs.textval)
    {
        return true;
    }
    else if(__rhs.textval < textval)
    {
        return false;
    }
    return false;
}

void
gtr::GameTaskResultT::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(id);
    __os->write(no);
    __os->write(type);
    __os->write(gameId);
    __os->write(result);
    __os->write(errmsg);
    __os->write(textval);
}

void
gtr::GameTaskResultT::__read(::IceInternal::BasicStream* __is)
{
    __is->read(id);
    __is->read(no);
    __is->read(type);
    __is->read(gameId);
    __is->read(result);
    __is->read(errmsg);
    __is->read(textval);
}

bool
gtr::GameInfoT::operator==(const GameInfoT& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(id != __rhs.id)
    {
        return false;
    }
    if(name != __rhs.name)
    {
        return false;
    }
    if(version != __rhs.version)
    {
        return false;
    }
    if(maskType != __rhs.maskType)
    {
        return false;
    }
    return true;
}

bool
gtr::GameInfoT::operator<(const GameInfoT& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(id < __rhs.id)
    {
        return true;
    }
    else if(__rhs.id < id)
    {
        return false;
    }
    if(name < __rhs.name)
    {
        return true;
    }
    else if(__rhs.name < name)
    {
        return false;
    }
    if(version < __rhs.version)
    {
        return true;
    }
    else if(__rhs.version < version)
    {
        return false;
    }
    if(maskType < __rhs.maskType)
    {
        return true;
    }
    else if(__rhs.maskType < maskType)
    {
        return false;
    }
    return false;
}

void
gtr::GameInfoT::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(id);
    __os->write(name);
    __os->write(version);
    __os->write(maskType);
}

void
gtr::GameInfoT::__read(::IceInternal::BasicStream* __is)
{
    __is->read(id);
    __is->read(name);
    __is->read(version);
    __is->read(maskType);
}

void
gtr::__writeGameInfoListT(::IceInternal::BasicStream* __os, const ::gtr::GameInfoT* begin, const ::gtr::GameInfoT* end)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        begin[i].__write(__os);
    }
}

void
gtr::__readGameInfoListT(::IceInternal::BasicStream* __is, ::gtr::GameInfoListT& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->startSeq(sz, 10);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
        v[i].__read(__is);
        __is->checkSeq();
        __is->endElement();
    }
    __is->endSeq(sz);
}

bool
gtr::GameRobotInfoT::operator==(const GameRobotInfoT& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(id != __rhs.id)
    {
        return false;
    }
    if(ip != __rhs.ip)
    {
        return false;
    }
    if(network != __rhs.network)
    {
        return false;
    }
    if(supportGames != __rhs.supportGames)
    {
        return false;
    }
    return true;
}

bool
gtr::GameRobotInfoT::operator<(const GameRobotInfoT& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(id < __rhs.id)
    {
        return true;
    }
    else if(__rhs.id < id)
    {
        return false;
    }
    if(ip < __rhs.ip)
    {
        return true;
    }
    else if(__rhs.ip < ip)
    {
        return false;
    }
    if(network < __rhs.network)
    {
        return true;
    }
    else if(__rhs.network < network)
    {
        return false;
    }
    if(supportGames < __rhs.supportGames)
    {
        return true;
    }
    else if(__rhs.supportGames < supportGames)
    {
        return false;
    }
    return false;
}

void
gtr::GameRobotInfoT::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(id);
    __os->write(ip);
    __os->write(network);
    if(supportGames.size() == 0)
    {
        __os->writeSize(0);
    }
    else
    {
        ::gtr::__writeGameInfoListT(__os, &supportGames[0], &supportGames[0] + supportGames.size());
    }
}

void
gtr::GameRobotInfoT::__read(::IceInternal::BasicStream* __is)
{
    __is->read(id);
    __is->read(ip);
    __is->read(network);
    ::gtr::__readGameInfoListT(__is, supportGames);
}

::Ice::Int
IceProxy::gtr::IService::getType(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __checkTwowayOnly(__gtr__IService__getType_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::gtr::IService* __del = dynamic_cast< ::IceDelegate::gtr::IService*>(__delBase.get());
            return __del->getType(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::gtr::ServiceIdentifyT
IceProxy::gtr::IService::getId(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __checkTwowayOnly(__gtr__IService__getId_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::gtr::IService* __del = dynamic_cast< ::IceDelegate::gtr::IService*>(__delBase.get());
            return __del->getId(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Ice::Int
IceProxy::gtr::IService::getTimestamp(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __checkTwowayOnly(__gtr__IService__getTimestamp_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::gtr::IService* __del = dynamic_cast< ::IceDelegate::gtr::IService*>(__delBase.get());
            return __del->getTimestamp(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::gtr::IService::shutdown(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __delBase = __getDelegate(false);
            ::IceDelegate::gtr::IService* __del = dynamic_cast< ::IceDelegate::gtr::IService*>(__delBase.get());
            __del->shutdown(__ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::gtr::IService::heartbeat(const ::std::string& senderType, const ::std::string& senderId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __delBase = __getDelegate(false);
            ::IceDelegate::gtr::IService* __del = dynamic_cast< ::IceDelegate::gtr::IService*>(__delBase.get());
            __del->heartbeat(senderType, senderId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

const ::std::string&
IceProxy::gtr::IService::ice_staticId()
{
    return ::gtr::IService::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::gtr::IService::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::gtr::IService);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::gtr::IService::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::gtr::IService);
}

::IceProxy::Ice::Object*
IceProxy::gtr::IService::__newInstance() const
{
    return new IService;
}

::Ice::Int
IceProxy::gtr::IAnswerEndpoint::getRemains(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __checkTwowayOnly(__gtr__IAnswerEndpoint__getRemains_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::gtr::IAnswerEndpoint* __del = dynamic_cast< ::IceDelegate::gtr::IAnswerEndpoint*>(__delBase.get());
            return __del->getRemains(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Ice::Int
IceProxy::gtr::IAnswerEndpoint::addQuestion(const ::gtr::IQuestionServerPrx& server, const ::std::string& no, const ::std::string& createTime, const ::gtr::QuestionContentT& question, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __checkTwowayOnly(__gtr__IAnswerEndpoint__addQuestion_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::gtr::IAnswerEndpoint* __del = dynamic_cast< ::IceDelegate::gtr::IAnswerEndpoint*>(__delBase.get());
            return __del->addQuestion(server, no, createTime, question, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

const ::std::string&
IceProxy::gtr::IAnswerEndpoint::ice_staticId()
{
    return ::gtr::IAnswerEndpoint::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::gtr::IAnswerEndpoint::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::gtr::IAnswerEndpoint);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::gtr::IAnswerEndpoint::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::gtr::IAnswerEndpoint);
}

::IceProxy::Ice::Object*
IceProxy::gtr::IAnswerEndpoint::__newInstance() const
{
    return new IAnswerEndpoint;
}

void
IceProxy::gtr::IQuestionAsker::answerResult(const ::std::string& no, const ::std::string& result, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __delBase = __getDelegate(false);
            ::IceDelegate::gtr::IQuestionAsker* __del = dynamic_cast< ::IceDelegate::gtr::IQuestionAsker*>(__delBase.get());
            __del->answerResult(no, result, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

const ::std::string&
IceProxy::gtr::IQuestionAsker::ice_staticId()
{
    return ::gtr::IQuestionAsker::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::gtr::IQuestionAsker::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::gtr::IQuestionAsker);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::gtr::IQuestionAsker::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::gtr::IQuestionAsker);
}

::IceProxy::Ice::Object*
IceProxy::gtr::IQuestionAsker::__newInstance() const
{
    return new IQuestionAsker;
}

void
IceProxy::gtr::IQuestionServer::answer(const ::gtr::IQuestionAskerPrx& asker, const ::std::string& no, const ::gtr::QuestionContentT& question, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __delBase = __getDelegate(false);
            ::IceDelegate::gtr::IQuestionServer* __del = dynamic_cast< ::IceDelegate::gtr::IQuestionServer*>(__delBase.get());
            __del->answer(asker, no, question, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::gtr::IQuestionServer::answerResult(const ::std::string& no, const ::gtr::QuestionResultT& result, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __delBase = __getDelegate(false);
            ::IceDelegate::gtr::IQuestionServer* __del = dynamic_cast< ::IceDelegate::gtr::IQuestionServer*>(__delBase.get());
            __del->answerResult(no, result, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::gtr::CallReturnT
IceProxy::gtr::IQuestionServer::login(const ::gtr::IAnswerEndpointPrx& answer, const ::std::string& worker, const ::std::string& passwd, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __checkTwowayOnly(__gtr__IQuestionServer__login_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::gtr::IQuestionServer* __del = dynamic_cast< ::IceDelegate::gtr::IQuestionServer*>(__delBase.get());
            return __del->login(answer, worker, passwd, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::gtr::IQuestionServer::logout(const ::gtr::IAnswerEndpointPrx& answer, const ::std::string& worker, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __delBase = __getDelegate(false);
            ::IceDelegate::gtr::IQuestionServer* __del = dynamic_cast< ::IceDelegate::gtr::IQuestionServer*>(__delBase.get());
            __del->logout(answer, worker, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::gtr::IQuestionServer::verifyAnswer(const ::std::string& no, ::Ice::Int type, bool succ, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __delBase = __getDelegate(false);
            ::IceDelegate::gtr::IQuestionServer* __del = dynamic_cast< ::IceDelegate::gtr::IQuestionServer*>(__delBase.get());
            __del->verifyAnswer(no, type, succ, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

const ::std::string&
IceProxy::gtr::IQuestionServer::ice_staticId()
{
    return ::gtr::IQuestionServer::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::gtr::IQuestionServer::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::gtr::IQuestionServer);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::gtr::IQuestionServer::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::gtr::IQuestionServer);
}

::IceProxy::Ice::Object*
IceProxy::gtr::IQuestionServer::__newInstance() const
{
    return new IQuestionServer;
}

void
IceProxy::gtr::ILogger::gameMsg(const ::gtr::GameIdentifyT& gameId, ::Ice::Int timetick, const ::gtr::LogMessageT& msg, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __delBase = __getDelegate(false);
            ::IceDelegate::gtr::ILogger* __del = dynamic_cast< ::IceDelegate::gtr::ILogger*>(__delBase.get());
            __del->gameMsg(gameId, timetick, msg, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::gtr::ILogger::gameImage(const ::gtr::GameIdentifyT& gameId, ::Ice::Int timetick, const ::std::string& opName, const ::gtr::ImageDataT& image, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __delBase = __getDelegate(false);
            ::IceDelegate::gtr::ILogger* __del = dynamic_cast< ::IceDelegate::gtr::ILogger*>(__delBase.get());
            __del->gameImage(gameId, timetick, opName, image, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

const ::std::string&
IceProxy::gtr::ILogger::ice_staticId()
{
    return ::gtr::ILogger::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::gtr::ILogger::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::gtr::ILogger);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::gtr::ILogger::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::gtr::ILogger);
}

::IceProxy::Ice::Object*
IceProxy::gtr::ILogger::__newInstance() const
{
    return new ILogger;
}

const ::std::string&
IceProxy::gtr::ILogServer::ice_staticId()
{
    return ::gtr::ILogServer::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::gtr::ILogServer::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::gtr::ILogServer);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::gtr::ILogServer::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::gtr::ILogServer);
}

::IceProxy::Ice::Object*
IceProxy::gtr::ILogServer::__newInstance() const
{
    return new ILogServer;
}

::gtr::GameTaskletT
IceProxy::gtr::IGameHost::getTask(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __checkTwowayOnly(__gtr__IGameHost__getTask_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::gtr::IGameHost* __del = dynamic_cast< ::IceDelegate::gtr::IGameHost*>(__delBase.get());
            return __del->getTask(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::gtr::IGameHost::completeTask(const ::gtr::GameTaskResultT& result, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __delBase = __getDelegate(false);
            ::IceDelegate::gtr::IGameHost* __del = dynamic_cast< ::IceDelegate::gtr::IGameHost*>(__delBase.get());
            __del->completeTask(result, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::std::string
IceProxy::gtr::IGameHost::answer(const ::gtr::QuestionContentT& question, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __checkTwowayOnly(__gtr__IGameHost__answer_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::gtr::IGameHost* __del = dynamic_cast< ::IceDelegate::gtr::IGameHost*>(__delBase.get());
            return __del->answer(question, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::gtr::IGameHost::verifyAnswer(::Ice::Int type, bool succ, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __delBase = __getDelegate(false);
            ::IceDelegate::gtr::IGameHost* __del = dynamic_cast< ::IceDelegate::gtr::IGameHost*>(__delBase.get());
            __del->verifyAnswer(type, succ, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

const ::std::string&
IceProxy::gtr::IGameHost::ice_staticId()
{
    return ::gtr::IGameHost::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::gtr::IGameHost::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::gtr::IGameHost);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::gtr::IGameHost::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::gtr::IGameHost);
}

::IceProxy::Ice::Object*
IceProxy::gtr::IGameHost::__newInstance() const
{
    return new IGameHost;
}

::gtr::GameTaskletT
IceProxy::gtr::IGtrServer::getTask(const ::gtr::GameRobotInfoT& robot, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __checkTwowayOnly(__gtr__IGtrServer__getTask_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::gtr::IGtrServer* __del = dynamic_cast< ::IceDelegate::gtr::IGtrServer*>(__delBase.get());
            return __del->getTask(robot, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::gtr::IGtrServer::completeTask(const ::gtr::GameTaskResultT& result, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __delBase = __getDelegate(false);
            ::IceDelegate::gtr::IGtrServer* __del = dynamic_cast< ::IceDelegate::gtr::IGtrServer*>(__delBase.get());
            __del->completeTask(result, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

const ::std::string&
IceProxy::gtr::IGtrServer::ice_staticId()
{
    return ::gtr::IGtrServer::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::gtr::IGtrServer::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::gtr::IGtrServer);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::gtr::IGtrServer::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::gtr::IGtrServer);
}

::IceProxy::Ice::Object*
IceProxy::gtr::IGtrServer::__newInstance() const
{
    return new IGtrServer;
}

::Ice::Int
IceDelegateM::gtr::IService::getType(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __gtr__IService__getType_name, ::Ice::Normal, __context);
    bool __ok = __og.invoke();
    ::Ice::Int __ret;
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::gtr::ServiceIdentifyT
IceDelegateM::gtr::IService::getId(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __gtr__IService__getId_name, ::Ice::Normal, __context);
    bool __ok = __og.invoke();
    ::gtr::ServiceIdentifyT __ret;
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __ret.__read(__is);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::gtr::IService::getTimestamp(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __gtr__IService__getTimestamp_name, ::Ice::Normal, __context);
    bool __ok = __og.invoke();
    ::Ice::Int __ret;
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::gtr::IService::shutdown(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __gtr__IService__shutdown_name, ::Ice::Normal, __context);
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateM::gtr::IService::heartbeat(const ::std::string& senderType, const ::std::string& senderId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __gtr__IService__heartbeat_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(senderType);
        __os->write(senderId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

::Ice::Int
IceDelegateM::gtr::IAnswerEndpoint::getRemains(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __gtr__IAnswerEndpoint__getRemains_name, ::Ice::Normal, __context);
    bool __ok = __og.invoke();
    ::Ice::Int __ret;
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::gtr::IAnswerEndpoint::addQuestion(const ::gtr::IQuestionServerPrx& server, const ::std::string& no, const ::std::string& createTime, const ::gtr::QuestionContentT& question, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __gtr__IAnswerEndpoint__addQuestion_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(::Ice::ObjectPrx(::IceInternal::upCast(server.get())));
        __os->write(no);
        __os->write(createTime);
        question.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    ::Ice::Int __ret;
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::gtr::IQuestionAsker::answerResult(const ::std::string& no, const ::std::string& result, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __gtr__IQuestionAsker__answerResult_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(no);
        __os->write(result);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateM::gtr::IQuestionServer::answer(const ::gtr::IQuestionAskerPrx& asker, const ::std::string& no, const ::gtr::QuestionContentT& question, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __gtr__IQuestionServer__answer_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(::Ice::ObjectPrx(::IceInternal::upCast(asker.get())));
        __os->write(no);
        question.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateM::gtr::IQuestionServer::answerResult(const ::std::string& no, const ::gtr::QuestionResultT& result, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __gtr__IQuestionServer__answerResult_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(no);
        result.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

::gtr::CallReturnT
IceDelegateM::gtr::IQuestionServer::login(const ::gtr::IAnswerEndpointPrx& answer, const ::std::string& worker, const ::std::string& passwd, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __gtr__IQuestionServer__login_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(::Ice::ObjectPrx(::IceInternal::upCast(answer.get())));
        __os->write(worker);
        __os->write(passwd);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    ::gtr::CallReturnT __ret;
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __ret.__read(__is);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::gtr::IQuestionServer::logout(const ::gtr::IAnswerEndpointPrx& answer, const ::std::string& worker, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __gtr__IQuestionServer__logout_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(::Ice::ObjectPrx(::IceInternal::upCast(answer.get())));
        __os->write(worker);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateM::gtr::IQuestionServer::verifyAnswer(const ::std::string& no, ::Ice::Int type, bool succ, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __gtr__IQuestionServer__verifyAnswer_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(no);
        __os->write(type);
        __os->write(succ);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateM::gtr::ILogger::gameMsg(const ::gtr::GameIdentifyT& gameId, ::Ice::Int timetick, const ::gtr::LogMessageT& msg, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __gtr__ILogger__gameMsg_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        gameId.__write(__os);
        __os->write(timetick);
        msg.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateM::gtr::ILogger::gameImage(const ::gtr::GameIdentifyT& gameId, ::Ice::Int timetick, const ::std::string& opName, const ::gtr::ImageDataT& image, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __gtr__ILogger__gameImage_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        gameId.__write(__os);
        __os->write(timetick);
        __os->write(opName);
        image.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

::gtr::GameTaskletT
IceDelegateM::gtr::IGameHost::getTask(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __gtr__IGameHost__getTask_name, ::Ice::Normal, __context);
    bool __ok = __og.invoke();
    ::gtr::GameTaskletT __ret;
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __ret.__read(__is);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::gtr::IGameHost::completeTask(const ::gtr::GameTaskResultT& result, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __gtr__IGameHost__completeTask_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        result.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

::std::string
IceDelegateM::gtr::IGameHost::answer(const ::gtr::QuestionContentT& question, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __gtr__IGameHost__answer_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        question.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    ::std::string __ret;
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::gtr::IGameHost::verifyAnswer(::Ice::Int type, bool succ, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __gtr__IGameHost__verifyAnswer_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(type);
        __os->write(succ);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

::gtr::GameTaskletT
IceDelegateM::gtr::IGtrServer::getTask(const ::gtr::GameRobotInfoT& robot, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __gtr__IGtrServer__getTask_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        robot.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    ::gtr::GameTaskletT __ret;
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __ret.__read(__is);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::gtr::IGtrServer::completeTask(const ::gtr::GameTaskResultT& result, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __gtr__IGtrServer__completeTask_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        result.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

::Ice::Int
IceDelegateD::gtr::IService::getType(const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Ice::Int& __result, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::gtr::IService* servant = dynamic_cast< ::gtr::IService*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->getType(_current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::Ice::Int& _result;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __gtr__IService__getType_name, ::Ice::Normal, __context);
    ::Ice::Int __result;
    try
    {
        _DirectI __direct(__result, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

::gtr::ServiceIdentifyT
IceDelegateD::gtr::IService::getId(const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::gtr::ServiceIdentifyT& __result, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::gtr::IService* servant = dynamic_cast< ::gtr::IService*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->getId(_current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::gtr::ServiceIdentifyT& _result;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __gtr__IService__getId_name, ::Ice::Normal, __context);
    ::gtr::ServiceIdentifyT __result;
    try
    {
        _DirectI __direct(__result, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

::Ice::Int
IceDelegateD::gtr::IService::getTimestamp(const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Ice::Int& __result, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::gtr::IService* servant = dynamic_cast< ::gtr::IService*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->getTimestamp(_current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::Ice::Int& _result;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __gtr__IService__getTimestamp_name, ::Ice::Normal, __context);
    ::Ice::Int __result;
    try
    {
        _DirectI __direct(__result, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

void
IceDelegateD::gtr::IService::shutdown(const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::gtr::IService* servant = dynamic_cast< ::gtr::IService*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->shutdown(_current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __gtr__IService__shutdown_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(__current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

void
IceDelegateD::gtr::IService::heartbeat(const ::std::string& senderType, const ::std::string& senderId, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::std::string& senderType, const ::std::string& senderId, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_senderType(senderType),
            _m_senderId(senderId)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::gtr::IService* servant = dynamic_cast< ::gtr::IService*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->heartbeat(_m_senderType, _m_senderId, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::std::string& _m_senderType;
        const ::std::string& _m_senderId;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __gtr__IService__heartbeat_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(senderType, senderId, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

::Ice::Int
IceDelegateD::gtr::IAnswerEndpoint::getRemains(const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Ice::Int& __result, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::gtr::IAnswerEndpoint* servant = dynamic_cast< ::gtr::IAnswerEndpoint*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->getRemains(_current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::Ice::Int& _result;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __gtr__IAnswerEndpoint__getRemains_name, ::Ice::Normal, __context);
    ::Ice::Int __result;
    try
    {
        _DirectI __direct(__result, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

::Ice::Int
IceDelegateD::gtr::IAnswerEndpoint::addQuestion(const ::gtr::IQuestionServerPrx& server, const ::std::string& no, const ::std::string& createTime, const ::gtr::QuestionContentT& question, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Ice::Int& __result, const ::gtr::IQuestionServerPrx& server, const ::std::string& no, const ::std::string& createTime, const ::gtr::QuestionContentT& question, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_server(server),
            _m_no(no),
            _m_createTime(createTime),
            _m_question(question)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::gtr::IAnswerEndpoint* servant = dynamic_cast< ::gtr::IAnswerEndpoint*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->addQuestion(_m_server, _m_no, _m_createTime, _m_question, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::Ice::Int& _result;
        const ::gtr::IQuestionServerPrx& _m_server;
        const ::std::string& _m_no;
        const ::std::string& _m_createTime;
        const ::gtr::QuestionContentT& _m_question;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __gtr__IAnswerEndpoint__addQuestion_name, ::Ice::Normal, __context);
    ::Ice::Int __result;
    try
    {
        _DirectI __direct(__result, server, no, createTime, question, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

void
IceDelegateD::gtr::IQuestionAsker::answerResult(const ::std::string& no, const ::std::string& result, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::std::string& no, const ::std::string& result, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_no(no),
            _m_result(result)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::gtr::IQuestionAsker* servant = dynamic_cast< ::gtr::IQuestionAsker*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->answerResult(_m_no, _m_result, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::std::string& _m_no;
        const ::std::string& _m_result;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __gtr__IQuestionAsker__answerResult_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(no, result, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

void
IceDelegateD::gtr::IQuestionServer::answer(const ::gtr::IQuestionAskerPrx& asker, const ::std::string& no, const ::gtr::QuestionContentT& question, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::gtr::IQuestionAskerPrx& asker, const ::std::string& no, const ::gtr::QuestionContentT& question, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_asker(asker),
            _m_no(no),
            _m_question(question)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::gtr::IQuestionServer* servant = dynamic_cast< ::gtr::IQuestionServer*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->answer(_m_asker, _m_no, _m_question, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::gtr::IQuestionAskerPrx& _m_asker;
        const ::std::string& _m_no;
        const ::gtr::QuestionContentT& _m_question;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __gtr__IQuestionServer__answer_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(asker, no, question, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

void
IceDelegateD::gtr::IQuestionServer::answerResult(const ::std::string& no, const ::gtr::QuestionResultT& result, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::std::string& no, const ::gtr::QuestionResultT& result, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_no(no),
            _m_result(result)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::gtr::IQuestionServer* servant = dynamic_cast< ::gtr::IQuestionServer*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->answerResult(_m_no, _m_result, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::std::string& _m_no;
        const ::gtr::QuestionResultT& _m_result;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __gtr__IQuestionServer__answerResult_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(no, result, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

::gtr::CallReturnT
IceDelegateD::gtr::IQuestionServer::login(const ::gtr::IAnswerEndpointPrx& answer, const ::std::string& worker, const ::std::string& passwd, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::gtr::CallReturnT& __result, const ::gtr::IAnswerEndpointPrx& answer, const ::std::string& worker, const ::std::string& passwd, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_answer(answer),
            _m_worker(worker),
            _m_passwd(passwd)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::gtr::IQuestionServer* servant = dynamic_cast< ::gtr::IQuestionServer*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->login(_m_answer, _m_worker, _m_passwd, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::gtr::CallReturnT& _result;
        const ::gtr::IAnswerEndpointPrx& _m_answer;
        const ::std::string& _m_worker;
        const ::std::string& _m_passwd;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __gtr__IQuestionServer__login_name, ::Ice::Normal, __context);
    ::gtr::CallReturnT __result;
    try
    {
        _DirectI __direct(__result, answer, worker, passwd, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

void
IceDelegateD::gtr::IQuestionServer::logout(const ::gtr::IAnswerEndpointPrx& answer, const ::std::string& worker, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::gtr::IAnswerEndpointPrx& answer, const ::std::string& worker, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_answer(answer),
            _m_worker(worker)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::gtr::IQuestionServer* servant = dynamic_cast< ::gtr::IQuestionServer*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->logout(_m_answer, _m_worker, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::gtr::IAnswerEndpointPrx& _m_answer;
        const ::std::string& _m_worker;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __gtr__IQuestionServer__logout_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(answer, worker, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

void
IceDelegateD::gtr::IQuestionServer::verifyAnswer(const ::std::string& no, ::Ice::Int type, bool succ, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::std::string& no, ::Ice::Int type, bool succ, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_no(no),
            _m_type(type),
            _m_succ(succ)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::gtr::IQuestionServer* servant = dynamic_cast< ::gtr::IQuestionServer*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->verifyAnswer(_m_no, _m_type, _m_succ, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::std::string& _m_no;
        ::Ice::Int _m_type;
        bool _m_succ;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __gtr__IQuestionServer__verifyAnswer_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(no, type, succ, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

void
IceDelegateD::gtr::ILogger::gameMsg(const ::gtr::GameIdentifyT& gameId, ::Ice::Int timetick, const ::gtr::LogMessageT& msg, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::gtr::GameIdentifyT& gameId, ::Ice::Int timetick, const ::gtr::LogMessageT& msg, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_gameId(gameId),
            _m_timetick(timetick),
            _m_msg(msg)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::gtr::ILogger* servant = dynamic_cast< ::gtr::ILogger*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->gameMsg(_m_gameId, _m_timetick, _m_msg, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::gtr::GameIdentifyT& _m_gameId;
        ::Ice::Int _m_timetick;
        const ::gtr::LogMessageT& _m_msg;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __gtr__ILogger__gameMsg_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(gameId, timetick, msg, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

void
IceDelegateD::gtr::ILogger::gameImage(const ::gtr::GameIdentifyT& gameId, ::Ice::Int timetick, const ::std::string& opName, const ::gtr::ImageDataT& image, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::gtr::GameIdentifyT& gameId, ::Ice::Int timetick, const ::std::string& opName, const ::gtr::ImageDataT& image, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_gameId(gameId),
            _m_timetick(timetick),
            _m_opName(opName),
            _m_image(image)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::gtr::ILogger* servant = dynamic_cast< ::gtr::ILogger*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->gameImage(_m_gameId, _m_timetick, _m_opName, _m_image, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::gtr::GameIdentifyT& _m_gameId;
        ::Ice::Int _m_timetick;
        const ::std::string& _m_opName;
        const ::gtr::ImageDataT& _m_image;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __gtr__ILogger__gameImage_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(gameId, timetick, opName, image, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

::gtr::GameTaskletT
IceDelegateD::gtr::IGameHost::getTask(const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::gtr::GameTaskletT& __result, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::gtr::IGameHost* servant = dynamic_cast< ::gtr::IGameHost*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->getTask(_current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::gtr::GameTaskletT& _result;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __gtr__IGameHost__getTask_name, ::Ice::Normal, __context);
    ::gtr::GameTaskletT __result;
    try
    {
        _DirectI __direct(__result, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

void
IceDelegateD::gtr::IGameHost::completeTask(const ::gtr::GameTaskResultT& result, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::gtr::GameTaskResultT& result, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_result(result)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::gtr::IGameHost* servant = dynamic_cast< ::gtr::IGameHost*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->completeTask(_m_result, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::gtr::GameTaskResultT& _m_result;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __gtr__IGameHost__completeTask_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(result, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

::std::string
IceDelegateD::gtr::IGameHost::answer(const ::gtr::QuestionContentT& question, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::std::string& __result, const ::gtr::QuestionContentT& question, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_question(question)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::gtr::IGameHost* servant = dynamic_cast< ::gtr::IGameHost*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->answer(_m_question, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::std::string& _result;
        const ::gtr::QuestionContentT& _m_question;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __gtr__IGameHost__answer_name, ::Ice::Normal, __context);
    ::std::string __result;
    try
    {
        _DirectI __direct(__result, question, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

void
IceDelegateD::gtr::IGameHost::verifyAnswer(::Ice::Int type, bool succ, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Ice::Int type, bool succ, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_type(type),
            _m_succ(succ)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::gtr::IGameHost* servant = dynamic_cast< ::gtr::IGameHost*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->verifyAnswer(_m_type, _m_succ, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::Ice::Int _m_type;
        bool _m_succ;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __gtr__IGameHost__verifyAnswer_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(type, succ, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

::gtr::GameTaskletT
IceDelegateD::gtr::IGtrServer::getTask(const ::gtr::GameRobotInfoT& robot, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::gtr::GameTaskletT& __result, const ::gtr::GameRobotInfoT& robot, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_robot(robot)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::gtr::IGtrServer* servant = dynamic_cast< ::gtr::IGtrServer*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->getTask(_m_robot, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::gtr::GameTaskletT& _result;
        const ::gtr::GameRobotInfoT& _m_robot;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __gtr__IGtrServer__getTask_name, ::Ice::Normal, __context);
    ::gtr::GameTaskletT __result;
    try
    {
        _DirectI __direct(__result, robot, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

void
IceDelegateD::gtr::IGtrServer::completeTask(const ::gtr::GameTaskResultT& result, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::gtr::GameTaskResultT& result, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_result(result)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::gtr::IGtrServer* servant = dynamic_cast< ::gtr::IGtrServer*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->completeTask(_m_result, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::gtr::GameTaskResultT& _m_result;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __gtr__IGtrServer__completeTask_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(result, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

::Ice::ObjectPtr
gtr::IService::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __gtr__IService_ids[2] =
{
    "::Ice::Object",
    "::gtr::IService"
};

bool
gtr::IService::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__gtr__IService_ids, __gtr__IService_ids + 2, _s);
}

::std::vector< ::std::string>
gtr::IService::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__gtr__IService_ids[0], &__gtr__IService_ids[2]);
}

const ::std::string&
gtr::IService::ice_id(const ::Ice::Current&) const
{
    return __gtr__IService_ids[1];
}

const ::std::string&
gtr::IService::ice_staticId()
{
    return __gtr__IService_ids[1];
}

::Ice::DispatchStatus
gtr::IService::___getType(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getType(__current);
    __os->write(__ret);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
gtr::IService::___getId(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::gtr::ServiceIdentifyT __ret = getId(__current);
    __ret.__write(__os);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
gtr::IService::___getTimestamp(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getTimestamp(__current);
    __os->write(__ret);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
gtr::IService::___shutdown(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    __inS.is()->skipEmptyEncaps();
    shutdown(__current);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
gtr::IService::___heartbeat(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::std::string senderType;
    ::std::string senderId;
    __is->read(senderType);
    __is->read(senderId);
    __is->endReadEncaps();
    heartbeat(senderType, senderId, __current);
    return ::Ice::DispatchOK;
}

static ::std::string __gtr__IService_all[] =
{
    "getId",
    "getTimestamp",
    "getType",
    "heartbeat",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "shutdown"
};

::Ice::DispatchStatus
gtr::IService::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__gtr__IService_all, __gtr__IService_all + 9, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __gtr__IService_all)
    {
        case 0:
        {
            return ___getId(in, current);
        }
        case 1:
        {
            return ___getTimestamp(in, current);
        }
        case 2:
        {
            return ___getType(in, current);
        }
        case 3:
        {
            return ___heartbeat(in, current);
        }
        case 4:
        {
            return ___ice_id(in, current);
        }
        case 5:
        {
            return ___ice_ids(in, current);
        }
        case 6:
        {
            return ___ice_isA(in, current);
        }
        case 7:
        {
            return ___ice_ping(in, current);
        }
        case 8:
        {
            return ___shutdown(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
gtr::IService::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
gtr::IService::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
gtr::IService::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type gtr::IService was not generated with stream support";
    throw ex;
}

void
gtr::IService::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type gtr::IService was not generated with stream support";
    throw ex;
}

void 
gtr::__patch__IServicePtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::gtr::IServicePtr* p = static_cast< ::gtr::IServicePtr*>(__addr);
    assert(p);
    *p = ::gtr::IServicePtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::gtr::IService::ice_staticId(), v->ice_id());
    }
}

bool
gtr::operator==(const ::gtr::IService& l, const ::gtr::IService& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
gtr::operator<(const ::gtr::IService& l, const ::gtr::IService& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

::Ice::ObjectPtr
gtr::IAnswerEndpoint::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __gtr__IAnswerEndpoint_ids[3] =
{
    "::Ice::Object",
    "::gtr::IAnswerEndpoint",
    "::gtr::IService"
};

bool
gtr::IAnswerEndpoint::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__gtr__IAnswerEndpoint_ids, __gtr__IAnswerEndpoint_ids + 3, _s);
}

::std::vector< ::std::string>
gtr::IAnswerEndpoint::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__gtr__IAnswerEndpoint_ids[0], &__gtr__IAnswerEndpoint_ids[3]);
}

const ::std::string&
gtr::IAnswerEndpoint::ice_id(const ::Ice::Current&) const
{
    return __gtr__IAnswerEndpoint_ids[1];
}

const ::std::string&
gtr::IAnswerEndpoint::ice_staticId()
{
    return __gtr__IAnswerEndpoint_ids[1];
}

::Ice::DispatchStatus
gtr::IAnswerEndpoint::___getRemains(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getRemains(__current);
    __os->write(__ret);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
gtr::IAnswerEndpoint::___addQuestion(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::gtr::IQuestionServerPrx server;
    ::std::string no;
    ::std::string createTime;
    ::gtr::QuestionContentT question;
    ::gtr::__read(__is, server);
    __is->read(no);
    __is->read(createTime);
    question.__read(__is);
    __is->endReadEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = addQuestion(server, no, createTime, question, __current);
    __os->write(__ret);
    return ::Ice::DispatchOK;
}

static ::std::string __gtr__IAnswerEndpoint_all[] =
{
    "addQuestion",
    "getId",
    "getRemains",
    "getTimestamp",
    "getType",
    "heartbeat",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "shutdown"
};

::Ice::DispatchStatus
gtr::IAnswerEndpoint::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__gtr__IAnswerEndpoint_all, __gtr__IAnswerEndpoint_all + 11, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __gtr__IAnswerEndpoint_all)
    {
        case 0:
        {
            return ___addQuestion(in, current);
        }
        case 1:
        {
            return ___getId(in, current);
        }
        case 2:
        {
            return ___getRemains(in, current);
        }
        case 3:
        {
            return ___getTimestamp(in, current);
        }
        case 4:
        {
            return ___getType(in, current);
        }
        case 5:
        {
            return ___heartbeat(in, current);
        }
        case 6:
        {
            return ___ice_id(in, current);
        }
        case 7:
        {
            return ___ice_ids(in, current);
        }
        case 8:
        {
            return ___ice_isA(in, current);
        }
        case 9:
        {
            return ___ice_ping(in, current);
        }
        case 10:
        {
            return ___shutdown(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
gtr::IAnswerEndpoint::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
gtr::IAnswerEndpoint::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
gtr::IAnswerEndpoint::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type gtr::IAnswerEndpoint was not generated with stream support";
    throw ex;
}

void
gtr::IAnswerEndpoint::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type gtr::IAnswerEndpoint was not generated with stream support";
    throw ex;
}

void 
gtr::__patch__IAnswerEndpointPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::gtr::IAnswerEndpointPtr* p = static_cast< ::gtr::IAnswerEndpointPtr*>(__addr);
    assert(p);
    *p = ::gtr::IAnswerEndpointPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::gtr::IAnswerEndpoint::ice_staticId(), v->ice_id());
    }
}

bool
gtr::operator==(const ::gtr::IAnswerEndpoint& l, const ::gtr::IAnswerEndpoint& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
gtr::operator<(const ::gtr::IAnswerEndpoint& l, const ::gtr::IAnswerEndpoint& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

::Ice::ObjectPtr
gtr::IQuestionAsker::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __gtr__IQuestionAsker_ids[2] =
{
    "::Ice::Object",
    "::gtr::IQuestionAsker"
};

bool
gtr::IQuestionAsker::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__gtr__IQuestionAsker_ids, __gtr__IQuestionAsker_ids + 2, _s);
}

::std::vector< ::std::string>
gtr::IQuestionAsker::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__gtr__IQuestionAsker_ids[0], &__gtr__IQuestionAsker_ids[2]);
}

const ::std::string&
gtr::IQuestionAsker::ice_id(const ::Ice::Current&) const
{
    return __gtr__IQuestionAsker_ids[1];
}

const ::std::string&
gtr::IQuestionAsker::ice_staticId()
{
    return __gtr__IQuestionAsker_ids[1];
}

::Ice::DispatchStatus
gtr::IQuestionAsker::___answerResult(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::std::string no;
    ::std::string result;
    __is->read(no);
    __is->read(result);
    __is->endReadEncaps();
    answerResult(no, result, __current);
    return ::Ice::DispatchOK;
}

static ::std::string __gtr__IQuestionAsker_all[] =
{
    "answerResult",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping"
};

::Ice::DispatchStatus
gtr::IQuestionAsker::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__gtr__IQuestionAsker_all, __gtr__IQuestionAsker_all + 5, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __gtr__IQuestionAsker_all)
    {
        case 0:
        {
            return ___answerResult(in, current);
        }
        case 1:
        {
            return ___ice_id(in, current);
        }
        case 2:
        {
            return ___ice_ids(in, current);
        }
        case 3:
        {
            return ___ice_isA(in, current);
        }
        case 4:
        {
            return ___ice_ping(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
gtr::IQuestionAsker::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
gtr::IQuestionAsker::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
gtr::IQuestionAsker::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type gtr::IQuestionAsker was not generated with stream support";
    throw ex;
}

void
gtr::IQuestionAsker::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type gtr::IQuestionAsker was not generated with stream support";
    throw ex;
}

void 
gtr::__patch__IQuestionAskerPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::gtr::IQuestionAskerPtr* p = static_cast< ::gtr::IQuestionAskerPtr*>(__addr);
    assert(p);
    *p = ::gtr::IQuestionAskerPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::gtr::IQuestionAsker::ice_staticId(), v->ice_id());
    }
}

bool
gtr::operator==(const ::gtr::IQuestionAsker& l, const ::gtr::IQuestionAsker& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
gtr::operator<(const ::gtr::IQuestionAsker& l, const ::gtr::IQuestionAsker& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

::Ice::ObjectPtr
gtr::IQuestionServer::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __gtr__IQuestionServer_ids[2] =
{
    "::Ice::Object",
    "::gtr::IQuestionServer"
};

bool
gtr::IQuestionServer::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__gtr__IQuestionServer_ids, __gtr__IQuestionServer_ids + 2, _s);
}

::std::vector< ::std::string>
gtr::IQuestionServer::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__gtr__IQuestionServer_ids[0], &__gtr__IQuestionServer_ids[2]);
}

const ::std::string&
gtr::IQuestionServer::ice_id(const ::Ice::Current&) const
{
    return __gtr__IQuestionServer_ids[1];
}

const ::std::string&
gtr::IQuestionServer::ice_staticId()
{
    return __gtr__IQuestionServer_ids[1];
}

::Ice::DispatchStatus
gtr::IQuestionServer::___answer(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::gtr::IQuestionAskerPrx asker;
    ::std::string no;
    ::gtr::QuestionContentT question;
    ::gtr::__read(__is, asker);
    __is->read(no);
    question.__read(__is);
    __is->endReadEncaps();
    answer(asker, no, question, __current);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
gtr::IQuestionServer::___answerResult(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::std::string no;
    ::gtr::QuestionResultT result;
    __is->read(no);
    result.__read(__is);
    __is->endReadEncaps();
    answerResult(no, result, __current);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
gtr::IQuestionServer::___login(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::gtr::IAnswerEndpointPrx answer;
    ::std::string worker;
    ::std::string passwd;
    ::gtr::__read(__is, answer);
    __is->read(worker);
    __is->read(passwd);
    __is->endReadEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::gtr::CallReturnT __ret = login(answer, worker, passwd, __current);
    __ret.__write(__os);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
gtr::IQuestionServer::___logout(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::gtr::IAnswerEndpointPrx answer;
    ::std::string worker;
    ::gtr::__read(__is, answer);
    __is->read(worker);
    __is->endReadEncaps();
    logout(answer, worker, __current);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
gtr::IQuestionServer::___verifyAnswer(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::std::string no;
    ::Ice::Int type;
    bool succ;
    __is->read(no);
    __is->read(type);
    __is->read(succ);
    __is->endReadEncaps();
    verifyAnswer(no, type, succ, __current);
    return ::Ice::DispatchOK;
}

static ::std::string __gtr__IQuestionServer_all[] =
{
    "answer",
    "answerResult",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "login",
    "logout",
    "verifyAnswer"
};

::Ice::DispatchStatus
gtr::IQuestionServer::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__gtr__IQuestionServer_all, __gtr__IQuestionServer_all + 9, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __gtr__IQuestionServer_all)
    {
        case 0:
        {
            return ___answer(in, current);
        }
        case 1:
        {
            return ___answerResult(in, current);
        }
        case 2:
        {
            return ___ice_id(in, current);
        }
        case 3:
        {
            return ___ice_ids(in, current);
        }
        case 4:
        {
            return ___ice_isA(in, current);
        }
        case 5:
        {
            return ___ice_ping(in, current);
        }
        case 6:
        {
            return ___login(in, current);
        }
        case 7:
        {
            return ___logout(in, current);
        }
        case 8:
        {
            return ___verifyAnswer(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
gtr::IQuestionServer::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
gtr::IQuestionServer::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
gtr::IQuestionServer::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type gtr::IQuestionServer was not generated with stream support";
    throw ex;
}

void
gtr::IQuestionServer::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type gtr::IQuestionServer was not generated with stream support";
    throw ex;
}

void 
gtr::__patch__IQuestionServerPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::gtr::IQuestionServerPtr* p = static_cast< ::gtr::IQuestionServerPtr*>(__addr);
    assert(p);
    *p = ::gtr::IQuestionServerPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::gtr::IQuestionServer::ice_staticId(), v->ice_id());
    }
}

bool
gtr::operator==(const ::gtr::IQuestionServer& l, const ::gtr::IQuestionServer& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
gtr::operator<(const ::gtr::IQuestionServer& l, const ::gtr::IQuestionServer& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

::Ice::ObjectPtr
gtr::ILogger::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __gtr__ILogger_ids[2] =
{
    "::Ice::Object",
    "::gtr::ILogger"
};

bool
gtr::ILogger::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__gtr__ILogger_ids, __gtr__ILogger_ids + 2, _s);
}

::std::vector< ::std::string>
gtr::ILogger::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__gtr__ILogger_ids[0], &__gtr__ILogger_ids[2]);
}

const ::std::string&
gtr::ILogger::ice_id(const ::Ice::Current&) const
{
    return __gtr__ILogger_ids[1];
}

const ::std::string&
gtr::ILogger::ice_staticId()
{
    return __gtr__ILogger_ids[1];
}

::Ice::DispatchStatus
gtr::ILogger::___gameMsg(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::gtr::GameIdentifyT gameId;
    ::Ice::Int timetick;
    ::gtr::LogMessageT msg;
    gameId.__read(__is);
    __is->read(timetick);
    msg.__read(__is);
    __is->endReadEncaps();
    gameMsg(gameId, timetick, msg, __current);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
gtr::ILogger::___gameImage(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::gtr::GameIdentifyT gameId;
    ::Ice::Int timetick;
    ::std::string opName;
    ::gtr::ImageDataT image;
    gameId.__read(__is);
    __is->read(timetick);
    __is->read(opName);
    image.__read(__is);
    __is->endReadEncaps();
    gameImage(gameId, timetick, opName, image, __current);
    return ::Ice::DispatchOK;
}

static ::std::string __gtr__ILogger_all[] =
{
    "gameImage",
    "gameMsg",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping"
};

::Ice::DispatchStatus
gtr::ILogger::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__gtr__ILogger_all, __gtr__ILogger_all + 6, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __gtr__ILogger_all)
    {
        case 0:
        {
            return ___gameImage(in, current);
        }
        case 1:
        {
            return ___gameMsg(in, current);
        }
        case 2:
        {
            return ___ice_id(in, current);
        }
        case 3:
        {
            return ___ice_ids(in, current);
        }
        case 4:
        {
            return ___ice_isA(in, current);
        }
        case 5:
        {
            return ___ice_ping(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
gtr::ILogger::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
gtr::ILogger::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
gtr::ILogger::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type gtr::ILogger was not generated with stream support";
    throw ex;
}

void
gtr::ILogger::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type gtr::ILogger was not generated with stream support";
    throw ex;
}

void 
gtr::__patch__ILoggerPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::gtr::ILoggerPtr* p = static_cast< ::gtr::ILoggerPtr*>(__addr);
    assert(p);
    *p = ::gtr::ILoggerPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::gtr::ILogger::ice_staticId(), v->ice_id());
    }
}

bool
gtr::operator==(const ::gtr::ILogger& l, const ::gtr::ILogger& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
gtr::operator<(const ::gtr::ILogger& l, const ::gtr::ILogger& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

::Ice::ObjectPtr
gtr::ILogServer::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __gtr__ILogServer_ids[4] =
{
    "::Ice::Object",
    "::gtr::ILogServer",
    "::gtr::ILogger",
    "::gtr::IService"
};

bool
gtr::ILogServer::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__gtr__ILogServer_ids, __gtr__ILogServer_ids + 4, _s);
}

::std::vector< ::std::string>
gtr::ILogServer::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__gtr__ILogServer_ids[0], &__gtr__ILogServer_ids[4]);
}

const ::std::string&
gtr::ILogServer::ice_id(const ::Ice::Current&) const
{
    return __gtr__ILogServer_ids[1];
}

const ::std::string&
gtr::ILogServer::ice_staticId()
{
    return __gtr__ILogServer_ids[1];
}

static ::std::string __gtr__ILogServer_all[] =
{
    "gameImage",
    "gameMsg",
    "getId",
    "getTimestamp",
    "getType",
    "heartbeat",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "shutdown"
};

::Ice::DispatchStatus
gtr::ILogServer::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__gtr__ILogServer_all, __gtr__ILogServer_all + 11, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __gtr__ILogServer_all)
    {
        case 0:
        {
            return ___gameImage(in, current);
        }
        case 1:
        {
            return ___gameMsg(in, current);
        }
        case 2:
        {
            return ___getId(in, current);
        }
        case 3:
        {
            return ___getTimestamp(in, current);
        }
        case 4:
        {
            return ___getType(in, current);
        }
        case 5:
        {
            return ___heartbeat(in, current);
        }
        case 6:
        {
            return ___ice_id(in, current);
        }
        case 7:
        {
            return ___ice_ids(in, current);
        }
        case 8:
        {
            return ___ice_isA(in, current);
        }
        case 9:
        {
            return ___ice_ping(in, current);
        }
        case 10:
        {
            return ___shutdown(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
gtr::ILogServer::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
gtr::ILogServer::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
gtr::ILogServer::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type gtr::ILogServer was not generated with stream support";
    throw ex;
}

void
gtr::ILogServer::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type gtr::ILogServer was not generated with stream support";
    throw ex;
}

void 
gtr::__patch__ILogServerPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::gtr::ILogServerPtr* p = static_cast< ::gtr::ILogServerPtr*>(__addr);
    assert(p);
    *p = ::gtr::ILogServerPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::gtr::ILogServer::ice_staticId(), v->ice_id());
    }
}

bool
gtr::operator==(const ::gtr::ILogServer& l, const ::gtr::ILogServer& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
gtr::operator<(const ::gtr::ILogServer& l, const ::gtr::ILogServer& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

::Ice::ObjectPtr
gtr::IGameHost::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __gtr__IGameHost_ids[5] =
{
    "::Ice::Object",
    "::gtr::IGameHost",
    "::gtr::ILogger",
    "::gtr::IQuestionAsker",
    "::gtr::IService"
};

bool
gtr::IGameHost::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__gtr__IGameHost_ids, __gtr__IGameHost_ids + 5, _s);
}

::std::vector< ::std::string>
gtr::IGameHost::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__gtr__IGameHost_ids[0], &__gtr__IGameHost_ids[5]);
}

const ::std::string&
gtr::IGameHost::ice_id(const ::Ice::Current&) const
{
    return __gtr__IGameHost_ids[1];
}

const ::std::string&
gtr::IGameHost::ice_staticId()
{
    return __gtr__IGameHost_ids[1];
}

::Ice::DispatchStatus
gtr::IGameHost::___getTask(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::gtr::GameTaskletT __ret = getTask(__current);
    __ret.__write(__os);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
gtr::IGameHost::___completeTask(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::gtr::GameTaskResultT result;
    result.__read(__is);
    __is->endReadEncaps();
    completeTask(result, __current);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
gtr::IGameHost::___answer(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::gtr::QuestionContentT question;
    question.__read(__is);
    __is->endReadEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string __ret = answer(question, __current);
    __os->write(__ret);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
gtr::IGameHost::___verifyAnswer(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int type;
    bool succ;
    __is->read(type);
    __is->read(succ);
    __is->endReadEncaps();
    verifyAnswer(type, succ, __current);
    return ::Ice::DispatchOK;
}

static ::std::string __gtr__IGameHost_all[] =
{
    "answer",
    "answerResult",
    "completeTask",
    "gameImage",
    "gameMsg",
    "getId",
    "getTask",
    "getTimestamp",
    "getType",
    "heartbeat",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "shutdown",
    "verifyAnswer"
};

::Ice::DispatchStatus
gtr::IGameHost::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__gtr__IGameHost_all, __gtr__IGameHost_all + 16, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __gtr__IGameHost_all)
    {
        case 0:
        {
            return ___answer(in, current);
        }
        case 1:
        {
            return ___answerResult(in, current);
        }
        case 2:
        {
            return ___completeTask(in, current);
        }
        case 3:
        {
            return ___gameImage(in, current);
        }
        case 4:
        {
            return ___gameMsg(in, current);
        }
        case 5:
        {
            return ___getId(in, current);
        }
        case 6:
        {
            return ___getTask(in, current);
        }
        case 7:
        {
            return ___getTimestamp(in, current);
        }
        case 8:
        {
            return ___getType(in, current);
        }
        case 9:
        {
            return ___heartbeat(in, current);
        }
        case 10:
        {
            return ___ice_id(in, current);
        }
        case 11:
        {
            return ___ice_ids(in, current);
        }
        case 12:
        {
            return ___ice_isA(in, current);
        }
        case 13:
        {
            return ___ice_ping(in, current);
        }
        case 14:
        {
            return ___shutdown(in, current);
        }
        case 15:
        {
            return ___verifyAnswer(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
gtr::IGameHost::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
gtr::IGameHost::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
gtr::IGameHost::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type gtr::IGameHost was not generated with stream support";
    throw ex;
}

void
gtr::IGameHost::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type gtr::IGameHost was not generated with stream support";
    throw ex;
}

void 
gtr::__patch__IGameHostPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::gtr::IGameHostPtr* p = static_cast< ::gtr::IGameHostPtr*>(__addr);
    assert(p);
    *p = ::gtr::IGameHostPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::gtr::IGameHost::ice_staticId(), v->ice_id());
    }
}

bool
gtr::operator==(const ::gtr::IGameHost& l, const ::gtr::IGameHost& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
gtr::operator<(const ::gtr::IGameHost& l, const ::gtr::IGameHost& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

::Ice::ObjectPtr
gtr::IGtrServer::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __gtr__IGtrServer_ids[4] =
{
    "::Ice::Object",
    "::gtr::IGtrServer",
    "::gtr::IQuestionServer",
    "::gtr::IService"
};

bool
gtr::IGtrServer::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__gtr__IGtrServer_ids, __gtr__IGtrServer_ids + 4, _s);
}

::std::vector< ::std::string>
gtr::IGtrServer::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__gtr__IGtrServer_ids[0], &__gtr__IGtrServer_ids[4]);
}

const ::std::string&
gtr::IGtrServer::ice_id(const ::Ice::Current&) const
{
    return __gtr__IGtrServer_ids[1];
}

const ::std::string&
gtr::IGtrServer::ice_staticId()
{
    return __gtr__IGtrServer_ids[1];
}

::Ice::DispatchStatus
gtr::IGtrServer::___getTask(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::gtr::GameRobotInfoT robot;
    robot.__read(__is);
    __is->endReadEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::gtr::GameTaskletT __ret = getTask(robot, __current);
    __ret.__write(__os);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
gtr::IGtrServer::___completeTask(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::gtr::GameTaskResultT result;
    result.__read(__is);
    __is->endReadEncaps();
    completeTask(result, __current);
    return ::Ice::DispatchOK;
}

static ::std::string __gtr__IGtrServer_all[] =
{
    "answer",
    "answerResult",
    "completeTask",
    "getId",
    "getTask",
    "getTimestamp",
    "getType",
    "heartbeat",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "login",
    "logout",
    "shutdown",
    "verifyAnswer"
};

::Ice::DispatchStatus
gtr::IGtrServer::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__gtr__IGtrServer_all, __gtr__IGtrServer_all + 16, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __gtr__IGtrServer_all)
    {
        case 0:
        {
            return ___answer(in, current);
        }
        case 1:
        {
            return ___answerResult(in, current);
        }
        case 2:
        {
            return ___completeTask(in, current);
        }
        case 3:
        {
            return ___getId(in, current);
        }
        case 4:
        {
            return ___getTask(in, current);
        }
        case 5:
        {
            return ___getTimestamp(in, current);
        }
        case 6:
        {
            return ___getType(in, current);
        }
        case 7:
        {
            return ___heartbeat(in, current);
        }
        case 8:
        {
            return ___ice_id(in, current);
        }
        case 9:
        {
            return ___ice_ids(in, current);
        }
        case 10:
        {
            return ___ice_isA(in, current);
        }
        case 11:
        {
            return ___ice_ping(in, current);
        }
        case 12:
        {
            return ___login(in, current);
        }
        case 13:
        {
            return ___logout(in, current);
        }
        case 14:
        {
            return ___shutdown(in, current);
        }
        case 15:
        {
            return ___verifyAnswer(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
gtr::IGtrServer::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
gtr::IGtrServer::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
gtr::IGtrServer::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type gtr::IGtrServer was not generated with stream support";
    throw ex;
}

void
gtr::IGtrServer::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type gtr::IGtrServer was not generated with stream support";
    throw ex;
}

void 
gtr::__patch__IGtrServerPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::gtr::IGtrServerPtr* p = static_cast< ::gtr::IGtrServerPtr*>(__addr);
    assert(p);
    *p = ::gtr::IGtrServerPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::gtr::IGtrServer::ice_staticId(), v->ice_id());
    }
}

bool
gtr::operator==(const ::gtr::IGtrServer& l, const ::gtr::IGtrServer& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
gtr::operator<(const ::gtr::IGtrServer& l, const ::gtr::IGtrServer& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}
