#include "jxsj_mailpost.h"
#include <assert.h>

using namespace std;

#define MAX_GOLD 200000 * 10000

const int selectserver_trytimes = 2;
const int selectarea_trytimes = 2;
const int login_trytimes = 2;
const int inputmb_trytimes = 3;
const int selectrole_trytimes = 3;

IMPLEMENT_APP_CONSOLE(JXSJ_Mailpost)

#define XLOG getLogger().Debug

void JXSJ_Mailpost::task_MailPost(gtr::GameTaskResultT& result)
{
	XLOG("������Ϊ%s",(char*)_tasklet.no.c_str());
	XLOG("�������������Ϊ%lld",_tasklet.post.buyerMoney);
	XLOG("�������Ľ������Ϊ%lld",_tasklet.post.money);
	XLOG("�������Ϊ%s",_tasklet.post.buyerActor.c_str());
	XLOG("��������Ϊ%s",_tasklet.post.sellerActor.c_str());
	XLOG("�����д�����ϢΪ%s",_tasklet.area.c_str());
	XLOG("������С����ϢΪ%s",_tasklet.server.c_str());
	XLOG("�������˺���ϢΪ%s",_tasklet.account.c_str());
	//XLOG("������������ϢΪ%s",_tasklet.password.c_str());

	/*
	����Ĭ�Ͻӿڳ�ʱʱ��
	*/
	_gamectx.timeout = 40000;

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
		XLOG("������Ϸʧ��");
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

	if ( specialvalue != 0 && result.result == GT_ERR_2030 )
	{
		result.result = specialvalue;
	}

	XLOG("���ط������Ľ��׽��Ϊ%d",(int)result.result);
}

