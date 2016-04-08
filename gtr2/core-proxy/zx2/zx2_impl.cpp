#include "zx2_impl.h"
#include "Withdraw.h"

void WAIT(bool enable = false);
void WAIT(bool enable)
{

}

IMPLEMENT_APP_CONSOLE(zx2_impl)

swlib::swLogger& appLogger()
{
	return wxGetApp().getLogger();
}

#define SAFE_TIME 120

const int selectserver_trytimes = 2;
const int selectarea_trytimes = 2;
const int login_trytimes = 3;
const int inputmb_trytimes = 3;
const int selectrole_trytimes = 3;

zx2_impl::zx2_impl(void)
{
}

zx2_impl::~zx2_impl(void)
{
}

void zx2_impl::task_MailPost(gtr::GameTaskResultT& result)
{
	/*
	������Ϸ
	*/
	_gamectx.apilist->Begin(&_gamectx);
	/*
	�м�Ĵ������
	*/

	try
	{
		_gamectx.timeout = -1;
		/*
		Ԥ����Ĭ�ϵķ��ؽ��
		*/
		result.result = GT_ERR_3120;

		validating();

		login(&_gamectx,_tasklet);

		doBusiness(&_gamectx,_tasklet);
	}
	catch (robot_error err)
	{
		result.result = err.code;
		getLogger().Message("%s", err.message.c_str());
	}
	catch (int ret)
	{
		result.result = ret;
	}

	/*
	�ر���Ϸ
	*/
	_gamectx.apilist->End(&_gamectx);

	getLogger().Message("���ط������Ľ��׽��Ϊ%d",(int)result.result);
}

void zx2_impl::validating()
{
	/*
	�ж��������Ľ�������Ƿ����������Ľ������
	*/
	if( _tasklet.post.money < _tasklet.post.buyerMoney )
	{
		throw(robot_error(GT_ERR_2030,"�������Ľ������С�������Ľ������"));
	}

	getLogger().Message("������Ϊ%s",(char*)_tasklet.no.c_str());
	getLogger().Message("�������������Ϊ%d",_tasklet.post.buyerMoney);
	/*
	�ж϶����������
	*/
	if ( _tasklet.post.buyerMoney > 200000 * 10000 )
	{
		throw(robot_error(GT_ERR_3120,"����������"));
	}

}

