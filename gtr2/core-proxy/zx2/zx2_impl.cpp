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
	启动游戏
	*/
	_gamectx.apilist->Begin(&_gamectx);
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
	关闭游戏
	*/
	_gamectx.apilist->End(&_gamectx);

	getLogger().Message("返回服务器的交易结果为%d",(int)result.result);
}

void zx2_impl::validating()
{
	/*
	判断卖家卖的金币数额是否满足买家买的金币数额
	*/
	if( _tasklet.post.money < _tasklet.post.buyerMoney )
	{
		throw(robot_error(GT_ERR_2030,"卖家卖的金币数额小于买家买的金币数额"));
	}

	getLogger().Message("订单号为%s",(char*)_tasklet.no.c_str());
	getLogger().Message("买家需求金币数量为%d",_tasklet.post.buyerMoney);
	/*
	判断订单金币数量
	*/
	if ( _tasklet.post.buyerMoney > 200000 * 10000 )
	{
		throw(robot_error(GT_ERR_3120,"订单超限了"));
	}

}

void zx2_impl::login(CALLCTX* call,gtr::GameTaskletT& tasklet)
{
	int i;
	int returnvalue;

	/*
	选大区流程
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
			返回值大区无法连接,转人工
			*/
			throw(robot_error(GT_ERR_3000, "连接大区失败"));
		}
		else
		{
			
			throw(make_error(returnvalue));		
		}
	}

	getLogger().Message("连接大区成功");

	/*
	选小区流程
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
			返回值小区无法连接,转人工
			*/
			throw(robot_error(GT_ERR_3020,"连接小区失败"));
		}
		else
		{
			throw(make_error(returnvalue));		
		}
	}

	getLogger().Message("连接小区成功");

	/*
	账号登陆流程
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
			卖家密码错误l
			*/
			throw(robot_error(GT_ERR_2000,"卖家密码错误"));
		}
		else if ( returnvalue == GT_MBERROR && i != login_trytimes -1 )
		{
			continue;
		}
		else if ( returnvalue == GT_MBERROR && i == login_trytimes -1 )
		{
			/*
			卖家密保上传错误
			*/
			throw(robot_error(GT_ERR_2090,"卖家密保上传错误"));
		}
		else if ( returnvalue == GT_VERSIONERROR )
		{
			/*
			游戏版本错误
			*/
			throw(robot_error(GT_ERR_3120, "游戏版本错误"));
		}
		else if ( returnvalue == GT_PLAYERINLINE )
		{
			/*
			玩家在线
			*/
			throw(robot_error(GT_ERR_3120, "玩家在线"));
		}
		else if ( returnvalue == GT_FALSE && i != login_trytimes -1 )
		{
			continue;
		}
		else if ( returnvalue == GT_FALSE && i == login_trytimes -1 )
		{
			throw(robot_error(GT_ERR_3120, "游戏服务器没开或者可能是密保输入多次错误账号被临时封停"));
		}
		else
		{
			throw(make_error(returnvalue));		
		}
	}

	getLogger().Message("账号登陆成功");

	/*
	选线流程
	*/
	//returnvalue = call->apilist->SelectLineByName("12",call); WAIT();
	returnvalue = call->apilist->SelectLineByIndex(12,call); WAIT();

	if ( returnvalue != GT_OK )
	{
		getLogger().Message("选线失败");

		throw(make_error(returnvalue));		
	}

	getLogger().Message("选择线路成功");

	/*
	选角色流程
	*/
	for ( i = 0; i < selectrole_trytimes; ++i )
	{
		returnvalue = call->apilist->SelectRoleByName((char*)_tasklet.post.sellerActor.c_str(),call); WAIT();

		if ( returnvalue == GT_OK )
		{
			break;
		}

		// 判断角色列表是否为空， 空直接撤单， 名字不匹配转人工
		else if ( returnvalue == GT_NOTEXISTED && i != selectrole_trytimes -1 )
		{
		}
		else if ( returnvalue == GT_NOTEXISTED && i == selectrole_trytimes -1 )
		{
			throw(robot_error(GT_ERR_2010, "选角色失败"));
		}
		else
		{
			throw(make_error(returnvalue));		
		}
	}

	getLogger().Message("选择角色登陆成功");

	/*
	安全时间检测
	*/
	int safetime;
	call->apilist->QuerySafeTime(&safetime,call); WAIT();
	if ( safetime >= SAFE_TIME )
	{
		/*
		返回值安全时间大于2分钟,转人工
		*/
		throw(robot_error(GT_ERR_3030,"安全时间大于2分钟"));
	}

	getLogger().Message("安全时间检测成功");

}

