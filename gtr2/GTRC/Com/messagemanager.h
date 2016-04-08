#ifndef _GTR_MESSAGE_MANAGER_H
#define _GTR_MESSAGE_MANAGER_H

#include <string>
#include "message.h"
#include <BaseTsd.h>

using namespace std;

//发送的协议只需要重写序列化函数和计算序列字长
//接收的协议只需要重写反序列化函数
//发送和接收都要的以上3个函数都需要重写

class VerifyInfo : public GtMessageBase
{
public:
	VerifyInfo()
	{																	 ;
		_type = VERIFYREQUEST;
	}
	 
	virtual ~VerifyInfo(){}
	std::string NO;				// 交易单号
	std::string Account;		// 卖家账号
	std::string Password;		// 卖家密码
	std::string Area;			// 卖家大区
	std::string Server;			// 卖家小区
	std::string SellerActor;	// 卖家角色
	int			Level;			// 角色等级
	UINT64		Money;			// 交易金币
	int			Verifytime;		// 验证剩余时间
	std::string	SellerSecondPwd;// 卖家2级密码
	int			SellerIndex;	// 卖家角色序号
	int			SellerGroup;	// 卖家阵营
	std::string BankPwd;		// 钱庄密码
	int			GameId;			// 当前游戏id

	GtMessageType	getType();
	virtual bool parse(GtByte* data,GtUInt32 size);
	virtual string toString();
};

class TransactionInfo : public GtMessageBase
{
public:
	TransactionInfo()
	{
		_type = TRANSACTREQUEST;
	}
	virtual ~TransactionInfo(){}
	std::string NO;				// 交易单号
	std::string Account;		// 卖家账号
	std::string Password;		// 卖家密码
	std::string Area;			// 卖家大区
	std::string Server;			// 卖家小区
	std::string SellerActor;	// 卖家角色
	int			SellerLevel;	// 卖家等级
	UINT64		Money;			// 交易金币
	int			TransactionTime;// 交易剩余时间
	std::string SellerSecondPwd;// 卖家2级密码
	std::string BuyerActor;		// 买家角色
	int			BuyerLevel;		// 买家等级
	UINT64		BuyerMoney;		// 买金币数
	int			SellerIndex;	// 卖家序号
	int			SellerGroup;	// 卖家阵营
	std::string BankPwd;		// 钱庄密码
	int			GameId;			// 当前游戏id

	GtMessageType	getType();
	virtual bool parse(GtByte* data,GtUInt32 size);
	virtual string toString();
};

class AccountVerifyInfo : public GtMessageBase
{
public:
	AccountVerifyInfo()
	{
		_type = ACCOUNTVERIFYREQUEST;
	}
	virtual ~AccountVerifyInfo(){}
	std::string NO;				// 交易单号
	std::string Account;		// 卖家账号
	std::string Password;		// 卖家密码
	std::string Area;			// 卖家大区
	std::string Server;			// 卖家小区
	std::string SellerActor;	// 卖家角色
	std::string SellerSecondPwd;// 卖家2级密码
	int			SellerIndex;	// 卖家序号
	int			SellerGroup;	// 卖家阵营
	std::string BankPwd;		// 钱庄密码
	int			GameId;			// 当前游戏id

	GtMessageType	getType();
	virtual bool parse(GtByte* data,GtUInt32 size);
	virtual string toString();
};

class YZMContent : public GtMessageBase
{
public:
	YZMContent()
	{
		_type = YZMCONTENT;
	}
	virtual ~YZMContent(){}
	string NO;					// 交易单号
	string content;				// 验证码识别结果
	string username;			// 答题者用户名

	GtMessageType	getType();
	virtual bool parse(GtByte* data,GtUInt32 size);
	virtual string toString();
};

class MBKContent : public GtMessageBase
{
public:
	MBKContent()
	{
		_type = MBKCONTENT;
	}
	virtual ~MBKContent(){}
	string NO;					// 交易单号
	string content;				// 密保卡识别结果
	string username;			// 答题者用户名

	GtMessageType	getType();
	virtual bool parse(GtByte* data,GtUInt32 size);
	virtual string toString();
};

