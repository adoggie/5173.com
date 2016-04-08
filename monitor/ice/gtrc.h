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

#ifndef _____ice_gtrc_h__
#define _____ice_gtrc_h__

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

namespace gtr
{

class IService;

class IQuestionServer;

class IAnswerEndpoint;

class IQuestionAsker;

class ILogger;

class ILogServer;

class IGameHost;

class IGtrServer;

}

}

namespace gtr
{

class IService;
bool operator==(const IService&, const IService&);
bool operator<(const IService&, const IService&);

class IQuestionServer;
bool operator==(const IQuestionServer&, const IQuestionServer&);
bool operator<(const IQuestionServer&, const IQuestionServer&);

class IAnswerEndpoint;
bool operator==(const IAnswerEndpoint&, const IAnswerEndpoint&);
bool operator<(const IAnswerEndpoint&, const IAnswerEndpoint&);

class IQuestionAsker;
bool operator==(const IQuestionAsker&, const IQuestionAsker&);
bool operator<(const IQuestionAsker&, const IQuestionAsker&);

class ILogger;
bool operator==(const ILogger&, const ILogger&);
bool operator<(const ILogger&, const ILogger&);

class ILogServer;
bool operator==(const ILogServer&, const ILogServer&);
bool operator<(const ILogServer&, const ILogServer&);

class IGameHost;
bool operator==(const IGameHost&, const IGameHost&);
bool operator<(const IGameHost&, const IGameHost&);

class IGtrServer;
bool operator==(const IGtrServer&, const IGtrServer&);
bool operator<(const IGtrServer&, const IGtrServer&);

}

namespace IceInternal
{

::Ice::Object* upCast(::gtr::IService*);
::IceProxy::Ice::Object* upCast(::IceProxy::gtr::IService*);

::Ice::Object* upCast(::gtr::IQuestionServer*);
::IceProxy::Ice::Object* upCast(::IceProxy::gtr::IQuestionServer*);

::Ice::Object* upCast(::gtr::IAnswerEndpoint*);
::IceProxy::Ice::Object* upCast(::IceProxy::gtr::IAnswerEndpoint*);

::Ice::Object* upCast(::gtr::IQuestionAsker*);
::IceProxy::Ice::Object* upCast(::IceProxy::gtr::IQuestionAsker*);

::Ice::Object* upCast(::gtr::ILogger*);
::IceProxy::Ice::Object* upCast(::IceProxy::gtr::ILogger*);

::Ice::Object* upCast(::gtr::ILogServer*);
::IceProxy::Ice::Object* upCast(::IceProxy::gtr::ILogServer*);

::Ice::Object* upCast(::gtr::IGameHost*);
::IceProxy::Ice::Object* upCast(::IceProxy::gtr::IGameHost*);

::Ice::Object* upCast(::gtr::IGtrServer*);
::IceProxy::Ice::Object* upCast(::IceProxy::gtr::IGtrServer*);

}

namespace gtr
{

typedef ::IceInternal::Handle< ::gtr::IService> IServicePtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::gtr::IService> IServicePrx;

void __read(::IceInternal::BasicStream*, IServicePrx&);
void __patch__IServicePtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::gtr::IQuestionServer> IQuestionServerPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::gtr::IQuestionServer> IQuestionServerPrx;

void __read(::IceInternal::BasicStream*, IQuestionServerPrx&);
void __patch__IQuestionServerPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::gtr::IAnswerEndpoint> IAnswerEndpointPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::gtr::IAnswerEndpoint> IAnswerEndpointPrx;

void __read(::IceInternal::BasicStream*, IAnswerEndpointPrx&);
void __patch__IAnswerEndpointPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::gtr::IQuestionAsker> IQuestionAskerPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::gtr::IQuestionAsker> IQuestionAskerPrx;

void __read(::IceInternal::BasicStream*, IQuestionAskerPrx&);
void __patch__IQuestionAskerPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::gtr::ILogger> ILoggerPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::gtr::ILogger> ILoggerPrx;

void __read(::IceInternal::BasicStream*, ILoggerPrx&);
void __patch__ILoggerPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::gtr::ILogServer> ILogServerPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::gtr::ILogServer> ILogServerPrx;

void __read(::IceInternal::BasicStream*, ILogServerPrx&);
void __patch__ILogServerPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::gtr::IGameHost> IGameHostPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::gtr::IGameHost> IGameHostPrx;

void __read(::IceInternal::BasicStream*, IGameHostPrx&);
void __patch__IGameHostPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::gtr::IGtrServer> IGtrServerPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::gtr::IGtrServer> IGtrServerPrx;

void __read(::IceInternal::BasicStream*, IGtrServerPrx&);
void __patch__IGtrServerPtr(void*, ::Ice::ObjectPtr&);

}

namespace gtr
{

typedef ::std::map< ::std::string, ::std::string> HashValueSet;
void __writeHashValueSet(::IceInternal::BasicStream*, const HashValueSet&);
void __readHashValueSet(::IceInternal::BasicStream*, HashValueSet&);

typedef ::std::map< ::std::string, ::std::string> ReturnValueT;
void __writeReturnValueT(::IceInternal::BasicStream*, const ReturnValueT&);
void __readReturnValueT(::IceInternal::BasicStream*, ReturnValueT&);

typedef ::std::vector< ::Ice::Byte> ByteStreamT;

typedef ::std::vector< ::std::string> StringListT;

typedef ::std::vector< ::gtr::HashValueSet> HashValueListT;
void __writeHashValueListT(::IceInternal::BasicStream*, const ::gtr::HashValueSet*, const ::gtr::HashValueSet*);
void __readHashValueListT(::IceInternal::BasicStream*, HashValueListT&);

typedef ::std::vector< ::Ice::Int> IntListT;

typedef ::std::vector< ::gtr::StringListT> StringListListT;
void __writeStringListListT(::IceInternal::BasicStream*, const ::gtr::StringListT*, const ::gtr::StringListT*);
void __readStringListListT(::IceInternal::BasicStream*, StringListListT&);

struct CallReturnT
{
    bool succ;
    ::std::string msg;
    ::gtr::HashValueSet props;

