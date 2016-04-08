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

#if __MonoCS__

using _System = System;
using _Microsoft = Microsoft;
#else

using _System = global::System;
using _Microsoft = global::Microsoft;
#endif

namespace gtr
{
    public class CallReturnT : _System.ICloneable
    {
        #region Slice data members

        public bool succ;

        public string msg;

        public _System.Collections.Generic.Dictionary<string, string> props;

        #endregion

        #region Constructors

        public CallReturnT()
        {
        }

        public CallReturnT(bool succ, string msg, _System.Collections.Generic.Dictionary<string, string> props)
        {
            this.succ = succ;
            this.msg = msg;
            this.props = props;
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
            if(msg != null)
            {
                h__ = 5 * h__ + msg.GetHashCode();
            }
            if(props != null)
            {
                h__ = 5 * h__ + IceUtilInternal.Collections.DictionaryGetHashCode(props);
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
            CallReturnT o__ = (CallReturnT)other__;
            if(!succ.Equals(o__.succ))
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
            if(props == null)
            {
                if(o__.props != null)
                {
                    return false;
                }
            }
            else
            {
                if(!IceUtilInternal.Collections.DictionaryEquals(props, o__.props))
                {
                    return false;
                }
            }
            return true;
        }

        #endregion

        #region Comparison members

        public static bool operator==(CallReturnT lhs__, CallReturnT rhs__)
        {
            return Equals(lhs__, rhs__);
        }

        public static bool operator!=(CallReturnT lhs__, CallReturnT rhs__)
        {
            return !Equals(lhs__, rhs__);
        }

        #endregion

        #region Marshalling support

        public void write__(IceInternal.BasicStream os__)
        {
            os__.writeBool(succ);
            os__.writeString(msg);
            gtr.HashValueSetHelper.write(os__, props);
        }

        public void read__(IceInternal.BasicStream is__)
        {
            succ = is__.readBool();
            msg = is__.readString();
            props = gtr.HashValueSetHelper.read(is__);
        }

        #endregion
    }

    public abstract class IMAGEJPEG
    {
        public const int value = 1;
    }

    public abstract class IMAGEPNG
    {
        public const int value = 2;
    }

    public abstract class IMAGEBMP
    {
        public const int value = 3;
    }

    public class ImageDataT : _System.ICloneable
    {
        #region Slice data members

        public int type;

        public byte[] bytes;

        public int width;

        public int height;

        #endregion

        #region Constructors

        public ImageDataT()
        {
        }

        public ImageDataT(int type, byte[] bytes, int width, int height)
        {
            this.type = type;
            this.bytes = bytes;
            this.width = width;
            this.height = height;
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
            h__ = 5 * h__ + type.GetHashCode();
            if(bytes != null)
            {
                h__ = 5 * h__ + IceUtilInternal.Arrays.GetHashCode(bytes);
            }
            h__ = 5 * h__ + width.GetHashCode();
            h__ = 5 * h__ + height.GetHashCode();
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
            ImageDataT o__ = (ImageDataT)other__;
            if(!type.Equals(o__.type))
            {
                return false;
            }
            if(bytes == null)
            {
                if(o__.bytes != null)
                {
                    return false;
                }
            }
            else
            {
                if(!IceUtilInternal.Arrays.Equals(bytes, o__.bytes))
                {
                    return false;
                }
            }
            if(!width.Equals(o__.width))
            {
                return false;
            }
            if(!height.Equals(o__.height))
            {
                return false;
            }
            return true;
        }

        #endregion

        #region Comparison members

        public static bool operator==(ImageDataT lhs__, ImageDataT rhs__)
        {
            return Equals(lhs__, rhs__);
        }

        public static bool operator!=(ImageDataT lhs__, ImageDataT rhs__)
        {
            return !Equals(lhs__, rhs__);
        }

        #endregion

        #region Marshalling support

        public void write__(IceInternal.BasicStream os__)
        {
            os__.writeInt(type);
            os__.writeByteSeq(bytes);
            os__.writeInt(width);
            os__.writeInt(height);
        }

        public void read__(IceInternal.BasicStream is__)
        {
            type = is__.readInt();
            bytes = is__.readByteSeq();
            width = is__.readInt();
            height = is__.readInt();
        }

        #endregion
    }

    public class GameAuthDataT : _System.ICloneable
    {
        #region Slice data members

        public int type;

        public gtr.ImageDataT image;

        public string seckey;

        #endregion

        #region Constructors

        public GameAuthDataT()
        {
        }

        public GameAuthDataT(int type, gtr.ImageDataT image, string seckey)
        {
            this.type = type;
            this.image = image;
            this.seckey = seckey;
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
            h__ = 5 * h__ + type.GetHashCode();
            if(image != null)
            {
                h__ = 5 * h__ + image.GetHashCode();
            }
            if(seckey != null)
            {
                h__ = 5 * h__ + seckey.GetHashCode();
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
            GameAuthDataT o__ = (GameAuthDataT)other__;
            if(!type.Equals(o__.type))
            {
                return false;
            }
            if(image == null)
            {
                if(o__.image != null)
                {
                    return false;
                }
            }
            else
            {
                if(!image.Equals(o__.image))
                {
                    return false;
                }
            }
            if(seckey == null)
            {
                if(o__.seckey != null)
                {
                    return false;
                }
            }
            else
            {
                if(!seckey.Equals(o__.seckey))
                {
                    return false;
                }
            }
            return true;
        }

        #endregion

        #region Comparison members

        public static bool operator==(GameAuthDataT lhs__, GameAuthDataT rhs__)
        {
            return Equals(lhs__, rhs__);
        }

        public static bool operator!=(GameAuthDataT lhs__, GameAuthDataT rhs__)
        {
            return !Equals(lhs__, rhs__);
        }

        #endregion

        #region Marshalling support

        public void write__(IceInternal.BasicStream os__)
        {
            os__.writeInt(type);
            if(image == null)
            {
                gtr.ImageDataT tmp__ = new gtr.ImageDataT();
                tmp__.write__(os__);
            }
            else
            {
                image.write__(os__);
            }
            os__.writeString(seckey);
        }

        public void read__(IceInternal.BasicStream is__)
        {
            type = is__.readInt();
            if(image == null)
            {
                image = new gtr.ImageDataT();
            }
            image.read__(is__);
            seckey = is__.readString();
        }

        #endregion
    }

    public class GameIdentifyT : _System.ICloneable
    {
        #region Slice data members

        public string id;

        public string tradeNo;

        #endregion

        #region Constructors

        public GameIdentifyT()
        {
        }

        public GameIdentifyT(string id, string tradeNo)
        {
            this.id = id;
            this.tradeNo = tradeNo;
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
            if(tradeNo != null)
            {
                h__ = 5 * h__ + tradeNo.GetHashCode();
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
            GameIdentifyT o__ = (GameIdentifyT)other__;
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
            return true;
        }

        #endregion

        #region Comparison members

        public static bool operator==(GameIdentifyT lhs__, GameIdentifyT rhs__)
        {
            return Equals(lhs__, rhs__);
        }

        public static bool operator!=(GameIdentifyT lhs__, GameIdentifyT rhs__)
        {
            return !Equals(lhs__, rhs__);
        }

        #endregion

        #region Marshalling support

        public void write__(IceInternal.BasicStream os__)
        {
            os__.writeString(id);
            os__.writeString(tradeNo);
        }

        public void read__(IceInternal.BasicStream is__)
        {
            id = is__.readString();
            tradeNo = is__.readString();
        }

        #endregion
    }

    public class ServiceIdentifyT : _System.ICloneable
    {
        #region Slice data members

        public string id;

        public string version;

        #endregion

        #region Constructors

        public ServiceIdentifyT()
        {
        }

        public ServiceIdentifyT(string id, string version)
        {
            this.id = id;
            this.version = version;
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
            if(version != null)
            {
                h__ = 5 * h__ + version.GetHashCode();
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
            ServiceIdentifyT o__ = (ServiceIdentifyT)other__;
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
            if(version == null)
            {
                if(o__.version != null)
                {
                    return false;
                }
            }
            else
            {
                if(!version.Equals(o__.version))
                {
                    return false;
                }
            }
            return true;
        }

        #endregion

        #region Comparison members

        public static bool operator==(ServiceIdentifyT lhs__, ServiceIdentifyT rhs__)
        {
            return Equals(lhs__, rhs__);
        }

        public static bool operator!=(ServiceIdentifyT lhs__, ServiceIdentifyT rhs__)
        {
            return !Equals(lhs__, rhs__);
        }

        #endregion

        #region Marshalling support

        public void write__(IceInternal.BasicStream os__)
        {
            os__.writeString(id);
            os__.writeString(version);
        }

        public void read__(IceInternal.BasicStream is__)
        {
            id = is__.readString();
            version = is__.readString();
        }

        #endregion
    }

    public interface IService : Ice.Object, IServiceOperations_, IServiceOperationsNC_
    {
    }

    public class QuestionContentT : _System.ICloneable
    {
        #region Slice data members

        public int type;

        public gtr.ImageDataT image;

        public gtr.ImageDataT image2;

        public string text;

        public int cookie;

        public string gameId;

        #endregion

        #region Constructors

        public QuestionContentT()
        {
        }

        public QuestionContentT(int type, gtr.ImageDataT image, gtr.ImageDataT image2, string text, int cookie, string gameId)
        {
            this.type = type;
            this.image = image;
            this.image2 = image2;
            this.text = text;
            this.cookie = cookie;
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
            h__ = 5 * h__ + type.GetHashCode();
            if(image != null)
            {
                h__ = 5 * h__ + image.GetHashCode();
            }
            if(image2 != null)
            {
                h__ = 5 * h__ + image2.GetHashCode();
            }
            if(text != null)
            {
                h__ = 5 * h__ + text.GetHashCode();
            }
            h__ = 5 * h__ + cookie.GetHashCode();
            if(gameId != null)
            {
                h__ = 5 * h__ + gameId.GetHashCode();
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
            QuestionContentT o__ = (QuestionContentT)other__;
            if(!type.Equals(o__.type))
            {
                return false;
            }
            if(image == null)
            {
                if(o__.image != null)
                {
                    return false;
                }
            }
            else
            {
                if(!image.Equals(o__.image))
                {
                    return false;
                }
            }
            if(image2 == null)
            {
                if(o__.image2 != null)
                {
                    return false;
                }
            }
            else
            {
                if(!image2.Equals(o__.image2))
                {
                    return false;
                }
            }
            if(text == null)
            {
                if(o__.text != null)
                {
                    return false;
                }
            }
            else
            {
                if(!text.Equals(o__.text))
                {
                    return false;
                }
            }
            if(!cookie.Equals(o__.cookie))
            {
                return false;
            }
            if(gameId == null)
            {
                if(o__.gameId != null)
                {
                    return false;
                }
            }
            else
            {
                if(!gameId.Equals(o__.gameId))
                {
                    return false;
                }
            }
            return true;
        }

        #endregion

        #region Comparison members

        public static bool operator==(QuestionContentT lhs__, QuestionContentT rhs__)
        {
            return Equals(lhs__, rhs__);
        }

        public static bool operator!=(QuestionContentT lhs__, QuestionContentT rhs__)
        {
            return !Equals(lhs__, rhs__);
        }

        #endregion

        #region Marshalling support

        public void write__(IceInternal.BasicStream os__)
        {
            os__.writeInt(type);
            if(image == null)
            {
                gtr.ImageDataT tmp__ = new gtr.ImageDataT();
                tmp__.write__(os__);
            }
            else
            {
                image.write__(os__);
            }
            if(image2 == null)
            {
                gtr.ImageDataT tmp__ = new gtr.ImageDataT();
                tmp__.write__(os__);
            }
            else
            {
                image2.write__(os__);
            }
            os__.writeString(text);
            os__.writeInt(cookie);
            os__.writeString(gameId);
        }

        public void read__(IceInternal.BasicStream is__)
        {
            type = is__.readInt();
            if(image == null)
            {
                image = new gtr.ImageDataT();
            }
            image.read__(is__);
            if(image2 == null)
            {
                image2 = new gtr.ImageDataT();
            }
            image2.read__(is__);
            text = is__.readString();
            cookie = is__.readInt();
            gameId = is__.readString();
        }

        #endregion
    }

    public class QuestionResultT : _System.ICloneable
    {
        #region Slice data members

        public string value;

        public int cookie;

        #endregion

        #region Constructors

        public QuestionResultT()
        {
        }

        public QuestionResultT(string value, int cookie)
        {
            this.value = value;
            this.cookie = cookie;
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
            if(value != null)
            {
                h__ = 5 * h__ + value.GetHashCode();
            }
            h__ = 5 * h__ + cookie.GetHashCode();
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
            QuestionResultT o__ = (QuestionResultT)other__;
            if(value == null)
            {
                if(o__.value != null)
                {
                    return false;
                }
            }
            else
            {
                if(!value.Equals(o__.value))
                {
                    return false;
                }
            }
            if(!cookie.Equals(o__.cookie))
            {
                return false;
            }
            return true;
        }

        #endregion

        #region Comparison members

        public static bool operator==(QuestionResultT lhs__, QuestionResultT rhs__)
        {
            return Equals(lhs__, rhs__);
        }

        public static bool operator!=(QuestionResultT lhs__, QuestionResultT rhs__)
        {
            return !Equals(lhs__, rhs__);
        }

        #endregion

        #region Marshalling support

        public void write__(IceInternal.BasicStream os__)
        {
            os__.writeString(value);
            os__.writeInt(cookie);
        }

        public void read__(IceInternal.BasicStream is__)
        {
            value = is__.readString();
            cookie = is__.readInt();
        }

        #endregion
    }

    public interface IAnswerEndpoint : Ice.Object, IAnswerEndpointOperations_, IAnswerEndpointOperationsNC_, gtr.IService
    {
    }

    public interface IQuestionAsker : Ice.Object, IQuestionAskerOperations_, IQuestionAskerOperationsNC_
    {
    }

    public interface IQuestionServer : Ice.Object, IQuestionServerOperations_, IQuestionServerOperationsNC_, gtr.IService
    {
    }

    public class LogMessageT : _System.ICloneable
    {
        #region Slice data members

        public int xclass;

        public string msg;

        #endregion

        #region Constructors

        public LogMessageT()
        {
        }

        public LogMessageT(int xclass, string msg)
        {
            this.xclass = xclass;
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
            h__ = 5 * h__ + xclass.GetHashCode();
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
            LogMessageT o__ = (LogMessageT)other__;
            if(!xclass.Equals(o__.xclass))
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

        public static bool operator==(LogMessageT lhs__, LogMessageT rhs__)
        {
            return Equals(lhs__, rhs__);
        }

        public static bool operator!=(LogMessageT lhs__, LogMessageT rhs__)
        {
            return !Equals(lhs__, rhs__);
        }

        #endregion

        #region Marshalling support

        public void write__(IceInternal.BasicStream os__)
        {
            os__.writeInt(xclass);
            os__.writeString(msg);
        }

        public void read__(IceInternal.BasicStream is__)
        {
            xclass = is__.readInt();
            msg = is__.readString();
        }

        #endregion
    }

    public interface ILogger : Ice.Object, ILoggerOperations_, ILoggerOperationsNC_
    {
    }

    public interface ILogServer : Ice.Object, ILogServerOperations_, ILogServerOperationsNC_, gtr.ILogger, gtr.IService
    {
    }

    public abstract class gwsPost
    {
        public const int value = 1;
    }

    public abstract class gwsAccountAudit
    {
        public const int value = 2;
    }

    public abstract class gwsVerify
    {
        public const int value = 4;
    }

    public class GameWorkSheetPostT : _System.ICloneable
    {
        #region Slice data members

        public string sellerActor;

        public int sellerLevel;

        public long money;

        public int transactionTime;

        public string sellerSecondPwd;

        public string buyerActor;

        public int buyerLevel;

        public long buyerMoney;

        public int sellerIndex;

        public int sellerGroup;

        public string bankPwd;

        #endregion

        #region Constructors

        public GameWorkSheetPostT()
        {
        }

        public GameWorkSheetPostT(string sellerActor, int sellerLevel, long money, int transactionTime, string sellerSecondPwd, string buyerActor, int buyerLevel, long buyerMoney, int sellerIndex, int sellerGroup, string bankPwd)
        {
            this.sellerActor = sellerActor;
            this.sellerLevel = sellerLevel;
            this.money = money;
            this.transactionTime = transactionTime;
            this.sellerSecondPwd = sellerSecondPwd;
            this.buyerActor = buyerActor;
            this.buyerLevel = buyerLevel;
            this.buyerMoney = buyerMoney;
            this.sellerIndex = sellerIndex;
            this.sellerGroup = sellerGroup;
            this.bankPwd = bankPwd;
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
            if(sellerActor != null)
            {
                h__ = 5 * h__ + sellerActor.GetHashCode();
            }
            h__ = 5 * h__ + sellerLevel.GetHashCode();
            h__ = 5 * h__ + money.GetHashCode();
            h__ = 5 * h__ + transactionTime.GetHashCode();
            if(sellerSecondPwd != null)
            {
                h__ = 5 * h__ + sellerSecondPwd.GetHashCode();
            }
            if(buyerActor != null)
            {
                h__ = 5 * h__ + buyerActor.GetHashCode();
            }
            h__ = 5 * h__ + buyerLevel.GetHashCode();
            h__ = 5 * h__ + buyerMoney.GetHashCode();
            h__ = 5 * h__ + sellerIndex.GetHashCode();
            h__ = 5 * h__ + sellerGroup.GetHashCode();
            if(bankPwd != null)
            {
                h__ = 5 * h__ + bankPwd.GetHashCode();
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
            GameWorkSheetPostT o__ = (GameWorkSheetPostT)other__;
            if(sellerActor == null)
            {
                if(o__.sellerActor != null)
                {
                    return false;
                }
            }
            else
            {
                if(!sellerActor.Equals(o__.sellerActor))
                {
                    return false;
                }
            }
            if(!sellerLevel.Equals(o__.sellerLevel))
            {
                return false;
            }
            if(!money.Equals(o__.money))
            {
                return false;
            }
            if(!transactionTime.Equals(o__.transactionTime))
            {
                return false;
            }
            if(sellerSecondPwd == null)
            {
                if(o__.sellerSecondPwd != null)
                {
                    return false;
                }
            }
            else
            {
                if(!sellerSecondPwd.Equals(o__.sellerSecondPwd))
                {
                    return false;
                }
            }
            if(buyerActor == null)
            {
                if(o__.buyerActor != null)
                {
                    return false;
                }
            }
            else
            {
                if(!buyerActor.Equals(o__.buyerActor))
                {
                    return false;
                }
            }
            if(!buyerLevel.Equals(o__.buyerLevel))
            {
                return false;
            }
            if(!buyerMoney.Equals(o__.buyerMoney))
            {
                return false;
            }
            if(!sellerIndex.Equals(o__.sellerIndex))
            {
                return false;
            }
            if(!sellerGroup.Equals(o__.sellerGroup))
            {
                return false;
            }
            if(bankPwd == null)
            {
                if(o__.bankPwd != null)
                {
                    return false;
                }
            }
            else
            {
                if(!bankPwd.Equals(o__.bankPwd))
                {
                    return false;
                }
            }
            return true;
        }

        #endregion

        #region Comparison members

        public static bool operator==(GameWorkSheetPostT lhs__, GameWorkSheetPostT rhs__)
        {
            return Equals(lhs__, rhs__);
        }

        public static bool operator!=(GameWorkSheetPostT lhs__, GameWorkSheetPostT rhs__)
        {
            return !Equals(lhs__, rhs__);
        }

        #endregion

        #region Marshalling support

        public void write__(IceInternal.BasicStream os__)
        {
            os__.writeString(sellerActor);
            os__.writeInt(sellerLevel);
            os__.writeLong(money);
            os__.writeInt(transactionTime);
            os__.writeString(sellerSecondPwd);
            os__.writeString(buyerActor);
            os__.writeInt(buyerLevel);
            os__.writeLong(buyerMoney);
            os__.writeInt(sellerIndex);
            os__.writeInt(sellerGroup);
            os__.writeString(bankPwd);
        }

        public void read__(IceInternal.BasicStream is__)
        {
            sellerActor = is__.readString();
            sellerLevel = is__.readInt();
            money = is__.readLong();
            transactionTime = is__.readInt();
            sellerSecondPwd = is__.readString();
            buyerActor = is__.readString();
            buyerLevel = is__.readInt();
            buyerMoney = is__.readLong();
            sellerIndex = is__.readInt();
            sellerGroup = is__.readInt();
            bankPwd = is__.readString();
        }

        #endregion
    }

