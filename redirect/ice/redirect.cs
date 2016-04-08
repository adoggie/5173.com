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

#if __MonoCS__

using _System = System;
using _Microsoft = Microsoft;
#else

using _System = global::System;
using _Microsoft = global::Microsoft;
#endif

namespace rd
{
    public class CallResultT : _System.ICloneable
    {
        #region Slice data members

        public bool succ;

        public int errNo;

        public string msg;

        #endregion

        #region Constructors

        public CallResultT()
        {
        }

        public CallResultT(bool succ, int errNo, string msg)
        {
            this.succ = succ;
            this.errNo = errNo;
            this.msg = msg;
        }

        #endregion

        #region ICloneable members

        public object Clone()
        {
            return MemberwiseClone();
        }

        #endregion

        #region Object members

        public override int GetHashCode()
        {
            int h__ = 0;
            h__ = 5 * h__ + succ.GetHashCode();
            h__ = 5 * h__ + errNo.GetHashCode();
            if(msg != null)
            {
                h__ = 5 * h__ + msg.GetHashCode();
            }
            return h__;
        }

        public override bool Equals(object other__)
        {
            if(object.ReferenceEquals(this, other__))
            {
                return true;
            }
            if(other__ == null)
            {
                return false;
            }
            if(GetType() != other__.GetType())
            {
                return false;
            }
            CallResultT o__ = (CallResultT)other__;
            if(!succ.Equals(o__.succ))
            {
                return false;
            }
            if(!errNo.Equals(o__.errNo))
            {
                return false;
            }
            if(msg == null)
            {
                if(o__.msg != null)
                {
                    return false;
                }
            }
            else
            {
                if(!msg.Equals(o__.msg))
                {
                    return false;
                }
            }
            return true;
        }

        #endregion

        #region Comparison members

        public static bool operator==(CallResultT lhs__, CallResultT rhs__)
        {
            return Equals(lhs__, rhs__);
        }

        public static bool operator!=(CallResultT lhs__, CallResultT rhs__)
        {
            return !Equals(lhs__, rhs__);
        }

        #endregion

        #region Marshalling support

        public void write__(IceInternal.BasicStream os__)
        {
            os__.writeBool(succ);
            os__.writeInt(errNo);
            os__.writeString(msg);
        }

        public void read__(IceInternal.BasicStream is__)
        {
            succ = is__.readBool();
            errNo = is__.readInt();
            msg = is__.readString();
        }

        #endregion
    }

    public interface IService : Ice.Object, IServiceOperations_, IServiceOperationsNC_
    {
    }

    public struct PingTargetT
    {
        #region Slice data members

        public int netaddr;

        #endregion

        #region Constructor

        public PingTargetT(int netaddr)
        {
            this.netaddr = netaddr;
        }

        #endregion

        #region Object members

        public override int GetHashCode()
        {
            int h__ = 0;
            h__ = 5 * h__ + netaddr.GetHashCode();
            return h__;
        }

        public override bool Equals(object other__)
        {
            if(!(other__ is PingTargetT))
            {
                return false;
            }
            PingTargetT o__ = (PingTargetT)other__;
            if(!netaddr.Equals(o__.netaddr))
            {
                return false;
            }
            return true;
        }

        #endregion

        #region Comparison members

        public static bool operator==(PingTargetT lhs__, PingTargetT rhs__)
        {
            return Equals(lhs__, rhs__);
        }

        public static bool operator!=(PingTargetT lhs__, PingTargetT rhs__)
        {
            return !Equals(lhs__, rhs__);
        }

        #endregion

        #region Marshalling support

        public void write__(IceInternal.BasicStream os__)
        {
            os__.writeInt(netaddr);
        }

        public void read__(IceInternal.BasicStream is__)
        {
            netaddr = is__.readInt();
        }

        #endregion
    }

    public struct PingResultT
    {
        #region Slice data members

        public int netaddr;

        public int responseTime;

        public int timetick;

        #endregion

        #region Constructor

        public PingResultT(int netaddr, int responseTime, int timetick)
        {
            this.netaddr = netaddr;
            this.responseTime = responseTime;
            this.timetick = timetick;
        }

        #endregion

        #region Object members

        public override int GetHashCode()
        {
            int h__ = 0;
            h__ = 5 * h__ + netaddr.GetHashCode();
            h__ = 5 * h__ + responseTime.GetHashCode();
            h__ = 5 * h__ + timetick.GetHashCode();
            return h__;
        }

        public override bool Equals(object other__)
        {
            if(!(other__ is PingResultT))
            {
                return false;
            }
            PingResultT o__ = (PingResultT)other__;
            if(!netaddr.Equals(o__.netaddr))
            {
                return false;
            }
            if(!responseTime.Equals(o__.responseTime))
            {
                return false;
            }
            if(!timetick.Equals(o__.timetick))
            {
                return false;
            }
            return true;
        }

        #endregion

        #region Comparison members

        public static bool operator==(PingResultT lhs__, PingResultT rhs__)
        {
            return Equals(lhs__, rhs__);
        }

        public static bool operator!=(PingResultT lhs__, PingResultT rhs__)
        {
            return !Equals(lhs__, rhs__);
        }

        #endregion

        #region Marshalling support

        public void write__(IceInternal.BasicStream os__)
        {
            os__.writeInt(netaddr);
            os__.writeInt(responseTime);
            os__.writeInt(timetick);
        }

        public void read__(IceInternal.BasicStream is__)
        {
            netaddr = is__.readInt();
            responseTime = is__.readInt();
            timetick = is__.readInt();
        }

        #endregion
    }

    public class RdPingerInfoT : _System.ICloneable
    {
        #region Slice data members

        public string id;

        public string ip;

        #endregion

        #region Constructors

        public RdPingerInfoT()
        {
        }

        public RdPingerInfoT(string id, string ip)
        {
            this.id = id;
            this.ip = ip;
        }

        #endregion

        #region ICloneable members

        public object Clone()
        {
            return MemberwiseClone();
        }

        #endregion

        #region Object members

        public override int GetHashCode()
        {
            int h__ = 0;
            if(id != null)
            {
                h__ = 5 * h__ + id.GetHashCode();
            }
            if(ip != null)
            {
                h__ = 5 * h__ + ip.GetHashCode();
            }
            return h__;
        }

        public override bool Equals(object other__)
        {
            if(object.ReferenceEquals(this, other__))
            {
                return true;
            }
            if(other__ == null)
            {
                return false;
            }
            if(GetType() != other__.GetType())
            {
                return false;
            }
            RdPingerInfoT o__ = (RdPingerInfoT)other__;
            if(id == null)
            {
                if(o__.id != null)
                {
                    return false;
                }
            }
            else
            {
                if(!id.Equals(o__.id))
                {
                    return false;
                }
            }
            if(ip == null)
            {
                if(o__.ip != null)
                {
                    return false;
                }
            }
            else
            {
                if(!ip.Equals(o__.ip))
                {
                    return false;
                }
            }
            return true;
        }

        #endregion

        #region Comparison members

        public static bool operator==(RdPingerInfoT lhs__, RdPingerInfoT rhs__)
        {
            return Equals(lhs__, rhs__);
        }

        public static bool operator!=(RdPingerInfoT lhs__, RdPingerInfoT rhs__)
        {
            return !Equals(lhs__, rhs__);
        }

        #endregion

        #region Marshalling support

        public void write__(IceInternal.BasicStream os__)
        {
            os__.writeString(id);
            os__.writeString(ip);
        }

        public void read__(IceInternal.BasicStream is__)
        {
            id = is__.readString();
            ip = is__.readString();
        }

        #endregion
    }

    public class RdServerInfoT : _System.ICloneable
    {
        #region Slice data members

        public string ip;

        public int port;

        public string mac;

        #endregion

        #region Constructors

        public RdServerInfoT()
        {
        }

        public RdServerInfoT(string ip, int port, string mac)
        {
            this.ip = ip;
            this.port = port;
            this.mac = mac;
        }

        #endregion

        #region ICloneable members

        public object Clone()
        {
            return MemberwiseClone();
        }

        #endregion

        #region Object members

        public override int GetHashCode()
        {
            int h__ = 0;
            if(ip != null)
            {
                h__ = 5 * h__ + ip.GetHashCode();
            }
            h__ = 5 * h__ + port.GetHashCode();
            if(mac != null)
            {
                h__ = 5 * h__ + mac.GetHashCode();
            }
            return h__;
        }

        public override bool Equals(object other__)
        {
            if(object.ReferenceEquals(this, other__))
            {
                return true;
            }
            if(other__ == null)
            {
                return false;
            }
            if(GetType() != other__.GetType())
            {
                return false;
            }
            RdServerInfoT o__ = (RdServerInfoT)other__;
            if(ip == null)
            {
                if(o__.ip != null)
                {
                    return false;
                }
            }
            else
            {
                if(!ip.Equals(o__.ip))
                {
                    return false;
                }
            }
            if(!port.Equals(o__.port))
            {
                return false;
            }
            if(mac == null)
            {
                if(o__.mac != null)
                {
                    return false;
                }
            }
            else
            {
                if(!mac.Equals(o__.mac))
                {
                    return false;
                }
            }
            return true;
        }

        #endregion

        #region Comparison members

        public static bool operator==(RdServerInfoT lhs__, RdServerInfoT rhs__)
        {
            return Equals(lhs__, rhs__);
        }

        public static bool operator!=(RdServerInfoT lhs__, RdServerInfoT rhs__)
        {
            return !Equals(lhs__, rhs__);
        }

        #endregion

        #region Marshalling support

        public void write__(IceInternal.BasicStream os__)
        {
            os__.writeString(ip);
            os__.writeInt(port);
            os__.writeString(mac);
        }

        public void read__(IceInternal.BasicStream is__)
        {
            ip = is__.readString();
            port = is__.readInt();
            mac = is__.readString();
        }

        #endregion
    }

    public class RdFrontInfoT : _System.ICloneable
    {
        #region Slice data members

        public string id;

        public string ip;

        #endregion

        #region Constructors

        public RdFrontInfoT()
        {
        }

        public RdFrontInfoT(string id, string ip)
        {
            this.id = id;
            this.ip = ip;
        }

        #endregion

        #region ICloneable members

        public object Clone()
        {
            return MemberwiseClone();
        }

        #endregion

        #region Object members

        public override int GetHashCode()
        {
            int h__ = 0;
            if(id != null)
            {
                h__ = 5 * h__ + id.GetHashCode();
            }
            if(ip != null)
            {
                h__ = 5 * h__ + ip.GetHashCode();
            }
            return h__;
        }

        public override bool Equals(object other__)
        {
            if(object.ReferenceEquals(this, other__))
            {
                return true;
            }
            if(other__ == null)
            {
                return false;
            }
            if(GetType() != other__.GetType())
            {
                return false;
            }
            RdFrontInfoT o__ = (RdFrontInfoT)other__;
            if(id == null)
            {
                if(o__.id != null)
                {
                    return false;
                }
            }
            else
            {
                if(!id.Equals(o__.id))
                {
                    return false;
                }
            }
            if(ip == null)
            {
                if(o__.ip != null)
                {
                    return false;
                }
            }
            else
            {
                if(!ip.Equals(o__.ip))
                {
                    return false;
                }
            }
            return true;
        }

        #endregion

        #region Comparison members

        public static bool operator==(RdFrontInfoT lhs__, RdFrontInfoT rhs__)
        {
            return Equals(lhs__, rhs__);
        }

        public static bool operator!=(RdFrontInfoT lhs__, RdFrontInfoT rhs__)
        {
            return !Equals(lhs__, rhs__);
        }

        #endregion

        #region Marshalling support

        public void write__(IceInternal.BasicStream os__)
        {
            os__.writeString(id);
            os__.writeString(ip);
        }

        public void read__(IceInternal.BasicStream is__)
        {
            id = is__.readString();
            ip = is__.readString();
        }

        #endregion
    }

    public class RdWorkSheetT : _System.ICloneable
    {
        #region Slice data members

        public string areaName;

        public string tradeNo;

        public int gameId;

        #endregion

        #region Constructors

        public RdWorkSheetT()
        {
        }

        public RdWorkSheetT(string areaName, string tradeNo, int gameId)
        {
            this.areaName = areaName;
            this.tradeNo = tradeNo;
            this.gameId = gameId;
        }

        #endregion

        #region ICloneable members

        public object Clone()
        {
            return MemberwiseClone();
        }

        #endregion

        #region Object members

        public override int GetHashCode()
        {
            int h__ = 0;
            if(areaName != null)
            {
                h__ = 5 * h__ + areaName.GetHashCode();
            }
            if(tradeNo != null)
            {
                h__ = 5 * h__ + tradeNo.GetHashCode();
            }
            h__ = 5 * h__ + gameId.GetHashCode();
            return h__;
        }

        public override bool Equals(object other__)
        {
            if(object.ReferenceEquals(this, other__))
            {
                return true;
            }
            if(other__ == null)
            {
                return false;
            }
            if(GetType() != other__.GetType())
            {
                return false;
            }
            RdWorkSheetT o__ = (RdWorkSheetT)other__;
            if(areaName == null)
            {
                if(o__.areaName != null)
                {
                    return false;
                }
            }
            else
            {
                if(!areaName.Equals(o__.areaName))
                {
                    return false;
                }
            }
            if(tradeNo == null)
            {
                if(o__.tradeNo != null)
                {
                    return false;
                }
            }
            else
            {
                if(!tradeNo.Equals(o__.tradeNo))
                {
                    return false;
                }
            }
            if(!gameId.Equals(o__.gameId))
            {
                return false;
            }
            return true;
        }