void zx2_impl::login(CALLCTX* call,gtr::GameTaskletT& tasklet)
{
	int i;
	int returnvalue;

	/*
	ѡ��������
	*/
	for ( i = 0; i < selectarea_trytimes; ++i )
	{
		returnvalue = call->apilist->SelectArea(const_cast<char*>(tasklet.area.c_str()),call); WAIT();
		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_UNABLECONNECT && i != selectarea_trytimes - 1 )
			continue;
		else if ( returnvalue == GT_UNABLECONNECT && i == selectarea_trytimes - 1 )
		{
			/*
			����ֵ�����޷�����,ת�˹�
			*/
			throw(robot_error(GT_ERR_3000, "���Ӵ���ʧ��"));
		}
		else
		{
			
			throw(make_error(returnvalue));		
		}
	}

	getLogger().Message("���Ӵ����ɹ�");

	/*
	ѡС������
	*/
	for ( i = 0; i < selectserver_trytimes; ++i )
	{
		returnvalue = call->apilist->SelectServer(const_cast<char*>(tasklet.server.c_str()),call); WAIT();
		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_UNABLECONNECT && i != selectserver_trytimes - 1 )
			continue;
		else if ( returnvalue == GT_UNABLECONNECT && i == selectserver_trytimes - 1 )
		{
			/*
			����ֵС���޷�����,ת�˹�
			*/
			throw(robot_error(GT_ERR_3020,"����С��ʧ��"));
		}
		else
		{
			throw(make_error(returnvalue));		
		}
	}

	getLogger().Message("����С���ɹ�");

	/*
	�˺ŵ�½����
	*/
	for ( i = 0; i < login_trytimes; ++i )
	{
		call->timeout = -1;
		returnvalue = call->apilist->Login(const_cast<char*>(tasklet.account.c_str()),const_cast<char*>(tasklet.password.c_str()),call); WAIT();

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
			throw(robot_error(GT_ERR_2000,"�����������"));
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
			throw(robot_error(GT_ERR_2090,"�����ܱ��ϴ�����"));
		}
		else if ( returnvalue == GT_VERSIONERROR )
		{
			/*
			��Ϸ�汾����
			*/
			throw(robot_error(GT_ERR_3120, "��Ϸ�汾����"));
		}
		else if ( returnvalue == GT_PLAYERINLINE )
		{
			/*
			�������
			*/
			throw(robot_error(GT_ERR_3120, "�������"));
		}
		else if ( returnvalue == GT_FALSE && i != login_trytimes -1 )
		{
			continue;
		}
		else if ( returnvalue == GT_FALSE && i == login_trytimes -1 )
		{
			throw(robot_error(GT_ERR_3120, "��Ϸ������û�����߿������ܱ������δ����˺ű���ʱ��ͣ"));
		}
		else
		{
			throw(make_error(returnvalue));		
		}
	}

	getLogger().Message("�˺ŵ�½�ɹ�");

	/*
	ѡ������
	*/
	//returnvalue = call->apilist->SelectLineByName("12",call); WAIT();
	returnvalue = call->apilist->SelectLineByIndex(12,call); WAIT();

	if ( returnvalue != GT_OK )
	{
		getLogger().Message("ѡ��ʧ��");

		throw(make_error(returnvalue));		
	}

	getLogger().Message("ѡ����·�ɹ�");

	/*
	ѡ��ɫ����
	*/
	for ( i = 0; i < selectrole_trytimes; ++i )
	{
		returnvalue = call->apilist->SelectRoleByName((char*)_tasklet.post.sellerActor.c_str(),call); WAIT();

		if ( returnvalue == GT_OK )
		{
			break;
		}

		// �жϽ�ɫ�б��Ƿ�Ϊ�գ� ��ֱ�ӳ����� ���ֲ�ƥ��ת�˹�
		else if ( returnvalue == GT_NOTEXISTED && i != selectrole_trytimes -1 )
		{
		}
		else if ( returnvalue == GT_NOTEXISTED && i == selectrole_trytimes -1 )
		{
			throw(robot_error(GT_ERR_2010, "ѡ��ɫʧ��"));
		}
		else
		{
			throw(make_error(returnvalue));		
		}
	}

	getLogger().Message("ѡ���ɫ��½�ɹ�");

	/*
	��ȫʱ����
	*/
	int safetime;
	call->apilist->QuerySafeTime(&safetime,call); WAIT();
	if ( safetime >= SAFE_TIME )
	{
		/*
		����ֵ��ȫʱ�����2����,ת�˹�
		*/
		throw(robot_error(GT_ERR_3030,"��ȫʱ�����2����"));
	}

	getLogger().Message("��ȫʱ����ɹ�");

}