void JXSJ_Mailpost::run(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
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

	int returnvalue;

	if (loginprocess(call,tasklet,taskresult)==false)
		return;

	call->timeout = 30000;

	/*
	�жϽ�ɫ�ȼ�
	*/
	int rolelevel;
	returnvalue = call->apilist->QueryRoleLevel((char*)tasklet.post.sellerActor.c_str(),&rolelevel,call);
	if ( returnvalue == GT_OK )
	{
		XLOG("���ҵȼ�Ϊ%d",rolelevel);
		INT64 maxinum = getRoleMaximumGold(rolelevel);
		XLOG("���ҵȼ���Ӧ�������Я������Ϊ%lld",maxinum);
		if ( maxinum < tasklet.post.buyerMoney )
		{
			XLOG("���ұ��������Я�����������������");

			taskresult.result = GT_ERR_3220;
			return;
		}
	}
	else
	{
		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}

	/*
	��ѯ�������
	*/
	returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)JXSJ_ITEM_GOLD,&baggold,call);
	if ( returnvalue != GT_OK )
	{
		XLOG("��ѯ�������ʧ��");

		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}

	XLOG("��ѯ�������Ϊ%lld",baggold);

	if ( baggold >= tasklet.post.buyerMoney )
	{
		XLOG("��ұ�����ұ�����������");

		sendMailprocess(call,tasklet,taskresult);
		return;
	}

	XLOG("��ұ�����ұ�����������");

	INT64 withdrawgold;

	/*
	��ѯǮׯ����Ƿ��㹻
	*/
	INT64 bankgold;
	returnvalue = call->apilist->QueryItemsInBank((Gt_GameItemT)JXSJ_ITEM_GOLD,&bankgold,call);
	if ( returnvalue != GT_OK )
	{
		XLOG("��ѯǮׯ���ʧ��");

		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}
	XLOG("Ǯׯ���н����Ϊ%lld",bankgold);
	if ( bankgold != 0 )
	{
		if ( baggold + bankgold >= tasklet.post.buyerMoney )
		{
			withdrawgold = tasklet.post.buyerMoney - baggold;
		}
		else
		{
			withdrawgold = bankgold;
		}
		XLOG("׼��ȡ���������Ϊ%lld",withdrawgold);

		returnvalue = call->apilist->WithdrawItemsInBank((Gt_GameItemT)JXSJ_ITEM_GOLD,&withdrawgold,call);
		if ( returnvalue == GT_OK )
		{
			XLOG("ǮׯȡǮ�ɹ�");
		}
		else if( returnvalue == GT_FALSE )
		{
			XLOG("ǮׯȡǮʧ��");
		}
		else if ( returnvalue == GT_BankFailed )
		{
			XLOG("ǮׯȡǮ����");
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
		returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)JXSJ_ITEM_GOLD,&baggold,call);
		if ( returnvalue != GT_OK )
		{
			XLOG("��ѯ�������ʧ��");

			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
		XLOG("ȡ��Ǯׯ��Һ�,��ѯ�������Ϊ%lld",baggold);
		if ( baggold >= tasklet.post.buyerMoney )
		{
			XLOG("��ұ�����ұ�����������");

			sendMailprocess(call,tasklet,taskresult);
			return;
		}
	}

	/*
	��ѯ����������Ƿ��㹻
	*/
	INT64 exchangegold;
	returnvalue = call->apilist->QueryItemsInExchange((Gt_GameItemT)JXSJ_ITEM_GOLD,&exchangegold,call);
	if ( returnvalue != GT_OK )
	{
		XLOG("��ѯ���������ʧ��");

		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}
	XLOG("���������н����Ϊ%lld",exchangegold);
	if( exchangegold != 0 )
	{
		if ( baggold + exchangegold >= tasklet.post.buyerMoney )
		{
			withdrawgold = tasklet.post.buyerMoney - baggold;
		}
		else
		{
			withdrawgold = exchangegold;
		}
		XLOG("׼��ȡ���������Ϊ%lld",withdrawgold);

		returnvalue = call->apilist->WithdrawItemsInExchange((Gt_GameItemT)JXSJ_ITEM_GOLD,&withdrawgold,call);
		if ( returnvalue == GT_OK )
		{
			XLOG("������ȡǮ�ɹ�");
		}
		else if( returnvalue == GT_FALSE )
		{
			XLOG("������ȡǮʧ��");
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
		returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)JXSJ_ITEM_GOLD,&baggold,call);
		if ( returnvalue != GT_OK )
		{
			XLOG("��ѯ�������ʧ��");

			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
		XLOG("ȡ�꽻������Һ�,��ѯ�������Ϊ%lld",baggold);
		if ( baggold >= tasklet.post.buyerMoney )
		{
			XLOG("��ұ�����ұ�����������");

			sendMailprocess(call,tasklet,taskresult);
			return;
		}
	}

	/*
	��ѯ�������Ƿ��㹻
	*/
	INT64 mailboxgold = tasklet.post.buyerMoney - baggold;
	returnvalue = call->apilist->IsEnoughItemsInMailbox((Gt_GameItemT)JXSJ_ITEM_GOLD,&mailboxgold,call);
	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		XLOG("��ѯ������ʧ��");

		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}
	XLOG("�������н����Ϊ%lld",mailboxgold);
	if( mailboxgold != 0 )
	{
		if ( baggold + mailboxgold >= tasklet.post.buyerMoney )
		{
			withdrawgold = tasklet.post.buyerMoney - baggold;
		}
		else
		{
			withdrawgold = mailboxgold;
		}
		XLOG("׼��ȡ���������Ϊ%lld",withdrawgold);

		returnvalue = call->apilist->WithdrawItemsInMailbox((Gt_GameItemT)JXSJ_ITEM_GOLD,&withdrawgold,call);
		if ( returnvalue == GT_OK )
		{
			XLOG("����ȡǮ�ɹ�");
		}
		else if( returnvalue == GT_FALSE )
		{
			XLOG("����ȡǮʧ��");
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
		returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)JXSJ_ITEM_GOLD,&baggold,call);
		if ( returnvalue != GT_OK )
		{
			XLOG("��ѯ�������ʧ��");

			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
		XLOG("ȡ�������Һ�,��ѯ�������Ϊ%lld",baggold);
		if ( baggold >= tasklet.post.buyerMoney )
		{
			XLOG("��ұ�����ұ�����������");

			sendMailprocess(call,tasklet,taskresult);
			return;
		}
	}

	/*
	��ѯ�ֿ���
	*/
	INT64 warehousegold;
	returnvalue = call->apilist->QueryItemsInWarehouse((Gt_GameItemT)JXSJ_ITEM_GOLD,&warehousegold,call);
	if ( returnvalue != GT_OK )
	{
		XLOG("��ѯ�ֿ���ʧ��");
		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}

	XLOG("�ֿ����н����Ϊ%lld",warehousegold);

	if ( baggold + warehousegold >= tasklet.post.buyerMoney )
	{
		/*
		�ƶ����ֿ�
		*/
		call->timeout = 50000;
		returnvalue = call->apilist->MoveToByNpcID(JXSJ_NPC_WAREHOUSE,call);
		if ( returnvalue != GT_OK )
		{
			XLOG("�ƶ����ֿ�ʧ��");
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
		else
		{
			XLOG("�ƶ����ֿ�ɹ�");

			/*
			�Ӳֿ�ȡ���
			*/
			withdrawgold = tasklet.post.buyerMoney - baggold;

			XLOG("׼��ȡ���������Ϊ%lld",withdrawgold);

			returnvalue = call->apilist->WithdrawItemsInWarehouse((Gt_GameItemT)JXSJ_ITEM_GOLD,&withdrawgold,call);
			if ( returnvalue == GT_OK )
			{
				XLOG("�ֿ�ȡǮ�ɹ�");
			}
			else if( returnvalue == GT_FALSE )
			{
				XLOG("�ֿ�ȡǮʧ��");
			}
			else
			{
				checkReturnvalueprocess(returnvalue,taskresult);
				return;
			}
			returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)JXSJ_ITEM_GOLD,&baggold,call);
			if ( returnvalue != GT_OK )
			{
				XLOG("��ѯ�������ʧ��");

				checkReturnvalueprocess(returnvalue,taskresult);
				return;
			}
			XLOG("ȡ��ֿ��Һ�,��ѯ�������Ϊ%lld",baggold);
			if ( baggold >= tasklet.post.buyerMoney )
			{
				XLOG("��ұ�����ұ�����������");

				sendMailprocess(call,tasklet,taskresult);
				return;
			}
		}
	}
	else
	{
		XLOG("��ҽ�Ҳ���");
		taskresult.result = GT_ERR_2030;
	}
}

