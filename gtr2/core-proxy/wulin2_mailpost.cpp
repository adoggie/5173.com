
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
	XLOG("订单号为%s",(char*)_tasklet.no.c_str());
	XLOG("买家需求金币数量为%lld",_tasklet.post.buyerMoney);
	XLOG("卖家卖的金币数量为%lld",_tasklet.post.money);
	XLOG("买家姓名为%s",_tasklet.post.buyerActor.c_str());
	XLOG("卖家姓名为%s",_tasklet.post.sellerActor.c_str());
	XLOG("订单中小区信息为%s",_tasklet.server.c_str());
	XLOG("订单中账号信息为%s",_tasklet.account.c_str());
	/*
	预定义默认的返回结果
	*/
	result.result = GT_ERR_3120;
	/*
	启动游戏
	*/
	int returnvalue = _gamectx.apilist->Begin(&_gamectx);
	if (returnvalue != GT_OK)
	{
		_gamectx.apilist->End(&_gamectx);
		XLOG("返回服务器的交易结果为%d",(int)result.result);
		return;
	}
	/*
	中间的处理过程
	*/
	run(&_gamectx,_tasklet,result);
	/*
	关闭游戏
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

	XLOG("返回服务器的交易结果为%d",(int)result.result);
}


void Wulin2_Mailpost::run(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
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
	选小区流程
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

			XLOG("小区无法连接");
			return;
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
	}

	//XLOG("选小区成功");

	/*
	账号登陆流程
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
			卖家密码错误l
			*/
			taskresult.result = GT_ERR_2000;

			XLOG("卖家密码错误");
			return;
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
			continue;
		}
		else if ( returnvalue == GT_FALSE && i == login_trytimes -1 )
		{
			XLOG("游戏服务器没开或者可能是密保输入多次错误账号被临时封停");
			return;
		}
		else if ( returnvalue == GT_UNABLECONNECT )
		{
			taskresult.result = GT_ERR_3020;

			XLOG("小区无法连接");
			return;
		}
		else if ( returnvalue == GT_RECOQNIZEREMPTY && i != login_trytimes -1 )
		{
			continue;
		}
		else if ( returnvalue == GT_RECOQNIZEREMPTY && i == login_trytimes -1 )
		{
			taskresult.result = GT_ERR_3160;

			XLOG("答题员放弃答题,答题超时,密保未上传");
			return;
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
	}

	/*
	选线流程
	*/
	returnvalue = call->apilist->SelectLineByName("",call);

	if ( returnvalue != GT_OK )
	{
		XLOG("选线失败");

		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}

	XLOG("选线成功");

	/*
	角色登陆匹配流程
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
	选角色流程
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
			XLOG("选角色失败");

			taskresult.result = GT_ERR_2010;
			return;
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
	}

	XLOG("选角色成功");

	/*
	安全时间检测
	*/
	int safetime;
	call->apilist->QuerySafeTime(&safetime,call);
	if ( safetime >= SAFE_TIME )
	{
		/*
		返回值为安全时间大于2分钟，转人工
		*/
		taskresult.result = GT_ERR_3030;

		XLOG("安全时间大于2分钟");
		return;
	}

	XLOG("安全时间小于2分钟");
	/*
	查询背包金币
	*/
	returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)WULIN2_GOLD,&baggold,call);
	if ( returnvalue != GT_OK )
	{
		XLOG("查询背包金币失败");

		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}

	XLOG("第1次查询背包金币为%d",baggold);


	/*
	使用回城物品，回城技能
	*/
	backhomeSkillprocess(call,tasklet,taskresult);

	/*
	订单中金币单位是金。
	获取的金币单位是铜
	1金 = 100银 = 10000铜
	*/
	if ( baggold >= calculate_buyermoney() )
	{
		XLOG("玩家背包金币比需求数量多");

		sendMailprocess(call,tasklet,taskresult);
		return;
	}

	XLOG("玩家背包金币比需求数量少");

	/*
	判断订单金币数量
	*/
	if ( tasklet.post.buyerMoney > 190000 * 10000 )
	{
		XLOG("订单金币超过19万");
		return;
	}

	/*
	查询背包金条,金块,金砖数量
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

	XLOG("玩家背包内金条数量为%d",(int)goldingot.itemnum);
	XLOG("玩家背包内金块数量为%d",(int)goldbullion.itemnum);
	XLOG("玩家背包内金砖数量为%d",(int)goldbrick.itemnum);

	if ( calculate_allinbag() >= calculate_buyermoney() )
	{
		XLOG("玩家背包金币加上物品价值比需求数量多");
		sellItemprocess(call,tasklet,taskresult);
		return;
	}

	XLOG("玩家背包金币加上物品价值比需求数量少");
	/*
	检测当前地图是否为七侠镇
	*/
	returnvalue = call->apilist->IsInMap(MAP_QIXIAZHEN,call);
	if ( returnvalue == GT_FALSE )
	{
		XLOG("玩家不在七侠镇");
		/*
		检查背包金币是否满足传送费
		*/
		if ( baggold < 1000 )
		{
			XLOG("玩家背包金币不够传送费");
			return;
		}

		/*
		移动到传送NPC
		*/
		returnvalue = call->apilist->MoveToByNpcID(NPC_CONVEY,call);
		if ( returnvalue != GT_OK )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
		/*
		对话传送NPC
		*/
		returnvalue = call->apilist->Talk(NPC_CONVEY,call);
		if ( returnvalue != GT_OK )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
		/*
		使用传送功能
		*/
		returnvalue = call->apilist->Transport(MAP_QIXIAZHEN,call);
		if ( returnvalue != GT_OK )
		{
			XLOG("传送到七侠镇失败");
			if( returnvalue == GT_FALSE )
			{
				taskresult.result = GT_ERR_3040;
				return;
			}
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
		XLOG("传送到七侠镇成功");
	}

	/*
	判断仓库NPC是否在附近
	*/
	/*
	临时修改
	*/
	returnvalue = GT_OK;
	//returnvalue = call->apilist->IsExistNPC(NPC_WAREHOUSE,call);
	if ( returnvalue == GT_OK )
	{
		XLOG("检测到仓库NPC");
		/*
		移动到仓库NPC
		*/
		returnvalue = call->apilist->MoveToByNpcID(NPC_WAREHOUSE,call);
		if ( returnvalue != GT_OK )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}

		XLOG("移动到仓库NPC成功");
		/*
		与仓库NPC对话
		*/
		returnvalue = call->apilist->Talk(NPC_WAREHOUSE,call);
		if ( returnvalue != GT_OK )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}

		XLOG("与仓库NPC对话成功");
		/*
		打开仓库
		*/
		returnvalue = call->apilist->OpenWarehouse((char*)tasklet.post.sellerSecondPwd.c_str(),call);
		realSecondPwd = tasklet.post.sellerSecondPwd;
		if ( returnvalue != GT_OK )
		{
			XLOG("打开仓库失败使用空密码再尝试一次");
			returnvalue = call->apilist->OpenWarehouse("",call);
			realSecondPwd = "";
		}
		if ( returnvalue == GT_OK )
		{
			XLOG("玩家提供的2级密码正确");
			INT64 warehousegold,withdrawgold;
			/*
			查询背包金币
			*/
			returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)WULIN2_GOLD,&baggold,call);
			if ( returnvalue != GT_OK )
			{
				checkReturnvalueprocess( returnvalue , taskresult);
				return;
			}
			/*
			查询仓库内金币
			*/
			returnvalue = call->apilist->QueryItemsInWarehouse((Gt_GameItemT)WULIN2_GOLD,&warehousegold,call);
			if ( returnvalue != GT_OK )
			{
				checkReturnvalueprocess( returnvalue , taskresult);
				return;
			}
			if ( returnvalue == GT_OK )
			{
				XLOG("仓库内金币为%d",(int)warehousegold);
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
					XLOG("取仓库金币后背包内金币数量为%d",(int)baggold);
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
					XLOG("取仓库金币后背包内金币数量为%d",(int)baggold);
					XLOG("背包内金币没有满足订单需求");
				}
			}
			/*
			查询并获取仓库内金条,金砖,金块数量
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

			XLOG("玩家仓库内金条数量为%d",(int)warehousegoldingot);
			XLOG("玩家仓库内金块数量为%d",(int)warehousegoldbullion);
			XLOG("玩家仓库内金砖数量为%d",(int)warehousegoldbrick);

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

			XLOG("取完仓库内物品后玩家背包内金条数量为%d",(int)goldingot.itemnum);
			XLOG("取完仓库内物品后玩家背包内金块数量为%d",(int)goldbullion.itemnum);
			XLOG("取完仓库内物品后玩家背包内金砖数量为%d",(int)goldbrick.itemnum);

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
			打开帮派仓库
			*/
			returnvalue = call->apilist->OpenExchange((char*)realSecondPwd.c_str(),call);
			if ( returnvalue != GT_OK )
			{
				XLOG("打开仓库失败使用空密码再尝试一次");
				returnvalue = call->apilist->OpenExchange("",call);
			}
			if ( returnvalue == GT_OK )
			{
				XLOG("打开帮派仓库成功");
				/*
				查询并获取帮派仓库内金条,金砖,金块数量
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

				XLOG("玩家帮派仓库内金条数量为%d",(int)guildgoldingot);
				XLOG("玩家帮派仓库内金块数量为%d",(int)guildgoldbullion);
				XLOG("玩家帮派仓库内金砖数量为%d",(int)guildgoldbrick);

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

				XLOG("取完帮派仓库内物品后玩家背包内金条数量为%d",(int)goldingot.itemnum);
				XLOG("取完帮派仓库内物品后玩家背包内金块数量为%d",(int)goldbullion.itemnum);
				XLOG("取完帮派仓库内物品后玩家背包内金砖数量为%d",(int)goldbrick.itemnum);

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
				XLOG("打开帮派仓库失败");

				warehouseRvalue = GT_ERR_2020;
			}
		}
		else
		{
			XLOG("玩家提供的2级密码错误");

			warehouseRvalue = GT_ERR_2020;
		}
	}
	else
	{
		XLOG("检测不到仓库NPC");
	}

	/*
	判断是否解锁
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

	XLOG("安全锁已经解锁");

	/*
	判断钱庄NPC是否在附近
	*/
	/*
	临时修改
	*/
	returnvalue = GT_OK;
	//returnvalue = call->apilist->IsExistNPC(NPC_BANK,call);
	if ( returnvalue == GT_OK )
	{
		XLOG("检测到钱庄NPC");
		/*
		移动到钱庄NPC
		*/
		returnvalue = call->apilist->MoveToByNpcID(NPC_BANK,call);
		if ( returnvalue != GT_OK )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
		/*
		与钱庄npc对话
		*/
		returnvalue = call->apilist->Talk(NPC_BANK,call);
		if ( returnvalue != GT_OK )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
		/*
		打开钱庄
		*/
		getLogger().Message("钱庄密码为%s",(char*)tasklet.post.bankPwd.c_str());
		returnvalue = call->apilist->OpenBank((char*)tasklet.post.bankPwd.c_str(),call);
		//if ( returnvalue == GT_OK )
		//{
			//XLOG("解锁成功");
			INT64 bankgold,withdrawgold;
			/*
			查询钱庄内金币
			*/
			returnvalue = call->apilist->QueryItemsInBank((Gt_GameItemT)WULIN2_GOLD,&bankgold,call);
			//if ( returnvalue != GT_OK )
			//{
			//	checkReturnvalueprocess( returnvalue , taskresult);
			//	return;
			//}
			XLOG("钱庄内金币数量%d",(int)bankgold);
			if ( returnvalue == GT_OK )
			{
				INT64 oldbaggold = baggold;

				if ( calculate_allinbag() + bankgold >= calculate_buyermoney() )
				{
					withdrawgold = calculate_buyermoney() - calculate_allinbag();
					XLOG("从钱庄内尝试去取%d钱",(int)withdrawgold);
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
					XLOG("从钱庄内取完钱后背包金币为%d",(int)baggold);
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
					XLOG("从钱庄内尝试去取%d钱",(int)withdrawgold);
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
					XLOG("从钱庄内取完钱后背包金币为%d",(int)baggold);
				}

				if ( oldbaggold == baggold )
				{
					XLOG("从钱庄取钱不成功，可能是卖家提供的钱庄密码错误");

					bankRvalue = GT_ERR_2020;
				}
				else
				{
					XLOG("从钱庄取钱成功");
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
	检测邮箱NPC是否在附近
	*/
	/*
	临时修改
	*/
	returnvalue = GT_OK;
	//returnvalue = call->apilist->IsExistNPC(NPC_MAILBOX,call);
	if ( returnvalue != GT_OK )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}
	/*
	移动到邮箱NPC
	*/
	returnvalue = call->apilist->MoveToByNpcID(NPC_MAILBOX,call);
	if ( returnvalue != GT_OK )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}
	/*
	与邮箱npc对话
	*/
	returnvalue = call->apilist->Talk(NPC_MAILBOX,call);
	if ( returnvalue != GT_OK )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}

	/*
	取出邮箱金币
	*/
	INT64 mailboxgold = calculate_buyermoney() - calculate_allinbag();

	INT64 withdrawgold = mailboxgold;
	XLOG("传入的为%d",(int)mailboxgold);
	returnvalue = call->apilist->IsEnoughItemsInMailbox((Gt_GameItemT)WULIN2_GOLD,&mailboxgold,call);
	XLOG("邮箱中有金币数量为%d",(int)mailboxgold);

	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}
	if ( returnvalue == GT_OK )
	{
		XLOG("邮箱中的钱足够差额%d",(int)withdrawgold);
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
		XLOG("取完差额背包金币为%d",(int)baggold);
		if ( baggold >= calculate_buyermoney() )
		{
			/*
			发送邮件
			*/
			returnvalue = call->apilist->SendMail((char*)tasklet.post.buyerActor.c_str(),(char*)configdata.sMailTitle.c_str(),(char*)configdata.sMailContent.c_str(),tasklet.post.buyerMoney - 500,call);

			if ( returnvalue == GT_OK )
			{
				XLOG("发邮件成功");
				taskresult.result = GT_ERR_1000;

				returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)WULIN2_GOLD,&baggold,call);
				XLOG("发完邮件后背包金币为%d",(int)baggold);
				return;
			}
			else if ( returnvalue == GT_NOTEXISTED )
			{
				taskresult.result = GT_ERR_2050;

				XLOG("买家角色名错误");
				return;
			}
			else if ( returnvalue == GT_MAIlBOXFULL )
			{
				taskresult.result = GT_ERR_3070;

				XLOG("买家邮箱已满");
				return;
			}
			else if ( returnvalue == GT_MAIlBOXLOCKED )
			{
				taskresult.result = GT_ERR_2100;

				XLOG("买家邮箱已冻结");
				return;
			}
			else if ( returnvalue == GT_ROLEKICK )
			{
				taskresult.result = GT_ERR_3050;

				XLOG("卖家顶号");
				return;
			}
			else if ( returnvalue == GT_TIMEOUT )
			{
				taskresult.result = GT_ERR_3120;

				XLOG("选小区超时");
				return;
			}
			else if ( returnvalue == GT_CONNECTBREAK )
			{
				taskresult.result = GT_ERR_3120;

				XLOG("连接中断");
				return;
			}
			else
				XLOG("其他未知发邮件错误");
		}
		else if ( calculate_allinbag() >= calculate_buyermoney() )
		{
			sellItemprocess(call,tasklet,taskresult);
			return;
		}
		else
		{
			XLOG("不足发货金币");

			taskresult.result = GT_ERR_2030;
		}
	}
	else
	{
		XLOG("邮箱中的钱不足够");

		XLOG("不足发货金币");

		taskresult.result = GT_ERR_2030;
	}
}

