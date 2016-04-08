
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
		throw(robot_error(GT_ERR_3120, "机器人运行超时(超时设置180秒)"));
		return true;
	}
	return false;
}

void ZX2_Mailpost::task_MailPost(gtr::GameTaskResultT& result)
{
	_tmStart = time(NULL);

	XLOG("订单号为%s",(char*)_tasklet.no.c_str());
	XLOG("买家需求金币数量为%lld",_tasklet.post.buyerMoney);
	XLOG("卖家卖的金币数量为%lld",_tasklet.post.money);
	XLOG("买家姓名为%s",_tasklet.post.buyerActor.c_str());
	XLOG("卖家姓名为%s",_tasklet.post.sellerActor.c_str());
	XLOG("订单中大区信息为%s",_tasklet.area.c_str());
	XLOG("订单中小区信息为%s",_tasklet.server.c_str());
	XLOG("订单中账号信息为%s",_tasklet.account.c_str());


	for(int i=0; i<2; i++)
	{
		if( task_process(result) )
			break;
	}

	if ( (result.result == GT_ERR_2030 || result.result == GT_ERR_3120) && warehouseRvalue == GT_ERR_2020 )
	{
		result.result = GT_ERR_2020;
	}

	XLOG("返回服务器的交易结果为%d",(int)result.result);
}

