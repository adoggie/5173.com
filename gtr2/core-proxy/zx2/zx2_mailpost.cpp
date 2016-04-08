
#include "zx2_mailpost.h"
#include <assert.h>

#define SAFE_TIME 120

const int selectserver_trytimes = 2;
const int selectarea_trytimes = 2;
const int login_trytimes = 3;
const int inputmb_trytimes = 3;
const int selectrole_trytimes = 3;

#if NDEBUG

IMPLEMENT_APP_CONSOLE(ZX2_Mailpost)
swlib::swLogger& appLogger()
{
	return wxGetApp().getLogger();
}

#endif

#define TIMEOUT_5 5000
#define TIMEOUT_15 15000
#define TIMEOUT_120 120000

//#define XLOG getLogger().Message
#define XLOG logmsg

bool ZX2_Mailpost::isTimeout()
{
	time_t tmNow = time(NULL);
	double diff = difftime(tmNow, _tmStart);
	if(diff > 180)
	{
		throw(robot_error(GT_ERR_3120, "���������г�ʱ(��ʱ����180��)"));
		return true;
	}
	return false;
}

void ZX2_Mailpost::task_MailPost(gtr::GameTaskResultT& result)
{
	_tmStart = time(NULL);

	XLOG("������Ϊ%s",(char*)_tasklet.no.c_str());
	XLOG("�������������Ϊ%lld",_tasklet.post.buyerMoney);
	XLOG("�������Ľ������Ϊ%lld",_tasklet.post.money);
	XLOG("�������Ϊ%s",_tasklet.post.buyerActor.c_str());
	XLOG("��������Ϊ%s",_tasklet.post.sellerActor.c_str());
	XLOG("�����д�����ϢΪ%s",_tasklet.area.c_str());
	XLOG("������С����ϢΪ%s",_tasklet.server.c_str());
	XLOG("�������˺���ϢΪ%s",_tasklet.account.c_str());


	for(int i=0; i<2; i++)
	{
		if( task_process(result) )
			break;
	}

	if ( (result.result == GT_ERR_2030 || result.result == GT_ERR_3120) && warehouseRvalue == GT_ERR_2020 )
	{
		result.result = GT_ERR_2020;
	}

	XLOG("���ط������Ľ��׽��Ϊ%d",(int)result.result);
}

bool ZX2_Mailpost::task_process(gtr::GameTaskResultT& result)
{
	bool ret = true;

	/*
	������Ϸ
	*/
	_gamectx.apilist->Begin(&_gamectx);

	try
	{
		/*
		�м�Ĵ������
		*/
		run(&_gamectx,_tasklet,result);
	}
	catch (robot_error e)
	{
		result.result = GT_ERR_3120;

		if(e.ret==GT_CONNECTBREAK)
		{
			ret = false;
		}
	}
	catch (...)
	{
		
	}

	/*
	�ر���Ϸ
	*/
	_gamectx.apilist->End(&_gamectx);

	return ret;

}