void Wulin2_Mailpost::sellItemprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	检测杂货NPC是否在附近
	*/
	/*
	临时修改
	*/
	returnvalue = GT_OK;
	//returnvalue = call->apilist->IsExistNPC(NPC_GROCER,call);
	if ( returnvalue != GT_OK )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}
	/*
	移动到杂货NPC
	*/
	returnvalue = call->apilist->MoveToByNpcID(NPC_GROCER,call);
	if ( returnvalue != GT_OK )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}
	/*
	与杂货npc对话
	*/
	returnvalue = call->apilist->Talk(NPC_GROCER,call);
	if ( returnvalue != GT_OK )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}

	/*
	判断是否解锁
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

	XLOG("安全锁解锁成功");
	/*
	先卖金块
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

		XLOG("即将卖出%d个金块",num);

		returnvalue = call->apilist->SellItem(WULIN2_GOLDBULLION,(int)num,call);

		if ( returnvalue == GT_OK )
		{
			XLOG("卖金块成功");
		}
		else if ( returnvalue == GT_FALSE )
		{
			XLOG("卖金块不成功");
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
	}
	else
	{
		XLOG("即将卖出%d个金块",goldbullion.itemnum);
		if (goldbullion.itemnum != 0)
		{
			returnvalue = call->apilist->SellItem(WULIN2_GOLDBULLION,(int)goldbullion.itemnum,call);
			if ( returnvalue == GT_OK )
			{
				XLOG("卖金块成功");
			}
			else if ( returnvalue == GT_FALSE )
			{
				XLOG("卖金块不成功");
			}
			else
			{
				checkReturnvalueprocess( returnvalue , taskresult);
				return;
			}
		}
	}

	/*
	查询卖完金块后背包金币
	*/

	returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)WULIN2_GOLD,&baggold,call);

	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}

	XLOG("卖完金块后背包金币为%d",baggold);

	/*
	判断卖完金块后背包金币是否够订单用
	*/
	if ( baggold >= calculate_buyermoney() )
	{
		sendMailprocess(call,tasklet,taskresult);
		return;
	}

	/*
	再卖金砖
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

		XLOG("即将卖出%d个金砖",num);

		returnvalue = call->apilist->SellItem(WULIN2_GOLDBRICK,(int)num,call);
		if ( returnvalue == GT_OK )
		{
			XLOG("卖金砖成功");
		}
		else if ( returnvalue == GT_FALSE )
		{
			XLOG("卖金砖不成功");
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
	}
	else
	{
		XLOG("即将卖出%d个金砖",goldbrick.itemnum);
		if (goldbrick.itemnum != 0)
		{
			returnvalue = call->apilist->SellItem(WULIN2_GOLDBRICK,(int)goldbrick.itemnum,call);

			if ( returnvalue == GT_OK )
			{
				XLOG("卖金砖成功");
			}
			else if ( returnvalue == GT_FALSE )
			{
				XLOG("卖金砖不成功");
			}
			else
			{
				checkReturnvalueprocess( returnvalue , taskresult);
				return;
			}
		}
	}

	/*
	查询卖完金砖后背包金币
	*/

	returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)WULIN2_GOLD,&baggold,call);

	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}

	XLOG("卖完金砖后背包金币为%d",baggold);

	/*
	判断卖完金砖后背包金币是否够订单用
	*/
	if ( baggold >= calculate_buyermoney() )
	{
		sendMailprocess(call,tasklet,taskresult);
		return;
	}

	/*
	最后卖金条
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

		XLOG("即将卖出%d个金条",num);
		returnvalue = call->apilist->SellItem(WULIN2_GOLDINGOT,(int)num,call);

		if ( returnvalue == GT_OK )
		{
			XLOG("卖金条成功");
		}
		else if ( returnvalue == GT_FALSE )
		{
			XLOG("卖金条不成功");
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
	查询卖完金条后背包金币
	*/

	returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)WULIN2_GOLD,&baggold,call);

	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}

	XLOG("卖完金条后背包金币为%d",baggold);

	/*
	判断卖完金条后背包金币是否够订单用
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
	检测邮箱NPC是否在附近
	*/
	/*
	临时修改
	*/
	returnvalue = GT_OK;
	//returnvalue = call->apilist->IsExistNPC(NPC_MAILBOX,call);
	if ( returnvalue != GT_OK )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}
	/*
	移动到邮箱NPC
	*/
	returnvalue = call->apilist->MoveToByNpcID(NPC_MAILBOX,call);
	if ( returnvalue != GT_OK )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}
	/*
	与邮箱npc对话
	*/
	returnvalue = call->apilist->Talk(NPC_MAILBOX,call);
	if ( returnvalue != GT_OK )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}

	/*
	判断是否解锁
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

	XLOG("安全锁解锁成功");

	/*
	发送邮件
	*/
	returnvalue = call->apilist->SendMail((char*)tasklet.post.buyerActor.c_str(),(char*)configdata.sMailTitle.c_str(),(char*)configdata.sMailContent.c_str(),tasklet.post.buyerMoney - 500,call);

	if ( returnvalue == GT_OK )
	{
		XLOG("发邮件成功");
		taskresult.result = GT_ERR_1000;

		returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)WULIN2_GOLD,&baggold,call);
		XLOG("发完邮件后背包金币为%d",(int)baggold);
		return;
	}
	else if ( returnvalue == GT_NOTEXISTED )
	{
		taskresult.result = GT_ERR_2050;

		XLOG("买家角色名错误");
		return;
	}
	else if ( returnvalue == GT_MAIlBOXFULL )
	{
		taskresult.result = GT_ERR_3070;

		XLOG("买家邮箱已满");
		return;
	}
	else if ( returnvalue == GT_MAIlBOXLOCKED )
	{
		taskresult.result = GT_ERR_2100;

		XLOG("买家邮箱已冻结");
		return;
	}
	else if ( returnvalue == GT_ROLEKICK )
	{
		taskresult.result = GT_ERR_3050;

		XLOG("卖家顶号");
		return;
	}
	else if ( returnvalue == GT_TIMEOUT )
	{
		taskresult.result = GT_ERR_3120;

		XLOG("选小区超时");
		return;
	}
	else if ( returnvalue == GT_CONNECTBREAK )
	{
		taskresult.result = GT_ERR_3120;

		XLOG("连接中断");
		return;
	}
	else
		XLOG("其他未知发邮件错误");
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

		XLOG("上一步操作失败导致无法继续");
		return;
	}
	else if ( returnvalue == GT_NOTEXISTED )
	{
		taskresult.result = GT_ERR_2050;

		XLOG("买家角色名错误");
		return;
	}
	else if ( returnvalue == GT_MAIlBOXFULL )
	{
		taskresult.result = GT_ERR_3070;

		XLOG("买家邮箱已满");
		return;
	}
	else if ( returnvalue == GT_MAIlBOXLOCKED )
	{
		taskresult.result = GT_ERR_2100;

		XLOG("买家邮箱已冻结");
		return;
	}
	else if ( returnvalue == GT_ROLEKICK )
	{
		taskresult.result = GT_ERR_3050;

		XLOG("卖家顶号");
		return;
	}
	else if ( returnvalue == GT_TIMEOUT )
	{
		taskresult.result = GT_ERR_3120;

		XLOG("超时");
		return;
	}
	else if ( returnvalue == GT_CONNECTBREAK )
	{
		taskresult.result = GT_ERR_3120;

		XLOG("连接中断");
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
}

