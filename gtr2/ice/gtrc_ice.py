# **********************************************************************
#
# Copyright (c) 2003-2009 ZeroC, Inc. All rights reserved.
#
# This copy of Ice is licensed to you under the terms described in the
# ICE_LICENSE file included in this distribution.
#
# **********************************************************************

# Ice version 3.3.1
# Generated from file `gtrc.ice'

import Ice, IcePy, __builtin__

if not Ice.__dict__.has_key("_struct_marker"):
    Ice._struct_marker = object()

# Start of module gtr
_M_gtr = Ice.openModule('gtr')
__name__ = 'gtr'

if not _M_gtr.__dict__.has_key('_t_HashValueSet'):
    _M_gtr._t_HashValueSet = IcePy.defineDictionary('::gtr::HashValueSet', (), IcePy._t_string, IcePy._t_string)

if not _M_gtr.__dict__.has_key('_t_ReturnValueT'):
    _M_gtr._t_ReturnValueT = IcePy.defineDictionary('::gtr::ReturnValueT', (), IcePy._t_string, IcePy._t_string)

if not _M_gtr.__dict__.has_key('_t_ByteStreamT'):
    _M_gtr._t_ByteStreamT = IcePy.defineSequence('::gtr::ByteStreamT', (), IcePy._t_byte)

if not _M_gtr.__dict__.has_key('_t_StringListT'):
    _M_gtr._t_StringListT = IcePy.defineSequence('::gtr::StringListT', (), IcePy._t_string)

if not _M_gtr.__dict__.has_key('_t_HashValueListT'):
    _M_gtr._t_HashValueListT = IcePy.defineSequence('::gtr::HashValueListT', (), _M_gtr._t_HashValueSet)

if not _M_gtr.__dict__.has_key('_t_IntListT'):
    _M_gtr._t_IntListT = IcePy.defineSequence('::gtr::IntListT', (), IcePy._t_int)

if not _M_gtr.__dict__.has_key('_t_StringListListT'):
    _M_gtr._t_StringListListT = IcePy.defineSequence('::gtr::StringListListT', (), _M_gtr._t_StringListT)

if not _M_gtr.__dict__.has_key('CallReturnT'):
    _M_gtr.CallReturnT = Ice.createTempClass()
    class CallReturnT(object):
        def __init__(self, succ=False, msg='', props=None):
            self.succ = succ
            self.msg = msg
            self.props = props

        def __hash__(self):
            _h = 0
            _h = 5 * _h + __builtin__.hash(self.succ)
            _h = 5 * _h + __builtin__.hash(self.msg)
            if self.props:
                for _i0 in self.props:
                    _h = 5 * _h + __builtin__.hash(_i0)
                    _h = 5 * _h + __builtin__.hash(self.props[_i0])
            return _h % 0x7fffffff

        def __cmp__(self, other):
            if other == None:
                return 1
            if self.succ < other.succ:
                return -1
            elif self.succ > other.succ:
                return 1
            if self.msg < other.msg:
                return -1
            elif self.msg > other.msg:
                return 1
            if self.props < other.props:
                return -1
            elif self.props > other.props:
                return 1
            return 0

        def __str__(self):
            return IcePy.stringify(self, _M_gtr._t_CallReturnT)

        __repr__ = __str__

    _M_gtr._t_CallReturnT = IcePy.defineStruct('::gtr::CallReturnT', CallReturnT, (), (
        ('succ', (), IcePy._t_bool),
        ('msg', (), IcePy._t_string),
        ('props', (), _M_gtr._t_HashValueSet)
    ))

    _M_gtr.CallReturnT = CallReturnT
    del CallReturnT

_M_gtr.IMAGEJPEG = 1

_M_gtr.IMAGEPNG = 2

_M_gtr.IMAGEBMP = 3

if not _M_gtr.__dict__.has_key('ImageDataT'):
    _M_gtr.ImageDataT = Ice.createTempClass()
    class ImageDataT(object):
        def __init__(self, type=0, bytes=None, width=0, height=0):
            self.type = type
            self.bytes = bytes
            self.width = width
            self.height = height

        def __hash__(self):
            _h = 0
            _h = 5 * _h + __builtin__.hash(self.type)
            if self.bytes:
                for _i0 in self.bytes:
                    _h = 5 * _h + __builtin__.hash(_i0)
            _h = 5 * _h + __builtin__.hash(self.width)
            _h = 5 * _h + __builtin__.hash(self.height)
            return _h % 0x7fffffff

        def __cmp__(self, other):
            if other == None:
                return 1
            if self.type < other.type:
                return -1
            elif self.type > other.type:
                return 1
            if self.bytes < other.bytes:
                return -1
            elif self.bytes > other.bytes:
                return 1
            if self.width < other.width:
                return -1
            elif self.width > other.width:
                return 1
            if self.height < other.height:
                return -1
            elif self.height > other.height:
                return 1
            return 0

        def __str__(self):
            return IcePy.stringify(self, _M_gtr._t_ImageDataT)

        __repr__ = __str__

    _M_gtr._t_ImageDataT = IcePy.defineStruct('::gtr::ImageDataT', ImageDataT, (), (
        ('type', (), IcePy._t_int),
        ('bytes', (), _M_gtr._t_ByteStreamT),
        ('width', (), IcePy._t_int),
        ('height', (), IcePy._t_int)
    ))

    _M_gtr.ImageDataT = ImageDataT
    del ImageDataT

if not _M_gtr.__dict__.has_key('GameAuthDataT'):
    _M_gtr.GameAuthDataT = Ice.createTempClass()
    class GameAuthDataT(object):
        def __init__(self, type=0, image=Ice._struct_marker, seckey=''):
            self.type = type
            if image is Ice._struct_marker:
                self.image = _M_gtr.ImageDataT()
            else:
                self.image = image
            self.seckey = seckey

        def __hash__(self):
            _h = 0
            _h = 5 * _h + __builtin__.hash(self.type)
            _h = 5 * _h + __builtin__.hash(self.image)
            _h = 5 * _h + __builtin__.hash(self.seckey)
            return _h % 0x7fffffff

        def __cmp__(self, other):
            if other == None:
                return 1
            if self.type < other.type:
                return -1
            elif self.type > other.type:
                return 1
            if self.image < other.image:
                return -1
            elif self.image > other.image:
                return 1
            if self.seckey < other.seckey:
                return -1
            elif self.seckey > other.seckey:
                return 1
            return 0

        def __str__(self):
            return IcePy.stringify(self, _M_gtr._t_GameAuthDataT)

        __repr__ = __str__

    _M_gtr._t_GameAuthDataT = IcePy.defineStruct('::gtr::GameAuthDataT', GameAuthDataT, (), (
        ('type', (), IcePy._t_int),
        ('image', (), _M_gtr._t_ImageDataT),
        ('seckey', (), IcePy._t_string)
    ))

    _M_gtr.GameAuthDataT = GameAuthDataT
    del GameAuthDataT