void zx2_impl::_sendMail(CALLCTX *call,gtr::GameTaskletT& tasklet)
{
	int returnvalue;
	/*
	�����ʼ�
	*/
	returnvalue = call->apilist->SendMail((char*)tasklet.post.buyerActor.c_str(),"youjian","youjian",tasklet.post.buyerMoney,call); WAIT();
	if ( returnvalue == GT_OK )
	{
		getLogger().Message("���ʼ��ɹ�");
//		taskresult.result = GT_ERR_1000;

		returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)ZX2_GOLD,&baggold,call); WAIT();
		getLogger().Message("�����ʼ��󱳰����Ϊ%d",(int)baggold);
	}
	else if ( returnvalue == GT_NOTEXISTED )
	{
		throw(robot_error(GT_ERR_2050,"��ҽ�ɫ������"));
	}
	else if ( returnvalue == GT_MAIlBOXFULL )
	{
		throw(robot_error(GT_ERR_3070, "�����������"));
	}
	else if ( returnvalue == GT_MAIlBOXLOCKED )
	{
		throw(robot_error(GT_ERR_3070, "��������Ѷ���"));
	}
	else if ( returnvalue == GT_ROLEKICK )
	{
		throw(robot_error(GT_ERR_3050, "���Ҷ���"));
	}
	else if ( returnvalue == GT_TIMEOUT )
	{
		throw(robot_error(GT_ERR_3120, "ѡС����ʱ"));
	}
	else if ( returnvalue == GT_CONNECTBREAK )
	{
		throw(robot_error(GT_ERR_3120, "�����ж�"));
	}
	else
	{
		throw(robot_error(GT_ERR_3120, "����δ֪���ʼ�����"));
	}

}

bool zx2_impl::_withdraw_mailbox(CALLCTX *call,gtr::GameTaskletT& tasklet)
{
	int returnvalue;
	/*
	�ж������н�ң���������ȡǮ
	*/
	INT64 mailboxgold = tasklet.post.buyerMoney - baggold;
	INT64 temp = mailboxgold;
	returnvalue = call->apilist->IsEnoughItemsInMailbox((Gt_GameItemT)ZX2_GOLD,&temp,call); WAIT();
	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		throw(make_error( returnvalue));
	}
	if ( returnvalue == GT_TRUE )
	{
		getLogger().Message("���������㹻��Ǯ");
		returnvalue = call->apilist->WithdrawItemsInMailbox((Gt_GameItemT)ZX2_GOLD,&mailboxgold,call); WAIT();

		if ( returnvalue != GT_OK )
		{
			throw(make_error( returnvalue));
		}

		getLogger().Message("������ȡǮ�ɹ�");

		returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)ZX2_GOLD,&baggold,call); WAIT();

		if ( returnvalue != GT_OK )
		{
			throw(make_error( returnvalue));
		}

		if( baggold >= tasklet.post.buyerMoney )
		{
			getLogger().Message("��������������ڶ�������ȡ�����ҳɹ�");

			return true;
		}
		else
		{
			getLogger().Message("�����������С�ڶ�������ȡ������ʧ��");
		}
	}
	else
	{
		getLogger().Message("������û���㹻��Ǯ");
	}

	return false;
}

void zx2_impl::_withdraw(CALLCTX *call,gtr::GameTaskletT& tasklet)
{
	int returnvalue;

	/*
	��ֿ�NPC�Ի�
	*/
	int talkc = 0;
	while(talkc < 20)
	{
		returnvalue = call->apilist->Talk(ZX2_NPC_WAREHOUSE,call); WAIT();
		if(returnvalue==GT_OK)
			break;
		talkc++;

	}
	if ( returnvalue == GT_OK )
	{
		getLogger().Message("��ֿ�NPC�Ի��ɹ�");
		/*
		�򿪲ֿ�
		*/
		returnvalue = call->apilist->OpenWarehouse((char*)tasklet.post.sellerSecondPwd.c_str(),call); WAIT();

		/*
		�ÿյĲֿ��������³���һ��
		*/
		if ( returnvalue != GT_OK )
		{
			returnvalue = call->apilist->OpenWarehouse("",call); WAIT();

			getLogger().Message("��һ�δ򿪲ֿ�ʧ�ܣ�ʹ�ÿ������ٳ��Դ�1��");
		}

		if ( returnvalue == GT_OK )
		{
			getLogger().Message("�򿪲ֿ�ɹ�");
			/*
			��ѯ�ֿ��ڽ��
			*/
			INT64 warehousegold = 0;
			returnvalue = call->apilist->QueryItemsInWarehouse((Gt_GameItemT)ZX2_GOLD,&warehousegold,call); WAIT();
			if ( returnvalue == GT_OK )
			{
				getLogger().Message("��ѯ�ֿ��ҳɹ�");
				/*
				�жϽ������
				*/
				INT64 withdrawgold = tasklet.post.buyerMoney - baggold;
				if( warehousegold <= withdrawgold )
				{
					returnvalue = call->apilist->WithdrawItemsInWarehouse((Gt_GameItemT)ZX2_GOLD,&warehousegold,call); WAIT();
				}
				else
				{
					returnvalue = call->apilist->WithdrawItemsInWarehouse((Gt_GameItemT)ZX2_GOLD,&withdrawgold,call); WAIT();
				}

				if(returnvalue != GT_OK)
				{

				}
			}
		}
		else
		{
			getLogger().Message("�����ṩ��2���������");
		}
	}
	else
	{
		getLogger().Message("�ֿ�NPC�Ի�ʧ��");
	}

}

