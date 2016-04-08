// **********************************************************************
//
// Copyright (c) 2003-2009 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.3.1
// Generated from file `redirect.ice'

#include <redirect.h>
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

static const ::std::string __rd__IService__getSequence_name = "getSequence";

static const ::std::string __rd__IService__getType_name = "getType";

static const ::std::string __rd__IService__getId_name = "getId";

static const ::std::string __rd__IService__getTimestamp_name = "getTimestamp";

static const ::std::string __rd__IService__getVersion_name = "getVersion";

static const ::std::string __rd__IRdDispatcher__getPingList_name = "getPingList";

static const ::std::string __rd__IRdDispatcher__completePing_name = "completePing";

static const ::std::string __rd__IRdDispatcher__getBastRdServers_name = "getBastRdServers";

static const ::std::string __rd__IRdDispatcher__connectedRdServer_name = "connectedRdServer";

static const ::std::string __rd__IRdDispatcher__disconnectedRdServer_name = "disconnectedRdServer";

static const ::std::string __rd__IRdFront__prepare_name = "prepare";

static const ::std::string __rd__IRdFront__end_name = "end";

::Ice::Object* IceInternal::upCast(::rd::IService* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::rd::IService* p) { return p; }

::Ice::Object* IceInternal::upCast(::rd::IRdDispatcher* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::rd::IRdDispatcher* p) { return p; }

::Ice::Object* IceInternal::upCast(::rd::IRdFront* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::rd::IRdFront* p) { return p; }

void
rd::__read(::IceInternal::BasicStream* __is, ::rd::IServicePrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::rd::IService;
        v->__copyFrom(proxy);
    }
}

void
rd::__read(::IceInternal::BasicStream* __is, ::rd::IRdDispatcherPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::rd::IRdDispatcher;
        v->__copyFrom(proxy);
    }
}

void
rd::__read(::IceInternal::BasicStream* __is, ::rd::IRdFrontPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::rd::IRdFront;
        v->__copyFrom(proxy);
    }
}

void
rd::__writeHashValueSet(::IceInternal::BasicStream* __os, const ::rd::HashValueSet& v)
{
    __os->writeSize(::Ice::Int(v.size()));
    ::rd::HashValueSet::const_iterator p;
    for(p = v.begin(); p != v.end(); ++p)
    {
        __os->write(p->first);
        __os->write(p->second);
    }
}

void
rd::__readHashValueSet(::IceInternal::BasicStream* __is, ::rd::HashValueSet& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    while(sz--)
    {
        ::std::pair<const  ::std::string, ::std::string> pair;
        __is->read(const_cast< ::std::string&>(pair.first));
        ::rd::HashValueSet::iterator __i = v.insert(v.end(), pair);
        __is->read(__i->second);
    }
}

void
rd::__writeReturnValueT(::IceInternal::BasicStream* __os, const ::rd::ReturnValueT& v)
{
    __os->writeSize(::Ice::Int(v.size()));
    ::rd::ReturnValueT::const_iterator p;
    for(p = v.begin(); p != v.end(); ++p)
    {
        __os->write(p->first);
        __os->write(p->second);
    }
}

void
rd::__readReturnValueT(::IceInternal::BasicStream* __is, ::rd::ReturnValueT& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    while(sz--)
    {
        ::std::pair<const  ::std::string, ::std::string> pair;
        __is->read(const_cast< ::std::string&>(pair.first));
        ::rd::ReturnValueT::iterator __i = v.insert(v.end(), pair);
        __is->read(__i->second);
    }
}

void
rd::__writeHashValueListT(::IceInternal::BasicStream* __os, const ::rd::HashValueSet* begin, const ::rd::HashValueSet* end)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        ::rd::__writeHashValueSet(__os, begin[i]);
    }
}

void
rd::__readHashValueListT(::IceInternal::BasicStream* __is, ::rd::HashValueListT& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->startSeq(sz, 1);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
        ::rd::__readHashValueSet(__is, v[i]);
        __is->checkSeq();
        __is->endElement();
    }
    __is->endSeq(sz);
}

void
rd::__writeStringListListT(::IceInternal::BasicStream* __os, const ::rd::StringListT* begin, const ::rd::StringListT* end)
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
rd::__readStringListListT(::IceInternal::BasicStream* __is, ::rd::StringListListT& v)
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
rd::CallResultT::operator==(const CallResultT& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(succ != __rhs.succ)
    {
        return false;
    }
    if(errNo != __rhs.errNo)
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
rd::CallResultT::operator<(const CallResultT& __rhs) const
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
    if(errNo < __rhs.errNo)
    {
        return true;
    }
    else if(__rhs.errNo < errNo)
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
rd::CallResultT::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(succ);
    __os->write(errNo);
    __os->write(msg);
}

