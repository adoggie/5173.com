#include "mhzx_impl.h"

#define SAFE_TIME 300

#if 1//_DEBUG
IMPLEMENT_APP_CONSOLE(mhzx_impl)

swlib::swLogger& appLogger()
{
	return wxGetApp().getLogger();
}

GameRobotInstance& getRobotApp()
{
	return wxGetApp();
}

#endif

#define XLOG appLogger().Message

int BAG_CHECK_TRIES = 1;
int WITHDRAW_TRIES = 2;

withdraw_check::withdraw_check(Role* role)
{
	_fatel_error = 0;
	_role = role;
}

GT_RESULT withdraw_check::Do(GT_RESULT ret, int type)
{
	if( ret != GT_OK)
	{
		XLOG("Withdraw Return Value[%d], type Value[%d]", ret, type);
		setWithdrawError(ret, type);
	}
	if(!_role->checkBag(BAG_CHECK_TRIES))
	{
		ret = GT_FALSE;
	}
	return ret;
}

void withdraw_check::setWithdrawError(int ret, int npc)
{
	int error = 0;
	switch(ret)
	{
	case GT_SECONDPWDERROR:
		if(npc==WithDrawMethod::WD_EXCHANGE)
		{
			XLOG("Ԫ�������ʻ��������");
			error = GT_ERR_2110;
		}
		else if(npc==WithDrawMethod::WD_WAREHOUSE)
		{
			XLOG("�ֿ��������");
			error = GT_ERR_2020;
		}
		break;
	}

	if(_fatel_error)
		return;

	_fatel_error = error;

}

void withdraw_check::errorCheck()
{
	//XLOG("_fatel_error [%d]", _fatel_error);
	if(_fatel_error)
	{
		switch(_fatel_error)
		{
		case GT_ERR_2020:
			throw(robot_error(GT_ERR_2020, "�ֿ��������"));
			break;

		case GT_ERR_2110:
			throw(robot_error(GT_ERR_2110, "�������루Ԫ�������ʻ����룩����"));
			break;

		default:
			throw(robot_error(GT_ERR_3120, "���ɿ�����"));
		}
	}
}

mhzx_impl::mhzx_impl(void)
:_role(&_wrap)
,_exchange(&_wrap, WithDrawMethod::WD_EXCHANGE)
,_warehouse(&_wrap)
,_shop(&_wrap, WithDrawMethod::WD_BANK)
,_mailbox(&_wrap)
,_withdrawCheck(&_role)
{
	_exchange.setName("���Ԫ�������ʺ�");
	_warehouse.setName("��Ҳֿ�");
	_shop.setName("�̵����Ա");
	_mailbox.setName("�������");

	_answerStub.setMask(1,2);
	_answerStub.setMask(2,2);
	_answerStub.setMask(3,2);
	_wrap.addChecker(&_answerStub);
}

mhzx_impl::~mhzx_impl(void)
{
}

void mhzx_impl::auth_validate(int type, std::string secret)
{
	_answerStub.doCheck(type, secret);
}

void mhzx_impl::task_MailPost(gtr::GameTaskResultT& result)
{
	_tasklet.post.buyerMoney /= 10000;
	_tasklet.post.money /= 10000;

	XLOG("������Ϊ%s",(char*)_tasklet.no.c_str());
	XLOG("�������������Ϊ%lld",_tasklet.post.buyerMoney);
	XLOG("�������Ľ������Ϊ%lld",_tasklet.post.money);
	XLOG("�������Ϊ%s",_tasklet.post.buyerActor.c_str());
	XLOG("��������Ϊ%s",_tasklet.post.sellerActor.c_str());
	XLOG("�����д�����ϢΪ%s",_tasklet.area.c_str());
	XLOG("������С����ϢΪ%s",_tasklet.server.c_str());
	XLOG("�������˺���ϢΪ%s",_tasklet.account.c_str());
	//XLOG("�������Ԫ���ʻ�����Ϊ%s",_tasklet.post.bankPwd.c_str());
	//XLOG("�����ֿ����Ϊ%s",_tasklet.post.sellerSecondPwd.c_str());

	_wrap.Initialize(&_gamectx);

	doPost(result);

	if(result.result==0)
	{
		doPostCheck(result);

	}

	XLOG("���ط������Ľ��׽��Ϊ%d",(int)result.result);
}

