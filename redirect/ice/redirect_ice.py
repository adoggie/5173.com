# **********************************************************************
#
# Copyright (c) 2003-2009 ZeroC, Inc. All rights reserved.
#
# This copy of Ice is licensed to you under the terms described in the
# ICE_LICENSE file included in this distribution.
#
# **********************************************************************

# Ice version 3.3.1
# Generated from file `redirect.ice'

import Ice, IcePy, __builtin__

if not Ice.__dict__.has_key("_struct_marker"):
    Ice._struct_marker = object()

# Start of module rd
_M_rd = Ice.openModule('rd')
__name__ = 'rd'

if not _M_rd.__dict__.has_key('_t_HashValueSet'):
    _M_rd._t_HashValueSet = IcePy.defineDictionary('::rd::HashValueSet', (), IcePy._t_string, IcePy._t_string)

if not _M_rd.__dict__.has_key('_t_ReturnValueT'):
    _M_rd._t_ReturnValueT = IcePy.defineDictionary('::rd::ReturnValueT', (), IcePy._t_string, IcePy._t_string)

if not _M_rd.__dict__.has_key('_t_StreamDataT'):
    _M_rd._t_StreamDataT = IcePy.defineSequence('::rd::StreamDataT', (), IcePy._t_byte)

if not _M_rd.__dict__.has_key('_t_StringListT'):
    _M_rd._t_StringListT = IcePy.defineSequence('::rd::StringListT', (), IcePy._t_string)

if not _M_rd.__dict__.has_key('_t_HashValueListT'):
    _M_rd._t_HashValueListT = IcePy.defineSequence('::rd::HashValueListT', (), _M_rd._t_HashValueSet)

if not _M_rd.__dict__.has_key('_t_IntListT'):
    _M_rd._t_IntListT = IcePy.defineSequence('::rd::IntListT', (), IcePy._t_int)

if not _M_rd.__dict__.has_key('_t_StringListListT'):
    _M_rd._t_StringListListT = IcePy.defineSequence('::rd::StringListListT', (), _M_rd._t_StringListT)

if not _M_rd.__dict__.has_key('CallResultT'):
    _M_rd.CallResultT = Ice.createTempClass()
    class CallResultT(object):
        def __init__(self, succ=False, errNo=0, msg=''):
            self.succ = succ
            self.errNo = errNo
            self.msg = msg

        def __hash__(self):
            _h = 0
            _h = 5 * _h + __builtin__.hash(self.succ)
            _h = 5 * _h + __builtin__.hash(self.errNo)
            _h = 5 * _h + __builtin__.hash(self.msg)
            return _h % 0x7fffffff

        def __cmp__(self, other):
            if other == None:
                return 1
            if self.succ < other.succ:
                return -1
            elif self.succ > other.succ:
                return 1
            if self.errNo < other.errNo:
                return -1
            elif self.errNo > other.errNo:
                return 1
            if self.msg < other.msg:
                return -1
            elif self.msg > other.msg:
                return 1
            return 0

        def __str__(self):
            return IcePy.stringify(self, _M_rd._t_CallResultT)

        __repr__ = __str__

    _M_rd._t_CallResultT = IcePy.defineStruct('::rd::CallResultT', CallResultT, (), (
        ('succ', (), IcePy._t_bool),
        ('errNo', (), IcePy._t_int),
        ('msg', (), IcePy._t_string)
    ))

    _M_rd.CallResultT = CallResultT
    del CallResultT