void ZX2_Mailpost::run(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	call->timeout = TIMEOUT_120;
	/*
	Ԥ����Ĭ�ϵķ��ؽ��
	*/
	taskresult.result = GT_ERR_3120;

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
	ѡ��������
	*/
	for ( i = 0; i < selectarea_trytimes; ++i )
	{
		isTimeout();
		returnvalue = call->apilist->SelectArea(const_cast<char*>(tasklet.area.c_str()),call);
		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_UNABLECONNECT && i != selectarea_trytimes - 1 )
			continue;
		else if ( returnvalue == GT_UNABLECONNECT && i == selectarea_trytimes - 1 )
		{
			/*
			����ֵ�����޷�����,ת�˹�
			*/
			taskresult.result = GT_ERR_3000;
			XLOG("���Ӵ���ʧ��");
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
	for ( i = 0; i < selectserver_trytimes; ++i )
	{
		isTimeout();
		returnvalue = call->apilist->SelectServer(const_cast<char*>(tasklet.server.c_str()),call);
		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_UNABLECONNECT && i != selectserver_trytimes - 1 )
			continue;
		else if ( returnvalue == GT_UNABLECONNECT && i == selectserver_trytimes - 1 )
		{
			/*
			����ֵС���޷�����,ת�˹�
			*/
			taskresult.result = GT_ERR_3020;
			XLOG("����С��ʧ��");
			return;
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
	}

	XLOG("����С���ɹ�");

	/*
	�˺ŵ�½����
	*/
	for ( i = 0; i < login_trytimes; ++i )
	{
		isTimeout();
		returnvalue = call->apilist->Login(const_cast<char*>(tasklet.account.c_str()),const_cast<char*>(tasklet.password.c_str()),call);

		getLogger().Message("�ܱ�����ʱ����%d��", _mbkTimeout);
		if(_mbkTimeout==2)
		{
			XLOG("�ܱ�����ʱ2��");
			taskresult.result = GT_ERR_3120;
			return;
		}

		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_PASSWORDERROR && i != login_trytimes - 1 )
		{
			XLOG("��%d�ε�¼���������", i + 1);
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
			XLOG("��%d���ܱ�������", i + 1);
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
			XLOG("��%d�ε�¼ʧ��", i + 1);
			continue;
		}
		else if ( returnvalue == GT_FALSE && i == login_trytimes -1 )
		{
			XLOG("��Ϸ������û�����߿������ܱ������δ����˺ű���ʱ��ͣ");
			return;
		}
		else if ( returnvalue == GT_CONNECTBREAK && i != login_trytimes -1 )
		{
			XLOG("��%d�ε�¼���������ж�", i + 1);
			continue;
		}
		else if ( returnvalue == GT_CONNECTBREAK && i == login_trytimes -1 )
		{
			XLOG("��½������2��û�ɹ��������ж���");
			return;
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
	}

	XLOG("�˺ŵ�½�ɹ�");

	/*
	ѡ������
	*/
	isTimeout();
	returnvalue = call->apilist->SelectLineByName("",call);

	if ( returnvalue != GT_OK )
	{
		XLOG("ѡ��ʧ��");

		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}

	XLOG("ѡ����·�ɹ�");

	/*
	ѡ��ɫ����
	*/
	for ( i = 0; i < selectrole_trytimes; ++i )
	{
		isTimeout();
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
			XLOG("��¼��ɫ%sʧ��",_tasklet.post.sellerActor.c_str());

			taskresult.result = GT_ERR_2010;

			//taskresult.result = GT_ERR_3120;
			return;
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
	}

	XLOG("ѡ���ɫ%s��½�ɹ�",_tasklet.post.sellerActor.c_str());

	/*
	��ȫʱ����
	*/
	isTimeout();
	int safetime;
	call->apilist->QuerySafeTime(&safetime,call);
	if ( safetime >= SAFE_TIME )
	{
		/*
		����ֵ��ȫʱ�����2����,ת�˹�
		*/
		taskresult.result = GT_ERR_3030;

		XLOG("��ȫʱ����ڵ���2����");
		return;
	}

	XLOG("��ȫʱ��С��2����");

	/*
	��ѯ�������
	*/
	isTimeout();
	returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)ZX2_GOLD,&baggold,call);
	if ( returnvalue != GT_OK )
	{
		XLOG("��ѯ�������ʧ��");
		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}

	XLOG("��1�β�ѯ�������Ϊ%d",(int)baggold);

	/*
	�����н�ҵ�λ�ǽ�
	��ȡ�Ľ�ҵ�λ��ͭ
	1�� = 100�� = 10000ͭ
	*/
	if ( baggold >= tasklet.post.buyerMoney )
	{
		XLOG("�����еĽ�ұȶ����н�Ҷ�");

		isTimeout();
		returnvalue = _gamectx.apilist->IsNearBy(ZX2_NPC_MAILBOX,call);
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
		if ( returnvalue == GT_TRUE )
		{
			XLOG("��������NPC");

			isTimeout();
			if ( mailboxnpcprocess(call,tasklet,taskresult,ZX2_NPC_MAILBOX,true,false) )
			{
				return;
			}
		}
		else
		{
			XLOG("����������NPC");
		}
	}
	else
	{
		XLOG("�����еĽ�ұȶ����н����");
		isTimeout();
		returnvalue = call->apilist->IsNearBy(ZX2_NPC_WAREHOUSE,call);
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
		else if ( returnvalue == GT_TRUE )
		{
			XLOG("�����ֿ�NPC");

			/*
			��ֿ�NPC�Ի�
			*/
			isTimeout();
			returnvalue = Talk(ZX2_NPC_WAREHOUSE,call);
			if ( returnvalue == GT_OK )
			{
				XLOG("��ֿ�NPC�Ի��ɹ�");
				/*
				�򿪲ֿ�
				*/
				isTimeout();
				returnvalue = call->apilist->OpenWarehouse((char*)tasklet.post.sellerSecondPwd.c_str(),call);

				/*
				�ÿյĲֿ��������³���һ��
				*/
				if ( returnvalue != GT_OK )
				{
					isTimeout();
					returnvalue = call->apilist->OpenWarehouse("",call);

					XLOG("��һ�δ򿪲ֿ�ʧ�ܣ�ʹ�ÿ������ٳ��Դ�1��");
				}

				if ( returnvalue == GT_OK )
				{
					XLOG("�򿪲ֿ�ɹ�");
					/*
					��ѯ�ֿ��ڽ��
					*/
					INT64 warehousegold = 0;
					isTimeout();
					returnvalue = call->apilist->QueryItemsInWarehouse((Gt_GameItemT)ZX2_GOLD,&warehousegold,call);
					if ( returnvalue == GT_OK )
					{
						XLOG("��ѯ�ֿ��ҳɹ�");
						XLOG("�ֿ��ڽ��Ϊ%d",warehousegold);
						/*
						�жϽ������
						*/
						isTimeout();
						INT64 withdrawgold = tasklet.post.buyerMoney - baggold;
						if( warehousegold <= withdrawgold )
						{
							returnvalue = call->apilist->WithdrawItemsInWarehouse((Gt_GameItemT)ZX2_GOLD,&warehousegold,call);
						}
						else
						{
							returnvalue = call->apilist->WithdrawItemsInWarehouse((Gt_GameItemT)ZX2_GOLD,&withdrawgold,call);
						}
						if ( returnvalue != GT_OK )
						{
							XLOG("ȡ�ֿ��ڽ��ʧ��");
							XLOG("ȥ�ֿ�ʧ�ܷ���ֵΪ%d",returnvalue);
							withdrawsucc = false;
						}
						else
						{
							/*
							��ѯ�������
							*/
							isTimeout();
							returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)ZX2_GOLD,&baggold,call);
							if ( returnvalue != GT_OK )
							{
								XLOG("��ѯ�������ʧ��");
								checkReturnvalueprocess( returnvalue , taskresult);
								return;
							}
							XLOG("ȡ��ֿ��Һ󣬱�������%d",baggold);
							withdrawsucc = true;

							if( baggold >= tasklet.post.buyerMoney )
							{
								isTimeout();
								returnvalue = _gamectx.apilist->IsNearBy(ZX2_NPC_MAILBOX,call);
								if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
								{
									checkReturnvalueprocess( returnvalue , taskresult);
									return;
								}
								if ( returnvalue == GT_TRUE )
								{
									XLOG("��������NPC");

									if ( mailboxnpcprocess(call,tasklet,taskresult,ZX2_NPC_MAILBOX,true,false) )
									{
										return;
									}
								}
								else
								{
									XLOG("����������NPC");
								}
							}
							else
							{
								isTimeout();
								returnvalue = _gamectx.apilist->IsNearBy(ZX2_NPC_MAILBOX,call);
								if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
								{
									checkReturnvalueprocess( returnvalue , taskresult);
									return;
								}
								if ( returnvalue == GT_TRUE )
								{
									XLOG("��������NPC");

									isTimeout();
									if ( mailboxnpcprocess(call,tasklet,taskresult,ZX2_NPC_MAILBOX,true,true) )
									{
										return;
									}
								}
								else
								{
									XLOG("����������NPC");
								}
							}
						}
					}
				}
				else
				{
					XLOG("�����ṩ��2���������");
				}
			}
			else
			{
				XLOG("�Ի��ֿ�NPCʧ��");
			}
		}
	}

	/*
	�������س�
	*/
	isTimeout();
	if (backHomeprocess(call,tasklet,taskresult)==false)
	{
		/*
		���ɿ�����
		*/
		//GT_ERR_3040	3040	//��ǰ��ͼ����ָ������NPC�ǳ�

		taskresult.result = GT_ERR_3040;

		XLOG("�س�ʧ��");
		return;
	}
	XLOG("�سǳɹ�");

	/*
	ʹ�ûسǼ��ܳɹ���
	*/
	if ( withdrawsucc )
	{
		XLOG("ȡ�ֿ�ɹ�,ֱ��ȥ����");

		if ( baggold >= tasklet.post.buyerMoney )
		{
			XLOG("������ұȶ����������������");

			isTimeout();
			bh2mailboxprocess(call,tasklet,taskresult);
		}
		else
		{
			XLOG("������ұȶ�����������������");

			isTimeout();
			bh2mailboxprocess2(call,tasklet,taskresult);
		}
	}
	else
	{
		if ( baggold >= tasklet.post.buyerMoney )
		{
			XLOG("������ұȶ����������������");

			isTimeout();
			bh2mailboxprocess(call,tasklet,taskresult);
		}
		else
		{
			XLOG("������ұȶ�����������������");

			isTimeout();
			if( bh2warehouseprocess(call,tasklet,taskresult) == false )
				return;

			isTimeout();
			warehouse2mailboxprocess(call,tasklet,taskresult);
		}
	}
}