if not _M_gtr.__dict__.has_key('GameIdentifyT'):
    _M_gtr.GameIdentifyT = Ice.createTempClass()
    class GameIdentifyT(object):
        def __init__(self, id='', tradeNo=''):
            self.id = id
            self.tradeNo = tradeNo

        def __hash__(self):
            _h = 0
            _h = 5 * _h + __builtin__.hash(self.id)
            _h = 5 * _h + __builtin__.hash(self.tradeNo)
            return _h % 0x7fffffff

        def __cmp__(self, other):
            if other == None:
                return 1
            if self.id < other.id:
                return -1
            elif self.id > other.id:
                return 1
            if self.tradeNo < other.tradeNo:
                return -1
            elif self.tradeNo > other.tradeNo:
                return 1
            return 0

        def __str__(self):
            return IcePy.stringify(self, _M_gtr._t_GameIdentifyT)

        __repr__ = __str__

    _M_gtr._t_GameIdentifyT = IcePy.defineStruct('::gtr::GameIdentifyT', GameIdentifyT, (), (
        ('id', (), IcePy._t_string),
        ('tradeNo', (), IcePy._t_string)
    ))

    _M_gtr.GameIdentifyT = GameIdentifyT
    del GameIdentifyT

if not _M_gtr.__dict__.has_key('ServiceIdentifyT'):
    _M_gtr.ServiceIdentifyT = Ice.createTempClass()
    class ServiceIdentifyT(object):
        def __init__(self, id='', version=''):
            self.id = id
            self.version = version

        def __hash__(self):
            _h = 0
            _h = 5 * _h + __builtin__.hash(self.id)
            _h = 5 * _h + __builtin__.hash(self.version)
            return _h % 0x7fffffff

        def __cmp__(self, other):
            if other == None:
                return 1
            if self.id < other.id:
                return -1
            elif self.id > other.id:
                return 1
            if self.version < other.version:
                return -1
            elif self.version > other.version:
                return 1
            return 0

        def __str__(self):
            return IcePy.stringify(self, _M_gtr._t_ServiceIdentifyT)

        __repr__ = __str__

    _M_gtr._t_ServiceIdentifyT = IcePy.defineStruct('::gtr::ServiceIdentifyT', ServiceIdentifyT, (), (
        ('id', (), IcePy._t_string),
        ('version', (), IcePy._t_string)
    ))

    _M_gtr.ServiceIdentifyT = ServiceIdentifyT
    del ServiceIdentifyT

if not _M_gtr.__dict__.has_key('IService'):
    _M_gtr.IService = Ice.createTempClass()
    class IService(Ice.Object):
        def __init__(self):
            if __builtin__.type(self) == _M_gtr.IService:
                raise RuntimeError('gtr.IService is an abstract class')

        def ice_ids(self, current=None):
            return ('::Ice::Object', '::gtr::IService')

        def ice_id(self, current=None):
            return '::gtr::IService'

        def ice_staticId():
            return '::gtr::IService'
        ice_staticId = staticmethod(ice_staticId)

        #
        # Operation signatures.
        #
        # def getType(self, current=None):
        # def getId(self, current=None):
        # def getTimestamp(self, current=None):
        # def shutdown(self, current=None):
        # def heartbeat(self, senderType, senderId, current=None):

        def __str__(self):
            return IcePy.stringify(self, _M_gtr._t_IService)

        __repr__ = __str__

    _M_gtr.IServicePrx = Ice.createTempClass()
    class IServicePrx(Ice.ObjectPrx):

        def getType(self, _ctx=None):
            return _M_gtr.IService._op_getType.invoke(self, ((), _ctx))

        def getId(self, _ctx=None):
            return _M_gtr.IService._op_getId.invoke(self, ((), _ctx))

        def getTimestamp(self, _ctx=None):
            return _M_gtr.IService._op_getTimestamp.invoke(self, ((), _ctx))

        def shutdown(self, _ctx=None):
            return _M_gtr.IService._op_shutdown.invoke(self, ((), _ctx))

        def heartbeat(self, senderType, senderId, _ctx=None):
            return _M_gtr.IService._op_heartbeat.invoke(self, ((senderType, senderId), _ctx))

        def checkedCast(proxy, facetOrCtx=None, _ctx=None):
            return _M_gtr.IServicePrx.ice_checkedCast(proxy, '::gtr::IService', facetOrCtx, _ctx)
        checkedCast = staticmethod(checkedCast)

        def uncheckedCast(proxy, facet=None):
            return _M_gtr.IServicePrx.ice_uncheckedCast(proxy, facet)
        uncheckedCast = staticmethod(uncheckedCast)

    _M_gtr._t_IServicePrx = IcePy.defineProxy('::gtr::IService', IServicePrx)

    _M_gtr._t_IService = IcePy.defineClass('::gtr::IService', IService, (), True, None, (), ())
    IService.ice_type = _M_gtr._t_IService

    IService._op_getType = IcePy.Operation('getType', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (), (), IcePy._t_int, ())
    IService._op_getId = IcePy.Operation('getId', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (), (), _M_gtr._t_ServiceIdentifyT, ())
    IService._op_getTimestamp = IcePy.Operation('getTimestamp', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (), (), IcePy._t_int, ())
    IService._op_shutdown = IcePy.Operation('shutdown', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (), (), None, ())
    IService._op_heartbeat = IcePy.Operation('heartbeat', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), IcePy._t_string), ((), IcePy._t_string)), (), None, ())

    _M_gtr.IService = IService
    del IService

    _M_gtr.IServicePrx = IServicePrx
    del IServicePrx

if not _M_gtr.__dict__.has_key('QuestionContentT'):
    _M_gtr.QuestionContentT = Ice.createTempClass()
    class QuestionContentT(object):
        def __init__(self, type=0, image=Ice._struct_marker, image2=Ice._struct_marker, text='', cookie=0, gameId=''):
            self.type = type
            if image is Ice._struct_marker:
                self.image = _M_gtr.ImageDataT()
            else:
                self.image = image
            if image2 is Ice._struct_marker:
                self.image2 = _M_gtr.ImageDataT()
            else:
                self.image2 = image2
            self.text = text
            self.cookie = cookie
            self.gameId = gameId

        def __hash__(self):
            _h = 0
            _h = 5 * _h + __builtin__.hash(self.type)
            _h = 5 * _h + __builtin__.hash(self.image)
            _h = 5 * _h + __builtin__.hash(self.image2)
            _h = 5 * _h + __builtin__.hash(self.text)
            _h = 5 * _h + __builtin__.hash(self.cookie)
            _h = 5 * _h + __builtin__.hash(self.gameId)
            return _h % 0x7fffffff

        def __cmp__(self, other):
            if other == None:
                return 1
            if self.type < other.type:
                return -1
            elif self.type > other.type:
                return 1
            if self.image < other.image:
                return -1
            elif self.image > other.image:
                return 1
            if self.image2 < other.image2:
                return -1
            elif self.image2 > other.image2:
                return 1
            if self.text < other.text:
                return -1
            elif self.text > other.text:
                return 1
            if self.cookie < other.cookie:
                return -1
            elif self.cookie > other.cookie:
                return 1
            if self.gameId < other.gameId:
                return -1
            elif self.gameId > other.gameId:
                return 1
            return 0

        def __str__(self):
            return IcePy.stringify(self, _M_gtr._t_QuestionContentT)

        __repr__ = __str__

    _M_gtr._t_QuestionContentT = IcePy.defineStruct('::gtr::QuestionContentT', QuestionContentT, (), (
        ('type', (), IcePy._t_int),
        ('image', (), _M_gtr._t_ImageDataT),
        ('image2', (), _M_gtr._t_ImageDataT),
        ('text', (), IcePy._t_string),
        ('cookie', (), IcePy._t_int),
        ('gameId', (), IcePy._t_string)
    ))

    _M_gtr.QuestionContentT = QuestionContentT
    del QuestionContentT