void Wulin2_Mailpost::backhomeSkillprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	检测回城技能
	*/
	returnvalue = call->apilist->IsExistBackHomeSkill(call);
	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}
	else if ( returnvalue == GT_TRUE )
	{
		XLOG("玩家存在回城技能");
		returnvalue = call->apilist->UseBackHomeSkill(call);
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
		else if( returnvalue == GT_TRUE )
		{
			XLOG("玩家使用回城技能成功");
		}
		else
		{
			XLOG("玩家使用回城技能失败");
		}
	}
	else
	{
		XLOG("玩家不存在回城技能");
	}
}
void Wulin2_Mailpost::backhomeItemprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	检测回城物品
	*/
	returnvalue = call->apilist->IsExistBackHomeItem(call);
	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return;
	}
	else if ( returnvalue == GT_TRUE )
	{
		XLOG("玩家存在回城物品");
		returnvalue = call->apilist->UseBackHomeItem(call);
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
		else if( returnvalue == GT_TRUE )
		{
			XLOG("玩家使用回城物品成功");
		}
		else
		{
			XLOG("玩家使用回城物品失败");
			backhomeSkillprocess(call,tasklet,taskresult);
		}
	}
	else
	{
		XLOG("玩家不存在回城物品");
		backhomeSkillprocess(call,tasklet,taskresult);
	}
}