    public class GameWorkSheetAccountAuditT : _System.ICloneable
    {
        #region Slice data members

        public string sellerActor;

        public string sellerSecondPwd;

        public int sellerIndex;

        public int sellerGroup;

        public string bankPwd;

        #endregion

        #region Constructors

        public GameWorkSheetAccountAuditT()
        {
        }

        public GameWorkSheetAccountAuditT(string sellerActor, string sellerSecondPwd, int sellerIndex, int sellerGroup, string bankPwd)
        {
            this.sellerActor = sellerActor;
            this.sellerSecondPwd = sellerSecondPwd;
            this.sellerIndex = sellerIndex;
            this.sellerGroup = sellerGroup;
            this.bankPwd = bankPwd;
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
            if(sellerActor != null)
            {
                h__ = 5 * h__ + sellerActor.GetHashCode();
            }
            if(sellerSecondPwd != null)
            {
                h__ = 5 * h__ + sellerSecondPwd.GetHashCode();
            }
            h__ = 5 * h__ + sellerIndex.GetHashCode();
            h__ = 5 * h__ + sellerGroup.GetHashCode();
            if(bankPwd != null)
            {
                h__ = 5 * h__ + bankPwd.GetHashCode();
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
            GameWorkSheetAccountAuditT o__ = (GameWorkSheetAccountAuditT)other__;
            if(sellerActor == null)
            {
                if(o__.sellerActor != null)
                {
                    return false;
                }
            }
            else
            {
                if(!sellerActor.Equals(o__.sellerActor))
                {
                    return false;
                }
            }
            if(sellerSecondPwd == null)
            {
                if(o__.sellerSecondPwd != null)
                {
                    return false;
                }
            }
            else
            {
                if(!sellerSecondPwd.Equals(o__.sellerSecondPwd))
                {
                    return false;
                }
            }
            if(!sellerIndex.Equals(o__.sellerIndex))
            {
                return false;
            }
            if(!sellerGroup.Equals(o__.sellerGroup))
            {
                return false;
            }
            if(bankPwd == null)
            {
                if(o__.bankPwd != null)
                {
                    return false;
                }
            }
            else
            {
                if(!bankPwd.Equals(o__.bankPwd))
                {
                    return false;
                }
            }
            return true;
        }

        #endregion

        #region Comparison members

        public static bool operator==(GameWorkSheetAccountAuditT lhs__, GameWorkSheetAccountAuditT rhs__)
        {
            return Equals(lhs__, rhs__);
        }

        public static bool operator!=(GameWorkSheetAccountAuditT lhs__, GameWorkSheetAccountAuditT rhs__)
        {
            return !Equals(lhs__, rhs__);
        }

        #endregion

        #region Marshalling support

        public void write__(IceInternal.BasicStream os__)
        {
            os__.writeString(sellerActor);
            os__.writeString(sellerSecondPwd);
            os__.writeInt(sellerIndex);
            os__.writeInt(sellerGroup);
            os__.writeString(bankPwd);
        }

        public void read__(IceInternal.BasicStream is__)
        {
            sellerActor = is__.readString();
            sellerSecondPwd = is__.readString();
            sellerIndex = is__.readInt();
            sellerGroup = is__.readInt();
            bankPwd = is__.readString();
        }

        #endregion
    }

    public class GameWorkSheetVerifyT : _System.ICloneable
    {
        #region Slice data members

        public string sellerActor;

        public int level;

        public long money;

        public int verifyTime;

        public string sellerSecondPwd;

        public int sellerIndex;

        public int sellerGroup;

        public string bankPwd;

        #endregion

        #region Constructors

        public GameWorkSheetVerifyT()
        {
        }

        public GameWorkSheetVerifyT(string sellerActor, int level, long money, int verifyTime, string sellerSecondPwd, int sellerIndex, int sellerGroup, string bankPwd)
        {
            this.sellerActor = sellerActor;
            this.level = level;
            this.money = money;
            this.verifyTime = verifyTime;
            this.sellerSecondPwd = sellerSecondPwd;
            this.sellerIndex = sellerIndex;
            this.sellerGroup = sellerGroup;
            this.bankPwd = bankPwd;
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
            if(sellerActor != null)
            {
                h__ = 5 * h__ + sellerActor.GetHashCode();
            }
            h__ = 5 * h__ + level.GetHashCode();
            h__ = 5 * h__ + money.GetHashCode();
            h__ = 5 * h__ + verifyTime.GetHashCode();
            if(sellerSecondPwd != null)
            {
                h__ = 5 * h__ + sellerSecondPwd.GetHashCode();
            }
            h__ = 5 * h__ + sellerIndex.GetHashCode();
            h__ = 5 * h__ + sellerGroup.GetHashCode();
            if(bankPwd != null)
            {
                h__ = 5 * h__ + bankPwd.GetHashCode();
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
            GameWorkSheetVerifyT o__ = (GameWorkSheetVerifyT)other__;
            if(sellerActor == null)
            {
                if(o__.sellerActor != null)
                {
                    return false;
                }
            }
            else
            {
                if(!sellerActor.Equals(o__.sellerActor))
                {
                    return false;
                }
            }
            if(!level.Equals(o__.level))
            {
                return false;
            }
            if(!money.Equals(o__.money))
            {
                return false;
            }
            if(!verifyTime.Equals(o__.verifyTime))
            {
                return false;
            }
            if(sellerSecondPwd == null)
            {
                if(o__.sellerSecondPwd != null)
                {
                    return false;
                }
            }
            else
            {
                if(!sellerSecondPwd.Equals(o__.sellerSecondPwd))
                {
                    return false;
                }
            }
            if(!sellerIndex.Equals(o__.sellerIndex))
            {
                return false;
            }
            if(!sellerGroup.Equals(o__.sellerGroup))
            {
                return false;
            }
            if(bankPwd == null)
            {
                if(o__.bankPwd != null)
                {
                    return false;
                }
            }
            else
            {
                if(!bankPwd.Equals(o__.bankPwd))
                {
                    return false;
                }
            }
            return true;
        }

        #endregion

        #region Comparison members

        public static bool operator==(GameWorkSheetVerifyT lhs__, GameWorkSheetVerifyT rhs__)
        {
            return Equals(lhs__, rhs__);
        }

        public static bool operator!=(GameWorkSheetVerifyT lhs__, GameWorkSheetVerifyT rhs__)
        {
            return !Equals(lhs__, rhs__);
        }

        #endregion

        #region Marshalling support

        public void write__(IceInternal.BasicStream os__)
        {
            os__.writeString(sellerActor);
            os__.writeInt(level);
            os__.writeLong(money);
            os__.writeInt(verifyTime);
            os__.writeString(sellerSecondPwd);
            os__.writeInt(sellerIndex);
            os__.writeInt(sellerGroup);
            os__.writeString(bankPwd);
        }

        public void read__(IceInternal.BasicStream is__)
        {
            sellerActor = is__.readString();
            level = is__.readInt();
            money = is__.readLong();
            verifyTime = is__.readInt();
            sellerSecondPwd = is__.readString();
            sellerIndex = is__.readInt();
            sellerGroup = is__.readInt();
            bankPwd = is__.readString();
        }

        #endregion
    }

    public class GameTaskletT : _System.ICloneable
    {
        #region Slice data members

        public string id;

        public int type;

        public string no;

        public string gameId;

        public string account;

        public string password;

        public string area;

        public string server;

        public string lineName;

        public short lineNo;

        public string createTime;

        public string secretKey;

        public bool proxyEnable;

        public string proxyRegion;

        public int remainTime;

        public gtr.GameWorkSheetPostT post;

        public gtr.GameWorkSheetAccountAuditT audit;

        public gtr.GameWorkSheetVerifyT verify;

        #endregion

        #region Constructors

        public GameTaskletT()
        {
        }

        public GameTaskletT(string id, int type, string no, string gameId, string account, string password, string area, string server, string lineName, short lineNo, string createTime, string secretKey, bool proxyEnable, string proxyRegion, int remainTime, gtr.GameWorkSheetPostT post, gtr.GameWorkSheetAccountAuditT audit, gtr.GameWorkSheetVerifyT verify)
        {
            this.id = id;
            this.type = type;
            this.no = no;
            this.gameId = gameId;
            this.account = account;
            this.password = password;
            this.area = area;
            this.server = server;
            this.lineName = lineName;
            this.lineNo = lineNo;
            this.createTime = createTime;
            this.secretKey = secretKey;
            this.proxyEnable = proxyEnable;
            this.proxyRegion = proxyRegion;
            this.remainTime = remainTime;
            this.post = post;
            this.audit = audit;
            this.verify = verify;
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
            h__ = 5 * h__ + type.GetHashCode();
            if(no != null)
            {
                h__ = 5 * h__ + no.GetHashCode();
            }
            if(gameId != null)
            {
                h__ = 5 * h__ + gameId.GetHashCode();
            }
            if(account != null)
            {
                h__ = 5 * h__ + account.GetHashCode();
            }
            if(password != null)
            {
                h__ = 5 * h__ + password.GetHashCode();
            }
            if(area != null)
            {
                h__ = 5 * h__ + area.GetHashCode();
            }
            if(server != null)
            {
                h__ = 5 * h__ + server.GetHashCode();
            }
            if(lineName != null)
            {
                h__ = 5 * h__ + lineName.GetHashCode();
            }
            h__ = 5 * h__ + lineNo.GetHashCode();
            if(createTime != null)
            {
                h__ = 5 * h__ + createTime.GetHashCode();
            }
            if(secretKey != null)
            {
                h__ = 5 * h__ + secretKey.GetHashCode();
            }
            h__ = 5 * h__ + proxyEnable.GetHashCode();
            if(proxyRegion != null)
            {
                h__ = 5 * h__ + proxyRegion.GetHashCode();
            }
            h__ = 5 * h__ + remainTime.GetHashCode();
            if(post != null)
            {
                h__ = 5 * h__ + post.GetHashCode();
            }
            if(audit != null)
            {
                h__ = 5 * h__ + audit.GetHashCode();
            }
            if(verify != null)
            {
                h__ = 5 * h__ + verify.GetHashCode();
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
            GameTaskletT o__ = (GameTaskletT)other__;
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
            if(!type.Equals(o__.type))
            {
                return false;
            }
            if(no == null)
            {
                if(o__.no != null)
                {
                    return false;
                }
            }
            else
            {
                if(!no.Equals(o__.no))
                {
                    return false;
                }
            }
            if(gameId == null)
            {
                if(o__.gameId != null)
                {
                    return false;
                }
            }
            else
            {
                if(!gameId.Equals(o__.gameId))
                {
                    return false;
                }
            }
            if(account == null)
            {
                if(o__.account != null)
                {
                    return false;
                }
            }
            else
            {
                if(!account.Equals(o__.account))
                {
                    return false;
                }
            }
            if(password == null)
            {
                if(o__.password != null)
                {
                    return false;
                }
            }
            else
            {
                if(!password.Equals(o__.password))
                {
                    return false;
                }
            }
            if(area == null)
            {
                if(o__.area != null)
                {
                    return false;
                }
            }
            else
            {
                if(!area.Equals(o__.area))
                {
                    return false;
                }
            }
            if(server == null)
            {
                if(o__.server != null)
                {
                    return false;
                }
            }
            else
            {
                if(!server.Equals(o__.server))
                {
                    return false;
                }
            }
            if(lineName == null)
            {
                if(o__.lineName != null)
                {
                    return false;
                }
            }
            else
            {
                if(!lineName.Equals(o__.lineName))
                {
                    return false;
                }
            }
            if(!lineNo.Equals(o__.lineNo))
            {
                return false;
            }
            if(createTime == null)
            {
                if(o__.createTime != null)
                {
                    return false;
                }
            }
            else
            {
                if(!createTime.Equals(o__.createTime))
                {
                    return false;
                }
            }
            if(secretKey == null)
            {
                if(o__.secretKey != null)
                {
                    return false;
                }
            }
            else
            {
                if(!secretKey.Equals(o__.secretKey))
                {
                    return false;
                }
            }
            if(!proxyEnable.Equals(o__.proxyEnable))
            {
                return false;
            }
            if(proxyRegion == null)
            {
                if(o__.proxyRegion != null)
                {
                    return false;
                }
            }
            else
            {
                if(!proxyRegion.Equals(o__.proxyRegion))
                {
                    return false;
                }
            }
            if(!remainTime.Equals(o__.remainTime))
            {
                return false;
            }
            if(post == null)
            {
                if(o__.post != null)
                {
                    return false;
                }
            }
            else
            {
                if(!post.Equals(o__.post))
                {
                    return false;
                }
            }
            if(audit == null)
            {
                if(o__.audit != null)
                {
                    return false;
                }
            }
            else
            {
                if(!audit.Equals(o__.audit))
                {
                    return false;
                }
            }
            if(verify == null)
            {
                if(o__.verify != null)
                {
                    return false;
                }
            }
            else
            {
                if(!verify.Equals(o__.verify))
                {
                    return false;
                }
            }
            return true;
        }

        #endregion

        #region Comparison members

        public static bool operator==(GameTaskletT lhs__, GameTaskletT rhs__)
        {
            return Equals(lhs__, rhs__);
        }

        public static bool operator!=(GameTaskletT lhs__, GameTaskletT rhs__)
        {
            return !Equals(lhs__, rhs__);
        }

        #endregion

        #region Marshalling support

        public void write__(IceInternal.BasicStream os__)
        {
            os__.writeString(id);
            os__.writeInt(type);
            os__.writeString(no);
            os__.writeString(gameId);
            os__.writeString(account);
            os__.writeString(password);
            os__.writeString(area);
            os__.writeString(server);
            os__.writeString(lineName);
            os__.writeShort(lineNo);
            os__.writeString(createTime);
            os__.writeString(secretKey);
            os__.writeBool(proxyEnable);
            os__.writeString(proxyRegion);
            os__.writeInt(remainTime);
            if(post == null)
            {
                gtr.GameWorkSheetPostT tmp__ = new gtr.GameWorkSheetPostT();
                tmp__.write__(os__);
            }
            else
            {
                post.write__(os__);
            }
            if(audit == null)
            {
                gtr.GameWorkSheetAccountAuditT tmp__ = new gtr.GameWorkSheetAccountAuditT();
                tmp__.write__(os__);
            }
            else
            {
                audit.write__(os__);
            }
            if(verify == null)
            {
                gtr.GameWorkSheetVerifyT tmp__ = new gtr.GameWorkSheetVerifyT();
                tmp__.write__(os__);
            }
            else
            {
                verify.write__(os__);
            }
        }

        public void read__(IceInternal.BasicStream is__)
        {
            id = is__.readString();
            type = is__.readInt();
            no = is__.readString();
            gameId = is__.readString();
            account = is__.readString();
            password = is__.readString();
            area = is__.readString();
            server = is__.readString();
            lineName = is__.readString();
            lineNo = is__.readShort();
            createTime = is__.readString();
            secretKey = is__.readString();
            proxyEnable = is__.readBool();
            proxyRegion = is__.readString();
            remainTime = is__.readInt();
            if(post == null)
            {
                post = new gtr.GameWorkSheetPostT();
            }
            post.read__(is__);
            if(audit == null)
            {
                audit = new gtr.GameWorkSheetAccountAuditT();
            }
            audit.read__(is__);
            if(verify == null)
            {
                verify = new gtr.GameWorkSheetVerifyT();
            }
            verify.read__(is__);
        }

        #endregion
    }

    public class GameTaskResultT : _System.ICloneable
    {
        #region Slice data members

        public string id;

        public string no;

        public int type;

        public string gameId;

        public int result;

        public string errmsg;

        public string textval;

        #endregion

        #region Constructors

        public GameTaskResultT()
        {
        }

