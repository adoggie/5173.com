
#include "wulin2_mailpost.h"
#include <assert.h>

using namespace std;

#define SAFE_TIME 120
#define MAX_GOLD 200000 * 10000

const int selectserver_trytimes = 2;
const int selectarea_trytimes = 2;
const int login_trytimes = 2;
const int inputmb_trytimes = 3;
const int selectrole_trytimes = 3;
const int sellitem_trytimes = 3;

IMPLEMENT_APP_CONSOLE(Wulin2_Mailpost)

//#define XLOG getLogger().Message
#define XLOG logmsg

char buf[256];

void Wulin2_Mailpost::task_MailPost(gtr::GameTaskResultT& result)
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

	if ( (result.result == GT_ERR_2030 || result.result == GT_ERR_3120) && warehouseRvalue == GT_ERR_2020 )
	{
		result.result = GT_ERR_2020;
	}

	if ( selectroleRvalue != 0 && result.result != GT_ERR_1000 )
	{
		result.result = selectroleRvalue;
	}

	XLOG("���ط������Ľ��׽��Ϊ%d",(int)result.result);
}


void Wulin2_Mailpost::run(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
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

	/*
	�ж϶����������
	*/
	if ( tasklet.post.buyerMoney > 200000 * 10000 )
	{
		XLOG("����������");
		return;
	}
	int i;
	int returnvalue;

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
			taskresult.result = GT_ERR_3020;

			XLOG("С���޷�����");
			return;
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
	}

	//XLOG("ѡС���ɹ�");

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
		else if ( returnvalue == GT_VERSIONERROR )
		{
			/*
			��Ϸ�汾����
			*/
			XLOG("��Ϸ�汾����");
			return;
		}
		else if ( returnvalue == GT_PLAYERINLINE )
		{
			/*
			�������
			*/
			XLOG("�������");
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

			XLOG("С���޷�����");
			return;
		}
		else if ( returnvalue == GT_RECOQNIZEREMPTY && i != login_trytimes -1 )
		{
			continue;
		}
		else if ( returnvalue == GT_RECOQNIZEREMPTY && i == login_trytimes -1 )
		{
			taskresult.result = GT_ERR_3160;

			XLOG("����Ա��������,���ⳬʱ,�ܱ�δ�ϴ�");
			return;
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
	}

	/*
	ѡ������
	*/
	returnvalue = call->apilist->SelectLineByName("",call);

	if ( returnvalue != GT_OK )
	{
		XLOG("ѡ��ʧ��");

		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}

	XLOG("ѡ�߳ɹ�");

	/*
	��ɫ��½ƥ������
	*/
	vector<string> rolelist;

	if ( parserolelist(rolelist) == true )
	{
		if ( rolematch(rolelist,selectroleRvalue,tasklet.post.sellerActor) == false )
		{
			taskresult.result = selectroleRvalue;
			return;
		}
	}

	/*
	ѡ��ɫ����
	*/
	for ( i = 0; i < selectrole_trytimes; ++i )
	{
		returnvalue = call->apilist->SelectRoleByName((char*)_tasklet.post.sellerActor.c_str(),call);
		if ( returnvalue == GT_OK )
		{
			break;
		}
		else if ( returnvalue == GT_NOTEXISTED && i != selectrole_trytimes -1 )
		{
		}
		else if ( returnvalue == GT_NOTEXISTED && i == selectrole_trytimes -1 )
		{
			XLOG("ѡ��ɫʧ��");

			taskresult.result = GT_ERR_2010;
			return;
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
	}

	XLOG("ѡ��ɫ�ɹ�");

	/*
	��ȫʱ����
	*/
	int safetime;
	call->apilist->QuerySafeTime(&safetime,call);
	if ( safetime >= SAFE_TIME )
	{
		/*
		����ֵΪ��ȫʱ�����2���ӣ�ת�˹�
		*/
		taskresult.result = GT_ERR_3030;

		XLOG("��ȫʱ�����2����");
		return;
	}

	XLOG("��ȫʱ��С��2����");
	/*
	��ѯ�������
	*/
	returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)WULIN2_GOLD,&baggold,call);
	if ( returnvalue != GT_OK )
	{
		XLOG("��ѯ�������ʧ��");

		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}

	XLOG("��1�β�ѯ�������Ϊ%d",baggold);


	/*
	ʹ�ûس���Ʒ���سǼ���
	*/
	backhomeSkillprocess(call,tasklet,taskresult);

	/*
	�����н�ҵ�λ�ǽ�
	��ȡ�Ľ�ҵ�λ��ͭ
	1�� = 100�� = 10000ͭ
	*/
	if ( baggold >= calculate_buyermoney() )
	{
		XLOG("��ұ�����ұ�����������");

		sendMailprocess(call,tasklet,taskresult);
		return;
	}

	XLOG("��ұ�����ұ�����������");

	/*
	�ж϶����������
	*/
	if ( tasklet.post.buyerMoney > 190000 * 10000 )
	{
		XLOG("������ҳ���19��");
		return;
	}

	/*
	��ѯ��������,���,��ש����
	*/

	returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)goldingot.itemtype,	&goldingot.itemnum,		call);
	if ( returnvalue != GT_OK )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}
	returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)goldbullion.itemtype,&goldbullion.itemnum,	call);
	if ( returnvalue != GT_OK )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}
	returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)goldbrick.itemtype,	&goldbrick.itemnum,		call);
	if ( returnvalue != GT_OK )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}

	XLOG("��ұ����ڽ�������Ϊ%d",(int)goldingot.itemnum);
	XLOG("��ұ����ڽ������Ϊ%d",(int)goldbullion.itemnum);
	XLOG("��ұ����ڽ�ש����Ϊ%d",(int)goldbrick.itemnum);

	if ( calculate_allinbag() >= calculate_buyermoney() )
	{
		XLOG("��ұ�����Ҽ�����Ʒ��ֵ������������");
		sellItemprocess(call,tasklet,taskresult);
		return;
	}

	XLOG("��ұ�����Ҽ�����Ʒ��ֵ������������");
	/*
	��⵱ǰ��ͼ�Ƿ�Ϊ������
	*/
	returnvalue = call->apilist->IsInMap(MAP_QIXIAZHEN,call);
	if ( returnvalue == GT_FALSE )
	{
		XLOG("��Ҳ���������");
		/*
		��鱳������Ƿ����㴫�ͷ�
		*/
		if ( baggold < 1000 )
		{
			XLOG("��ұ�����Ҳ������ͷ�");
			return;
		}

		/*
		�ƶ�������NPC
		*/
		returnvalue = call->apilist->MoveToByNpcID(NPC_CONVEY,call);
		if ( returnvalue != GT_OK )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
		/*
		�Ի�����NPC
		*/
		returnvalue = call->apilist->Talk(NPC_CONVEY,call);
		if ( returnvalue != GT_OK )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
		/*
		ʹ�ô��͹���
		*/
		returnvalue = call->apilist->Transport(MAP_QIXIAZHEN,call);
		if ( returnvalue != GT_OK )
		{
			XLOG("���͵�������ʧ��");
			if( returnvalue == GT_FALSE )
			{
				taskresult.result = GT_ERR_3040;
				return;
			}
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
		XLOG("���͵�������ɹ�");
	}

	/*
	�жϲֿ�NPC�Ƿ��ڸ���
	*/
	/*
	��ʱ�޸�
	*/
	returnvalue = GT_OK;
	//returnvalue = call->apilist->IsExistNPC(NPC_WAREHOUSE,call);
	if ( returnvalue == GT_OK )
	{
		XLOG("��⵽�ֿ�NPC");
		/*
		�ƶ����ֿ�NPC
		*/
		returnvalue = call->apilist->MoveToByNpcID(NPC_WAREHOUSE,call);
		if ( returnvalue != GT_OK )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}

		XLOG("�ƶ����ֿ�NPC�ɹ�");
		/*
		��ֿ�NPC�Ի�
		*/
		returnvalue = call->apilist->Talk(NPC_WAREHOUSE,call);
		if ( returnvalue != GT_OK )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}

		XLOG("��ֿ�NPC�Ի��ɹ�");
		/*
		�򿪲ֿ�
		*/
		returnvalue = call->apilist->OpenWarehouse((char*)tasklet.post.sellerSecondPwd.c_str(),call);
		realSecondPwd = tasklet.post.sellerSecondPwd;
		if ( returnvalue != GT_OK )
		{
			XLOG("�򿪲ֿ�ʧ��ʹ�ÿ������ٳ���һ��");
			returnvalue = call->apilist->OpenWarehouse("",call);
			realSecondPwd = "";
		}
		if ( returnvalue == GT_OK )
		{
			XLOG("����ṩ��2��������ȷ");
			INT64 warehousegold,withdrawgold;
			/*
			��ѯ�������
			*/
			returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)WULIN2_GOLD,&baggold,call);
			if ( returnvalue != GT_OK )
			{
				checkReturnvalueprocess( returnvalue , taskresult);
				return;
			}
			/*
			��ѯ�ֿ��ڽ��
			*/
			returnvalue = call->apilist->QueryItemsInWarehouse((Gt_GameItemT)WULIN2_GOLD,&warehousegold,call);
			if ( returnvalue != GT_OK )
			{
				checkReturnvalueprocess( returnvalue , taskresult);
				return;
			}
			if ( returnvalue == GT_OK )
			{
				XLOG("�ֿ��ڽ��Ϊ%d",(int)warehousegold);
				if ( calculate_allinbag() + warehousegold >= calculate_buyermoney() )
				{
					withdrawgold = calculate_buyermoney() - calculate_allinbag();
					returnvalue = call->apilist->WithdrawItemsInWarehouse((Gt_GameItemT)WULIN2_GOLD,&withdrawgold,call);
					if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
					{
						checkReturnvalueprocess( returnvalue , taskresult);
						return;
					}
					returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)WULIN2_GOLD,&baggold,call);
					if ( returnvalue != GT_OK )
					{
						checkReturnvalueprocess( returnvalue , taskresult);
						return;
					}
					XLOG("ȡ�ֿ��Һ󱳰��ڽ������Ϊ%d",(int)baggold);
					if ( baggold >= calculate_buyermoney() )
					{
						sendMailprocess(call,tasklet,taskresult);
						return;
					}
					else if ( calculate_allinbag() >= calculate_buyermoney() )
					{
						sellItemprocess(call,tasklet,taskresult);
						return;
					}
					else
						assert(0);
				}
				else
				{
					withdrawgold = warehousegold;
					returnvalue = call->apilist->WithdrawItemsInWarehouse((Gt_GameItemT)WULIN2_GOLD,&withdrawgold,call);
					if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
					{
						checkReturnvalueprocess( returnvalue , taskresult);
						return;
					}
					returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)WULIN2_GOLD,&baggold,call);
					if ( returnvalue != GT_OK )
					{
						checkReturnvalueprocess( returnvalue , taskresult);
						return;
					}
					XLOG("ȡ�ֿ��Һ󱳰��ڽ������Ϊ%d",(int)baggold);
					XLOG("�����ڽ��û�����㶩������");
				}
			}
			/*
			��ѯ����ȡ�ֿ��ڽ���,��ש,�������
			*/
			INT64 warehousegoldingot = 0;
			INT64 warehousegoldbullion = 0;
			INT64 warehousegoldbrick = 0;
			returnvalue = call->apilist->QueryItemsInWarehouse((Gt_GameItemT)goldingot.itemtype,		&warehousegoldingot,		call);
			if ( returnvalue != GT_OK )
			{
				checkReturnvalueprocess( returnvalue , taskresult);
				return;
			}
			returnvalue = call->apilist->QueryItemsInWarehouse((Gt_GameItemT)goldbullion.itemtype,	&warehousegoldbullion,		call);
			if ( returnvalue != GT_OK )
			{
				checkReturnvalueprocess( returnvalue , taskresult);
				return;
			}
			returnvalue = call->apilist->QueryItemsInWarehouse((Gt_GameItemT)goldbrick.itemtype,		&warehousegoldbrick,		call);
			if ( returnvalue != GT_OK )
			{
				checkReturnvalueprocess( returnvalue , taskresult);
				return;
			}

			XLOG("��Ҳֿ��ڽ�������Ϊ%d",(int)warehousegoldingot);
			XLOG("��Ҳֿ��ڽ������Ϊ%d",(int)warehousegoldbullion);
			XLOG("��Ҳֿ��ڽ�ש����Ϊ%d",(int)warehousegoldbrick);

			returnvalue = call->apilist->WithdrawItemsInWarehouse((Gt_GameItemT)goldingot.itemtype,	&warehousegoldingot,		call);
			if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
			{
				checkReturnvalueprocess( returnvalue , taskresult);
				return;
			}
			returnvalue = call->apilist->WithdrawItemsInWarehouse((Gt_GameItemT)goldbullion.itemtype,	&warehousegoldbullion,		call);
			if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
			{
				checkReturnvalueprocess( returnvalue , taskresult);
				return;
			}
			returnvalue = call->apilist->WithdrawItemsInWarehouse((Gt_GameItemT)goldbrick.itemtype,	&warehousegoldbrick,		call);
			if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
			{
				checkReturnvalueprocess( returnvalue , taskresult);
				return;
			}

			returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)goldingot.itemtype,	&goldingot.itemnum,		call);
			if ( returnvalue != GT_OK )
			{
				checkReturnvalueprocess( returnvalue , taskresult);
				return;
			}
			returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)goldbullion.itemtype,	&goldbullion.itemnum,	call);
			if ( returnvalue != GT_OK )
			{
				checkReturnvalueprocess( returnvalue , taskresult);
				return;
			}
			returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)goldbrick.itemtype,	&goldbrick.itemnum,		call);
			if ( returnvalue != GT_OK )
			{
				checkReturnvalueprocess( returnvalue , taskresult);
				return;
			}

			XLOG("ȡ��ֿ�����Ʒ����ұ����ڽ�������Ϊ%d",(int)goldingot.itemnum);
			XLOG("ȡ��ֿ�����Ʒ����ұ����ڽ������Ϊ%d",(int)goldbullion.itemnum);
			XLOG("ȡ��ֿ�����Ʒ����ұ����ڽ�ש����Ϊ%d",(int)goldbrick.itemnum);

			if ( baggold >= calculate_buyermoney() )
			{
				sendMailprocess(call,tasklet,taskresult);
				return;
			}
			else if ( calculate_allinbag() >= calculate_buyermoney() )
			{
				sellItemprocess(call,tasklet,taskresult);
				return;
			}

			/*
			�򿪰��ɲֿ�
			*/
			returnvalue = call->apilist->OpenExchange((char*)realSecondPwd.c_str(),call);
			if ( returnvalue != GT_OK )
			{
				XLOG("�򿪲ֿ�ʧ��ʹ�ÿ������ٳ���һ��");
				returnvalue = call->apilist->OpenExchange("",call);
			}
			if ( returnvalue == GT_OK )
			{
				XLOG("�򿪰��ɲֿ�ɹ�");
				/*
				��ѯ����ȡ���ɲֿ��ڽ���,��ש,�������
				*/
				INT64 guildgoldingot = 0;
				INT64 guildgoldbullion = 0;
				INT64 guildgoldbrick = 0;
				call->apilist->QueryItemsInExchange((Gt_GameItemT)goldingot.itemtype,		&guildgoldingot,		call);
				if ( returnvalue != GT_OK )
				{
					checkReturnvalueprocess( returnvalue , taskresult);
					return;
				}
				call->apilist->QueryItemsInExchange((Gt_GameItemT)goldbullion.itemtype,		&guildgoldbullion,		call);
				if ( returnvalue != GT_OK )
				{
					checkReturnvalueprocess( returnvalue , taskresult);
					return;
				}
				call->apilist->QueryItemsInExchange((Gt_GameItemT)goldbrick.itemtype,		&guildgoldbrick,		call);
				if ( returnvalue != GT_OK )
				{
					checkReturnvalueprocess( returnvalue , taskresult);
					return;
				}

				XLOG("��Ұ��ɲֿ��ڽ�������Ϊ%d",(int)guildgoldingot);
				XLOG("��Ұ��ɲֿ��ڽ������Ϊ%d",(int)guildgoldbullion);
				XLOG("��Ұ��ɲֿ��ڽ�ש����Ϊ%d",(int)guildgoldbrick);

				call->apilist->WithdrawItemsInExchange((Gt_GameItemT)goldingot.itemtype,	&guildgoldingot,		call);
				if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
				{
					checkReturnvalueprocess( returnvalue , taskresult);
					return;
				}
				call->apilist->WithdrawItemsInExchange((Gt_GameItemT)goldbullion.itemtype,	&guildgoldbullion,		call);
				if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
				{
					checkReturnvalueprocess( returnvalue , taskresult);
					return;
				}
				call->apilist->WithdrawItemsInExchange((Gt_GameItemT)goldbrick.itemtype,	&guildgoldbrick,		call);
				if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
				{
					checkReturnvalueprocess( returnvalue , taskresult);
					return;
				}

				call->apilist->QueryItemsInBag((Gt_GameItemT)goldingot.itemtype,	&goldingot.itemnum,		call);
				if ( returnvalue != GT_OK )
				{
					checkReturnvalueprocess( returnvalue , taskresult);
					return;
				}
				call->apilist->QueryItemsInBag((Gt_GameItemT)goldbullion.itemtype,	&goldbullion.itemnum,	call);
				if ( returnvalue != GT_OK )
				{
					checkReturnvalueprocess( returnvalue , taskresult);
					return;
				}
				call->apilist->QueryItemsInBag((Gt_GameItemT)goldbrick.itemtype,	&goldbrick.itemnum,		call);
				if ( returnvalue != GT_OK )
				{
					checkReturnvalueprocess( returnvalue , taskresult);
					return;
				}

				XLOG("ȡ����ɲֿ�����Ʒ����ұ����ڽ�������Ϊ%d",(int)goldingot.itemnum);
				XLOG("ȡ����ɲֿ�����Ʒ����ұ����ڽ������Ϊ%d",(int)goldbullion.itemnum);
				XLOG("ȡ����ɲֿ�����Ʒ����ұ����ڽ�ש����Ϊ%d",(int)goldbrick.itemnum);

				if ( baggold >= calculate_buyermoney() )
				{
					sendMailprocess(call,tasklet,taskresult);
					return;
				}
				else if ( calculate_allinbag() >= calculate_buyermoney() )
				{
					sellItemprocess(call,tasklet,taskresult);
					return;
				}
			}
			else
			{
				XLOG("�򿪰��ɲֿ�ʧ��");

				warehouseRvalue = GT_ERR_2020;
			}
		}
		else
		{
			XLOG("����ṩ��2���������");

			warehouseRvalue = GT_ERR_2020;
		}
	}
	else
	{
		XLOG("��ⲻ���ֿ�NPC");
	}

	/*
	�ж��Ƿ����
	*/
	returnvalue = GT_FALSE;
	while (!returnvalue)
	{
		returnvalue = call->apilist->IsUnlocked(call);

		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
		Sleep(1000);
	}

	XLOG("��ȫ���Ѿ�����");

	/*
	�ж�ǮׯNPC�Ƿ��ڸ���
	*/
	/*
	��ʱ�޸�
	*/
	returnvalue = GT_OK;
	//returnvalue = call->apilist->IsExistNPC(NPC_BANK,call);
	if ( returnvalue == GT_OK )
	{
		XLOG("��⵽ǮׯNPC");
		/*
		�ƶ���ǮׯNPC
		*/
		returnvalue = call->apilist->MoveToByNpcID(NPC_BANK,call);
		if ( returnvalue != GT_OK )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
		/*
		��Ǯׯnpc�Ի�
		*/
		returnvalue = call->apilist->Talk(NPC_BANK,call);
		if ( returnvalue != GT_OK )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
		/*
		��Ǯׯ
		*/
		getLogger().Message("Ǯׯ����Ϊ%s",(char*)tasklet.post.bankPwd.c_str());
		returnvalue = call->apilist->OpenBank((char*)tasklet.post.bankPwd.c_str(),call);
		//if ( returnvalue == GT_OK )
		//{
			//XLOG("�����ɹ�");
			INT64 bankgold,withdrawgold;
			/*
			��ѯǮׯ�ڽ��
			*/
			returnvalue = call->apilist->QueryItemsInBank((Gt_GameItemT)WULIN2_GOLD,&bankgold,call);
			//if ( returnvalue != GT_OK )
			//{
			//	checkReturnvalueprocess( returnvalue , taskresult);
			//	return;
			//}
			XLOG("Ǯׯ�ڽ������%d",(int)bankgold);
			if ( returnvalue == GT_OK )
			{
				INT64 oldbaggold = baggold;

				if ( calculate_allinbag() + bankgold >= calculate_buyermoney() )
				{
					withdrawgold = calculate_buyermoney() - calculate_allinbag();
					XLOG("��Ǯׯ�ڳ���ȥȡ%dǮ",(int)withdrawgold);
					returnvalue = call->apilist->WithdrawItemsInBank((Gt_GameItemT)WULIN2_GOLD,&withdrawgold,call);
					//if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
					//{
					//	checkReturnvalueprocess( returnvalue , taskresult);
					//	return;
					//}
					returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)WULIN2_GOLD,&baggold,call);
					//if ( returnvalue != GT_OK )
					//{
					//	checkReturnvalueprocess( returnvalue , taskresult);
					//	return;
					//}
					XLOG("��Ǯׯ��ȡ��Ǯ�󱳰����Ϊ%d",(int)baggold);
					if ( baggold >= calculate_buyermoney() )
					{
						sendMailprocess(call,tasklet,taskresult);
						return;
					}
					else if ( calculate_allinbag() >= calculate_buyermoney() )
					{
						sellItemprocess(call,tasklet,taskresult);
						return;
					}
				}
				else
				{
					withdrawgold = bankgold;
					XLOG("��Ǯׯ�ڳ���ȥȡ%dǮ",(int)withdrawgold);
					returnvalue = call->apilist->WithdrawItemsInBank((Gt_GameItemT)WULIN2_GOLD,&withdrawgold,call);
					//if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
					//{
					//	checkReturnvalueprocess( returnvalue , taskresult);
					//	return;
					//}
					returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)WULIN2_GOLD,&baggold,call);
					//if ( returnvalue != GT_OK )
					//{
					//	checkReturnvalueprocess( returnvalue , taskresult);
					//	return;
					//}
					XLOG("��Ǯׯ��ȡ��Ǯ�󱳰����Ϊ%d",(int)baggold);
				}

				if ( oldbaggold == baggold )
				{
					XLOG("��ǮׯȡǮ���ɹ��������������ṩ��Ǯׯ�������");

					bankRvalue = GT_ERR_2020;
				}
				else
				{
					XLOG("��ǮׯȡǮ�ɹ�");
				}
			}
			if ( baggold >= calculate_buyermoney() )
			{
				sendMailprocess(call,tasklet,taskresult);
				return;
			}
			else if ( calculate_allinbag() >= calculate_buyermoney() )
			{
				sellItemprocess(call,tasklet,taskresult);
				return;
			}
		//}
	}

	/*
	�������NPC�Ƿ��ڸ���
	*/
	/*
	��ʱ�޸�
	*/
	returnvalue = GT_OK;
	//returnvalue = call->apilist->IsExistNPC(NPC_MAILBOX,call);
	if ( returnvalue != GT_OK )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}
	/*
	�ƶ�������NPC
	*/
	returnvalue = call->apilist->MoveToByNpcID(NPC_MAILBOX,call);
	if ( returnvalue != GT_OK )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}
	/*
	������npc�Ի�
	*/
	returnvalue = call->apilist->Talk(NPC_MAILBOX,call);
	if ( returnvalue != GT_OK )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}

	/*
	ȡ��������
	*/
	INT64 mailboxgold = calculate_buyermoney() - calculate_allinbag();

	INT64 withdrawgold = mailboxgold;
	XLOG("�����Ϊ%d",(int)mailboxgold);
	returnvalue = call->apilist->IsEnoughItemsInMailbox((Gt_GameItemT)WULIN2_GOLD,&mailboxgold,call);
	XLOG("�������н������Ϊ%d",(int)mailboxgold);

	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}
	if ( returnvalue == GT_OK )
	{
		XLOG("�����е�Ǯ�㹻���%d",(int)withdrawgold);
		returnvalue = call->apilist->WithdrawItemsInMailbox((Gt_GameItemT)WULIN2_GOLD,&withdrawgold,call);
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
		returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)WULIN2_GOLD,&baggold,call);
		if ( returnvalue != GT_OK )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
		XLOG("ȡ��������Ϊ%d",(int)baggold);
		if ( baggold >= calculate_buyermoney() )
		{
			/*
			�����ʼ�
			*/
			returnvalue = call->apilist->SendMail((char*)tasklet.post.buyerActor.c_str(),(char*)configdata.sMailTitle.c_str(),(char*)configdata.sMailContent.c_str(),tasklet.post.buyerMoney - 500,call);

			if ( returnvalue == GT_OK )
			{
				XLOG("���ʼ��ɹ�");
				taskresult.result = GT_ERR_1000;

				returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)WULIN2_GOLD,&baggold,call);
				XLOG("�����ʼ��󱳰����Ϊ%d",(int)baggold);
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

				XLOG("ѡС����ʱ");
				return;
			}
			else if ( returnvalue == GT_CONNECTBREAK )
			{
				taskresult.result = GT_ERR_3120;

				XLOG("�����ж�");
				return;
			}
			else
				XLOG("����δ֪���ʼ�����");
		}
		else if ( calculate_allinbag() >= calculate_buyermoney() )
		{
			sellItemprocess(call,tasklet,taskresult);
			return;
		}
		else
		{
			XLOG("���㷢�����");

			taskresult.result = GT_ERR_2030;
		}
	}
	else
	{
		XLOG("�����е�Ǯ���㹻");

		XLOG("���㷢�����");

		taskresult.result = GT_ERR_2030;
	}
}