bool ZX2_Mailpost::backHomeprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	���سǼ���
	*/
	isTimeout();
	returnvalue = call->apilist->IsExistBackHomeSkill(call);
	if ( returnvalue == GT_TRUE )
	{
		XLOG("��ɫ���ڻسǼ���");
		/*
		ʹ�ûسǼ���
		*/
		isTimeout();
		returnvalue = UseBackHomeSkill(call);
		if ( returnvalue == GT_TRUE )
		{
			XLOG("��ɫʹ�ûسǼ��ܳɹ�");
			return true;
		}
		else if( returnvalue == GT_FALSE )
		{
			XLOG("��ɫʹ�ûسǼ���ʧ��");
			/*
			���سǵ���
			*/
			isTimeout();
			returnvalue = call->apilist->IsExistBackHomeItem(call);
			if ( returnvalue == GT_TRUE )
			{
				XLOG("��ɫ���ڻس���Ʒ");
				/*
				ʹ�ûسǵ���
				*/
				isTimeout();
				returnvalue = call->apilist->UseBackHomeItem(call);
				if ( returnvalue == GT_TRUE )
				{
					XLOG("��ɫʹ�ûس���Ʒ�ɹ�");
					return true;
				}
				else if ( returnvalue == GT_FALSE )
				{
					XLOG("��ɫʹ�ûس���Ʒʧ��");
					return false;
				}
				else
				{
					checkReturnvalueprocess( returnvalue , taskresult);
					return false;
				}
			}
			else if ( returnvalue == GT_FALSE )
			{
				XLOG("��ɫ�����ڻس���Ʒ");
				return false;
			}
			else
			{
				checkReturnvalueprocess( returnvalue , taskresult);
				return false;
			}
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return false;
		}
	}
	else if ( returnvalue == GT_FALSE )
	{
		XLOG("��ɫ�����ڻسǼ���");
		/*
		���سǵ���
		*/
		isTimeout();
		returnvalue = call->apilist->IsExistBackHomeItem(call);
		if ( returnvalue == GT_TRUE )
		{
			XLOG("��ɫ���ڻس���Ʒ");
			/*
			ʹ�ûسǵ���
			*/
			isTimeout();
			returnvalue = call->apilist->UseBackHomeItem(call);
			if ( returnvalue == GT_TRUE )
			{
				XLOG("��ɫʹ�ûس���Ʒ�ɹ�");
				return true;
			}
			else if ( returnvalue == GT_FALSE )
			{
				XLOG("��ɫʹ�ûس���Ʒʧ��");
				return false;
			}
			else
			{
				checkReturnvalueprocess( returnvalue , taskresult);
				return false;
			}
		}
		else if ( returnvalue == GT_FALSE )
		{
			XLOG("��ɫ�����ڻس���Ʒ");
			return false;
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return false;
		}
	}
	else
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return false;
	}
}