if not _M_gtr.__dict__.has_key('QuestionResultT'):
    _M_gtr.QuestionResultT = Ice.createTempClass()
    class QuestionResultT(object):
        def __init__(self, value='', cookie=0):
            self.value = value
            self.cookie = cookie

        def __hash__(self):
            _h = 0
            _h = 5 * _h + __builtin__.hash(self.value)
            _h = 5 * _h + __builtin__.hash(self.cookie)
            return _h % 0x7fffffff

        def __cmp__(self, other):
            if other == None:
                return 1
            if self.value < other.value:
                return -1
            elif self.value > other.value:
                return 1
            if self.cookie < other.cookie:
                return -1
            elif self.cookie > other.cookie:
                return 1
            return 0

        def __str__(self):
            return IcePy.stringify(self, _M_gtr._t_QuestionResultT)

        __repr__ = __str__

    _M_gtr._t_QuestionResultT = IcePy.defineStruct('::gtr::QuestionResultT', QuestionResultT, (), (
        ('value', (), IcePy._t_string),
        ('cookie', (), IcePy._t_int)
    ))

    _M_gtr.QuestionResultT = QuestionResultT
    del QuestionResultT

if not _M_gtr.__dict__.has_key('IQuestionServer'):
    _M_gtr._t_IQuestionServer = IcePy.declareClass('::gtr::IQuestionServer')
    _M_gtr._t_IQuestionServerPrx = IcePy.declareProxy('::gtr::IQuestionServer')

if not _M_gtr.__dict__.has_key('IAnswerEndpoint'):
    _M_gtr.IAnswerEndpoint = Ice.createTempClass()
    class IAnswerEndpoint(_M_gtr.IService):
        def __init__(self):
            if __builtin__.type(self) == _M_gtr.IAnswerEndpoint:
                raise RuntimeError('gtr.IAnswerEndpoint is an abstract class')

        def ice_ids(self, current=None):
            return ('::Ice::Object', '::gtr::IAnswerEndpoint', '::gtr::IService')

        def ice_id(self, current=None):
            return '::gtr::IAnswerEndpoint'

        def ice_staticId():
            return '::gtr::IAnswerEndpoint'
        ice_staticId = staticmethod(ice_staticId)

        #
        # Operation signatures.
        #
        # def getRemains(self, current=None):
        # def addQuestion(self, server, no, createTime, question, current=None):

        def __str__(self):
            return IcePy.stringify(self, _M_gtr._t_IAnswerEndpoint)

        __repr__ = __str__

    _M_gtr.IAnswerEndpointPrx = Ice.createTempClass()
    class IAnswerEndpointPrx(_M_gtr.IServicePrx):

        def getRemains(self, _ctx=None):
            return _M_gtr.IAnswerEndpoint._op_getRemains.invoke(self, ((), _ctx))

        def addQuestion(self, server, no, createTime, question, _ctx=None):
            return _M_gtr.IAnswerEndpoint._op_addQuestion.invoke(self, ((server, no, createTime, question), _ctx))

        def checkedCast(proxy, facetOrCtx=None, _ctx=None):
            return _M_gtr.IAnswerEndpointPrx.ice_checkedCast(proxy, '::gtr::IAnswerEndpoint', facetOrCtx, _ctx)
        checkedCast = staticmethod(checkedCast)

        def uncheckedCast(proxy, facet=None):
            return _M_gtr.IAnswerEndpointPrx.ice_uncheckedCast(proxy, facet)
        uncheckedCast = staticmethod(uncheckedCast)

    _M_gtr._t_IAnswerEndpointPrx = IcePy.defineProxy('::gtr::IAnswerEndpoint', IAnswerEndpointPrx)

    _M_gtr._t_IAnswerEndpoint = IcePy.defineClass('::gtr::IAnswerEndpoint', IAnswerEndpoint, (), True, None, (_M_gtr._t_IService,), ())
    IAnswerEndpoint.ice_type = _M_gtr._t_IAnswerEndpoint

    IAnswerEndpoint._op_getRemains = IcePy.Operation('getRemains', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (), (), IcePy._t_int, ())
    IAnswerEndpoint._op_addQuestion = IcePy.Operation('addQuestion', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), _M_gtr._t_IQuestionServerPrx), ((), IcePy._t_string), ((), IcePy._t_string), ((), _M_gtr._t_QuestionContentT)), (), IcePy._t_int, ())

    _M_gtr.IAnswerEndpoint = IAnswerEndpoint
    del IAnswerEndpoint

    _M_gtr.IAnswerEndpointPrx = IAnswerEndpointPrx
    del IAnswerEndpointPrx

if not _M_gtr.__dict__.has_key('IQuestionAsker'):
    _M_gtr.IQuestionAsker = Ice.createTempClass()
    class IQuestionAsker(Ice.Object):
        def __init__(self):
            if __builtin__.type(self) == _M_gtr.IQuestionAsker:
                raise RuntimeError('gtr.IQuestionAsker is an abstract class')

        def ice_ids(self, current=None):
            return ('::Ice::Object', '::gtr::IQuestionAsker')

        def ice_id(self, current=None):
            return '::gtr::IQuestionAsker'

        def ice_staticId():
            return '::gtr::IQuestionAsker'
        ice_staticId = staticmethod(ice_staticId)

        #
        # Operation signatures.
        #
        # def answerResult(self, no, result, current=None):

        def __str__(self):
            return IcePy.stringify(self, _M_gtr._t_IQuestionAsker)

        __repr__ = __str__

    _M_gtr.IQuestionAskerPrx = Ice.createTempClass()
    class IQuestionAskerPrx(Ice.ObjectPrx):

        def answerResult(self, no, result, _ctx=None):
            return _M_gtr.IQuestionAsker._op_answerResult.invoke(self, ((no, result), _ctx))

        def checkedCast(proxy, facetOrCtx=None, _ctx=None):
            return _M_gtr.IQuestionAskerPrx.ice_checkedCast(proxy, '::gtr::IQuestionAsker', facetOrCtx, _ctx)
        checkedCast = staticmethod(checkedCast)

        def uncheckedCast(proxy, facet=None):
            return _M_gtr.IQuestionAskerPrx.ice_uncheckedCast(proxy, facet)
        uncheckedCast = staticmethod(uncheckedCast)

    _M_gtr._t_IQuestionAskerPrx = IcePy.defineProxy('::gtr::IQuestionAsker', IQuestionAskerPrx)

    _M_gtr._t_IQuestionAsker = IcePy.defineClass('::gtr::IQuestionAsker', IQuestionAsker, (), True, None, (), ())
    IQuestionAsker.ice_type = _M_gtr._t_IQuestionAsker

    IQuestionAsker._op_answerResult = IcePy.Operation('answerResult', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), IcePy._t_string), ((), IcePy._t_string)), (), None, ())

    _M_gtr.IQuestionAsker = IQuestionAsker
    del IQuestionAsker

    _M_gtr.IQuestionAskerPrx = IQuestionAskerPrx
    del IQuestionAskerPrx

