# **********************************************************************
#
# Copyright (c) 2003-2009 ZeroC, Inc. All rights reserved.
#
# This copy of Ice is licensed to you under the terms described in the
# ICE_LICENSE file included in this distribution.
#
# **********************************************************************

# Ice version 3.3.1
# Generated from file `sync.ice'

import Ice, IcePy, __builtin__

if not Ice.__dict__.has_key("_struct_marker"):
    Ice._struct_marker = object()

# Start of module games
_M_games = Ice.openModule('games')
__name__ = 'games'

if not _M_games.__dict__.has_key('_t_HashValueSet'):
    _M_games._t_HashValueSet = IcePy.defineDictionary('::games::HashValueSet', (), IcePy._t_string, IcePy._t_string)

if not _M_games.__dict__.has_key('_t_ReturnValueT'):
    _M_games._t_ReturnValueT = IcePy.defineDictionary('::games::ReturnValueT', (), IcePy._t_string, IcePy._t_string)

if not _M_games.__dict__.has_key('_t_StreamDataT'):
    _M_games._t_StreamDataT = IcePy.defineSequence('::games::StreamDataT', (), IcePy._t_byte)

if not _M_games.__dict__.has_key('_t_StringListT'):
    _M_games._t_StringListT = IcePy.defineSequence('::games::StringListT', (), IcePy._t_string)

if not _M_games.__dict__.has_key('_t_HashValueListT'):
    _M_games._t_HashValueListT = IcePy.defineSequence('::games::HashValueListT', (), _M_games._t_HashValueSet)

if not _M_games.__dict__.has_key('_t_IntListT'):
    _M_games._t_IntListT = IcePy.defineSequence('::games::IntListT', (), IcePy._t_int)

if not _M_games.__dict__.has_key('_t_StringListListT'):
    _M_games._t_StringListListT = IcePy.defineSequence('::games::StringListListT', (), _M_games._t_StringListT)

if not _M_games.__dict__.has_key('IService'):
    _M_games.IService = Ice.createTempClass()
    class IService(Ice.Object):
        def __init__(self):
            if __builtin__.type(self) == _M_games.IService:
                raise RuntimeError('games.IService is an abstract class')

        def ice_ids(self, current=None):
            return ('::Ice::Object', '::games::IService')

        def ice_id(self, current=None):
            return '::games::IService'

        def ice_staticId():
            return '::games::IService'
        ice_staticId = staticmethod(ice_staticId)

        #
        # Operation signatures.
        #
        # def invokeOneway(self, value, stream, current=None):
        # def getSequence(self, current=None):
        # def getType(self, current=None):
        # def getId(self, current=None):
        # def getTimestamp(self, current=None):
        # def getVersion(self, current=None):

        def __str__(self):
            return IcePy.stringify(self, _M_games._t_IService)

        __repr__ = __str__

    _M_games.IServicePrx = Ice.createTempClass()
    class IServicePrx(Ice.ObjectPrx):

        def invokeOneway(self, value, stream, _ctx=None):
            return _M_games.IService._op_invokeOneway.invoke(self, ((value, stream), _ctx))

        def getSequence(self, _ctx=None):
            return _M_games.IService._op_getSequence.invoke(self, ((), _ctx))

        def getType(self, _ctx=None):
            return _M_games.IService._op_getType.invoke(self, ((), _ctx))

        def getId(self, _ctx=None):
            return _M_games.IService._op_getId.invoke(self, ((), _ctx))

        def getTimestamp(self, _ctx=None):
            return _M_games.IService._op_getTimestamp.invoke(self, ((), _ctx))

        def getVersion(self, _ctx=None):
            return _M_games.IService._op_getVersion.invoke(self, ((), _ctx))

        def checkedCast(proxy, facetOrCtx=None, _ctx=None):
            return _M_games.IServicePrx.ice_checkedCast(proxy, '::games::IService', facetOrCtx, _ctx)
        checkedCast = staticmethod(checkedCast)

        def uncheckedCast(proxy, facet=None):
            return _M_games.IServicePrx.ice_uncheckedCast(proxy, facet)
        uncheckedCast = staticmethod(uncheckedCast)

    _M_games._t_IServicePrx = IcePy.defineProxy('::games::IService', IServicePrx)

    _M_games._t_IService = IcePy.defineClass('::games::IService', IService, (), True, None, (), ())
    IService.ice_type = _M_games._t_IService

    IService._op_invokeOneway = IcePy.Operation('invokeOneway', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), _M_games._t_HashValueSet), ((), _M_games._t_StreamDataT)), (), None, ())
    IService._op_getSequence = IcePy.Operation('getSequence', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (), (), IcePy._t_string, ())
    IService._op_getType = IcePy.Operation('getType', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (), (), IcePy._t_string, ())
    IService._op_getId = IcePy.Operation('getId', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (), (), IcePy._t_string, ())
    IService._op_getTimestamp = IcePy.Operation('getTimestamp', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (), (), IcePy._t_int, ())
    IService._op_getVersion = IcePy.Operation('getVersion', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (), (), IcePy._t_string, ())

    _M_games.IService = IService
    del IService

    _M_games.IServicePrx = IServicePrx
    del IServicePrx