        #endregion

        #region Comparison members

        public static bool operator==(RdWorkSheetT lhs__, RdWorkSheetT rhs__)
        {
            return Equals(lhs__, rhs__);
        }

        public static bool operator!=(RdWorkSheetT lhs__, RdWorkSheetT rhs__)
        {
            return !Equals(lhs__, rhs__);
        }

        #endregion

        #region Marshalling support

        public void write__(IceInternal.BasicStream os__)
        {
            os__.writeString(areaName);
            os__.writeString(tradeNo);
            os__.writeInt(gameId);
        }

        public void read__(IceInternal.BasicStream is__)
        {
            areaName = is__.readString();
            tradeNo = is__.readString();
            gameId = is__.readInt();
        }

        #endregion
    }

    public interface IRdDispatcher : Ice.Object, IRdDispatcherOperations_, IRdDispatcherOperationsNC_, rd.IService
    {
    }

    public interface IRdFront : Ice.Object, IRdFrontOperations_, IRdFrontOperationsNC_
    {
    }
}

namespace rd
{
    public interface IServicePrx : Ice.ObjectPrx
    {
        string getSequence();
        string getSequence(_System.Collections.Generic.Dictionary<string, string> context__);

        string ice_getType_();
        string ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__);

        string getId();
        string getId(_System.Collections.Generic.Dictionary<string, string> context__);

        int getTimestamp();
        int getTimestamp(_System.Collections.Generic.Dictionary<string, string> context__);

        string getVersion();
        string getVersion(_System.Collections.Generic.Dictionary<string, string> context__);
    }

    public interface IRdDispatcherPrx : rd.IServicePrx
    {
        rd.PingTargetT[] getPingList(rd.RdPingerInfoT pinger);
        rd.PingTargetT[] getPingList(rd.RdPingerInfoT pinger, _System.Collections.Generic.Dictionary<string, string> context__);

        void completePing(rd.RdPingerInfoT pinger, rd.PingResultT[] result);
        void completePing(rd.RdPingerInfoT pinger, rd.PingResultT[] result, _System.Collections.Generic.Dictionary<string, string> context__);

        rd.RdServerInfoT[] getBastRdServers(string areaName, int reqnum, rd.RdFrontInfoT front);
        rd.RdServerInfoT[] getBastRdServers(string areaName, int reqnum, rd.RdFrontInfoT front, _System.Collections.Generic.Dictionary<string, string> context__);

        rd.CallResultT connectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet);
        rd.CallResultT connectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet, _System.Collections.Generic.Dictionary<string, string> context__);

        rd.CallResultT disconnectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet);
        rd.CallResultT disconnectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet, _System.Collections.Generic.Dictionary<string, string> context__);
    }

    public interface IRdFrontPrx : Ice.ObjectPrx
    {
        rd.CallResultT prepare(rd.RdWorkSheetT sheet, int timeout);
        rd.CallResultT prepare(rd.RdWorkSheetT sheet, int timeout, _System.Collections.Generic.Dictionary<string, string> context__);

        void end();
        void end(_System.Collections.Generic.Dictionary<string, string> context__);
    }
}

namespace rd
{
    public interface IServiceOperations_
    {
        string getSequence(Ice.Current current__);

        string ice_getType_(Ice.Current current__);

        string getId(Ice.Current current__);

        int getTimestamp(Ice.Current current__);

        string getVersion(Ice.Current current__);
    }

    public interface IServiceOperationsNC_
    {
        string getSequence();

        string ice_getType_();

        string getId();

        int getTimestamp();

        string getVersion();
    }

    public interface IRdDispatcherOperations_ : rd.IServiceOperations_
    {
        rd.PingTargetT[] getPingList(rd.RdPingerInfoT pinger, Ice.Current current__);

        void completePing(rd.RdPingerInfoT pinger, rd.PingResultT[] result, Ice.Current current__);

        rd.RdServerInfoT[] getBastRdServers(string areaName, int reqnum, rd.RdFrontInfoT front, Ice.Current current__);

        rd.CallResultT connectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet, Ice.Current current__);

        rd.CallResultT disconnectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet, Ice.Current current__);
    }

    public interface IRdDispatcherOperationsNC_ : rd.IServiceOperationsNC_
    {
        rd.PingTargetT[] getPingList(rd.RdPingerInfoT pinger);

        void completePing(rd.RdPingerInfoT pinger, rd.PingResultT[] result);

        rd.RdServerInfoT[] getBastRdServers(string areaName, int reqnum, rd.RdFrontInfoT front);

        rd.CallResultT connectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet);

        rd.CallResultT disconnectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet);
    }

    public interface IRdFrontOperations_
    {
        rd.CallResultT prepare(rd.RdWorkSheetT sheet, int timeout, Ice.Current current__);

        void end(Ice.Current current__);
    }

    public interface IRdFrontOperationsNC_
    {
        rd.CallResultT prepare(rd.RdWorkSheetT sheet, int timeout);

        void end();
    }
}

namespace rd
{
    public sealed class HashValueSetHelper
    {
        public static void write(IceInternal.BasicStream os__,
                                 _System.Collections.Generic.Dictionary<string, string> v__)
        {
            if(v__ == null)
            {
                os__.writeSize(0);
            }
            else
            {
                os__.writeSize(v__.Count);
                foreach(_System.Collections.Generic.KeyValuePair<string, string> e__ in v__)
                {
                    os__.writeString(e__.Key);
                    os__.writeString(e__.Value);
                }
            }
        }

        public static _System.Collections.Generic.Dictionary<string, string> read(IceInternal.BasicStream is__)
        {
            int sz__ = is__.readSize();
            _System.Collections.Generic.Dictionary<string, string> r__ = new _System.Collections.Generic.Dictionary<string, string>();
            for(int i__ = 0; i__ < sz__; ++i__)
            {
                string k__;
                k__ = is__.readString();
                string v__;
                v__ = is__.readString();
                r__[k__] = v__;
            }
            return r__;
        }
    }

    public sealed class ReturnValueTHelper
    {
        public static void write(IceInternal.BasicStream os__,
                                 _System.Collections.Generic.Dictionary<string, string> v__)
        {
            if(v__ == null)
            {
                os__.writeSize(0);
            }
            else
            {
                os__.writeSize(v__.Count);
                foreach(_System.Collections.Generic.KeyValuePair<string, string> e__ in v__)
                {
                    os__.writeString(e__.Key);
                    os__.writeString(e__.Value);
                }
            }
        }

        public static _System.Collections.Generic.Dictionary<string, string> read(IceInternal.BasicStream is__)
        {
            int sz__ = is__.readSize();
            _System.Collections.Generic.Dictionary<string, string> r__ = new _System.Collections.Generic.Dictionary<string, string>();
            for(int i__ = 0; i__ < sz__; ++i__)
            {
                string k__;
                k__ = is__.readString();
                string v__;
                v__ = is__.readString();
                r__[k__] = v__;
            }
            return r__;
        }
    }

    public sealed class StreamDataTHelper
    {
        public static void write(IceInternal.BasicStream os__, byte[] v__)
        {
            os__.writeByteSeq(v__);
        }

        public static byte[] read(IceInternal.BasicStream is__)
        {
            byte[] v__;
            v__ = is__.readByteSeq();
            return v__;
        }
    }

    public sealed class StringListTHelper
    {
        public static void write(IceInternal.BasicStream os__, string[] v__)
        {
            os__.writeStringSeq(v__);
        }

        public static string[] read(IceInternal.BasicStream is__)
        {
            string[] v__;
            v__ = is__.readStringSeq();
            return v__;
        }
    }

    public sealed class HashValueListTHelper
    {
        public static void write(IceInternal.BasicStream os__, _System.Collections.Generic.Dictionary<string, string>[] v__)
        {
            if(v__ == null)
            {
                os__.writeSize(0);
            }
            else
            {
                os__.writeSize(v__.Length);
                for(int ix__ = 0; ix__ < v__.Length; ++ix__)
                {
                    rd.HashValueSetHelper.write(os__, v__[ix__]);
                }
            }
        }

        public static _System.Collections.Generic.Dictionary<string, string>[] read(IceInternal.BasicStream is__)
        {
            _System.Collections.Generic.Dictionary<string, string>[] v__;
            {
                int szx__ = is__.readSize();
                is__.startSeq(szx__, 1);
                v__ = new _System.Collections.Generic.Dictionary<string, string>[szx__];
                for(int ix__ = 0; ix__ < szx__; ++ix__)
                {
                    v__[ix__] = rd.HashValueSetHelper.read(is__);
                    is__.checkSeq();
                    is__.endElement();
                }
                is__.endSeq(szx__);
            }
            return v__;
        }
    }

    public sealed class IntListTHelper
    {
        public static void write(IceInternal.BasicStream os__, int[] v__)
        {
            os__.writeIntSeq(v__);
        }

        public static int[] read(IceInternal.BasicStream is__)
        {
            int[] v__;
            v__ = is__.readIntSeq();
            return v__;
        }
    }

    public sealed class StringListListTHelper
    {
        public static void write(IceInternal.BasicStream os__, string[][] v__)
        {
            if(v__ == null)
            {
                os__.writeSize(0);
            }
            else
            {
                os__.writeSize(v__.Length);
                for(int ix__ = 0; ix__ < v__.Length; ++ix__)
                {
                    rd.StringListTHelper.write(os__, v__[ix__]);
                }
            }
        }

        public static string[][] read(IceInternal.BasicStream is__)
        {
            string[][] v__;
            {
                int szx__ = is__.readSize();
                is__.startSeq(szx__, 1);
                v__ = new string[szx__][];
                for(int ix__ = 0; ix__ < szx__; ++ix__)
                {
                    v__[ix__] = rd.StringListTHelper.read(is__);
                    is__.endElement();
                }
                is__.endSeq(szx__);
            }
            return v__;
        }
    }

    public sealed class IServicePrxHelper : Ice.ObjectPrxHelperBase, IServicePrx
    {
        #region Synchronous operations

        public string getId()
        {
            return getId(null, false);
        }

        public string getId(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return getId(context__, true);
        }