if not _M_gtr.__dict__.has_key('IQuestionServer'):
    _M_gtr.IQuestionServer = Ice.createTempClass()
    class IQuestionServer(_M_gtr.IService):
        def __init__(self):
            if __builtin__.type(self) == _M_gtr.IQuestionServer:
                raise RuntimeError('gtr.IQuestionServer is an abstract class')

        def ice_ids(self, current=None):
            return ('::Ice::Object', '::gtr::IQuestionServer', '::gtr::IService')

        def ice_id(self, current=None):
            return '::gtr::IQuestionServer'

        def ice_staticId():
            return '::gtr::IQuestionServer'
        ice_staticId = staticmethod(ice_staticId)

        #
        # Operation signatures.
        #
        # def answer(self, asker, no, question, current=None):
        # def answerResult(self, no, result, current=None):
        # def login(self, answer, worker, passwd, current=None):
        # def logout(self, answer, worker, current=None):
        # def verifyAnswer(self, no, type, succ, current=None):

        def __str__(self):
            return IcePy.stringify(self, _M_gtr._t_IQuestionServer)

        __repr__ = __str__

    _M_gtr.IQuestionServerPrx = Ice.createTempClass()
    class IQuestionServerPrx(_M_gtr.IServicePrx):

        def answer(self, asker, no, question, _ctx=None):
            return _M_gtr.IQuestionServer._op_answer.invoke(self, ((asker, no, question), _ctx))

        def answerResult(self, no, result, _ctx=None):
            return _M_gtr.IQuestionServer._op_answerResult.invoke(self, ((no, result), _ctx))

        def login(self, answer, worker, passwd, _ctx=None):
            return _M_gtr.IQuestionServer._op_login.invoke(self, ((answer, worker, passwd), _ctx))

        def logout(self, answer, worker, _ctx=None):
            return _M_gtr.IQuestionServer._op_logout.invoke(self, ((answer, worker), _ctx))

        def verifyAnswer(self, no, type, succ, _ctx=None):
            return _M_gtr.IQuestionServer._op_verifyAnswer.invoke(self, ((no, type, succ), _ctx))

        def checkedCast(proxy, facetOrCtx=None, _ctx=None):
            return _M_gtr.IQuestionServerPrx.ice_checkedCast(proxy, '::gtr::IQuestionServer', facetOrCtx, _ctx)
        checkedCast = staticmethod(checkedCast)

        def uncheckedCast(proxy, facet=None):
            return _M_gtr.IQuestionServerPrx.ice_uncheckedCast(proxy, facet)
        uncheckedCast = staticmethod(uncheckedCast)

    _M_gtr._t_IQuestionServerPrx = IcePy.defineProxy('::gtr::IQuestionServer', IQuestionServerPrx)

    _M_gtr._t_IQuestionServer = IcePy.defineClass('::gtr::IQuestionServer', IQuestionServer, (), True, None, (_M_gtr._t_IService,), ())
    IQuestionServer.ice_type = _M_gtr._t_IQuestionServer

    IQuestionServer._op_answer = IcePy.Operation('answer', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), _M_gtr._t_IQuestionAskerPrx), ((), IcePy._t_string), ((), _M_gtr._t_QuestionContentT)), (), None, ())
    IQuestionServer._op_answerResult = IcePy.Operation('answerResult', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), IcePy._t_string), ((), _M_gtr._t_QuestionResultT)), (), None, ())
    IQuestionServer._op_login = IcePy.Operation('login', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), _M_gtr._t_IAnswerEndpointPrx), ((), IcePy._t_string), ((), IcePy._t_string)), (), _M_gtr._t_CallReturnT, ())
    IQuestionServer._op_logout = IcePy.Operation('logout', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), _M_gtr._t_IAnswerEndpointPrx), ((), IcePy._t_string)), (), None, ())
    IQuestionServer._op_verifyAnswer = IcePy.Operation('verifyAnswer', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), IcePy._t_string), ((), IcePy._t_int), ((), IcePy._t_bool)), (), None, ())

    _M_gtr.IQuestionServer = IQuestionServer
    del IQuestionServer

    _M_gtr.IQuestionServerPrx = IQuestionServerPrx
    del IQuestionServerPrx

if not _M_gtr.__dict__.has_key('LogMessageT'):
    _M_gtr.LogMessageT = Ice.createTempClass()
    class LogMessageT(object):
        def __init__(self, xclass=0, msg=''):
            self.xclass = xclass
            self.msg = msg

        def __hash__(self):
            _h = 0
            _h = 5 * _h + __builtin__.hash(self.xclass)
            _h = 5 * _h + __builtin__.hash(self.msg)
            return _h % 0x7fffffff

        def __cmp__(self, other):
            if other == None:
                return 1
            if self.xclass < other.xclass:
                return -1
            elif self.xclass > other.xclass:
                return 1
            if self.msg < other.msg:
                return -1
            elif self.msg > other.msg:
                return 1
            return 0

        def __str__(self):
            return IcePy.stringify(self, _M_gtr._t_LogMessageT)

        __repr__ = __str__

    _M_gtr._t_LogMessageT = IcePy.defineStruct('::gtr::LogMessageT', LogMessageT, (), (
        ('xclass', (), IcePy._t_int),
        ('msg', (), IcePy._t_string)
    ))

    _M_gtr.LogMessageT = LogMessageT
    del LogMessageT

if not _M_gtr.__dict__.has_key('ILogger'):
    _M_gtr.ILogger = Ice.createTempClass()
    class ILogger(Ice.Object):
        def __init__(self):
            if __builtin__.type(self) == _M_gtr.ILogger:
                raise RuntimeError('gtr.ILogger is an abstract class')

        def ice_ids(self, current=None):
            return ('::Ice::Object', '::gtr::ILogger')

        def ice_id(self, current=None):
            return '::gtr::ILogger'

        def ice_staticId():
            return '::gtr::ILogger'
        ice_staticId = staticmethod(ice_staticId)

        #
        # Operation signatures.
        #
        # def gameMsg(self, gameId, timetick, msg, current=None):
        # def gameImage(self, gameId, timetick, opName, image, current=None):

        def __str__(self):
            return IcePy.stringify(self, _M_gtr._t_ILogger)

        __repr__ = __str__

    _M_gtr.ILoggerPrx = Ice.createTempClass()
    class ILoggerPrx(Ice.ObjectPrx):

        def gameMsg(self, gameId, timetick, msg, _ctx=None):
            return _M_gtr.ILogger._op_gameMsg.invoke(self, ((gameId, timetick, msg), _ctx))

        def gameImage(self, gameId, timetick, opName, image, _ctx=None):
            return _M_gtr.ILogger._op_gameImage.invoke(self, ((gameId, timetick, opName, image), _ctx))

        def checkedCast(proxy, facetOrCtx=None, _ctx=None):
            return _M_gtr.ILoggerPrx.ice_checkedCast(proxy, '::gtr::ILogger', facetOrCtx, _ctx)
        checkedCast = staticmethod(checkedCast)

        def uncheckedCast(proxy, facet=None):
            return _M_gtr.ILoggerPrx.ice_uncheckedCast(proxy, facet)
        uncheckedCast = staticmethod(uncheckedCast)

    _M_gtr._t_ILoggerPrx = IcePy.defineProxy('::gtr::ILogger', ILoggerPrx)

    _M_gtr._t_ILogger = IcePy.defineClass('::gtr::ILogger', ILogger, (), True, None, (), ())
    ILogger.ice_type = _M_gtr._t_ILogger

    ILogger._op_gameMsg = IcePy.Operation('gameMsg', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), _M_gtr._t_GameIdentifyT), ((), IcePy._t_int), ((), _M_gtr._t_LogMessageT)), (), None, ())
    ILogger._op_gameImage = IcePy.Operation('gameImage', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), _M_gtr._t_GameIdentifyT), ((), IcePy._t_int), ((), IcePy._t_string), ((), _M_gtr._t_ImageDataT)), (), None, ())

    _M_gtr.ILogger = ILogger
    del ILogger

    _M_gtr.ILoggerPrx = ILoggerPrx
    del ILoggerPrx

