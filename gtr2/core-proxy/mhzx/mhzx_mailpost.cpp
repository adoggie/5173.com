#include "mhzx_mailpost.h"
#include <assert.h>

#define SAFE_TIME 120
#define MAX_GOLD 200000 * 10000

const int selectserver_trytimes = 2;
const int selectarea_trytimes = 2;
const int login_trytimes = 2;
const int inputmb_trytimes = 3;
const int selectrole_trytimes = 3;
const int sellitem_trytimes = 3;

IMPLEMENT_APP_CONSOLE(MHZX_Mailpost)

#define XLOG getLogger().Message
char buf[256];

void MHZX_Mailpost::task_MailPost(gtr::GameTaskResultT& result)
{
	XLOG("������Ϊ%s",(char*)_tasklet.no.c_str());
	XLOG("�������������Ϊ%lld",_tasklet.post.buyerMoney);
	XLOG("�������Ľ������Ϊ%lld",_tasklet.post.money);
	XLOG("�������Ϊ%s",_tasklet.post.buyerActor.c_str());
	XLOG("��������Ϊ%s",_tasklet.post.sellerActor.c_str());
	XLOG("������С����ϢΪ%s",_tasklet.server.c_str());
	XLOG("�������˺���ϢΪ%s",_tasklet.account.c_str());
	/*
	Ԥ����Ĭ�ϵķ��ؽ��
	*/
	result.result = GT_ERR_3120;
	/*
	������Ϸ
	*/
	int returnvalue = _gamectx.apilist->Begin(&_gamectx);
	if (returnvalue != GT_OK)
	{
		_gamectx.apilist->End(&_gamectx);
		XLOG("���ط������Ľ��׽��Ϊ%d",(int)result.result);
		return;
	}
	/*
	�м�Ĵ������
	*/
	run(&_gamectx,_tasklet,result);
	/*
	�ر���Ϸ
	*/
	_gamectx.apilist->End(&_gamectx);

	XLOG("���ط������Ľ��׽��Ϊ%d",(int)result.result);
}

void MHZX_Mailpost::run(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	/*
	�ж��������Ľ�������Ƿ����������Ľ������
	*/
	if( tasklet.post.money < tasklet.post.buyerMoney )
	{
		taskresult.result = GT_ERR_2030;

		XLOG("�������Ľ������С�������Ľ������");

		return;
	}

	int i;
	int returnvalue;

	/*
	ѡ��������
	*/
	for ( i = 0; i < selectserver_trytimes; ++i )
	{
		returnvalue = call->apilist->SelectServer(const_cast<char*>(tasklet.server.c_str()),call);
		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_UNABLECONNECT && i != selectserver_trytimes - 1 )
			continue;
		else if ( returnvalue == GT_UNABLECONNECT && i == selectserver_trytimes - 1 )
		{
			/*
			����ֵ�����޷�����,ת�˹�
			*/
			taskresult.result = GT_ERR_3000;
			getLogger().Message("���Ӵ���ʧ��");
			return;
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
	}

	XLOG("���Ӵ����ɹ�");

	/*
	ѡС������
	*/
	for ( i = 0; i < selectarea_trytimes; ++i )
	{
		returnvalue = call->apilist->SelectArea(const_cast<char*>(tasklet.area.c_str()),call);
		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_UNABLECONNECT && i != selectarea_trytimes - 1 )
			continue;
		else if ( returnvalue == GT_UNABLECONNECT && i == selectarea_trytimes - 1 )
		{
			/*
			����ֵС���޷�����,ת�˹�
			*/
			taskresult.result = GT_ERR_3020;
			getLogger().Message("����С��ʧ��");
			return;
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
	}

	getLogger().Message("����С���ɹ�");

	/*
	�˺ŵ�½����
	*/
	for ( i = 0; i < login_trytimes; ++i )
	{
		returnvalue = call->apilist->Login(const_cast<char*>(tasklet.account.c_str()),const_cast<char*>(tasklet.password.c_str()),call);
		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_PASSWORDERROR && i != login_trytimes - 1 )
		{
			continue;
		}
		else if ( returnvalue == GT_PASSWORDERROR && i == login_trytimes - 1 )
		{
			/*
			�����������l
			*/
			taskresult.result = GT_ERR_2000;

			XLOG("�����������");
			return;
		}
		else if ( returnvalue == GT_MBERROR && i != login_trytimes -1 )
		{
			continue;
		}
		else if ( returnvalue == GT_MBERROR && i == login_trytimes -1 )
		{
			/*
			�����ܱ��ϴ�����
			*/
			taskresult.result = GT_ERR_2090;

			XLOG("�����ܱ��ϴ�����");
			return;
		}
		else if ( returnvalue == GT_FALSE && i != login_trytimes -1 )
		{
			continue;
		}
		else if ( returnvalue == GT_FALSE && i == login_trytimes -1 )
		{
			XLOG("��Ϸ������û�����߿������ܱ������δ����˺ű���ʱ��ͣ");
			return;
		}
		else if ( returnvalue == GT_UNABLECONNECT )
		{
			taskresult.result = GT_ERR_3020;

			XLOG("�˺������޷���֤");
			return;
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
	}

	/*
	��ɫ��½
	*/
}

void MHZX_Mailpost::checkReturnvalueprocess( int returnvalue, gtr::GameTaskResultT& taskresult )
{
	if ( returnvalue == GT_OK )
	{
		assert(0);
		return;
	}
	else if ( returnvalue == GT_FALSE )
	{
		taskresult.result = GT_ERR_3120;

		XLOG("��һ������ʧ�ܵ����޷�����");
		return;
	}
	else if ( returnvalue == GT_NOTEXISTED )
	{
		taskresult.result = GT_ERR_2050;

		XLOG("��ҽ�ɫ������");
		return;
	}
	else if ( returnvalue == GT_MAIlBOXFULL )
	{
		taskresult.result = GT_ERR_3070;

		XLOG("�����������");
		return;
	}
	else if ( returnvalue == GT_MAIlBOXLOCKED )
	{
		taskresult.result = GT_ERR_2100;

		XLOG("��������Ѷ���");
		return;
	}
	else if ( returnvalue == GT_ROLEKICK )
	{
		taskresult.result = GT_ERR_3050;

		XLOG("���Ҷ���");
		return;
	}
	else if ( returnvalue == GT_TIMEOUT )
	{
		taskresult.result = GT_ERR_3120;

		XLOG("��ʱ");
		return;
	}
	else if ( returnvalue == GT_CONNECTBREAK )
	{
		taskresult.result = GT_ERR_3120;

		XLOG("�����ж�");
		return;
	}
	else if ( returnvalue == GT_UNABLEMOVETO )
	{
		taskresult.result = GT_ERR_3120;

		XLOG("�޷�����Ŀ��NPC");
		return;
	}
	else if ( returnvalue == GT_UNABLETALKTO )
	{
		taskresult.result = GT_ERR_3120;

		XLOG("�޷��Ի�Ŀ��NPC");
		return;
	}
}