if not _M_games.__dict__.has_key('FileEntryT'):
    _M_games.FileEntryT = Ice.createTempClass()
    class FileEntryT(object):
        def __init__(self, filename='', size=0, timestamp=0, digest=''):
            self.filename = filename
            self.size = size
            self.timestamp = timestamp
            self.digest = digest

        def __hash__(self):
            _h = 0
            _h = 5 * _h + __builtin__.hash(self.filename)
            _h = 5 * _h + __builtin__.hash(self.size)
            _h = 5 * _h + __builtin__.hash(self.timestamp)
            _h = 5 * _h + __builtin__.hash(self.digest)
            return _h % 0x7fffffff

        def __cmp__(self, other):
            if other == None:
                return 1
            if self.filename < other.filename:
                return -1
            elif self.filename > other.filename:
                return 1
            if self.size < other.size:
                return -1
            elif self.size > other.size:
                return 1
            if self.timestamp < other.timestamp:
                return -1
            elif self.timestamp > other.timestamp:
                return 1
            if self.digest < other.digest:
                return -1
            elif self.digest > other.digest:
                return 1
            return 0

        def __str__(self):
            return IcePy.stringify(self, _M_games._t_FileEntryT)

        __repr__ = __str__

    _M_games._t_FileEntryT = IcePy.defineStruct('::games::FileEntryT', FileEntryT, (), (
        ('filename', (), IcePy._t_string),
        ('size', (), IcePy._t_int),
        ('timestamp', (), IcePy._t_int),
        ('digest', (), IcePy._t_string)
    ))

    _M_games.FileEntryT = FileEntryT
    del FileEntryT

if not _M_games.__dict__.has_key('_t_FileEntryListT'):
    _M_games._t_FileEntryListT = IcePy.defineSequence('::games::FileEntryListT', (), _M_games._t_FileEntryT)