if not _M_gtr.__dict__.has_key('ILogServer'):
    _M_gtr.ILogServer = Ice.createTempClass()
    class ILogServer(_M_gtr.ILogger, _M_gtr.IService):
        def __init__(self):
            if __builtin__.type(self) == _M_gtr.ILogServer:
                raise RuntimeError('gtr.ILogServer is an abstract class')

        def ice_ids(self, current=None):
            return ('::Ice::Object', '::gtr::ILogServer', '::gtr::ILogger', '::gtr::IService')

        def ice_id(self, current=None):
            return '::gtr::ILogServer'

        def ice_staticId():
            return '::gtr::ILogServer'
        ice_staticId = staticmethod(ice_staticId)

        def __str__(self):
            return IcePy.stringify(self, _M_gtr._t_ILogServer)

        __repr__ = __str__

    _M_gtr.ILogServerPrx = Ice.createTempClass()
    class ILogServerPrx(_M_gtr.ILoggerPrx, _M_gtr.IServicePrx):

        def checkedCast(proxy, facetOrCtx=None, _ctx=None):
            return _M_gtr.ILogServerPrx.ice_checkedCast(proxy, '::gtr::ILogServer', facetOrCtx, _ctx)
        checkedCast = staticmethod(checkedCast)

        def uncheckedCast(proxy, facet=None):
            return _M_gtr.ILogServerPrx.ice_uncheckedCast(proxy, facet)
        uncheckedCast = staticmethod(uncheckedCast)

    _M_gtr._t_ILogServerPrx = IcePy.defineProxy('::gtr::ILogServer', ILogServerPrx)

    _M_gtr._t_ILogServer = IcePy.defineClass('::gtr::ILogServer', ILogServer, (), True, None, (_M_gtr._t_ILogger, _M_gtr._t_IService), ())
    ILogServer.ice_type = _M_gtr._t_ILogServer

    _M_gtr.ILogServer = ILogServer
    del ILogServer

    _M_gtr.ILogServerPrx = ILogServerPrx
    del ILogServerPrx

_M_gtr.gwsPost = 1

_M_gtr.gwsAccountAudit = 2

_M_gtr.gwsVerify = 4

if not _M_gtr.__dict__.has_key('GameWorkSheetPostT'):
    _M_gtr.GameWorkSheetPostT = Ice.createTempClass()
    class GameWorkSheetPostT(object):
        def __init__(self, sellerActor='', sellerLevel=0, money=0, transactionTime=0, sellerSecondPwd='', buyerActor='', buyerLevel=0, buyerMoney=0, sellerIndex=0, sellerGroup=0, bankPwd=''):
            self.sellerActor = sellerActor
            self.sellerLevel = sellerLevel
            self.money = money
            self.transactionTime = transactionTime
            self.sellerSecondPwd = sellerSecondPwd
            self.buyerActor = buyerActor
            self.buyerLevel = buyerLevel
            self.buyerMoney = buyerMoney
            self.sellerIndex = sellerIndex
            self.sellerGroup = sellerGroup
            self.bankPwd = bankPwd

        def __hash__(self):
            _h = 0
            _h = 5 * _h + __builtin__.hash(self.sellerActor)
            _h = 5 * _h + __builtin__.hash(self.sellerLevel)
            _h = 5 * _h + __builtin__.hash(self.money)
            _h = 5 * _h + __builtin__.hash(self.transactionTime)
            _h = 5 * _h + __builtin__.hash(self.sellerSecondPwd)
            _h = 5 * _h + __builtin__.hash(self.buyerActor)
            _h = 5 * _h + __builtin__.hash(self.buyerLevel)
            _h = 5 * _h + __builtin__.hash(self.buyerMoney)
            _h = 5 * _h + __builtin__.hash(self.sellerIndex)
            _h = 5 * _h + __builtin__.hash(self.sellerGroup)
            _h = 5 * _h + __builtin__.hash(self.bankPwd)
            return _h % 0x7fffffff

        def __cmp__(self, other):
            if other == None:
                return 1
            if self.sellerActor < other.sellerActor:
                return -1
            elif self.sellerActor > other.sellerActor:
                return 1
            if self.sellerLevel < other.sellerLevel:
                return -1
            elif self.sellerLevel > other.sellerLevel:
                return 1
            if self.money < other.money:
                return -1
            elif self.money > other.money:
                return 1
            if self.transactionTime < other.transactionTime:
                return -1
            elif self.transactionTime > other.transactionTime:
                return 1
            if self.sellerSecondPwd < other.sellerSecondPwd:
                return -1
            elif self.sellerSecondPwd > other.sellerSecondPwd:
                return 1
            if self.buyerActor < other.buyerActor:
                return -1
            elif self.buyerActor > other.buyerActor:
                return 1
            if self.buyerLevel < other.buyerLevel:
                return -1
            elif self.buyerLevel > other.buyerLevel:
                return 1
            if self.buyerMoney < other.buyerMoney:
                return -1
            elif self.buyerMoney > other.buyerMoney:
                return 1
            if self.sellerIndex < other.sellerIndex:
                return -1
            elif self.sellerIndex > other.sellerIndex:
                return 1
            if self.sellerGroup < other.sellerGroup:
                return -1
            elif self.sellerGroup > other.sellerGroup:
                return 1
            if self.bankPwd < other.bankPwd:
                return -1
            elif self.bankPwd > other.bankPwd:
                return 1
            return 0

        def __str__(self):
            return IcePy.stringify(self, _M_gtr._t_GameWorkSheetPostT)

        __repr__ = __str__

    _M_gtr._t_GameWorkSheetPostT = IcePy.defineStruct('::gtr::GameWorkSheetPostT', GameWorkSheetPostT, (), (
        ('sellerActor', (), IcePy._t_string),
        ('sellerLevel', (), IcePy._t_int),
        ('money', (), IcePy._t_long),
        ('transactionTime', (), IcePy._t_int),
        ('sellerSecondPwd', (), IcePy._t_string),
        ('buyerActor', (), IcePy._t_string),
        ('buyerLevel', (), IcePy._t_int),
        ('buyerMoney', (), IcePy._t_long),
        ('sellerIndex', (), IcePy._t_int),
        ('sellerGroup', (), IcePy._t_int),
        ('bankPwd', (), IcePy._t_string)
    ))

    _M_gtr.GameWorkSheetPostT = GameWorkSheetPostT
    del GameWorkSheetPostT