bool ZX2_Mailpost::warehouse2mailboxprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	�ֿ��ƶ�������
	*/
	isTimeout();
	returnvalue = call->apilist->MoveTo(WAREHOUSE2MAILBOX,call);
	Sleep(30000);
	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return false;
	}

	if ( returnvalue == GT_OK )
	{
		XLOG("�ֿ��ƶ�������ɹ�");

		/*
		��ѯ�������
		*/
		isTimeout();
		returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)ZX2_GOLD,&baggold,call);
		if ( returnvalue != GT_OK )
		{
			XLOG("��ѯ�������ʧ��");
			checkReturnvalueprocess( returnvalue , taskresult);
			return false;
		}

		XLOG("��3�β�ѯ�������Ϊ%d",(int)baggold);

		if ( baggold >= tasklet.post.buyerMoney )
		{
			XLOG("��������������ڶ�������");

			isTimeout();
			mailboxnpcprocess(call,tasklet,taskresult,ZX2_NPC_MAILBOX,true,false);
			return false;
		}
		else
		{
			XLOG("�����������С�ڶ�������");

			isTimeout();
			mailboxnpcprocess(call,tasklet,taskresult,ZX2_NPC_MAILBOX,true,true);
			return false;
		}
	}
	else
	{
		XLOG("�ֿ��ƶ�������ʧ��");
		/*
		���ɿ�����
		*/
		taskresult.result = GT_ERR_3120;
		return false;
	}
	return true;
}