void zx2_impl::doBusiness(CALLCTX* call,gtr::GameTaskletT& tasklet)
{
	int returnvalue;

	/*
	��ѯ�������
	*/
	returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)ZX2_GOLD,&baggold,call);
	if ( returnvalue != GT_OK )
	{
		getLogger().Message("��ѯ�������ʧ��");

		throw(make_error(returnvalue));
		
	}

	getLogger().Message("��1�β�ѯ�������Ϊ%d",(int)baggold);


	/*
	�����н�ҵ�λ�ǽ�
	��ȡ�Ľ�ҵ�λ��ͭ
	1�� = 100�� = 10000ͭ
	*/
	if ( baggold >= tasklet.post.buyerMoney )
	{
		getLogger().Message("�����еĽ�ұȶ����н�Ҷ�");

		returnvalue = call->apilist->IsNearBy(ZX2_NPC_MAILBOX,call); WAIT();
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			throw(make_error( returnvalue));
		}
		if ( returnvalue == GT_TRUE )
		{
			getLogger().Message("��������NPC");

			NPC mailbox(ZX2_NPC_MAILBOX);
			mailbox.Create(call);	// talk & openmailbox & isunlocked
			mailbox.WaitUnLocked(call);	//
			_sendMail(call, tasklet);
			return;
		}
		else
		{
			getLogger().Message("����������NPC");
		}
	}
	else
	{
		getLogger().Message("�����еĽ�ұȶ����н����");

		/*
		returnvalue = call->apilist->IsNearBy(ZX2_NPC_MAILBOX,call); WAIT();
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			throw(make_error( returnvalue));
		}
		if ( returnvalue == GT_TRUE )
		{
			getLogger().Message("��������NPC");

			NPC mailbox(ZX2_NPC_MAILBOX);
			mailbox.Create(call);	// talk & openmailbox & isunlocked
			mailbox.WaitUnLocked(call);	//
			if( _withdraw_mailbox(call, tasklet) )
			{
				_sendMail(call, tasklet);
				return;
			}
		}
		else
		{
			getLogger().Message("����������NPC");
		}
		*/
		returnvalue = call->apilist->IsNearBy(ZX2_NPC_WAREHOUSE,call); WAIT();
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			throw(make_error( returnvalue));
		}
		if ( returnvalue == GT_TRUE )
		{
			getLogger().Message("�����ֿ�NPC");

			NPC warehouse(ZX2_NPC_WAREHOUSE);
			warehouse.Create(call);	// talk & openmailbox & isunlocked
			warehouse.WaitUnLocked(call);	//
			_withdraw(call, tasklet);
		}
		else
		{
			getLogger().Message("����������NPC");
		}
	}

	if (backHomeprocess(call)==false)
	{
		/*
		���ɿ�����
		*/
		throw(robot_error(GT_ERR_3120, "�س�ʧ��"));
	}
	getLogger().Message("�سǳɹ�");

	if ( baggold >= tasklet.post.buyerMoney )
	{
		getLogger().Message("������ұȶ����������������");
		/*
		�ӻسǵ��ߵ�����
		*/
		WAIT(true);
		returnvalue = call->apilist->MoveTo(BH2MAILBOX,call); WAIT();
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			throw(make_error( returnvalue));
		}
		if ( returnvalue == GT_OK )
		{
			getLogger().Message("�ӻسǵ��ߵ�����ɹ�");

			NPC mailbox(ZX2_NPC_MAILBOX);
			mailbox.Create(call);	// talk & openmailbox & isunlocked
			mailbox.WaitUnLocked(call);	//
			_sendMail(call, tasklet);
			return;

		}
		else
		{
			/*
			���ɿ�����
			*/
			throw(robot_error(GT_ERR_3120, "�ӻسǵ��ߵ�����ʧ��"));
		}
	}
	else
	{
		getLogger().Message("������ұȶ�����������������");
		/*
		�سǵ��ƶ����ֿ�
		*/
		WAIT(true);
		returnvalue = call->apilist->MoveTo(BH2WAREHOUSE,call); WAIT();
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			throw(make_error( returnvalue));
		}
		if ( returnvalue == GT_OK )
		{
			getLogger().Message("�ӻسǵ��ߵ��ֿ�ɹ�");

			NPC warehouse(ZX2_NPC_WAREHOUSE);
			warehouse.Create(call);	// talk & OpenWarehouse 
			_withdraw(call, tasklet);

		}
		else
		{
			/*
			���ɿ�����
			*/
			throw(robot_error(GT_ERR_3120, "�ӻسǵ��ߵ��ֿ�ʧ��"));
		}

		/*
		�ֿ��ƶ�������
		*/
		returnvalue = call->apilist->MoveTo(WAREHOUSE2MAILBOX,call); WAIT();
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			throw(make_error( returnvalue));
		}

		if ( returnvalue == GT_OK )
		{
			getLogger().Message("�ֿ��ƶ�������ɹ�");

			NPC mailbox(ZX2_NPC_MAILBOX);
			mailbox.Create(call);	// talk & openmailbox & isunlocked
			mailbox.WaitUnLocked(call);	//

			/*
			��ѯ�������
			*/
			returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)ZX2_GOLD,&baggold,call); WAIT();
			if ( returnvalue != GT_OK )
			{
				throw(make_error( returnvalue));
			}

			if ( baggold >= tasklet.post.buyerMoney )
			{
				getLogger().Message("��������������ڶ�������");
				_sendMail(call, tasklet);
				return;
			}
			else
			{
				getLogger().Message("�����������С�ڶ�������");

				/*
				�ж������н�ң���������ȡǮ
				*/
				if( _withdraw_mailbox(call, tasklet) )
				{
					_sendMail(call, tasklet);
					return;
				}
				else
				{
					/*
					���㷢�����
					*/
					throw(robot_error(GT_ERR_2030, "û���㹻��Ǯ"));
				}
			}
		}
		else
		{
			/*
			���ɿ�����
			*/
			throw(robot_error(GT_ERR_3120,"�ֿ��ƶ�������ʧ��"));
		}
	}
}