if not _M_gtr.__dict__.has_key('GameWorkSheetAccountAuditT'):
    _M_gtr.GameWorkSheetAccountAuditT = Ice.createTempClass()
    class GameWorkSheetAccountAuditT(object):
        def __init__(self, sellerActor='', sellerSecondPwd='', sellerIndex=0, sellerGroup=0, bankPwd=''):
            self.sellerActor = sellerActor
            self.sellerSecondPwd = sellerSecondPwd
            self.sellerIndex = sellerIndex
            self.sellerGroup = sellerGroup
            self.bankPwd = bankPwd

        def __hash__(self):
            _h = 0
            _h = 5 * _h + __builtin__.hash(self.sellerActor)
            _h = 5 * _h + __builtin__.hash(self.sellerSecondPwd)
            _h = 5 * _h + __builtin__.hash(self.sellerIndex)
            _h = 5 * _h + __builtin__.hash(self.sellerGroup)
            _h = 5 * _h + __builtin__.hash(self.bankPwd)
            return _h % 0x7fffffff

        def __cmp__(self, other):
            if other == None:
                return 1
            if self.sellerActor < other.sellerActor:
                return -1
            elif self.sellerActor > other.sellerActor:
                return 1
            if self.sellerSecondPwd < other.sellerSecondPwd:
                return -1
            elif self.sellerSecondPwd > other.sellerSecondPwd:
                return 1
            if self.sellerIndex < other.sellerIndex:
                return -1
            elif self.sellerIndex > other.sellerIndex:
                return 1
            if self.sellerGroup < other.sellerGroup:
                return -1
            elif self.sellerGroup > other.sellerGroup:
                return 1
            if self.bankPwd < other.bankPwd:
                return -1
            elif self.bankPwd > other.bankPwd:
                return 1
            return 0

        def __str__(self):
            return IcePy.stringify(self, _M_gtr._t_GameWorkSheetAccountAuditT)

        __repr__ = __str__

    _M_gtr._t_GameWorkSheetAccountAuditT = IcePy.defineStruct('::gtr::GameWorkSheetAccountAuditT', GameWorkSheetAccountAuditT, (), (
        ('sellerActor', (), IcePy._t_string),
        ('sellerSecondPwd', (), IcePy._t_string),
        ('sellerIndex', (), IcePy._t_int),
        ('sellerGroup', (), IcePy._t_int),
        ('bankPwd', (), IcePy._t_string)
    ))

    _M_gtr.GameWorkSheetAccountAuditT = GameWorkSheetAccountAuditT
    del GameWorkSheetAccountAuditT

if not _M_gtr.__dict__.has_key('GameWorkSheetVerifyT'):
    _M_gtr.GameWorkSheetVerifyT = Ice.createTempClass()
    class GameWorkSheetVerifyT(object):
        def __init__(self, sellerActor='', level=0, money=0, verifyTime=0, sellerSecondPwd='', sellerIndex=0, sellerGroup=0, bankPwd=''):
            self.sellerActor = sellerActor
            self.level = level
            self.money = money
            self.verifyTime = verifyTime
            self.sellerSecondPwd = sellerSecondPwd
            self.sellerIndex = sellerIndex
            self.sellerGroup = sellerGroup
            self.bankPwd = bankPwd

        def __hash__(self):
            _h = 0
            _h = 5 * _h + __builtin__.hash(self.sellerActor)
            _h = 5 * _h + __builtin__.hash(self.level)
            _h = 5 * _h + __builtin__.hash(self.money)
            _h = 5 * _h + __builtin__.hash(self.verifyTime)
            _h = 5 * _h + __builtin__.hash(self.sellerSecondPwd)
            _h = 5 * _h + __builtin__.hash(self.sellerIndex)
            _h = 5 * _h + __builtin__.hash(self.sellerGroup)
            _h = 5 * _h + __builtin__.hash(self.bankPwd)
            return _h % 0x7fffffff

        def __cmp__(self, other):
            if other == None:
                return 1
            if self.sellerActor < other.sellerActor:
                return -1
            elif self.sellerActor > other.sellerActor:
                return 1
            if self.level < other.level:
                return -1
            elif self.level > other.level:
                return 1
            if self.money < other.money:
                return -1
            elif self.money > other.money:
                return 1
            if self.verifyTime < other.verifyTime:
                return -1
            elif self.verifyTime > other.verifyTime:
                return 1
            if self.sellerSecondPwd < other.sellerSecondPwd:
                return -1
            elif self.sellerSecondPwd > other.sellerSecondPwd:
                return 1
            if self.sellerIndex < other.sellerIndex:
                return -1
            elif self.sellerIndex > other.sellerIndex:
                return 1
            if self.sellerGroup < other.sellerGroup:
                return -1
            elif self.sellerGroup > other.sellerGroup:
                return 1
            if self.bankPwd < other.bankPwd:
                return -1
            elif self.bankPwd > other.bankPwd:
                return 1
            return 0

        def __str__(self):
            return IcePy.stringify(self, _M_gtr._t_GameWorkSheetVerifyT)

        __repr__ = __str__

    _M_gtr._t_GameWorkSheetVerifyT = IcePy.defineStruct('::gtr::GameWorkSheetVerifyT', GameWorkSheetVerifyT, (), (
        ('sellerActor', (), IcePy._t_string),
        ('level', (), IcePy._t_int),
        ('money', (), IcePy._t_long),
        ('verifyTime', (), IcePy._t_int),
        ('sellerSecondPwd', (), IcePy._t_string),
        ('sellerIndex', (), IcePy._t_int),
        ('sellerGroup', (), IcePy._t_int),
        ('bankPwd', (), IcePy._t_string)
    ))

    _M_gtr.GameWorkSheetVerifyT = GameWorkSheetVerifyT
    del GameWorkSheetVerifyT

