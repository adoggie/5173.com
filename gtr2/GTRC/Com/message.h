#ifndef _GTR_MESSAGE_H
#define _GTR_MESSAGE_H

#include "gtr_base.h"


//�����
enum GtMessageType{
	// Client 2 server.
	ROBOTSTATUS = 1,			//������״̬
	YZMIMAGE,					//��֤��
	MBKPOSITION,				//�ܱ���
	VERIFYRESULT,				//��֤���
	TRANSACTRESULT,				//���׽��
	YMCONTENT_RUESULT,			//��֤�롢�ܱ�����½��Ľ��
	ROBOTEGAMEID,				//��ǰ�����˶�Ӧ����ϷID
	ACCOUNTRESULT,				//�˺���֤���

	// SERVER 2 CLIENT.
	VERIFYREQUEST = 10,		//��֤����
	TRANSACTREQUEST,		//��������
	YZMCONTENT,				//��֤������
	MBKCONTENT,				//�ܱ�������
	DECRYPTIONKEY,			//���ܽ�
	ACCOUNTVERIFYREQUEST,	//�˺���֤����

	// SERVER 2 RECOGNIZER.
	YZMINFORMATON = 20,
	MBKINFORMATON,

	// RECOGNIZER 2 SERVER.
	YZMRESULT = 30,
	MBKRESULT,
	//
	ROBOTHEART = 40,
};

//������״̬
enum eRebotStatus{
	RS_FREE,
	RS_UNKNOW,
	RS_VERIFY,
	RS_TRANSACT,
};

//��֤״̬
enum eVerifyResult{
	VR_VERIFYSUCCESS = 10,				//�ɹ�
	VR_ACCOUNTERROR,					//�˺Ż��������
	VR_ACTORUNAVAILABLE,				//�˺����ִ���
	VR_LEVELERROR,						//��ɫ�ȼ�����
	VR_MONEYERROR,						//��Ҵ���
	VR_UNKNOW,							//δ֪����
	VR_NEEDSHMB = 17,					//��Ҫ�ֻ��ܱ�
	VR_NEEDDTMB,						//��Ҫ��̬�ܱ�
};

enum eTransactResult
{
	TR_TRANSACTSUCCESS = 1,				//���׳ɹ�
	TR_MANUALHANDLE,					//�˹�����
	TR_BUYERCANCEL,						//���ȡ��
	TR_SELLERCANCEL,					//����ȡ��
	TR_UNKNOW
};

enum eYMContentResult
{
	YMR_VERIFYCODEERROT,			//��֤�����
	YMR_MBKCODEERROR,				//�ܱ�������
};


class GtMessageBase{
public:	
	GtMessageBase(){}
	virtual ~GtMessageBase(){}
	virtual GtMessageType	getType() = 0;								//��ȡ������
	virtual GtStreamBytes	encBytes()									//���г��ֽ���
	{
		GtStreamBytes gtstr;
		return gtstr;
	}
	virtual bool parse(GtByte* data,GtUInt32 size){return true;}		//�����ֽ������ṹ
	virtual GtUInt32 getSize(){return 0;}								//�������г��ֽڵĴ�С
	virtual std::string toString() = 0;
protected:
	GtMessageType	_type;
};





#endif

