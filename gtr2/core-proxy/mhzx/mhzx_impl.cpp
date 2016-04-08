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
			XLOG("元宝交易帐户密码错误");
			error = GT_ERR_2110;
		}
		else if(npc==WithDrawMethod::WD_WAREHOUSE)
		{
			XLOG("仓库密码错误");
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
			throw(robot_error(GT_ERR_2020, "仓库密码错误"));
			break;

		case GT_ERR_2110:
			throw(robot_error(GT_ERR_2110, "三级密码（元宝交易帐户密码）错误"));
			break;

		default:
			throw(robot_error(GT_ERR_3120, "不可控因素"));
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
	_exchange.setName("玩家元宝交易帐号");
	_warehouse.setName("玩家仓库");
	_shop.setName("商店管理员");
	_mailbox.setName("玩家邮箱");

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

	XLOG("订单号为%s",(char*)_tasklet.no.c_str());
	XLOG("买家需求金币数量为%lld",_tasklet.post.buyerMoney);
	XLOG("卖家卖的金币数量为%lld",_tasklet.post.money);
	XLOG("买家姓名为%s",_tasklet.post.buyerActor.c_str());
	XLOG("卖家姓名为%s",_tasklet.post.sellerActor.c_str());
	XLOG("订单中大区信息为%s",_tasklet.area.c_str());
	XLOG("订单中小区信息为%s",_tasklet.server.c_str());
	XLOG("订单中账号信息为%s",_tasklet.account.c_str());
	//XLOG("订单玩家元宝帐户口令为%s",_tasklet.post.bankPwd.c_str());
	//XLOG("订单仓库口令为%s",_tasklet.post.sellerSecondPwd.c_str());

	_wrap.Initialize(&_gamectx);

	doPost(result);

	if(result.result==0)
	{
		doPostCheck(result);

	}

	XLOG("返回服务器的交易结果为%d",(int)result.result);
}

void mhzx_impl::doPostCheck(gtr::GameTaskResultT& result)
{
	int rv;
	/*
	启动游戏
	*/
	rv = _wrap.Begin();
	if(rv==GT_TRUE)
	{
		XLOG("游戏启动成功");
	}
	else
	{
		XLOG("游戏启动失败");
	}

	/*
	中间的处理过程
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
	关闭游戏
	*/
	_wrap.End();
}

void mhzx_impl::doPost(gtr::GameTaskResultT& result)
{
	int rv;
	/*
	启动游戏
	*/
	rv = _wrap.Begin();
	if(rv==GT_TRUE)
	{
		XLOG("游戏启动成功");
	}
	else
	{
		XLOG("游戏启动失败");
	}

	/*
	中间的处理过程
	*/

	try
	{
		_gamectx.timeout = -1;
		/*
		预定义默认的返回结果
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
	关闭游戏
	*/
	_wrap.End();

}

void mhzx_impl::validating()
{
	/*
	判断卖家卖的金币数额是否满足买家买的金币数额
	*/
	if( _tasklet.post.money < _tasklet.post.buyerMoney )
	{
		extern void _debug_loop();
		//_debug_loop();

		throw(robot_error(GT_ERR_2030,"卖家卖的金币数额小于买家买的金币数额"));
	}

	//XLOG("订单号为%s",(char*)_tasklet.no.c_str());
	//XLOG("买家需求金币数量为%d",_tasklet.post.buyerMoney);
	/*
	判断订单金币数量
	*/
	if ( _tasklet.post.buyerMoney > 200000 * 10000 )
	{
		throw(robot_error(GT_ERR_3120,"订单超限了"));
	}

}


/*
1. 根据接收到得交易单信息，选择游戏大区以及服务器
a. 正常进入账号登陆界面后进行下一步操作
b. 因为网络阻塞以及其他原因照成不能正常连接游戏服务器则尝试第二次连接，如果仍然不能正常连接，结束本次操作并且返回本次操作结果，转为人工交易。
2.  自动登陆游戏
a.正常登陆游戏有进行下一步操作
b.账号密码错误或输入密保卡错误3次直接撤单
c.出现登陆账号3次都显示：该账号被系统冻结，直接撤单

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
		XLOG("不能获取玩家所在地图信息");
		return -1;
		//throw(robot_error(0, "不能获取玩家所在地图信息"));
	}
	string mapname;
	mapname.assign(buf.begin()._Myptr, 255);
	XLOG("玩家所在地图为: %s", mapname.c_str());
	mapname = mapname.c_str();

#if 0
	if(mapname.find("京城") != -1)
		return 0;

	if(mapname.find("河阳") != -1)
		return 1;

	if(mapname.find("大王村") != -1)
		return 2;

	if(mapname.find("南疆") != -1)
		return 3;
#endif
	if(mapname == "京城")
		return 0;

	if(mapname == "河阳")
		return 1;

	if(mapname == "大王村")
		return 2;

	if(mapname == "南疆")
		return 3;

	return -1;
}

void mhzx_impl::moveToWarehouse()
{
	int which = roleAtWhichMap();
	if(which<0)
	{
		XLOG("玩家所在地图没有仓库和商店管理员");

		_role.BackHome();
	}

	int returnvalue;
	returnvalue = _wrap.MoveToByNpcID(Gt_MoveWareHouse);
	if(returnvalue == GT_OK)
	{
		XLOG("走到仓库NPC成功");
	}
	else
	{
		XLOG("走到仓库NPC失败(%d)", returnvalue);
		throw(make_error(returnvalue));
	}
}

void mhzx_impl::moveToShop()
{
	int which = roleAtWhichMap();
	if(which!=0)
	{
		XLOG("玩家不在京城");

		_role.BackHome();
	}

	int returnvalue;
	returnvalue = _wrap.MoveToByNpcID(Gt_MoveShop);
	if(returnvalue == GT_OK)
	{
		XLOG("走到商店NPC成功");
	}
	else
	{
		XLOG("走到商店NPC失败(%d)", returnvalue);
		throw(make_error(returnvalue));
	}
}

/*
仓库坐标	商店管理员坐标	
京城	590.289		520.252		
河阳	257.243		
南疆	40.363		
大王村	341.65	
*/
void mhzx_impl::_sendMail(gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	XLOG("背包中的金币比订单中金币多");

	tasklet.post.buyerMoney -= 500;

	//mailbox.Create();	// talk & openmailbox & isunlocked
	_mailbox.WaitUnLocked();	
	_mailbox.sendMail(tasklet);
	if(_role.checkBag(BAG_CHECK_TRIES))
	{
		XLOG("发完邮件后背包金币为%lld",_role.baggold);
		taskresult.result = GT_ERR_1000;
	}
	else
	{
		XLOG("发完邮件后，背包金币没变化");
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

	//XLOG("玩家元宝交易帐户口令:%s", passwd.c_str() );
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
			XLOG("靠近仓库NPC");
			//XLOG("玩家仓库口令:%s", passwd.c_str() );

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
			XLOG("不靠近仓库NPC");
		}

	}
}