if not _M_gtr.__dict__.has_key('GameTaskletT'):
    _M_gtr.GameTaskletT = Ice.createTempClass()
    class GameTaskletT(object):
        def __init__(self, id='', type=0, no='', gameId='', account='', password='', area='', server='', lineName='', lineNo=0, createTime='', secretKey='', proxyEnable=False, proxyRegion='', remainTime=0, post=Ice._struct_marker, audit=Ice._struct_marker, verify=Ice._struct_marker):
            self.id = id
            self.type = type
            self.no = no
            self.gameId = gameId
            self.account = account
            self.password = password
            self.area = area
            self.server = server
            self.lineName = lineName
            self.lineNo = lineNo
            self.createTime = createTime
            self.secretKey = secretKey
            self.proxyEnable = proxyEnable
            self.proxyRegion = proxyRegion
            self.remainTime = remainTime
            if post is Ice._struct_marker:
                self.post = _M_gtr.GameWorkSheetPostT()
            else:
                self.post = post
            if audit is Ice._struct_marker:
                self.audit = _M_gtr.GameWorkSheetAccountAuditT()
            else:
                self.audit = audit
            if verify is Ice._struct_marker:
                self.verify = _M_gtr.GameWorkSheetVerifyT()
            else:
                self.verify = verify

        def __hash__(self):
            _h = 0
            _h = 5 * _h + __builtin__.hash(self.id)
            _h = 5 * _h + __builtin__.hash(self.type)
            _h = 5 * _h + __builtin__.hash(self.no)
            _h = 5 * _h + __builtin__.hash(self.gameId)
            _h = 5 * _h + __builtin__.hash(self.account)
            _h = 5 * _h + __builtin__.hash(self.password)
            _h = 5 * _h + __builtin__.hash(self.area)
            _h = 5 * _h + __builtin__.hash(self.server)
            _h = 5 * _h + __builtin__.hash(self.lineName)
            _h = 5 * _h + __builtin__.hash(self.lineNo)
            _h = 5 * _h + __builtin__.hash(self.createTime)
            _h = 5 * _h + __builtin__.hash(self.secretKey)
            _h = 5 * _h + __builtin__.hash(self.proxyEnable)
            _h = 5 * _h + __builtin__.hash(self.proxyRegion)
            _h = 5 * _h + __builtin__.hash(self.remainTime)
            _h = 5 * _h + __builtin__.hash(self.post)
            _h = 5 * _h + __builtin__.hash(self.audit)
            _h = 5 * _h + __builtin__.hash(self.verify)
            return _h % 0x7fffffff

        def __cmp__(self, other):
            if other == None:
                return 1
            if self.id < other.id:
                return -1
            elif self.id > other.id:
                return 1
            if self.type < other.type:
                return -1
            elif self.type > other.type:
                return 1
            if self.no < other.no:
                return -1
            elif self.no > other.no:
                return 1
            if self.gameId < other.gameId:
                return -1
            elif self.gameId > other.gameId:
                return 1
            if self.account < other.account:
                return -1
            elif self.account > other.account:
                return 1
            if self.password < other.password:
                return -1
            elif self.password > other.password:
                return 1
            if self.area < other.area:
                return -1
            elif self.area > other.area:
                return 1
            if self.server < other.server:
                return -1
            elif self.server > other.server:
                return 1
            if self.lineName < other.lineName:
                return -1
            elif self.lineName > other.lineName:
                return 1
            if self.lineNo < other.lineNo:
                return -1
            elif self.lineNo > other.lineNo:
                return 1
            if self.createTime < other.createTime:
                return -1
            elif self.createTime > other.createTime:
                return 1
            if self.secretKey < other.secretKey:
                return -1
            elif self.secretKey > other.secretKey:
                return 1
            if self.proxyEnable < other.proxyEnable:
                return -1
            elif self.proxyEnable > other.proxyEnable:
                return 1
            if self.proxyRegion < other.proxyRegion:
                return -1
            elif self.proxyRegion > other.proxyRegion:
                return 1
            if self.remainTime < other.remainTime:
                return -1
            elif self.remainTime > other.remainTime:
                return 1
            if self.post < other.post:
                return -1
            elif self.post > other.post:
                return 1
            if self.audit < other.audit:
                return -1
            elif self.audit > other.audit:
                return 1
            if self.verify < other.verify:
                return -1
            elif self.verify > other.verify:
                return 1
            return 0

        def __str__(self):
            return IcePy.stringify(self, _M_gtr._t_GameTaskletT)

        __repr__ = __str__

    _M_gtr._t_GameTaskletT = IcePy.defineStruct('::gtr::GameTaskletT', GameTaskletT, (), (
        ('id', (), IcePy._t_string),
        ('type', (), IcePy._t_int),
        ('no', (), IcePy._t_string),
        ('gameId', (), IcePy._t_string),
        ('account', (), IcePy._t_string),
        ('password', (), IcePy._t_string),
        ('area', (), IcePy._t_string),
        ('server', (), IcePy._t_string),
        ('lineName', (), IcePy._t_string),
        ('lineNo', (), IcePy._t_short),
        ('createTime', (), IcePy._t_string),
        ('secretKey', (), IcePy._t_string),
        ('proxyEnable', (), IcePy._t_bool),
        ('proxyRegion', (), IcePy._t_string),
        ('remainTime', (), IcePy._t_int),
        ('post', (), _M_gtr._t_GameWorkSheetPostT),
        ('audit', (), _M_gtr._t_GameWorkSheetAccountAuditT),
        ('verify', (), _M_gtr._t_GameWorkSheetVerifyT)
    ))

    _M_gtr.GameTaskletT = GameTaskletT
    del GameTaskletT

if not _M_gtr.__dict__.has_key('GameTaskResultT'):
    _M_gtr.GameTaskResultT = Ice.createTempClass()
    class GameTaskResultT(object):
        def __init__(self, id='', no='', type=0, gameId='', result=0, errmsg='', textval=''):
            self.id = id
            self.no = no
            self.type = type
            self.gameId = gameId
            self.result = result
            self.errmsg = errmsg
            self.textval = textval

        def __hash__(self):
            _h = 0
            _h = 5 * _h + __builtin__.hash(self.id)
            _h = 5 * _h + __builtin__.hash(self.no)
            _h = 5 * _h + __builtin__.hash(self.type)
            _h = 5 * _h + __builtin__.hash(self.gameId)
            _h = 5 * _h + __builtin__.hash(self.result)
            _h = 5 * _h + __builtin__.hash(self.errmsg)
            _h = 5 * _h + __builtin__.hash(self.textval)
            return _h % 0x7fffffff

        def __cmp__(self, other):
            if other == None:
                return 1
            if self.id < other.id:
                return -1
            elif self.id > other.id:
                return 1
            if self.no < other.no:
                return -1
            elif self.no > other.no:
                return 1
            if self.type < other.type:
                return -1
            elif self.type > other.type:
                return 1
            if self.gameId < other.gameId:
                return -1
            elif self.gameId > other.gameId:
                return 1
            if self.result < other.result:
                return -1
            elif self.result > other.result:
                return 1
            if self.errmsg < other.errmsg:
                return -1
            elif self.errmsg > other.errmsg:
                return 1
            if self.textval < other.textval:
                return -1
            elif self.textval > other.textval:
                return 1
            return 0

        def __str__(self):
            return IcePy.stringify(self, _M_gtr._t_GameTaskResultT)

        __repr__ = __str__

    _M_gtr._t_GameTaskResultT = IcePy.defineStruct('::gtr::GameTaskResultT', GameTaskResultT, (), (
        ('id', (), IcePy._t_string),
        ('no', (), IcePy._t_string),
        ('type', (), IcePy._t_int),
        ('gameId', (), IcePy._t_string),
        ('result', (), IcePy._t_int),
        ('errmsg', (), IcePy._t_string),
        ('textval', (), IcePy._t_string)
    ))

    _M_gtr.GameTaskResultT = GameTaskResultT
    del GameTaskResultT

if not _M_gtr.__dict__.has_key('IGameHost'):
    _M_gtr.IGameHost = Ice.createTempClass()
    class IGameHost(_M_gtr.IQuestionAsker, _M_gtr.IService, _M_gtr.ILogger):
        def __init__(self):
            if __builtin__.type(self) == _M_gtr.IGameHost:
                raise RuntimeError('gtr.IGameHost is an abstract class')

        def ice_ids(self, current=None):
            return ('::Ice::Object', '::gtr::IGameHost', '::gtr::ILogger', '::gtr::IQuestionAsker', '::gtr::IService')

        def ice_id(self, current=None):
            return '::gtr::IGameHost'

        def ice_staticId():
            return '::gtr::IGameHost'
        ice_staticId = staticmethod(ice_staticId)

        #
        # Operation signatures.
        #
        # def getTask(self, current=None):
        # def completeTask(self, result, current=None):
        # def answer(self, question, current=None):
        # def verifyAnswer(self, type, succ, current=None):

        def __str__(self):
            return IcePy.stringify(self, _M_gtr._t_IGameHost)

        __repr__ = __str__

    _M_gtr.IGameHostPrx = Ice.createTempClass()
    class IGameHostPrx(_M_gtr.IQuestionAskerPrx, _M_gtr.IServicePrx, _M_gtr.ILoggerPrx):

        def getTask(self, _ctx=None):
            return _M_gtr.IGameHost._op_getTask.invoke(self, ((), _ctx))

        def completeTask(self, result, _ctx=None):
            return _M_gtr.IGameHost._op_completeTask.invoke(self, ((result, ), _ctx))

        def answer(self, question, _ctx=None):
            return _M_gtr.IGameHost._op_answer.invoke(self, ((question, ), _ctx))

        def verifyAnswer(self, type, succ, _ctx=None):
            return _M_gtr.IGameHost._op_verifyAnswer.invoke(self, ((type, succ), _ctx))

        def checkedCast(proxy, facetOrCtx=None, _ctx=None):
            return _M_gtr.IGameHostPrx.ice_checkedCast(proxy, '::gtr::IGameHost', facetOrCtx, _ctx)
        checkedCast = staticmethod(checkedCast)

        def uncheckedCast(proxy, facet=None):
            return _M_gtr.IGameHostPrx.ice_uncheckedCast(proxy, facet)
        uncheckedCast = staticmethod(uncheckedCast)

    _M_gtr._t_IGameHostPrx = IcePy.defineProxy('::gtr::IGameHost', IGameHostPrx)

    _M_gtr._t_IGameHost = IcePy.defineClass('::gtr::IGameHost', IGameHost, (), True, None, (_M_gtr._t_IQuestionAsker, _M_gtr._t_IService, _M_gtr._t_ILogger), ())
    IGameHost.ice_type = _M_gtr._t_IGameHost

    IGameHost._op_getTask = IcePy.Operation('getTask', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (), (), _M_gtr._t_GameTaskletT, ())
    IGameHost._op_completeTask = IcePy.Operation('completeTask', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), _M_gtr._t_GameTaskResultT),), (), None, ())
    IGameHost._op_answer = IcePy.Operation('answer', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), _M_gtr._t_QuestionContentT),), (), IcePy._t_string, ())
    IGameHost._op_verifyAnswer = IcePy.Operation('verifyAnswer', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), IcePy._t_int), ((), IcePy._t_bool)), (), None, ())

    _M_gtr.IGameHost = IGameHost
    del IGameHost

    _M_gtr.IGameHostPrx = IGameHostPrx
    del IGameHostPrx

