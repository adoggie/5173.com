#ifndef _____ice_redirectI_h__
#define _____ice_redirectI_h__

#include <redirect.h>
#include <IServiceI.h>

namespace rd
{

class IServiceI : virtual public IService
{
public:

    virtual ::std::string getSequence(const Ice::Current&);

    virtual ::std::string getType(const Ice::Current&);

    virtual ::std::string getId(const Ice::Current&);

    virtual ::Ice::Int getTimestamp(const Ice::Current&);

    virtual ::std::string getVersion(const Ice::Current&);
};

class IRdDispatcherI : virtual public IRdDispatcher,
                       virtual public ::rd::IServiceI
{
public:

    virtual ::rd::PingTargetListT getPingList(const ::rd::RdPingerInfoT&,
                                              const Ice::Current&);

    virtual void completePing(const ::rd::RdPingerInfoT&,
                              const ::rd::PingResultListT&,
                              const Ice::Current&);

    virtual ::rd::RdServerInfoListT getBastRdServers(const ::std::string&,
                                                     ::Ice::Int,
                                                     const ::rd::RdFrontInfoT&,
                                                     const Ice::Current&);

    virtual ::rd::CallResultT connectedRdServer(const ::rd::RdFrontInfoT&,
                                                const ::rd::RdServerInfoT&,
                                                const ::rd::RdWorkSheetT&,
                                                const Ice::Current&);

    virtual ::rd::CallResultT disconnectedRdServer(const ::rd::RdFrontInfoT&,
                                                   const ::rd::RdServerInfoT&,
                                                   const ::rd::RdWorkSheetT&,
                                                   const Ice::Current&);
};

class IRdFrontI : virtual public IRdFront
{
public:

    virtual ::rd::CallResultT prepare(const ::rd::RdWorkSheetT&,
                                      ::Ice::Int,
                                      const Ice::Current&);

    virtual void end(const Ice::Current&);
};

}

#endif