        private string getId(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
        {
            if(explicitContext__ && context__ == null)
            {
                context__ = emptyContext_;
            }
            int cnt__ = 0;
            while(true)
            {
                Ice.ObjectDel_ delBase__ = null;
                try
                {
                    checkTwowayOnly__("getId");
                    delBase__ = getDelegate__(false);
                    IServiceDel_ del__ = (IServiceDel_)delBase__;
                    return del__.getId(context__);
                }
                catch(IceInternal.LocalExceptionWrapper ex__)
                {
                    handleExceptionWrapper__(delBase__, ex__, null);
                }
                catch(Ice.LocalException ex__)
                {
                    handleException__(delBase__, ex__, null, ref cnt__);
                }
            }
        }

        public string getSequence()
        {
            return getSequence(null, false);
        }

        public string getSequence(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return getSequence(context__, true);
        }

        private string getSequence(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
        {
            if(explicitContext__ && context__ == null)
            {
                context__ = emptyContext_;
            }
            int cnt__ = 0;
            while(true)
            {
                Ice.ObjectDel_ delBase__ = null;
                try
                {
                    checkTwowayOnly__("getSequence");
                    delBase__ = getDelegate__(false);
                    IServiceDel_ del__ = (IServiceDel_)delBase__;
                    return del__.getSequence(context__);
                }
                catch(IceInternal.LocalExceptionWrapper ex__)
                {
                    handleExceptionWrapper__(delBase__, ex__, null);
                }
                catch(Ice.LocalException ex__)
                {
                    handleException__(delBase__, ex__, null, ref cnt__);
                }
            }
        }

        public int getTimestamp()
        {
            return getTimestamp(null, false);
        }

        public int getTimestamp(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return getTimestamp(context__, true);
        }

        private int getTimestamp(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
        {
            if(explicitContext__ && context__ == null)
            {
                context__ = emptyContext_;
            }
            int cnt__ = 0;
            while(true)
            {
                Ice.ObjectDel_ delBase__ = null;
                try
                {
                    checkTwowayOnly__("getTimestamp");
                    delBase__ = getDelegate__(false);
                    IServiceDel_ del__ = (IServiceDel_)delBase__;
                    return del__.getTimestamp(context__);
                }
                catch(IceInternal.LocalExceptionWrapper ex__)
                {
                    handleExceptionWrapper__(delBase__, ex__, null);
                }
                catch(Ice.LocalException ex__)
                {
                    handleException__(delBase__, ex__, null, ref cnt__);
                }
            }
        }

        public string ice_getType_()
        {
            return ice_getType_(null, false);
        }

        public string ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return ice_getType_(context__, true);
        }

        private string ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
        {
            if(explicitContext__ && context__ == null)
            {
                context__ = emptyContext_;
            }
            int cnt__ = 0;
            while(true)
            {
                Ice.ObjectDel_ delBase__ = null;
                try
                {
                    checkTwowayOnly__("getType");
                    delBase__ = getDelegate__(false);
                    IServiceDel_ del__ = (IServiceDel_)delBase__;
                    return del__.ice_getType_(context__);
                }
                catch(IceInternal.LocalExceptionWrapper ex__)
                {
                    handleExceptionWrapper__(delBase__, ex__, null);
                }
                catch(Ice.LocalException ex__)
                {
                    handleException__(delBase__, ex__, null, ref cnt__);
                }
            }
        }

        public string getVersion()
        {
            return getVersion(null, false);
        }

        public string getVersion(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return getVersion(context__, true);
        }

        private string getVersion(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
        {
            if(explicitContext__ && context__ == null)
            {
                context__ = emptyContext_;
            }
            int cnt__ = 0;
            while(true)
            {
                Ice.ObjectDel_ delBase__ = null;
                try
                {
                    checkTwowayOnly__("getVersion");
                    delBase__ = getDelegate__(false);
                    IServiceDel_ del__ = (IServiceDel_)delBase__;
                    return del__.getVersion(context__);
                }
                catch(IceInternal.LocalExceptionWrapper ex__)
                {
                    handleExceptionWrapper__(delBase__, ex__, null);
                }
                catch(Ice.LocalException ex__)
                {
                    handleException__(delBase__, ex__, null, ref cnt__);
                }
            }
        }

        #endregion

        #region Checked and unchecked cast operations

        public static IServicePrx checkedCast(Ice.ObjectPrx b)
        {
            if(b == null)
            {
                return null;
            }
            IServicePrx r = b as IServicePrx;
            if((r == null) && b.ice_isA("::rd::IService"))
            {
                IServicePrxHelper h = new IServicePrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IServicePrx checkedCast(Ice.ObjectPrx b, _System.Collections.Generic.Dictionary<string, string> ctx)
        {
            if(b == null)
            {
                return null;
            }
            IServicePrx r = b as IServicePrx;
            if((r == null) && b.ice_isA("::rd::IService", ctx))
            {
                IServicePrxHelper h = new IServicePrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IServicePrx checkedCast(Ice.ObjectPrx b, string f)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            try
            {
                if(bb.ice_isA("::rd::IService"))
                {
                    IServicePrxHelper h = new IServicePrxHelper();
                    h.copyFrom__(bb);
                    return h;
                }
            }
            catch(Ice.FacetNotExistException)
            {
            }
            return null;
        }

        public static IServicePrx checkedCast(Ice.ObjectPrx b, string f, _System.Collections.Generic.Dictionary<string, string> ctx)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            try
            {
                if(bb.ice_isA("::rd::IService", ctx))
                {
                    IServicePrxHelper h = new IServicePrxHelper();
                    h.copyFrom__(bb);
                    return h;
                }
            }
            catch(Ice.FacetNotExistException)
            {
            }
            return null;
        }

        public static IServicePrx uncheckedCast(Ice.ObjectPrx b)
        {
            if(b == null)
            {
                return null;
            }
            IServicePrx r = b as IServicePrx;
            if(r == null)
            {
                IServicePrxHelper h = new IServicePrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IServicePrx uncheckedCast(Ice.ObjectPrx b, string f)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            IServicePrxHelper h = new IServicePrxHelper();
            h.copyFrom__(bb);
            return h;
        }

        #endregion

        #region Marshaling support

        protected override Ice.ObjectDelM_ createDelegateM__()
        {
            return new IServiceDelM_();
        }

        protected override Ice.ObjectDelD_ createDelegateD__()
        {
            return new IServiceDelD_();
        }

        public static void write__(IceInternal.BasicStream os__, IServicePrx v__)
        {
            os__.writeProxy(v__);
        }

        public static IServicePrx read__(IceInternal.BasicStream is__)
        {
            Ice.ObjectPrx proxy = is__.readProxy();
            if(proxy != null)
            {
                IServicePrxHelper result = new IServicePrxHelper();
                result.copyFrom__(proxy);
                return result;
            }
            return null;
        }

        #endregion
    }

    public sealed class PingTargetListTHelper
    {
        public static void write(IceInternal.BasicStream os__, rd.PingTargetT[] v__)
        {
            if(v__ == null)
            {
                os__.writeSize(0);
            }
            else
            {
                os__.writeSize(v__.Length);
                for(int ix__ = 0; ix__ < v__.Length; ++ix__)
                {
                    v__[ix__].write__(os__);
                }
            }
        }

        public static rd.PingTargetT[] read(IceInternal.BasicStream is__)
        {
            rd.PingTargetT[] v__;
            {
                int szx__ = is__.readSize();
                is__.checkFixedSeq(szx__, 4);
                v__ = new rd.PingTargetT[szx__];
                for(int ix__ = 0; ix__ < szx__; ++ix__)
                {
                    v__[ix__].read__(is__);
                }
            }
            return v__;
        }
    }

    public sealed class PingResultListTHelper
    {
        public static void write(IceInternal.BasicStream os__, rd.PingResultT[] v__)
        {
            if(v__ == null)
            {
                os__.writeSize(0);
            }
            else
            {
                os__.writeSize(v__.Length);
                for(int ix__ = 0; ix__ < v__.Length; ++ix__)
                {
                    v__[ix__].write__(os__);
                }
            }
        }

        public static rd.PingResultT[] read(IceInternal.BasicStream is__)
        {
            rd.PingResultT[] v__;
            {
                int szx__ = is__.readSize();
                is__.checkFixedSeq(szx__, 12);
                v__ = new rd.PingResultT[szx__];
                for(int ix__ = 0; ix__ < szx__; ++ix__)
                {
                    v__[ix__].read__(is__);
                }
            }
            return v__;
        }
    }

    public sealed class RdServerInfoListTHelper
    {
        public static void write(IceInternal.BasicStream os__, rd.RdServerInfoT[] v__)
        {
            if(v__ == null)
            {
                os__.writeSize(0);
            }
            else
            {
                os__.writeSize(v__.Length);
                for(int ix__ = 0; ix__ < v__.Length; ++ix__)
                {
                    (v__[ix__] == null ? new rd.RdServerInfoT() : v__[ix__]).write__(os__);
                }
            }
        }

        public static rd.RdServerInfoT[] read(IceInternal.BasicStream is__)
        {
            rd.RdServerInfoT[] v__;
            {
                int szx__ = is__.readSize();
                is__.startSeq(szx__, 6);
                v__ = new rd.RdServerInfoT[szx__];
                for(int ix__ = 0; ix__ < szx__; ++ix__)
                {
                    v__[ix__] = new rd.RdServerInfoT();
                    v__[ix__].read__(is__);
                    is__.checkSeq();
                    is__.endElement();
                }
                is__.endSeq(szx__);
            }
            return v__;
        }
    }

    public sealed class IRdDispatcherPrxHelper : Ice.ObjectPrxHelperBase, IRdDispatcherPrx
    {
        #region Synchronous operations

        public void completePing(rd.RdPingerInfoT pinger, rd.PingResultT[] result)
        {
            completePing(pinger, result, null, false);
        }

        public void completePing(rd.RdPingerInfoT pinger, rd.PingResultT[] result, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            completePing(pinger, result, context__, true);
        }

        private void completePing(rd.RdPingerInfoT pinger, rd.PingResultT[] result, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
        {
            if(explicitContext__ && context__ == null)
            {
                context__ = emptyContext_;
            }
            int cnt__ = 0;
            while(true)
            {
                Ice.ObjectDel_ delBase__ = null;
                try
                {
                    delBase__ = getDelegate__(false);
                    IRdDispatcherDel_ del__ = (IRdDispatcherDel_)delBase__;
                    del__.completePing(pinger, result, context__);
                    return;
                }
                catch(IceInternal.LocalExceptionWrapper ex__)
                {
                    handleExceptionWrapper__(delBase__, ex__, null);
                }
                catch(Ice.LocalException ex__)
                {
                    handleException__(delBase__, ex__, null, ref cnt__);
                }
            }
        }

        public rd.CallResultT connectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet)
        {
            return connectedRdServer(front, server, sheet, null, false);
        }

        public rd.CallResultT connectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            return connectedRdServer(front, server, sheet, context__, true);
        }

        private rd.CallResultT connectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
        {
            if(explicitContext__ && context__ == null)
            {
                context__ = emptyContext_;
            }
            int cnt__ = 0;
            while(true)
            {
                Ice.ObjectDel_ delBase__ = null;
                try
                {
                    checkTwowayOnly__("connectedRdServer");
                    delBase__ = getDelegate__(false);
                    IRdDispatcherDel_ del__ = (IRdDispatcherDel_)delBase__;
                    return del__.connectedRdServer(front, server, sheet, context__);
                }
                catch(IceInternal.LocalExceptionWrapper ex__)
                {
                    handleExceptionWrapper__(delBase__, ex__, null);
                }
                catch(Ice.LocalException ex__)
                {
                    handleException__(delBase__, ex__, null, ref cnt__);
                }
            }
        }

        public rd.CallResultT disconnectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet)
        {
            return disconnectedRdServer(front, server, sheet, null, false);
        }

        public rd.CallResultT disconnectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            return disconnectedRdServer(front, server, sheet, context__, true);
        }

        private rd.CallResultT disconnectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
        {
            if(explicitContext__ && context__ == null)
            {
                context__ = emptyContext_;
            }
            int cnt__ = 0;
            while(true)
            {
                Ice.ObjectDel_ delBase__ = null;
                try
                {
                    checkTwowayOnly__("disconnectedRdServer");
                    delBase__ = getDelegate__(false);
                    IRdDispatcherDel_ del__ = (IRdDispatcherDel_)delBase__;
                    return del__.disconnectedRdServer(front, server, sheet, context__);
                }
                catch(IceInternal.LocalExceptionWrapper ex__)
                {
                    handleExceptionWrapper__(delBase__, ex__, null);
                }
                catch(Ice.LocalException ex__)
                {
                    handleException__(delBase__, ex__, null, ref cnt__);
                }
            }
        }

        public rd.RdServerInfoT[] getBastRdServers(string areaName, int reqnum, rd.RdFrontInfoT front)
        {
            return getBastRdServers(areaName, reqnum, front, null, false);
        }

        public rd.RdServerInfoT[] getBastRdServers(string areaName, int reqnum, rd.RdFrontInfoT front, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            return getBastRdServers(areaName, reqnum, front, context__, true);
        }

        private rd.RdServerInfoT[] getBastRdServers(string areaName, int reqnum, rd.RdFrontInfoT front, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
        {
            if(explicitContext__ && context__ == null)
            {
                context__ = emptyContext_;
            }
            int cnt__ = 0;
            while(true)
            {
                Ice.ObjectDel_ delBase__ = null;
                try
                {
                    checkTwowayOnly__("getBastRdServers");
                    delBase__ = getDelegate__(false);
                    IRdDispatcherDel_ del__ = (IRdDispatcherDel_)delBase__;
                    return del__.getBastRdServers(areaName, reqnum, front, context__);
                }
                catch(IceInternal.LocalExceptionWrapper ex__)
                {
                    handleExceptionWrapper__(delBase__, ex__, null);
                }
                catch(Ice.LocalException ex__)
                {
                    handleException__(delBase__, ex__, null, ref cnt__);
                }
            }
        }

        public rd.PingTargetT[] getPingList(rd.RdPingerInfoT pinger)
        {
            return getPingList(pinger, null, false);
        }

        public rd.PingTargetT[] getPingList(rd.RdPingerInfoT pinger, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            return getPingList(pinger, context__, true);
        }

        private rd.PingTargetT[] getPingList(rd.RdPingerInfoT pinger, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
        {
            if(explicitContext__ && context__ == null)
            {
                context__ = emptyContext_;
            }
            int cnt__ = 0;
            while(true)
            {
                Ice.ObjectDel_ delBase__ = null;
                try
                {
                    checkTwowayOnly__("getPingList");
                    delBase__ = getDelegate__(false);
                    IRdDispatcherDel_ del__ = (IRdDispatcherDel_)delBase__;
                    return del__.getPingList(pinger, context__);
                }
                catch(IceInternal.LocalExceptionWrapper ex__)
                {
                    handleExceptionWrapper__(delBase__, ex__, null);
                }
                catch(Ice.LocalException ex__)
                {
                    handleException__(delBase__, ex__, null, ref cnt__);
                }
            }
        }

        public string getId()
        {
            return getId(null, false);
        }

        public string getId(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return getId(context__, true);
        }

        private string getId(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
        {
            if(explicitContext__ && context__ == null)
            {
                context__ = emptyContext_;
            }
            int cnt__ = 0;
            while(true)
            {
                Ice.ObjectDel_ delBase__ = null;
                try
                {
                    checkTwowayOnly__("getId");
                    delBase__ = getDelegate__(false);
                    IRdDispatcherDel_ del__ = (IRdDispatcherDel_)delBase__;
                    return del__.getId(context__);
                }
                catch(IceInternal.LocalExceptionWrapper ex__)
                {
                    handleExceptionWrapper__(delBase__, ex__, null);
                }
                catch(Ice.LocalException ex__)
                {
                    handleException__(delBase__, ex__, null, ref cnt__);
                }
            }
        }

        public string getSequence()
        {
            return getSequence(null, false);
        }

        public string getSequence(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return getSequence(context__, true);
        }

        private string getSequence(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
        {
            if(explicitContext__ && context__ == null)
            {
                context__ = emptyContext_;
            }
            int cnt__ = 0;
            while(true)
            {
                Ice.ObjectDel_ delBase__ = null;
                try
                {
                    checkTwowayOnly__("getSequence");
                    delBase__ = getDelegate__(false);
                    IRdDispatcherDel_ del__ = (IRdDispatcherDel_)delBase__;
                    return del__.getSequence(context__);
                }
                catch(IceInternal.LocalExceptionWrapper ex__)
                {
                    handleExceptionWrapper__(delBase__, ex__, null);
                }
                catch(Ice.LocalException ex__)
                {
                    handleException__(delBase__, ex__, null, ref cnt__);
                }
            }
        }

        public int getTimestamp()
        {
            return getTimestamp(null, false);
        }

        public int getTimestamp(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return getTimestamp(context__, true);
        }

        private int getTimestamp(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
        {
            if(explicitContext__ && context__ == null)
            {
                context__ = emptyContext_;
            }
            int cnt__ = 0;
            while(true)
            {
                Ice.ObjectDel_ delBase__ = null;
                try
                {
                    checkTwowayOnly__("getTimestamp");
                    delBase__ = getDelegate__(false);
                    IRdDispatcherDel_ del__ = (IRdDispatcherDel_)delBase__;
                    return del__.getTimestamp(context__);
                }
                catch(IceInternal.LocalExceptionWrapper ex__)
                {
                    handleExceptionWrapper__(delBase__, ex__, null);
                }
                catch(Ice.LocalException ex__)
                {
                    handleException__(delBase__, ex__, null, ref cnt__);
                }
            }
        }

        public string ice_getType_()
        {
            return ice_getType_(null, false);
        }

        public string ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return ice_getType_(context__, true);
        }

        private string ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
        {
            if(explicitContext__ && context__ == null)
            {
                context__ = emptyContext_;
            }
            int cnt__ = 0;
            while(true)
            {
                Ice.ObjectDel_ delBase__ = null;
                try
                {
                    checkTwowayOnly__("getType");
                    delBase__ = getDelegate__(false);
                    IRdDispatcherDel_ del__ = (IRdDispatcherDel_)delBase__;
                    return del__.ice_getType_(context__);
                }
                catch(IceInternal.LocalExceptionWrapper ex__)
                {
                    handleExceptionWrapper__(delBase__, ex__, null);
                }
                catch(Ice.LocalException ex__)
                {
                    handleException__(delBase__, ex__, null, ref cnt__);
                }
            }
        }

        public string getVersion()
        {
            return getVersion(null, false);
        }

        public string getVersion(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return getVersion(context__, true);
        }

        private string getVersion(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
        {
            if(explicitContext__ && context__ == null)
            {
                context__ = emptyContext_;
            }
            int cnt__ = 0;
            while(true)
            {
                Ice.ObjectDel_ delBase__ = null;
                try
                {
                    checkTwowayOnly__("getVersion");
                    delBase__ = getDelegate__(false);
                    IRdDispatcherDel_ del__ = (IRdDispatcherDel_)delBase__;
                    return del__.getVersion(context__);
                }
                catch(IceInternal.LocalExceptionWrapper ex__)
                {
                    handleExceptionWrapper__(delBase__, ex__, null);
                }
                catch(Ice.LocalException ex__)
                {
                    handleException__(delBase__, ex__, null, ref cnt__);
                }
            }
        }

        #endregion

        #region Checked and unchecked cast operations

        public static IRdDispatcherPrx checkedCast(Ice.ObjectPrx b)
        {
            if(b == null)
            {
                return null;
            }
            IRdDispatcherPrx r = b as IRdDispatcherPrx;
            if((r == null) && b.ice_isA("::rd::IRdDispatcher"))
            {
                IRdDispatcherPrxHelper h = new IRdDispatcherPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IRdDispatcherPrx checkedCast(Ice.ObjectPrx b, _System.Collections.Generic.Dictionary<string, string> ctx)
        {
            if(b == null)
            {
                return null;
            }
            IRdDispatcherPrx r = b as IRdDispatcherPrx;
            if((r == null) && b.ice_isA("::rd::IRdDispatcher", ctx))
            {
                IRdDispatcherPrxHelper h = new IRdDispatcherPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IRdDispatcherPrx checkedCast(Ice.ObjectPrx b, string f)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            try
            {
                if(bb.ice_isA("::rd::IRdDispatcher"))
                {
                    IRdDispatcherPrxHelper h = new IRdDispatcherPrxHelper();
                    h.copyFrom__(bb);
                    return h;
                }
            }
            catch(Ice.FacetNotExistException)
            {
            }
            return null;
        }

        public static IRdDispatcherPrx checkedCast(Ice.ObjectPrx b, string f, _System.Collections.Generic.Dictionary<string, string> ctx)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            try
            {
                if(bb.ice_isA("::rd::IRdDispatcher", ctx))
                {
                    IRdDispatcherPrxHelper h = new IRdDispatcherPrxHelper();
                    h.copyFrom__(bb);
                    return h;
                }
            }
            catch(Ice.FacetNotExistException)
            {
            }
            return null;
        }

        public static IRdDispatcherPrx uncheckedCast(Ice.ObjectPrx b)
        {
            if(b == null)
            {
                return null;
            }
            IRdDispatcherPrx r = b as IRdDispatcherPrx;
            if(r == null)
            {
                IRdDispatcherPrxHelper h = new IRdDispatcherPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IRdDispatcherPrx uncheckedCast(Ice.ObjectPrx b, string f)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            IRdDispatcherPrxHelper h = new IRdDispatcherPrxHelper();
            h.copyFrom__(bb);
            return h;
        }

        #endregion

        #region Marshaling support

        protected override Ice.ObjectDelM_ createDelegateM__()
        {
            return new IRdDispatcherDelM_();
        }

        protected override Ice.ObjectDelD_ createDelegateD__()
        {
            return new IRdDispatcherDelD_();
        }

        public static void write__(IceInternal.BasicStream os__, IRdDispatcherPrx v__)
        {
            os__.writeProxy(v__);
        }

        public static IRdDispatcherPrx read__(IceInternal.BasicStream is__)
        {
            Ice.ObjectPrx proxy = is__.readProxy();
            if(proxy != null)
            {
                IRdDispatcherPrxHelper result = new IRdDispatcherPrxHelper();
                result.copyFrom__(proxy);
                return result;
            }
            return null;
        }

        #endregion
    }

    public sealed class IRdFrontPrxHelper : Ice.ObjectPrxHelperBase, IRdFrontPrx
    {
        #region Synchronous operations

        public void end()
        {
            end(null, false);
        }

        public void end(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            end(context__, true);
        }

        private void end(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
        {
            if(explicitContext__ && context__ == null)
            {
                context__ = emptyContext_;
            }
            int cnt__ = 0;
            while(true)
            {
                Ice.ObjectDel_ delBase__ = null;
                try
                {
                    delBase__ = getDelegate__(false);
                    IRdFrontDel_ del__ = (IRdFrontDel_)delBase__;
                    del__.end(context__);
                    return;
                }
                catch(IceInternal.LocalExceptionWrapper ex__)
                {
                    handleExceptionWrapper__(delBase__, ex__, null);
                }
                catch(Ice.LocalException ex__)
                {
                    handleException__(delBase__, ex__, null, ref cnt__);
                }
            }
        }

        public rd.CallResultT prepare(rd.RdWorkSheetT sheet, int timeout)
        {
            return prepare(sheet, timeout, null, false);
        }

        public rd.CallResultT prepare(rd.RdWorkSheetT sheet, int timeout, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            return prepare(sheet, timeout, context__, true);
        }

        private rd.CallResultT prepare(rd.RdWorkSheetT sheet, int timeout, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
        {
            if(explicitContext__ && context__ == null)
            {
                context__ = emptyContext_;
            }
            int cnt__ = 0;
            while(true)
            {
                Ice.ObjectDel_ delBase__ = null;
                try
                {
                    checkTwowayOnly__("prepare");
                    delBase__ = getDelegate__(false);
                    IRdFrontDel_ del__ = (IRdFrontDel_)delBase__;
                    return del__.prepare(sheet, timeout, context__);
                }
                catch(IceInternal.LocalExceptionWrapper ex__)
                {
                    handleExceptionWrapper__(delBase__, ex__, null);
                }
                catch(Ice.LocalException ex__)
                {
                    handleException__(delBase__, ex__, null, ref cnt__);
                }
            }
        }

        #endregion

        #region Checked and unchecked cast operations

        public static IRdFrontPrx checkedCast(Ice.ObjectPrx b)
        {
            if(b == null)
            {
                return null;
            }
            IRdFrontPrx r = b as IRdFrontPrx;
            if((r == null) && b.ice_isA("::rd::IRdFront"))
            {
                IRdFrontPrxHelper h = new IRdFrontPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IRdFrontPrx checkedCast(Ice.ObjectPrx b, _System.Collections.Generic.Dictionary<string, string> ctx)
        {
            if(b == null)
            {
                return null;
            }
            IRdFrontPrx r = b as IRdFrontPrx;
            if((r == null) && b.ice_isA("::rd::IRdFront", ctx))
            {
                IRdFrontPrxHelper h = new IRdFrontPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IRdFrontPrx checkedCast(Ice.ObjectPrx b, string f)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            try
            {
                if(bb.ice_isA("::rd::IRdFront"))
                {
                    IRdFrontPrxHelper h = new IRdFrontPrxHelper();
                    h.copyFrom__(bb);
                    return h;
                }
            }
            catch(Ice.FacetNotExistException)
            {
            }
            return null;
        }

        public static IRdFrontPrx checkedCast(Ice.ObjectPrx b, string f, _System.Collections.Generic.Dictionary<string, string> ctx)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            try
            {
                if(bb.ice_isA("::rd::IRdFront", ctx))
                {
                    IRdFrontPrxHelper h = new IRdFrontPrxHelper();
                    h.copyFrom__(bb);
                    return h;
                }
            }
            catch(Ice.FacetNotExistException)
            {
            }
            return null;
        }

        public static IRdFrontPrx uncheckedCast(Ice.ObjectPrx b)
        {
            if(b == null)
            {
                return null;
            }
            IRdFrontPrx r = b as IRdFrontPrx;
            if(r == null)
            {
                IRdFrontPrxHelper h = new IRdFrontPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IRdFrontPrx uncheckedCast(Ice.ObjectPrx b, string f)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            IRdFrontPrxHelper h = new IRdFrontPrxHelper();
            h.copyFrom__(bb);
            return h;
        }

        #endregion

        #region Marshaling support

        protected override Ice.ObjectDelM_ createDelegateM__()
        {
            return new IRdFrontDelM_();
        }

        protected override Ice.ObjectDelD_ createDelegateD__()
        {
            return new IRdFrontDelD_();
        }

        public static void write__(IceInternal.BasicStream os__, IRdFrontPrx v__)
        {
            os__.writeProxy(v__);
        }

        public static IRdFrontPrx read__(IceInternal.BasicStream is__)
        {
            Ice.ObjectPrx proxy = is__.readProxy();
            if(proxy != null)
            {
                IRdFrontPrxHelper result = new IRdFrontPrxHelper();
                result.copyFrom__(proxy);
                return result;
            }
            return null;
        }

        #endregion
    }
}

namespace rd
{
    public interface IServiceDel_ : Ice.ObjectDel_
    {
        string getSequence(_System.Collections.Generic.Dictionary<string, string> context__);

        string ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__);

        string getId(_System.Collections.Generic.Dictionary<string, string> context__);

        int getTimestamp(_System.Collections.Generic.Dictionary<string, string> context__);

        string getVersion(_System.Collections.Generic.Dictionary<string, string> context__);
    }

    public interface IRdDispatcherDel_ : rd.IServiceDel_
    {
        rd.PingTargetT[] getPingList(rd.RdPingerInfoT pinger, _System.Collections.Generic.Dictionary<string, string> context__);

        void completePing(rd.RdPingerInfoT pinger, rd.PingResultT[] result, _System.Collections.Generic.Dictionary<string, string> context__);

        rd.RdServerInfoT[] getBastRdServers(string areaName, int reqnum, rd.RdFrontInfoT front, _System.Collections.Generic.Dictionary<string, string> context__);

        rd.CallResultT connectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet, _System.Collections.Generic.Dictionary<string, string> context__);

        rd.CallResultT disconnectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet, _System.Collections.Generic.Dictionary<string, string> context__);
    }

    public interface IRdFrontDel_ : Ice.ObjectDel_
    {
        rd.CallResultT prepare(rd.RdWorkSheetT sheet, int timeout, _System.Collections.Generic.Dictionary<string, string> context__);

        void end(_System.Collections.Generic.Dictionary<string, string> context__);
    }
}

namespace rd
{
    public sealed class IServiceDelM_ : Ice.ObjectDelM_, IServiceDel_
    {
        public string getId(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("getId", Ice.OperationMode.Normal, context__);
            try
            {
                bool ok__ = og__.invoke();
                try
                {
                    if(!ok__)
                    {
                        try
                        {
                            og__.throwUserException();
                        }
                        catch(Ice.UserException ex__)
                        {
                            throw new Ice.UnknownUserException(ex__.ice_name(), ex__);
                        }
                    }
                    IceInternal.BasicStream is__ = og__.istr();
                    is__.startReadEncaps();
                    string ret__;
                    ret__ = is__.readString();
                    is__.endReadEncaps();
                    return ret__;
                }
                catch(Ice.LocalException ex__)
                {
                    throw new IceInternal.LocalExceptionWrapper(ex__, false);
                }
            }
            finally
            {
                handler__.reclaimOutgoing(og__);
            }
        }

        public string getSequence(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("getSequence", Ice.OperationMode.Normal, context__);
            try
            {
                bool ok__ = og__.invoke();
                try
                {
                    if(!ok__)
                    {
                        try
                        {
                            og__.throwUserException();
                        }
                        catch(Ice.UserException ex__)
                        {
                            throw new Ice.UnknownUserException(ex__.ice_name(), ex__);
                        }
                    }
                    IceInternal.BasicStream is__ = og__.istr();
                    is__.startReadEncaps();
                    string ret__;
                    ret__ = is__.readString();
                    is__.endReadEncaps();
                    return ret__;
                }
                catch(Ice.LocalException ex__)
                {
                    throw new IceInternal.LocalExceptionWrapper(ex__, false);
                }
            }
            finally
            {
                handler__.reclaimOutgoing(og__);
            }
        }

        public int getTimestamp(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("getTimestamp", Ice.OperationMode.Normal, context__);
            try
            {
                bool ok__ = og__.invoke();
                try
                {
                    if(!ok__)
                    {
                        try
                        {
                            og__.throwUserException();
                        }
                        catch(Ice.UserException ex__)
                        {
                            throw new Ice.UnknownUserException(ex__.ice_name(), ex__);
                        }
                    }
                    IceInternal.BasicStream is__ = og__.istr();
                    is__.startReadEncaps();
                    int ret__;
                    ret__ = is__.readInt();
                    is__.endReadEncaps();
                    return ret__;
                }
                catch(Ice.LocalException ex__)
                {
                    throw new IceInternal.LocalExceptionWrapper(ex__, false);
                }
            }
            finally
            {
                handler__.reclaimOutgoing(og__);
            }
        }

        public string ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("getType", Ice.OperationMode.Normal, context__);
            try
            {
                bool ok__ = og__.invoke();
                try
                {
                    if(!ok__)
                    {
                        try
                        {
                            og__.throwUserException();
                        }
                        catch(Ice.UserException ex__)
                        {
                            throw new Ice.UnknownUserException(ex__.ice_name(), ex__);
                        }
                    }
                    IceInternal.BasicStream is__ = og__.istr();
                    is__.startReadEncaps();
                    string ret__;
                    ret__ = is__.readString();
                    is__.endReadEncaps();
                    return ret__;
                }
                catch(Ice.LocalException ex__)
                {
                    throw new IceInternal.LocalExceptionWrapper(ex__, false);
                }
            }
            finally
            {
                handler__.reclaimOutgoing(og__);
            }
        }

        public string getVersion(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("getVersion", Ice.OperationMode.Normal, context__);
            try
            {
                bool ok__ = og__.invoke();
                try
                {
                    if(!ok__)
                    {
                        try
                        {
                            og__.throwUserException();
                        }
                        catch(Ice.UserException ex__)
                        {
                            throw new Ice.UnknownUserException(ex__.ice_name(), ex__);
                        }
                    }
                    IceInternal.BasicStream is__ = og__.istr();
                    is__.startReadEncaps();
                    string ret__;
                    ret__ = is__.readString();
                    is__.endReadEncaps();
                    return ret__;
                }
                catch(Ice.LocalException ex__)
                {
                    throw new IceInternal.LocalExceptionWrapper(ex__, false);
                }
            }
            finally
            {
                handler__.reclaimOutgoing(og__);
            }
        }
    }

    public sealed class IRdDispatcherDelM_ : Ice.ObjectDelM_, IRdDispatcherDel_
    {
        public void completePing(rd.RdPingerInfoT pinger, rd.PingResultT[] result, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("completePing", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    if(pinger == null)
                    {
                        rd.RdPingerInfoT tmp__ = new rd.RdPingerInfoT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        pinger.write__(os__);
                    }
                    if(result == null)
                    {
                        os__.writeSize(0);
                    }
                    else
                    {
                        os__.writeSize(result.Length);
                        for(int ix__ = 0; ix__ < result.Length; ++ix__)
                        {
                            result[ix__].write__(os__);
                        }
                    }
                }
                catch(Ice.LocalException ex__)
                {
                    og__.abort(ex__);
                }
                bool ok__ = og__.invoke();
                if(!og__.istr().isEmpty())
                {
                    try
                    {
                        if(!ok__)
                        {
                            try
                            {
                                og__.throwUserException();
                            }
                            catch(Ice.UserException ex__)
                            {
                                throw new Ice.UnknownUserException(ex__.ice_name(), ex__);
                            }
                        }
                        og__.istr().skipEmptyEncaps();
                    }
                    catch(Ice.LocalException ex__)
                    {
                        throw new IceInternal.LocalExceptionWrapper(ex__, false);
                    }
                }
            }
            finally
            {
                handler__.reclaimOutgoing(og__);
            }
        }

        public rd.CallResultT connectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("connectedRdServer", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    if(front == null)
                    {
                        rd.RdFrontInfoT tmp__ = new rd.RdFrontInfoT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        front.write__(os__);
                    }
                    if(server == null)
                    {
                        rd.RdServerInfoT tmp__ = new rd.RdServerInfoT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        server.write__(os__);
                    }
                    if(sheet == null)
                    {
                        rd.RdWorkSheetT tmp__ = new rd.RdWorkSheetT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        sheet.write__(os__);
                    }
                }
                catch(Ice.LocalException ex__)
                {
                    og__.abort(ex__);
                }
                bool ok__ = og__.invoke();
                try
                {
                    if(!ok__)
                    {
                        try
                        {
                            og__.throwUserException();
                        }
                        catch(Ice.UserException ex__)
                        {
                            throw new Ice.UnknownUserException(ex__.ice_name(), ex__);
                        }
                    }
                    IceInternal.BasicStream is__ = og__.istr();
                    is__.startReadEncaps();
                    rd.CallResultT ret__;
                    ret__ = null;
                    if(ret__ == null)
                    {
                        ret__ = new rd.CallResultT();
                    }
                    ret__.read__(is__);
                    is__.endReadEncaps();
                    return ret__;
                }
                catch(Ice.LocalException ex__)
                {
                    throw new IceInternal.LocalExceptionWrapper(ex__, false);
                }
            }
            finally
            {
                handler__.reclaimOutgoing(og__);
            }
        }

        public rd.CallResultT disconnectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("disconnectedRdServer", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    if(front == null)
                    {
                        rd.RdFrontInfoT tmp__ = new rd.RdFrontInfoT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        front.write__(os__);
                    }
                    if(server == null)
                    {
                        rd.RdServerInfoT tmp__ = new rd.RdServerInfoT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        server.write__(os__);
                    }
                    if(sheet == null)
                    {
                        rd.RdWorkSheetT tmp__ = new rd.RdWorkSheetT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        sheet.write__(os__);
                    }
                }
                catch(Ice.LocalException ex__)
                {
                    og__.abort(ex__);
                }
                bool ok__ = og__.invoke();
                try
                {
                    if(!ok__)
                    {
                        try
                        {
                            og__.throwUserException();
                        }
                        catch(Ice.UserException ex__)
                        {
                            throw new Ice.UnknownUserException(ex__.ice_name(), ex__);
                        }
                    }
                    IceInternal.BasicStream is__ = og__.istr();
                    is__.startReadEncaps();
                    rd.CallResultT ret__;
                    ret__ = null;
                    if(ret__ == null)
                    {
                        ret__ = new rd.CallResultT();
                    }
                    ret__.read__(is__);
                    is__.endReadEncaps();
                    return ret__;
                }
                catch(Ice.LocalException ex__)
                {
                    throw new IceInternal.LocalExceptionWrapper(ex__, false);
                }
            }
            finally
            {
                handler__.reclaimOutgoing(og__);
            }
        }

        public rd.RdServerInfoT[] getBastRdServers(string areaName, int reqnum, rd.RdFrontInfoT front, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("getBastRdServers", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    os__.writeString(areaName);
                    os__.writeInt(reqnum);
                    if(front == null)
                    {
                        rd.RdFrontInfoT tmp__ = new rd.RdFrontInfoT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        front.write__(os__);
                    }
                }
                catch(Ice.LocalException ex__)
                {
                    og__.abort(ex__);
                }
                bool ok__ = og__.invoke();
                try
                {
                    if(!ok__)
                    {
                        try
                        {
                            og__.throwUserException();
                        }
                        catch(Ice.UserException ex__)
                        {
                            throw new Ice.UnknownUserException(ex__.ice_name(), ex__);
                        }
                    }
                    IceInternal.BasicStream is__ = og__.istr();
                    is__.startReadEncaps();
                    rd.RdServerInfoT[] ret__;
                    {
                        int szx__ = is__.readSize();
                        is__.startSeq(szx__, 6);
                        ret__ = new rd.RdServerInfoT[szx__];
                        for(int ix__ = 0; ix__ < szx__; ++ix__)
                        {
                            ret__[ix__] = new rd.RdServerInfoT();
                            ret__[ix__].read__(is__);
                            is__.checkSeq();
                            is__.endElement();
                        }
                        is__.endSeq(szx__);
                    }
                    is__.endReadEncaps();
                    return ret__;
                }
                catch(Ice.LocalException ex__)
                {
                    throw new IceInternal.LocalExceptionWrapper(ex__, false);
                }
            }
            finally
            {
                handler__.reclaimOutgoing(og__);
            }
        }

        public rd.PingTargetT[] getPingList(rd.RdPingerInfoT pinger, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("getPingList", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    if(pinger == null)
                    {
                        rd.RdPingerInfoT tmp__ = new rd.RdPingerInfoT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        pinger.write__(os__);
                    }
                }
                catch(Ice.LocalException ex__)
                {
                    og__.abort(ex__);
                }
                bool ok__ = og__.invoke();
                try
                {
                    if(!ok__)
                    {
                        try
                        {
                            og__.throwUserException();
                        }
                        catch(Ice.UserException ex__)
                        {
                            throw new Ice.UnknownUserException(ex__.ice_name(), ex__);
                        }
                    }
                    IceInternal.BasicStream is__ = og__.istr();
                    is__.startReadEncaps();
                    rd.PingTargetT[] ret__;
                    {
                        int szx__ = is__.readSize();
                        is__.checkFixedSeq(szx__, 4);
                        ret__ = new rd.PingTargetT[szx__];
                        for(int ix__ = 0; ix__ < szx__; ++ix__)
                        {
                            ret__[ix__].read__(is__);
                        }
                    }
                    is__.endReadEncaps();
                    return ret__;
                }
                catch(Ice.LocalException ex__)
                {
                    throw new IceInternal.LocalExceptionWrapper(ex__, false);
                }
            }
            finally
            {
                handler__.reclaimOutgoing(og__);
            }
        }

        public string getId(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("getId", Ice.OperationMode.Normal, context__);
            try
            {
                bool ok__ = og__.invoke();
                try
                {
                    if(!ok__)
                    {
                        try
                        {
                            og__.throwUserException();
                        }
                        catch(Ice.UserException ex__)
                        {
                            throw new Ice.UnknownUserException(ex__.ice_name(), ex__);
                        }
                    }
                    IceInternal.BasicStream is__ = og__.istr();
                    is__.startReadEncaps();
                    string ret__;
                    ret__ = is__.readString();
                    is__.endReadEncaps();
                    return ret__;
                }
                catch(Ice.LocalException ex__)
                {
                    throw new IceInternal.LocalExceptionWrapper(ex__, false);
                }
            }
            finally
            {
                handler__.reclaimOutgoing(og__);
            }
        }

        public string getSequence(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("getSequence", Ice.OperationMode.Normal, context__);
            try
            {
                bool ok__ = og__.invoke();
                try
                {
                    if(!ok__)
                    {
                        try
                        {
                            og__.throwUserException();
                        }
                        catch(Ice.UserException ex__)
                        {
                            throw new Ice.UnknownUserException(ex__.ice_name(), ex__);
                        }
                    }
                    IceInternal.BasicStream is__ = og__.istr();
                    is__.startReadEncaps();
                    string ret__;
                    ret__ = is__.readString();
                    is__.endReadEncaps();
                    return ret__;
                }
                catch(Ice.LocalException ex__)
                {
                    throw new IceInternal.LocalExceptionWrapper(ex__, false);
                }
            }
            finally
            {
                handler__.reclaimOutgoing(og__);
            }
        }

        public int getTimestamp(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("getTimestamp", Ice.OperationMode.Normal, context__);
            try
            {
                bool ok__ = og__.invoke();
                try
                {
                    if(!ok__)
                    {
                        try
                        {
                            og__.throwUserException();
                        }
                        catch(Ice.UserException ex__)
                        {
                            throw new Ice.UnknownUserException(ex__.ice_name(), ex__);
                        }
                    }
                    IceInternal.BasicStream is__ = og__.istr();
                    is__.startReadEncaps();
                    int ret__;
                    ret__ = is__.readInt();
                    is__.endReadEncaps();
                    return ret__;
                }
                catch(Ice.LocalException ex__)
                {
                    throw new IceInternal.LocalExceptionWrapper(ex__, false);
                }
            }
            finally
            {
                handler__.reclaimOutgoing(og__);
            }
        }

        public string ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("getType", Ice.OperationMode.Normal, context__);
            try
            {
                bool ok__ = og__.invoke();
                try
                {
                    if(!ok__)
                    {
                        try
                        {
                            og__.throwUserException();
                        }
                        catch(Ice.UserException ex__)
                        {
                            throw new Ice.UnknownUserException(ex__.ice_name(), ex__);
                        }
                    }
                    IceInternal.BasicStream is__ = og__.istr();
                    is__.startReadEncaps();
                    string ret__;
                    ret__ = is__.readString();
                    is__.endReadEncaps();
                    return ret__;
                }
                catch(Ice.LocalException ex__)
                {
                    throw new IceInternal.LocalExceptionWrapper(ex__, false);
                }
            }
            finally
            {
                handler__.reclaimOutgoing(og__);
            }
        }

        public string getVersion(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("getVersion", Ice.OperationMode.Normal, context__);
            try
            {
                bool ok__ = og__.invoke();
                try
                {
                    if(!ok__)
                    {
                        try
                        {
                            og__.throwUserException();
                        }
                        catch(Ice.UserException ex__)
                        {
                            throw new Ice.UnknownUserException(ex__.ice_name(), ex__);
                        }
                    }
                    IceInternal.BasicStream is__ = og__.istr();
                    is__.startReadEncaps();
                    string ret__;
                    ret__ = is__.readString();
                    is__.endReadEncaps();
                    return ret__;
                }
                catch(Ice.LocalException ex__)
                {
                    throw new IceInternal.LocalExceptionWrapper(ex__, false);
                }
            }
            finally
            {
                handler__.reclaimOutgoing(og__);
            }
        }
    }

    public sealed class IRdFrontDelM_ : Ice.ObjectDelM_, IRdFrontDel_
    {
        public void end(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("end", Ice.OperationMode.Normal, context__);
            try
            {
                bool ok__ = og__.invoke();
                if(!og__.istr().isEmpty())
                {
                    try
                    {
                        if(!ok__)
                        {
                            try
                            {
                                og__.throwUserException();
                            }
                            catch(Ice.UserException ex__)
                            {
                                throw new Ice.UnknownUserException(ex__.ice_name(), ex__);
                            }
                        }
                        og__.istr().skipEmptyEncaps();
                    }
                    catch(Ice.LocalException ex__)
                    {
                        throw new IceInternal.LocalExceptionWrapper(ex__, false);
                    }
                }
            }
            finally
            {
                handler__.reclaimOutgoing(og__);
            }
        }

        public rd.CallResultT prepare(rd.RdWorkSheetT sheet, int timeout, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("prepare", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    if(sheet == null)
                    {
                        rd.RdWorkSheetT tmp__ = new rd.RdWorkSheetT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        sheet.write__(os__);
                    }
                    os__.writeInt(timeout);
                }
                catch(Ice.LocalException ex__)
                {
                    og__.abort(ex__);
                }
                bool ok__ = og__.invoke();
                try
                {
                    if(!ok__)
                    {
                        try
                        {
                            og__.throwUserException();
                        }
                        catch(Ice.UserException ex__)
                        {
                            throw new Ice.UnknownUserException(ex__.ice_name(), ex__);
                        }
                    }
                    IceInternal.BasicStream is__ = og__.istr();
                    is__.startReadEncaps();
                    rd.CallResultT ret__;
                    ret__ = null;
                    if(ret__ == null)
                    {
                        ret__ = new rd.CallResultT();
                    }
                    ret__.read__(is__);
                    is__.endReadEncaps();
                    return ret__;
                }
                catch(Ice.LocalException ex__)
                {
                    throw new IceInternal.LocalExceptionWrapper(ex__, false);
                }
            }
            finally
            {
                handler__.reclaimOutgoing(og__);
            }
        }
    }
}

namespace rd
{
    public sealed class IServiceDelD_ : Ice.ObjectDelD_, IServiceDel_
    {
        public string getId(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getId", Ice.OperationMode.Normal, context__);
            string result__ = null;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IService servant__ = null;
                try
                {
                    servant__ = (IService)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                result__ = servant__.getId(current__);
                return Ice.DispatchStatus.DispatchOK;
            };
            IceInternal.Direct direct__ = null;
            try
            {
                direct__ = new IceInternal.Direct(current__, run__);
                try
                {
                    Ice.DispatchStatus status__ = direct__.servant().collocDispatch__(direct__);
                    _System.Diagnostics.Debug.Assert(status__ == Ice.DispatchStatus.DispatchOK);
                }
                finally
                {
                    direct__.destroy();
                }
            }
            catch(Ice.SystemException)
            {
                throw;
            }
            catch(System.Exception ex__)
            {
                IceInternal.LocalExceptionWrapper.throwWrapper(ex__);
            }
            return result__;
        }

        public string getSequence(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getSequence", Ice.OperationMode.Normal, context__);
            string result__ = null;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IService servant__ = null;
                try
                {
                    servant__ = (IService)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                result__ = servant__.getSequence(current__);
                return Ice.DispatchStatus.DispatchOK;
            };
            IceInternal.Direct direct__ = null;
            try
            {
                direct__ = new IceInternal.Direct(current__, run__);
                try
                {
                    Ice.DispatchStatus status__ = direct__.servant().collocDispatch__(direct__);
                    _System.Diagnostics.Debug.Assert(status__ == Ice.DispatchStatus.DispatchOK);
                }
                finally
                {
                    direct__.destroy();
                }
            }
            catch(Ice.SystemException)
            {
                throw;
            }
            catch(System.Exception ex__)
            {
                IceInternal.LocalExceptionWrapper.throwWrapper(ex__);
            }
            return result__;
        }

        public int getTimestamp(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getTimestamp", Ice.OperationMode.Normal, context__);
            int result__ = 0;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IService servant__ = null;
                try
                {
                    servant__ = (IService)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                result__ = servant__.getTimestamp(current__);
                return Ice.DispatchStatus.DispatchOK;
            };
            IceInternal.Direct direct__ = null;
            try
            {
                direct__ = new IceInternal.Direct(current__, run__);
                try
                {
                    Ice.DispatchStatus status__ = direct__.servant().collocDispatch__(direct__);
                    _System.Diagnostics.Debug.Assert(status__ == Ice.DispatchStatus.DispatchOK);
                }
                finally
                {
                    direct__.destroy();
                }
            }
            catch(Ice.SystemException)
            {
                throw;
            }
            catch(System.Exception ex__)
            {
                IceInternal.LocalExceptionWrapper.throwWrapper(ex__);
            }
            return result__;
        }

        public string ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getType", Ice.OperationMode.Normal, context__);
            string result__ = null;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IService servant__ = null;
                try
                {
                    servant__ = (IService)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                result__ = servant__.ice_getType_(current__);
                return Ice.DispatchStatus.DispatchOK;
            };
            IceInternal.Direct direct__ = null;
            try
            {
                direct__ = new IceInternal.Direct(current__, run__);
                try
                {
                    Ice.DispatchStatus status__ = direct__.servant().collocDispatch__(direct__);
                    _System.Diagnostics.Debug.Assert(status__ == Ice.DispatchStatus.DispatchOK);
                }
                finally
                {
                    direct__.destroy();
                }
            }
            catch(Ice.SystemException)
            {
                throw;
            }
            catch(System.Exception ex__)
            {
                IceInternal.LocalExceptionWrapper.throwWrapper(ex__);
            }
            return result__;
        }

        public string getVersion(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getVersion", Ice.OperationMode.Normal, context__);
            string result__ = null;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IService servant__ = null;
                try
                {
                    servant__ = (IService)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                result__ = servant__.getVersion(current__);
                return Ice.DispatchStatus.DispatchOK;
            };
            IceInternal.Direct direct__ = null;
            try
            {
                direct__ = new IceInternal.Direct(current__, run__);
                try
                {
                    Ice.DispatchStatus status__ = direct__.servant().collocDispatch__(direct__);
                    _System.Diagnostics.Debug.Assert(status__ == Ice.DispatchStatus.DispatchOK);
                }
                finally
                {
                    direct__.destroy();
                }
            }
            catch(Ice.SystemException)
            {
                throw;
            }
            catch(System.Exception ex__)
            {
                IceInternal.LocalExceptionWrapper.throwWrapper(ex__);
            }
            return result__;
        }
    }

    public sealed class IRdDispatcherDelD_ : Ice.ObjectDelD_, IRdDispatcherDel_
    {
        public void completePing(rd.RdPingerInfoT pinger, rd.PingResultT[] result, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "completePing", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IRdDispatcher servant__ = null;
                try
                {
                    servant__ = (IRdDispatcher)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.completePing(pinger, result, current__);
                return Ice.DispatchStatus.DispatchOK;
            };
            IceInternal.Direct direct__ = null;
            try
            {
                direct__ = new IceInternal.Direct(current__, run__);
                try
                {
                    Ice.DispatchStatus status__ = direct__.servant().collocDispatch__(direct__);
                    _System.Diagnostics.Debug.Assert(status__ == Ice.DispatchStatus.DispatchOK);
                }
                finally
                {
                    direct__.destroy();
                }
            }
            catch(Ice.SystemException)
            {
                throw;
            }
            catch(System.Exception ex__)
            {
                IceInternal.LocalExceptionWrapper.throwWrapper(ex__);
            }
        }

        public rd.CallResultT connectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "connectedRdServer", Ice.OperationMode.Normal, context__);
            rd.CallResultT result__ = new rd.CallResultT();
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IRdDispatcher servant__ = null;
                try
                {
                    servant__ = (IRdDispatcher)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                result__ = servant__.connectedRdServer(front, server, sheet, current__);
                return Ice.DispatchStatus.DispatchOK;
            };
            IceInternal.Direct direct__ = null;
            try
            {
                direct__ = new IceInternal.Direct(current__, run__);
                try
                {
                    Ice.DispatchStatus status__ = direct__.servant().collocDispatch__(direct__);
                    _System.Diagnostics.Debug.Assert(status__ == Ice.DispatchStatus.DispatchOK);
                }
                finally
                {
                    direct__.destroy();
                }
            }
            catch(Ice.SystemException)
            {
                throw;
            }
            catch(System.Exception ex__)
            {
                IceInternal.LocalExceptionWrapper.throwWrapper(ex__);
            }
            return result__;
        }