void JXSJ_Mailpost::checkReturnvalueprocess( int returnvalue, gtr::GameTaskResultT& taskresult )
{
	if ( returnvalue == GT_OK )
	{
		assert(0);
		return;
	}
	else if ( returnvalue == GT_FALSE )
	{
		XLOG("��һ������ʧ�ܵ����޷�����");
		return;
	}
	else if ( returnvalue == GT_RECOQNIZEREMPTY )
	{
		XLOG("������������Ϊ��,��������");

		taskresult.result = GT_ERR_3160;
		return;
	}
	else if ( returnvalue == GT_DYNAMICMB )
	{
		XLOG("�н�ɽ����,ת�˹�");

		taskresult.result = GT_ERR_3010;
		return;
	}
	else if ( returnvalue == GT_MBERROR )
	{
		XLOG("�ܱ��������");

		taskresult.result = GT_ERR_2090;
		return;
	}
	else if ( returnvalue == GT_SECONDPWDERROR )
	{
		XLOG("����ṩ�Ķ����������");

		taskresult.result = GT_ERR_2020;
		return;
	}
	else if ( returnvalue == GT_PLAYERINLINE )
	{
		XLOG("��������޷���½");

		taskresult.result = GT_ERR_3210;
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
		taskresult.result = GT_ERR_3190;

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
	else if ( returnvalue == GT_NoGoods )
	{
		XLOG("û����Ʒ(��Ҫʹ����Ʒʱ)");

		taskresult.result = GT_ERR_3040;
		return;
	}
	else if ( returnvalue == GT_NpcNotFind )
	{
		XLOG("�Ҳ���npc");
		return;
	}
	else if ( returnvalue == GT_OpenNpcFail )
	{
		XLOG("��ncpʧ��");
		return;
	}
	else if ( returnvalue == GT_NotEnoughMoney )
	{
		XLOG("��������");
		return;
	}
	else if ( returnvalue == GT_PlayerOffline )
	{
		XLOG("��Ҳ�����(�Է������߼Ӳ��˺���)");

		taskresult.result = GT_ERR_3200;
		return;
	}
	else if ( returnvalue == GT_AddFriendTimeout )
	{
		XLOG("�Ӻ��ѳ�ʱ");

		taskresult.result = GT_ERR_3200;
		return;
	}
	else if ( returnvalue == GT_GetMapNameFail )
	{
		XLOG("��ȡ��ͼ����ʧ��");
		return;
	}
	else if ( returnvalue == GT_GameUncontrollable )
	{
		XLOG("��Ϸ���ɿ�(sendmessage��ʱ,����game����,Ӧ������Ϸ)");
		return;
	}
	else if( returnvalue == GT_MBOnLimit )
	{
		XLOG("�ܱ���������ﵽ����");
		return;
	}
	else if ( returnvalue == GT_AddFriendOffline )
	{
		XLOG("�Ӻ��Ѷ�����");
		return;
	}
	else
		XLOG("����δ֪����%d",returnvalue);
}

void JXSJ_Mailpost::sendMailprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;

	call->timeout = 180000;

	sendmailgold = baggold;
	/*
	�����ʼ�
	*/
	returnvalue = call->apilist->SendMail((char*)tasklet.post.buyerActor.c_str(),(char*)configdata.sMailTitle.c_str(),(char*)configdata.sMailContent.c_str(),tasklet.post.buyerMoney - 500,call);

	switch ( returnvalue )
	{
	case GT_OK:
		{
			XLOG("���ʼ��ɹ�");
			taskresult.result = GT_ERR_1000;

			returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)JXSJ_ITEM_GOLD,&baggold,call);
			XLOG("�����ʼ��󱳰����Ϊ%d",(int)baggold);
		}
		break;
	case GT_TIMEOUT:
		{
			XLOG("���ʼ���ʱ");
			restartprocess(call,tasklet,taskresult);
		}
		break;
	case GT_CONNECTBREAK:
		{
			XLOG("���ʼ�ʱ�������ж�");
			restartprocess(call,tasklet,taskresult);
		}
		break;
	case GT_GameUncontrollable:
		{
			XLOG("���ʼ�ʱ����Ϸ����");
			restartprocess(call,tasklet,taskresult);
		}
		break;
	default:
		{
			checkReturnvalueprocess(returnvalue,taskresult);
		}
		break;
	}
}