        public GameTaskResultT(string id, string no, int type, string gameId, int result, string errmsg, string textval)
        {
            this.id = id;
            this.no = no;
            this.type = type;
            this.gameId = gameId;
            this.result = result;
            this.errmsg = errmsg;
            this.textval = textval;
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
            if(no != null)
            {
                h__ = 5 * h__ + no.GetHashCode();
            }
            h__ = 5 * h__ + type.GetHashCode();
            if(gameId != null)
            {
                h__ = 5 * h__ + gameId.GetHashCode();
            }
            h__ = 5 * h__ + result.GetHashCode();
            if(errmsg != null)
            {
                h__ = 5 * h__ + errmsg.GetHashCode();
            }
            if(textval != null)
            {
                h__ = 5 * h__ + textval.GetHashCode();
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
            GameTaskResultT o__ = (GameTaskResultT)other__;
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
            if(no == null)
            {
                if(o__.no != null)
                {
                    return false;
                }
            }
            else
            {
                if(!no.Equals(o__.no))
                {
                    return false;
                }
            }
            if(!type.Equals(o__.type))
            {
                return false;
            }
            if(gameId == null)
            {
                if(o__.gameId != null)
                {
                    return false;
                }
            }
            else
            {
                if(!gameId.Equals(o__.gameId))
                {
                    return false;
                }
            }
            if(!result.Equals(o__.result))
            {
                return false;
            }
            if(errmsg == null)
            {
                if(o__.errmsg != null)
                {
                    return false;
                }
            }
            else
            {
                if(!errmsg.Equals(o__.errmsg))
                {
                    return false;
                }
            }
            if(textval == null)
            {
                if(o__.textval != null)
                {
                    return false;
                }
            }
            else
            {
                if(!textval.Equals(o__.textval))
                {
                    return false;
                }
            }
            return true;
        }

        #endregion

        #region Comparison members

        public static bool operator==(GameTaskResultT lhs__, GameTaskResultT rhs__)
        {
            return Equals(lhs__, rhs__);
        }

        public static bool operator!=(GameTaskResultT lhs__, GameTaskResultT rhs__)
        {
            return !Equals(lhs__, rhs__);
        }

        #endregion

        #region Marshalling support

        public void write__(IceInternal.BasicStream os__)
        {
            os__.writeString(id);
            os__.writeString(no);
            os__.writeInt(type);
            os__.writeString(gameId);
            os__.writeInt(result);
            os__.writeString(errmsg);
            os__.writeString(textval);
        }

        public void read__(IceInternal.BasicStream is__)
        {
            id = is__.readString();
            no = is__.readString();
            type = is__.readInt();
            gameId = is__.readString();
            result = is__.readInt();
            errmsg = is__.readString();
            textval = is__.readString();
        }

        #endregion
    }

    public interface IGameHost : Ice.Object, IGameHostOperations_, IGameHostOperationsNC_, gtr.IQuestionAsker, gtr.IService, gtr.ILogger
    {
    }

    public class GameInfoT : _System.ICloneable
    {
        #region Slice data members

        public int id;

        public string name;

        public string version;

        public int maskType;

        #endregion

        #region Constructors

        public GameInfoT()
        {
        }

        public GameInfoT(int id, string name, string version, int maskType)
        {
            this.id = id;
            this.name = name;
            this.version = version;
            this.maskType = maskType;
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
            h__ = 5 * h__ + id.GetHashCode();
            if(name != null)
            {
                h__ = 5 * h__ + name.GetHashCode();
            }
            if(version != null)
            {
                h__ = 5 * h__ + version.GetHashCode();
            }
            h__ = 5 * h__ + maskType.GetHashCode();
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
            GameInfoT o__ = (GameInfoT)other__;
            if(!id.Equals(o__.id))
            {
                return false;
            }
            if(name == null)
            {
                if(o__.name != null)
                {
                    return false;
                }
            }
            else
            {
                if(!name.Equals(o__.name))
                {
                    return false;
                }
            }
            if(version == null)
            {
                if(o__.version != null)
                {
                    return false;
                }
            }
            else
            {
                if(!version.Equals(o__.version))
                {
                    return false;
                }
            }
            if(!maskType.Equals(o__.maskType))
            {
                return false;
            }
            return true;
        }

        #endregion

        #region Comparison members

        public static bool operator==(GameInfoT lhs__, GameInfoT rhs__)
        {
            return Equals(lhs__, rhs__);
        }

        public static bool operator!=(GameInfoT lhs__, GameInfoT rhs__)
        {
            return !Equals(lhs__, rhs__);
        }

        #endregion

        #region Marshalling support

        public void write__(IceInternal.BasicStream os__)
        {
            os__.writeInt(id);
            os__.writeString(name);
            os__.writeString(version);
            os__.writeInt(maskType);
        }

        public void read__(IceInternal.BasicStream is__)
        {
            id = is__.readInt();
            name = is__.readString();
            version = is__.readString();
            maskType = is__.readInt();
        }

        #endregion
    }

    public class GameRobotInfoT : _System.ICloneable
    {
        #region Slice data members

        public string id;

        public string ip;

        public int network;

        public gtr.GameInfoT[] supportGames;

        #endregion

        #region Constructors

        public GameRobotInfoT()
        {
        }

        public GameRobotInfoT(string id, string ip, int network, gtr.GameInfoT[] supportGames)
        {
            this.id = id;
            this.ip = ip;
            this.network = network;
            this.supportGames = supportGames;
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
            h__ = 5 * h__ + network.GetHashCode();
            if(supportGames != null)
            {
                h__ = 5 * h__ + IceUtilInternal.Arrays.GetHashCode(supportGames);
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
            GameRobotInfoT o__ = (GameRobotInfoT)other__;
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
            if(!network.Equals(o__.network))
            {
                return false;
            }
            if(supportGames == null)
            {
                if(o__.supportGames != null)
                {
                    return false;
                }
            }
            else
            {
                if(!IceUtilInternal.Arrays.Equals(supportGames, o__.supportGames))
                {
                    return false;
                }
            }
            return true;
        }

        #endregion

        #region Comparison members

        public static bool operator==(GameRobotInfoT lhs__, GameRobotInfoT rhs__)
        {
            return Equals(lhs__, rhs__);
        }

        public static bool operator!=(GameRobotInfoT lhs__, GameRobotInfoT rhs__)
        {
            return !Equals(lhs__, rhs__);
        }

        #endregion

        #region Marshalling support

        public void write__(IceInternal.BasicStream os__)
        {
            os__.writeString(id);
            os__.writeString(ip);
            os__.writeInt(network);
            if(supportGames == null)
            {
                os__.writeSize(0);
            }
            else
            {
                os__.writeSize(supportGames.Length);
                for(int ix__ = 0; ix__ < supportGames.Length; ++ix__)
                {
                    (supportGames[ix__] == null ? new gtr.GameInfoT() : supportGames[ix__]).write__(os__);
                }
            }
        }

        public void read__(IceInternal.BasicStream is__)
        {
            id = is__.readString();
            ip = is__.readString();
            network = is__.readInt();
            {
                int szx__ = is__.readSize();
                is__.startSeq(szx__, 10);
                supportGames = new gtr.GameInfoT[szx__];
                for(int ix__ = 0; ix__ < szx__; ++ix__)
                {
                    supportGames[ix__] = new gtr.GameInfoT();
                    supportGames[ix__].read__(is__);
                    is__.checkSeq();
                    is__.endElement();
                }
                is__.endSeq(szx__);
            }
        }

        #endregion
    }

    public interface IGtrServer : Ice.Object, IGtrServerOperations_, IGtrServerOperationsNC_, gtr.IService, gtr.IQuestionServer
    {
    }
}

namespace gtr
{
    public interface IServicePrx : Ice.ObjectPrx
    {
        int ice_getType_();
        int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__);

        gtr.ServiceIdentifyT getId();
        gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__);

        int getTimestamp();
        int getTimestamp(_System.Collections.Generic.Dictionary<string, string> context__);

        void shutdown();
        void shutdown(_System.Collections.Generic.Dictionary<string, string> context__);

        void heartbeat(string senderType, string senderId);
        void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__);
    }

    public interface IAnswerEndpointPrx : gtr.IServicePrx
    {
        int getRemains();
        int getRemains(_System.Collections.Generic.Dictionary<string, string> context__);

        int addQuestion(gtr.IQuestionServerPrx server, string no, string createTime, gtr.QuestionContentT question);
        int addQuestion(gtr.IQuestionServerPrx server, string no, string createTime, gtr.QuestionContentT question, _System.Collections.Generic.Dictionary<string, string> context__);
    }

    public interface IQuestionAskerPrx : Ice.ObjectPrx
    {
        void answerResult(string no, string result);
        void answerResult(string no, string result, _System.Collections.Generic.Dictionary<string, string> context__);
    }

    public interface IQuestionServerPrx : gtr.IServicePrx
    {
        void answer(gtr.IQuestionAskerPrx asker, string no, gtr.QuestionContentT question);
        void answer(gtr.IQuestionAskerPrx asker, string no, gtr.QuestionContentT question, _System.Collections.Generic.Dictionary<string, string> context__);

        void answerResult(string no, gtr.QuestionResultT result);
        void answerResult(string no, gtr.QuestionResultT result, _System.Collections.Generic.Dictionary<string, string> context__);

        gtr.CallReturnT login(gtr.IAnswerEndpointPrx answer, string worker, string passwd);
        gtr.CallReturnT login(gtr.IAnswerEndpointPrx answer, string worker, string passwd, _System.Collections.Generic.Dictionary<string, string> context__);

        void logout(gtr.IAnswerEndpointPrx answer, string worker);
        void logout(gtr.IAnswerEndpointPrx answer, string worker, _System.Collections.Generic.Dictionary<string, string> context__);

        void verifyAnswer(string no, int type, bool succ);
        void verifyAnswer(string no, int type, bool succ, _System.Collections.Generic.Dictionary<string, string> context__);
    }

    public interface ILoggerPrx : Ice.ObjectPrx
    {
        void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg);
        void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg, _System.Collections.Generic.Dictionary<string, string> context__);

        void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image);
        void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image, _System.Collections.Generic.Dictionary<string, string> context__);
    }

    public interface ILogServerPrx : gtr.ILoggerPrx, gtr.IServicePrx
    {
    }

    public interface IGameHostPrx : gtr.IQuestionAskerPrx, gtr.IServicePrx, gtr.ILoggerPrx
    {
        gtr.GameTaskletT getTask();
        gtr.GameTaskletT getTask(_System.Collections.Generic.Dictionary<string, string> context__);

        void completeTask(gtr.GameTaskResultT result);
        void completeTask(gtr.GameTaskResultT result, _System.Collections.Generic.Dictionary<string, string> context__);

        string answer(gtr.QuestionContentT question);
        string answer(gtr.QuestionContentT question, _System.Collections.Generic.Dictionary<string, string> context__);

        void verifyAnswer(int type, bool succ);
        void verifyAnswer(int type, bool succ, _System.Collections.Generic.Dictionary<string, string> context__);
    }

    public interface IGtrServerPrx : gtr.IServicePrx, gtr.IQuestionServerPrx
    {
        gtr.GameTaskletT getTask(gtr.GameRobotInfoT robot);
        gtr.GameTaskletT getTask(gtr.GameRobotInfoT robot, _System.Collections.Generic.Dictionary<string, string> context__);

        void completeTask(gtr.GameTaskResultT result);
        void completeTask(gtr.GameTaskResultT result, _System.Collections.Generic.Dictionary<string, string> context__);
    }
}

namespace gtr
{
    public interface IServiceOperations_
    {
        int ice_getType_(Ice.Current current__);

        gtr.ServiceIdentifyT getId(Ice.Current current__);

        int getTimestamp(Ice.Current current__);

        void shutdown(Ice.Current current__);

        void heartbeat(string senderType, string senderId, Ice.Current current__);
    }

    public interface IServiceOperationsNC_
    {
        int ice_getType_();

        gtr.ServiceIdentifyT getId();

        int getTimestamp();

        void shutdown();

        void heartbeat(string senderType, string senderId);
    }

    public interface IAnswerEndpointOperations_ : gtr.IServiceOperations_
    {
        int getRemains(Ice.Current current__);

        int addQuestion(gtr.IQuestionServerPrx server, string no, string createTime, gtr.QuestionContentT question, Ice.Current current__);
    }

    public interface IAnswerEndpointOperationsNC_ : gtr.IServiceOperationsNC_
    {
        int getRemains();

        int addQuestion(gtr.IQuestionServerPrx server, string no, string createTime, gtr.QuestionContentT question);
    }

    public interface IQuestionAskerOperations_
    {
        void answerResult(string no, string result, Ice.Current current__);
    }

    public interface IQuestionAskerOperationsNC_
    {
        void answerResult(string no, string result);
    }

    public interface IQuestionServerOperations_ : gtr.IServiceOperations_
    {
        void answer(gtr.IQuestionAskerPrx asker, string no, gtr.QuestionContentT question, Ice.Current current__);

        void answerResult(string no, gtr.QuestionResultT result, Ice.Current current__);

        gtr.CallReturnT login(gtr.IAnswerEndpointPrx answer, string worker, string passwd, Ice.Current current__);

        void logout(gtr.IAnswerEndpointPrx answer, string worker, Ice.Current current__);

        void verifyAnswer(string no, int type, bool succ, Ice.Current current__);
    }

    public interface IQuestionServerOperationsNC_ : gtr.IServiceOperationsNC_
    {
        void answer(gtr.IQuestionAskerPrx asker, string no, gtr.QuestionContentT question);

        void answerResult(string no, gtr.QuestionResultT result);

        gtr.CallReturnT login(gtr.IAnswerEndpointPrx answer, string worker, string passwd);

        void logout(gtr.IAnswerEndpointPrx answer, string worker);

        void verifyAnswer(string no, int type, bool succ);
    }

    public interface ILoggerOperations_
    {
        void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg, Ice.Current current__);

        void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image, Ice.Current current__);
    }

    public interface ILoggerOperationsNC_
    {
        void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg);

        void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image);
    }

    public interface ILogServerOperations_ : gtr.ILoggerOperations_, gtr.IServiceOperations_
    {
    }

    public interface ILogServerOperationsNC_ : gtr.ILoggerOperationsNC_, gtr.IServiceOperationsNC_
    {
    }

    public interface IGameHostOperations_ : gtr.IQuestionAskerOperations_, gtr.IServiceOperations_, gtr.ILoggerOperations_
    {
        gtr.GameTaskletT getTask(Ice.Current current__);

        void completeTask(gtr.GameTaskResultT result, Ice.Current current__);

        string answer(gtr.QuestionContentT question, Ice.Current current__);

        void verifyAnswer(int type, bool succ, Ice.Current current__);
    }

    public interface IGameHostOperationsNC_ : gtr.IQuestionAskerOperationsNC_, gtr.IServiceOperationsNC_, gtr.ILoggerOperationsNC_
    {
        gtr.GameTaskletT getTask();

        void completeTask(gtr.GameTaskResultT result);

        string answer(gtr.QuestionContentT question);

        void verifyAnswer(int type, bool succ);
    }

    public interface IGtrServerOperations_ : gtr.IServiceOperations_, gtr.IQuestionServerOperations_
    {
        gtr.GameTaskletT getTask(gtr.GameRobotInfoT robot, Ice.Current current__);

        void completeTask(gtr.GameTaskResultT result, Ice.Current current__);
    }

    public interface IGtrServerOperationsNC_ : gtr.IServiceOperationsNC_, gtr.IQuestionServerOperationsNC_
    {
        gtr.GameTaskletT getTask(gtr.GameRobotInfoT robot);

        void completeTask(gtr.GameTaskResultT result);
    }
}

namespace gtr
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

    public sealed class ByteStreamTHelper
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
                    gtr.HashValueSetHelper.write(os__, v__[ix__]);
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
                    v__[ix__] = gtr.HashValueSetHelper.read(is__);
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
                    gtr.StringListTHelper.write(os__, v__[ix__]);
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
                    v__[ix__] = gtr.StringListTHelper.read(is__);
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

        public gtr.ServiceIdentifyT getId()
        {
            return getId(null, false);
        }