void zx2_impl::_sendMail(CALLCTX *call,gtr::GameTaskletT& tasklet)
{
	int returnvalue;
	/*
	发送邮件
	*/
	returnvalue = call->apilist->SendMail((char*)tasklet.post.buyerActor.c_str(),"youjian","youjian",tasklet.post.buyerMoney,call); WAIT();
	if ( returnvalue == GT_OK )
	{
		getLogger().Message("发邮件成功");
//		taskresult.result = GT_ERR_1000;

		returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)ZX2_GOLD,&baggold,call); WAIT();
		getLogger().Message("发完邮件后背包金币为%d",(int)baggold);
	}
	else if ( returnvalue == GT_NOTEXISTED )
	{
		throw(robot_error(GT_ERR_2050,"买家角色名错误"));
	}
	else if ( returnvalue == GT_MAIlBOXFULL )
	{
		throw(robot_error(GT_ERR_3070, "买家邮箱已满"));
	}
	else if ( returnvalue == GT_MAIlBOXLOCKED )
	{
		throw(robot_error(GT_ERR_3070, "买家邮箱已冻结"));
	}
	else if ( returnvalue == GT_ROLEKICK )
	{
		throw(robot_error(GT_ERR_3050, "卖家顶号"));
	}
	else if ( returnvalue == GT_TIMEOUT )
	{
		throw(robot_error(GT_ERR_3120, "选小区超时"));
	}
	else if ( returnvalue == GT_CONNECTBREAK )
	{
		throw(robot_error(GT_ERR_3120, "连接中断"));
	}
	else
	{
		throw(robot_error(GT_ERR_3120, "其他未知发邮件错误"));
	}

}