void Wulin2_Mailpost::sellItemprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	����ӻ�NPC�Ƿ��ڸ���
	*/
	/*
	��ʱ�޸�
	*/
	returnvalue = GT_OK;
	//returnvalue = call->apilist->IsExistNPC(NPC_GROCER,call);
	if ( returnvalue != GT_OK )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}
	/*
	�ƶ����ӻ�NPC
	*/
	returnvalue = call->apilist->MoveToByNpcID(NPC_GROCER,call);
	if ( returnvalue != GT_OK )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}
	/*
	���ӻ�npc�Ի�
	*/
	returnvalue = call->apilist->Talk(NPC_GROCER,call);
	if ( returnvalue != GT_OK )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}

	/*
	�ж��Ƿ����
	*/
	returnvalue = GT_FALSE;
	while (!returnvalue)
	{
		returnvalue = call->apilist->IsUnlocked(call);

		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
		Sleep(1000);
	}

	XLOG("��ȫ�������ɹ�");
	/*
	�������
	*/
	if ( baggold + goldbullion.itemnum * goldbullion.itemprice >= calculate_buyermoney() )
	{
		INT64 num;
		if ((calculate_buyermoney() - baggold)%goldbullion.itemprice == 0)
		{
			num = (calculate_buyermoney() - baggold)/goldbullion.itemprice;
		}
		else
		{
			num = (calculate_buyermoney() - baggold)/goldbullion.itemprice + 1;
		}

		XLOG("��������%d�����",num);

		returnvalue = call->apilist->SellItem(WULIN2_GOLDBULLION,(int)num,call);

		if ( returnvalue == GT_OK )
		{
			XLOG("�����ɹ�");
		}
		else if ( returnvalue == GT_FALSE )
		{
			XLOG("����鲻�ɹ�");
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
	}
	else
	{
		XLOG("��������%d�����",goldbullion.itemnum);
		if (goldbullion.itemnum != 0)
		{
			returnvalue = call->apilist->SellItem(WULIN2_GOLDBULLION,(int)goldbullion.itemnum,call);
			if ( returnvalue == GT_OK )
			{
				XLOG("�����ɹ�");
			}
			else if ( returnvalue == GT_FALSE )
			{
				XLOG("����鲻�ɹ�");
			}
			else
			{
				checkReturnvalueprocess( returnvalue , taskresult);
				return;
			}
		}
	}

	/*
	��ѯ������󱳰����
	*/

	returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)WULIN2_GOLD,&baggold,call);

	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}

	XLOG("������󱳰����Ϊ%d",baggold);

	/*
	�ж�������󱳰�����Ƿ񹻶�����
	*/
	if ( baggold >= calculate_buyermoney() )
	{
		sendMailprocess(call,tasklet,taskresult);
		return;
	}

	/*
	������ש
	*/
	if ( baggold + goldbrick.itemnum * goldbrick.itemprice >= calculate_buyermoney() )
	{
		INT64 num;
		if ((calculate_buyermoney() - baggold)%goldbrick.itemprice == 0)
		{
			num = (calculate_buyermoney() - baggold)/goldbrick.itemprice;
		}
		else
		{
			num = (calculate_buyermoney() - baggold)/goldbrick.itemprice + 1;
		}

		XLOG("��������%d����ש",num);

		returnvalue = call->apilist->SellItem(WULIN2_GOLDBRICK,(int)num,call);
		if ( returnvalue == GT_OK )
		{
			XLOG("����ש�ɹ�");
		}
		else if ( returnvalue == GT_FALSE )
		{
			XLOG("����ש���ɹ�");
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
	}
	else
	{
		XLOG("��������%d����ש",goldbrick.itemnum);
		if (goldbrick.itemnum != 0)
		{
			returnvalue = call->apilist->SellItem(WULIN2_GOLDBRICK,(int)goldbrick.itemnum,call);

			if ( returnvalue == GT_OK )
			{
				XLOG("����ש�ɹ�");
			}
			else if ( returnvalue == GT_FALSE )
			{
				XLOG("����ש���ɹ�");
			}
			else
			{
				checkReturnvalueprocess( returnvalue , taskresult);
				return;
			}
		}
	}

	/*
	��ѯ�����ש�󱳰����
	*/

	returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)WULIN2_GOLD,&baggold,call);

	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}

	XLOG("�����ש�󱳰����Ϊ%d",baggold);

	/*
	�ж������ש�󱳰�����Ƿ񹻶�����
	*/
	if ( baggold >= calculate_buyermoney() )
	{
		sendMailprocess(call,tasklet,taskresult);
		return;
	}

	/*
	���������
	*/
	if ( baggold + goldingot.itemnum * goldingot.itemprice >= calculate_buyermoney() )
	{
		INT64 num;
		if ((calculate_buyermoney() - baggold)%goldingot.itemprice == 0)
		{
			num = (calculate_buyermoney() - baggold)/goldingot.itemprice;
		}
		else
		{
			num = (calculate_buyermoney() - baggold)/goldingot.itemprice + 1;
		}

		XLOG("��������%d������",num);
		returnvalue = call->apilist->SellItem(WULIN2_GOLDINGOT,(int)num,call);

		if ( returnvalue == GT_OK )
		{
			XLOG("�������ɹ�");
		}
		else if ( returnvalue == GT_FALSE )
		{
			XLOG("���������ɹ�");
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
	}
	else
	{
		return;
	}
	/*
	��ѯ��������󱳰����
	*/

	returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)WULIN2_GOLD,&baggold,call);

	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}

	XLOG("��������󱳰����Ϊ%d",baggold);

	/*
	�ж���������󱳰�����Ƿ񹻶�����
	*/
	if ( baggold >= calculate_buyermoney() )
	{
		sendMailprocess(call,tasklet,taskresult);
	}
	else
		return;
}
void Wulin2_Mailpost::sendMailprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	�������NPC�Ƿ��ڸ���
	*/
	/*
	��ʱ�޸�
	*/
	returnvalue = GT_OK;
	//returnvalue = call->apilist->IsExistNPC(NPC_MAILBOX,call);
	if ( returnvalue != GT_OK )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}
	/*
	�ƶ�������NPC
	*/
	returnvalue = call->apilist->MoveToByNpcID(NPC_MAILBOX,call);
	if ( returnvalue != GT_OK )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}
	/*
	������npc�Ի�
	*/
	returnvalue = call->apilist->Talk(NPC_MAILBOX,call);
	if ( returnvalue != GT_OK )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}

	/*
	�ж��Ƿ����
	*/
	returnvalue = GT_FALSE;
	while (!returnvalue)
	{
		returnvalue = call->apilist->IsUnlocked(call);

		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
		Sleep(1000);
	}

	XLOG("��ȫ�������ɹ�");

	/*
	�����ʼ�
	*/
	returnvalue = call->apilist->SendMail((char*)tasklet.post.buyerActor.c_str(),(char*)configdata.sMailTitle.c_str(),(char*)configdata.sMailContent.c_str(),tasklet.post.buyerMoney - 500,call);

	if ( returnvalue == GT_OK )
	{
		XLOG("���ʼ��ɹ�");
		taskresult.result = GT_ERR_1000;

		returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)WULIN2_GOLD,&baggold,call);
		XLOG("�����ʼ��󱳰����Ϊ%d",(int)baggold);
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

		XLOG("ѡС����ʱ");
		return;
	}
	else if ( returnvalue == GT_CONNECTBREAK )
	{
		taskresult.result = GT_ERR_3120;

		XLOG("�����ж�");
		return;
	}
	else
		XLOG("����δ֪���ʼ�����");
	return;
}