class DecryptionKey :public GtMessageBase
{
public:
	DecryptionKey()
	{
		_type = DECRYPTIONKEY;
	}
	virtual ~DecryptionKey(){}
	string key;					// 解密钥

	GtMessageType	getType();
	virtual bool parse(GtByte* data,GtUInt32 size);
	virtual string toString();
};

class RobotStatus : public GtMessageBase
{
public:
	RobotStatus()
	{
		_type = ROBOTSTATUS;
	}
	virtual ~RobotStatus(){}
	eRebotStatus m_statusVal;	// 机器人状态
	bool		 telecom;		// 电信还是网通
	char		 gameversion;	// 游戏版本

	GtMessageType			getType();
	virtual GtStreamBytes	encBytes();
	virtual GtUInt32 getSize();
	virtual string toString();
};

class VerifyResult : public GtMessageBase
{
public:
	VerifyResult()
	{
		_type = VERIFYRESULT;
	}
	virtual ~VerifyResult(){}
	string NO;						// 验证单号
	eVerifyResult m_verifyResult;	// 验证结果

	GtMessageType	getType();
	virtual GtStreamBytes	encBytes();
	virtual GtUInt32 getSize();
	virtual string toString();
};

class TransactResult : public GtMessageBase
{
public:
	TransactResult()
	{
		_type = TRANSACTRESULT;
	}
	virtual ~TransactResult(){}
	string NO;							// 交易单号
	eTransactResult m_transactResult;	// 交易结果

	GtMessageType	getType();
	virtual GtStreamBytes	encBytes();
	virtual GtUInt32 getSize();
	virtual string toString();
};

class YZMImage : public GtMessageBase
{
public:
	YZMImage()
	{
		_type = YZMIMAGE;
	}
	virtual ~YZMImage(){}
	string NO;							// 交易或验证单号
	GtStreamBytes YZMPix;				// 验证码图片
	GtMessageType	getType();
	virtual GtStreamBytes	encBytes();
	virtual GtUInt32 getSize();
	virtual string toString();
};
class MBKImage : public GtMessageBase
{
public:
	MBKImage()
	{
		_type = MBKPOSITION;
	}
	virtual ~MBKImage(){}
	string NO;							// 交易或验证单号
	GtStreamBytes MBKPix;				// 密保卡图片
	GtMessageType	getType();
	virtual GtStreamBytes	encBytes();
	virtual GtUInt32 getSize();
	virtual string toString();
};

class RobotHeart : public GtMessageBase
{
public:
	RobotHeart()
	{
		_type = ROBOTHEART;
	}
	virtual ~RobotHeart(){}
	GtMessageType	getType();
	virtual GtStreamBytes	encBytes();
	virtual bool parse(GtByte* data,GtUInt32 size);
	virtual GtUInt32 getSize();
	virtual string toString(){ string str; return str; }
};

class RobotGameId : public GtMessageBase
{
public:
	RobotGameId()
	{
		_type = ROBOTEGAMEID;
	}
	string			gameidstream;		//内部定义的游戏id流,由;分隔每个int型的数字
	string			gamename;			//gameid对应的游戏名,比如地下城与勇士,可以随意写.
	GtMessageType	getType();
	virtual GtStreamBytes	encBytes();
	virtual GtUInt32 getSize();
	virtual string toString();
};

class AnswerResult : public GtMessageBase
{
public:
	AnswerResult()
	{
		_type = YMCONTENT_RUESULT;
	}
	string			NO;					//单号
	char			Result;				//答题结果
	string			UserName;			//答题人用户名
	GtMessageType	getType();
	virtual GtStreamBytes	encBytes();
	virtual GtUInt32 getSize();
	virtual string toString();
};

class AccountVerifyResult : public GtMessageBase
{
public:
	AccountVerifyResult()
	{
		_type = ACCOUNTRESULT;
	}
	string			NO;					//单号
	int				Result;				//账号审核结果
	string			AccountInfo;		//账号信息xml格式,需要Base64加密后再发
	GtMessageType	getType();
	virtual GtStreamBytes	encBytes();
	virtual GtUInt32 getSize();
	virtual string toString(){ return string();}
};

#endif// _GTR_MESSAGE_MANAGER_H