bool zx2_impl::_withdraw_mailbox(CALLCTX *call,gtr::GameTaskletT& tasklet)
{
	int returnvalue;
	/*
	判断邮箱中金币，从邮箱中取钱
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
		getLogger().Message("邮箱中有足够的钱");
		returnvalue = call->apilist->WithdrawItemsInMailbox((Gt_GameItemT)ZX2_GOLD,&mailboxgold,call); WAIT();

		if ( returnvalue != GT_OK )
		{
			throw(make_error( returnvalue));
		}

		getLogger().Message("从邮箱取钱成功");

		returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)ZX2_GOLD,&baggold,call); WAIT();

		if ( returnvalue != GT_OK )
		{
			throw(make_error( returnvalue));
		}

		if( baggold >= tasklet.post.buyerMoney )
		{
			getLogger().Message("背包金币数量大于订单需求，取邮箱金币成功");

			return true;
		}
		else
		{
			getLogger().Message("背包金币数量小于订单需求，取邮箱金币失败");
		}
	}
	else
	{
		getLogger().Message("邮箱中没有足够的钱");
	}

	return false;
}

void zx2_impl::_withdraw(CALLCTX *call,gtr::GameTaskletT& tasklet)
{
	int returnvalue;

	/*
	与仓库NPC对话
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
		getLogger().Message("与仓库NPC对话成功");
		/*
		打开仓库
		*/
		returnvalue = call->apilist->OpenWarehouse((char*)tasklet.post.sellerSecondPwd.c_str(),call); WAIT();

		/*
		用空的仓库密码重新尝试一次
		*/
		if ( returnvalue != GT_OK )
		{
			returnvalue = call->apilist->OpenWarehouse("",call); WAIT();

			getLogger().Message("第一次打开仓库失败，使用空密码再尝试打开1次");
		}

		if ( returnvalue == GT_OK )
		{
			getLogger().Message("打开仓库成功");
			/*
			查询仓库内金币
			*/
			INT64 warehousegold = 0;
			returnvalue = call->apilist->QueryItemsInWarehouse((Gt_GameItemT)ZX2_GOLD,&warehousegold,call); WAIT();
			if ( returnvalue == GT_OK )
			{
				getLogger().Message("查询仓库金币成功");
				/*
				判断金币数量
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
			getLogger().Message("卖家提供的2级密码错误");
		}
	}
	else
	{
		getLogger().Message("仓库NPC对话失败");
	}

}

void zx2_impl::doBusiness(CALLCTX* call,gtr::GameTaskletT& tasklet)
{
	int returnvalue;

	/*
	查询背包金币
	*/
	returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)ZX2_GOLD,&baggold,call);
	if ( returnvalue != GT_OK )
	{
		getLogger().Message("查询背包金币失败");

		throw(make_error(returnvalue));
		
	}

	getLogger().Message("第1次查询背包金币为%d",(int)baggold);


	/*
	订单中金币单位是金。
	获取的金币单位是铜
	1金 = 100银 = 10000铜
	*/
	if ( baggold >= tasklet.post.buyerMoney )
	{
		getLogger().Message("背包中的金币比订单中金币多");

		returnvalue = call->apilist->IsNearBy(ZX2_NPC_MAILBOX,call); WAIT();
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			throw(make_error( returnvalue));
		}
		if ( returnvalue == GT_TRUE )
		{
			getLogger().Message("靠近邮箱NPC");

			NPC mailbox(ZX2_NPC_MAILBOX);
			mailbox.Create(call);	// talk & openmailbox & isunlocked
			mailbox.WaitUnLocked(call);	//
			_sendMail(call, tasklet);
			return;
		}
		else
		{
			getLogger().Message("不靠近邮箱NPC");
		}
	}
	else
	{
		getLogger().Message("背包中的金币比订单中金币少");

		/*
		returnvalue = call->apilist->IsNearBy(ZX2_NPC_MAILBOX,call); WAIT();
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			throw(make_error( returnvalue));
		}
		if ( returnvalue == GT_TRUE )
		{
			getLogger().Message("靠近邮箱NPC");

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
			getLogger().Message("不靠近邮箱NPC");
		}
		*/
		returnvalue = call->apilist->IsNearBy(ZX2_NPC_WAREHOUSE,call); WAIT();
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			throw(make_error( returnvalue));
		}
		if ( returnvalue == GT_TRUE )
		{
			getLogger().Message("靠近仓库NPC");

			NPC warehouse(ZX2_NPC_WAREHOUSE);
			warehouse.Create(call);	// talk & openmailbox & isunlocked
			warehouse.WaitUnLocked(call);	//
			_withdraw(call, tasklet);
		}
		else
		{
			getLogger().Message("不靠近邮箱NPC");
		}
	}

	if (backHomeprocess(call)==false)
	{
		/*
		不可控因素
		*/
		throw(robot_error(GT_ERR_3120, "回城失败"));
	}
	getLogger().Message("回城成功");

	if ( baggold >= tasklet.post.buyerMoney )
	{
		getLogger().Message("背包金币比订单中需求金币数额多");
		/*
		从回城点走到邮箱
		*/
		WAIT(true);
		returnvalue = call->apilist->MoveTo(BH2MAILBOX,call); WAIT();
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			throw(make_error( returnvalue));
		}
		if ( returnvalue == GT_OK )
		{
			getLogger().Message("从回城点走到邮箱成功");

			NPC mailbox(ZX2_NPC_MAILBOX);
			mailbox.Create(call);	// talk & openmailbox & isunlocked
			mailbox.WaitUnLocked(call);	//
			_sendMail(call, tasklet);
			return;

		}
		else
		{
			/*
			不可控因素
			*/
			throw(robot_error(GT_ERR_3120, "从回城点走到邮箱失败"));
		}
	}
	else
	{
		getLogger().Message("背包金币比订单中需求金币数额少");
		/*
		回城点移动到仓库
		*/
		WAIT(true);
		returnvalue = call->apilist->MoveTo(BH2WAREHOUSE,call); WAIT();
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			throw(make_error( returnvalue));
		}
		if ( returnvalue == GT_OK )
		{
			getLogger().Message("从回城点走到仓库成功");

			NPC warehouse(ZX2_NPC_WAREHOUSE);
			warehouse.Create(call);	// talk & OpenWarehouse 
			_withdraw(call, tasklet);

		}
		else
		{
			/*
			不可控因素
			*/
			throw(robot_error(GT_ERR_3120, "从回城点走到仓库失败"));
		}

		/*
		仓库移动到邮箱
		*/
		returnvalue = call->apilist->MoveTo(WAREHOUSE2MAILBOX,call); WAIT();
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			throw(make_error( returnvalue));
		}

		if ( returnvalue == GT_OK )
		{
			getLogger().Message("仓库移动到邮箱成功");

			NPC mailbox(ZX2_NPC_MAILBOX);
			mailbox.Create(call);	// talk & openmailbox & isunlocked
			mailbox.WaitUnLocked(call);	//

			/*
			查询背包金币
			*/
			returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)ZX2_GOLD,&baggold,call); WAIT();
			if ( returnvalue != GT_OK )
			{
				throw(make_error( returnvalue));
			}

			if ( baggold >= tasklet.post.buyerMoney )
			{
				getLogger().Message("背包金币数量大于订单需求");
				_sendMail(call, tasklet);
				return;
			}
			else
			{
				getLogger().Message("背包金币数量小于订单需求");

				/*
				判断邮箱中金币，从邮箱中取钱
				*/
				if( _withdraw_mailbox(call, tasklet) )
				{
					_sendMail(call, tasklet);
					return;
				}
				else
				{
					/*
					不足发货金币
					*/
					throw(robot_error(GT_ERR_2030, "没有足够的钱"));
				}
			}
		}
		else
		{
			/*
			不可控因素
			*/
			throw(robot_error(GT_ERR_3120,"仓库移动到邮箱失败"));
		}
	}
}

