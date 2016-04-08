#ifndef _GTR_MESSAGE_MANAGER_H
#define _GTR_MESSAGE_MANAGER_H

#include <string>
#include "message.h"
#include <BaseTsd.h>

using namespace std;

//���͵�Э��ֻ��Ҫ��д���л������ͼ��������ֳ�
//���յ�Э��ֻ��Ҫ��д�����л�����
//���ͺͽ��ն�Ҫ������3����������Ҫ��д

class VerifyInfo : public GtMessageBase
{
public:
	VerifyInfo()
	{																	 ;
		_type = VERIFYREQUEST;
	}
	 
	virtual ~VerifyInfo(){}
	std::string NO;				// ���׵���
	std::string Account;		// �����˺�
	std::string Password;		// ��������
	std::string Area;			// ���Ҵ���
	std::string Server;			// ����С��
	std::string SellerActor;	// ���ҽ�ɫ
	int			Level;			// ��ɫ�ȼ�
	UINT64		Money;			// ���׽��
	int			Verifytime;		// ��֤ʣ��ʱ��
	std::string	SellerSecondPwd;// ����2������
	int			SellerIndex;	// ���ҽ�ɫ���
	int			SellerGroup;	// ������Ӫ
	std::string BankPwd;		// Ǯׯ����
	int			GameId;			// ��ǰ��Ϸid

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
	std::string NO;				// ���׵���
	std::string Account;		// �����˺�
	std::string Password;		// ��������
	std::string Area;			// ���Ҵ���
	std::string Server;			// ����С��
	std::string SellerActor;	// ���ҽ�ɫ
	int			SellerLevel;	// ���ҵȼ�
	UINT64		Money;			// ���׽��
	int			TransactionTime;// ����ʣ��ʱ��
	std::string SellerSecondPwd;// ����2������
	std::string BuyerActor;		// ��ҽ�ɫ
	int			BuyerLevel;		// ��ҵȼ�
	UINT64		BuyerMoney;		// ������
	int			SellerIndex;	// �������
	int			SellerGroup;	// ������Ӫ
	std::string BankPwd;		// Ǯׯ����
	int			GameId;			// ��ǰ��Ϸid

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
	std::string NO;				// ���׵���
	std::string Account;		// �����˺�
	std::string Password;		// ��������
	std::string Area;			// ���Ҵ���
	std::string Server;			// ����С��
	std::string SellerActor;	// ���ҽ�ɫ
	std::string SellerSecondPwd;// ����2������
	int			SellerIndex;	// �������
	int			SellerGroup;	// ������Ӫ
	std::string BankPwd;		// Ǯׯ����
	int			GameId;			// ��ǰ��Ϸid

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
	string NO;					// ���׵���
	string content;				// ��֤��ʶ����
	string username;			// �������û���

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
	string NO;					// ���׵���
	string content;				// �ܱ���ʶ����
	string username;			// �������û���

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
	string key;					// ����Կ

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
	eRebotStatus m_statusVal;	// ������״̬
	bool		 telecom;		// ���Ż�����ͨ
	char		 gameversion;	// ��Ϸ�汾

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
	string NO;						// ��֤����
	eVerifyResult m_verifyResult;	// ��֤���

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
	string NO;							// ���׵���
	eTransactResult m_transactResult;	// ���׽��

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
	string NO;							// ���׻���֤����
	GtStreamBytes YZMPix;				// ��֤��ͼƬ
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
	string NO;							// ���׻���֤����
	GtStreamBytes MBKPix;				// �ܱ���ͼƬ
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
	string			gameidstream;		//�ڲ��������Ϸid��,��;�ָ�ÿ��int�͵�����
	string			gamename;			//gameid��Ӧ����Ϸ��,������³�����ʿ,��������д.
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
	string			NO;					//����
	char			Result;				//������
	string			UserName;			//�������û���
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
	string			NO;					//����
	int				Result;				//�˺���˽��
	string			AccountInfo;		//�˺���Ϣxml��ʽ,��ҪBase64���ܺ��ٷ�
	GtMessageType	getType();
	virtual GtStreamBytes	encBytes();
	virtual GtUInt32 getSize();
	virtual string toString(){ return string();}
};

#endif// _GTR_MESSAGE_MANAGER_H