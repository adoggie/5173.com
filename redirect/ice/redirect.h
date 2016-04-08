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

#ifndef _____ice_redirect_h__
#define _____ice_redirect_h__

#include <Ice/LocalObjectF.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/Proxy.h>
#include <Ice/Object.h>
#include <Ice/Outgoing.h>
#include <Ice/Incoming.h>
#include <Ice/Direct.h>
#include <Ice/StreamF.h>
#include <Ice/UndefSysMacros.h>

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

namespace IceProxy
{

namespace rd
{

class IService;

class IRdDispatcher;

class IRdFront;

}

}

namespace rd
{

class IService;
bool operator==(const IService&, const IService&);
bool operator<(const IService&, const IService&);

class IRdDispatcher;
bool operator==(const IRdDispatcher&, const IRdDispatcher&);
bool operator<(const IRdDispatcher&, const IRdDispatcher&);

class IRdFront;
bool operator==(const IRdFront&, const IRdFront&);
bool operator<(const IRdFront&, const IRdFront&);

}

namespace IceInternal
{

::Ice::Object* upCast(::rd::IService*);
::IceProxy::Ice::Object* upCast(::IceProxy::rd::IService*);

::Ice::Object* upCast(::rd::IRdDispatcher*);
::IceProxy::Ice::Object* upCast(::IceProxy::rd::IRdDispatcher*);

::Ice::Object* upCast(::rd::IRdFront*);
::IceProxy::Ice::Object* upCast(::IceProxy::rd::IRdFront*);

}

namespace rd
{

typedef ::IceInternal::Handle< ::rd::IService> IServicePtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::rd::IService> IServicePrx;

void __read(::IceInternal::BasicStream*, IServicePrx&);
void __patch__IServicePtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::rd::IRdDispatcher> IRdDispatcherPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::rd::IRdDispatcher> IRdDispatcherPrx;

void __read(::IceInternal::BasicStream*, IRdDispatcherPrx&);
void __patch__IRdDispatcherPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::rd::IRdFront> IRdFrontPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::rd::IRdFront> IRdFrontPrx;

void __read(::IceInternal::BasicStream*, IRdFrontPrx&);
void __patch__IRdFrontPtr(void*, ::Ice::ObjectPtr&);

}

namespace rd
{

typedef ::std::map< ::std::string, ::std::string> HashValueSet;
void __writeHashValueSet(::IceInternal::BasicStream*, const HashValueSet&);
void __readHashValueSet(::IceInternal::BasicStream*, HashValueSet&);

typedef ::std::map< ::std::string, ::std::string> ReturnValueT;
void __writeReturnValueT(::IceInternal::BasicStream*, const ReturnValueT&);
void __readReturnValueT(::IceInternal::BasicStream*, ReturnValueT&);

typedef ::std::vector< ::Ice::Byte> StreamDataT;

typedef ::std::vector< ::std::string> StringListT;

typedef ::std::vector< ::rd::HashValueSet> HashValueListT;
void __writeHashValueListT(::IceInternal::BasicStream*, const ::rd::HashValueSet*, const ::rd::HashValueSet*);
void __readHashValueListT(::IceInternal::BasicStream*, HashValueListT&);

typedef ::std::vector< ::Ice::Int> IntListT;

typedef ::std::vector< ::rd::StringListT> StringListListT;
void __writeStringListListT(::IceInternal::BasicStream*, const ::rd::StringListT*, const ::rd::StringListT*);
void __readStringListListT(::IceInternal::BasicStream*, StringListListT&);

struct CallResultT
{
    bool succ;
    ::Ice::Int errNo;
    ::std::string msg;