    bool operator==(const CallReturnT&) const;
    bool operator<(const CallReturnT&) const;
    bool operator!=(const CallReturnT& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const CallReturnT& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const CallReturnT& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const CallReturnT& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

const ::Ice::Int IMAGEJPEG = 1;

const ::Ice::Int IMAGEPNG = 2;

const ::Ice::Int IMAGEBMP = 3;

struct ImageDataT
{
    ::Ice::Int type;
    ::gtr::ByteStreamT bytes;
    ::Ice::Int width;
    ::Ice::Int height;

    bool operator==(const ImageDataT&) const;
    bool operator<(const ImageDataT&) const;
    bool operator!=(const ImageDataT& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const ImageDataT& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const ImageDataT& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const ImageDataT& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct GameAuthDataT
{
    ::Ice::Int type;
    ::gtr::ImageDataT image;
    ::std::string seckey;

    bool operator==(const GameAuthDataT&) const;
    bool operator<(const GameAuthDataT&) const;
    bool operator!=(const GameAuthDataT& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const GameAuthDataT& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const GameAuthDataT& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const GameAuthDataT& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct GameIdentifyT
{
    ::std::string id;
    ::std::string tradeNo;

    bool operator==(const GameIdentifyT&) const;
    bool operator<(const GameIdentifyT&) const;
    bool operator!=(const GameIdentifyT& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const GameIdentifyT& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const GameIdentifyT& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const GameIdentifyT& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct ServiceIdentifyT
{
    ::std::string id;
    ::std::string version;

    bool operator==(const ServiceIdentifyT&) const;
    bool operator<(const ServiceIdentifyT&) const;
    bool operator!=(const ServiceIdentifyT& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const ServiceIdentifyT& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const ServiceIdentifyT& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const ServiceIdentifyT& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct QuestionContentT
{
    ::Ice::Int type;
    ::gtr::ImageDataT image;
    ::gtr::ImageDataT image2;
    ::std::string text;
    ::Ice::Int cookie;
    ::std::string gameId;

    bool operator==(const QuestionContentT&) const;
    bool operator<(const QuestionContentT&) const;
    bool operator!=(const QuestionContentT& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const QuestionContentT& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const QuestionContentT& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const QuestionContentT& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct QuestionResultT
{
    ::std::string value;
    ::Ice::Int cookie;

    bool operator==(const QuestionResultT&) const;
    bool operator<(const QuestionResultT&) const;
    bool operator!=(const QuestionResultT& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const QuestionResultT& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const QuestionResultT& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const QuestionResultT& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct LogMessageT
{
    ::Ice::Int xclass;
    ::std::string msg;

    bool operator==(const LogMessageT&) const;
    bool operator<(const LogMessageT&) const;
    bool operator!=(const LogMessageT& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const LogMessageT& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const LogMessageT& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const LogMessageT& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

enum GameWorkSheetTypeT
{
    gwsPost,
    gwsAccountAudit,
    gwsVerify
};

void __write(::IceInternal::BasicStream*, GameWorkSheetTypeT);
void __read(::IceInternal::BasicStream*, GameWorkSheetTypeT&);

struct GameWorkSheetPostT
{
    ::std::string sellerActor;
    ::Ice::Int sellerLevel;
    ::Ice::Long money;
    ::Ice::Int transactionTime;
    ::std::string sellerSecondPwd;
    ::std::string buyerActor;
    ::Ice::Int buyerLevel;
    ::Ice::Long buyerMoney;
    ::Ice::Int sellerIndex;
    ::Ice::Int sellerGroup;
    ::std::string bankPwd;

    bool operator==(const GameWorkSheetPostT&) const;
    bool operator<(const GameWorkSheetPostT&) const;
    bool operator!=(const GameWorkSheetPostT& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const GameWorkSheetPostT& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const GameWorkSheetPostT& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const GameWorkSheetPostT& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct GameWorkSheetAccountAuditT
{
    ::std::string sellerActor;
    ::std::string sellerSecondPwd;
    ::Ice::Int sellerIndex;
    ::Ice::Int sellerGroup;
    ::std::string bankPwd;

    bool operator==(const GameWorkSheetAccountAuditT&) const;
    bool operator<(const GameWorkSheetAccountAuditT&) const;
    bool operator!=(const GameWorkSheetAccountAuditT& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const GameWorkSheetAccountAuditT& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const GameWorkSheetAccountAuditT& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const GameWorkSheetAccountAuditT& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct GameWorkSheetVerifyT
{
    ::std::string sellerActor;
    ::Ice::Int level;
    ::Ice::Long money;
    ::Ice::Int verifyTime;
    ::std::string sellerSecondPwd;
    ::Ice::Int sellerIndex;
    ::Ice::Int sellerGroup;
    ::std::string bankPwd;

    bool operator==(const GameWorkSheetVerifyT&) const;
    bool operator<(const GameWorkSheetVerifyT&) const;
    bool operator!=(const GameWorkSheetVerifyT& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const GameWorkSheetVerifyT& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const GameWorkSheetVerifyT& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const GameWorkSheetVerifyT& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct GameTaskletT
{
    ::std::string id;
    ::Ice::Int type;
    ::std::string no;
    ::std::string gameId;
    ::std::string account;
    ::std::string password;
    ::std::string area;
    ::std::string server;
    ::std::string lineName;
    ::Ice::Short lineNo;
    ::std::string createTime;
    ::std::string secretKey;
    ::gtr::GameWorkSheetPostT post;
    ::gtr::GameWorkSheetAccountAuditT audit;
    ::gtr::GameWorkSheetVerifyT verify;

    bool operator==(const GameTaskletT&) const;
    bool operator<(const GameTaskletT&) const;
    bool operator!=(const GameTaskletT& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const GameTaskletT& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const GameTaskletT& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const GameTaskletT& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct GameTaskResultT
{
    ::std::string id;
    ::std::string no;
    ::Ice::Int type;
    ::std::string gameId;
    ::Ice::Int result;
    ::std::string errmsg;

    bool operator==(const GameTaskResultT&) const;
    bool operator<(const GameTaskResultT&) const;
    bool operator!=(const GameTaskResultT& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const GameTaskResultT& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const GameTaskResultT& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const GameTaskResultT& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct GameInfoT
{
    ::Ice::Int id;
    ::std::string name;
    ::std::string version;

    bool operator==(const GameInfoT&) const;
    bool operator<(const GameInfoT&) const;
    bool operator!=(const GameInfoT& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const GameInfoT& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const GameInfoT& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const GameInfoT& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

typedef ::std::vector< ::gtr::GameInfoT> GameInfoListT;
void __writeGameInfoListT(::IceInternal::BasicStream*, const ::gtr::GameInfoT*, const ::gtr::GameInfoT*);
void __readGameInfoListT(::IceInternal::BasicStream*, GameInfoListT&);

struct GameRobotInfoT
{
    ::std::string id;
    ::std::string ip;
    ::Ice::Int network;
    ::gtr::GameInfoListT supportGames;

    bool operator==(const GameRobotInfoT&) const;
    bool operator<(const GameRobotInfoT&) const;
    bool operator!=(const GameRobotInfoT& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const GameRobotInfoT& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const GameRobotInfoT& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const GameRobotInfoT& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

}

namespace IceProxy
{

namespace gtr
{

class IService : virtual public ::IceProxy::Ice::Object
{
public:

    ::Ice::Int getType()
    {
        return getType(0);
    }
    ::Ice::Int getType(const ::Ice::Context& __ctx)
    {
        return getType(&__ctx);
    }
    
private:

    ::Ice::Int getType(const ::Ice::Context*);
    
public:

    ::gtr::ServiceIdentifyT getId()
    {
        return getId(0);
    }
    ::gtr::ServiceIdentifyT getId(const ::Ice::Context& __ctx)
    {
        return getId(&__ctx);
    }
    
private:

    ::gtr::ServiceIdentifyT getId(const ::Ice::Context*);
    
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

    void shutdown()
    {
        shutdown(0);
    }
    void shutdown(const ::Ice::Context& __ctx)
    {
        shutdown(&__ctx);
    }
    
private:

    void shutdown(const ::Ice::Context*);
    
public:

    void heartbeat(const ::std::string& senderType, const ::std::string& senderId)
    {
        heartbeat(senderType, senderId, 0);
    }
    void heartbeat(const ::std::string& senderType, const ::std::string& senderId, const ::Ice::Context& __ctx)
    {
        heartbeat(senderType, senderId, &__ctx);
    }
    
private:

    void heartbeat(const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
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

class IAnswerEndpoint : virtual public ::IceProxy::gtr::IService
{
public:

    ::Ice::Int getRemains()
    {
        return getRemains(0);
    }
    ::Ice::Int getRemains(const ::Ice::Context& __ctx)
    {
        return getRemains(&__ctx);
    }
    
private:

    ::Ice::Int getRemains(const ::Ice::Context*);
    
public:

    ::Ice::Int addQuestion(const ::gtr::IQuestionServerPrx& server, const ::std::string& no, const ::std::string& createTime, const ::gtr::QuestionContentT& question)
    {
        return addQuestion(server, no, createTime, question, 0);
    }
    ::Ice::Int addQuestion(const ::gtr::IQuestionServerPrx& server, const ::std::string& no, const ::std::string& createTime, const ::gtr::QuestionContentT& question, const ::Ice::Context& __ctx)
    {
        return addQuestion(server, no, createTime, question, &__ctx);
    }
    
private:

    ::Ice::Int addQuestion(const ::gtr::IQuestionServerPrx&, const ::std::string&, const ::std::string&, const ::gtr::QuestionContentT&, const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<IAnswerEndpoint> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IAnswerEndpoint*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<IAnswerEndpoint*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IAnswerEndpoint> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IAnswerEndpoint*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<IAnswerEndpoint*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IAnswerEndpoint> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IAnswerEndpoint*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<IAnswerEndpoint*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IAnswerEndpoint> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IAnswerEndpoint*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<IAnswerEndpoint*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IAnswerEndpoint> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IAnswerEndpoint*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<IAnswerEndpoint*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IAnswerEndpoint> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IAnswerEndpoint*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<IAnswerEndpoint*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IAnswerEndpoint> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IAnswerEndpoint*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<IAnswerEndpoint*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IAnswerEndpoint> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IAnswerEndpoint*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<IAnswerEndpoint*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IAnswerEndpoint> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IAnswerEndpoint*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<IAnswerEndpoint*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IAnswerEndpoint> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IAnswerEndpoint*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<IAnswerEndpoint*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IAnswerEndpoint> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IAnswerEndpoint*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<IAnswerEndpoint*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IAnswerEndpoint> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IAnswerEndpoint*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<IAnswerEndpoint*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IAnswerEndpoint> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IAnswerEndpoint*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<IAnswerEndpoint*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IAnswerEndpoint> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IAnswerEndpoint*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<IAnswerEndpoint*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IAnswerEndpoint> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IAnswerEndpoint*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<IAnswerEndpoint*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IAnswerEndpoint> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IAnswerEndpoint*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<IAnswerEndpoint*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IAnswerEndpoint> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IAnswerEndpoint*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<IAnswerEndpoint*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IAnswerEndpoint> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IAnswerEndpoint*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<IAnswerEndpoint*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IAnswerEndpoint> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IAnswerEndpoint*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<IAnswerEndpoint*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    #endif
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class IQuestionAsker : virtual public ::IceProxy::Ice::Object
{
public:

    void answerResult(const ::std::string& no, const ::std::string& result)
    {
        answerResult(no, result, 0);
    }
    void answerResult(const ::std::string& no, const ::std::string& result, const ::Ice::Context& __ctx)
    {
        answerResult(no, result, &__ctx);
    }
    
private:

    void answerResult(const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<IQuestionAsker> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionAsker*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<IQuestionAsker*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionAsker> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionAsker*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<IQuestionAsker*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionAsker> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionAsker*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<IQuestionAsker*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionAsker> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionAsker*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<IQuestionAsker*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionAsker> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionAsker*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<IQuestionAsker*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionAsker> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionAsker*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<IQuestionAsker*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionAsker> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionAsker*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<IQuestionAsker*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionAsker> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionAsker*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<IQuestionAsker*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionAsker> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionAsker*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<IQuestionAsker*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionAsker> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionAsker*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<IQuestionAsker*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionAsker> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionAsker*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<IQuestionAsker*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionAsker> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionAsker*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<IQuestionAsker*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionAsker> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionAsker*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<IQuestionAsker*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionAsker> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionAsker*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<IQuestionAsker*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionAsker> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionAsker*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<IQuestionAsker*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionAsker> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionAsker*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<IQuestionAsker*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionAsker> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionAsker*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<IQuestionAsker*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionAsker> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionAsker*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<IQuestionAsker*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionAsker> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionAsker*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<IQuestionAsker*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    #endif
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class IQuestionServer : virtual public ::IceProxy::Ice::Object
{
public:

    void answer(const ::gtr::IQuestionAskerPrx& asker, const ::std::string& no, const ::gtr::QuestionContentT& question)
    {
        answer(asker, no, question, 0);
    }
    void answer(const ::gtr::IQuestionAskerPrx& asker, const ::std::string& no, const ::gtr::QuestionContentT& question, const ::Ice::Context& __ctx)
    {
        answer(asker, no, question, &__ctx);
    }
    
private:

    void answer(const ::gtr::IQuestionAskerPrx&, const ::std::string&, const ::gtr::QuestionContentT&, const ::Ice::Context*);
    
public:

    void answerResult(const ::std::string& no, const ::gtr::QuestionResultT& result)
    {
        answerResult(no, result, 0);
    }
    void answerResult(const ::std::string& no, const ::gtr::QuestionResultT& result, const ::Ice::Context& __ctx)
    {
        answerResult(no, result, &__ctx);
    }
    
private:

    void answerResult(const ::std::string&, const ::gtr::QuestionResultT&, const ::Ice::Context*);
    
public:

    ::gtr::CallReturnT login(const ::gtr::IAnswerEndpointPrx& answer, const ::std::string& worker, const ::std::string& passwd)
    {
        return login(answer, worker, passwd, 0);
    }
    ::gtr::CallReturnT login(const ::gtr::IAnswerEndpointPrx& answer, const ::std::string& worker, const ::std::string& passwd, const ::Ice::Context& __ctx)
    {
        return login(answer, worker, passwd, &__ctx);
    }
    
private:

    ::gtr::CallReturnT login(const ::gtr::IAnswerEndpointPrx&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void logout(const ::gtr::IAnswerEndpointPrx& answer, const ::std::string& worker)
    {
        logout(answer, worker, 0);
    }
    void logout(const ::gtr::IAnswerEndpointPrx& answer, const ::std::string& worker, const ::Ice::Context& __ctx)
    {
        logout(answer, worker, &__ctx);
    }
    
private:

    void logout(const ::gtr::IAnswerEndpointPrx&, const ::std::string&, const ::Ice::Context*);
    
public:

    void verifyAnswer(const ::std::string& no, ::Ice::Int type, bool succ)
    {
        verifyAnswer(no, type, succ, 0);
    }
    void verifyAnswer(const ::std::string& no, ::Ice::Int type, bool succ, const ::Ice::Context& __ctx)
    {
        verifyAnswer(no, type, succ, &__ctx);
    }
    
private:

    void verifyAnswer(const ::std::string&, ::Ice::Int, bool, const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<IQuestionServer> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionServer*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<IQuestionServer*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionServer> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionServer*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<IQuestionServer*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionServer> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionServer*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<IQuestionServer*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionServer> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionServer*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<IQuestionServer*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionServer> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionServer*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<IQuestionServer*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionServer> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionServer*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<IQuestionServer*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionServer> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionServer*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<IQuestionServer*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionServer> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionServer*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<IQuestionServer*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionServer> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionServer*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<IQuestionServer*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionServer> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionServer*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<IQuestionServer*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionServer> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionServer*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<IQuestionServer*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionServer> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionServer*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<IQuestionServer*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionServer> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionServer*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<IQuestionServer*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionServer> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionServer*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<IQuestionServer*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionServer> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionServer*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<IQuestionServer*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionServer> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionServer*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<IQuestionServer*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionServer> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionServer*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<IQuestionServer*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionServer> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionServer*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<IQuestionServer*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IQuestionServer> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IQuestionServer*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<IQuestionServer*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    #endif
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class ILogger : virtual public ::IceProxy::Ice::Object
{
public:

    void gameMsg(const ::gtr::GameIdentifyT& gameId, ::Ice::Int timetick, const ::gtr::LogMessageT& msg)
    {
        gameMsg(gameId, timetick, msg, 0);
    }
    void gameMsg(const ::gtr::GameIdentifyT& gameId, ::Ice::Int timetick, const ::gtr::LogMessageT& msg, const ::Ice::Context& __ctx)
    {
        gameMsg(gameId, timetick, msg, &__ctx);
    }
    
private:

    void gameMsg(const ::gtr::GameIdentifyT&, ::Ice::Int, const ::gtr::LogMessageT&, const ::Ice::Context*);
    
public:

    void gameImage(const ::gtr::GameIdentifyT& gameId, ::Ice::Int timetick, const ::std::string& opName, const ::gtr::ImageDataT& image)
    {
        gameImage(gameId, timetick, opName, image, 0);
    }
    void gameImage(const ::gtr::GameIdentifyT& gameId, ::Ice::Int timetick, const ::std::string& opName, const ::gtr::ImageDataT& image, const ::Ice::Context& __ctx)
    {
        gameImage(gameId, timetick, opName, image, &__ctx);
    }
    
private:

    void gameImage(const ::gtr::GameIdentifyT&, ::Ice::Int, const ::std::string&, const ::gtr::ImageDataT&, const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<ILogger> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogger*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<ILogger*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogger> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogger*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<ILogger*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogger> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogger*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<ILogger*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogger> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogger*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<ILogger*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogger> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogger*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<ILogger*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogger> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogger*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<ILogger*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogger> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogger*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<ILogger*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogger> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogger*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<ILogger*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogger> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogger*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<ILogger*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogger> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogger*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<ILogger*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogger> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogger*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<ILogger*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogger> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogger*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<ILogger*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogger> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogger*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<ILogger*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogger> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogger*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<ILogger*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogger> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogger*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<ILogger*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogger> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogger*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<ILogger*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogger> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogger*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<ILogger*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogger> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogger*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<ILogger*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogger> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogger*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<ILogger*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    #endif
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class ILogServer : virtual public ::IceProxy::gtr::ILogger,
                   virtual public ::IceProxy::gtr::IService
{
public:
    
    ::IceInternal::ProxyHandle<ILogServer> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogServer*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<ILogServer*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogServer> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogServer*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<ILogServer*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogServer> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogServer*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<ILogServer*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogServer> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogServer*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<ILogServer*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogServer> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogServer*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<ILogServer*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogServer> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogServer*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<ILogServer*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogServer> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogServer*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<ILogServer*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogServer> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogServer*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<ILogServer*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogServer> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogServer*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<ILogServer*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogServer> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogServer*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<ILogServer*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogServer> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogServer*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<ILogServer*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogServer> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogServer*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<ILogServer*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogServer> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogServer*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<ILogServer*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogServer> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogServer*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<ILogServer*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogServer> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogServer*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<ILogServer*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogServer> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogServer*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<ILogServer*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogServer> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogServer*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<ILogServer*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogServer> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogServer*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<ILogServer*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ILogServer> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ILogServer*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<ILogServer*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    #endif
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class IGameHost : virtual public ::IceProxy::gtr::IQuestionAsker,
                  virtual public ::IceProxy::gtr::IService,
                  virtual public ::IceProxy::gtr::ILogger
{
public:

    ::gtr::GameTaskletT getTask()
    {
        return getTask(0);
    }
    ::gtr::GameTaskletT getTask(const ::Ice::Context& __ctx)
    {
        return getTask(&__ctx);
    }
    
private:

    ::gtr::GameTaskletT getTask(const ::Ice::Context*);
    
public:

    void completeTask(const ::gtr::GameTaskResultT& result)
    {
        completeTask(result, 0);
    }
    void completeTask(const ::gtr::GameTaskResultT& result, const ::Ice::Context& __ctx)
    {
        completeTask(result, &__ctx);
    }
    
private:

    void completeTask(const ::gtr::GameTaskResultT&, const ::Ice::Context*);
    
public:

    ::std::string answer(const ::gtr::QuestionContentT& question)
    {
        return answer(question, 0);
    }
    ::std::string answer(const ::gtr::QuestionContentT& question, const ::Ice::Context& __ctx)
    {
        return answer(question, &__ctx);
    }
    
private:

    ::std::string answer(const ::gtr::QuestionContentT&, const ::Ice::Context*);
    
public:

    void verifyAnswer(::Ice::Int type, bool succ)
    {
        verifyAnswer(type, succ, 0);
    }
    void verifyAnswer(::Ice::Int type, bool succ, const ::Ice::Context& __ctx)
    {
        verifyAnswer(type, succ, &__ctx);
    }
    
private:

    void verifyAnswer(::Ice::Int, bool, const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<IGameHost> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGameHost*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<IGameHost*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGameHost> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGameHost*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<IGameHost*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGameHost> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGameHost*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<IGameHost*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGameHost> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGameHost*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<IGameHost*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGameHost> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGameHost*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<IGameHost*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGameHost> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGameHost*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<IGameHost*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGameHost> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGameHost*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<IGameHost*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGameHost> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGameHost*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<IGameHost*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGameHost> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGameHost*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<IGameHost*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGameHost> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGameHost*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<IGameHost*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGameHost> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGameHost*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<IGameHost*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGameHost> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGameHost*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<IGameHost*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGameHost> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGameHost*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<IGameHost*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGameHost> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGameHost*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<IGameHost*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGameHost> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGameHost*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<IGameHost*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGameHost> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGameHost*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<IGameHost*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGameHost> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGameHost*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<IGameHost*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGameHost> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGameHost*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<IGameHost*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGameHost> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGameHost*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<IGameHost*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    #endif
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class IGtrServer : virtual public ::IceProxy::gtr::IService,
                   virtual public ::IceProxy::gtr::IQuestionServer
{
public:

    ::gtr::GameTaskletT getTask(const ::gtr::GameRobotInfoT& robot)
    {
        return getTask(robot, 0);
    }
    ::gtr::GameTaskletT getTask(const ::gtr::GameRobotInfoT& robot, const ::Ice::Context& __ctx)
    {
        return getTask(robot, &__ctx);
    }
    
private:

    ::gtr::GameTaskletT getTask(const ::gtr::GameRobotInfoT&, const ::Ice::Context*);
    
public:

    void completeTask(const ::gtr::GameTaskResultT& result)
    {
        completeTask(result, 0);
    }
    void completeTask(const ::gtr::GameTaskResultT& result, const ::Ice::Context& __ctx)
    {
        completeTask(result, &__ctx);
    }
    
private:

    void completeTask(const ::gtr::GameTaskResultT&, const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<IGtrServer> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGtrServer*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<IGtrServer*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGtrServer> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGtrServer*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<IGtrServer*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGtrServer> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGtrServer*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<IGtrServer*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGtrServer> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGtrServer*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<IGtrServer*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGtrServer> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGtrServer*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<IGtrServer*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGtrServer> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGtrServer*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<IGtrServer*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGtrServer> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGtrServer*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<IGtrServer*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGtrServer> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGtrServer*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<IGtrServer*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGtrServer> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGtrServer*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<IGtrServer*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGtrServer> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGtrServer*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<IGtrServer*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGtrServer> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGtrServer*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<IGtrServer*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGtrServer> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGtrServer*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<IGtrServer*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGtrServer> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGtrServer*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<IGtrServer*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGtrServer> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGtrServer*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<IGtrServer*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGtrServer> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGtrServer*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<IGtrServer*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGtrServer> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGtrServer*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<IGtrServer*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGtrServer> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGtrServer*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<IGtrServer*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGtrServer> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGtrServer*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<IGtrServer*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<IGtrServer> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<IGtrServer*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<IGtrServer*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
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

namespace gtr
{

class IService : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::Ice::Int getType(const ::Ice::Context*) = 0;

    virtual ::gtr::ServiceIdentifyT getId(const ::Ice::Context*) = 0;

    virtual ::Ice::Int getTimestamp(const ::Ice::Context*) = 0;

    virtual void shutdown(const ::Ice::Context*) = 0;

    virtual void heartbeat(const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;
};

class IAnswerEndpoint : virtual public ::IceDelegate::gtr::IService
{
public:

    virtual ::Ice::Int getRemains(const ::Ice::Context*) = 0;

    virtual ::Ice::Int addQuestion(const ::gtr::IQuestionServerPrx&, const ::std::string&, const ::std::string&, const ::gtr::QuestionContentT&, const ::Ice::Context*) = 0;
};

class IQuestionAsker : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void answerResult(const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;
};

class IQuestionServer : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void answer(const ::gtr::IQuestionAskerPrx&, const ::std::string&, const ::gtr::QuestionContentT&, const ::Ice::Context*) = 0;

    virtual void answerResult(const ::std::string&, const ::gtr::QuestionResultT&, const ::Ice::Context*) = 0;

    virtual ::gtr::CallReturnT login(const ::gtr::IAnswerEndpointPrx&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void logout(const ::gtr::IAnswerEndpointPrx&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void verifyAnswer(const ::std::string&, ::Ice::Int, bool, const ::Ice::Context*) = 0;
};

class ILogger : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void gameMsg(const ::gtr::GameIdentifyT&, ::Ice::Int, const ::gtr::LogMessageT&, const ::Ice::Context*) = 0;

    virtual void gameImage(const ::gtr::GameIdentifyT&, ::Ice::Int, const ::std::string&, const ::gtr::ImageDataT&, const ::Ice::Context*) = 0;
};

class ILogServer : virtual public ::IceDelegate::gtr::ILogger,
                   virtual public ::IceDelegate::gtr::IService
{
public:
};

class IGameHost : virtual public ::IceDelegate::gtr::IQuestionAsker,
                  virtual public ::IceDelegate::gtr::IService,
                  virtual public ::IceDelegate::gtr::ILogger
{
public:

    virtual ::gtr::GameTaskletT getTask(const ::Ice::Context*) = 0;

    virtual void completeTask(const ::gtr::GameTaskResultT&, const ::Ice::Context*) = 0;

    virtual ::std::string answer(const ::gtr::QuestionContentT&, const ::Ice::Context*) = 0;

    virtual void verifyAnswer(::Ice::Int, bool, const ::Ice::Context*) = 0;
};

class IGtrServer : virtual public ::IceDelegate::gtr::IService,
                   virtual public ::IceDelegate::gtr::IQuestionServer
{
public:

    virtual ::gtr::GameTaskletT getTask(const ::gtr::GameRobotInfoT&, const ::Ice::Context*) = 0;

    virtual void completeTask(const ::gtr::GameTaskResultT&, const ::Ice::Context*) = 0;
};

}

}

namespace IceDelegateM
{

namespace gtr
{

class IService : virtual public ::IceDelegate::gtr::IService,
                 virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::Ice::Int getType(const ::Ice::Context*);

    virtual ::gtr::ServiceIdentifyT getId(const ::Ice::Context*);

    virtual ::Ice::Int getTimestamp(const ::Ice::Context*);

    virtual void shutdown(const ::Ice::Context*);

    virtual void heartbeat(const ::std::string&, const ::std::string&, const ::Ice::Context*);
};

class IAnswerEndpoint : virtual public ::IceDelegate::gtr::IAnswerEndpoint,
                        virtual public ::IceDelegateM::gtr::IService
{
public:

    virtual ::Ice::Int getRemains(const ::Ice::Context*);

    virtual ::Ice::Int addQuestion(const ::gtr::IQuestionServerPrx&, const ::std::string&, const ::std::string&, const ::gtr::QuestionContentT&, const ::Ice::Context*);
};

class IQuestionAsker : virtual public ::IceDelegate::gtr::IQuestionAsker,
                       virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void answerResult(const ::std::string&, const ::std::string&, const ::Ice::Context*);
};

class IQuestionServer : virtual public ::IceDelegate::gtr::IQuestionServer,
                        virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void answer(const ::gtr::IQuestionAskerPrx&, const ::std::string&, const ::gtr::QuestionContentT&, const ::Ice::Context*);

    virtual void answerResult(const ::std::string&, const ::gtr::QuestionResultT&, const ::Ice::Context*);

    virtual ::gtr::CallReturnT login(const ::gtr::IAnswerEndpointPrx&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void logout(const ::gtr::IAnswerEndpointPrx&, const ::std::string&, const ::Ice::Context*);

    virtual void verifyAnswer(const ::std::string&, ::Ice::Int, bool, const ::Ice::Context*);
};

class ILogger : virtual public ::IceDelegate::gtr::ILogger,
                virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void gameMsg(const ::gtr::GameIdentifyT&, ::Ice::Int, const ::gtr::LogMessageT&, const ::Ice::Context*);

    virtual void gameImage(const ::gtr::GameIdentifyT&, ::Ice::Int, const ::std::string&, const ::gtr::ImageDataT&, const ::Ice::Context*);
};

class ILogServer : virtual public ::IceDelegate::gtr::ILogServer,
                   virtual public ::IceDelegateM::gtr::ILogger,
                   virtual public ::IceDelegateM::gtr::IService
{
public:
};

class IGameHost : virtual public ::IceDelegate::gtr::IGameHost,
                  virtual public ::IceDelegateM::gtr::IQuestionAsker,
                  virtual public ::IceDelegateM::gtr::IService,
                  virtual public ::IceDelegateM::gtr::ILogger
{
public:

    virtual ::gtr::GameTaskletT getTask(const ::Ice::Context*);

    virtual void completeTask(const ::gtr::GameTaskResultT&, const ::Ice::Context*);

    virtual ::std::string answer(const ::gtr::QuestionContentT&, const ::Ice::Context*);

    virtual void verifyAnswer(::Ice::Int, bool, const ::Ice::Context*);
};

class IGtrServer : virtual public ::IceDelegate::gtr::IGtrServer,
                   virtual public ::IceDelegateM::gtr::IService,
                   virtual public ::IceDelegateM::gtr::IQuestionServer
{
public:

    virtual ::gtr::GameTaskletT getTask(const ::gtr::GameRobotInfoT&, const ::Ice::Context*);

    virtual void completeTask(const ::gtr::GameTaskResultT&, const ::Ice::Context*);
};

}

}

namespace IceDelegateD
{

namespace gtr
{

class IService : virtual public ::IceDelegate::gtr::IService,
                 virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::Ice::Int getType(const ::Ice::Context*);

    virtual ::gtr::ServiceIdentifyT getId(const ::Ice::Context*);

    virtual ::Ice::Int getTimestamp(const ::Ice::Context*);

    virtual void shutdown(const ::Ice::Context*);

    virtual void heartbeat(const ::std::string&, const ::std::string&, const ::Ice::Context*);
};

class IAnswerEndpoint : virtual public ::IceDelegate::gtr::IAnswerEndpoint,
                        virtual public ::IceDelegateD::gtr::IService
{
public:

    virtual ::Ice::Int getRemains(const ::Ice::Context*);

    virtual ::Ice::Int addQuestion(const ::gtr::IQuestionServerPrx&, const ::std::string&, const ::std::string&, const ::gtr::QuestionContentT&, const ::Ice::Context*);
};

class IQuestionAsker : virtual public ::IceDelegate::gtr::IQuestionAsker,
                       virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void answerResult(const ::std::string&, const ::std::string&, const ::Ice::Context*);
};

class IQuestionServer : virtual public ::IceDelegate::gtr::IQuestionServer,
                        virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void answer(const ::gtr::IQuestionAskerPrx&, const ::std::string&, const ::gtr::QuestionContentT&, const ::Ice::Context*);

    virtual void answerResult(const ::std::string&, const ::gtr::QuestionResultT&, const ::Ice::Context*);

    virtual ::gtr::CallReturnT login(const ::gtr::IAnswerEndpointPrx&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void logout(const ::gtr::IAnswerEndpointPrx&, const ::std::string&, const ::Ice::Context*);

    virtual void verifyAnswer(const ::std::string&, ::Ice::Int, bool, const ::Ice::Context*);
};

class ILogger : virtual public ::IceDelegate::gtr::ILogger,
                virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void gameMsg(const ::gtr::GameIdentifyT&, ::Ice::Int, const ::gtr::LogMessageT&, const ::Ice::Context*);

    virtual void gameImage(const ::gtr::GameIdentifyT&, ::Ice::Int, const ::std::string&, const ::gtr::ImageDataT&, const ::Ice::Context*);
};

class ILogServer : virtual public ::IceDelegate::gtr::ILogServer,
                   virtual public ::IceDelegateD::gtr::ILogger,
                   virtual public ::IceDelegateD::gtr::IService
{
public:
};

class IGameHost : virtual public ::IceDelegate::gtr::IGameHost,
                  virtual public ::IceDelegateD::gtr::IQuestionAsker,
                  virtual public ::IceDelegateD::gtr::IService,
                  virtual public ::IceDelegateD::gtr::ILogger
{
public:

    virtual ::gtr::GameTaskletT getTask(const ::Ice::Context*);

    virtual void completeTask(const ::gtr::GameTaskResultT&, const ::Ice::Context*);

    virtual ::std::string answer(const ::gtr::QuestionContentT&, const ::Ice::Context*);

    virtual void verifyAnswer(::Ice::Int, bool, const ::Ice::Context*);
};

class IGtrServer : virtual public ::IceDelegate::gtr::IGtrServer,
                   virtual public ::IceDelegateD::gtr::IService,
                   virtual public ::IceDelegateD::gtr::IQuestionServer
{
public:

    virtual ::gtr::GameTaskletT getTask(const ::gtr::GameRobotInfoT&, const ::Ice::Context*);

    virtual void completeTask(const ::gtr::GameTaskResultT&, const ::Ice::Context*);
};

}

}

namespace gtr
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

    virtual ::Ice::Int getType(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getType(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::gtr::ServiceIdentifyT getId(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getId(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Int getTimestamp(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getTimestamp(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void shutdown(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___shutdown(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void heartbeat(const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___heartbeat(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class IAnswerEndpoint : virtual public ::gtr::IService
{
public:

    typedef IAnswerEndpointPrx ProxyType;
    typedef IAnswerEndpointPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::Ice::Int getRemains(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getRemains(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Int addQuestion(const ::gtr::IQuestionServerPrx&, const ::std::string&, const ::std::string&, const ::gtr::QuestionContentT&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___addQuestion(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class IQuestionAsker : virtual public ::Ice::Object
{
public:

    typedef IQuestionAskerPrx ProxyType;
    typedef IQuestionAskerPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void answerResult(const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___answerResult(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class IQuestionServer : virtual public ::Ice::Object
{
public:

    typedef IQuestionServerPrx ProxyType;
    typedef IQuestionServerPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void answer(const ::gtr::IQuestionAskerPrx&, const ::std::string&, const ::gtr::QuestionContentT&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___answer(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void answerResult(const ::std::string&, const ::gtr::QuestionResultT&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___answerResult(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::gtr::CallReturnT login(const ::gtr::IAnswerEndpointPrx&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___login(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void logout(const ::gtr::IAnswerEndpointPrx&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___logout(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void verifyAnswer(const ::std::string&, ::Ice::Int, bool, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___verifyAnswer(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class ILogger : virtual public ::Ice::Object
{
public:

    typedef ILoggerPrx ProxyType;
    typedef ILoggerPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void gameMsg(const ::gtr::GameIdentifyT&, ::Ice::Int, const ::gtr::LogMessageT&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___gameMsg(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void gameImage(const ::gtr::GameIdentifyT&, ::Ice::Int, const ::std::string&, const ::gtr::ImageDataT&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___gameImage(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class ILogServer : virtual public ::gtr::ILogger,
                   virtual public ::gtr::IService
{
public:

    typedef ILogServerPrx ProxyType;
    typedef ILogServerPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class IGameHost : virtual public ::gtr::IQuestionAsker,
                  virtual public ::gtr::IService,
                  virtual public ::gtr::ILogger
{
public:

    typedef IGameHostPrx ProxyType;
    typedef IGameHostPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::gtr::GameTaskletT getTask(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getTask(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void completeTask(const ::gtr::GameTaskResultT&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___completeTask(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::std::string answer(const ::gtr::QuestionContentT&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___answer(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void verifyAnswer(::Ice::Int, bool, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___verifyAnswer(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class IGtrServer : virtual public ::gtr::IService,
                   virtual public ::gtr::IQuestionServer
{
public:

    typedef IGtrServerPrx ProxyType;
    typedef IGtrServerPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::gtr::GameTaskletT getTask(const ::gtr::GameRobotInfoT&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getTask(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void completeTask(const ::gtr::GameTaskResultT&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___completeTask(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

}

#endif