bool ZX2_Mailpost::task_process(gtr::GameTaskResultT& result)
{
	bool ret = true;

	/*
	启动游戏
	*/
	_gamectx.apilist->Begin(&_gamectx);

	try
	{
		/*
		中间的处理过程
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
	关闭游戏
	*/
	_gamectx.apilist->End(&_gamectx);

	return ret;

}

void ZX2_Mailpost::run(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	call->timeout = TIMEOUT_120;
	/*
	预定义默认的返回结果
	*/
	taskresult.result = GT_ERR_3120;

	/*
	判断卖家卖的金币数额是否满足买家买的金币数额
	*/
	if( tasklet.post.money < tasklet.post.buyerMoney )
	{
		taskresult.result = GT_ERR_2030;

		XLOG("卖家卖的金币数额小于买家买的金币数额");

		return;
	}

	/*
	判断订单金币数量
	*/
	if ( tasklet.post.buyerMoney > 200000 * 10000 )
	{
		XLOG("订单超限了");
		return;
	}

	int i;
	int returnvalue;

	/*
	选大区流程
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
			返回值大区无法连接,转人工
			*/
			taskresult.result = GT_ERR_3000;
			XLOG("连接大区失败");
			return;
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
	}

	XLOG("连接大区成功");

	/*
	选小区流程
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
			返回值小区无法连接,转人工
			*/
			taskresult.result = GT_ERR_3020;
			XLOG("连接小区失败");
			return;
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
	}

	XLOG("连接小区成功");

	/*
	账号登陆流程
	*/
	for ( i = 0; i < login_trytimes; ++i )
	{
		isTimeout();
		returnvalue = call->apilist->Login(const_cast<char*>(tasklet.account.c_str()),const_cast<char*>(tasklet.password.c_str()),call);

		getLogger().Message("密保卡超时计数%d次", _mbkTimeout);
		if(_mbkTimeout==2)
		{
			XLOG("密保卡超时2次");
			taskresult.result = GT_ERR_3120;
			return;
		}

		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_PASSWORDERROR && i != login_trytimes - 1 )
		{
			XLOG("第%d次登录中密码错误", i + 1);
			continue;
		}
		else if ( returnvalue == GT_PASSWORDERROR && i == login_trytimes - 1 )
		{
			/*
			卖家密码错误l
			*/
			taskresult.result = GT_ERR_2000;

			XLOG("卖家密码错误");
			return;
		}
		else if ( returnvalue == GT_MBERROR && i != login_trytimes -1 )
		{
			XLOG("第%d次密保卡错误", i + 1);
			continue;
		}
		else if ( returnvalue == GT_MBERROR && i == login_trytimes -1 )
		{
			/*
			卖家密保上传错误
			*/
			taskresult.result = GT_ERR_2090;

			XLOG("卖家密保上传错误");
			return;
		}
		else if ( returnvalue == GT_VERSIONERROR )
		{
			/*
			游戏版本错误
			*/
			XLOG("游戏版本错误");
			return;
		}
		else if ( returnvalue == GT_PLAYERINLINE )
		{
			/*
			玩家在线
			*/
			XLOG("玩家在线");
			return;
		}
		else if ( returnvalue == GT_FALSE && i != login_trytimes -1 )
		{
			XLOG("第%d次登录失败", i + 1);
			continue;
		}
		else if ( returnvalue == GT_FALSE && i == login_trytimes -1 )
		{
			XLOG("游戏服务器没开或者可能是密保输入多次错误账号被临时封停");
			return;
		}
		else if ( returnvalue == GT_CONNECTBREAK && i != login_trytimes -1 )
		{
			XLOG("第%d次登录过程连接中断", i + 1);
			continue;
		}
		else if ( returnvalue == GT_CONNECTBREAK && i == login_trytimes -1 )
		{
			XLOG("登陆并答题2次没成功，连接中断了");
			return;
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
	}

	XLOG("账号登陆成功");

	/*
	选线流程
	*/
	isTimeout();
	returnvalue = call->apilist->SelectLineByName("",call);

	if ( returnvalue != GT_OK )
	{
		XLOG("选线失败");

		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}

	XLOG("选择线路成功");

	/*
	选角色流程
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
			XLOG("登录角色%s失败",_tasklet.post.sellerActor.c_str());

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

	XLOG("选择角色%s登陆成功",_tasklet.post.sellerActor.c_str());

	/*
	安全时间检测
	*/
	isTimeout();
	int safetime;
	call->apilist->QuerySafeTime(&safetime,call);
	if ( safetime >= SAFE_TIME )
	{
		/*
		返回值安全时间大于2分钟,转人工
		*/
		taskresult.result = GT_ERR_3030;

		XLOG("安全时间大于等于2分钟");
		return;
	}

	XLOG("安全时间小于2分钟");

	/*
	查询背包金币
	*/
	isTimeout();
	returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)ZX2_GOLD,&baggold,call);
	if ( returnvalue != GT_OK )
	{
		XLOG("查询背包金币失败");
		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}

	XLOG("第1次查询背包金币为%d",(int)baggold);

	/*
	订单中金币单位是金。
	获取的金币单位是铜
	1金 = 100银 = 10000铜
	*/
	if ( baggold >= tasklet.post.buyerMoney )
	{
		XLOG("背包中的金币比订单中金币多");

		isTimeout();
		returnvalue = _gamectx.apilist->IsNearBy(ZX2_NPC_MAILBOX,call);
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
		if ( returnvalue == GT_TRUE )
		{
			XLOG("靠近邮箱NPC");

			isTimeout();
			if ( mailboxnpcprocess(call,tasklet,taskresult,ZX2_NPC_MAILBOX,true,false) )
			{
				return;
			}
		}
		else
		{
			XLOG("不靠近邮箱NPC");
		}
	}
	else
	{
		XLOG("背包中的金币比订单中金币少");
		isTimeout();
		returnvalue = call->apilist->IsNearBy(ZX2_NPC_WAREHOUSE,call);
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
		else if ( returnvalue == GT_TRUE )
		{
			XLOG("靠近仓库NPC");

			/*
			与仓库NPC对话
			*/
			isTimeout();
			returnvalue = Talk(ZX2_NPC_WAREHOUSE,call);
			if ( returnvalue == GT_OK )
			{
				XLOG("与仓库NPC对话成功");
				/*
				打开仓库
				*/
				isTimeout();
				returnvalue = call->apilist->OpenWarehouse((char*)tasklet.post.sellerSecondPwd.c_str(),call);

				/*
				用空的仓库密码重新尝试一次
				*/
				if ( returnvalue != GT_OK )
				{
					isTimeout();
					returnvalue = call->apilist->OpenWarehouse("",call);

					XLOG("第一次打开仓库失败，使用空密码再尝试打开1次");
				}

				if ( returnvalue == GT_OK )
				{
					XLOG("打开仓库成功");
					/*
					查询仓库内金币
					*/
					INT64 warehousegold = 0;
					isTimeout();
					returnvalue = call->apilist->QueryItemsInWarehouse((Gt_GameItemT)ZX2_GOLD,&warehousegold,call);
					if ( returnvalue == GT_OK )
					{
						XLOG("查询仓库金币成功");
						XLOG("仓库内金币为%d",warehousegold);
						/*
						判断金币数量
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
							XLOG("取仓库内金币失败");
							XLOG("去仓库失败返回值为%d",returnvalue);
							withdrawsucc = false;
						}
						else
						{
							/*
							查询背包金币
							*/
							isTimeout();
							returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)ZX2_GOLD,&baggold,call);
							if ( returnvalue != GT_OK )
							{
								XLOG("查询背包金币失败");
								checkReturnvalueprocess( returnvalue , taskresult);
								return;
							}
							XLOG("取完仓库金币后，背包内有%d",baggold);
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
									XLOG("靠近邮箱NPC");

									if ( mailboxnpcprocess(call,tasklet,taskresult,ZX2_NPC_MAILBOX,true,false) )
									{
										return;
									}
								}
								else
								{
									XLOG("不靠近邮箱NPC");
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
									XLOG("靠近邮箱NPC");

									isTimeout();
									if ( mailboxnpcprocess(call,tasklet,taskresult,ZX2_NPC_MAILBOX,true,true) )
									{
										return;
									}
								}
								else
								{
									XLOG("不靠近邮箱NPC");
								}
							}
						}
					}
				}
				else
				{
					XLOG("卖家提供的2级密码错误");
				}
			}
			else
			{
				XLOG("对话仓库NPC失败");
			}
		}
	}

	/*
	这里做回城
	*/
	isTimeout();
	if (backHomeprocess(call,tasklet,taskresult)==false)
	{
		/*
		不可控因素
		*/
		//GT_ERR_3040	3040	//当前地图不在指定交易NPC城池

		taskresult.result = GT_ERR_3040;

		XLOG("回城失败");
		return;
	}
	XLOG("回城成功");

	/*
	使用回城技能成功后
	*/
	if ( withdrawsucc )
	{
		XLOG("取仓库成功,直接去邮箱");

		if ( baggold >= tasklet.post.buyerMoney )
		{
			XLOG("背包金币比订单中需求金币数额多");

			isTimeout();
			bh2mailboxprocess(call,tasklet,taskresult);
		}
		else
		{
			XLOG("背包金币比订单中需求金币数额少");

			isTimeout();
			bh2mailboxprocess2(call,tasklet,taskresult);
		}
	}
	else
	{
		if ( baggold >= tasklet.post.buyerMoney )
		{
			XLOG("背包金币比订单中需求金币数额多");

			isTimeout();
			bh2mailboxprocess(call,tasklet,taskresult);
		}
		else
		{
			XLOG("背包金币比订单中需求金币数额少");

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
	检测回城技能
	*/
	isTimeout();
	returnvalue = call->apilist->IsExistBackHomeSkill(call);
	if ( returnvalue == GT_TRUE )
	{
		XLOG("角色存在回城技能");
		/*
		使用回城技能
		*/
		isTimeout();
		returnvalue = UseBackHomeSkill(call);
		if ( returnvalue == GT_TRUE )
		{
			XLOG("角色使用回城技能成功");
			return true;
		}
		else if( returnvalue == GT_FALSE )
		{
			XLOG("角色使用回城技能失败");
			/*
			检测回城道具
			*/
			isTimeout();
			returnvalue = call->apilist->IsExistBackHomeItem(call);
			if ( returnvalue == GT_TRUE )
			{
				XLOG("角色存在回城物品");
				/*
				使用回城道具
				*/
				isTimeout();
				returnvalue = call->apilist->UseBackHomeItem(call);
				if ( returnvalue == GT_TRUE )
				{
					XLOG("角色使用回城物品成功");
					return true;
				}
				else if ( returnvalue == GT_FALSE )
				{
					XLOG("角色使用回城物品失败");
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
				XLOG("角色不存在回城物品");
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
		XLOG("角色不存在回城技能");
		/*
		检测回城道具
		*/
		isTimeout();
		returnvalue = call->apilist->IsExistBackHomeItem(call);
		if ( returnvalue == GT_TRUE )
		{
			XLOG("角色存在回城物品");
			/*
			使用回城道具
			*/
			isTimeout();
			returnvalue = call->apilist->UseBackHomeItem(call);
			if ( returnvalue == GT_TRUE )
			{
				XLOG("角色使用回城物品成功");
				return true;
			}
			else if ( returnvalue == GT_FALSE )
			{
				XLOG("角色使用回城物品失败");
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
			XLOG("角色不存在回城物品");
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
	仓库移动到邮箱
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
		XLOG("仓库移动到邮箱成功");

		/*
		查询背包金币
		*/
		isTimeout();
		returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)ZX2_GOLD,&baggold,call);
		if ( returnvalue != GT_OK )
		{
			XLOG("查询背包金币失败");
			checkReturnvalueprocess( returnvalue , taskresult);
			return false;
		}

		XLOG("第3次查询背包金币为%d",(int)baggold);

		if ( baggold >= tasklet.post.buyerMoney )
		{
			XLOG("背包金币数量大于订单需求");

			isTimeout();
			mailboxnpcprocess(call,tasklet,taskresult,ZX2_NPC_MAILBOX,true,false);
			return false;
		}
		else
		{
			XLOG("背包金币数量小于订单需求");

			isTimeout();
			mailboxnpcprocess(call,tasklet,taskresult,ZX2_NPC_MAILBOX,true,true);
			return false;
		}
	}
	else
	{
		XLOG("仓库移动到邮箱失败");
		/*
		不可控因素
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
	从回城点走到邮箱
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
		XLOG("从回城点走到邮箱成功");

		isTimeout();
		mailboxnpcprocess(call,tasklet,taskresult,ZX2_NPC_MAILBOX,true,false);
	}
	else
	{
		/*
		不可控因素
		*/
		taskresult.result = GT_ERR_3120;

		XLOG("从回城点走到邮箱失败");
		return false;
	}
	return true;
}

bool ZX2_Mailpost::bh2mailboxprocess2(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	从回城点走到邮箱
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
		XLOG("从回城点走到邮箱成功");

		isTimeout();
		mailboxnpcprocess(call,tasklet,taskresult,ZX2_NPC_MAILBOX,true,true);
	}
	else
	{
		/*
		不可控因素
		*/
		taskresult.result = GT_ERR_3120;

		XLOG("从回城点走到邮箱失败");
		return false;
	}
	return true;
}

bool ZX2_Mailpost::bh2warehouseprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	回城点移动到仓库
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
		XLOG("从回城点走到仓库成功");
		/*
		与仓库NPC对话
		*/
		isTimeout();
		returnvalue = Talk(ZX2_NPC_WAREHOUSE,call);
		if ( returnvalue == GT_OK )
		{
			XLOG("与仓库NPC对话成功");
			/*
			打开仓库
			*/
			isTimeout();
			returnvalue = call->apilist->OpenWarehouse((char*)tasklet.post.sellerSecondPwd.c_str(),call);

			/*
			用空的仓库密码重新尝试一次
			*/
			if ( returnvalue != GT_OK )
			{
				isTimeout();
				returnvalue = call->apilist->OpenWarehouse("",call);

				XLOG("第一次打开仓库失败，使用空密码再尝试打开1次");
			}

			if ( returnvalue == GT_OK )
			{
				XLOG("打开仓库成功");
				/*
				查询仓库内金币
				*/
				INT64 warehousegold = 0;
				isTimeout();
				returnvalue = call->apilist->QueryItemsInWarehouse((Gt_GameItemT)ZX2_GOLD,&warehousegold,call);
				if ( returnvalue == GT_OK )
				{
					XLOG("查询仓库金币成功");
					XLOG("仓库内金币为%d",warehousegold);
					/*
					判断金币数量
					*/
					INT64 withdrawgold = tasklet.post.buyerMoney - baggold;
					if( warehousegold <= withdrawgold )
					{
						if(warehousegold==0)
						{
							XLOG("仓库金币为%d",0);
						}
						else
						{
							isTimeout();
							returnvalue = call->apilist->WithdrawItemsInWarehouse((Gt_GameItemT)ZX2_GOLD,&warehousegold,call);
							if ( returnvalue != GT_OK )
							{
								XLOG("取仓库内金币失败");
								XLOG("去仓库失败返回值为%d",returnvalue);
							}
							else
							{
								XLOG("接口返回取仓库金币成功，未查询背包");
							}
						}
					}
					else
					{
						if(warehousegold==0)
						{
							XLOG("仓库金币为%d",0);
						}
						else
						{
							isTimeout();
							returnvalue = call->apilist->WithdrawItemsInWarehouse((Gt_GameItemT)ZX2_GOLD,&withdrawgold,call);

							if ( returnvalue != GT_OK )
							{
								XLOG("取仓库内金币失败");
								XLOG("去仓库失败返回值为%d",returnvalue);
							}
							else
							{
								XLOG("接口返回取仓库金币成功，未查询背包");
							}
						}
					}
				}
			}
			else
			{
				XLOG("卖家提供的2级密码错误");
			}
		}
		else
		{
			XLOG("与仓库NPC对话失败");
		}
	}
	else
	{
		/*
		不可控因素
		*/
		taskresult.result = GT_ERR_3120;

		XLOG("从回城点走到仓库失败");
		return false;
	}
	return true;
}

bool ZX2_Mailpost::sendmailprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	发送邮件
	*/
	isTimeout();
	returnvalue = call->apilist->SendMail((char*)tasklet.post.buyerActor.c_str(),(char*)configdata.sMailTitle.c_str(),(char*)configdata.sMailContent.c_str(),tasklet.post.buyerMoney - 500,call);
	if ( returnvalue == GT_OK )
	{
		XLOG("发邮件成功");
		taskresult.result = GT_ERR_1000;

		returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)ZX2_GOLD,&baggold,call);
		XLOG("发完邮件后背包金币为%d",(int)baggold);
		return true;
	}
	else if ( returnvalue == GT_NOTEXISTED )
	{
		taskresult.result = GT_ERR_2050;

		XLOG("买家角色名错误");
		return false;
	}
	else if ( returnvalue == GT_MAIlBOXFULL )
	{
		taskresult.result = GT_ERR_3070;

		XLOG("买家邮箱已满");
		return false;
	}
	else if ( returnvalue == GT_MAIlBOXLOCKED )
	{
		taskresult.result = GT_ERR_2100;

		XLOG("买家邮箱已冻结");
		return false;
	}
	else if ( returnvalue == GT_ROLEKICK )
	{
		taskresult.result = GT_ERR_3050;

		XLOG("卖家顶号");
		return false;
	}
	else if ( returnvalue == GT_TIMEOUT )
	{
		taskresult.result = GT_ERR_3120;

		XLOG("发送邮件超时");
		return false;
	}
	else if ( returnvalue == GT_CONNECTBREAK )
	{
		taskresult.result = GT_ERR_3120;

		XLOG("连接中断");
		throw(robot_error(GT_CONNECTBREAK, GT_ERR_3120, "连接中断"));
		return false;
	}
	else
		XLOG("其他未知发邮件错误");
	return true;;
}