bool zx2_impl::backHomeprocess(CALLCTX* call)
{
	int returnvalue;
	/*
	���سǼ���
	*/
	returnvalue = call->apilist->IsExistBackHomeSkill(call);
	if ( returnvalue == GT_TRUE )
	{
		getLogger().Message("��ɫ���ڻسǼ���");
		/*
		ʹ�ûسǼ���
		*/
		returnvalue = call->apilist->UseBackHomeSkill(call);
		if ( returnvalue == GT_TRUE )
		{
			getLogger().Message("��ɫʹ�ûسǼ��ܳɹ�");
			return true;
		}
		else if( returnvalue == GT_FALSE )
		{
			getLogger().Message("��ɫʹ�ûسǼ���ʧ��");
			/*
			���سǵ���
			*/
			returnvalue = call->apilist->IsExistBackHomeItem(call);
			if ( returnvalue == GT_TRUE )
			{
				getLogger().Message("��ɫ���ڻس���Ʒ");
				/*
				ʹ�ûسǵ���
				*/
				returnvalue = call->apilist->UseBackHomeItem(call);
				if ( returnvalue == GT_TRUE )
				{
					getLogger().Message("��ɫʹ�ûس���Ʒ�ɹ�");
					return true;
				}
				else if ( returnvalue == GT_FALSE )
				{
					getLogger().Message("��ɫʹ�ûس���Ʒʧ��");
					return false;
				}
				else
				{
					throw(make_error( returnvalue));
				}
			}
			else if ( returnvalue == GT_FALSE )
			{
				getLogger().Message("��ɫ�����ڻس���Ʒ");
				return false;
			}
			else
			{
				throw(make_error( returnvalue));
			}
		}
		else
		{
			throw(make_error( returnvalue));
		}
	}
	else if ( returnvalue == GT_FALSE )
	{
		getLogger().Message("��ɫ�����ڻسǼ���");
		/*
		���سǵ���
		*/
		returnvalue = call->apilist->IsExistBackHomeItem(call);
		if ( returnvalue == GT_TRUE )
		{
			getLogger().Message("��ɫ���ڻس���Ʒ");
			/*
			ʹ�ûسǵ���
			*/
			returnvalue = call->apilist->UseBackHomeItem(call);
			if ( returnvalue == GT_TRUE )
			{
				getLogger().Message("��ɫʹ�ûس���Ʒ�ɹ�");
				return true;
			}
			else if ( returnvalue == GT_FALSE )
			{
				getLogger().Message("��ɫʹ�ûس���Ʒʧ��");
				return false;
			}
			else
			{
				throw(make_error( returnvalue));
			}
		}
		else if ( returnvalue == GT_FALSE )
		{
			getLogger().Message("��ɫ�����ڻس���Ʒ");
			return false;
		}
		else
		{
			throw(make_error( returnvalue));
		}
	}
	else
	{
		throw(make_error( returnvalue));
	}
}