bool ZX2_Mailpost::bh2mailboxprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	�ӻسǵ��ߵ�����
	*/
	isTimeout();
	returnvalue = call->apilist->MoveTo(BH2MAILBOX,call);
	Sleep(30000);
	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return false;
	}
	if ( returnvalue == GT_OK )
	{
		XLOG("�ӻسǵ��ߵ�����ɹ�");

		isTimeout();
		mailboxnpcprocess(call,tasklet,taskresult,ZX2_NPC_MAILBOX,true,false);
	}
	else
	{
		/*
		���ɿ�����
		*/
		taskresult.result = GT_ERR_3120;

		XLOG("�ӻسǵ��ߵ�����ʧ��");
		return false;
	}
	return true;
}

bool ZX2_Mailpost::bh2mailboxprocess2(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	�ӻسǵ��ߵ�����
	*/
	isTimeout();
	returnvalue = call->apilist->MoveTo(BH2MAILBOX,call);
	Sleep(30000);
	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return false;
	}
	if ( returnvalue == GT_OK )
	{
		XLOG("�ӻسǵ��ߵ�����ɹ�");

		isTimeout();
		mailboxnpcprocess(call,tasklet,taskresult,ZX2_NPC_MAILBOX,true,true);
	}
	else
	{
		/*
		���ɿ�����
		*/
		taskresult.result = GT_ERR_3120;

		XLOG("�ӻسǵ��ߵ�����ʧ��");
		return false;
	}
	return true;
}