    bool operator==(const CallResultT&) const;
    bool operator<(const CallResultT&) const;
    bool operator!=(const CallResultT& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const CallResultT& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const CallResultT& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const CallResultT& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct PingTargetT
{
    ::Ice::Int netaddr;

    bool operator==(const PingTargetT&) const;
    bool operator<(const PingTargetT&) const;
    bool operator!=(const PingTargetT& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const PingTargetT& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const PingTargetT& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const PingTargetT& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

typedef ::std::vector< ::rd::PingTargetT> PingTargetListT;
void __writePingTargetListT(::IceInternal::BasicStream*, const ::rd::PingTargetT*, const ::rd::PingTargetT*);
void __readPingTargetListT(::IceInternal::BasicStream*, PingTargetListT&);

struct PingResultT
{
    ::Ice::Int netaddr;
    ::Ice::Int responseTime;
    ::Ice::Int timetick;

    bool operator==(const PingResultT&) const;
    bool operator<(const PingResultT&) const;
    bool operator!=(const PingResultT& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const PingResultT& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const PingResultT& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const PingResultT& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

typedef ::std::vector< ::rd::PingResultT> PingResultListT;
void __writePingResultListT(::IceInternal::BasicStream*, const ::rd::PingResultT*, const ::rd::PingResultT*);
void __readPingResultListT(::IceInternal::BasicStream*, PingResultListT&);

struct RdPingerInfoT
{
    ::std::string id;
    ::std::string ip;

    bool operator==(const RdPingerInfoT&) const;
    bool operator<(const RdPingerInfoT&) const;
    bool operator!=(const RdPingerInfoT& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const RdPingerInfoT& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const RdPingerInfoT& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const RdPingerInfoT& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct RdServerInfoT
{
    ::std::string ip;
    ::Ice::Int port;
    ::std::string mac;

    bool operator==(const RdServerInfoT&) const;
    bool operator<(const RdServerInfoT&) const;
    bool operator!=(const RdServerInfoT& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const RdServerInfoT& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const RdServerInfoT& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const RdServerInfoT& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

typedef ::std::vector< ::rd::RdServerInfoT> RdServerInfoListT;
void __writeRdServerInfoListT(::IceInternal::BasicStream*, const ::rd::RdServerInfoT*, const ::rd::RdServerInfoT*);
void __readRdServerInfoListT(::IceInternal::BasicStream*, RdServerInfoListT&);

struct RdFrontInfoT
{
    ::std::string id;
    ::std::string ip;

    bool operator==(const RdFrontInfoT&) const;
    bool operator<(const RdFrontInfoT&) const;
    bool operator!=(const RdFrontInfoT& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const RdFrontInfoT& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const RdFrontInfoT& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const RdFrontInfoT& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct RdWorkSheetT
{
    ::std::string areaName;
    ::std::string tradeNo;
    ::Ice::Int gameId;

    bool operator==(const RdWorkSheetT&) const;
    bool operator<(const RdWorkSheetT&) const;
    bool operator!=(const RdWorkSheetT& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const RdWorkSheetT& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const RdWorkSheetT& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const RdWorkSheetT& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

}

namespace IceProxy
{

namespace rd
{

class IService : virtual public ::IceProxy::Ice::Object
{
public:

    ::std::string getSequence()
    {
        return getSequence(0);
    }
    ::std::string getSequence(const ::Ice::Context& __ctx)
    {
        return getSequence(&__ctx);
    }
    
private:

    ::std::string getSequence(const ::Ice::Context*);
    
public:

    ::std::string getType()
    {
        return getType(0);
    }
    ::std::string getType(const ::Ice::Context& __ctx)
    {
        return getType(&__ctx);
    }
    
private:

    ::std::string getType(const ::Ice::Context*);
    
public:

    ::std::string getId()
    {
        return getId(0);
    }
    ::std::string getId(const ::Ice::Context& __ctx)
    {
        return getId(&__ctx);
    }
    
private:

    ::std::string getId(const ::Ice::Context*);
    
public:

    ::Ice::Int getTimestamp()
    {
        return getTimestamp(0);
    }
    ::Ice::Int getTimestamp(const ::Ice::Context& __ctx)
    {
        return getTimestamp(&__ctx);
    }
    
private:

    ::Ice::Int getTimestamp(const ::Ice::Context*);
    
public:

    ::std::string getVersion()
    {
        return getVersion(0);
    }
    ::std::string getVersion(const ::Ice::Context& __ctx)
    {
        return getVersion(&__ctx);
    }
    
private:

    ::std::string getVersion(const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<IService> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IService*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<IService*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IService> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IService*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<IService*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IService> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IService*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<IService*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IService> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IService*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<IService*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IService> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IService*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<IService*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IService> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IService*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<IService*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IService> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IService*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<IService*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IService> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IService*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<IService*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IService> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IService*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<IService*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IService> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IService*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<IService*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IService> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IService*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<IService*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IService> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IService*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<IService*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IService> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IService*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<IService*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IService> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IService*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<IService*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IService> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IService*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<IService*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IService> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IService*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<IService*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IService> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IService*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<IService*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IService> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IService*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<IService*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IService> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IService*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<IService*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    #endif
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class IRdDispatcher : virtual public ::IceProxy::rd::IService
{
public:

    ::rd::PingTargetListT getPingList(const ::rd::RdPingerInfoT& pinger)
    {
        return getPingList(pinger, 0);
    }
    ::rd::PingTargetListT getPingList(const ::rd::RdPingerInfoT& pinger, const ::Ice::Context& __ctx)
    {
        return getPingList(pinger, &__ctx);
    }
    
private:

    ::rd::PingTargetListT getPingList(const ::rd::RdPingerInfoT&, const ::Ice::Context*);
    
public:

    void completePing(const ::rd::RdPingerInfoT& pinger, const ::rd::PingResultListT& result)
    {
        completePing(pinger, result, 0);
    }
    void completePing(const ::rd::RdPingerInfoT& pinger, const ::rd::PingResultListT& result, const ::Ice::Context& __ctx)
    {
        completePing(pinger, result, &__ctx);
    }
    
private:

    void completePing(const ::rd::RdPingerInfoT&, const ::rd::PingResultListT&, const ::Ice::Context*);
    
public:

    ::rd::RdServerInfoListT getBastRdServers(const ::std::string& areaName, ::Ice::Int reqnum, const ::rd::RdFrontInfoT& front)
    {
        return getBastRdServers(areaName, reqnum, front, 0);
    }
    ::rd::RdServerInfoListT getBastRdServers(const ::std::string& areaName, ::Ice::Int reqnum, const ::rd::RdFrontInfoT& front, const ::Ice::Context& __ctx)
    {
        return getBastRdServers(areaName, reqnum, front, &__ctx);
    }
    
private:

    ::rd::RdServerInfoListT getBastRdServers(const ::std::string&, ::Ice::Int, const ::rd::RdFrontInfoT&, const ::Ice::Context*);
    
public:

    ::rd::CallResultT connectedRdServer(const ::rd::RdFrontInfoT& front, const ::rd::RdServerInfoT& server, const ::rd::RdWorkSheetT& sheet)
    {
        return connectedRdServer(front, server, sheet, 0);
    }
    ::rd::CallResultT connectedRdServer(const ::rd::RdFrontInfoT& front, const ::rd::RdServerInfoT& server, const ::rd::RdWorkSheetT& sheet, const ::Ice::Context& __ctx)
    {
        return connectedRdServer(front, server, sheet, &__ctx);
    }
    
private:

    ::rd::CallResultT connectedRdServer(const ::rd::RdFrontInfoT&, const ::rd::RdServerInfoT&, const ::rd::RdWorkSheetT&, const ::Ice::Context*);
    
public:

    ::rd::CallResultT disconnectedRdServer(const ::rd::RdFrontInfoT& front, const ::rd::RdServerInfoT& server, const ::rd::RdWorkSheetT& sheet)
    {
        return disconnectedRdServer(front, server, sheet, 0);
    }
    ::rd::CallResultT disconnectedRdServer(const ::rd::RdFrontInfoT& front, const ::rd::RdServerInfoT& server, const ::rd::RdWorkSheetT& sheet, const ::Ice::Context& __ctx)
    {
        return disconnectedRdServer(front, server, sheet, &__ctx);
    }
    
private:

    ::rd::CallResultT disconnectedRdServer(const ::rd::RdFrontInfoT&, const ::rd::RdServerInfoT&, const ::rd::RdWorkSheetT&, const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<IRdDispatcher> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdDispatcher*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<IRdDispatcher*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdDispatcher> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdDispatcher*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<IRdDispatcher*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdDispatcher> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdDispatcher*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<IRdDispatcher*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdDispatcher> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdDispatcher*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<IRdDispatcher*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdDispatcher> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdDispatcher*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<IRdDispatcher*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdDispatcher> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdDispatcher*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<IRdDispatcher*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdDispatcher> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdDispatcher*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<IRdDispatcher*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdDispatcher> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdDispatcher*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<IRdDispatcher*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdDispatcher> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdDispatcher*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<IRdDispatcher*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdDispatcher> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdDispatcher*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<IRdDispatcher*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdDispatcher> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdDispatcher*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<IRdDispatcher*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdDispatcher> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdDispatcher*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<IRdDispatcher*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdDispatcher> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdDispatcher*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<IRdDispatcher*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdDispatcher> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdDispatcher*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<IRdDispatcher*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdDispatcher> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdDispatcher*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<IRdDispatcher*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdDispatcher> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdDispatcher*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<IRdDispatcher*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdDispatcher> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdDispatcher*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<IRdDispatcher*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdDispatcher> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdDispatcher*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<IRdDispatcher*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdDispatcher> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdDispatcher*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<IRdDispatcher*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    #endif
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class IRdFront : virtual public ::IceProxy::Ice::Object
{
public:

    ::rd::CallResultT prepare(const ::rd::RdWorkSheetT& sheet, ::Ice::Int timeout)
    {
        return prepare(sheet, timeout, 0);
    }
    ::rd::CallResultT prepare(const ::rd::RdWorkSheetT& sheet, ::Ice::Int timeout, const ::Ice::Context& __ctx)
    {
        return prepare(sheet, timeout, &__ctx);
    }
    
private:

    ::rd::CallResultT prepare(const ::rd::RdWorkSheetT&, ::Ice::Int, const ::Ice::Context*);
    
public:

    void end()
    {
        end(0);
    }
    void end(const ::Ice::Context& __ctx)
    {
        end(&__ctx);
    }
    
private:

    void end(const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<IRdFront> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdFront*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<IRdFront*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdFront> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdFront*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<IRdFront*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdFront> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdFront*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<IRdFront*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdFront> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdFront*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<IRdFront*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdFront> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdFront*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<IRdFront*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdFront> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdFront*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<IRdFront*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdFront> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdFront*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<IRdFront*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdFront> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdFront*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<IRdFront*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdFront> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdFront*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<IRdFront*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdFront> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdFront*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<IRdFront*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdFront> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdFront*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<IRdFront*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdFront> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdFront*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<IRdFront*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdFront> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdFront*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<IRdFront*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdFront> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdFront*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<IRdFront*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdFront> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdFront*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<IRdFront*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdFront> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdFront*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<IRdFront*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdFront> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdFront*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<IRdFront*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdFront> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdFront*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<IRdFront*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IRdFront> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IRdFront*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<IRdFront*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    #endif
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

}

}

namespace IceDelegate
{

namespace rd
{

class IService : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::std::string getSequence(const ::Ice::Context*) = 0;

    virtual ::std::string getType(const ::Ice::Context*) = 0;

    virtual ::std::string getId(const ::Ice::Context*) = 0;

    virtual ::Ice::Int getTimestamp(const ::Ice::Context*) = 0;

    virtual ::std::string getVersion(const ::Ice::Context*) = 0;
};

class IRdDispatcher : virtual public ::IceDelegate::rd::IService
{
public:

    virtual ::rd::PingTargetListT getPingList(const ::rd::RdPingerInfoT&, const ::Ice::Context*) = 0;

    virtual void completePing(const ::rd::RdPingerInfoT&, const ::rd::PingResultListT&, const ::Ice::Context*) = 0;

    virtual ::rd::RdServerInfoListT getBastRdServers(const ::std::string&, ::Ice::Int, const ::rd::RdFrontInfoT&, const ::Ice::Context*) = 0;

    virtual ::rd::CallResultT connectedRdServer(const ::rd::RdFrontInfoT&, const ::rd::RdServerInfoT&, const ::rd::RdWorkSheetT&, const ::Ice::Context*) = 0;

    virtual ::rd::CallResultT disconnectedRdServer(const ::rd::RdFrontInfoT&, const ::rd::RdServerInfoT&, const ::rd::RdWorkSheetT&, const ::Ice::Context*) = 0;
};

class IRdFront : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::rd::CallResultT prepare(const ::rd::RdWorkSheetT&, ::Ice::Int, const ::Ice::Context*) = 0;

    virtual void end(const ::Ice::Context*) = 0;
};

}

}

namespace IceDelegateM
{

namespace rd
{

class IService : virtual public ::IceDelegate::rd::IService,
                 virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::std::string getSequence(const ::Ice::Context*);

    virtual ::std::string getType(const ::Ice::Context*);

    virtual ::std::string getId(const ::Ice::Context*);

    virtual ::Ice::Int getTimestamp(const ::Ice::Context*);

    virtual ::std::string getVersion(const ::Ice::Context*);
};

class IRdDispatcher : virtual public ::IceDelegate::rd::IRdDispatcher,
                      virtual public ::IceDelegateM::rd::IService
{
public:

    virtual ::rd::PingTargetListT getPingList(const ::rd::RdPingerInfoT&, const ::Ice::Context*);

    virtual void completePing(const ::rd::RdPingerInfoT&, const ::rd::PingResultListT&, const ::Ice::Context*);

    virtual ::rd::RdServerInfoListT getBastRdServers(const ::std::string&, ::Ice::Int, const ::rd::RdFrontInfoT&, const ::Ice::Context*);

    virtual ::rd::CallResultT connectedRdServer(const ::rd::RdFrontInfoT&, const ::rd::RdServerInfoT&, const ::rd::RdWorkSheetT&, const ::Ice::Context*);

    virtual ::rd::CallResultT disconnectedRdServer(const ::rd::RdFrontInfoT&, const ::rd::RdServerInfoT&, const ::rd::RdWorkSheetT&, const ::Ice::Context*);
};

class IRdFront : virtual public ::IceDelegate::rd::IRdFront,
                 virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::rd::CallResultT prepare(const ::rd::RdWorkSheetT&, ::Ice::Int, const ::Ice::Context*);

    virtual void end(const ::Ice::Context*);
};

}

}

namespace IceDelegateD
{

namespace rd
{

class IService : virtual public ::IceDelegate::rd::IService,
                 virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::std::string getSequence(const ::Ice::Context*);

    virtual ::std::string getType(const ::Ice::Context*);

    virtual ::std::string getId(const ::Ice::Context*);

    virtual ::Ice::Int getTimestamp(const ::Ice::Context*);

    virtual ::std::string getVersion(const ::Ice::Context*);
};

class IRdDispatcher : virtual public ::IceDelegate::rd::IRdDispatcher,
                      virtual public ::IceDelegateD::rd::IService
{
public:

    virtual ::rd::PingTargetListT getPingList(const ::rd::RdPingerInfoT&, const ::Ice::Context*);

    virtual void completePing(const ::rd::RdPingerInfoT&, const ::rd::PingResultListT&, const ::Ice::Context*);

    virtual ::rd::RdServerInfoListT getBastRdServers(const ::std::string&, ::Ice::Int, const ::rd::RdFrontInfoT&, const ::Ice::Context*);

    virtual ::rd::CallResultT connectedRdServer(const ::rd::RdFrontInfoT&, const ::rd::RdServerInfoT&, const ::rd::RdWorkSheetT&, const ::Ice::Context*);

    virtual ::rd::CallResultT disconnectedRdServer(const ::rd::RdFrontInfoT&, const ::rd::RdServerInfoT&, const ::rd::RdWorkSheetT&, const ::Ice::Context*);
};

class IRdFront : virtual public ::IceDelegate::rd::IRdFront,
                 virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::rd::CallResultT prepare(const ::rd::RdWorkSheetT&, ::Ice::Int, const ::Ice::Context*);

    virtual void end(const ::Ice::Context*);
};

}

}

namespace rd
{

class IService : virtual public ::Ice::Object
{
public:

    typedef IServicePrx ProxyType;
    typedef IServicePtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::std::string getSequence(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getSequence(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::std::string getType(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getType(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::std::string getId(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getId(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Int getTimestamp(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getTimestamp(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::std::string getVersion(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getVersion(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class IRdDispatcher : virtual public ::rd::IService
{
public:

    typedef IRdDispatcherPrx ProxyType;
    typedef IRdDispatcherPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::rd::PingTargetListT getPingList(const ::rd::RdPingerInfoT&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getPingList(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void completePing(const ::rd::RdPingerInfoT&, const ::rd::PingResultListT&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___completePing(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::rd::RdServerInfoListT getBastRdServers(const ::std::string&, ::Ice::Int, const ::rd::RdFrontInfoT&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getBastRdServers(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::rd::CallResultT connectedRdServer(const ::rd::RdFrontInfoT&, const ::rd::RdServerInfoT&, const ::rd::RdWorkSheetT&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___connectedRdServer(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::rd::CallResultT disconnectedRdServer(const ::rd::RdFrontInfoT&, const ::rd::RdServerInfoT&, const ::rd::RdWorkSheetT&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___disconnectedRdServer(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class IRdFront : virtual public ::Ice::Object
{
public:

    typedef IRdFrontPrx ProxyType;
    typedef IRdFrontPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::rd::CallResultT prepare(const ::rd::RdWorkSheetT&, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___prepare(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void end(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___end(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

}

#endif