        public rd.CallResultT disconnectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "disconnectedRdServer", Ice.OperationMode.Normal, context__);
            rd.CallResultT result__ = new rd.CallResultT();
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IRdDispatcher servant__ = null;
                try
                {
                    servant__ = (IRdDispatcher)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                result__ = servant__.disconnectedRdServer(front, server, sheet, current__);
                return Ice.DispatchStatus.DispatchOK;
            };
            IceInternal.Direct direct__ = null;
            try
            {
                direct__ = new IceInternal.Direct(current__, run__);
                try
                {
                    Ice.DispatchStatus status__ = direct__.servant().collocDispatch__(direct__);
                    _System.Diagnostics.Debug.Assert(status__ == Ice.DispatchStatus.DispatchOK);
                }
                finally
                {
                    direct__.destroy();
                }
            }
            catch(Ice.SystemException)
            {
                throw;
            }
            catch(System.Exception ex__)
            {
                IceInternal.LocalExceptionWrapper.throwWrapper(ex__);
            }
            return result__;
        }

        public rd.RdServerInfoT[] getBastRdServers(string areaName, int reqnum, rd.RdFrontInfoT front, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getBastRdServers", Ice.OperationMode.Normal, context__);
            rd.RdServerInfoT[] result__ = null;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IRdDispatcher servant__ = null;
                try
                {
                    servant__ = (IRdDispatcher)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                result__ = servant__.getBastRdServers(areaName, reqnum, front, current__);
                return Ice.DispatchStatus.DispatchOK;
            };
            IceInternal.Direct direct__ = null;
            try
            {
                direct__ = new IceInternal.Direct(current__, run__);
                try
                {
                    Ice.DispatchStatus status__ = direct__.servant().collocDispatch__(direct__);
                    _System.Diagnostics.Debug.Assert(status__ == Ice.DispatchStatus.DispatchOK);
                }
                finally
                {
                    direct__.destroy();
                }
            }
            catch(Ice.SystemException)
            {
                throw;
            }
            catch(System.Exception ex__)
            {
                IceInternal.LocalExceptionWrapper.throwWrapper(ex__);
            }
            return result__;
        }

        public rd.PingTargetT[] getPingList(rd.RdPingerInfoT pinger, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getPingList", Ice.OperationMode.Normal, context__);
            rd.PingTargetT[] result__ = null;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IRdDispatcher servant__ = null;
                try
                {
                    servant__ = (IRdDispatcher)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                result__ = servant__.getPingList(pinger, current__);
                return Ice.DispatchStatus.DispatchOK;
            };
            IceInternal.Direct direct__ = null;
            try
            {
                direct__ = new IceInternal.Direct(current__, run__);
                try
                {
                    Ice.DispatchStatus status__ = direct__.servant().collocDispatch__(direct__);
                    _System.Diagnostics.Debug.Assert(status__ == Ice.DispatchStatus.DispatchOK);
                }
                finally
                {
                    direct__.destroy();
                }
            }
            catch(Ice.SystemException)
            {
                throw;
            }
            catch(System.Exception ex__)
            {
                IceInternal.LocalExceptionWrapper.throwWrapper(ex__);
            }
            return result__;
        }

        public string getId(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getId", Ice.OperationMode.Normal, context__);
            string result__ = null;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IRdDispatcher servant__ = null;
                try
                {
                    servant__ = (IRdDispatcher)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                result__ = servant__.getId(current__);
                return Ice.DispatchStatus.DispatchOK;
            };
            IceInternal.Direct direct__ = null;
            try
            {
                direct__ = new IceInternal.Direct(current__, run__);
                try
                {
                    Ice.DispatchStatus status__ = direct__.servant().collocDispatch__(direct__);
                    _System.Diagnostics.Debug.Assert(status__ == Ice.DispatchStatus.DispatchOK);
                }
                finally
                {
                    direct__.destroy();
                }
            }
            catch(Ice.SystemException)
            {
                throw;
            }
            catch(System.Exception ex__)
            {
                IceInternal.LocalExceptionWrapper.throwWrapper(ex__);
            }
            return result__;
        }

        public string getSequence(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getSequence", Ice.OperationMode.Normal, context__);
            string result__ = null;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IRdDispatcher servant__ = null;
                try
                {
                    servant__ = (IRdDispatcher)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                result__ = servant__.getSequence(current__);
                return Ice.DispatchStatus.DispatchOK;
            };
            IceInternal.Direct direct__ = null;
            try
            {
                direct__ = new IceInternal.Direct(current__, run__);
                try
                {
                    Ice.DispatchStatus status__ = direct__.servant().collocDispatch__(direct__);
                    _System.Diagnostics.Debug.Assert(status__ == Ice.DispatchStatus.DispatchOK);
                }
                finally
                {
                    direct__.destroy();
                }
            }
            catch(Ice.SystemException)
            {
                throw;
            }
            catch(System.Exception ex__)
            {
                IceInternal.LocalExceptionWrapper.throwWrapper(ex__);
            }
            return result__;
        }

        public int getTimestamp(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getTimestamp", Ice.OperationMode.Normal, context__);
            int result__ = 0;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IRdDispatcher servant__ = null;
                try
                {
                    servant__ = (IRdDispatcher)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                result__ = servant__.getTimestamp(current__);
                return Ice.DispatchStatus.DispatchOK;
            };
            IceInternal.Direct direct__ = null;
            try
            {
                direct__ = new IceInternal.Direct(current__, run__);
                try
                {
                    Ice.DispatchStatus status__ = direct__.servant().collocDispatch__(direct__);
                    _System.Diagnostics.Debug.Assert(status__ == Ice.DispatchStatus.DispatchOK);
                }
                finally
                {
                    direct__.destroy();
                }
            }
            catch(Ice.SystemException)
            {
                throw;
            }
            catch(System.Exception ex__)
            {
                IceInternal.LocalExceptionWrapper.throwWrapper(ex__);
            }
            return result__;
        }

        public string ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getType", Ice.OperationMode.Normal, context__);
            string result__ = null;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IRdDispatcher servant__ = null;
                try
                {
                    servant__ = (IRdDispatcher)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                result__ = servant__.ice_getType_(current__);
                return Ice.DispatchStatus.DispatchOK;
            };
            IceInternal.Direct direct__ = null;
            try
            {
                direct__ = new IceInternal.Direct(current__, run__);
                try
                {
                    Ice.DispatchStatus status__ = direct__.servant().collocDispatch__(direct__);
                    _System.Diagnostics.Debug.Assert(status__ == Ice.DispatchStatus.DispatchOK);
                }
                finally
                {
                    direct__.destroy();
                }
            }
            catch(Ice.SystemException)
            {
                throw;
            }
            catch(System.Exception ex__)
            {
                IceInternal.LocalExceptionWrapper.throwWrapper(ex__);
            }
            return result__;
        }

        public string getVersion(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getVersion", Ice.OperationMode.Normal, context__);
            string result__ = null;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IRdDispatcher servant__ = null;
                try
                {
                    servant__ = (IRdDispatcher)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                result__ = servant__.getVersion(current__);
                return Ice.DispatchStatus.DispatchOK;
            };
            IceInternal.Direct direct__ = null;
            try
            {
                direct__ = new IceInternal.Direct(current__, run__);
                try
                {
                    Ice.DispatchStatus status__ = direct__.servant().collocDispatch__(direct__);
                    _System.Diagnostics.Debug.Assert(status__ == Ice.DispatchStatus.DispatchOK);
                }
                finally
                {
                    direct__.destroy();
                }
            }
            catch(Ice.SystemException)
            {
                throw;
            }
            catch(System.Exception ex__)
            {
                IceInternal.LocalExceptionWrapper.throwWrapper(ex__);
            }
            return result__;
        }
    }

    public sealed class IRdFrontDelD_ : Ice.ObjectDelD_, IRdFrontDel_
    {
        public void end(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "end", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IRdFront servant__ = null;
                try
                {
                    servant__ = (IRdFront)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.end(current__);
                return Ice.DispatchStatus.DispatchOK;
            };
            IceInternal.Direct direct__ = null;
            try
            {
                direct__ = new IceInternal.Direct(current__, run__);
                try
                {
                    Ice.DispatchStatus status__ = direct__.servant().collocDispatch__(direct__);
                    _System.Diagnostics.Debug.Assert(status__ == Ice.DispatchStatus.DispatchOK);
                }
                finally
                {
                    direct__.destroy();
                }
            }
            catch(Ice.SystemException)
            {
                throw;
            }
            catch(System.Exception ex__)
            {
                IceInternal.LocalExceptionWrapper.throwWrapper(ex__);
            }
        }

        public rd.CallResultT prepare(rd.RdWorkSheetT sheet, int timeout, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "prepare", Ice.OperationMode.Normal, context__);
            rd.CallResultT result__ = new rd.CallResultT();
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IRdFront servant__ = null;
                try
                {
                    servant__ = (IRdFront)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                result__ = servant__.prepare(sheet, timeout, current__);
                return Ice.DispatchStatus.DispatchOK;
            };
            IceInternal.Direct direct__ = null;
            try
            {
                direct__ = new IceInternal.Direct(current__, run__);
                try
                {
                    Ice.DispatchStatus status__ = direct__.servant().collocDispatch__(direct__);
                    _System.Diagnostics.Debug.Assert(status__ == Ice.DispatchStatus.DispatchOK);
                }
                finally
                {
                    direct__.destroy();
                }
            }
            catch(Ice.SystemException)
            {
                throw;
            }
            catch(System.Exception ex__)
            {
                IceInternal.LocalExceptionWrapper.throwWrapper(ex__);
            }
            return result__;
        }
    }
}