if not _M_rd.__dict__.has_key('IService'):
    _M_rd.IService = Ice.createTempClass()
    class IService(Ice.Object):
        def __init__(self):
            if __builtin__.type(self) == _M_rd.IService:
                raise RuntimeError('rd.IService is an abstract class')

        def ice_ids(self, current=None):
            return ('::Ice::Object', '::rd::IService')

        def ice_id(self, current=None):
            return '::rd::IService'

        def ice_staticId():
            return '::rd::IService'
        ice_staticId = staticmethod(ice_staticId)

        #
        # Operation signatures.
        #
        # def getSequence(self, current=None):
        # def getType(self, current=None):
        # def getId(self, current=None):
        # def getTimestamp(self, current=None):
        # def getVersion(self, current=None):

        def __str__(self):
            return IcePy.stringify(self, _M_rd._t_IService)

        __repr__ = __str__

    _M_rd.IServicePrx = Ice.createTempClass()
    class IServicePrx(Ice.ObjectPrx):

        def getSequence(self, _ctx=None):
            return _M_rd.IService._op_getSequence.invoke(self, ((), _ctx))

        def getType(self, _ctx=None):
            return _M_rd.IService._op_getType.invoke(self, ((), _ctx))

        def getId(self, _ctx=None):
            return _M_rd.IService._op_getId.invoke(self, ((), _ctx))

        def getTimestamp(self, _ctx=None):
            return _M_rd.IService._op_getTimestamp.invoke(self, ((), _ctx))

        def getVersion(self, _ctx=None):
            return _M_rd.IService._op_getVersion.invoke(self, ((), _ctx))

        def checkedCast(proxy, facetOrCtx=None, _ctx=None):
            return _M_rd.IServicePrx.ice_checkedCast(proxy, '::rd::IService', facetOrCtx, _ctx)
        checkedCast = staticmethod(checkedCast)

        def uncheckedCast(proxy, facet=None):
            return _M_rd.IServicePrx.ice_uncheckedCast(proxy, facet)
        uncheckedCast = staticmethod(uncheckedCast)

    _M_rd._t_IServicePrx = IcePy.defineProxy('::rd::IService', IServicePrx)

    _M_rd._t_IService = IcePy.defineClass('::rd::IService', IService, (), True, None, (), ())
    IService.ice_type = _M_rd._t_IService

    IService._op_getSequence = IcePy.Operation('getSequence', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (), (), IcePy._t_string, ())
    IService._op_getType = IcePy.Operation('getType', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (), (), IcePy._t_string, ())
    IService._op_getId = IcePy.Operation('getId', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (), (), IcePy._t_string, ())
    IService._op_getTimestamp = IcePy.Operation('getTimestamp', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (), (), IcePy._t_int, ())
    IService._op_getVersion = IcePy.Operation('getVersion', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (), (), IcePy._t_string, ())

    _M_rd.IService = IService
    del IService

    _M_rd.IServicePrx = IServicePrx
    del IServicePrx

if not _M_rd.__dict__.has_key('PingTargetT'):
    _M_rd.PingTargetT = Ice.createTempClass()
    class PingTargetT(object):
        def __init__(self, netaddr=0):
            self.netaddr = netaddr

        def __hash__(self):
            _h = 0
            _h = 5 * _h + __builtin__.hash(self.netaddr)
            return _h % 0x7fffffff

        def __cmp__(self, other):
            if other == None:
                return 1
            if self.netaddr < other.netaddr:
                return -1
            elif self.netaddr > other.netaddr:
                return 1
            return 0

        def __str__(self):
            return IcePy.stringify(self, _M_rd._t_PingTargetT)

        __repr__ = __str__

    _M_rd._t_PingTargetT = IcePy.defineStruct('::rd::PingTargetT', PingTargetT, (), (('netaddr', (), IcePy._t_int),))

    _M_rd.PingTargetT = PingTargetT
    del PingTargetT

if not _M_rd.__dict__.has_key('_t_PingTargetListT'):
    _M_rd._t_PingTargetListT = IcePy.defineSequence('::rd::PingTargetListT', (), _M_rd._t_PingTargetT)

if not _M_rd.__dict__.has_key('PingResultT'):
    _M_rd.PingResultT = Ice.createTempClass()
    class PingResultT(object):
        def __init__(self, netaddr=0, responseTime=0, timetick=0):
            self.netaddr = netaddr
            self.responseTime = responseTime
            self.timetick = timetick

        def __hash__(self):
            _h = 0
            _h = 5 * _h + __builtin__.hash(self.netaddr)
            _h = 5 * _h + __builtin__.hash(self.responseTime)
            _h = 5 * _h + __builtin__.hash(self.timetick)
            return _h % 0x7fffffff

        def __cmp__(self, other):
            if other == None:
                return 1
            if self.netaddr < other.netaddr:
                return -1
            elif self.netaddr > other.netaddr:
                return 1
            if self.responseTime < other.responseTime:
                return -1
            elif self.responseTime > other.responseTime:
                return 1
            if self.timetick < other.timetick:
                return -1
            elif self.timetick > other.timetick:
                return 1
            return 0

        def __str__(self):
            return IcePy.stringify(self, _M_rd._t_PingResultT)

        __repr__ = __str__

    _M_rd._t_PingResultT = IcePy.defineStruct('::rd::PingResultT', PingResultT, (), (
        ('netaddr', (), IcePy._t_int),
        ('responseTime', (), IcePy._t_int),
        ('timetick', (), IcePy._t_int)
    ))

    _M_rd.PingResultT = PingResultT
    del PingResultT