void
rd::CallResultT::__read(::IceInternal::BasicStream* __is)
{
    __is->read(succ);
    __is->read(errNo);
    __is->read(msg);
}

bool
rd::PingTargetT::operator==(const PingTargetT& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(netaddr != __rhs.netaddr)
    {
        return false;
    }
    return true;
}

bool
rd::PingTargetT::operator<(const PingTargetT& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(netaddr < __rhs.netaddr)
    {
        return true;
    }
    else if(__rhs.netaddr < netaddr)
    {
        return false;
    }
    return false;
}

void
rd::PingTargetT::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(netaddr);
}

void
rd::PingTargetT::__read(::IceInternal::BasicStream* __is)
{
    __is->read(netaddr);
}

void
rd::__writePingTargetListT(::IceInternal::BasicStream* __os, const ::rd::PingTargetT* begin, const ::rd::PingTargetT* end)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        begin[i].__write(__os);
    }
}

void
rd::__readPingTargetListT(::IceInternal::BasicStream* __is, ::rd::PingTargetListT& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->checkFixedSeq(sz, 4);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
        v[i].__read(__is);
    }
}

bool
rd::PingResultT::operator==(const PingResultT& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(netaddr != __rhs.netaddr)
    {
        return false;
    }
    if(responseTime != __rhs.responseTime)
    {
        return false;
    }
    if(timetick != __rhs.timetick)
    {
        return false;
    }
    return true;
}

bool
rd::PingResultT::operator<(const PingResultT& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(netaddr < __rhs.netaddr)
    {
        return true;
    }
    else if(__rhs.netaddr < netaddr)
    {
        return false;
    }
    if(responseTime < __rhs.responseTime)
    {
        return true;
    }
    else if(__rhs.responseTime < responseTime)
    {
        return false;
    }
    if(timetick < __rhs.timetick)
    {
        return true;
    }
    else if(__rhs.timetick < timetick)
    {
        return false;
    }
    return false;
}

void
rd::PingResultT::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(netaddr);
    __os->write(responseTime);
    __os->write(timetick);
}

void
rd::PingResultT::__read(::IceInternal::BasicStream* __is)
{
    __is->read(netaddr);
    __is->read(responseTime);
    __is->read(timetick);
}

void
rd::__writePingResultListT(::IceInternal::BasicStream* __os, const ::rd::PingResultT* begin, const ::rd::PingResultT* end)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        begin[i].__write(__os);
    }
}

void
rd::__readPingResultListT(::IceInternal::BasicStream* __is, ::rd::PingResultListT& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->checkFixedSeq(sz, 12);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
        v[i].__read(__is);
    }
}

bool
rd::RdPingerInfoT::operator==(const RdPingerInfoT& __rhs) const
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
    return true;
}

bool
rd::RdPingerInfoT::operator<(const RdPingerInfoT& __rhs) const
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
    return false;
}

void
rd::RdPingerInfoT::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(id);
    __os->write(ip);
}

void
rd::RdPingerInfoT::__read(::IceInternal::BasicStream* __is)
{
    __is->read(id);
    __is->read(ip);
}

bool
rd::RdServerInfoT::operator==(const RdServerInfoT& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(ip != __rhs.ip)
    {
        return false;
    }
    if(port != __rhs.port)
    {
        return false;
    }
    if(mac != __rhs.mac)
    {
        return false;
    }
    return true;
}

bool
rd::RdServerInfoT::operator<(const RdServerInfoT& __rhs) const
{
    if(this == &__rhs)
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
    if(port < __rhs.port)
    {
        return true;
    }
    else if(__rhs.port < port)
    {
        return false;
    }
    if(mac < __rhs.mac)
    {
        return true;
    }
    else if(__rhs.mac < mac)
    {
        return false;
    }
    return false;
}

void
rd::RdServerInfoT::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(ip);
    __os->write(port);
    __os->write(mac);
}

void
rd::RdServerInfoT::__read(::IceInternal::BasicStream* __is)
{
    __is->read(ip);
    __is->read(port);
    __is->read(mac);
}

void
rd::__writeRdServerInfoListT(::IceInternal::BasicStream* __os, const ::rd::RdServerInfoT* begin, const ::rd::RdServerInfoT* end)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        begin[i].__write(__os);
    }
}