void mhzx_impl::doPostCheck(gtr::GameTaskResultT& result)
{
	int rv;
	/*
	������Ϸ
	*/
	rv = _wrap.Begin();
	if(rv==GT_TRUE)
	{
		XLOG("��Ϸ�����ɹ�");
	}
	else
	{
		XLOG("��Ϸ����ʧ��");
	}

	/*
	�м�Ĵ������
	*/

	try
	{
		_role.Login(_tasklet);

		if( _role.checkBag(3) )
		{
			result.result = GT_ERR_1000;
		}
		else
		{
			result.result = GT_ERR_3120;
		}
		
	}
	catch (robot_error err)
	{
		result.result = err.code;
		XLOG("%s", err.message.c_str());
	}
	catch (int ret)
	{
		result.result = ret;
	}

	/*
	�ر���Ϸ
	*/
	_wrap.End();
}

void mhzx_impl::doPost(gtr::GameTaskResultT& result)
{
	int rv;
	/*
	������Ϸ
	*/
	rv = _wrap.Begin();
	if(rv==GT_TRUE)
	{
		XLOG("��Ϸ�����ɹ�");
	}
	else
	{
		XLOG("��Ϸ����ʧ��");
	}

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

		doBusiness(_tasklet, result);
	}
	catch (robot_error err)
	{
		result.result = err.code;
		XLOG("%s", err.message.c_str());
	}
	catch (int ret)
	{
		result.result = ret;
	}

	/*
	�ر���Ϸ
	*/
	_wrap.End();

}

void mhzx_impl::validating()
{
	/*
	�ж��������Ľ�������Ƿ����������Ľ������
	*/
	if( _tasklet.post.money < _tasklet.post.buyerMoney )
	{
		extern void _debug_loop();
		//_debug_loop();

		throw(robot_error(GT_ERR_2030,"�������Ľ������С�������Ľ������"));
	}

	//XLOG("������Ϊ%s",(char*)_tasklet.no.c_str());
	//XLOG("�������������Ϊ%d",_tasklet.post.buyerMoney);
	/*
	�ж϶����������
	*/
	if ( _tasklet.post.buyerMoney > 200000 * 10000 )
	{
		throw(robot_error(GT_ERR_3120,"����������"));
	}

}


/*
1. ���ݽ��յ��ý��׵���Ϣ��ѡ����Ϸ�����Լ�������
a. ���������˺ŵ�½����������һ������
b. ��Ϊ���������Լ�����ԭ���ճɲ�������������Ϸ���������Եڶ������ӣ������Ȼ�����������ӣ��������β������ҷ��ر��β��������תΪ�˹����ס�
2.  �Զ���½��Ϸ
a.������½��Ϸ�н�����һ������
b.�˺��������������ܱ�������3��ֱ�ӳ���
c.���ֵ�½�˺�3�ζ���ʾ�����˺ű�ϵͳ���ᣬֱ�ӳ���

*/
enum Gt_MoveType{
	Gt_MoveWareHouse = 0,
	Gt_MoveShop,
};

int mhzx_impl::roleAtWhichMap()
{
	int returnvalue;

	vector<char> buf(255);
	_gamectx.xtype = 1;
	_gamectx.xdata = buf.begin()._Myptr;
	_gamectx.xsize = 255;
	returnvalue = _wrap.IsInMap(0);
	if(returnvalue != GT_OK)
	{
		XLOG("���ܻ�ȡ������ڵ�ͼ��Ϣ");
		return -1;
		//throw(robot_error(0, "���ܻ�ȡ������ڵ�ͼ��Ϣ"));
	}
	string mapname;
	mapname.assign(buf.begin()._Myptr, 255);
	XLOG("������ڵ�ͼΪ: %s", mapname.c_str());
	mapname = mapname.c_str();

#if 0
	if(mapname.find("����") != -1)
		return 0;

	if(mapname.find("����") != -1)
		return 1;

	if(mapname.find("������") != -1)
		return 2;

	if(mapname.find("�Ͻ�") != -1)
		return 3;
#endif
	if(mapname == "����")
		return 0;

	if(mapname == "����")
		return 1;

	if(mapname == "������")
		return 2;

	if(mapname == "�Ͻ�")
		return 3;

	return -1;
}