bool zx2_impl::backHomeprocess(CALLCTX* call)
{
	int returnvalue;
	/*
	检测回城技能
	*/
	returnvalue = call->apilist->IsExistBackHomeSkill(call);
	if ( returnvalue == GT_TRUE )
	{
		getLogger().Message("角色存在回城技能");
		/*
		使用回城技能
		*/
		returnvalue = call->apilist->UseBackHomeSkill(call);
		if ( returnvalue == GT_TRUE )
		{
			getLogger().Message("角色使用回城技能成功");
			return true;
		}
		else if( returnvalue == GT_FALSE )
		{
			getLogger().Message("角色使用回城技能失败");
			/*
			检测回城道具
			*/
			returnvalue = call->apilist->IsExistBackHomeItem(call);
			if ( returnvalue == GT_TRUE )
			{
				getLogger().Message("角色存在回城物品");
				/*
				使用回城道具
				*/
				returnvalue = call->apilist->UseBackHomeItem(call);
				if ( returnvalue == GT_TRUE )
				{
					getLogger().Message("角色使用回城物品成功");
					return true;
				}
				else if ( returnvalue == GT_FALSE )
				{
					getLogger().Message("角色使用回城物品失败");
					return false;
				}
				else
				{
					throw(make_error( returnvalue));
				}
			}
			else if ( returnvalue == GT_FALSE )
			{
				getLogger().Message("角色不存在回城物品");
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
		getLogger().Message("角色不存在回城技能");
		/*
		检测回城道具
		*/
		returnvalue = call->apilist->IsExistBackHomeItem(call);
		if ( returnvalue == GT_TRUE )
		{
			getLogger().Message("角色存在回城物品");
			/*
			使用回城道具
			*/
			returnvalue = call->apilist->UseBackHomeItem(call);
			if ( returnvalue == GT_TRUE )
			{
				getLogger().Message("角色使用回城物品成功");
				return true;
			}
			else if ( returnvalue == GT_FALSE )
			{
				getLogger().Message("角色使用回城物品失败");
				return false;
			}
			else
			{
				throw(make_error( returnvalue));
			}
		}
		else if ( returnvalue == GT_FALSE )
		{
			getLogger().Message("角色不存在回城物品");
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
		return robot_error(GT_ERR_3120,"上一步操作失败导致无法继续");
	}
	else if ( returnvalue == GT_NOTEXISTED )
	{
		return robot_error(GT_ERR_2050,"上一步操作返回买家角色名错误");
	}
	else if ( returnvalue == GT_MAIlBOXFULL )
	{
		return robot_error(GT_ERR_3070,"上一步操作返回买家邮箱已满");
	}
	else if ( returnvalue == GT_MAIlBOXLOCKED )
	{
		return robot_error(GT_ERR_3070,"上一步操作返回买家邮箱已冻结");
	}
	else if ( returnvalue == GT_ROLEKICK )
	{
		return robot_error(GT_ERR_3050, "上一步操作返回卖家顶号");
	}
	else if ( returnvalue == GT_TIMEOUT )
	{
		return robot_error(GT_ERR_3120,"上一步操作超时");
	}
	else if ( returnvalue == GT_CONNECTBREAK )
	{
		return robot_error(GT_ERR_3120,"连接中断");
	}
	else if ( returnvalue == GT_UNABLEMOVETO )
	{
		return robot_error(GT_ERR_3120,"无法到达目标NPC");
	}
	else if ( returnvalue == GT_UNABLETALKTO )
	{
		return robot_error(GT_ERR_3120,"无法对话目标NPC");
	}
	//else if ( returnvalue == GT_INSAFETIME )
	//{
	//	return robot_error(GT_ERR_3120,"在安全时间中导致上一步的操作失败");
	//}
	else
	{
		return robot_error(GT_ERR_3120,"");
	}
}