bool ZX2_Mailpost::bh2warehouseprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	�سǵ��ƶ����ֿ�
	*/
	isTimeout();
	returnvalue = call->apilist->MoveTo(BH2WAREHOUSE,call);
	Sleep(30000);
	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return false;
	}
	if ( returnvalue == GT_OK )
	{
		XLOG("�ӻسǵ��ߵ��ֿ�ɹ�");
		/*
		��ֿ�NPC�Ի�
		*/
		isTimeout();
		returnvalue = Talk(ZX2_NPC_WAREHOUSE,call);
		if ( returnvalue == GT_OK )
		{
			XLOG("��ֿ�NPC�Ի��ɹ�");
			/*
			�򿪲ֿ�
			*/
			isTimeout();
			returnvalue = call->apilist->OpenWarehouse((char*)tasklet.post.sellerSecondPwd.c_str(),call);

			/*
			�ÿյĲֿ��������³���һ��
			*/
			if ( returnvalue != GT_OK )
			{
				isTimeout();
				returnvalue = call->apilist->OpenWarehouse("",call);

				XLOG("��һ�δ򿪲ֿ�ʧ�ܣ�ʹ�ÿ������ٳ��Դ�1��");
			}

			if ( returnvalue == GT_OK )
			{
				XLOG("�򿪲ֿ�ɹ�");
				/*
				��ѯ�ֿ��ڽ��
				*/
				INT64 warehousegold = 0;
				isTimeout();
				returnvalue = call->apilist->QueryItemsInWarehouse((Gt_GameItemT)ZX2_GOLD,&warehousegold,call);
				if ( returnvalue == GT_OK )
				{
					XLOG("��ѯ�ֿ��ҳɹ�");
					XLOG("�ֿ��ڽ��Ϊ%d",warehousegold);
					/*
					�жϽ������
					*/
					INT64 withdrawgold = tasklet.post.buyerMoney - baggold;
					if( warehousegold <= withdrawgold )
					{
						if(warehousegold==0)
						{
							XLOG("�ֿ���Ϊ%d",0);
						}
						else
						{
							isTimeout();
							returnvalue = call->apilist->WithdrawItemsInWarehouse((Gt_GameItemT)ZX2_GOLD,&warehousegold,call);
							if ( returnvalue != GT_OK )
							{
								XLOG("ȡ�ֿ��ڽ��ʧ��");
								XLOG("ȥ�ֿ�ʧ�ܷ���ֵΪ%d",returnvalue);
							}
							else
							{
								XLOG("�ӿڷ���ȡ�ֿ��ҳɹ���δ��ѯ����");
							}
						}
					}
					else
					{
						if(warehousegold==0)
						{
							XLOG("�ֿ���Ϊ%d",0);
						}
						else
						{
							isTimeout();
							returnvalue = call->apilist->WithdrawItemsInWarehouse((Gt_GameItemT)ZX2_GOLD,&withdrawgold,call);

							if ( returnvalue != GT_OK )
							{
								XLOG("ȡ�ֿ��ڽ��ʧ��");
								XLOG("ȥ�ֿ�ʧ�ܷ���ֵΪ%d",returnvalue);
							}
							else
							{
								XLOG("�ӿڷ���ȡ�ֿ��ҳɹ���δ��ѯ����");
							}
						}
					}
				}
			}
			else
			{
				XLOG("�����ṩ��2���������");
			}
		}
		else
		{
			XLOG("��ֿ�NPC�Ի�ʧ��");
		}
	}
	else
	{
		/*
		���ɿ�����
		*/
		taskresult.result = GT_ERR_3120;

		XLOG("�ӻسǵ��ߵ��ֿ�ʧ��");
		return false;
	}
	return true;
}