bool ZX2_Mailpost::checkmailpostprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	返回到角色选择画面
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
		重连多次失败，返回结果转人工
		*/
		taskresult.result = GT_ERR_3120;
		return false;
	}
	else
		restarttimes = restarttimes - 1;

	int returnvalue;
	/*
	关闭
	*/
	returnvalue = call->apilist->End(call);
	/*
	开始
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

		XLOG("上一步操作失败导致无法继续");
		return;
	}
	else if ( returnvalue == GT_NOTEXISTED )
	{
		taskresult.result = GT_ERR_2050;

		XLOG("上一步操作返回买家角色名错误");
		return;
	}
	else if ( returnvalue == GT_MAIlBOXFULL )
	{
		taskresult.result = GT_ERR_3070;

		XLOG("上一步操作返回买家邮箱已满");
		return;
	}
	else if ( returnvalue == GT_MAIlBOXLOCKED )
	{
		taskresult.result = GT_ERR_2100;

		XLOG("上一步操作返回买家邮箱已冻结");
		return;
	}
	else if ( returnvalue == GT_ROLEKICK )
	{
		taskresult.result = GT_ERR_3050;

		XLOG("上一步操作返回卖家顶号");
		return;
	}
	else if ( returnvalue == GT_TIMEOUT )
	{
		taskresult.result = GT_ERR_3120;

		XLOG("上一步操作超时");
		return;
	}
	else if ( returnvalue == GT_CONNECTBREAK )
	{
		taskresult.result = GT_ERR_3120;

		XLOG("连接中断");
		throw(robot_error(GT_CONNECTBREAK, GT_ERR_3120, "连接中断"));
		return;
	}
	else if ( returnvalue == GT_UNABLEMOVETO )
	{
		taskresult.result = GT_ERR_3120;

		XLOG("无法到达目标NPC");
		return;
	}
	else if ( returnvalue == GT_UNABLETALKTO )
	{
		taskresult.result = GT_ERR_3120;

		XLOG("无法对话目标NPC");
		return;
	}
	else if ( returnvalue == GT_INSAFETIME )
	{
		XLOG("在安全时间中导致上一步的操作失败");
		return;
	}
	else if ( returnvalue == GT_ROLELOCK )
	{
		XLOG("账号被封");
		return;
	}
	else
	{
		XLOG("未知的返回值%d",returnvalue);
		return;
	}
}
bool ZX2_Mailpost::mailboxnpcprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult,eZX2NPCType npctype,bool safelock,bool withdrawgold)
{
	int returnvalue;

	/*
	与邮箱npc对话
	*/
	isTimeout();
	returnvalue = Talk(npctype,call);
	if ( returnvalue != GT_OK )
	{
		XLOG("与邮箱NPC对话失败");
		checkReturnvalueprocess( returnvalue , taskresult);
		return false;
	}

	/*
	判断是否解锁
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

		XLOG("安全锁解锁成功");
	}

	/*
	打开邮箱
	*/
	isTimeout();
	returnvalue = call->apilist->OpenMailBox(NULL,call);
	if ( returnvalue != GT_OK )
	{
		XLOG("打开邮箱失败");
		checkReturnvalueprocess( returnvalue , taskresult);
		return true;
	}

	if(withdrawgold)
	{
		/*
		判断邮箱中金币，从邮箱中取钱
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
			XLOG("查询背包金币失败");
			checkReturnvalueprocess( returnvalue , taskresult);
			return true;
		}

		XLOG("取完邮箱金币后查询背包金币为%d",(int)baggold);
		if( baggold >= tasklet.post.buyerMoney )
		{
			XLOG("背包金币数量大于订单需求，取邮箱金币成功");
			/*
			发送邮件
			*/
			isTimeout();
			sendmailprocess(call,tasklet,taskresult);
			return true;
		}
		else
		{
			XLOG("背包金币数量小于订单需求");
			/*
			不足发货金币
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