namespace rd
{
    public abstract class IServiceDisp_ : Ice.ObjectImpl, IService
    {
        #region Slice operations

        public string getSequence()
        {
            return getSequence(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract string getSequence(Ice.Current current__);

        public string ice_getType_()
        {
            return ice_getType_(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract string ice_getType_(Ice.Current current__);

        public string getId()
        {
            return getId(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract string getId(Ice.Current current__);

        public int getTimestamp()
        {
            return getTimestamp(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract int getTimestamp(Ice.Current current__);

        public string getVersion()
        {
            return getVersion(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract string getVersion(Ice.Current current__);

        #endregion

        #region Slice type-related members

        public static new string[] ids__ = 
        {
            "::Ice::Object",
            "::rd::IService"
        };

        public override bool ice_isA(string s)
        {
            return _System.Array.BinarySearch(ids__, s, IceUtilInternal.StringUtil.OrdinalStringComparer) >= 0;
        }

        public override bool ice_isA(string s, Ice.Current current__)
        {
            return _System.Array.BinarySearch(ids__, s, IceUtilInternal.StringUtil.OrdinalStringComparer) >= 0;
        }

        public override string[] ice_ids()
        {
            return ids__;
        }

        public override string[] ice_ids(Ice.Current current__)
        {
            return ids__;
        }

        public override string ice_id()
        {
            return ids__[1];
        }

        public override string ice_id(Ice.Current current__)
        {
            return ids__[1];
        }

        public static new string ice_staticId()
        {
            return ids__[1];
        }

        #endregion

        #region Operation dispatch

        public static Ice.DispatchStatus getSequence___(IService obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            inS__.istr().skipEmptyEncaps();
            IceInternal.BasicStream os__ = inS__.ostr();
            string ret__ = obj__.getSequence(current__);
            os__.writeString(ret__);
            return Ice.DispatchStatus.DispatchOK;
        }

        public static Ice.DispatchStatus getType___(IService obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            inS__.istr().skipEmptyEncaps();
            IceInternal.BasicStream os__ = inS__.ostr();
            string ret__ = obj__.ice_getType_(current__);
            os__.writeString(ret__);
            return Ice.DispatchStatus.DispatchOK;
        }

        public static Ice.DispatchStatus getId___(IService obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            inS__.istr().skipEmptyEncaps();
            IceInternal.BasicStream os__ = inS__.ostr();
            string ret__ = obj__.getId(current__);
            os__.writeString(ret__);
            return Ice.DispatchStatus.DispatchOK;
        }

        public static Ice.DispatchStatus getTimestamp___(IService obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            inS__.istr().skipEmptyEncaps();
            IceInternal.BasicStream os__ = inS__.ostr();
            int ret__ = obj__.getTimestamp(current__);
            os__.writeInt(ret__);
            return Ice.DispatchStatus.DispatchOK;
        }

        public static Ice.DispatchStatus getVersion___(IService obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            inS__.istr().skipEmptyEncaps();
            IceInternal.BasicStream os__ = inS__.ostr();
            string ret__ = obj__.getVersion(current__);
            os__.writeString(ret__);
            return Ice.DispatchStatus.DispatchOK;
        }

        private static string[] all__ =
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

        public override Ice.DispatchStatus dispatch__(IceInternal.Incoming inS__, Ice.Current current__)
        {
            int pos = _System.Array.BinarySearch(all__, current__.operation, IceUtilInternal.StringUtil.OrdinalStringComparer);
            if(pos < 0)
            {
                throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
            }

            switch(pos)
            {
                case 0:
                {
                    return getId___(this, inS__, current__);
                }
                case 1:
                {
                    return getSequence___(this, inS__, current__);
                }
                case 2:
                {
                    return getTimestamp___(this, inS__, current__);
                }
                case 3:
                {
                    return getType___(this, inS__, current__);
                }
                case 4:
                {
                    return getVersion___(this, inS__, current__);
                }
                case 5:
                {
                    return ice_id___(this, inS__, current__);
                }
                case 6:
                {
                    return ice_ids___(this, inS__, current__);
                }
                case 7:
                {
                    return ice_isA___(this, inS__, current__);
                }
                case 8:
                {
                    return ice_ping___(this, inS__, current__);
                }
            }

            _System.Diagnostics.Debug.Assert(false);
            throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
        }

        #endregion

        #region Marshaling support

        public override void write__(IceInternal.BasicStream os__)
        {
            os__.writeTypeId(ice_staticId());
            os__.startWriteSlice();
            os__.endWriteSlice();
            base.write__(os__);
        }

        public override void read__(IceInternal.BasicStream is__, bool rid__)
        {
            if(rid__)
            {
                /* string myId = */ is__.readTypeId();
            }
            is__.startReadSlice();
            is__.endReadSlice();
            base.read__(is__, true);
        }

        public override void write__(Ice.OutputStream outS__)
        {
            Ice.MarshalException ex = new Ice.MarshalException();
            ex.reason = "type rd::IService was not generated with stream support";
            throw ex;
        }

        public override void read__(Ice.InputStream inS__, bool rid__)
        {
            Ice.MarshalException ex = new Ice.MarshalException();
            ex.reason = "type rd::IService was not generated with stream support";
            throw ex;
        }

        #endregion
    }

    public abstract class IRdDispatcherDisp_ : Ice.ObjectImpl, IRdDispatcher
    {
        #region Slice operations

        public rd.PingTargetT[] getPingList(rd.RdPingerInfoT pinger)
        {
            return getPingList(pinger, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract rd.PingTargetT[] getPingList(rd.RdPingerInfoT pinger, Ice.Current current__);

        public void completePing(rd.RdPingerInfoT pinger, rd.PingResultT[] result)
        {
            completePing(pinger, result, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void completePing(rd.RdPingerInfoT pinger, rd.PingResultT[] result, Ice.Current current__);

        public rd.RdServerInfoT[] getBastRdServers(string areaName, int reqnum, rd.RdFrontInfoT front)
        {
            return getBastRdServers(areaName, reqnum, front, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract rd.RdServerInfoT[] getBastRdServers(string areaName, int reqnum, rd.RdFrontInfoT front, Ice.Current current__);

        public rd.CallResultT connectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet)
        {
            return connectedRdServer(front, server, sheet, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract rd.CallResultT connectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet, Ice.Current current__);

        public rd.CallResultT disconnectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet)
        {
            return disconnectedRdServer(front, server, sheet, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract rd.CallResultT disconnectedRdServer(rd.RdFrontInfoT front, rd.RdServerInfoT server, rd.RdWorkSheetT sheet, Ice.Current current__);

        #endregion

        #region Inherited Slice operations

        public string getId()
        {
            return getId(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract string getId(Ice.Current current__);

        public string getSequence()
        {
            return getSequence(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract string getSequence(Ice.Current current__);

        public int getTimestamp()
        {
            return getTimestamp(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract int getTimestamp(Ice.Current current__);

        public string ice_getType_()
        {
            return ice_getType_(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract string ice_getType_(Ice.Current current__);

        public string getVersion()
        {
            return getVersion(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract string getVersion(Ice.Current current__);

        #endregion

        #region Slice type-related members

        public static new string[] ids__ = 
        {
            "::Ice::Object",
            "::rd::IRdDispatcher",
            "::rd::IService"
        };

        public override bool ice_isA(string s)
        {
            return _System.Array.BinarySearch(ids__, s, IceUtilInternal.StringUtil.OrdinalStringComparer) >= 0;
        }

        public override bool ice_isA(string s, Ice.Current current__)
        {
            return _System.Array.BinarySearch(ids__, s, IceUtilInternal.StringUtil.OrdinalStringComparer) >= 0;
        }

        public override string[] ice_ids()
        {
            return ids__;
        }

        public override string[] ice_ids(Ice.Current current__)
        {
            return ids__;
        }

        public override string ice_id()
        {
            return ids__[1];
        }

        public override string ice_id(Ice.Current current__)
        {
            return ids__[1];
        }

        public static new string ice_staticId()
        {
            return ids__[1];
        }

        #endregion

        #region Operation dispatch

        public static Ice.DispatchStatus getPingList___(IRdDispatcher obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            IceInternal.BasicStream is__ = inS__.istr();
            is__.startReadEncaps();
            rd.RdPingerInfoT pinger;
            pinger = null;
            if(pinger == null)
            {
                pinger = new rd.RdPingerInfoT();
            }
            pinger.read__(is__);
            is__.endReadEncaps();
            IceInternal.BasicStream os__ = inS__.ostr();
            rd.PingTargetT[] ret__ = obj__.getPingList(pinger, current__);
            if(ret__ == null)
            {
                os__.writeSize(0);
            }
            else
            {
                os__.writeSize(ret__.Length);
                for(int ix__ = 0; ix__ < ret__.Length; ++ix__)
                {
                    ret__[ix__].write__(os__);
                }
            }
            return Ice.DispatchStatus.DispatchOK;
        }

        public static Ice.DispatchStatus completePing___(IRdDispatcher obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            IceInternal.BasicStream is__ = inS__.istr();
            is__.startReadEncaps();
            rd.RdPingerInfoT pinger;
            pinger = null;
            if(pinger == null)
            {
                pinger = new rd.RdPingerInfoT();
            }
            pinger.read__(is__);
            rd.PingResultT[] result;
            {
                int szx__ = is__.readSize();
                is__.checkFixedSeq(szx__, 12);
                result = new rd.PingResultT[szx__];
                for(int ix__ = 0; ix__ < szx__; ++ix__)
                {
                    result[ix__].read__(is__);
                }
            }
            is__.endReadEncaps();
            obj__.completePing(pinger, result, current__);
            return Ice.DispatchStatus.DispatchOK;
        }

        public static Ice.DispatchStatus getBastRdServers___(IRdDispatcher obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            IceInternal.BasicStream is__ = inS__.istr();
            is__.startReadEncaps();
            string areaName;
            areaName = is__.readString();
            int reqnum;
            reqnum = is__.readInt();
            rd.RdFrontInfoT front;
            front = null;
            if(front == null)
            {
                front = new rd.RdFrontInfoT();
            }
            front.read__(is__);
            is__.endReadEncaps();
            IceInternal.BasicStream os__ = inS__.ostr();
            rd.RdServerInfoT[] ret__ = obj__.getBastRdServers(areaName, reqnum, front, current__);
            if(ret__ == null)
            {
                os__.writeSize(0);
            }
            else
            {
                os__.writeSize(ret__.Length);
                for(int ix__ = 0; ix__ < ret__.Length; ++ix__)
                {
                    (ret__[ix__] == null ? new rd.RdServerInfoT() : ret__[ix__]).write__(os__);
                }
            }
            return Ice.DispatchStatus.DispatchOK;
        }

        public static Ice.DispatchStatus connectedRdServer___(IRdDispatcher obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            IceInternal.BasicStream is__ = inS__.istr();
            is__.startReadEncaps();
            rd.RdFrontInfoT front;
            front = null;
            if(front == null)
            {
                front = new rd.RdFrontInfoT();
            }
            front.read__(is__);
            rd.RdServerInfoT server;
            server = null;
            if(server == null)
            {
                server = new rd.RdServerInfoT();
            }
            server.read__(is__);
            rd.RdWorkSheetT sheet;
            sheet = null;
            if(sheet == null)
            {
                sheet = new rd.RdWorkSheetT();
            }
            sheet.read__(is__);
            is__.endReadEncaps();
            IceInternal.BasicStream os__ = inS__.ostr();
            rd.CallResultT ret__ = obj__.connectedRdServer(front, server, sheet, current__);
            if(ret__ == null)
            {
                rd.CallResultT tmp__ = new rd.CallResultT();
                tmp__.write__(os__);
            }
            else
            {
                ret__.write__(os__);
            }
            return Ice.DispatchStatus.DispatchOK;
        }

        public static Ice.DispatchStatus disconnectedRdServer___(IRdDispatcher obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            IceInternal.BasicStream is__ = inS__.istr();
            is__.startReadEncaps();
            rd.RdFrontInfoT front;
            front = null;
            if(front == null)
            {
                front = new rd.RdFrontInfoT();
            }
            front.read__(is__);
            rd.RdServerInfoT server;
            server = null;
            if(server == null)
            {
                server = new rd.RdServerInfoT();
            }
            server.read__(is__);
            rd.RdWorkSheetT sheet;
            sheet = null;
            if(sheet == null)
            {
                sheet = new rd.RdWorkSheetT();
            }
            sheet.read__(is__);
            is__.endReadEncaps();
            IceInternal.BasicStream os__ = inS__.ostr();
            rd.CallResultT ret__ = obj__.disconnectedRdServer(front, server, sheet, current__);
            if(ret__ == null)
            {
                rd.CallResultT tmp__ = new rd.CallResultT();
                tmp__.write__(os__);
            }
            else
            {
                ret__.write__(os__);
            }
            return Ice.DispatchStatus.DispatchOK;
        }

        private static string[] all__ =
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

        public override Ice.DispatchStatus dispatch__(IceInternal.Incoming inS__, Ice.Current current__)
        {
            int pos = _System.Array.BinarySearch(all__, current__.operation, IceUtilInternal.StringUtil.OrdinalStringComparer);
            if(pos < 0)
            {
                throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
            }

            switch(pos)
            {
                case 0:
                {
                    return completePing___(this, inS__, current__);
                }
                case 1:
                {
                    return connectedRdServer___(this, inS__, current__);
                }
                case 2:
                {
                    return disconnectedRdServer___(this, inS__, current__);
                }
                case 3:
                {
                    return getBastRdServers___(this, inS__, current__);
                }
                case 4:
                {
                    return rd.IServiceDisp_.getId___(this, inS__, current__);
                }
                case 5:
                {
                    return getPingList___(this, inS__, current__);
                }
                case 6:
                {
                    return rd.IServiceDisp_.getSequence___(this, inS__, current__);
                }
                case 7:
                {
                    return rd.IServiceDisp_.getTimestamp___(this, inS__, current__);
                }
                case 8:
                {
                    return rd.IServiceDisp_.getType___(this, inS__, current__);
                }
                case 9:
                {
                    return rd.IServiceDisp_.getVersion___(this, inS__, current__);
                }
                case 10:
                {
                    return ice_id___(this, inS__, current__);
                }
                case 11:
                {
                    return ice_ids___(this, inS__, current__);
                }
                case 12:
                {
                    return ice_isA___(this, inS__, current__);
                }
                case 13:
                {
                    return ice_ping___(this, inS__, current__);
                }
            }

            _System.Diagnostics.Debug.Assert(false);
            throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
        }

        #endregion

        #region Marshaling support

        public override void write__(IceInternal.BasicStream os__)
        {
            os__.writeTypeId(ice_staticId());
            os__.startWriteSlice();
            os__.endWriteSlice();
            base.write__(os__);
        }

        public override void read__(IceInternal.BasicStream is__, bool rid__)
        {
            if(rid__)
            {
                /* string myId = */ is__.readTypeId();
            }
            is__.startReadSlice();
            is__.endReadSlice();
            base.read__(is__, true);
        }

        public override void write__(Ice.OutputStream outS__)
        {
            Ice.MarshalException ex = new Ice.MarshalException();
            ex.reason = "type rd::IRdDispatcher was not generated with stream support";
            throw ex;
        }

        public override void read__(Ice.InputStream inS__, bool rid__)
        {
            Ice.MarshalException ex = new Ice.MarshalException();
            ex.reason = "type rd::IRdDispatcher was not generated with stream support";
            throw ex;
        }

        #endregion
    }

    public abstract class IRdFrontDisp_ : Ice.ObjectImpl, IRdFront
    {
        #region Slice operations

        public rd.CallResultT prepare(rd.RdWorkSheetT sheet, int timeout)
        {
            return prepare(sheet, timeout, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract rd.CallResultT prepare(rd.RdWorkSheetT sheet, int timeout, Ice.Current current__);

        public void end()
        {
            end(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void end(Ice.Current current__);

        #endregion

        #region Slice type-related members

        public static new string[] ids__ = 
        {
            "::Ice::Object",
            "::rd::IRdFront"
        };

        public override bool ice_isA(string s)
        {
            return _System.Array.BinarySearch(ids__, s, IceUtilInternal.StringUtil.OrdinalStringComparer) >= 0;
        }

        public override bool ice_isA(string s, Ice.Current current__)
        {
            return _System.Array.BinarySearch(ids__, s, IceUtilInternal.StringUtil.OrdinalStringComparer) >= 0;
        }

        public override string[] ice_ids()
        {
            return ids__;
        }

        public override string[] ice_ids(Ice.Current current__)
        {
            return ids__;
        }

        public override string ice_id()
        {
            return ids__[1];
        }

        public override string ice_id(Ice.Current current__)
        {
            return ids__[1];
        }

        public static new string ice_staticId()
        {
            return ids__[1];
        }

        #endregion

        #region Operation dispatch

        public static Ice.DispatchStatus prepare___(IRdFront obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            IceInternal.BasicStream is__ = inS__.istr();
            is__.startReadEncaps();
            rd.RdWorkSheetT sheet;
            sheet = null;
            if(sheet == null)
            {
                sheet = new rd.RdWorkSheetT();
            }
            sheet.read__(is__);
            int timeout;
            timeout = is__.readInt();
            is__.endReadEncaps();
            IceInternal.BasicStream os__ = inS__.ostr();
            rd.CallResultT ret__ = obj__.prepare(sheet, timeout, current__);
            if(ret__ == null)
            {
                rd.CallResultT tmp__ = new rd.CallResultT();
                tmp__.write__(os__);
            }
            else
            {
                ret__.write__(os__);
            }
            return Ice.DispatchStatus.DispatchOK;
        }

        public static Ice.DispatchStatus end___(IRdFront obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            inS__.istr().skipEmptyEncaps();
            obj__.end(current__);
            return Ice.DispatchStatus.DispatchOK;
        }

        private static string[] all__ =
        {
            "end",
            "ice_id",
            "ice_ids",
            "ice_isA",
            "ice_ping",
            "prepare"
        };

        public override Ice.DispatchStatus dispatch__(IceInternal.Incoming inS__, Ice.Current current__)
        {
            int pos = _System.Array.BinarySearch(all__, current__.operation, IceUtilInternal.StringUtil.OrdinalStringComparer);
            if(pos < 0)
            {
                throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
            }

            switch(pos)
            {
                case 0:
                {
                    return end___(this, inS__, current__);
                }
                case 1:
                {
                    return ice_id___(this, inS__, current__);
                }
                case 2:
                {
                    return ice_ids___(this, inS__, current__);
                }
                case 3:
                {
                    return ice_isA___(this, inS__, current__);
                }
                case 4:
                {
                    return ice_ping___(this, inS__, current__);
                }
                case 5:
                {
                    return prepare___(this, inS__, current__);
                }
            }

            _System.Diagnostics.Debug.Assert(false);
            throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
        }

        #endregion

        #region Marshaling support

        public override void write__(IceInternal.BasicStream os__)
        {
            os__.writeTypeId(ice_staticId());
            os__.startWriteSlice();
            os__.endWriteSlice();
            base.write__(os__);
        }

        public override void read__(IceInternal.BasicStream is__, bool rid__)
        {
            if(rid__)
            {
                /* string myId = */ is__.readTypeId();
            }
            is__.startReadSlice();
            is__.endReadSlice();
            base.read__(is__, true);
        }

        public override void write__(Ice.OutputStream outS__)
        {
            Ice.MarshalException ex = new Ice.MarshalException();
            ex.reason = "type rd::IRdFront was not generated with stream support";
            throw ex;
        }

        public override void read__(Ice.InputStream inS__, bool rid__)
        {
            Ice.MarshalException ex = new Ice.MarshalException();
            ex.reason = "type rd::IRdFront was not generated with stream support";
            throw ex;
        }

        #endregion
    }
}