void mhzx_impl::moveToWarehouse()
{
	int which = roleAtWhichMap();
	if(which<0)
	{
		XLOG("������ڵ�ͼû�вֿ���̵����Ա");

		_role.BackHome();
	}

	int returnvalue;
	returnvalue = _wrap.MoveToByNpcID(Gt_MoveWareHouse);
	if(returnvalue == GT_OK)
	{
		XLOG("�ߵ��ֿ�NPC�ɹ�");
	}
	else
	{
		XLOG("�ߵ��ֿ�NPCʧ��(%d)", returnvalue);
		throw(make_error(returnvalue));
	}
}

void mhzx_impl::moveToShop()
{
	int which = roleAtWhichMap();
	if(which!=0)
	{
		XLOG("��Ҳ��ھ���");

		_role.BackHome();
	}

	int returnvalue;
	returnvalue = _wrap.MoveToByNpcID(Gt_MoveShop);
	if(returnvalue == GT_OK)
	{
		XLOG("�ߵ��̵�NPC�ɹ�");
	}
	else
	{
		XLOG("�ߵ��̵�NPCʧ��(%d)", returnvalue);
		throw(make_error(returnvalue));
	}
}

/*
�ֿ�����	�̵����Ա����	
����	590.289		520.252		
����	257.243		
�Ͻ�	40.363		
������	341.65	
*/
void mhzx_impl::_sendMail(gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	XLOG("�����еĽ�ұȶ����н�Ҷ�");

	tasklet.post.buyerMoney -= 500;

	//mailbox.Create();	// talk & openmailbox & isunlocked
	_mailbox.WaitUnLocked();	
	_mailbox.sendMail(tasklet);
	if(_role.checkBag(BAG_CHECK_TRIES))
	{
		XLOG("�����ʼ��󱳰����Ϊ%lld",_role.baggold);
		taskresult.result = GT_ERR_1000;
	}
	else
	{
		XLOG("�����ʼ��󣬱������û�仯");
		taskresult.result = GT_ERR_3120;
	}
}

void mhzx_impl::_withdrawFromShop(INT64 withdraw)
{
	if(_shop.getNumber(GT_ITEM_1) > 0)
	{
		int tries = WITHDRAW_TRIES;
		do 
		{
			tries--;
			_shop.setWithdrawNum(withdraw);
			int ret = _shop.WithdrawItems(GT_ITEM_1, &_withdrawCheck);
			//if( _shop.getNumber(GT_ITEM_1)!=0)
			//	break;
			if(ret == GT_OK)
				break;
		} while (tries);
	}
}

void mhzx_impl::_withdrawFromMailbox(INT64 withdraw)
{
	_mailbox.setWithdrawNum(withdraw);
	//_mailbox.QueryItems(GT_ITEM_1);
	//INT64 gold3 = _mailbox.getNumber(GT_ITEM_1);
	_mailbox.setActionMask(MASK_ISEXIST | MASK_OPEN | MASK_MOVETO | MASK_TALK);
	int ret = _mailbox.WithdrawItems(GT_ITEM_1, &_withdrawCheck);
}