char* JXSJ_Mailpost::core_auth_image(Gt_CallContext* ctx,Gt_ImageTypeT imagetype,char* imagedata,int size,int width,int height)
{
	if ( ctx->xtype == -1 )
	{
		return (char*)_tasklet.post.sellerSecondPwd.c_str();
	}

	if ( ctx->xtype == 1 )
	{
		XLOG("���ܱ�����");
		XLOG("�ܱ�������%s",imagedata);
		XLOG("�ܱ������ݳ���%d",size);
	}

	static std::string secret;
	gtr::QuestionContentT data;

	data.type = ctx->xtype;	
	data.image.type = (int)imagetype;
	data.image.width = width;
	data.image.height = height;
	data.image.bytes.resize(size);
	memcpy(&data.image.bytes[0],imagedata,size);

	try{
		secret = _serverPrx->answer(data);
	}	catch(...){

	}
	XLOG("�ܱ������ؽ��Ϊ%s",(char*)secret.c_str());
	return (char*)secret.c_str();
}

void JXSJ_Mailpost::checksendMailprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	��ѯ�������
	*/
	returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)JXSJ_ITEM_GOLD,&baggold,call);
	XLOG("�ʼ������쳣���:�������%d",(int)baggold);
	if( baggold == sendmailgold )
	{
		XLOG("�ʼ������쳣���:��������ʼ����ɹ�");

		taskresult.result = GT_ERR_3120;
		return;
	}
	else
	{
		XLOG("�ʼ������쳣���:��������ʼ��ɹ�");
		taskresult.result = GT_ERR_1000;
		return;
	}
}