void Wulin2_Mailpost::checkReturnvalueprocess( int returnvalue, gtr::GameTaskResultT& taskresult )
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

void Wulin2_Mailpost::backhomeSkillprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	���سǼ���
	*/
	returnvalue = call->apilist->IsExistBackHomeSkill(call);
	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}
	else if ( returnvalue == GT_TRUE )
	{
		XLOG("��Ҵ��ڻسǼ���");
		returnvalue = call->apilist->UseBackHomeSkill(call);
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
		else if( returnvalue == GT_TRUE )
		{
			XLOG("���ʹ�ûسǼ��ܳɹ�");
		}
		else
		{
			XLOG("���ʹ�ûسǼ���ʧ��");
		}
	}
	else
	{
		XLOG("��Ҳ����ڻسǼ���");
	}
}
void Wulin2_Mailpost::backhomeItemprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	���س���Ʒ
	*/
	returnvalue = call->apilist->IsExistBackHomeItem(call);
	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}
	else if ( returnvalue == GT_TRUE )
	{
		XLOG("��Ҵ��ڻس���Ʒ");
		returnvalue = call->apilist->UseBackHomeItem(call);
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
		else if( returnvalue == GT_TRUE )
		{
			XLOG("���ʹ�ûس���Ʒ�ɹ�");
		}
		else
		{
			XLOG("���ʹ�ûس���Ʒʧ��");
			backhomeSkillprocess(call,tasklet,taskresult);
		}
	}
	else
	{
		XLOG("��Ҳ����ڻس���Ʒ");
		backhomeSkillprocess(call,tasklet,taskresult);
	}
}