void mhzx_impl::_withdrawFromExchange(INT64 withdraw, string passwd)
{
	if(passwd=="")
		passwd = "123456";
	_gamectx.xtype = 2;
	_gamectx.xsize = passwd.size();
	_gamectx.xdata = (char*) passwd.c_str();

	//XLOG("���Ԫ�������ʻ�����:%s", passwd.c_str() );
	_exchange.setActionMask(MASK_ISEXIST | MASK_OPEN | MASK_MOVETO | MASK_TALK);


	if(_exchange.getNumber(GT_ITEM_1) > 0)
	{
		if(_exchange.getNumber(GT_ITEM_1) < withdraw)
			withdraw = _exchange.getNumber(GT_ITEM_1);

		int tries = WITHDRAW_TRIES;
		do 
		{
			tries--;
			_exchange.setWithdrawNum(withdraw);
			int ret = _exchange.WithdrawItems(GT_ITEM_1, &_withdrawCheck);
			if(ret==GT_OK)
				break;
		} while (tries);

	}

}

void mhzx_impl::_withdrawFromWarehouse(INT64 withdraw, string passwd)
{

	if( _warehouse.getNumber(GT_ITEM_1) > 0 )
	{
		if(_warehouse.getNumber(GT_ITEM_1) < withdraw)
			withdraw = _warehouse.getNumber(GT_ITEM_1);

		moveToWarehouse();

		if ( true )//_role.IsNearByNpc(MHZX_NPC_WAREHOUSE) )
		{
			XLOG("�����ֿ�NPC");
			//XLOG("��Ҳֿ����:%s", passwd.c_str() );

			if(passwd=="")
				passwd = "123456";
			_gamectx.xtype = 3;
			_gamectx.xsize = passwd.size();
			_gamectx.xdata = (char*) passwd.c_str();

			int tries = WITHDRAW_TRIES;
			do 
			{
				tries--;
				_warehouse.setWithdrawNum(withdraw);
				int ret = _warehouse.WithdrawItems(GT_ITEM_1, &_withdrawCheck);
				if(ret==GT_OK)
					break;
			} while (tries);
		}
		else
		{
			XLOG("�������ֿ�NPC");
		}

	}
}