if not _M_rd.__dict__.has_key('_t_PingResultListT'):
    _M_rd._t_PingResultListT = IcePy.defineSequence('::rd::PingResultListT', (), _M_rd._t_PingResultT)

if not _M_rd.__dict__.has_key('RdPingerInfoT'):
    _M_rd.RdPingerInfoT = Ice.createTempClass()
    class RdPingerInfoT(object):
        def __init__(self, id='', ip=''):
            self.id = id
            self.ip = ip

        def __hash__(self):
            _h = 0
            _h = 5 * _h + __builtin__.hash(self.id)
            _h = 5 * _h + __builtin__.hash(self.ip)
            return _h % 0x7fffffff

        def __cmp__(self, other):
            if other == None:
                return 1
            if self.id < other.id:
                return -1
            elif self.id > other.id:
                return 1
            if self.ip < other.ip:
                return -1
            elif self.ip > other.ip:
                return 1
            return 0

        def __str__(self):
            return IcePy.stringify(self, _M_rd._t_RdPingerInfoT)

        __repr__ = __str__

    _M_rd._t_RdPingerInfoT = IcePy.defineStruct('::rd::RdPingerInfoT', RdPingerInfoT, (), (
        ('id', (), IcePy._t_string),
        ('ip', (), IcePy._t_string)
    ))

    _M_rd.RdPingerInfoT = RdPingerInfoT
    del RdPingerInfoT

if not _M_rd.__dict__.has_key('RdServerInfoT'):
    _M_rd.RdServerInfoT = Ice.createTempClass()
    class RdServerInfoT(object):
        def __init__(self, ip='', port=0, mac=''):
            self.ip = ip
            self.port = port
            self.mac = mac

        def __hash__(self):
            _h = 0
            _h = 5 * _h + __builtin__.hash(self.ip)
            _h = 5 * _h + __builtin__.hash(self.port)
            _h = 5 * _h + __builtin__.hash(self.mac)
            return _h % 0x7fffffff

        def __cmp__(self, other):
            if other == None:
                return 1
            if self.ip < other.ip:
                return -1
            elif self.ip > other.ip:
                return 1
            if self.port < other.port:
                return -1
            elif self.port > other.port:
                return 1
            if self.mac < other.mac:
                return -1
            elif self.mac > other.mac:
                return 1
            return 0

        def __str__(self):
            return IcePy.stringify(self, _M_rd._t_RdServerInfoT)

        __repr__ = __str__

    _M_rd._t_RdServerInfoT = IcePy.defineStruct('::rd::RdServerInfoT', RdServerInfoT, (), (
        ('ip', (), IcePy._t_string),
        ('port', (), IcePy._t_int),
        ('mac', (), IcePy._t_string)
    ))

    _M_rd.RdServerInfoT = RdServerInfoT
    del RdServerInfoT

if not _M_rd.__dict__.has_key('_t_RdServerInfoListT'):
    _M_rd._t_RdServerInfoListT = IcePy.defineSequence('::rd::RdServerInfoListT', (), _M_rd._t_RdServerInfoT)

if not _M_rd.__dict__.has_key('RdFrontInfoT'):
    _M_rd.RdFrontInfoT = Ice.createTempClass()
    class RdFrontInfoT(object):
        def __init__(self, id='', ip=''):
            self.id = id
            self.ip = ip

        def __hash__(self):
            _h = 0
            _h = 5 * _h + __builtin__.hash(self.id)
            _h = 5 * _h + __builtin__.hash(self.ip)
            return _h % 0x7fffffff

        def __cmp__(self, other):
            if other == None:
                return 1
            if self.id < other.id:
                return -1
            elif self.id > other.id:
                return 1
            if self.ip < other.ip:
                return -1
            elif self.ip > other.ip:
                return 1
            return 0

        def __str__(self):
            return IcePy.stringify(self, _M_rd._t_RdFrontInfoT)

        __repr__ = __str__

    _M_rd._t_RdFrontInfoT = IcePy.defineStruct('::rd::RdFrontInfoT', RdFrontInfoT, (), (
        ('id', (), IcePy._t_string),
        ('ip', (), IcePy._t_string)
    ))

    _M_rd.RdFrontInfoT = RdFrontInfoT
    del RdFrontInfoT