if not _M_games.__dict__.has_key('ISyncEndpoint'):
    _M_games.ISyncEndpoint = Ice.createTempClass()
    class ISyncEndpoint(_M_games.IService):
        def __init__(self):
            if __builtin__.type(self) == _M_games.ISyncEndpoint:
                raise RuntimeError('games.ISyncEndpoint is an abstract class')

        def ice_ids(self, current=None):
            return ('::Ice::Object', '::games::IService', '::games::ISyncEndpoint')

        def ice_id(self, current=None):
            return '::games::ISyncEndpoint'

        def ice_staticId():
            return '::games::ISyncEndpoint'
        ice_staticId = staticmethod(ice_staticId)

        #
        # Operation signatures.
        #
        # def getFileDescList(self, path, current=None):
        # def getFileDigest(self, file, current=None):
        # def syncFileStart(self, file, current=None):
        # def syncFileData(self, bytes, current=None):
        # def syncFileEnd(self, current=None):
        # def launchApp(self, params, current=None):
        # def deleteFile(self, file, current=None):
        # def terminateGame(self, game, current=None):
        # def launchGame(self, game, current=None):
        # def executeBatchFile(self, file, current=None):
        # def killProcessByName(self, procname, current=None):
        # def startUpdate(self, current=None):
        # def getRemoteFile(self, remotefile, current=None):
        # def getFileDesc(self, remotefile, current=None):
        # def getRemoteFileData(self, remotefile, offset, size, current=None):
        # def shutdown(self, current=None):

        def __str__(self):
            return IcePy.stringify(self, _M_games._t_ISyncEndpoint)

        __repr__ = __str__

    _M_games.ISyncEndpointPrx = Ice.createTempClass()
    class ISyncEndpointPrx(_M_games.IServicePrx):

        def getFileDescList(self, path, _ctx=None):
            return _M_games.ISyncEndpoint._op_getFileDescList.invoke(self, ((path, ), _ctx))

        def getFileDigest(self, file, _ctx=None):
            return _M_games.ISyncEndpoint._op_getFileDigest.invoke(self, ((file, ), _ctx))

        def syncFileStart(self, file, _ctx=None):
            return _M_games.ISyncEndpoint._op_syncFileStart.invoke(self, ((file, ), _ctx))

        def syncFileData(self, bytes, _ctx=None):
            return _M_games.ISyncEndpoint._op_syncFileData.invoke(self, ((bytes, ), _ctx))

        def syncFileEnd(self, _ctx=None):
            return _M_games.ISyncEndpoint._op_syncFileEnd.invoke(self, ((), _ctx))

        def launchApp(self, params, _ctx=None):
            return _M_games.ISyncEndpoint._op_launchApp.invoke(self, ((params, ), _ctx))

        def deleteFile(self, file, _ctx=None):
            return _M_games.ISyncEndpoint._op_deleteFile.invoke(self, ((file, ), _ctx))

        def terminateGame(self, game, _ctx=None):
            return _M_games.ISyncEndpoint._op_terminateGame.invoke(self, ((game, ), _ctx))

        def launchGame(self, game, _ctx=None):
            return _M_games.ISyncEndpoint._op_launchGame.invoke(self, ((game, ), _ctx))

        def executeBatchFile(self, file, _ctx=None):
            return _M_games.ISyncEndpoint._op_executeBatchFile.invoke(self, ((file, ), _ctx))

        def killProcessByName(self, procname, _ctx=None):
            return _M_games.ISyncEndpoint._op_killProcessByName.invoke(self, ((procname, ), _ctx))

        def startUpdate(self, _ctx=None):
            return _M_games.ISyncEndpoint._op_startUpdate.invoke(self, ((), _ctx))

        def getRemoteFile(self, remotefile, _ctx=None):
            return _M_games.ISyncEndpoint._op_getRemoteFile.invoke(self, ((remotefile, ), _ctx))

        def getFileDesc(self, remotefile, _ctx=None):
            return _M_games.ISyncEndpoint._op_getFileDesc.invoke(self, ((remotefile, ), _ctx))

        def getRemoteFileData(self, remotefile, offset, size, _ctx=None):
            return _M_games.ISyncEndpoint._op_getRemoteFileData.invoke(self, ((remotefile, offset, size), _ctx))

        def shutdown(self, _ctx=None):
            return _M_games.ISyncEndpoint._op_shutdown.invoke(self, ((), _ctx))

        def checkedCast(proxy, facetOrCtx=None, _ctx=None):
            return _M_games.ISyncEndpointPrx.ice_checkedCast(proxy, '::games::ISyncEndpoint', facetOrCtx, _ctx)
        checkedCast = staticmethod(checkedCast)

        def uncheckedCast(proxy, facet=None):
            return _M_games.ISyncEndpointPrx.ice_uncheckedCast(proxy, facet)
        uncheckedCast = staticmethod(uncheckedCast)

    _M_games._t_ISyncEndpointPrx = IcePy.defineProxy('::games::ISyncEndpoint', ISyncEndpointPrx)

    _M_games._t_ISyncEndpoint = IcePy.defineClass('::games::ISyncEndpoint', ISyncEndpoint, (), True, None, (_M_games._t_IService,), ())
    ISyncEndpoint.ice_type = _M_games._t_ISyncEndpoint

    ISyncEndpoint._op_getFileDescList = IcePy.Operation('getFileDescList', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), IcePy._t_string),), (), _M_games._t_FileEntryListT, ())
    ISyncEndpoint._op_getFileDigest = IcePy.Operation('getFileDigest', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), IcePy._t_string),), (), _M_games._t_ReturnValueT, ())
    ISyncEndpoint._op_syncFileStart = IcePy.Operation('syncFileStart', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), IcePy._t_string),), (), _M_games._t_ReturnValueT, ())
    ISyncEndpoint._op_syncFileData = IcePy.Operation('syncFileData', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), IcePy._t_string),), (), _M_games._t_ReturnValueT, ())
    ISyncEndpoint._op_syncFileEnd = IcePy.Operation('syncFileEnd', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (), (), _M_games._t_ReturnValueT, ())
    ISyncEndpoint._op_launchApp = IcePy.Operation('launchApp', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), _M_games._t_HashValueSet),), (), _M_games._t_ReturnValueT, ())
    ISyncEndpoint._op_deleteFile = IcePy.Operation('deleteFile', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), IcePy._t_string),), (), _M_games._t_ReturnValueT, ())
    ISyncEndpoint._op_terminateGame = IcePy.Operation('terminateGame', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), IcePy._t_string),), (), _M_games._t_ReturnValueT, ())
    ISyncEndpoint._op_launchGame = IcePy.Operation('launchGame', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), IcePy._t_string),), (), _M_games._t_ReturnValueT, ())
    ISyncEndpoint._op_executeBatchFile = IcePy.Operation('executeBatchFile', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), IcePy._t_string),), (), _M_games._t_ReturnValueT, ())
    ISyncEndpoint._op_killProcessByName = IcePy.Operation('killProcessByName', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), IcePy._t_string),), (), _M_games._t_ReturnValueT, ())
    ISyncEndpoint._op_startUpdate = IcePy.Operation('startUpdate', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (), (), _M_games._t_ReturnValueT, ())
    ISyncEndpoint._op_getRemoteFile = IcePy.Operation('getRemoteFile', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), IcePy._t_string),), (), _M_games._t_StreamDataT, ())
    ISyncEndpoint._op_getFileDesc = IcePy.Operation('getFileDesc', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), IcePy._t_string),), (), _M_games._t_FileEntryT, ())
    ISyncEndpoint._op_getRemoteFileData = IcePy.Operation('getRemoteFileData', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), IcePy._t_string), ((), IcePy._t_int), ((), IcePy._t_int)), (), _M_games._t_StreamDataT, ())
    ISyncEndpoint._op_shutdown = IcePy.Operation('shutdown', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (), (), None, ())

    _M_games.ISyncEndpoint = ISyncEndpoint
    del ISyncEndpoint

    _M_games.ISyncEndpointPrx = ISyncEndpointPrx
    del ISyncEndpointPrx

# End of module games