bool ZX2_Mailpost::sendmailprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	�����ʼ�
	*/
	isTimeout();
	returnvalue = call->apilist->SendMail((char*)tasklet.post.buyerActor.c_str(),(char*)configdata.sMailTitle.c_str(),(char*)configdata.sMailContent.c_str(),tasklet.post.buyerMoney - 500,call);
	if ( returnvalue == GT_OK )
	{
		XLOG("���ʼ��ɹ�");
		taskresult.result = GT_ERR_1000;

		returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)ZX2_GOLD,&baggold,call);
		XLOG("�����ʼ��󱳰����Ϊ%d",(int)baggold);
		return true;
	}
	else if ( returnvalue == GT_NOTEXISTED )
	{
		taskresult.result = GT_ERR_2050;

		XLOG("��ҽ�ɫ������");
		return false;
	}
	else if ( returnvalue == GT_MAIlBOXFULL )
	{
		taskresult.result = GT_ERR_3070;

		XLOG("�����������");
		return false;
	}
	else if ( returnvalue == GT_MAIlBOXLOCKED )
	{
		taskresult.result = GT_ERR_2100;

		XLOG("��������Ѷ���");
		return false;
	}
	else if ( returnvalue == GT_ROLEKICK )
	{
		taskresult.result = GT_ERR_3050;

		XLOG("���Ҷ���");
		return false;
	}
	else if ( returnvalue == GT_TIMEOUT )
	{
		taskresult.result = GT_ERR_3120;

		XLOG("�����ʼ���ʱ");
		return false;
	}
	else if ( returnvalue == GT_CONNECTBREAK )
	{
		taskresult.result = GT_ERR_3120;

		XLOG("�����ж�");
		throw(robot_error(GT_CONNECTBREAK, GT_ERR_3120, "�����ж�"));
		return false;
	}
	else
		XLOG("����δ֪���ʼ�����");
	return true;;
}

bool ZX2_Mailpost::checkmailpostprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	���ص���ɫѡ����
	*/
	isTimeout();
	returnvalue = call->apilist->ReturnToSelectRole(call);
	if ( returnvalue == GT_OK )
	{
		isTimeout();
		returnvalue = call->apilist->SelectRoleByName((char*)tasklet.post.sellerActor.c_str(),call);
		if ( returnvalue == GT_OK )
		{
			INT64 curbaggold;
			isTimeout();
			returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)ZX2_GOLD,&curbaggold,call);
			if ( returnvalue == GT_OK )
			{
				if ( curbaggold == baggold )
				{
					taskresult.result = GT_ERR_3120;
					return true;
				}
				else
				{
					taskresult.result = GT_ERR_1000;
					return true;
				}
			}
			else if( returnvalue == GT_FALSE )
			{

			}
			else
			{
				checkReturnvalueprocess( returnvalue , taskresult);
				return false;
			}
		}
		else if( returnvalue == GT_FALSE )
		{

		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return false;
		}
	}
	else if( returnvalue == GT_FALSE )
	{

	}
	else
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return false;
	}

	return true;
}

bool ZX2_Mailpost::timeoutprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	if ( restarttimes == 0 )
	{
		/*
		�������ʧ�ܣ����ؽ��ת�˹�
		*/
		taskresult.result = GT_ERR_3120;
		return false;
	}
	else
		restarttimes = restarttimes - 1;

	int returnvalue;
	/*
	�ر�
	*/
	returnvalue = call->apilist->End(call);
	/*
	��ʼ
	*/
	returnvalue = call->apilist->Begin(call);


	run(call,tasklet,taskresult);
	return true;
}