void
rd::__readRdServerInfoListT(::IceInternal::BasicStream* __is, ::rd::RdServerInfoListT& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->startSeq(sz, 6);
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
rd::RdFrontInfoT::operator==(const RdFrontInfoT& __rhs) const
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
    return true;
}

bool
rd::RdFrontInfoT::operator<(const RdFrontInfoT& __rhs) const
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
    return false;
}

void
rd::RdFrontInfoT::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(id);
    __os->write(ip);
}

void
rd::RdFrontInfoT::__read(::IceInternal::BasicStream* __is)
{
    __is->read(id);
    __is->read(ip);
}

bool
rd::RdWorkSheetT::operator==(const RdWorkSheetT& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(areaName != __rhs.areaName)
    {
        return false;
    }
    if(tradeNo != __rhs.tradeNo)
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
rd::RdWorkSheetT::operator<(const RdWorkSheetT& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(areaName < __rhs.areaName)
    {
        return true;
    }
    else if(__rhs.areaName < areaName)
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
rd::RdWorkSheetT::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(areaName);
    __os->write(tradeNo);
    __os->write(gameId);
}

void
rd::RdWorkSheetT::__read(::IceInternal::BasicStream* __is)
{
    __is->read(areaName);
    __is->read(tradeNo);
    __is->read(gameId);
}

::std::string
IceProxy::rd::IService::getSequence(const ::Ice::Context* __ctx)
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
            __checkTwowayOnly(__rd__IService__getSequence_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::rd::IService* __del = dynamic_cast< ::IceDelegate::rd::IService*>(__delBase.get());
            return __del->getSequence(__ctx);
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
IceProxy::rd::IService::getType(const ::Ice::Context* __ctx)
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
            __checkTwowayOnly(__rd__IService__getType_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::rd::IService* __del = dynamic_cast< ::IceDelegate::rd::IService*>(__delBase.get());
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

::std::string
IceProxy::rd::IService::getId(const ::Ice::Context* __ctx)
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
            __checkTwowayOnly(__rd__IService__getId_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::rd::IService* __del = dynamic_cast< ::IceDelegate::rd::IService*>(__delBase.get());
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
IceProxy::rd::IService::getTimestamp(const ::Ice::Context* __ctx)
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
            __checkTwowayOnly(__rd__IService__getTimestamp_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::rd::IService* __del = dynamic_cast< ::IceDelegate::rd::IService*>(__delBase.get());
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

::std::string
IceProxy::rd::IService::getVersion(const ::Ice::Context* __ctx)
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
            __checkTwowayOnly(__rd__IService__getVersion_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::rd::IService* __del = dynamic_cast< ::IceDelegate::rd::IService*>(__delBase.get());
            return __del->getVersion(__ctx);
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
IceProxy::rd::IService::ice_staticId()
{
    return ::rd::IService::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::rd::IService::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::rd::IService);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::rd::IService::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::rd::IService);
}

::IceProxy::Ice::Object*
IceProxy::rd::IService::__newInstance() const
{
    return new IService;
}

::rd::PingTargetListT
IceProxy::rd::IRdDispatcher::getPingList(const ::rd::RdPingerInfoT& pinger, const ::Ice::Context* __ctx)
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
            __checkTwowayOnly(__rd__IRdDispatcher__getPingList_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::rd::IRdDispatcher* __del = dynamic_cast< ::IceDelegate::rd::IRdDispatcher*>(__delBase.get());
            return __del->getPingList(pinger, __ctx);
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
IceProxy::rd::IRdDispatcher::completePing(const ::rd::RdPingerInfoT& pinger, const ::rd::PingResultListT& result, const ::Ice::Context* __ctx)
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
            ::IceDelegate::rd::IRdDispatcher* __del = dynamic_cast< ::IceDelegate::rd::IRdDispatcher*>(__delBase.get());
            __del->completePing(pinger, result, __ctx);
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

::rd::RdServerInfoListT
IceProxy::rd::IRdDispatcher::getBastRdServers(const ::std::string& areaName, ::Ice::Int reqnum, const ::rd::RdFrontInfoT& front, const ::Ice::Context* __ctx)
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
            __checkTwowayOnly(__rd__IRdDispatcher__getBastRdServers_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::rd::IRdDispatcher* __del = dynamic_cast< ::IceDelegate::rd::IRdDispatcher*>(__delBase.get());
            return __del->getBastRdServers(areaName, reqnum, front, __ctx);
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

::rd::CallResultT
IceProxy::rd::IRdDispatcher::connectedRdServer(const ::rd::RdFrontInfoT& front, const ::rd::RdServerInfoT& server, const ::rd::RdWorkSheetT& sheet, const ::Ice::Context* __ctx)
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
            __checkTwowayOnly(__rd__IRdDispatcher__connectedRdServer_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::rd::IRdDispatcher* __del = dynamic_cast< ::IceDelegate::rd::IRdDispatcher*>(__delBase.get());
            return __del->connectedRdServer(front, server, sheet, __ctx);
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

::rd::CallResultT
IceProxy::rd::IRdDispatcher::disconnectedRdServer(const ::rd::RdFrontInfoT& front, const ::rd::RdServerInfoT& server, const ::rd::RdWorkSheetT& sheet, const ::Ice::Context* __ctx)
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
            __checkTwowayOnly(__rd__IRdDispatcher__disconnectedRdServer_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::rd::IRdDispatcher* __del = dynamic_cast< ::IceDelegate::rd::IRdDispatcher*>(__delBase.get());
            return __del->disconnectedRdServer(front, server, sheet, __ctx);
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
IceProxy::rd::IRdDispatcher::ice_staticId()
{
    return ::rd::IRdDispatcher::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::rd::IRdDispatcher::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::rd::IRdDispatcher);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::rd::IRdDispatcher::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::rd::IRdDispatcher);
}

::IceProxy::Ice::Object*
IceProxy::rd::IRdDispatcher::__newInstance() const
{
    return new IRdDispatcher;
}

::rd::CallResultT
IceProxy::rd::IRdFront::prepare(const ::rd::RdWorkSheetT& sheet, ::Ice::Int timeout, const ::Ice::Context* __ctx)
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
            __checkTwowayOnly(__rd__IRdFront__prepare_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::rd::IRdFront* __del = dynamic_cast< ::IceDelegate::rd::IRdFront*>(__delBase.get());
            return __del->prepare(sheet, timeout, __ctx);
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
IceProxy::rd::IRdFront::end(const ::Ice::Context* __ctx)
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
            ::IceDelegate::rd::IRdFront* __del = dynamic_cast< ::IceDelegate::rd::IRdFront*>(__delBase.get());
            __del->end(__ctx);
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
IceProxy::rd::IRdFront::ice_staticId()
{
    return ::rd::IRdFront::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::rd::IRdFront::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::rd::IRdFront);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::rd::IRdFront::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::rd::IRdFront);
}

::IceProxy::Ice::Object*
IceProxy::rd::IRdFront::__newInstance() const
{
    return new IRdFront;
}

::std::string
IceDelegateM::rd::IService::getSequence(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __rd__IService__getSequence_name, ::Ice::Normal, __context);
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

::std::string
IceDelegateM::rd::IService::getType(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __rd__IService__getType_name, ::Ice::Normal, __context);
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

::std::string
IceDelegateM::rd::IService::getId(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __rd__IService__getId_name, ::Ice::Normal, __context);
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

::Ice::Int
IceDelegateM::rd::IService::getTimestamp(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __rd__IService__getTimestamp_name, ::Ice::Normal, __context);
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

::std::string
IceDelegateM::rd::IService::getVersion(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __rd__IService__getVersion_name, ::Ice::Normal, __context);
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

::rd::PingTargetListT
IceDelegateM::rd::IRdDispatcher::getPingList(const ::rd::RdPingerInfoT& pinger, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __rd__IRdDispatcher__getPingList_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        pinger.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    ::rd::PingTargetListT __ret;
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
        ::rd::__readPingTargetListT(__is, __ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rd::IRdDispatcher::completePing(const ::rd::RdPingerInfoT& pinger, const ::rd::PingResultListT& result, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __rd__IRdDispatcher__completePing_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        pinger.__write(__os);
        if(result.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            ::rd::__writePingResultListT(__os, &result[0], &result[0] + result.size());
        }
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

::rd::RdServerInfoListT
IceDelegateM::rd::IRdDispatcher::getBastRdServers(const ::std::string& areaName, ::Ice::Int reqnum, const ::rd::RdFrontInfoT& front, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __rd__IRdDispatcher__getBastRdServers_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(areaName);
        __os->write(reqnum);
        front.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    ::rd::RdServerInfoListT __ret;
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
        ::rd::__readRdServerInfoListT(__is, __ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::rd::CallResultT
IceDelegateM::rd::IRdDispatcher::connectedRdServer(const ::rd::RdFrontInfoT& front, const ::rd::RdServerInfoT& server, const ::rd::RdWorkSheetT& sheet, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __rd__IRdDispatcher__connectedRdServer_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        front.__write(__os);
        server.__write(__os);
        sheet.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    ::rd::CallResultT __ret;
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

::rd::CallResultT
IceDelegateM::rd::IRdDispatcher::disconnectedRdServer(const ::rd::RdFrontInfoT& front, const ::rd::RdServerInfoT& server, const ::rd::RdWorkSheetT& sheet, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __rd__IRdDispatcher__disconnectedRdServer_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        front.__write(__os);
        server.__write(__os);
        sheet.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    ::rd::CallResultT __ret;
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

::rd::CallResultT
IceDelegateM::rd::IRdFront::prepare(const ::rd::RdWorkSheetT& sheet, ::Ice::Int timeout, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __rd__IRdFront__prepare_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        sheet.__write(__os);
        __os->write(timeout);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    ::rd::CallResultT __ret;
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
IceDelegateM::rd::IRdFront::end(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __rd__IRdFront__end_name, ::Ice::Normal, __context);
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
IceDelegateD::rd::IService::getSequence(const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::std::string& __result, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::rd::IService* servant = dynamic_cast< ::rd::IService*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->getSequence(_current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::std::string& _result;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __rd__IService__getSequence_name, ::Ice::Normal, __context);
    ::std::string __result;
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

::std::string
IceDelegateD::rd::IService::getType(const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::std::string& __result, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::rd::IService* servant = dynamic_cast< ::rd::IService*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->getType(_current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::std::string& _result;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __rd__IService__getType_name, ::Ice::Normal, __context);
    ::std::string __result;
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

::std::string
IceDelegateD::rd::IService::getId(const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::std::string& __result, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::rd::IService* servant = dynamic_cast< ::rd::IService*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->getId(_current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::std::string& _result;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __rd__IService__getId_name, ::Ice::Normal, __context);
    ::std::string __result;
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
IceDelegateD::rd::IService::getTimestamp(const ::Ice::Context* __context)
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
            ::rd::IService* servant = dynamic_cast< ::rd::IService*>(object);
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
    __initCurrent(__current, __rd__IService__getTimestamp_name, ::Ice::Normal, __context);
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

::std::string
IceDelegateD::rd::IService::getVersion(const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::std::string& __result, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::rd::IService* servant = dynamic_cast< ::rd::IService*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->getVersion(_current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::std::string& _result;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __rd__IService__getVersion_name, ::Ice::Normal, __context);
    ::std::string __result;
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

::rd::PingTargetListT
IceDelegateD::rd::IRdDispatcher::getPingList(const ::rd::RdPingerInfoT& pinger, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::rd::PingTargetListT& __result, const ::rd::RdPingerInfoT& pinger, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_pinger(pinger)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::rd::IRdDispatcher* servant = dynamic_cast< ::rd::IRdDispatcher*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->getPingList(_m_pinger, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::rd::PingTargetListT& _result;
        const ::rd::RdPingerInfoT& _m_pinger;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __rd__IRdDispatcher__getPingList_name, ::Ice::Normal, __context);
    ::rd::PingTargetListT __result;
    try
    {
        _DirectI __direct(__result, pinger, __current);
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
IceDelegateD::rd::IRdDispatcher::completePing(const ::rd::RdPingerInfoT& pinger, const ::rd::PingResultListT& result, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::rd::RdPingerInfoT& pinger, const ::rd::PingResultListT& result, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_pinger(pinger),
            _m_result(result)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::rd::IRdDispatcher* servant = dynamic_cast< ::rd::IRdDispatcher*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->completePing(_m_pinger, _m_result, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::rd::RdPingerInfoT& _m_pinger;
        const ::rd::PingResultListT& _m_result;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __rd__IRdDispatcher__completePing_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(pinger, result, __current);
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

::rd::RdServerInfoListT
IceDelegateD::rd::IRdDispatcher::getBastRdServers(const ::std::string& areaName, ::Ice::Int reqnum, const ::rd::RdFrontInfoT& front, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::rd::RdServerInfoListT& __result, const ::std::string& areaName, ::Ice::Int reqnum, const ::rd::RdFrontInfoT& front, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_areaName(areaName),
            _m_reqnum(reqnum),
            _m_front(front)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::rd::IRdDispatcher* servant = dynamic_cast< ::rd::IRdDispatcher*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->getBastRdServers(_m_areaName, _m_reqnum, _m_front, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::rd::RdServerInfoListT& _result;
        const ::std::string& _m_areaName;
        ::Ice::Int _m_reqnum;
        const ::rd::RdFrontInfoT& _m_front;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __rd__IRdDispatcher__getBastRdServers_name, ::Ice::Normal, __context);
    ::rd::RdServerInfoListT __result;
    try
    {
        _DirectI __direct(__result, areaName, reqnum, front, __current);
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

::rd::CallResultT
IceDelegateD::rd::IRdDispatcher::connectedRdServer(const ::rd::RdFrontInfoT& front, const ::rd::RdServerInfoT& server, const ::rd::RdWorkSheetT& sheet, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::rd::CallResultT& __result, const ::rd::RdFrontInfoT& front, const ::rd::RdServerInfoT& server, const ::rd::RdWorkSheetT& sheet, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_front(front),
            _m_server(server),
            _m_sheet(sheet)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::rd::IRdDispatcher* servant = dynamic_cast< ::rd::IRdDispatcher*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->connectedRdServer(_m_front, _m_server, _m_sheet, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::rd::CallResultT& _result;
        const ::rd::RdFrontInfoT& _m_front;
        const ::rd::RdServerInfoT& _m_server;
        const ::rd::RdWorkSheetT& _m_sheet;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __rd__IRdDispatcher__connectedRdServer_name, ::Ice::Normal, __context);
    ::rd::CallResultT __result;
    try
    {
        _DirectI __direct(__result, front, server, sheet, __current);
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

::rd::CallResultT
IceDelegateD::rd::IRdDispatcher::disconnectedRdServer(const ::rd::RdFrontInfoT& front, const ::rd::RdServerInfoT& server, const ::rd::RdWorkSheetT& sheet, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::rd::CallResultT& __result, const ::rd::RdFrontInfoT& front, const ::rd::RdServerInfoT& server, const ::rd::RdWorkSheetT& sheet, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_front(front),
            _m_server(server),
            _m_sheet(sheet)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::rd::IRdDispatcher* servant = dynamic_cast< ::rd::IRdDispatcher*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->disconnectedRdServer(_m_front, _m_server, _m_sheet, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::rd::CallResultT& _result;
        const ::rd::RdFrontInfoT& _m_front;
        const ::rd::RdServerInfoT& _m_server;
        const ::rd::RdWorkSheetT& _m_sheet;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __rd__IRdDispatcher__disconnectedRdServer_name, ::Ice::Normal, __context);
    ::rd::CallResultT __result;
    try
    {
        _DirectI __direct(__result, front, server, sheet, __current);
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

::rd::CallResultT
IceDelegateD::rd::IRdFront::prepare(const ::rd::RdWorkSheetT& sheet, ::Ice::Int timeout, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::rd::CallResultT& __result, const ::rd::RdWorkSheetT& sheet, ::Ice::Int timeout, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_sheet(sheet),
            _m_timeout(timeout)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::rd::IRdFront* servant = dynamic_cast< ::rd::IRdFront*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->prepare(_m_sheet, _m_timeout, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::rd::CallResultT& _result;
        const ::rd::RdWorkSheetT& _m_sheet;
        ::Ice::Int _m_timeout;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __rd__IRdFront__prepare_name, ::Ice::Normal, __context);
    ::rd::CallResultT __result;
    try
    {
        _DirectI __direct(__result, sheet, timeout, __current);
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
IceDelegateD::rd::IRdFront::end(const ::Ice::Context* __context)
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
            ::rd::IRdFront* servant = dynamic_cast< ::rd::IRdFront*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->end(_current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __rd__IRdFront__end_name, ::Ice::Normal, __context);
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

::Ice::ObjectPtr
rd::IService::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __rd__IService_ids[2] =
{
    "::Ice::Object",
    "::rd::IService"
};

bool
rd::IService::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__rd__IService_ids, __rd__IService_ids + 2, _s);
}

::std::vector< ::std::string>
rd::IService::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__rd__IService_ids[0], &__rd__IService_ids[2]);
}

const ::std::string&
rd::IService::ice_id(const ::Ice::Current&) const
{
    return __rd__IService_ids[1];
}

const ::std::string&
rd::IService::ice_staticId()
{
    return __rd__IService_ids[1];
}

::Ice::DispatchStatus
rd::IService::___getSequence(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string __ret = getSequence(__current);
    __os->write(__ret);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
rd::IService::___getType(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string __ret = getType(__current);
    __os->write(__ret);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
rd::IService::___getId(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string __ret = getId(__current);
    __os->write(__ret);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
rd::IService::___getTimestamp(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getTimestamp(__current);
    __os->write(__ret);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
rd::IService::___getVersion(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string __ret = getVersion(__current);
    __os->write(__ret);
    return ::Ice::DispatchOK;
}

static ::std::string __rd__IService_all[] =
{
    "getId",
    "getSequence",
    "getTimestamp",
    "getType",
    "getVersion",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping"
};

::Ice::DispatchStatus
rd::IService::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__rd__IService_all, __rd__IService_all + 9, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __rd__IService_all)
    {
        case 0:
        {
            return ___getId(in, current);
        }
        case 1:
        {
            return ___getSequence(in, current);
        }
        case 2:
        {
            return ___getTimestamp(in, current);
        }
        case 3:
        {
            return ___getType(in, current);
        }
        case 4:
        {
            return ___getVersion(in, current);
        }
        case 5:
        {
            return ___ice_id(in, current);
        }
        case 6:
        {
            return ___ice_ids(in, current);
        }
        case 7:
        {
            return ___ice_isA(in, current);
        }
        case 8:
        {
            return ___ice_ping(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
rd::IService::__write(::IceInternal::BasicStream* __os) const
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
rd::IService::__read(::IceInternal::BasicStream* __is, bool __rid)
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
rd::IService::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type rd::IService was not generated with stream support";
    throw ex;
}

void
rd::IService::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type rd::IService was not generated with stream support";
    throw ex;
}

void 
rd::__patch__IServicePtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::rd::IServicePtr* p = static_cast< ::rd::IServicePtr*>(__addr);
    assert(p);
    *p = ::rd::IServicePtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::rd::IService::ice_staticId(), v->ice_id());
    }
}

bool
rd::operator==(const ::rd::IService& l, const ::rd::IService& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
rd::operator<(const ::rd::IService& l, const ::rd::IService& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

::Ice::ObjectPtr
rd::IRdDispatcher::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __rd__IRdDispatcher_ids[3] =
{
    "::Ice::Object",
    "::rd::IRdDispatcher",
    "::rd::IService"
};

bool
rd::IRdDispatcher::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__rd__IRdDispatcher_ids, __rd__IRdDispatcher_ids + 3, _s);
}

::std::vector< ::std::string>
rd::IRdDispatcher::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__rd__IRdDispatcher_ids[0], &__rd__IRdDispatcher_ids[3]);
}

const ::std::string&
rd::IRdDispatcher::ice_id(const ::Ice::Current&) const
{
    return __rd__IRdDispatcher_ids[1];
}

const ::std::string&
rd::IRdDispatcher::ice_staticId()
{
    return __rd__IRdDispatcher_ids[1];
}

::Ice::DispatchStatus
rd::IRdDispatcher::___getPingList(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::rd::RdPingerInfoT pinger;
    pinger.__read(__is);
    __is->endReadEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::rd::PingTargetListT __ret = getPingList(pinger, __current);
    if(__ret.size() == 0)
    {
        __os->writeSize(0);
    }
    else
    {
        ::rd::__writePingTargetListT(__os, &__ret[0], &__ret[0] + __ret.size());
    }
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
rd::IRdDispatcher::___completePing(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::rd::RdPingerInfoT pinger;
    ::rd::PingResultListT result;
    pinger.__read(__is);
    ::rd::__readPingResultListT(__is, result);
    __is->endReadEncaps();
    completePing(pinger, result, __current);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
rd::IRdDispatcher::___getBastRdServers(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::std::string areaName;
    ::Ice::Int reqnum;
    ::rd::RdFrontInfoT front;
    __is->read(areaName);
    __is->read(reqnum);
    front.__read(__is);
    __is->endReadEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::rd::RdServerInfoListT __ret = getBastRdServers(areaName, reqnum, front, __current);
    if(__ret.size() == 0)
    {
        __os->writeSize(0);
    }
    else
    {
        ::rd::__writeRdServerInfoListT(__os, &__ret[0], &__ret[0] + __ret.size());
    }
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
rd::IRdDispatcher::___connectedRdServer(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::rd::RdFrontInfoT front;
    ::rd::RdServerInfoT server;
    ::rd::RdWorkSheetT sheet;
    front.__read(__is);
    server.__read(__is);
    sheet.__read(__is);
    __is->endReadEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::rd::CallResultT __ret = connectedRdServer(front, server, sheet, __current);
    __ret.__write(__os);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
rd::IRdDispatcher::___disconnectedRdServer(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::rd::RdFrontInfoT front;
    ::rd::RdServerInfoT server;
    ::rd::RdWorkSheetT sheet;
    front.__read(__is);
    server.__read(__is);
    sheet.__read(__is);
    __is->endReadEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::rd::CallResultT __ret = disconnectedRdServer(front, server, sheet, __current);
    __ret.__write(__os);
    return ::Ice::DispatchOK;
}

static ::std::string __rd__IRdDispatcher_all[] =
{
    "completePing",
    "connectedRdServer",
    "disconnectedRdServer",
    "getBastRdServers",
    "getId",
    "getPingList",
    "getSequence",
    "getTimestamp",
    "getType",
    "getVersion",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping"
};

::Ice::DispatchStatus
rd::IRdDispatcher::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__rd__IRdDispatcher_all, __rd__IRdDispatcher_all + 14, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __rd__IRdDispatcher_all)
    {
        case 0:
        {
            return ___completePing(in, current);
        }
        case 1:
        {
            return ___connectedRdServer(in, current);
        }
        case 2:
        {
            return ___disconnectedRdServer(in, current);
        }
        case 3:
        {
            return ___getBastRdServers(in, current);
        }
        case 4:
        {
            return ___getId(in, current);
        }
        case 5:
        {
            return ___getPingList(in, current);
        }
        case 6:
        {
            return ___getSequence(in, current);
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
            return ___getVersion(in, current);
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
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
rd::IRdDispatcher::__write(::IceInternal::BasicStream* __os) const
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
rd::IRdDispatcher::__read(::IceInternal::BasicStream* __is, bool __rid)
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
rd::IRdDispatcher::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type rd::IRdDispatcher was not generated with stream support";
    throw ex;
}

void
rd::IRdDispatcher::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type rd::IRdDispatcher was not generated with stream support";
    throw ex;
}

void 
rd::__patch__IRdDispatcherPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::rd::IRdDispatcherPtr* p = static_cast< ::rd::IRdDispatcherPtr*>(__addr);
    assert(p);
    *p = ::rd::IRdDispatcherPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::rd::IRdDispatcher::ice_staticId(), v->ice_id());
    }
}

bool
rd::operator==(const ::rd::IRdDispatcher& l, const ::rd::IRdDispatcher& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
rd::operator<(const ::rd::IRdDispatcher& l, const ::rd::IRdDispatcher& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

::Ice::ObjectPtr
rd::IRdFront::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __rd__IRdFront_ids[2] =
{
    "::Ice::Object",
    "::rd::IRdFront"
};

bool
rd::IRdFront::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__rd__IRdFront_ids, __rd__IRdFront_ids + 2, _s);
}

::std::vector< ::std::string>
rd::IRdFront::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__rd__IRdFront_ids[0], &__rd__IRdFront_ids[2]);
}

const ::std::string&
rd::IRdFront::ice_id(const ::Ice::Current&) const
{
    return __rd__IRdFront_ids[1];
}

const ::std::string&
rd::IRdFront::ice_staticId()
{
    return __rd__IRdFront_ids[1];
}

::Ice::DispatchStatus
rd::IRdFront::___prepare(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::rd::RdWorkSheetT sheet;
    ::Ice::Int timeout;
    sheet.__read(__is);
    __is->read(timeout);
    __is->endReadEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::rd::CallResultT __ret = prepare(sheet, timeout, __current);
    __ret.__write(__os);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
rd::IRdFront::___end(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    __inS.is()->skipEmptyEncaps();
    end(__current);
    return ::Ice::DispatchOK;
}

static ::std::string __rd__IRdFront_all[] =
{
    "end",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "prepare"
};

::Ice::DispatchStatus
rd::IRdFront::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__rd__IRdFront_all, __rd__IRdFront_all + 6, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __rd__IRdFront_all)
    {
        case 0:
        {
            return ___end(in, current);
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
        case 5:
        {
            return ___prepare(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
rd::IRdFront::__write(::IceInternal::BasicStream* __os) const
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
rd::IRdFront::__read(::IceInternal::BasicStream* __is, bool __rid)
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
rd::IRdFront::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type rd::IRdFront was not generated with stream support";
    throw ex;
}

void
rd::IRdFront::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type rd::IRdFront was not generated with stream support";
    throw ex;
}

void 
rd::__patch__IRdFrontPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::rd::IRdFrontPtr* p = static_cast< ::rd::IRdFrontPtr*>(__addr);
    assert(p);
    *p = ::rd::IRdFrontPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::rd::IRdFront::ice_staticId(), v->ice_id());
    }
}

bool
rd::operator==(const ::rd::IRdFront& l, const ::rd::IRdFront& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
rd::operator<(const ::rd::IRdFront& l, const ::rd::IRdFront& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}