if not _M_rd.__dict__.has_key('RdWorkSheetT'):
    _M_rd.RdWorkSheetT = Ice.createTempClass()
    class RdWorkSheetT(object):
        def __init__(self, areaName='', tradeNo='', gameId=0):
            self.areaName = areaName
            self.tradeNo = tradeNo
            self.gameId = gameId

        def __hash__(self):
            _h = 0
            _h = 5 * _h + __builtin__.hash(self.areaName)
            _h = 5 * _h + __builtin__.hash(self.tradeNo)
            _h = 5 * _h + __builtin__.hash(self.gameId)
            return _h % 0x7fffffff

        def __cmp__(self, other):
            if other == None:
                return 1
            if self.areaName < other.areaName:
                return -1
            elif self.areaName > other.areaName:
                return 1
            if self.tradeNo < other.tradeNo:
                return -1
            elif self.tradeNo > other.tradeNo:
                return 1
            if self.gameId < other.gameId:
                return -1
            elif self.gameId > other.gameId:
                return 1
            return 0

        def __str__(self):
            return IcePy.stringify(self, _M_rd._t_RdWorkSheetT)

        __repr__ = __str__

    _M_rd._t_RdWorkSheetT = IcePy.defineStruct('::rd::RdWorkSheetT', RdWorkSheetT, (), (
        ('areaName', (), IcePy._t_string),
        ('tradeNo', (), IcePy._t_string),
        ('gameId', (), IcePy._t_int)
    ))

    _M_rd.RdWorkSheetT = RdWorkSheetT
    del RdWorkSheetT

if not _M_rd.__dict__.has_key('IRdDispatcher'):
    _M_rd.IRdDispatcher = Ice.createTempClass()
    class IRdDispatcher(_M_rd.IService):
        def __init__(self):
            if __builtin__.type(self) == _M_rd.IRdDispatcher:
                raise RuntimeError('rd.IRdDispatcher is an abstract class')

        def ice_ids(self, current=None):
            return ('::Ice::Object', '::rd::IRdDispatcher', '::rd::IService')

        def ice_id(self, current=None):
            return '::rd::IRdDispatcher'

        def ice_staticId():
            return '::rd::IRdDispatcher'
        ice_staticId = staticmethod(ice_staticId)

        #
        # Operation signatures.
        #
        # def getPingList(self, pinger, current=None):
        # def completePing(self, pinger, result, current=None):
        # def getBastRdServers(self, areaName, reqnum, front, current=None):
        # def connectedRdServer(self, front, server, sheet, current=None):
        # def disconnectedRdServer(self, front, server, sheet, current=None):

        def __str__(self):
            return IcePy.stringify(self, _M_rd._t_IRdDispatcher)

        __repr__ = __str__

    _M_rd.IRdDispatcherPrx = Ice.createTempClass()
    class IRdDispatcherPrx(_M_rd.IServicePrx):

        def getPingList(self, pinger, _ctx=None):
            return _M_rd.IRdDispatcher._op_getPingList.invoke(self, ((pinger, ), _ctx))

        def completePing(self, pinger, result, _ctx=None):
            return _M_rd.IRdDispatcher._op_completePing.invoke(self, ((pinger, result), _ctx))

        def getBastRdServers(self, areaName, reqnum, front, _ctx=None):
            return _M_rd.IRdDispatcher._op_getBastRdServers.invoke(self, ((areaName, reqnum, front), _ctx))

        def connectedRdServer(self, front, server, sheet, _ctx=None):
            return _M_rd.IRdDispatcher._op_connectedRdServer.invoke(self, ((front, server, sheet), _ctx))

        def disconnectedRdServer(self, front, server, sheet, _ctx=None):
            return _M_rd.IRdDispatcher._op_disconnectedRdServer.invoke(self, ((front, server, sheet), _ctx))

        def checkedCast(proxy, facetOrCtx=None, _ctx=None):
            return _M_rd.IRdDispatcherPrx.ice_checkedCast(proxy, '::rd::IRdDispatcher', facetOrCtx, _ctx)
        checkedCast = staticmethod(checkedCast)

        def uncheckedCast(proxy, facet=None):
            return _M_rd.IRdDispatcherPrx.ice_uncheckedCast(proxy, facet)
        uncheckedCast = staticmethod(uncheckedCast)

    _M_rd._t_IRdDispatcherPrx = IcePy.defineProxy('::rd::IRdDispatcher', IRdDispatcherPrx)

    _M_rd._t_IRdDispatcher = IcePy.defineClass('::rd::IRdDispatcher', IRdDispatcher, (), True, None, (_M_rd._t_IService,), ())
    IRdDispatcher.ice_type = _M_rd._t_IRdDispatcher

    IRdDispatcher._op_getPingList = IcePy.Operation('getPingList', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), _M_rd._t_RdPingerInfoT),), (), _M_rd._t_PingTargetListT, ())
    IRdDispatcher._op_completePing = IcePy.Operation('completePing', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), _M_rd._t_RdPingerInfoT), ((), _M_rd._t_PingResultListT)), (), None, ())
    IRdDispatcher._op_getBastRdServers = IcePy.Operation('getBastRdServers', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), IcePy._t_string), ((), IcePy._t_int), ((), _M_rd._t_RdFrontInfoT)), (), _M_rd._t_RdServerInfoListT, ())
    IRdDispatcher._op_connectedRdServer = IcePy.Operation('connectedRdServer', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), _M_rd._t_RdFrontInfoT), ((), _M_rd._t_RdServerInfoT), ((), _M_rd._t_RdWorkSheetT)), (), _M_rd._t_CallResultT, ())
    IRdDispatcher._op_disconnectedRdServer = IcePy.Operation('disconnectedRdServer', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), _M_rd._t_RdFrontInfoT), ((), _M_rd._t_RdServerInfoT), ((), _M_rd._t_RdWorkSheetT)), (), _M_rd._t_CallResultT, ())

    _M_rd.IRdDispatcher = IRdDispatcher
    del IRdDispatcher

    _M_rd.IRdDispatcherPrx = IRdDispatcherPrx
    del IRdDispatcherPrx