bool JXSJ_Mailpost::loginprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int i;
	int returnvalue;

	/*
	ѡ��������
	*/
	for ( i = 0; i < selectserver_trytimes; ++i )
	{
		returnvalue = call->apilist->SelectServer(const_cast<char*>(tasklet.area.c_str()),call);
		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_FALSE && i != selectserver_trytimes - 1 )
			continue;
		else if ( returnvalue == GT_FALSE && i == selectserver_trytimes - 1 )
		{
			/*
			����ֵ�����޷�����,ת�˹�
			*/
			taskresult.result = GT_ERR_3000;
			getLogger().Message("���Ӵ���ʧ��");
			return false;
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return false;
		}
	}

	XLOG("���Ӵ����ɹ�");

	/*
	ѡС������
	*/
	for ( i = 0; i < selectarea_trytimes; ++i )
	{
		returnvalue = call->apilist->SelectArea(const_cast<char*>(tasklet.server.c_str()),call);
		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_FALSE && i != selectarea_trytimes - 1 )
			continue;
		else if ( returnvalue == GT_FALSE && i == selectarea_trytimes - 1 )
		{
			/*
			����ֵС���޷�����,ת�˹�
			*/
			taskresult.result = GT_ERR_3020;
			XLOG("����С��ʧ��");
			return false;
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return false;
		}
	}

	XLOG("����С���ɹ�");

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
			return false;
		}
		else if ( returnvalue == GT_FALSE && i != login_trytimes -1 )
		{
			continue;
		}
		else if ( returnvalue == GT_FALSE && i == login_trytimes -1 )
		{
			XLOG("δ֪��½����");
			return false;
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return false;
		}
	}

	XLOG("�˺ŵ�½�ɹ�");

	/*
	��ɫ��½ƥ������
	*/
	vector<string> rolelist;

	if ( parserolelist(rolelist) == true )
	{
		if ( rolematch(rolelist,specialvalue,tasklet.post.sellerActor) == false )
		{
			taskresult.result = specialvalue;
			return false;
		}
	}

	/*
	��ɫ��½
	*/
	for ( i = 0; i < selectrole_trytimes; ++i )
	{
		returnvalue = call->apilist->SelectRoleByName((char*)tasklet.post.sellerActor.c_str(),call);
		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_NOTEXISTED && i != selectrole_trytimes - 1 )
			continue;
		else if ( returnvalue == GT_NOTEXISTED && i == selectrole_trytimes - 1 )
		{
			taskresult.result = GT_ERR_2010;

			XLOG("�޽�ɫ");
			return false;
		}
		else if ( returnvalue == GT_FALSE && i != selectrole_trytimes - 1 )
			continue;
		else if ( returnvalue == GT_FALSE && i == selectrole_trytimes - 1 )
		{
			taskresult.result = GT_ERR_2010;

			XLOG("�޽�ɫ");
			return false;
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return false;
		}
	}

	XLOG("��ɫ%s��½�ɹ�",(char*)tasklet.post.sellerActor.c_str());

	return true;
}

void JXSJ_Mailpost::restartprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	call->apilist->End(call);

	/*
	������Ϸ
	*/
	int returnvalue = _gamectx.apilist->Begin(&_gamectx);
	if (returnvalue != GT_OK)
	{
		_gamectx.apilist->End(&_gamectx);
		return;
	}

	if (loginprocess(call,tasklet,taskresult))
	{
		checksendMailprocess(call,tasklet,taskresult);
	}
}

INT64 JXSJ_Mailpost::getRoleMaximumGold( int level )
{
	if ( level >=1 && level <= 9 )
		return 100000;
	else if ( level >= 10 && level <= 19 )
		return 300000;
	else if ( level >= 20 && level <= 29 )
		return 1000000;
	else if ( level >= 30 && level <= 39 )
		return 3000000;
	else if ( level >= 40 && level <= 49 )
		return 10000000;
	else if ( level >= 50 && level <= 59 )
		return 30000000;
	else if ( level >= 60 && level <= 69 )
		return 50000000;
	else if ( level >= 70 && level <= 79 )
		return 100000000;
	else if ( level >= 80 && level <= 89 )
		return 200000000;
	else if ( level >= 90 && level <= 99 )
		return 300000000;
	else if ( level >= 100 && level <= 109 )
		return 500000000;
	else if ( level >= 110 && level <= 119 )
		return 1000000000;
	else if ( level >= 120 )
		return 2000000000;
	else
		return 0;
}