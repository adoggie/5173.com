#ifndef PACKAGETYPE_H
#define PACKAGETYPE_H

enum PackageEnum
{
	// Client 2 serter.
	ROBOTSTATUS = 1,		//������״̬
	YZMIMAGE,				//��֤��
	MBKPOSITION,			//�ܱ���
	VERIFYRESULT,			//��֤���
	TRANSACTRESULT,			//���׽��
	YMCONTENT_RUESULT,		//��֤�롢�ܱ�����½��Ľ��
	ROBOTEGAMEID,			//��ǰ�����˶�Ӧ����ϷID

	// SertER 2 CLIENT.
	VERIFYREQUEST = 10,		//��֤����
	TRANSACTREQUEST,		//��������
	YZMCONTENT,				//��֤������
	MBKCONTENT,				//�ܱ�������
	DECRYPTIONKEY,			//���ܽ�

	// SERVER 2 RECOGNIZER.
	YZMINFORMATON = 20,
	MBKINFORMATON,
	LOGINRESULT,

	// RECOGNIZER 2 SERVER.
	YZMRESULT	=	30,
	MBKRESULT	=	31,
	LEAVE		=	32,
	GOBACK		=	33,
	LOGININFO	=	34,
	RECOGNIZERSTATUS = 35,

	//
	ROBOTHEART = 40,
	RECONGIZERHEART = 41,
};

enum eLoginResult
{
	LR_ACCOUNTERR = 0,
	LR_PWDERR,
	LR_ISUSING,
	LR_SUCCESS
};
#endif // PACKAGETYPE_H
