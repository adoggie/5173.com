
#include <redirectI.h>

::std::string
rd::IServiceI::getSequence(const Ice::Current& current)
{
    return ::std::string();
}

::std::string
rd::IServiceI::getType(const Ice::Current& current)
{
    return ::std::string();
}

::std::string
rd::IServiceI::getId(const Ice::Current& current)
{
    return ::std::string();
}

::Ice::Int
rd::IServiceI::getTimestamp(const Ice::Current& current)
{
    return 0;
}

::std::string
rd::IServiceI::getVersion(const Ice::Current& current)
{
    return ::std::string();
}

::rd::PingTargetListT
rd::IRdDispatcherI::getPingList(const ::rd::RdPingerInfoT& pinger,
                                const Ice::Current& current)
{
    return ::rd::PingTargetListT();
}

void
rd::IRdDispatcherI::completePing(const ::rd::RdPingerInfoT& pinger,
                                 const ::rd::PingResultListT& result,
                                 const Ice::Current& current)
{
}

::rd::RdServerInfoListT
rd::IRdDispatcherI::getBastRdServers(const ::std::string& areaName,
                                     ::Ice::Int reqnum,
                                     const ::rd::RdFrontInfoT& front,
                                     const Ice::Current& current)
{
    return ::rd::RdServerInfoListT();
}

::rd::CallResultT
rd::IRdDispatcherI::connectedRdServer(const ::rd::RdFrontInfoT& front,
                                      const ::rd::RdServerInfoT& server,
                                      const ::rd::RdWorkSheetT& sheet,
                                      const Ice::Current& current)
{
    return ::rd::CallResultT();
}

::rd::CallResultT
rd::IRdDispatcherI::disconnectedRdServer(const ::rd::RdFrontInfoT& front,
                                         const ::rd::RdServerInfoT& server,
                                         const ::rd::RdWorkSheetT& sheet,
                                         const Ice::Current& current)
{
    return ::rd::CallResultT();
}

::rd::CallResultT
rd::IRdFrontI::prepare(const ::rd::RdWorkSheetT& sheet,
                       ::Ice::Int timeout,
                       const Ice::Current& current)
{
    return ::rd::CallResultT();
}

void
rd::IRdFrontI::end(const Ice::Current& current)
{
}