if not _M_rd.__dict__.has_key('IRdFront'):
    _M_rd.IRdFront = Ice.createTempClass()
    class IRdFront(Ice.Object):
        def __init__(self):
            if __builtin__.type(self) == _M_rd.IRdFront:
                raise RuntimeError('rd.IRdFront is an abstract class')

        def ice_ids(self, current=None):
            return ('::Ice::Object', '::rd::IRdFront')

        def ice_id(self, current=None):
            return '::rd::IRdFront'

        def ice_staticId():
            return '::rd::IRdFront'
        ice_staticId = staticmethod(ice_staticId)

        #
        # Operation signatures.
        #
        # def prepare(self, sheet, timeout, current=None):
        # def end(self, current=None):

        def __str__(self):
            return IcePy.stringify(self, _M_rd._t_IRdFront)

        __repr__ = __str__

    _M_rd.IRdFrontPrx = Ice.createTempClass()
    class IRdFrontPrx(Ice.ObjectPrx):

        def prepare(self, sheet, timeout, _ctx=None):
            return _M_rd.IRdFront._op_prepare.invoke(self, ((sheet, timeout), _ctx))

        def end(self, _ctx=None):
            return _M_rd.IRdFront._op_end.invoke(self, ((), _ctx))

        def checkedCast(proxy, facetOrCtx=None, _ctx=None):
            return _M_rd.IRdFrontPrx.ice_checkedCast(proxy, '::rd::IRdFront', facetOrCtx, _ctx)
        checkedCast = staticmethod(checkedCast)

        def uncheckedCast(proxy, facet=None):
            return _M_rd.IRdFrontPrx.ice_uncheckedCast(proxy, facet)
        uncheckedCast = staticmethod(uncheckedCast)

    _M_rd._t_IRdFrontPrx = IcePy.defineProxy('::rd::IRdFront', IRdFrontPrx)

    _M_rd._t_IRdFront = IcePy.defineClass('::rd::IRdFront', IRdFront, (), True, None, (), ())
    IRdFront.ice_type = _M_rd._t_IRdFront

    IRdFront._op_prepare = IcePy.Operation('prepare', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), _M_rd._t_RdWorkSheetT), ((), IcePy._t_int)), (), _M_rd._t_CallResultT, ())
    IRdFront._op_end = IcePy.Operation('end', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (), (), None, ())

    _M_rd.IRdFront = IRdFront
    del IRdFront

    _M_rd.IRdFrontPrx = IRdFrontPrx
    del IRdFrontPrx

# End of module rd