robot_error zx2_impl::make_error( int returnvalue)
{
	assert ( returnvalue != GT_OK );

	if ( returnvalue == GT_FALSE )
	{
		return robot_error(GT_ERR_3120,"��һ������ʧ�ܵ����޷�����");
	}
	else if ( returnvalue == GT_NOTEXISTED )
	{
		return robot_error(GT_ERR_2050,"��һ������������ҽ�ɫ������");
	}
	else if ( returnvalue == GT_MAIlBOXFULL )
	{
		return robot_error(GT_ERR_3070,"��һ���������������������");
	}
	else if ( returnvalue == GT_MAIlBOXLOCKED )
	{
		return robot_error(GT_ERR_3070,"��һ������������������Ѷ���");
	}
	else if ( returnvalue == GT_ROLEKICK )
	{
		return robot_error(GT_ERR_3050, "��һ�������������Ҷ���");
	}
	else if ( returnvalue == GT_TIMEOUT )
	{
		return robot_error(GT_ERR_3120,"��һ��������ʱ");
	}
	else if ( returnvalue == GT_CONNECTBREAK )
	{
		return robot_error(GT_ERR_3120,"�����ж�");
	}
	else if ( returnvalue == GT_UNABLEMOVETO )
	{
		return robot_error(GT_ERR_3120,"�޷�����Ŀ��NPC");
	}
	else if ( returnvalue == GT_UNABLETALKTO )
	{
		return robot_error(GT_ERR_3120,"�޷��Ի�Ŀ��NPC");
	}
	//else if ( returnvalue == GT_INSAFETIME )
	//{
	//	return robot_error(GT_ERR_3120,"�ڰ�ȫʱ���е�����һ���Ĳ���ʧ��");
	//}
	else
	{
		return robot_error(GT_ERR_3120,"");
	}
}