void mhzx_impl::doBusiness(gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{

	int returnvalue;


	validating();

	/*
	游戏登录
	*/
	_role.Login(_tasklet);

	_role.QueryLevel();

	_role.QuerySafeTime(SAFE_TIME);

	/*
	查询背包金币
	*/
	_role.QueryBag();

	/*
	订单中金币单位是金。
	获取的金币单位是铜
	1金 = 100银 = 10000铜
	*/
	if ( _role.baggold >= tasklet.post.buyerMoney )
	{

		_sendMail(tasklet, taskresult);
		return;

	}
	else
	{
		XLOG("背包中的金币比订单中金币少");

		/*
		查询元宝交易账户金币
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
		从邮箱取钱(查询邮差金币)
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
		查询仓库金币
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
		无足够金币进行交易，查询商店金币,判断角色当前等级
		*/
		if(_role._level >= 30)
		{
			/*
			去商店管理员检测是否有金币
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
				不足发货金币
				*/
				throw(robot_error(GT_ERR_2030, "没有足够的钱"));

			}
		}
		else
		{
			_withdrawCheck.errorCheck();

			throw(robot_error(GT_ERR_2030, "角色当前等级没有到达30级"));
		}

	}

	_withdrawCheck.errorCheck();

	XLOG("背包金币数量小于订单需求");

	/*
	不足发货金币
	*/
	throw(robot_error(GT_ERR_2030, "没有足够的钱"));

#if 0
	/*
	从元宝交易账户取金币
	*/
	if( _role.baggold < tasklet.post.buyerMoney )
	{
		int withdraw = tasklet.post.buyerMoney - _role.baggold;
		_withdrawFromExchange(withdraw, tasklet.post.bankPwd);
	}

	/*
	从仓库取金币
	*/
	if(_role.baggold < tasklet.post.buyerMoney)
	{
		int withdraw = tasklet.post.buyerMoney - _role.baggold;
		_withdrawFromWarehouse(withdraw, tasklet.post.sellerSecondPwd);
	}

	/*
	发送金币
	*/
	if (  _role.baggold >= tasklet.post.buyerMoney )
	{
		_sendMail(tasklet, taskresult);
	}
	else
	{
		XLOG("背包金币数量小于订单需求");

		/*
		不足发货金币
		*/
		throw(robot_error(GT_ERR_2030, "没有足够的钱"));
	}
#endif
}