void mhzx_impl::doBusiness(gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{

	int returnvalue;


	validating();

	/*
	��Ϸ��¼
	*/
	_role.Login(_tasklet);

	_role.QueryLevel();

	_role.QuerySafeTime(SAFE_TIME);

	/*
	��ѯ�������
	*/
	_role.QueryBag();

	/*
	�����н�ҵ�λ�ǽ�
	��ȡ�Ľ�ҵ�λ��ͭ
	1�� = 100�� = 10000ͭ
	*/
	if ( _role.baggold >= tasklet.post.buyerMoney )
	{

		_sendMail(tasklet, taskresult);
		return;

	}
	else
	{
		XLOG("�����еĽ�ұȶ����н����");

		/*
		��ѯԪ�������˻����
		*/
		_exchange.setActionMask(MASK_ISEXIST | MASK_OPEN | MASK_MOVETO | MASK_TALK);
		_exchange.QueryItems(GT_ITEM_1);
		INT64 gold1 = _exchange.getNumber(GT_ITEM_1);

		//if(gold1 + _role.baggold >= tasklet.post.buyerMoney)
		{
			INT64 withdraw = tasklet.post.buyerMoney - _role.baggold;
			_withdrawFromExchange(withdraw, tasklet.post.bankPwd);
			if (  _role.baggold >= tasklet.post.buyerMoney )
			{
				_sendMail(tasklet, taskresult);
				return;
			}
			gold1 = 0;
		}

		/*
		������ȡǮ(��ѯ�ʲ���)
		*/
		_withdrawFromMailbox(-1);

		if(gold1 + _role.baggold >= tasklet.post.buyerMoney)
		{
			if (  _role.baggold >= tasklet.post.buyerMoney )
			{
				_sendMail(tasklet, taskresult);
				return;
			}
			else
			{
				if(gold1 != 0)
				{
					INT64 withdraw = tasklet.post.buyerMoney - _role.baggold;
					_withdrawFromExchange(withdraw, tasklet.post.bankPwd);
					gold1 = 0;

				}
				if (  _role.baggold >= tasklet.post.buyerMoney )
				{
					_sendMail(tasklet, taskresult);
					return;
				}
			}
		}

		/*
		��ѯ�ֿ���
		*/
		_warehouse.QueryItems(GT_ITEM_1);
		INT64 gold2 = _warehouse.getNumber(GT_ITEM_1);
		//if(gold1 + gold2 + _role.baggold >= tasklet.post.buyerMoney)
		{
			INT64 withdraw = tasklet.post.buyerMoney - _role.baggold;
			if(gold1!=0)
			{
				_withdrawFromExchange(withdraw, tasklet.post.bankPwd);
				withdraw = tasklet.post.buyerMoney - _role.baggold;
			}
			_withdrawFromWarehouse(withdraw, tasklet.post.sellerSecondPwd);
			if (  _role.baggold >= tasklet.post.buyerMoney )
			{
				_sendMail(tasklet, taskresult);
				return;
			}
			gold2 = 0;
		}

		/*
		���㹻��ҽ��н��ף���ѯ�̵���,�жϽ�ɫ��ǰ�ȼ�
		*/
		if(_role._level >= 30)
		{
			/*
			ȥ�̵����Ա����Ƿ��н��
			*/
			moveToShop();
			_shop.QueryItems(GT_ITEM_1);
			//INT64 gold4 = _shop.getNumber(GT_ITEM_1);
			INT64 withdraw = tasklet.post.buyerMoney - _role.baggold;
			_withdrawFromShop(withdraw);//gold4);//0x7FFFFFFF);

			if(gold1 + gold2 +  _role.baggold >= tasklet.post.buyerMoney)
			{
				if (  _role.baggold >= tasklet.post.buyerMoney )
				{
					_sendMail(tasklet, taskresult);
					return;
				}
				else
				{
					if(gold1 != 0)
					{
						INT64 withdraw = tasklet.post.buyerMoney - _role.baggold;
						_withdrawFromExchange(withdraw, tasklet.post.bankPwd);
						if (  _role.baggold >= tasklet.post.buyerMoney )
						{
							_sendMail(tasklet, taskresult);
							return;
						}
						gold1 = 0;
					}

					if(gold2 != 0)
					{
						INT64 withdraw = tasklet.post.buyerMoney - _role.baggold;
						_withdrawFromWarehouse(withdraw, tasklet.post.sellerSecondPwd);
						if (  _role.baggold >= tasklet.post.buyerMoney )
						{
							_sendMail(tasklet, taskresult);
							return;
						}
						gold2 = 0;
					}

					if (  _role.baggold >= tasklet.post.buyerMoney )
					{
						_sendMail(tasklet, taskresult);
						return;
					}
				}
				
			}
			else
			{
				_withdrawCheck.errorCheck();
				/*
				���㷢�����
				*/
				throw(robot_error(GT_ERR_2030, "û���㹻��Ǯ"));

			}
		}
		else
		{
			_withdrawCheck.errorCheck();

			throw(robot_error(GT_ERR_2030, "��ɫ��ǰ�ȼ�û�е���30��"));
		}

	}

	_withdrawCheck.errorCheck();

	XLOG("�����������С�ڶ�������");

	/*
	���㷢�����
	*/
	throw(robot_error(GT_ERR_2030, "û���㹻��Ǯ"));

#if 0
	/*
	��Ԫ�������˻�ȡ���
	*/
	if( _role.baggold < tasklet.post.buyerMoney )
	{
		int withdraw = tasklet.post.buyerMoney - _role.baggold;
		_withdrawFromExchange(withdraw, tasklet.post.bankPwd);
	}

	/*
	�Ӳֿ�ȡ���
	*/
	if(_role.baggold < tasklet.post.buyerMoney)
	{
		int withdraw = tasklet.post.buyerMoney - _role.baggold;
		_withdrawFromWarehouse(withdraw, tasklet.post.sellerSecondPwd);
	}

	/*
	���ͽ��
	*/
	if (  _role.baggold >= tasklet.post.buyerMoney )
	{
		_sendMail(tasklet, taskresult);
	}
	else
	{
		XLOG("�����������С�ڶ�������");

		/*
		���㷢�����
		*/
		throw(robot_error(GT_ERR_2030, "û���㹻��Ǯ"));
	}
#endif
}