if not _M_gtr.__dict__.has_key('GameInfoT'):
    _M_gtr.GameInfoT = Ice.createTempClass()
    class GameInfoT(object):
        def __init__(self, id=0, name='', version='', maskType=0):
            self.id = id
            self.name = name
            self.version = version
            self.maskType = maskType

        def __hash__(self):
            _h = 0
            _h = 5 * _h + __builtin__.hash(self.id)
            _h = 5 * _h + __builtin__.hash(self.name)
            _h = 5 * _h + __builtin__.hash(self.version)
            _h = 5 * _h + __builtin__.hash(self.maskType)
            return _h % 0x7fffffff

        def __cmp__(self, other):
            if other == None:
                return 1
            if self.id < other.id:
                return -1
            elif self.id > other.id:
                return 1
            if self.name < other.name:
                return -1
            elif self.name > other.name:
                return 1
            if self.version < other.version:
                return -1
            elif self.version > other.version:
                return 1
            if self.maskType < other.maskType:
                return -1
            elif self.maskType > other.maskType:
                return 1
            return 0

        def __str__(self):
            return IcePy.stringify(self, _M_gtr._t_GameInfoT)

        __repr__ = __str__

    _M_gtr._t_GameInfoT = IcePy.defineStruct('::gtr::GameInfoT', GameInfoT, (), (
        ('id', (), IcePy._t_int),
        ('name', (), IcePy._t_string),
        ('version', (), IcePy._t_string),
        ('maskType', (), IcePy._t_int)
    ))

    _M_gtr.GameInfoT = GameInfoT
    del GameInfoT

if not _M_gtr.__dict__.has_key('_t_GameInfoListT'):
    _M_gtr._t_GameInfoListT = IcePy.defineSequence('::gtr::GameInfoListT', (), _M_gtr._t_GameInfoT)

if not _M_gtr.__dict__.has_key('GameRobotInfoT'):
    _M_gtr.GameRobotInfoT = Ice.createTempClass()
    class GameRobotInfoT(object):
        def __init__(self, id='', ip='', network=0, supportGames=None):
            self.id = id
            self.ip = ip
            self.network = network
            self.supportGames = supportGames

        def __hash__(self):
            _h = 0
            _h = 5 * _h + __builtin__.hash(self.id)
            _h = 5 * _h + __builtin__.hash(self.ip)
            _h = 5 * _h + __builtin__.hash(self.network)
            if self.supportGames:
                for _i0 in self.supportGames:
                    _h = 5 * _h + __builtin__.hash(_i0)
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
            if self.network < other.network:
                return -1
            elif self.network > other.network:
                return 1
            if self.supportGames < other.supportGames:
                return -1
            elif self.supportGames > other.supportGames:
                return 1
            return 0

        def __str__(self):
            return IcePy.stringify(self, _M_gtr._t_GameRobotInfoT)

        __repr__ = __str__

    _M_gtr._t_GameRobotInfoT = IcePy.defineStruct('::gtr::GameRobotInfoT', GameRobotInfoT, (), (
        ('id', (), IcePy._t_string),
        ('ip', (), IcePy._t_string),
        ('network', (), IcePy._t_int),
        ('supportGames', (), _M_gtr._t_GameInfoListT)
    ))

    _M_gtr.GameRobotInfoT = GameRobotInfoT
    del GameRobotInfoT

if not _M_gtr.__dict__.has_key('IGtrServer'):
    _M_gtr.IGtrServer = Ice.createTempClass()
    class IGtrServer(_M_gtr.IService, _M_gtr.IQuestionServer):
        def __init__(self):
            if __builtin__.type(self) == _M_gtr.IGtrServer:
                raise RuntimeError('gtr.IGtrServer is an abstract class')

        def ice_ids(self, current=None):
            return ('::Ice::Object', '::gtr::IGtrServer', '::gtr::IQuestionServer', '::gtr::IService')

        def ice_id(self, current=None):
            return '::gtr::IGtrServer'

        def ice_staticId():
            return '::gtr::IGtrServer'
        ice_staticId = staticmethod(ice_staticId)

        #
        # Operation signatures.
        #
        # def getTask(self, robot, current=None):
        # def completeTask(self, result, current=None):

        def __str__(self):
            return IcePy.stringify(self, _M_gtr._t_IGtrServer)

        __repr__ = __str__

    _M_gtr.IGtrServerPrx = Ice.createTempClass()
    class IGtrServerPrx(_M_gtr.IServicePrx, _M_gtr.IQuestionServerPrx):

        def getTask(self, robot, _ctx=None):
            return _M_gtr.IGtrServer._op_getTask.invoke(self, ((robot, ), _ctx))

        def completeTask(self, result, _ctx=None):
            return _M_gtr.IGtrServer._op_completeTask.invoke(self, ((result, ), _ctx))

        def checkedCast(proxy, facetOrCtx=None, _ctx=None):
            return _M_gtr.IGtrServerPrx.ice_checkedCast(proxy, '::gtr::IGtrServer', facetOrCtx, _ctx)
        checkedCast = staticmethod(checkedCast)

        def uncheckedCast(proxy, facet=None):
            return _M_gtr.IGtrServerPrx.ice_uncheckedCast(proxy, facet)
        uncheckedCast = staticmethod(uncheckedCast)

    _M_gtr._t_IGtrServerPrx = IcePy.defineProxy('::gtr::IGtrServer', IGtrServerPrx)

    _M_gtr._t_IGtrServer = IcePy.defineClass('::gtr::IGtrServer', IGtrServer, (), True, None, (_M_gtr._t_IService, _M_gtr._t_IQuestionServer), ())
    IGtrServer.ice_type = _M_gtr._t_IGtrServer

    IGtrServer._op_getTask = IcePy.Operation('getTask', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), _M_gtr._t_GameRobotInfoT),), (), _M_gtr._t_GameTaskletT, ())
    IGtrServer._op_completeTask = IcePy.Operation('completeTask', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, (), (((), _M_gtr._t_GameTaskResultT),), (), None, ())

    _M_gtr.IGtrServer = IGtrServer
    del IGtrServer

    _M_gtr.IGtrServerPrx = IGtrServerPrx
    del IGtrServerPrx

# End of module gtr