        public gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return getId(context__, true);
        }

        private gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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

        public int ice_getType_()
        {
            return ice_getType_(null, false);
        }

        public int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return ice_getType_(context__, true);
        }

        private int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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

        public void heartbeat(string senderType, string senderId)
        {
            heartbeat(senderType, senderId, null, false);
        }

        public void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            heartbeat(senderType, senderId, context__, true);
        }

        private void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IServiceDel_ del__ = (IServiceDel_)delBase__;
                    del__.heartbeat(senderType, senderId, context__);
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

        public void shutdown()
        {
            shutdown(null, false);
        }

        public void shutdown(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            shutdown(context__, true);
        }

        private void shutdown(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IServiceDel_ del__ = (IServiceDel_)delBase__;
                    del__.shutdown(context__);
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

        #endregion

        #region Checked and unchecked cast operations

        public static IServicePrx checkedCast(Ice.ObjectPrx b)
        {
            if(b == null)
            {
                return null;
            }
            IServicePrx r = b as IServicePrx;
            if((r == null) && b.ice_isA("::gtr::IService"))
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
            if((r == null) && b.ice_isA("::gtr::IService", ctx))
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
                if(bb.ice_isA("::gtr::IService"))
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
                if(bb.ice_isA("::gtr::IService", ctx))
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

    public sealed class IAnswerEndpointPrxHelper : Ice.ObjectPrxHelperBase, IAnswerEndpointPrx
    {
        #region Synchronous operations

        public int addQuestion(gtr.IQuestionServerPrx server, string no, string createTime, gtr.QuestionContentT question)
        {
            return addQuestion(server, no, createTime, question, null, false);
        }

        public int addQuestion(gtr.IQuestionServerPrx server, string no, string createTime, gtr.QuestionContentT question, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            return addQuestion(server, no, createTime, question, context__, true);
        }

        private int addQuestion(gtr.IQuestionServerPrx server, string no, string createTime, gtr.QuestionContentT question, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    checkTwowayOnly__("addQuestion");
                    delBase__ = getDelegate__(false);
                    IAnswerEndpointDel_ del__ = (IAnswerEndpointDel_)delBase__;
                    return del__.addQuestion(server, no, createTime, question, context__);
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

        public int getRemains()
        {
            return getRemains(null, false);
        }

        public int getRemains(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return getRemains(context__, true);
        }

        private int getRemains(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    checkTwowayOnly__("getRemains");
                    delBase__ = getDelegate__(false);
                    IAnswerEndpointDel_ del__ = (IAnswerEndpointDel_)delBase__;
                    return del__.getRemains(context__);
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

        public gtr.ServiceIdentifyT getId()
        {
            return getId(null, false);
        }

        public gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return getId(context__, true);
        }

        private gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IAnswerEndpointDel_ del__ = (IAnswerEndpointDel_)delBase__;
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
                    IAnswerEndpointDel_ del__ = (IAnswerEndpointDel_)delBase__;
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

        public int ice_getType_()
        {
            return ice_getType_(null, false);
        }

        public int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return ice_getType_(context__, true);
        }

        private int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IAnswerEndpointDel_ del__ = (IAnswerEndpointDel_)delBase__;
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

        public void heartbeat(string senderType, string senderId)
        {
            heartbeat(senderType, senderId, null, false);
        }

        public void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            heartbeat(senderType, senderId, context__, true);
        }

        private void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IAnswerEndpointDel_ del__ = (IAnswerEndpointDel_)delBase__;
                    del__.heartbeat(senderType, senderId, context__);
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

        public void shutdown()
        {
            shutdown(null, false);
        }

        public void shutdown(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            shutdown(context__, true);
        }

        private void shutdown(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IAnswerEndpointDel_ del__ = (IAnswerEndpointDel_)delBase__;
                    del__.shutdown(context__);
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

        #endregion

        #region Checked and unchecked cast operations

        public static IAnswerEndpointPrx checkedCast(Ice.ObjectPrx b)
        {
            if(b == null)
            {
                return null;
            }
            IAnswerEndpointPrx r = b as IAnswerEndpointPrx;
            if((r == null) && b.ice_isA("::gtr::IAnswerEndpoint"))
            {
                IAnswerEndpointPrxHelper h = new IAnswerEndpointPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IAnswerEndpointPrx checkedCast(Ice.ObjectPrx b, _System.Collections.Generic.Dictionary<string, string> ctx)
        {
            if(b == null)
            {
                return null;
            }
            IAnswerEndpointPrx r = b as IAnswerEndpointPrx;
            if((r == null) && b.ice_isA("::gtr::IAnswerEndpoint", ctx))
            {
                IAnswerEndpointPrxHelper h = new IAnswerEndpointPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IAnswerEndpointPrx checkedCast(Ice.ObjectPrx b, string f)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            try
            {
                if(bb.ice_isA("::gtr::IAnswerEndpoint"))
                {
                    IAnswerEndpointPrxHelper h = new IAnswerEndpointPrxHelper();
                    h.copyFrom__(bb);
                    return h;
                }
            }
            catch(Ice.FacetNotExistException)
            {
            }
            return null;
        }

        public static IAnswerEndpointPrx checkedCast(Ice.ObjectPrx b, string f, _System.Collections.Generic.Dictionary<string, string> ctx)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            try
            {
                if(bb.ice_isA("::gtr::IAnswerEndpoint", ctx))
                {
                    IAnswerEndpointPrxHelper h = new IAnswerEndpointPrxHelper();
                    h.copyFrom__(bb);
                    return h;
                }
            }
            catch(Ice.FacetNotExistException)
            {
            }
            return null;
        }

        public static IAnswerEndpointPrx uncheckedCast(Ice.ObjectPrx b)
        {
            if(b == null)
            {
                return null;
            }
            IAnswerEndpointPrx r = b as IAnswerEndpointPrx;
            if(r == null)
            {
                IAnswerEndpointPrxHelper h = new IAnswerEndpointPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IAnswerEndpointPrx uncheckedCast(Ice.ObjectPrx b, string f)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            IAnswerEndpointPrxHelper h = new IAnswerEndpointPrxHelper();
            h.copyFrom__(bb);
            return h;
        }

        #endregion

        #region Marshaling support

        protected override Ice.ObjectDelM_ createDelegateM__()
        {
            return new IAnswerEndpointDelM_();
        }

        protected override Ice.ObjectDelD_ createDelegateD__()
        {
            return new IAnswerEndpointDelD_();
        }

        public static void write__(IceInternal.BasicStream os__, IAnswerEndpointPrx v__)
        {
            os__.writeProxy(v__);
        }

        public static IAnswerEndpointPrx read__(IceInternal.BasicStream is__)
        {
            Ice.ObjectPrx proxy = is__.readProxy();
            if(proxy != null)
            {
                IAnswerEndpointPrxHelper result = new IAnswerEndpointPrxHelper();
                result.copyFrom__(proxy);
                return result;
            }
            return null;
        }

        #endregion
    }

    public sealed class IQuestionAskerPrxHelper : Ice.ObjectPrxHelperBase, IQuestionAskerPrx
    {
        #region Synchronous operations

        public void answerResult(string no, string result)
        {
            answerResult(no, result, null, false);
        }

        public void answerResult(string no, string result, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            answerResult(no, result, context__, true);
        }

        private void answerResult(string no, string result, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IQuestionAskerDel_ del__ = (IQuestionAskerDel_)delBase__;
                    del__.answerResult(no, result, context__);
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

        #endregion

        #region Checked and unchecked cast operations

        public static IQuestionAskerPrx checkedCast(Ice.ObjectPrx b)
        {
            if(b == null)
            {
                return null;
            }
            IQuestionAskerPrx r = b as IQuestionAskerPrx;
            if((r == null) && b.ice_isA("::gtr::IQuestionAsker"))
            {
                IQuestionAskerPrxHelper h = new IQuestionAskerPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IQuestionAskerPrx checkedCast(Ice.ObjectPrx b, _System.Collections.Generic.Dictionary<string, string> ctx)
        {
            if(b == null)
            {
                return null;
            }
            IQuestionAskerPrx r = b as IQuestionAskerPrx;
            if((r == null) && b.ice_isA("::gtr::IQuestionAsker", ctx))
            {
                IQuestionAskerPrxHelper h = new IQuestionAskerPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IQuestionAskerPrx checkedCast(Ice.ObjectPrx b, string f)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            try
            {
                if(bb.ice_isA("::gtr::IQuestionAsker"))
                {
                    IQuestionAskerPrxHelper h = new IQuestionAskerPrxHelper();
                    h.copyFrom__(bb);
                    return h;
                }
            }
            catch(Ice.FacetNotExistException)
            {
            }
            return null;
        }

        public static IQuestionAskerPrx checkedCast(Ice.ObjectPrx b, string f, _System.Collections.Generic.Dictionary<string, string> ctx)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            try
            {
                if(bb.ice_isA("::gtr::IQuestionAsker", ctx))
                {
                    IQuestionAskerPrxHelper h = new IQuestionAskerPrxHelper();
                    h.copyFrom__(bb);
                    return h;
                }
            }
            catch(Ice.FacetNotExistException)
            {
            }
            return null;
        }

        public static IQuestionAskerPrx uncheckedCast(Ice.ObjectPrx b)
        {
            if(b == null)
            {
                return null;
            }
            IQuestionAskerPrx r = b as IQuestionAskerPrx;
            if(r == null)
            {
                IQuestionAskerPrxHelper h = new IQuestionAskerPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IQuestionAskerPrx uncheckedCast(Ice.ObjectPrx b, string f)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            IQuestionAskerPrxHelper h = new IQuestionAskerPrxHelper();
            h.copyFrom__(bb);
            return h;
        }

        #endregion

        #region Marshaling support

        protected override Ice.ObjectDelM_ createDelegateM__()
        {
            return new IQuestionAskerDelM_();
        }

        protected override Ice.ObjectDelD_ createDelegateD__()
        {
            return new IQuestionAskerDelD_();
        }

        public static void write__(IceInternal.BasicStream os__, IQuestionAskerPrx v__)
        {
            os__.writeProxy(v__);
        }

        public static IQuestionAskerPrx read__(IceInternal.BasicStream is__)
        {
            Ice.ObjectPrx proxy = is__.readProxy();
            if(proxy != null)
            {
                IQuestionAskerPrxHelper result = new IQuestionAskerPrxHelper();
                result.copyFrom__(proxy);
                return result;
            }
            return null;
        }

        #endregion
    }

    public sealed class IQuestionServerPrxHelper : Ice.ObjectPrxHelperBase, IQuestionServerPrx
    {
        #region Synchronous operations

        public void answer(gtr.IQuestionAskerPrx asker, string no, gtr.QuestionContentT question)
        {
            answer(asker, no, question, null, false);
        }

        public void answer(gtr.IQuestionAskerPrx asker, string no, gtr.QuestionContentT question, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            answer(asker, no, question, context__, true);
        }

        private void answer(gtr.IQuestionAskerPrx asker, string no, gtr.QuestionContentT question, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IQuestionServerDel_ del__ = (IQuestionServerDel_)delBase__;
                    del__.answer(asker, no, question, context__);
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

        public void answerResult(string no, gtr.QuestionResultT result)
        {
            answerResult(no, result, null, false);
        }

        public void answerResult(string no, gtr.QuestionResultT result, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            answerResult(no, result, context__, true);
        }

        private void answerResult(string no, gtr.QuestionResultT result, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IQuestionServerDel_ del__ = (IQuestionServerDel_)delBase__;
                    del__.answerResult(no, result, context__);
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

        public gtr.CallReturnT login(gtr.IAnswerEndpointPrx answer, string worker, string passwd)
        {
            return login(answer, worker, passwd, null, false);
        }

        public gtr.CallReturnT login(gtr.IAnswerEndpointPrx answer, string worker, string passwd, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            return login(answer, worker, passwd, context__, true);
        }

        private gtr.CallReturnT login(gtr.IAnswerEndpointPrx answer, string worker, string passwd, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    checkTwowayOnly__("login");
                    delBase__ = getDelegate__(false);
                    IQuestionServerDel_ del__ = (IQuestionServerDel_)delBase__;
                    return del__.login(answer, worker, passwd, context__);
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

        public void logout(gtr.IAnswerEndpointPrx answer, string worker)
        {
            logout(answer, worker, null, false);
        }

        public void logout(gtr.IAnswerEndpointPrx answer, string worker, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            logout(answer, worker, context__, true);
        }

        private void logout(gtr.IAnswerEndpointPrx answer, string worker, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IQuestionServerDel_ del__ = (IQuestionServerDel_)delBase__;
                    del__.logout(answer, worker, context__);
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

        public void verifyAnswer(string no, int type, bool succ)
        {
            verifyAnswer(no, type, succ, null, false);
        }

        public void verifyAnswer(string no, int type, bool succ, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            verifyAnswer(no, type, succ, context__, true);
        }

        private void verifyAnswer(string no, int type, bool succ, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IQuestionServerDel_ del__ = (IQuestionServerDel_)delBase__;
                    del__.verifyAnswer(no, type, succ, context__);
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

        public gtr.ServiceIdentifyT getId()
        {
            return getId(null, false);
        }

        public gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return getId(context__, true);
        }

        private gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IQuestionServerDel_ del__ = (IQuestionServerDel_)delBase__;
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
                    IQuestionServerDel_ del__ = (IQuestionServerDel_)delBase__;
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

        public int ice_getType_()
        {
            return ice_getType_(null, false);
        }

        public int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return ice_getType_(context__, true);
        }

        private int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IQuestionServerDel_ del__ = (IQuestionServerDel_)delBase__;
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

        public void heartbeat(string senderType, string senderId)
        {
            heartbeat(senderType, senderId, null, false);
        }

        public void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            heartbeat(senderType, senderId, context__, true);
        }

        private void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IQuestionServerDel_ del__ = (IQuestionServerDel_)delBase__;
                    del__.heartbeat(senderType, senderId, context__);
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

        public void shutdown()
        {
            shutdown(null, false);
        }

        public void shutdown(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            shutdown(context__, true);
        }

        private void shutdown(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IQuestionServerDel_ del__ = (IQuestionServerDel_)delBase__;
                    del__.shutdown(context__);
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

        #endregion

        #region Checked and unchecked cast operations

        public static IQuestionServerPrx checkedCast(Ice.ObjectPrx b)
        {
            if(b == null)
            {
                return null;
            }
            IQuestionServerPrx r = b as IQuestionServerPrx;
            if((r == null) && b.ice_isA("::gtr::IQuestionServer"))
            {
                IQuestionServerPrxHelper h = new IQuestionServerPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IQuestionServerPrx checkedCast(Ice.ObjectPrx b, _System.Collections.Generic.Dictionary<string, string> ctx)
        {
            if(b == null)
            {
                return null;
            }
            IQuestionServerPrx r = b as IQuestionServerPrx;
            if((r == null) && b.ice_isA("::gtr::IQuestionServer", ctx))
            {
                IQuestionServerPrxHelper h = new IQuestionServerPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IQuestionServerPrx checkedCast(Ice.ObjectPrx b, string f)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            try
            {
                if(bb.ice_isA("::gtr::IQuestionServer"))
                {
                    IQuestionServerPrxHelper h = new IQuestionServerPrxHelper();
                    h.copyFrom__(bb);
                    return h;
                }
            }
            catch(Ice.FacetNotExistException)
            {
            }
            return null;
        }

        public static IQuestionServerPrx checkedCast(Ice.ObjectPrx b, string f, _System.Collections.Generic.Dictionary<string, string> ctx)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            try
            {
                if(bb.ice_isA("::gtr::IQuestionServer", ctx))
                {
                    IQuestionServerPrxHelper h = new IQuestionServerPrxHelper();
                    h.copyFrom__(bb);
                    return h;
                }
            }
            catch(Ice.FacetNotExistException)
            {
            }
            return null;
        }

        public static IQuestionServerPrx uncheckedCast(Ice.ObjectPrx b)
        {
            if(b == null)
            {
                return null;
            }
            IQuestionServerPrx r = b as IQuestionServerPrx;
            if(r == null)
            {
                IQuestionServerPrxHelper h = new IQuestionServerPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IQuestionServerPrx uncheckedCast(Ice.ObjectPrx b, string f)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            IQuestionServerPrxHelper h = new IQuestionServerPrxHelper();
            h.copyFrom__(bb);
            return h;
        }

        #endregion

        #region Marshaling support

        protected override Ice.ObjectDelM_ createDelegateM__()
        {
            return new IQuestionServerDelM_();
        }

        protected override Ice.ObjectDelD_ createDelegateD__()
        {
            return new IQuestionServerDelD_();
        }

        public static void write__(IceInternal.BasicStream os__, IQuestionServerPrx v__)
        {
            os__.writeProxy(v__);
        }

        public static IQuestionServerPrx read__(IceInternal.BasicStream is__)
        {
            Ice.ObjectPrx proxy = is__.readProxy();
            if(proxy != null)
            {
                IQuestionServerPrxHelper result = new IQuestionServerPrxHelper();
                result.copyFrom__(proxy);
                return result;
            }
            return null;
        }

        #endregion
    }

    public sealed class ILoggerPrxHelper : Ice.ObjectPrxHelperBase, ILoggerPrx
    {
        #region Synchronous operations

        public void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image)
        {
            gameImage(gameId, timetick, opName, image, null, false);
        }

        public void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            gameImage(gameId, timetick, opName, image, context__, true);
        }

        private void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    ILoggerDel_ del__ = (ILoggerDel_)delBase__;
                    del__.gameImage(gameId, timetick, opName, image, context__);
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

        public void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg)
        {
            gameMsg(gameId, timetick, msg, null, false);
        }

        public void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            gameMsg(gameId, timetick, msg, context__, true);
        }

        private void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    ILoggerDel_ del__ = (ILoggerDel_)delBase__;
                    del__.gameMsg(gameId, timetick, msg, context__);
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

        #endregion

        #region Checked and unchecked cast operations

        public static ILoggerPrx checkedCast(Ice.ObjectPrx b)
        {
            if(b == null)
            {
                return null;
            }
            ILoggerPrx r = b as ILoggerPrx;
            if((r == null) && b.ice_isA("::gtr::ILogger"))
            {
                ILoggerPrxHelper h = new ILoggerPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static ILoggerPrx checkedCast(Ice.ObjectPrx b, _System.Collections.Generic.Dictionary<string, string> ctx)
        {
            if(b == null)
            {
                return null;
            }
            ILoggerPrx r = b as ILoggerPrx;
            if((r == null) && b.ice_isA("::gtr::ILogger", ctx))
            {
                ILoggerPrxHelper h = new ILoggerPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static ILoggerPrx checkedCast(Ice.ObjectPrx b, string f)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            try
            {
                if(bb.ice_isA("::gtr::ILogger"))
                {
                    ILoggerPrxHelper h = new ILoggerPrxHelper();
                    h.copyFrom__(bb);
                    return h;
                }
            }
            catch(Ice.FacetNotExistException)
            {
            }
            return null;
        }

        public static ILoggerPrx checkedCast(Ice.ObjectPrx b, string f, _System.Collections.Generic.Dictionary<string, string> ctx)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            try
            {
                if(bb.ice_isA("::gtr::ILogger", ctx))
                {
                    ILoggerPrxHelper h = new ILoggerPrxHelper();
                    h.copyFrom__(bb);
                    return h;
                }
            }
            catch(Ice.FacetNotExistException)
            {
            }
            return null;
        }

        public static ILoggerPrx uncheckedCast(Ice.ObjectPrx b)
        {
            if(b == null)
            {
                return null;
            }
            ILoggerPrx r = b as ILoggerPrx;
            if(r == null)
            {
                ILoggerPrxHelper h = new ILoggerPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static ILoggerPrx uncheckedCast(Ice.ObjectPrx b, string f)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            ILoggerPrxHelper h = new ILoggerPrxHelper();
            h.copyFrom__(bb);
            return h;
        }

        #endregion

        #region Marshaling support

        protected override Ice.ObjectDelM_ createDelegateM__()
        {
            return new ILoggerDelM_();
        }

        protected override Ice.ObjectDelD_ createDelegateD__()
        {
            return new ILoggerDelD_();
        }

        public static void write__(IceInternal.BasicStream os__, ILoggerPrx v__)
        {
            os__.writeProxy(v__);
        }

        public static ILoggerPrx read__(IceInternal.BasicStream is__)
        {
            Ice.ObjectPrx proxy = is__.readProxy();
            if(proxy != null)
            {
                ILoggerPrxHelper result = new ILoggerPrxHelper();
                result.copyFrom__(proxy);
                return result;
            }
            return null;
        }

        #endregion
    }

    public sealed class ILogServerPrxHelper : Ice.ObjectPrxHelperBase, ILogServerPrx
    {
        #region Synchronous operations

        public void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image)
        {
            gameImage(gameId, timetick, opName, image, null, false);
        }

        public void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            gameImage(gameId, timetick, opName, image, context__, true);
        }

        private void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    ILogServerDel_ del__ = (ILogServerDel_)delBase__;
                    del__.gameImage(gameId, timetick, opName, image, context__);
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

        public void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg)
        {
            gameMsg(gameId, timetick, msg, null, false);
        }

        public void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            gameMsg(gameId, timetick, msg, context__, true);
        }

        private void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    ILogServerDel_ del__ = (ILogServerDel_)delBase__;
                    del__.gameMsg(gameId, timetick, msg, context__);
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

        public gtr.ServiceIdentifyT getId()
        {
            return getId(null, false);
        }

        public gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return getId(context__, true);
        }

        private gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    ILogServerDel_ del__ = (ILogServerDel_)delBase__;
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
                    ILogServerDel_ del__ = (ILogServerDel_)delBase__;
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

        public int ice_getType_()
        {
            return ice_getType_(null, false);
        }

        public int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return ice_getType_(context__, true);
        }

        private int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    ILogServerDel_ del__ = (ILogServerDel_)delBase__;
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

        public void heartbeat(string senderType, string senderId)
        {
            heartbeat(senderType, senderId, null, false);
        }

        public void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            heartbeat(senderType, senderId, context__, true);
        }

        private void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    ILogServerDel_ del__ = (ILogServerDel_)delBase__;
                    del__.heartbeat(senderType, senderId, context__);
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

        public void shutdown()
        {
            shutdown(null, false);
        }

        public void shutdown(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            shutdown(context__, true);
        }

        private void shutdown(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    ILogServerDel_ del__ = (ILogServerDel_)delBase__;
                    del__.shutdown(context__);
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

        #endregion

        #region Checked and unchecked cast operations

        public static ILogServerPrx checkedCast(Ice.ObjectPrx b)
        {
            if(b == null)
            {
                return null;
            }
            ILogServerPrx r = b as ILogServerPrx;
            if((r == null) && b.ice_isA("::gtr::ILogServer"))
            {
                ILogServerPrxHelper h = new ILogServerPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static ILogServerPrx checkedCast(Ice.ObjectPrx b, _System.Collections.Generic.Dictionary<string, string> ctx)
        {
            if(b == null)
            {
                return null;
            }
            ILogServerPrx r = b as ILogServerPrx;
            if((r == null) && b.ice_isA("::gtr::ILogServer", ctx))
            {
                ILogServerPrxHelper h = new ILogServerPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static ILogServerPrx checkedCast(Ice.ObjectPrx b, string f)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            try
            {
                if(bb.ice_isA("::gtr::ILogServer"))
                {
                    ILogServerPrxHelper h = new ILogServerPrxHelper();
                    h.copyFrom__(bb);
                    return h;
                }
            }
            catch(Ice.FacetNotExistException)
            {
            }
            return null;
        }

        public static ILogServerPrx checkedCast(Ice.ObjectPrx b, string f, _System.Collections.Generic.Dictionary<string, string> ctx)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            try
            {
                if(bb.ice_isA("::gtr::ILogServer", ctx))
                {
                    ILogServerPrxHelper h = new ILogServerPrxHelper();
                    h.copyFrom__(bb);
                    return h;
                }
            }
            catch(Ice.FacetNotExistException)
            {
            }
            return null;
        }

        public static ILogServerPrx uncheckedCast(Ice.ObjectPrx b)
        {
            if(b == null)
            {
                return null;
            }
            ILogServerPrx r = b as ILogServerPrx;
            if(r == null)
            {
                ILogServerPrxHelper h = new ILogServerPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static ILogServerPrx uncheckedCast(Ice.ObjectPrx b, string f)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            ILogServerPrxHelper h = new ILogServerPrxHelper();
            h.copyFrom__(bb);
            return h;
        }

        #endregion

        #region Marshaling support

        protected override Ice.ObjectDelM_ createDelegateM__()
        {
            return new ILogServerDelM_();
        }

        protected override Ice.ObjectDelD_ createDelegateD__()
        {
            return new ILogServerDelD_();
        }

        public static void write__(IceInternal.BasicStream os__, ILogServerPrx v__)
        {
            os__.writeProxy(v__);
        }

        public static ILogServerPrx read__(IceInternal.BasicStream is__)
        {
            Ice.ObjectPrx proxy = is__.readProxy();
            if(proxy != null)
            {
                ILogServerPrxHelper result = new ILogServerPrxHelper();
                result.copyFrom__(proxy);
                return result;
            }
            return null;
        }

        #endregion
    }

    public sealed class IGameHostPrxHelper : Ice.ObjectPrxHelperBase, IGameHostPrx
    {
        #region Synchronous operations

        public string answer(gtr.QuestionContentT question)
        {
            return answer(question, null, false);
        }

        public string answer(gtr.QuestionContentT question, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            return answer(question, context__, true);
        }

        private string answer(gtr.QuestionContentT question, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    checkTwowayOnly__("answer");
                    delBase__ = getDelegate__(false);
                    IGameHostDel_ del__ = (IGameHostDel_)delBase__;
                    return del__.answer(question, context__);
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

        public void completeTask(gtr.GameTaskResultT result)
        {
            completeTask(result, null, false);
        }

        public void completeTask(gtr.GameTaskResultT result, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            completeTask(result, context__, true);
        }

        private void completeTask(gtr.GameTaskResultT result, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IGameHostDel_ del__ = (IGameHostDel_)delBase__;
                    del__.completeTask(result, context__);
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

        public gtr.GameTaskletT getTask()
        {
            return getTask(null, false);
        }

        public gtr.GameTaskletT getTask(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return getTask(context__, true);
        }

        private gtr.GameTaskletT getTask(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    checkTwowayOnly__("getTask");
                    delBase__ = getDelegate__(false);
                    IGameHostDel_ del__ = (IGameHostDel_)delBase__;
                    return del__.getTask(context__);
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

        public void verifyAnswer(int type, bool succ)
        {
            verifyAnswer(type, succ, null, false);
        }

        public void verifyAnswer(int type, bool succ, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            verifyAnswer(type, succ, context__, true);
        }

        private void verifyAnswer(int type, bool succ, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IGameHostDel_ del__ = (IGameHostDel_)delBase__;
                    del__.verifyAnswer(type, succ, context__);
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

        public void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image)
        {
            gameImage(gameId, timetick, opName, image, null, false);
        }

        public void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            gameImage(gameId, timetick, opName, image, context__, true);
        }

        private void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IGameHostDel_ del__ = (IGameHostDel_)delBase__;
                    del__.gameImage(gameId, timetick, opName, image, context__);
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

        public void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg)
        {
            gameMsg(gameId, timetick, msg, null, false);
        }

        public void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            gameMsg(gameId, timetick, msg, context__, true);
        }

        private void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IGameHostDel_ del__ = (IGameHostDel_)delBase__;
                    del__.gameMsg(gameId, timetick, msg, context__);
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

        public void answerResult(string no, string result)
        {
            answerResult(no, result, null, false);
        }

        public void answerResult(string no, string result, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            answerResult(no, result, context__, true);
        }

        private void answerResult(string no, string result, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IGameHostDel_ del__ = (IGameHostDel_)delBase__;
                    del__.answerResult(no, result, context__);
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

        public gtr.ServiceIdentifyT getId()
        {
            return getId(null, false);
        }

        public gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return getId(context__, true);
        }

        private gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IGameHostDel_ del__ = (IGameHostDel_)delBase__;
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
                    IGameHostDel_ del__ = (IGameHostDel_)delBase__;
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

        public int ice_getType_()
        {
            return ice_getType_(null, false);
        }

        public int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return ice_getType_(context__, true);
        }

        private int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IGameHostDel_ del__ = (IGameHostDel_)delBase__;
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

        public void heartbeat(string senderType, string senderId)
        {
            heartbeat(senderType, senderId, null, false);
        }

        public void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            heartbeat(senderType, senderId, context__, true);
        }

        private void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IGameHostDel_ del__ = (IGameHostDel_)delBase__;
                    del__.heartbeat(senderType, senderId, context__);
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

        public void shutdown()
        {
            shutdown(null, false);
        }

        public void shutdown(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            shutdown(context__, true);
        }

        private void shutdown(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IGameHostDel_ del__ = (IGameHostDel_)delBase__;
                    del__.shutdown(context__);
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

        #endregion

        #region Checked and unchecked cast operations

        public static IGameHostPrx checkedCast(Ice.ObjectPrx b)
        {
            if(b == null)
            {
                return null;
            }
            IGameHostPrx r = b as IGameHostPrx;
            if((r == null) && b.ice_isA("::gtr::IGameHost"))
            {
                IGameHostPrxHelper h = new IGameHostPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IGameHostPrx checkedCast(Ice.ObjectPrx b, _System.Collections.Generic.Dictionary<string, string> ctx)
        {
            if(b == null)
            {
                return null;
            }
            IGameHostPrx r = b as IGameHostPrx;
            if((r == null) && b.ice_isA("::gtr::IGameHost", ctx))
            {
                IGameHostPrxHelper h = new IGameHostPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IGameHostPrx checkedCast(Ice.ObjectPrx b, string f)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            try
            {
                if(bb.ice_isA("::gtr::IGameHost"))
                {
                    IGameHostPrxHelper h = new IGameHostPrxHelper();
                    h.copyFrom__(bb);
                    return h;
                }
            }
            catch(Ice.FacetNotExistException)
            {
            }
            return null;
        }

        public static IGameHostPrx checkedCast(Ice.ObjectPrx b, string f, _System.Collections.Generic.Dictionary<string, string> ctx)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            try
            {
                if(bb.ice_isA("::gtr::IGameHost", ctx))
                {
                    IGameHostPrxHelper h = new IGameHostPrxHelper();
                    h.copyFrom__(bb);
                    return h;
                }
            }
            catch(Ice.FacetNotExistException)
            {
            }
            return null;
        }

        public static IGameHostPrx uncheckedCast(Ice.ObjectPrx b)
        {
            if(b == null)
            {
                return null;
            }
            IGameHostPrx r = b as IGameHostPrx;
            if(r == null)
            {
                IGameHostPrxHelper h = new IGameHostPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IGameHostPrx uncheckedCast(Ice.ObjectPrx b, string f)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            IGameHostPrxHelper h = new IGameHostPrxHelper();
            h.copyFrom__(bb);
            return h;
        }

        #endregion

        #region Marshaling support

        protected override Ice.ObjectDelM_ createDelegateM__()
        {
            return new IGameHostDelM_();
        }

        protected override Ice.ObjectDelD_ createDelegateD__()
        {
            return new IGameHostDelD_();
        }

        public static void write__(IceInternal.BasicStream os__, IGameHostPrx v__)
        {
            os__.writeProxy(v__);
        }

        public static IGameHostPrx read__(IceInternal.BasicStream is__)
        {
            Ice.ObjectPrx proxy = is__.readProxy();
            if(proxy != null)
            {
                IGameHostPrxHelper result = new IGameHostPrxHelper();
                result.copyFrom__(proxy);
                return result;
            }
            return null;
        }

        #endregion
    }

    public sealed class GameInfoListTHelper
    {
        public static void write(IceInternal.BasicStream os__, gtr.GameInfoT[] v__)
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
                    (v__[ix__] == null ? new gtr.GameInfoT() : v__[ix__]).write__(os__);
                }
            }
        }

        public static gtr.GameInfoT[] read(IceInternal.BasicStream is__)
        {
            gtr.GameInfoT[] v__;
            {
                int szx__ = is__.readSize();
                is__.startSeq(szx__, 10);
                v__ = new gtr.GameInfoT[szx__];
                for(int ix__ = 0; ix__ < szx__; ++ix__)
                {
                    v__[ix__] = new gtr.GameInfoT();
                    v__[ix__].read__(is__);
                    is__.checkSeq();
                    is__.endElement();
                }
                is__.endSeq(szx__);
            }
            return v__;
        }
    }

    public sealed class IGtrServerPrxHelper : Ice.ObjectPrxHelperBase, IGtrServerPrx
    {
        #region Synchronous operations

        public void completeTask(gtr.GameTaskResultT result)
        {
            completeTask(result, null, false);
        }

        public void completeTask(gtr.GameTaskResultT result, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            completeTask(result, context__, true);
        }

        private void completeTask(gtr.GameTaskResultT result, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IGtrServerDel_ del__ = (IGtrServerDel_)delBase__;
                    del__.completeTask(result, context__);
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

        public gtr.GameTaskletT getTask(gtr.GameRobotInfoT robot)
        {
            return getTask(robot, null, false);
        }

        public gtr.GameTaskletT getTask(gtr.GameRobotInfoT robot, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            return getTask(robot, context__, true);
        }

        private gtr.GameTaskletT getTask(gtr.GameRobotInfoT robot, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    checkTwowayOnly__("getTask");
                    delBase__ = getDelegate__(false);
                    IGtrServerDel_ del__ = (IGtrServerDel_)delBase__;
                    return del__.getTask(robot, context__);
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

        public void answer(gtr.IQuestionAskerPrx asker, string no, gtr.QuestionContentT question)
        {
            answer(asker, no, question, null, false);
        }

        public void answer(gtr.IQuestionAskerPrx asker, string no, gtr.QuestionContentT question, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            answer(asker, no, question, context__, true);
        }

        private void answer(gtr.IQuestionAskerPrx asker, string no, gtr.QuestionContentT question, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IGtrServerDel_ del__ = (IGtrServerDel_)delBase__;
                    del__.answer(asker, no, question, context__);
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

        public void answerResult(string no, gtr.QuestionResultT result)
        {
            answerResult(no, result, null, false);
        }

        public void answerResult(string no, gtr.QuestionResultT result, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            answerResult(no, result, context__, true);
        }

        private void answerResult(string no, gtr.QuestionResultT result, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IGtrServerDel_ del__ = (IGtrServerDel_)delBase__;
                    del__.answerResult(no, result, context__);
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

        public gtr.CallReturnT login(gtr.IAnswerEndpointPrx answer, string worker, string passwd)
        {
            return login(answer, worker, passwd, null, false);
        }

        public gtr.CallReturnT login(gtr.IAnswerEndpointPrx answer, string worker, string passwd, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            return login(answer, worker, passwd, context__, true);
        }

        private gtr.CallReturnT login(gtr.IAnswerEndpointPrx answer, string worker, string passwd, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    checkTwowayOnly__("login");
                    delBase__ = getDelegate__(false);
                    IGtrServerDel_ del__ = (IGtrServerDel_)delBase__;
                    return del__.login(answer, worker, passwd, context__);
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

        public void logout(gtr.IAnswerEndpointPrx answer, string worker)
        {
            logout(answer, worker, null, false);
        }

        public void logout(gtr.IAnswerEndpointPrx answer, string worker, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            logout(answer, worker, context__, true);
        }

        private void logout(gtr.IAnswerEndpointPrx answer, string worker, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IGtrServerDel_ del__ = (IGtrServerDel_)delBase__;
                    del__.logout(answer, worker, context__);
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

        public void verifyAnswer(string no, int type, bool succ)
        {
            verifyAnswer(no, type, succ, null, false);
        }

        public void verifyAnswer(string no, int type, bool succ, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            verifyAnswer(no, type, succ, context__, true);
        }

        private void verifyAnswer(string no, int type, bool succ, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IGtrServerDel_ del__ = (IGtrServerDel_)delBase__;
                    del__.verifyAnswer(no, type, succ, context__);
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

        public gtr.ServiceIdentifyT getId()
        {
            return getId(null, false);
        }

        public gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return getId(context__, true);
        }

        private gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IGtrServerDel_ del__ = (IGtrServerDel_)delBase__;
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
                    IGtrServerDel_ del__ = (IGtrServerDel_)delBase__;
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

        public int ice_getType_()
        {
            return ice_getType_(null, false);
        }

        public int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            return ice_getType_(context__, true);
        }

        private int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IGtrServerDel_ del__ = (IGtrServerDel_)delBase__;
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

        public void heartbeat(string senderType, string senderId)
        {
            heartbeat(senderType, senderId, null, false);
        }

        public void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            heartbeat(senderType, senderId, context__, true);
        }

        private void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IGtrServerDel_ del__ = (IGtrServerDel_)delBase__;
                    del__.heartbeat(senderType, senderId, context__);
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

        public void shutdown()
        {
            shutdown(null, false);
        }

        public void shutdown(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            shutdown(context__, true);
        }

        private void shutdown(_System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
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
                    IGtrServerDel_ del__ = (IGtrServerDel_)delBase__;
                    del__.shutdown(context__);
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

        #endregion

        #region Checked and unchecked cast operations

        public static IGtrServerPrx checkedCast(Ice.ObjectPrx b)
        {
            if(b == null)
            {
                return null;
            }
            IGtrServerPrx r = b as IGtrServerPrx;
            if((r == null) && b.ice_isA("::gtr::IGtrServer"))
            {
                IGtrServerPrxHelper h = new IGtrServerPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IGtrServerPrx checkedCast(Ice.ObjectPrx b, _System.Collections.Generic.Dictionary<string, string> ctx)
        {
            if(b == null)
            {
                return null;
            }
            IGtrServerPrx r = b as IGtrServerPrx;
            if((r == null) && b.ice_isA("::gtr::IGtrServer", ctx))
            {
                IGtrServerPrxHelper h = new IGtrServerPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IGtrServerPrx checkedCast(Ice.ObjectPrx b, string f)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            try
            {
                if(bb.ice_isA("::gtr::IGtrServer"))
                {
                    IGtrServerPrxHelper h = new IGtrServerPrxHelper();
                    h.copyFrom__(bb);
                    return h;
                }
            }
            catch(Ice.FacetNotExistException)
            {
            }
            return null;
        }

        public static IGtrServerPrx checkedCast(Ice.ObjectPrx b, string f, _System.Collections.Generic.Dictionary<string, string> ctx)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            try
            {
                if(bb.ice_isA("::gtr::IGtrServer", ctx))
                {
                    IGtrServerPrxHelper h = new IGtrServerPrxHelper();
                    h.copyFrom__(bb);
                    return h;
                }
            }
            catch(Ice.FacetNotExistException)
            {
            }
            return null;
        }

        public static IGtrServerPrx uncheckedCast(Ice.ObjectPrx b)
        {
            if(b == null)
            {
                return null;
            }
            IGtrServerPrx r = b as IGtrServerPrx;
            if(r == null)
            {
                IGtrServerPrxHelper h = new IGtrServerPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static IGtrServerPrx uncheckedCast(Ice.ObjectPrx b, string f)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            IGtrServerPrxHelper h = new IGtrServerPrxHelper();
            h.copyFrom__(bb);
            return h;
        }

        #endregion

        #region Marshaling support

        protected override Ice.ObjectDelM_ createDelegateM__()
        {
            return new IGtrServerDelM_();
        }

        protected override Ice.ObjectDelD_ createDelegateD__()
        {
            return new IGtrServerDelD_();
        }

        public static void write__(IceInternal.BasicStream os__, IGtrServerPrx v__)
        {
            os__.writeProxy(v__);
        }

        public static IGtrServerPrx read__(IceInternal.BasicStream is__)
        {
            Ice.ObjectPrx proxy = is__.readProxy();
            if(proxy != null)
            {
                IGtrServerPrxHelper result = new IGtrServerPrxHelper();
                result.copyFrom__(proxy);
                return result;
            }
            return null;
        }

        #endregion
    }
}

namespace gtr
{
    public interface IServiceDel_ : Ice.ObjectDel_
    {
        int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__);

        gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__);

        int getTimestamp(_System.Collections.Generic.Dictionary<string, string> context__);

        void shutdown(_System.Collections.Generic.Dictionary<string, string> context__);

        void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__);
    }

    public interface IAnswerEndpointDel_ : gtr.IServiceDel_
    {
        int getRemains(_System.Collections.Generic.Dictionary<string, string> context__);

        int addQuestion(gtr.IQuestionServerPrx server, string no, string createTime, gtr.QuestionContentT question, _System.Collections.Generic.Dictionary<string, string> context__);
    }

    public interface IQuestionAskerDel_ : Ice.ObjectDel_
    {
        void answerResult(string no, string result, _System.Collections.Generic.Dictionary<string, string> context__);
    }

    public interface IQuestionServerDel_ : gtr.IServiceDel_
    {
        void answer(gtr.IQuestionAskerPrx asker, string no, gtr.QuestionContentT question, _System.Collections.Generic.Dictionary<string, string> context__);

        void answerResult(string no, gtr.QuestionResultT result, _System.Collections.Generic.Dictionary<string, string> context__);

        gtr.CallReturnT login(gtr.IAnswerEndpointPrx answer, string worker, string passwd, _System.Collections.Generic.Dictionary<string, string> context__);

        void logout(gtr.IAnswerEndpointPrx answer, string worker, _System.Collections.Generic.Dictionary<string, string> context__);

        void verifyAnswer(string no, int type, bool succ, _System.Collections.Generic.Dictionary<string, string> context__);
    }

    public interface ILoggerDel_ : Ice.ObjectDel_
    {
        void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg, _System.Collections.Generic.Dictionary<string, string> context__);

        void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image, _System.Collections.Generic.Dictionary<string, string> context__);
    }

    public interface ILogServerDel_ : gtr.ILoggerDel_, gtr.IServiceDel_
    {
    }

    public interface IGameHostDel_ : gtr.IQuestionAskerDel_, gtr.IServiceDel_, gtr.ILoggerDel_
    {
        gtr.GameTaskletT getTask(_System.Collections.Generic.Dictionary<string, string> context__);

        void completeTask(gtr.GameTaskResultT result, _System.Collections.Generic.Dictionary<string, string> context__);

        string answer(gtr.QuestionContentT question, _System.Collections.Generic.Dictionary<string, string> context__);

        void verifyAnswer(int type, bool succ, _System.Collections.Generic.Dictionary<string, string> context__);
    }

    public interface IGtrServerDel_ : gtr.IServiceDel_, gtr.IQuestionServerDel_
    {
        gtr.GameTaskletT getTask(gtr.GameRobotInfoT robot, _System.Collections.Generic.Dictionary<string, string> context__);

        void completeTask(gtr.GameTaskResultT result, _System.Collections.Generic.Dictionary<string, string> context__);
    }
}

namespace gtr
{
    public sealed class IServiceDelM_ : Ice.ObjectDelM_, IServiceDel_
    {
        public gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__)
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
                    gtr.ServiceIdentifyT ret__;
                    ret__ = null;
                    if(ret__ == null)
                    {
                        ret__ = new gtr.ServiceIdentifyT();
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

        public int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
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

        public void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("heartbeat", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    os__.writeString(senderType);
                    os__.writeString(senderId);
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

        public void shutdown(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("shutdown", Ice.OperationMode.Normal, context__);
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
    }

    public sealed class IAnswerEndpointDelM_ : Ice.ObjectDelM_, IAnswerEndpointDel_
    {
        public int addQuestion(gtr.IQuestionServerPrx server, string no, string createTime, gtr.QuestionContentT question, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("addQuestion", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    gtr.IQuestionServerPrxHelper.write__(os__, server);
                    os__.writeString(no);
                    os__.writeString(createTime);
                    if(question == null)
                    {
                        gtr.QuestionContentT tmp__ = new gtr.QuestionContentT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        question.write__(os__);
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

        public int getRemains(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("getRemains", Ice.OperationMode.Normal, context__);
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

        public gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__)
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
                    gtr.ServiceIdentifyT ret__;
                    ret__ = null;
                    if(ret__ == null)
                    {
                        ret__ = new gtr.ServiceIdentifyT();
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

        public int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
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

        public void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("heartbeat", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    os__.writeString(senderType);
                    os__.writeString(senderId);
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

        public void shutdown(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("shutdown", Ice.OperationMode.Normal, context__);
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
    }

    public sealed class IQuestionAskerDelM_ : Ice.ObjectDelM_, IQuestionAskerDel_
    {
        public void answerResult(string no, string result, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("answerResult", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    os__.writeString(no);
                    os__.writeString(result);
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
    }

    public sealed class IQuestionServerDelM_ : Ice.ObjectDelM_, IQuestionServerDel_
    {
        public void answer(gtr.IQuestionAskerPrx asker, string no, gtr.QuestionContentT question, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("answer", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    gtr.IQuestionAskerPrxHelper.write__(os__, asker);
                    os__.writeString(no);
                    if(question == null)
                    {
                        gtr.QuestionContentT tmp__ = new gtr.QuestionContentT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        question.write__(os__);
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

        public void answerResult(string no, gtr.QuestionResultT result, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("answerResult", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    os__.writeString(no);
                    if(result == null)
                    {
                        gtr.QuestionResultT tmp__ = new gtr.QuestionResultT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        result.write__(os__);
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

        public gtr.CallReturnT login(gtr.IAnswerEndpointPrx answer, string worker, string passwd, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("login", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    gtr.IAnswerEndpointPrxHelper.write__(os__, answer);
                    os__.writeString(worker);
                    os__.writeString(passwd);
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
                    gtr.CallReturnT ret__;
                    ret__ = null;
                    if(ret__ == null)
                    {
                        ret__ = new gtr.CallReturnT();
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

        public void logout(gtr.IAnswerEndpointPrx answer, string worker, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("logout", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    gtr.IAnswerEndpointPrxHelper.write__(os__, answer);
                    os__.writeString(worker);
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

        public void verifyAnswer(string no, int type, bool succ, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("verifyAnswer", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    os__.writeString(no);
                    os__.writeInt(type);
                    os__.writeBool(succ);
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

        public gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__)
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
                    gtr.ServiceIdentifyT ret__;
                    ret__ = null;
                    if(ret__ == null)
                    {
                        ret__ = new gtr.ServiceIdentifyT();
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

        public int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
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

        public void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("heartbeat", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    os__.writeString(senderType);
                    os__.writeString(senderId);
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

        public void shutdown(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("shutdown", Ice.OperationMode.Normal, context__);
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
    }

    public sealed class ILoggerDelM_ : Ice.ObjectDelM_, ILoggerDel_
    {
        public void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("gameImage", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    if(gameId == null)
                    {
                        gtr.GameIdentifyT tmp__ = new gtr.GameIdentifyT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        gameId.write__(os__);
                    }
                    os__.writeInt(timetick);
                    os__.writeString(opName);
                    if(image == null)
                    {
                        gtr.ImageDataT tmp__ = new gtr.ImageDataT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        image.write__(os__);
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

        public void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("gameMsg", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    if(gameId == null)
                    {
                        gtr.GameIdentifyT tmp__ = new gtr.GameIdentifyT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        gameId.write__(os__);
                    }
                    os__.writeInt(timetick);
                    if(msg == null)
                    {
                        gtr.LogMessageT tmp__ = new gtr.LogMessageT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        msg.write__(os__);
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
    }

    public sealed class ILogServerDelM_ : Ice.ObjectDelM_, ILogServerDel_
    {
        public void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("gameImage", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    if(gameId == null)
                    {
                        gtr.GameIdentifyT tmp__ = new gtr.GameIdentifyT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        gameId.write__(os__);
                    }
                    os__.writeInt(timetick);
                    os__.writeString(opName);
                    if(image == null)
                    {
                        gtr.ImageDataT tmp__ = new gtr.ImageDataT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        image.write__(os__);
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

        public void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("gameMsg", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    if(gameId == null)
                    {
                        gtr.GameIdentifyT tmp__ = new gtr.GameIdentifyT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        gameId.write__(os__);
                    }
                    os__.writeInt(timetick);
                    if(msg == null)
                    {
                        gtr.LogMessageT tmp__ = new gtr.LogMessageT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        msg.write__(os__);
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

        public gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__)
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
                    gtr.ServiceIdentifyT ret__;
                    ret__ = null;
                    if(ret__ == null)
                    {
                        ret__ = new gtr.ServiceIdentifyT();
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

        public int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
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

        public void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("heartbeat", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    os__.writeString(senderType);
                    os__.writeString(senderId);
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

        public void shutdown(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("shutdown", Ice.OperationMode.Normal, context__);
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
    }

    public sealed class IGameHostDelM_ : Ice.ObjectDelM_, IGameHostDel_
    {
        public string answer(gtr.QuestionContentT question, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("answer", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    if(question == null)
                    {
                        gtr.QuestionContentT tmp__ = new gtr.QuestionContentT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        question.write__(os__);
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

        public void completeTask(gtr.GameTaskResultT result, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("completeTask", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    if(result == null)
                    {
                        gtr.GameTaskResultT tmp__ = new gtr.GameTaskResultT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        result.write__(os__);
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

        public gtr.GameTaskletT getTask(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("getTask", Ice.OperationMode.Normal, context__);
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
                    gtr.GameTaskletT ret__;
                    ret__ = null;
                    if(ret__ == null)
                    {
                        ret__ = new gtr.GameTaskletT();
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

        public void verifyAnswer(int type, bool succ, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("verifyAnswer", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    os__.writeInt(type);
                    os__.writeBool(succ);
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

        public void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("gameImage", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    if(gameId == null)
                    {
                        gtr.GameIdentifyT tmp__ = new gtr.GameIdentifyT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        gameId.write__(os__);
                    }
                    os__.writeInt(timetick);
                    os__.writeString(opName);
                    if(image == null)
                    {
                        gtr.ImageDataT tmp__ = new gtr.ImageDataT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        image.write__(os__);
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

        public void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("gameMsg", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    if(gameId == null)
                    {
                        gtr.GameIdentifyT tmp__ = new gtr.GameIdentifyT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        gameId.write__(os__);
                    }
                    os__.writeInt(timetick);
                    if(msg == null)
                    {
                        gtr.LogMessageT tmp__ = new gtr.LogMessageT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        msg.write__(os__);
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

        public void answerResult(string no, string result, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("answerResult", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    os__.writeString(no);
                    os__.writeString(result);
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

        public gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__)
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
                    gtr.ServiceIdentifyT ret__;
                    ret__ = null;
                    if(ret__ == null)
                    {
                        ret__ = new gtr.ServiceIdentifyT();
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

        public int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
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

        public void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("heartbeat", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    os__.writeString(senderType);
                    os__.writeString(senderId);
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

        public void shutdown(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("shutdown", Ice.OperationMode.Normal, context__);
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
    }

    public sealed class IGtrServerDelM_ : Ice.ObjectDelM_, IGtrServerDel_
    {
        public void completeTask(gtr.GameTaskResultT result, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("completeTask", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    if(result == null)
                    {
                        gtr.GameTaskResultT tmp__ = new gtr.GameTaskResultT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        result.write__(os__);
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

        public gtr.GameTaskletT getTask(gtr.GameRobotInfoT robot, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("getTask", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    if(robot == null)
                    {
                        gtr.GameRobotInfoT tmp__ = new gtr.GameRobotInfoT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        robot.write__(os__);
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
                    gtr.GameTaskletT ret__;
                    ret__ = null;
                    if(ret__ == null)
                    {
                        ret__ = new gtr.GameTaskletT();
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

        public void answer(gtr.IQuestionAskerPrx asker, string no, gtr.QuestionContentT question, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("answer", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    gtr.IQuestionAskerPrxHelper.write__(os__, asker);
                    os__.writeString(no);
                    if(question == null)
                    {
                        gtr.QuestionContentT tmp__ = new gtr.QuestionContentT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        question.write__(os__);
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

        public void answerResult(string no, gtr.QuestionResultT result, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("answerResult", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    os__.writeString(no);
                    if(result == null)
                    {
                        gtr.QuestionResultT tmp__ = new gtr.QuestionResultT();
                        tmp__.write__(os__);
                    }
                    else
                    {
                        result.write__(os__);
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

        public gtr.CallReturnT login(gtr.IAnswerEndpointPrx answer, string worker, string passwd, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("login", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    gtr.IAnswerEndpointPrxHelper.write__(os__, answer);
                    os__.writeString(worker);
                    os__.writeString(passwd);
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
                    gtr.CallReturnT ret__;
                    ret__ = null;
                    if(ret__ == null)
                    {
                        ret__ = new gtr.CallReturnT();
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

        public void logout(gtr.IAnswerEndpointPrx answer, string worker, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("logout", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    gtr.IAnswerEndpointPrxHelper.write__(os__, answer);
                    os__.writeString(worker);
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

        public void verifyAnswer(string no, int type, bool succ, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("verifyAnswer", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    os__.writeString(no);
                    os__.writeInt(type);
                    os__.writeBool(succ);
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

        public gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__)
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
                    gtr.ServiceIdentifyT ret__;
                    ret__ = null;
                    if(ret__ == null)
                    {
                        ret__ = new gtr.ServiceIdentifyT();
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

        public int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
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

        public void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("heartbeat", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    os__.writeString(senderType);
                    os__.writeString(senderId);
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

        public void shutdown(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("shutdown", Ice.OperationMode.Normal, context__);
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
    }
}

namespace gtr
{
    public sealed class IServiceDelD_ : Ice.ObjectDelD_, IServiceDel_
    {
        public gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getId", Ice.OperationMode.Normal, context__);
            gtr.ServiceIdentifyT result__ = new gtr.ServiceIdentifyT();
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

        public int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getType", Ice.OperationMode.Normal, context__);
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

        public void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "heartbeat", Ice.OperationMode.Normal, context__);
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
                servant__.heartbeat(senderType, senderId, current__);
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

        public void shutdown(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "shutdown", Ice.OperationMode.Normal, context__);
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
                servant__.shutdown(current__);
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
    }

    public sealed class IAnswerEndpointDelD_ : Ice.ObjectDelD_, IAnswerEndpointDel_
    {
        public int addQuestion(gtr.IQuestionServerPrx server, string no, string createTime, gtr.QuestionContentT question, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "addQuestion", Ice.OperationMode.Normal, context__);
            int result__ = 0;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IAnswerEndpoint servant__ = null;
                try
                {
                    servant__ = (IAnswerEndpoint)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                result__ = servant__.addQuestion(server, no, createTime, question, current__);
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

        public int getRemains(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getRemains", Ice.OperationMode.Normal, context__);
            int result__ = 0;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IAnswerEndpoint servant__ = null;
                try
                {
                    servant__ = (IAnswerEndpoint)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                result__ = servant__.getRemains(current__);
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

        public gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getId", Ice.OperationMode.Normal, context__);
            gtr.ServiceIdentifyT result__ = new gtr.ServiceIdentifyT();
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IAnswerEndpoint servant__ = null;
                try
                {
                    servant__ = (IAnswerEndpoint)obj__;
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

        public int getTimestamp(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getTimestamp", Ice.OperationMode.Normal, context__);
            int result__ = 0;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IAnswerEndpoint servant__ = null;
                try
                {
                    servant__ = (IAnswerEndpoint)obj__;
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

        public int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getType", Ice.OperationMode.Normal, context__);
            int result__ = 0;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IAnswerEndpoint servant__ = null;
                try
                {
                    servant__ = (IAnswerEndpoint)obj__;
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

        public void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "heartbeat", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IAnswerEndpoint servant__ = null;
                try
                {
                    servant__ = (IAnswerEndpoint)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.heartbeat(senderType, senderId, current__);
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

        public void shutdown(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "shutdown", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IAnswerEndpoint servant__ = null;
                try
                {
                    servant__ = (IAnswerEndpoint)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.shutdown(current__);
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
    }

    public sealed class IQuestionAskerDelD_ : Ice.ObjectDelD_, IQuestionAskerDel_
    {
        public void answerResult(string no, string result, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "answerResult", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IQuestionAsker servant__ = null;
                try
                {
                    servant__ = (IQuestionAsker)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.answerResult(no, result, current__);
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
    }

    public sealed class IQuestionServerDelD_ : Ice.ObjectDelD_, IQuestionServerDel_
    {
        public void answer(gtr.IQuestionAskerPrx asker, string no, gtr.QuestionContentT question, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "answer", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IQuestionServer servant__ = null;
                try
                {
                    servant__ = (IQuestionServer)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.answer(asker, no, question, current__);
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

        public void answerResult(string no, gtr.QuestionResultT result, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "answerResult", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IQuestionServer servant__ = null;
                try
                {
                    servant__ = (IQuestionServer)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.answerResult(no, result, current__);
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

        public gtr.CallReturnT login(gtr.IAnswerEndpointPrx answer, string worker, string passwd, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "login", Ice.OperationMode.Normal, context__);
            gtr.CallReturnT result__ = new gtr.CallReturnT();
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IQuestionServer servant__ = null;
                try
                {
                    servant__ = (IQuestionServer)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                result__ = servant__.login(answer, worker, passwd, current__);
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

        public void logout(gtr.IAnswerEndpointPrx answer, string worker, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "logout", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IQuestionServer servant__ = null;
                try
                {
                    servant__ = (IQuestionServer)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.logout(answer, worker, current__);
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

        public void verifyAnswer(string no, int type, bool succ, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "verifyAnswer", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IQuestionServer servant__ = null;
                try
                {
                    servant__ = (IQuestionServer)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.verifyAnswer(no, type, succ, current__);
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

        public gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getId", Ice.OperationMode.Normal, context__);
            gtr.ServiceIdentifyT result__ = new gtr.ServiceIdentifyT();
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IQuestionServer servant__ = null;
                try
                {
                    servant__ = (IQuestionServer)obj__;
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

        public int getTimestamp(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getTimestamp", Ice.OperationMode.Normal, context__);
            int result__ = 0;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IQuestionServer servant__ = null;
                try
                {
                    servant__ = (IQuestionServer)obj__;
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

        public int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getType", Ice.OperationMode.Normal, context__);
            int result__ = 0;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IQuestionServer servant__ = null;
                try
                {
                    servant__ = (IQuestionServer)obj__;
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

        public void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "heartbeat", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IQuestionServer servant__ = null;
                try
                {
                    servant__ = (IQuestionServer)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.heartbeat(senderType, senderId, current__);
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

        public void shutdown(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "shutdown", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IQuestionServer servant__ = null;
                try
                {
                    servant__ = (IQuestionServer)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.shutdown(current__);
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
    }

    public sealed class ILoggerDelD_ : Ice.ObjectDelD_, ILoggerDel_
    {
        public void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "gameImage", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                ILogger servant__ = null;
                try
                {
                    servant__ = (ILogger)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.gameImage(gameId, timetick, opName, image, current__);
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

        public void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "gameMsg", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                ILogger servant__ = null;
                try
                {
                    servant__ = (ILogger)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.gameMsg(gameId, timetick, msg, current__);
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
    }

    public sealed class ILogServerDelD_ : Ice.ObjectDelD_, ILogServerDel_
    {
        public void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "gameImage", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                ILogServer servant__ = null;
                try
                {
                    servant__ = (ILogServer)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.gameImage(gameId, timetick, opName, image, current__);
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

        public void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "gameMsg", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                ILogServer servant__ = null;
                try
                {
                    servant__ = (ILogServer)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.gameMsg(gameId, timetick, msg, current__);
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

        public gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getId", Ice.OperationMode.Normal, context__);
            gtr.ServiceIdentifyT result__ = new gtr.ServiceIdentifyT();
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                ILogServer servant__ = null;
                try
                {
                    servant__ = (ILogServer)obj__;
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

        public int getTimestamp(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getTimestamp", Ice.OperationMode.Normal, context__);
            int result__ = 0;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                ILogServer servant__ = null;
                try
                {
                    servant__ = (ILogServer)obj__;
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

        public int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getType", Ice.OperationMode.Normal, context__);
            int result__ = 0;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                ILogServer servant__ = null;
                try
                {
                    servant__ = (ILogServer)obj__;
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

        public void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "heartbeat", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                ILogServer servant__ = null;
                try
                {
                    servant__ = (ILogServer)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.heartbeat(senderType, senderId, current__);
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

        public void shutdown(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "shutdown", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                ILogServer servant__ = null;
                try
                {
                    servant__ = (ILogServer)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.shutdown(current__);
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
    }

    public sealed class IGameHostDelD_ : Ice.ObjectDelD_, IGameHostDel_
    {
        public string answer(gtr.QuestionContentT question, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "answer", Ice.OperationMode.Normal, context__);
            string result__ = null;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGameHost servant__ = null;
                try
                {
                    servant__ = (IGameHost)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                result__ = servant__.answer(question, current__);
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

        public void completeTask(gtr.GameTaskResultT result, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "completeTask", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGameHost servant__ = null;
                try
                {
                    servant__ = (IGameHost)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.completeTask(result, current__);
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

        public gtr.GameTaskletT getTask(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getTask", Ice.OperationMode.Normal, context__);
            gtr.GameTaskletT result__ = new gtr.GameTaskletT();
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGameHost servant__ = null;
                try
                {
                    servant__ = (IGameHost)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                result__ = servant__.getTask(current__);
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

        public void verifyAnswer(int type, bool succ, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "verifyAnswer", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGameHost servant__ = null;
                try
                {
                    servant__ = (IGameHost)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.verifyAnswer(type, succ, current__);
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

        public void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "gameImage", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGameHost servant__ = null;
                try
                {
                    servant__ = (IGameHost)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.gameImage(gameId, timetick, opName, image, current__);
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

        public void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "gameMsg", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGameHost servant__ = null;
                try
                {
                    servant__ = (IGameHost)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.gameMsg(gameId, timetick, msg, current__);
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

        public void answerResult(string no, string result, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "answerResult", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGameHost servant__ = null;
                try
                {
                    servant__ = (IGameHost)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.answerResult(no, result, current__);
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

        public gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getId", Ice.OperationMode.Normal, context__);
            gtr.ServiceIdentifyT result__ = new gtr.ServiceIdentifyT();
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGameHost servant__ = null;
                try
                {
                    servant__ = (IGameHost)obj__;
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

        public int getTimestamp(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getTimestamp", Ice.OperationMode.Normal, context__);
            int result__ = 0;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGameHost servant__ = null;
                try
                {
                    servant__ = (IGameHost)obj__;
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

        public int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getType", Ice.OperationMode.Normal, context__);
            int result__ = 0;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGameHost servant__ = null;
                try
                {
                    servant__ = (IGameHost)obj__;
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

        public void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "heartbeat", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGameHost servant__ = null;
                try
                {
                    servant__ = (IGameHost)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.heartbeat(senderType, senderId, current__);
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

        public void shutdown(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "shutdown", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGameHost servant__ = null;
                try
                {
                    servant__ = (IGameHost)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.shutdown(current__);
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
    }

    public sealed class IGtrServerDelD_ : Ice.ObjectDelD_, IGtrServerDel_
    {
        public void completeTask(gtr.GameTaskResultT result, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "completeTask", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGtrServer servant__ = null;
                try
                {
                    servant__ = (IGtrServer)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.completeTask(result, current__);
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

        public gtr.GameTaskletT getTask(gtr.GameRobotInfoT robot, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getTask", Ice.OperationMode.Normal, context__);
            gtr.GameTaskletT result__ = new gtr.GameTaskletT();
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGtrServer servant__ = null;
                try
                {
                    servant__ = (IGtrServer)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                result__ = servant__.getTask(robot, current__);
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

        public void answer(gtr.IQuestionAskerPrx asker, string no, gtr.QuestionContentT question, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "answer", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGtrServer servant__ = null;
                try
                {
                    servant__ = (IGtrServer)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.answer(asker, no, question, current__);
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

        public void answerResult(string no, gtr.QuestionResultT result, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "answerResult", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGtrServer servant__ = null;
                try
                {
                    servant__ = (IGtrServer)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.answerResult(no, result, current__);
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

        public gtr.CallReturnT login(gtr.IAnswerEndpointPrx answer, string worker, string passwd, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "login", Ice.OperationMode.Normal, context__);
            gtr.CallReturnT result__ = new gtr.CallReturnT();
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGtrServer servant__ = null;
                try
                {
                    servant__ = (IGtrServer)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                result__ = servant__.login(answer, worker, passwd, current__);
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

        public void logout(gtr.IAnswerEndpointPrx answer, string worker, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "logout", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGtrServer servant__ = null;
                try
                {
                    servant__ = (IGtrServer)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.logout(answer, worker, current__);
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

        public void verifyAnswer(string no, int type, bool succ, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "verifyAnswer", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGtrServer servant__ = null;
                try
                {
                    servant__ = (IGtrServer)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.verifyAnswer(no, type, succ, current__);
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

        public gtr.ServiceIdentifyT getId(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getId", Ice.OperationMode.Normal, context__);
            gtr.ServiceIdentifyT result__ = new gtr.ServiceIdentifyT();
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGtrServer servant__ = null;
                try
                {
                    servant__ = (IGtrServer)obj__;
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

        public int getTimestamp(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getTimestamp", Ice.OperationMode.Normal, context__);
            int result__ = 0;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGtrServer servant__ = null;
                try
                {
                    servant__ = (IGtrServer)obj__;
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

        public int ice_getType_(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "getType", Ice.OperationMode.Normal, context__);
            int result__ = 0;
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGtrServer servant__ = null;
                try
                {
                    servant__ = (IGtrServer)obj__;
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

        public void heartbeat(string senderType, string senderId, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "heartbeat", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGtrServer servant__ = null;
                try
                {
                    servant__ = (IGtrServer)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.heartbeat(senderType, senderId, current__);
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

        public void shutdown(_System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "shutdown", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                IGtrServer servant__ = null;
                try
                {
                    servant__ = (IGtrServer)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.shutdown(current__);
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
    }
}

namespace gtr
{
    public abstract class IServiceDisp_ : Ice.ObjectImpl, IService
    {
        #region Slice operations

        public int ice_getType_()
        {
            return ice_getType_(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract int ice_getType_(Ice.Current current__);

        public gtr.ServiceIdentifyT getId()
        {
            return getId(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract gtr.ServiceIdentifyT getId(Ice.Current current__);

        public int getTimestamp()
        {
            return getTimestamp(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract int getTimestamp(Ice.Current current__);

        public void shutdown()
        {
            shutdown(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void shutdown(Ice.Current current__);

        public void heartbeat(string senderType, string senderId)
        {
            heartbeat(senderType, senderId, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void heartbeat(string senderType, string senderId, Ice.Current current__);

        #endregion

        #region Slice type-related members

        public static new string[] ids__ = 
        {
            "::Ice::Object",
            "::gtr::IService"
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

        public static Ice.DispatchStatus getType___(IService obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            inS__.istr().skipEmptyEncaps();
            IceInternal.BasicStream os__ = inS__.ostr();
            int ret__ = obj__.ice_getType_(current__);
            os__.writeInt(ret__);
            return Ice.DispatchStatus.DispatchOK;
        }

        public static Ice.DispatchStatus getId___(IService obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            inS__.istr().skipEmptyEncaps();
            IceInternal.BasicStream os__ = inS__.ostr();
            gtr.ServiceIdentifyT ret__ = obj__.getId(current__);
            if(ret__ == null)
            {
                gtr.ServiceIdentifyT tmp__ = new gtr.ServiceIdentifyT();
                tmp__.write__(os__);
            }
            else
            {
                ret__.write__(os__);
            }
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

        public static Ice.DispatchStatus shutdown___(IService obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            inS__.istr().skipEmptyEncaps();
            obj__.shutdown(current__);
            return Ice.DispatchStatus.DispatchOK;
        }

        public static Ice.DispatchStatus heartbeat___(IService obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            IceInternal.BasicStream is__ = inS__.istr();
            is__.startReadEncaps();
            string senderType;
            senderType = is__.readString();
            string senderId;
            senderId = is__.readString();
            is__.endReadEncaps();
            obj__.heartbeat(senderType, senderId, current__);
            return Ice.DispatchStatus.DispatchOK;
        }

        private static string[] all__ =
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
                    return getTimestamp___(this, inS__, current__);
                }
                case 2:
                {
                    return getType___(this, inS__, current__);
                }
                case 3:
                {
                    return heartbeat___(this, inS__, current__);
                }
                case 4:
                {
                    return ice_id___(this, inS__, current__);
                }
                case 5:
                {
                    return ice_ids___(this, inS__, current__);
                }
                case 6:
                {
                    return ice_isA___(this, inS__, current__);
                }
                case 7:
                {
                    return ice_ping___(this, inS__, current__);
                }
                case 8:
                {
                    return shutdown___(this, inS__, current__);
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
            ex.reason = "type gtr::IService was not generated with stream support";
            throw ex;
        }

        public override void read__(Ice.InputStream inS__, bool rid__)
        {
            Ice.MarshalException ex = new Ice.MarshalException();
            ex.reason = "type gtr::IService was not generated with stream support";
            throw ex;
        }

        #endregion
    }

    public abstract class IAnswerEndpointDisp_ : Ice.ObjectImpl, IAnswerEndpoint
    {
        #region Slice operations

        public int getRemains()
        {
            return getRemains(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract int getRemains(Ice.Current current__);

        public int addQuestion(gtr.IQuestionServerPrx server, string no, string createTime, gtr.QuestionContentT question)
        {
            return addQuestion(server, no, createTime, question, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract int addQuestion(gtr.IQuestionServerPrx server, string no, string createTime, gtr.QuestionContentT question, Ice.Current current__);

        #endregion

        #region Inherited Slice operations

        public gtr.ServiceIdentifyT getId()
        {
            return getId(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract gtr.ServiceIdentifyT getId(Ice.Current current__);

        public int getTimestamp()
        {
            return getTimestamp(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract int getTimestamp(Ice.Current current__);

        public int ice_getType_()
        {
            return ice_getType_(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract int ice_getType_(Ice.Current current__);

        public void heartbeat(string senderType, string senderId)
        {
            heartbeat(senderType, senderId, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void heartbeat(string senderType, string senderId, Ice.Current current__);

        public void shutdown()
        {
            shutdown(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void shutdown(Ice.Current current__);

        #endregion

        #region Slice type-related members

        public static new string[] ids__ = 
        {
            "::Ice::Object",
            "::gtr::IAnswerEndpoint",
            "::gtr::IService"
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

        public static Ice.DispatchStatus getRemains___(IAnswerEndpoint obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            inS__.istr().skipEmptyEncaps();
            IceInternal.BasicStream os__ = inS__.ostr();
            int ret__ = obj__.getRemains(current__);
            os__.writeInt(ret__);
            return Ice.DispatchStatus.DispatchOK;
        }

        public static Ice.DispatchStatus addQuestion___(IAnswerEndpoint obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            IceInternal.BasicStream is__ = inS__.istr();
            is__.startReadEncaps();
            gtr.IQuestionServerPrx server;
            server = gtr.IQuestionServerPrxHelper.read__(is__);
            string no;
            no = is__.readString();
            string createTime;
            createTime = is__.readString();
            gtr.QuestionContentT question;
            question = null;
            if(question == null)
            {
                question = new gtr.QuestionContentT();
            }
            question.read__(is__);
            is__.endReadEncaps();
            IceInternal.BasicStream os__ = inS__.ostr();
            int ret__ = obj__.addQuestion(server, no, createTime, question, current__);
            os__.writeInt(ret__);
            return Ice.DispatchStatus.DispatchOK;
        }

        private static string[] all__ =
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
                    return addQuestion___(this, inS__, current__);
                }
                case 1:
                {
                    return gtr.IServiceDisp_.getId___(this, inS__, current__);
                }
                case 2:
                {
                    return getRemains___(this, inS__, current__);
                }
                case 3:
                {
                    return gtr.IServiceDisp_.getTimestamp___(this, inS__, current__);
                }
                case 4:
                {
                    return gtr.IServiceDisp_.getType___(this, inS__, current__);
                }
                case 5:
                {
                    return gtr.IServiceDisp_.heartbeat___(this, inS__, current__);
                }
                case 6:
                {
                    return ice_id___(this, inS__, current__);
                }
                case 7:
                {
                    return ice_ids___(this, inS__, current__);
                }
                case 8:
                {
                    return ice_isA___(this, inS__, current__);
                }
                case 9:
                {
                    return ice_ping___(this, inS__, current__);
                }
                case 10:
                {
                    return gtr.IServiceDisp_.shutdown___(this, inS__, current__);
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
            ex.reason = "type gtr::IAnswerEndpoint was not generated with stream support";
            throw ex;
        }

        public override void read__(Ice.InputStream inS__, bool rid__)
        {
            Ice.MarshalException ex = new Ice.MarshalException();
            ex.reason = "type gtr::IAnswerEndpoint was not generated with stream support";
            throw ex;
        }

        #endregion
    }

    public abstract class IQuestionAskerDisp_ : Ice.ObjectImpl, IQuestionAsker
    {
        #region Slice operations

        public void answerResult(string no, string result)
        {
            answerResult(no, result, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void answerResult(string no, string result, Ice.Current current__);

        #endregion

        #region Slice type-related members

        public static new string[] ids__ = 
        {
            "::Ice::Object",
            "::gtr::IQuestionAsker"
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

        public static Ice.DispatchStatus answerResult___(IQuestionAsker obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            IceInternal.BasicStream is__ = inS__.istr();
            is__.startReadEncaps();
            string no;
            no = is__.readString();
            string result;
            result = is__.readString();
            is__.endReadEncaps();
            obj__.answerResult(no, result, current__);
            return Ice.DispatchStatus.DispatchOK;
        }

        private static string[] all__ =
        {
            "answerResult",
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
                    return answerResult___(this, inS__, current__);
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
            ex.reason = "type gtr::IQuestionAsker was not generated with stream support";
            throw ex;
        }

        public override void read__(Ice.InputStream inS__, bool rid__)
        {
            Ice.MarshalException ex = new Ice.MarshalException();
            ex.reason = "type gtr::IQuestionAsker was not generated with stream support";
            throw ex;
        }

        #endregion
    }

    public abstract class IQuestionServerDisp_ : Ice.ObjectImpl, IQuestionServer
    {
        #region Slice operations

        public void answer(gtr.IQuestionAskerPrx asker, string no, gtr.QuestionContentT question)
        {
            answer(asker, no, question, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void answer(gtr.IQuestionAskerPrx asker, string no, gtr.QuestionContentT question, Ice.Current current__);

        public void answerResult(string no, gtr.QuestionResultT result)
        {
            answerResult(no, result, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void answerResult(string no, gtr.QuestionResultT result, Ice.Current current__);

        public gtr.CallReturnT login(gtr.IAnswerEndpointPrx answer, string worker, string passwd)
        {
            return login(answer, worker, passwd, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract gtr.CallReturnT login(gtr.IAnswerEndpointPrx answer, string worker, string passwd, Ice.Current current__);

        public void logout(gtr.IAnswerEndpointPrx answer, string worker)
        {
            logout(answer, worker, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void logout(gtr.IAnswerEndpointPrx answer, string worker, Ice.Current current__);

        public void verifyAnswer(string no, int type, bool succ)
        {
            verifyAnswer(no, type, succ, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void verifyAnswer(string no, int type, bool succ, Ice.Current current__);

        #endregion

        #region Inherited Slice operations

        public gtr.ServiceIdentifyT getId()
        {
            return getId(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract gtr.ServiceIdentifyT getId(Ice.Current current__);

        public int getTimestamp()
        {
            return getTimestamp(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract int getTimestamp(Ice.Current current__);

        public int ice_getType_()
        {
            return ice_getType_(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract int ice_getType_(Ice.Current current__);

        public void heartbeat(string senderType, string senderId)
        {
            heartbeat(senderType, senderId, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void heartbeat(string senderType, string senderId, Ice.Current current__);

        public void shutdown()
        {
            shutdown(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void shutdown(Ice.Current current__);

        #endregion

        #region Slice type-related members

        public static new string[] ids__ = 
        {
            "::Ice::Object",
            "::gtr::IQuestionServer",
            "::gtr::IService"
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

        public static Ice.DispatchStatus answer___(IQuestionServer obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            IceInternal.BasicStream is__ = inS__.istr();
            is__.startReadEncaps();
            gtr.IQuestionAskerPrx asker;
            asker = gtr.IQuestionAskerPrxHelper.read__(is__);
            string no;
            no = is__.readString();
            gtr.QuestionContentT question;
            question = null;
            if(question == null)
            {
                question = new gtr.QuestionContentT();
            }
            question.read__(is__);
            is__.endReadEncaps();
            obj__.answer(asker, no, question, current__);
            return Ice.DispatchStatus.DispatchOK;
        }

        public static Ice.DispatchStatus answerResult___(IQuestionServer obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            IceInternal.BasicStream is__ = inS__.istr();
            is__.startReadEncaps();
            string no;
            no = is__.readString();
            gtr.QuestionResultT result;
            result = null;
            if(result == null)
            {
                result = new gtr.QuestionResultT();
            }
            result.read__(is__);
            is__.endReadEncaps();
            obj__.answerResult(no, result, current__);
            return Ice.DispatchStatus.DispatchOK;
        }

        public static Ice.DispatchStatus login___(IQuestionServer obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            IceInternal.BasicStream is__ = inS__.istr();
            is__.startReadEncaps();
            gtr.IAnswerEndpointPrx answer;
            answer = gtr.IAnswerEndpointPrxHelper.read__(is__);
            string worker;
            worker = is__.readString();
            string passwd;
            passwd = is__.readString();
            is__.endReadEncaps();
            IceInternal.BasicStream os__ = inS__.ostr();
            gtr.CallReturnT ret__ = obj__.login(answer, worker, passwd, current__);
            if(ret__ == null)
            {
                gtr.CallReturnT tmp__ = new gtr.CallReturnT();
                tmp__.write__(os__);
            }
            else
            {
                ret__.write__(os__);
            }
            return Ice.DispatchStatus.DispatchOK;
        }

        public static Ice.DispatchStatus logout___(IQuestionServer obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            IceInternal.BasicStream is__ = inS__.istr();
            is__.startReadEncaps();
            gtr.IAnswerEndpointPrx answer;
            answer = gtr.IAnswerEndpointPrxHelper.read__(is__);
            string worker;
            worker = is__.readString();
            is__.endReadEncaps();
            obj__.logout(answer, worker, current__);
            return Ice.DispatchStatus.DispatchOK;
        }

        public static Ice.DispatchStatus verifyAnswer___(IQuestionServer obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            IceInternal.BasicStream is__ = inS__.istr();
            is__.startReadEncaps();
            string no;
            no = is__.readString();
            int type;
            type = is__.readInt();
            bool succ;
            succ = is__.readBool();
            is__.endReadEncaps();
            obj__.verifyAnswer(no, type, succ, current__);
            return Ice.DispatchStatus.DispatchOK;
        }

        private static string[] all__ =
        {
            "answer",
            "answerResult",
            "getId",
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
                    return answer___(this, inS__, current__);
                }
                case 1:
                {
                    return answerResult___(this, inS__, current__);
                }
                case 2:
                {
                    return gtr.IServiceDisp_.getId___(this, inS__, current__);
                }
                case 3:
                {
                    return gtr.IServiceDisp_.getTimestamp___(this, inS__, current__);
                }
                case 4:
                {
                    return gtr.IServiceDisp_.getType___(this, inS__, current__);
                }
                case 5:
                {
                    return gtr.IServiceDisp_.heartbeat___(this, inS__, current__);
                }
                case 6:
                {
                    return ice_id___(this, inS__, current__);
                }
                case 7:
                {
                    return ice_ids___(this, inS__, current__);
                }
                case 8:
                {
                    return ice_isA___(this, inS__, current__);
                }
                case 9:
                {
                    return ice_ping___(this, inS__, current__);
                }
                case 10:
                {
                    return login___(this, inS__, current__);
                }
                case 11:
                {
                    return logout___(this, inS__, current__);
                }
                case 12:
                {
                    return gtr.IServiceDisp_.shutdown___(this, inS__, current__);
                }
                case 13:
                {
                    return verifyAnswer___(this, inS__, current__);
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
            ex.reason = "type gtr::IQuestionServer was not generated with stream support";
            throw ex;
        }

        public override void read__(Ice.InputStream inS__, bool rid__)
        {
            Ice.MarshalException ex = new Ice.MarshalException();
            ex.reason = "type gtr::IQuestionServer was not generated with stream support";
            throw ex;
        }

        #endregion
    }

    public abstract class ILoggerDisp_ : Ice.ObjectImpl, ILogger
    {
        #region Slice operations

        public void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg)
        {
            gameMsg(gameId, timetick, msg, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg, Ice.Current current__);

        public void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image)
        {
            gameImage(gameId, timetick, opName, image, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image, Ice.Current current__);

        #endregion

        #region Slice type-related members

        public static new string[] ids__ = 
        {
            "::Ice::Object",
            "::gtr::ILogger"
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

        public static Ice.DispatchStatus gameMsg___(ILogger obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            IceInternal.BasicStream is__ = inS__.istr();
            is__.startReadEncaps();
            gtr.GameIdentifyT gameId;
            gameId = null;
            if(gameId == null)
            {
                gameId = new gtr.GameIdentifyT();
            }
            gameId.read__(is__);
            int timetick;
            timetick = is__.readInt();
            gtr.LogMessageT msg;
            msg = null;
            if(msg == null)
            {
                msg = new gtr.LogMessageT();
            }
            msg.read__(is__);
            is__.endReadEncaps();
            obj__.gameMsg(gameId, timetick, msg, current__);
            return Ice.DispatchStatus.DispatchOK;
        }

        public static Ice.DispatchStatus gameImage___(ILogger obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            IceInternal.BasicStream is__ = inS__.istr();
            is__.startReadEncaps();
            gtr.GameIdentifyT gameId;
            gameId = null;
            if(gameId == null)
            {
                gameId = new gtr.GameIdentifyT();
            }
            gameId.read__(is__);
            int timetick;
            timetick = is__.readInt();
            string opName;
            opName = is__.readString();
            gtr.ImageDataT image;
            image = null;
            if(image == null)
            {
                image = new gtr.ImageDataT();
            }
            image.read__(is__);
            is__.endReadEncaps();
            obj__.gameImage(gameId, timetick, opName, image, current__);
            return Ice.DispatchStatus.DispatchOK;
        }

        private static string[] all__ =
        {
            "gameImage",
            "gameMsg",
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
                    return gameImage___(this, inS__, current__);
                }
                case 1:
                {
                    return gameMsg___(this, inS__, current__);
                }
                case 2:
                {
                    return ice_id___(this, inS__, current__);
                }
                case 3:
                {
                    return ice_ids___(this, inS__, current__);
                }
                case 4:
                {
                    return ice_isA___(this, inS__, current__);
                }
                case 5:
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
            ex.reason = "type gtr::ILogger was not generated with stream support";
            throw ex;
        }

        public override void read__(Ice.InputStream inS__, bool rid__)
        {
            Ice.MarshalException ex = new Ice.MarshalException();
            ex.reason = "type gtr::ILogger was not generated with stream support";
            throw ex;
        }

        #endregion
    }

    public abstract class ILogServerDisp_ : Ice.ObjectImpl, ILogServer
    {
        #region Inherited Slice operations

        public void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image)
        {
            gameImage(gameId, timetick, opName, image, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image, Ice.Current current__);

        public void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg)
        {
            gameMsg(gameId, timetick, msg, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg, Ice.Current current__);

        public gtr.ServiceIdentifyT getId()
        {
            return getId(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract gtr.ServiceIdentifyT getId(Ice.Current current__);

        public int getTimestamp()
        {
            return getTimestamp(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract int getTimestamp(Ice.Current current__);

        public int ice_getType_()
        {
            return ice_getType_(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract int ice_getType_(Ice.Current current__);

        public void heartbeat(string senderType, string senderId)
        {
            heartbeat(senderType, senderId, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void heartbeat(string senderType, string senderId, Ice.Current current__);

        public void shutdown()
        {
            shutdown(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void shutdown(Ice.Current current__);

        #endregion

        #region Slice type-related members

        public static new string[] ids__ = 
        {
            "::Ice::Object",
            "::gtr::ILogServer",
            "::gtr::ILogger",
            "::gtr::IService"
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

        private static string[] all__ =
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
                    return gtr.ILoggerDisp_.gameImage___(this, inS__, current__);
                }
                case 1:
                {
                    return gtr.ILoggerDisp_.gameMsg___(this, inS__, current__);
                }
                case 2:
                {
                    return gtr.IServiceDisp_.getId___(this, inS__, current__);
                }
                case 3:
                {
                    return gtr.IServiceDisp_.getTimestamp___(this, inS__, current__);
                }
                case 4:
                {
                    return gtr.IServiceDisp_.getType___(this, inS__, current__);
                }
                case 5:
                {
                    return gtr.IServiceDisp_.heartbeat___(this, inS__, current__);
                }
                case 6:
                {
                    return ice_id___(this, inS__, current__);
                }
                case 7:
                {
                    return ice_ids___(this, inS__, current__);
                }
                case 8:
                {
                    return ice_isA___(this, inS__, current__);
                }
                case 9:
                {
                    return ice_ping___(this, inS__, current__);
                }
                case 10:
                {
                    return gtr.IServiceDisp_.shutdown___(this, inS__, current__);
                }
            }

            _System.Diagnostics.Debug.Assert(false);
            throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
        }

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
            ex.reason = "type gtr::ILogServer was not generated with stream support";
            throw ex;
        }

        public override void read__(Ice.InputStream inS__, bool rid__)
        {
            Ice.MarshalException ex = new Ice.MarshalException();
            ex.reason = "type gtr::ILogServer was not generated with stream support";
            throw ex;
        }

        #endregion
    }

    public abstract class IGameHostDisp_ : Ice.ObjectImpl, IGameHost
    {
        #region Slice operations

        public gtr.GameTaskletT getTask()
        {
            return getTask(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract gtr.GameTaskletT getTask(Ice.Current current__);

        public void completeTask(gtr.GameTaskResultT result)
        {
            completeTask(result, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void completeTask(gtr.GameTaskResultT result, Ice.Current current__);

        public string answer(gtr.QuestionContentT question)
        {
            return answer(question, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract string answer(gtr.QuestionContentT question, Ice.Current current__);

        public void verifyAnswer(int type, bool succ)
        {
            verifyAnswer(type, succ, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void verifyAnswer(int type, bool succ, Ice.Current current__);

        #endregion

        #region Inherited Slice operations

        public void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image)
        {
            gameImage(gameId, timetick, opName, image, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void gameImage(gtr.GameIdentifyT gameId, int timetick, string opName, gtr.ImageDataT image, Ice.Current current__);

        public void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg)
        {
            gameMsg(gameId, timetick, msg, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void gameMsg(gtr.GameIdentifyT gameId, int timetick, gtr.LogMessageT msg, Ice.Current current__);

        public void answerResult(string no, string result)
        {
            answerResult(no, result, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void answerResult(string no, string result, Ice.Current current__);

        public gtr.ServiceIdentifyT getId()
        {
            return getId(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract gtr.ServiceIdentifyT getId(Ice.Current current__);

        public int getTimestamp()
        {
            return getTimestamp(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract int getTimestamp(Ice.Current current__);

        public int ice_getType_()
        {
            return ice_getType_(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract int ice_getType_(Ice.Current current__);

        public void heartbeat(string senderType, string senderId)
        {
            heartbeat(senderType, senderId, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void heartbeat(string senderType, string senderId, Ice.Current current__);

        public void shutdown()
        {
            shutdown(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void shutdown(Ice.Current current__);

        #endregion

        #region Slice type-related members

        public static new string[] ids__ = 
        {
            "::Ice::Object",
            "::gtr::IGameHost",
            "::gtr::ILogger",
            "::gtr::IQuestionAsker",
            "::gtr::IService"
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

        public static Ice.DispatchStatus getTask___(IGameHost obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            inS__.istr().skipEmptyEncaps();
            IceInternal.BasicStream os__ = inS__.ostr();
            gtr.GameTaskletT ret__ = obj__.getTask(current__);
            if(ret__ == null)
            {
                gtr.GameTaskletT tmp__ = new gtr.GameTaskletT();
                tmp__.write__(os__);
            }
            else
            {
                ret__.write__(os__);
            }
            return Ice.DispatchStatus.DispatchOK;
        }

        public static Ice.DispatchStatus completeTask___(IGameHost obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            IceInternal.BasicStream is__ = inS__.istr();
            is__.startReadEncaps();
            gtr.GameTaskResultT result;
            result = null;
            if(result == null)
            {
                result = new gtr.GameTaskResultT();
            }
            result.read__(is__);
            is__.endReadEncaps();
            obj__.completeTask(result, current__);
            return Ice.DispatchStatus.DispatchOK;
        }

        public static Ice.DispatchStatus answer___(IGameHost obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            IceInternal.BasicStream is__ = inS__.istr();
            is__.startReadEncaps();
            gtr.QuestionContentT question;
            question = null;
            if(question == null)
            {
                question = new gtr.QuestionContentT();
            }
            question.read__(is__);
            is__.endReadEncaps();
            IceInternal.BasicStream os__ = inS__.ostr();
            string ret__ = obj__.answer(question, current__);
            os__.writeString(ret__);
            return Ice.DispatchStatus.DispatchOK;
        }

        public static Ice.DispatchStatus verifyAnswer___(IGameHost obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            IceInternal.BasicStream is__ = inS__.istr();
            is__.startReadEncaps();
            int type;
            type = is__.readInt();
            bool succ;
            succ = is__.readBool();
            is__.endReadEncaps();
            obj__.verifyAnswer(type, succ, current__);
            return Ice.DispatchStatus.DispatchOK;
        }

        private static string[] all__ =
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
                    return answer___(this, inS__, current__);
                }
                case 1:
                {
                    return gtr.IQuestionAskerDisp_.answerResult___(this, inS__, current__);
                }
                case 2:
                {
                    return completeTask___(this, inS__, current__);
                }
                case 3:
                {
                    return gtr.ILoggerDisp_.gameImage___(this, inS__, current__);
                }
                case 4:
                {
                    return gtr.ILoggerDisp_.gameMsg___(this, inS__, current__);
                }
                case 5:
                {
                    return gtr.IServiceDisp_.getId___(this, inS__, current__);
                }
                case 6:
                {
                    return getTask___(this, inS__, current__);
                }
                case 7:
                {
                    return gtr.IServiceDisp_.getTimestamp___(this, inS__, current__);
                }
                case 8:
                {
                    return gtr.IServiceDisp_.getType___(this, inS__, current__);
                }
                case 9:
                {
                    return gtr.IServiceDisp_.heartbeat___(this, inS__, current__);
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
                case 14:
                {
                    return gtr.IServiceDisp_.shutdown___(this, inS__, current__);
                }
                case 15:
                {
                    return verifyAnswer___(this, inS__, current__);
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
            ex.reason = "type gtr::IGameHost was not generated with stream support";
            throw ex;
        }

        public override void read__(Ice.InputStream inS__, bool rid__)
        {
            Ice.MarshalException ex = new Ice.MarshalException();
            ex.reason = "type gtr::IGameHost was not generated with stream support";
            throw ex;
        }

        #endregion
    }

    public abstract class IGtrServerDisp_ : Ice.ObjectImpl, IGtrServer
    {
        #region Slice operations

        public gtr.GameTaskletT getTask(gtr.GameRobotInfoT robot)
        {
            return getTask(robot, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract gtr.GameTaskletT getTask(gtr.GameRobotInfoT robot, Ice.Current current__);

        public void completeTask(gtr.GameTaskResultT result)
        {
            completeTask(result, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void completeTask(gtr.GameTaskResultT result, Ice.Current current__);

        #endregion

        #region Inherited Slice operations

        public void answer(gtr.IQuestionAskerPrx asker, string no, gtr.QuestionContentT question)
        {
            answer(asker, no, question, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void answer(gtr.IQuestionAskerPrx asker, string no, gtr.QuestionContentT question, Ice.Current current__);

        public void answerResult(string no, gtr.QuestionResultT result)
        {
            answerResult(no, result, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void answerResult(string no, gtr.QuestionResultT result, Ice.Current current__);

        public gtr.CallReturnT login(gtr.IAnswerEndpointPrx answer, string worker, string passwd)
        {
            return login(answer, worker, passwd, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract gtr.CallReturnT login(gtr.IAnswerEndpointPrx answer, string worker, string passwd, Ice.Current current__);

        public void logout(gtr.IAnswerEndpointPrx answer, string worker)
        {
            logout(answer, worker, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void logout(gtr.IAnswerEndpointPrx answer, string worker, Ice.Current current__);

        public void verifyAnswer(string no, int type, bool succ)
        {
            verifyAnswer(no, type, succ, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void verifyAnswer(string no, int type, bool succ, Ice.Current current__);

        public gtr.ServiceIdentifyT getId()
        {
            return getId(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract gtr.ServiceIdentifyT getId(Ice.Current current__);

        public int getTimestamp()
        {
            return getTimestamp(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract int getTimestamp(Ice.Current current__);

        public int ice_getType_()
        {
            return ice_getType_(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract int ice_getType_(Ice.Current current__);

        public void heartbeat(string senderType, string senderId)
        {
            heartbeat(senderType, senderId, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void heartbeat(string senderType, string senderId, Ice.Current current__);

        public void shutdown()
        {
            shutdown(Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void shutdown(Ice.Current current__);

        #endregion

        #region Slice type-related members

        public static new string[] ids__ = 
        {
            "::Ice::Object",
            "::gtr::IGtrServer",
            "::gtr::IQuestionServer",
            "::gtr::IService"
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

        public static Ice.DispatchStatus getTask___(IGtrServer obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            IceInternal.BasicStream is__ = inS__.istr();
            is__.startReadEncaps();
            gtr.GameRobotInfoT robot;
            robot = null;
            if(robot == null)
            {
                robot = new gtr.GameRobotInfoT();
            }
            robot.read__(is__);
            is__.endReadEncaps();
            IceInternal.BasicStream os__ = inS__.ostr();
            gtr.GameTaskletT ret__ = obj__.getTask(robot, current__);
            if(ret__ == null)
            {
                gtr.GameTaskletT tmp__ = new gtr.GameTaskletT();
                tmp__.write__(os__);
            }
            else
            {
                ret__.write__(os__);
            }
            return Ice.DispatchStatus.DispatchOK;
        }

        public static Ice.DispatchStatus completeTask___(IGtrServer obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            IceInternal.BasicStream is__ = inS__.istr();
            is__.startReadEncaps();
            gtr.GameTaskResultT result;
            result = null;
            if(result == null)
            {
                result = new gtr.GameTaskResultT();
            }
            result.read__(is__);
            is__.endReadEncaps();
            obj__.completeTask(result, current__);
            return Ice.DispatchStatus.DispatchOK;
        }

        private static string[] all__ =
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
                    return gtr.IQuestionServerDisp_.answer___(this, inS__, current__);
                }
                case 1:
                {
                    return gtr.IQuestionServerDisp_.answerResult___(this, inS__, current__);
                }
                case 2:
                {
                    return completeTask___(this, inS__, current__);
                }
                case 3:
                {
                    return gtr.IServiceDisp_.getId___(this, inS__, current__);
                }
                case 4:
                {
                    return getTask___(this, inS__, current__);
                }
                case 5:
                {
                    return gtr.IServiceDisp_.getTimestamp___(this, inS__, current__);
                }
                case 6:
                {
                    return gtr.IServiceDisp_.getType___(this, inS__, current__);
                }
                case 7:
                {
                    return gtr.IServiceDisp_.heartbeat___(this, inS__, current__);
                }
                case 8:
                {
                    return ice_id___(this, inS__, current__);
                }
                case 9:
                {
                    return ice_ids___(this, inS__, current__);
                }
                case 10:
                {
                    return ice_isA___(this, inS__, current__);
                }
                case 11:
                {
                    return ice_ping___(this, inS__, current__);
                }
                case 12:
                {
                    return gtr.IQuestionServerDisp_.login___(this, inS__, current__);
                }
                case 13:
                {
                    return gtr.IQuestionServerDisp_.logout___(this, inS__, current__);
                }
                case 14:
                {
                    return gtr.IServiceDisp_.shutdown___(this, inS__, current__);
                }
                case 15:
                {
                    return gtr.IQuestionServerDisp_.verifyAnswer___(this, inS__, current__);
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
            ex.reason = "type gtr::IGtrServer was not generated with stream support";
            throw ex;
        }

        public override void read__(Ice.InputStream inS__, bool rid__)
        {
            Ice.MarshalException ex = new Ice.MarshalException();
            ex.reason = "type gtr::IGtrServer was not generated with stream support";
            throw ex;
        }

        #endregion
    }
}