void ZX2_Mailpost::checkReturnvalueprocess( int returnvalue, gtr::GameTaskResultT& taskresult )
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

		XLOG("��һ������������ҽ�ɫ������");
		return;
	}
	else if ( returnvalue == GT_MAIlBOXFULL )
	{
		taskresult.result = GT_ERR_3070;

		XLOG("��һ���������������������");
		return;
	}
	else if ( returnvalue == GT_MAIlBOXLOCKED )
	{
		taskresult.result = GT_ERR_2100;

		XLOG("��һ������������������Ѷ���");
		return;
	}
	else if ( returnvalue == GT_ROLEKICK )
	{
		taskresult.result = GT_ERR_3050;

		XLOG("��һ�������������Ҷ���");
		return;
	}
	else if ( returnvalue == GT_TIMEOUT )
	{
		taskresult.result = GT_ERR_3120;

		XLOG("��һ��������ʱ");
		return;
	}
	else if ( returnvalue == GT_CONNECTBREAK )
	{
		taskresult.result = GT_ERR_3120;

		XLOG("�����ж�");
		throw(robot_error(GT_CONNECTBREAK, GT_ERR_3120, "�����ж�"));
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
	else if ( returnvalue == GT_INSAFETIME )
	{
		XLOG("�ڰ�ȫʱ���е�����һ���Ĳ���ʧ��");
		return;
	}
	else if ( returnvalue == GT_ROLELOCK )
	{
		XLOG("�˺ű���");
		return;
	}
	else
	{
		XLOG("δ֪�ķ���ֵ%d",returnvalue);
		return;
	}
}
bool ZX2_Mailpost::mailboxnpcprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult,eZX2NPCType npctype,bool safelock,bool withdrawgold)
{
	int returnvalue;

	/*
	������npc�Ի�
	*/
	isTimeout();
	returnvalue = Talk(npctype,call);
	if ( returnvalue != GT_OK )
	{
		XLOG("������NPC�Ի�ʧ��");
		checkReturnvalueprocess( returnvalue , taskresult);
		return false;
	}

	/*
	�ж��Ƿ����
	*/
	if ( safelock )
	{
		returnvalue = GT_FALSE;
		while (!returnvalue)
		{
			returnvalue = call->apilist->IsUnlocked(call);

			if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
			{
				checkReturnvalueprocess( returnvalue , taskresult);
				return true;
			}
			Sleep(1000);
		}

		XLOG("��ȫ�������ɹ�");
	}

	/*
	������
	*/
	isTimeout();
	returnvalue = call->apilist->OpenMailBox(NULL,call);
	if ( returnvalue != GT_OK )
	{
		XLOG("������ʧ��");
		checkReturnvalueprocess( returnvalue , taskresult);
		return true;
	}

	if(withdrawgold)
	{
		/*
		�ж������н�ң���������ȡǮ
		*/
		INT64 mailboxgold = tasklet.post.buyerMoney - baggold;

		isTimeout();
		returnvalue = call->apilist->WithdrawItemsInMailbox((Gt_GameItemT)ZX2_GOLD,&mailboxgold,call);
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return true;
		}
		isTimeout();
		returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)ZX2_GOLD,&baggold,call);
		if ( returnvalue != GT_OK )
		{
			XLOG("��ѯ�������ʧ��");
			checkReturnvalueprocess( returnvalue , taskresult);
			return true;
		}

		XLOG("ȡ�������Һ��ѯ�������Ϊ%d",(int)baggold);
		if( baggold >= tasklet.post.buyerMoney )
		{
			XLOG("��������������ڶ�������ȡ�����ҳɹ�");
			/*
			�����ʼ�
			*/
			isTimeout();
			sendmailprocess(call,tasklet,taskresult);
			return true;
		}
		else
		{
			XLOG("�����������С�ڶ�������");
			/*
			���㷢�����
			*/
			taskresult.result = GT_ERR_2030;
			//taskresult.result = GT_ERR_3120;
			return true;
		}
	}
	else
	{
		isTimeout();
		sendmailprocess(call,tasklet,taskresult);
	}
	return true;
}

int ZX2_Mailpost::Talk(Gt_NPCID npc,CALLCTX* call)
{
	int old = call->timeout;

	call->timeout = TIMEOUT_5;

	int returnvalue;
	
	for(int i=0; i<3; i++)
	{
		returnvalue = call->apilist->Talk(npc, call);
		if ( returnvalue == GT_OK )
		{
			break;
		}
	}

	call->timeout = old;

	return returnvalue;

}

int ZX2_Mailpost::UseBackHomeSkill(CALLCTX* call)
{
	int old = call->timeout;
	call->timeout = TIMEOUT_15;

	int returnvalue;

	for(int i=0; i<2; i++)
	{
		returnvalue = call->apilist->UseBackHomeSkill(call);
		if ( returnvalue == GT_OK )
		{
			break;
		}
	}

	call->timeout = old;

	return returnvalue;
}
