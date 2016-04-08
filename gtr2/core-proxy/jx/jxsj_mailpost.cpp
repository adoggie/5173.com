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
	XLOG("订单号为%s",(char*)_tasklet.no.c_str());
	XLOG("买家需求金币数量为%lld",_tasklet.post.buyerMoney);
	XLOG("卖家卖的金币数量为%lld",_tasklet.post.money);
	XLOG("买家姓名为%s",_tasklet.post.buyerActor.c_str());
	XLOG("卖家姓名为%s",_tasklet.post.sellerActor.c_str());
	XLOG("订单中大区信息为%s",_tasklet.area.c_str());
	XLOG("订单中小区信息为%s",_tasklet.server.c_str());
	XLOG("订单中账号信息为%s",_tasklet.account.c_str());
	//XLOG("订单中密码信息为%s",_tasklet.password.c_str());

	/*
	设置默认接口超时时间
	*/
	_gamectx.timeout = 40000;

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
		XLOG("启动游戏失败");
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

	if ( specialvalue != 0 && result.result == GT_ERR_2030 )
	{
		result.result = specialvalue;
	}

	XLOG("返回服务器的交易结果为%d",(int)result.result);
}

void JXSJ_Mailpost::run(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
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

	int returnvalue;

	if (loginprocess(call,tasklet,taskresult)==false)
		return;

	call->timeout = 30000;

	/*
	判断角色等级
	*/
	int rolelevel;
	returnvalue = call->apilist->QueryRoleLevel((char*)tasklet.post.sellerActor.c_str(),&rolelevel,call);
	if ( returnvalue == GT_OK )
	{
		XLOG("卖家等级为%d",rolelevel);
		INT64 maxinum = getRoleMaximumGold(rolelevel);
		XLOG("卖家等级对应的最大金币携带数量为%lld",maxinum);
		if ( maxinum < tasklet.post.buyerMoney )
		{
			XLOG("卖家背包最大金币携带数量比买家需求少");

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
	查询背包金币
	*/
	returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)JXSJ_ITEM_GOLD,&baggold,call);
	if ( returnvalue != GT_OK )
	{
		XLOG("查询背包金币失败");

		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}

	XLOG("查询背包金币为%lld",baggold);

	if ( baggold >= tasklet.post.buyerMoney )
	{
		XLOG("玩家背包金币比需求数量多");

		sendMailprocess(call,tasklet,taskresult);
		return;
	}

	XLOG("玩家背包金币比需求数量少");

	INT64 withdrawgold;

	/*
	查询钱庄金币是否足够
	*/
	INT64 bankgold;
	returnvalue = call->apilist->QueryItemsInBank((Gt_GameItemT)JXSJ_ITEM_GOLD,&bankgold,call);
	if ( returnvalue != GT_OK )
	{
		XLOG("查询钱庄金币失败");

		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}
	XLOG("钱庄中有金币数为%lld",bankgold);
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
		XLOG("准备取出金币数量为%lld",withdrawgold);

		returnvalue = call->apilist->WithdrawItemsInBank((Gt_GameItemT)JXSJ_ITEM_GOLD,&withdrawgold,call);
		if ( returnvalue == GT_OK )
		{
			XLOG("钱庄取钱成功");
		}
		else if( returnvalue == GT_FALSE )
		{
			XLOG("钱庄取钱失败");
		}
		else if ( returnvalue == GT_BankFailed )
		{
			XLOG("钱庄取钱上限");
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
		returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)JXSJ_ITEM_GOLD,&baggold,call);
		if ( returnvalue != GT_OK )
		{
			XLOG("查询背包金币失败");

			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
		XLOG("取完钱庄金币后,查询背包金币为%lld",baggold);
		if ( baggold >= tasklet.post.buyerMoney )
		{
			XLOG("玩家背包金币比需求数量多");

			sendMailprocess(call,tasklet,taskresult);
			return;
		}
	}

	/*
	查询交易所金币是否足够
	*/
	INT64 exchangegold;
	returnvalue = call->apilist->QueryItemsInExchange((Gt_GameItemT)JXSJ_ITEM_GOLD,&exchangegold,call);
	if ( returnvalue != GT_OK )
	{
		XLOG("查询交易所金币失败");

		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}
	XLOG("交易所中有金币数为%lld",exchangegold);
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
		XLOG("准备取出金币数量为%lld",withdrawgold);

		returnvalue = call->apilist->WithdrawItemsInExchange((Gt_GameItemT)JXSJ_ITEM_GOLD,&withdrawgold,call);
		if ( returnvalue == GT_OK )
		{
			XLOG("交易所取钱成功");
		}
		else if( returnvalue == GT_FALSE )
		{
			XLOG("交易所取钱失败");
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
		returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)JXSJ_ITEM_GOLD,&baggold,call);
		if ( returnvalue != GT_OK )
		{
			XLOG("查询背包金币失败");

			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
		XLOG("取完交易所金币后,查询背包金币为%lld",baggold);
		if ( baggold >= tasklet.post.buyerMoney )
		{
			XLOG("玩家背包金币比需求数量多");

			sendMailprocess(call,tasklet,taskresult);
			return;
		}
	}

	/*
	查询邮箱金币是否足够
	*/
	INT64 mailboxgold = tasklet.post.buyerMoney - baggold;
	returnvalue = call->apilist->IsEnoughItemsInMailbox((Gt_GameItemT)JXSJ_ITEM_GOLD,&mailboxgold,call);
	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		XLOG("查询邮箱金币失败");

		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}
	XLOG("邮箱中有金币数为%lld",mailboxgold);
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
		XLOG("准备取出金币数量为%lld",withdrawgold);

		returnvalue = call->apilist->WithdrawItemsInMailbox((Gt_GameItemT)JXSJ_ITEM_GOLD,&withdrawgold,call);
		if ( returnvalue == GT_OK )
		{
			XLOG("邮箱取钱成功");
		}
		else if( returnvalue == GT_FALSE )
		{
			XLOG("邮箱取钱失败");
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
		returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)JXSJ_ITEM_GOLD,&baggold,call);
		if ( returnvalue != GT_OK )
		{
			XLOG("查询背包金币失败");

			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
		XLOG("取完邮箱金币后,查询背包金币为%lld",baggold);
		if ( baggold >= tasklet.post.buyerMoney )
		{
			XLOG("玩家背包金币比需求数量多");

			sendMailprocess(call,tasklet,taskresult);
			return;
		}
	}

	/*
	查询仓库金币
	*/
	INT64 warehousegold;
	returnvalue = call->apilist->QueryItemsInWarehouse((Gt_GameItemT)JXSJ_ITEM_GOLD,&warehousegold,call);
	if ( returnvalue != GT_OK )
	{
		XLOG("查询仓库金币失败");
		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}

	XLOG("仓库中有金币数为%lld",warehousegold);

	if ( baggold + warehousegold >= tasklet.post.buyerMoney )
	{
		/*
		移动到仓库
		*/
		call->timeout = 50000;
		returnvalue = call->apilist->MoveToByNpcID(JXSJ_NPC_WAREHOUSE,call);
		if ( returnvalue != GT_OK )
		{
			XLOG("移动到仓库失败");
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
		else
		{
			XLOG("移动到仓库成功");

			/*
			从仓库取金币
			*/
			withdrawgold = tasklet.post.buyerMoney - baggold;

			XLOG("准备取出金币数量为%lld",withdrawgold);

			returnvalue = call->apilist->WithdrawItemsInWarehouse((Gt_GameItemT)JXSJ_ITEM_GOLD,&withdrawgold,call);
			if ( returnvalue == GT_OK )
			{
				XLOG("仓库取钱成功");
			}
			else if( returnvalue == GT_FALSE )
			{
				XLOG("仓库取钱失败");
			}
			else
			{
				checkReturnvalueprocess(returnvalue,taskresult);
				return;
			}
			returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)JXSJ_ITEM_GOLD,&baggold,call);
			if ( returnvalue != GT_OK )
			{
				XLOG("查询背包金币失败");

				checkReturnvalueprocess(returnvalue,taskresult);
				return;
			}
			XLOG("取完仓库金币后,查询背包金币为%lld",baggold);
			if ( baggold >= tasklet.post.buyerMoney )
			{
				XLOG("玩家背包金币比需求数量多");

				sendMailprocess(call,tasklet,taskresult);
				return;
			}
		}
	}
	else
	{
		XLOG("玩家金币不足");
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
		XLOG("上一步操作失败导致无法继续");
		return;
	}
	else if ( returnvalue == GT_RECOQNIZEREMPTY )
	{
		XLOG("答题器答题结果为空,放弃答题");

		taskresult.result = GT_ERR_3160;
		return;
	}
	else if ( returnvalue == GT_DYNAMICMB )
	{
		XLOG("有金山令牌,转人工");

		taskresult.result = GT_ERR_3010;
		return;
	}
	else if ( returnvalue == GT_MBERROR )
	{
		XLOG("密保答题错误");

		taskresult.result = GT_ERR_2090;
		return;
	}
	else if ( returnvalue == GT_SECONDPWDERROR )
	{
		XLOG("玩家提供的二级密码错误");

		taskresult.result = GT_ERR_2020;
		return;
	}
	else if ( returnvalue == GT_PLAYERINLINE )
	{
		XLOG("玩家在线无法登陆");

		taskresult.result = GT_ERR_3210;
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
		taskresult.result = GT_ERR_3190;

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
	else if ( returnvalue == GT_NoGoods )
	{
		XLOG("没有物品(需要使用物品时)");

		taskresult.result = GT_ERR_3040;
		return;
	}
	else if ( returnvalue == GT_NpcNotFind )
	{
		XLOG("找不到npc");
		return;
	}
	else if ( returnvalue == GT_OpenNpcFail )
	{
		XLOG("打开ncp失败");
		return;
	}
	else if ( returnvalue == GT_NotEnoughMoney )
	{
		XLOG("银两不够");
		return;
	}
	else if ( returnvalue == GT_PlayerOffline )
	{
		XLOG("玩家不在线(对方不在线加不了好友)");

		taskresult.result = GT_ERR_3200;
		return;
	}
	else if ( returnvalue == GT_AddFriendTimeout )
	{
		XLOG("加好友超时");

		taskresult.result = GT_ERR_3200;
		return;
	}
	else if ( returnvalue == GT_GetMapNameFail )
	{
		XLOG("获取地图名称失败");
		return;
	}
	else if ( returnvalue == GT_GameUncontrollable )
	{
		XLOG("游戏不可控(sendmessage超时,可能game挂了,应重启游戏)");
		return;
	}
	else if( returnvalue == GT_MBOnLimit )
	{
		XLOG("密保答题次数达到上限");
		return;
	}
	else if ( returnvalue == GT_AddFriendOffline )
	{
		XLOG("加好友断线了");
		return;
	}
	else
		XLOG("其他未知错误%d",returnvalue);
}

void JXSJ_Mailpost::sendMailprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;

	call->timeout = 180000;

	sendmailgold = baggold;
	/*
	发送邮件
	*/
	returnvalue = call->apilist->SendMail((char*)tasklet.post.buyerActor.c_str(),(char*)configdata.sMailTitle.c_str(),(char*)configdata.sMailContent.c_str(),tasklet.post.buyerMoney - 500,call);

	switch ( returnvalue )
	{
	case GT_OK:
		{
			XLOG("发邮件成功");
			taskresult.result = GT_ERR_1000;

			returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)JXSJ_ITEM_GOLD,&baggold,call);
			XLOG("发完邮件后背包金币为%d",(int)baggold);
		}
		break;
	case GT_TIMEOUT:
		{
			XLOG("发邮件超时");
			restartprocess(call,tasklet,taskresult);
		}
		break;
	case GT_CONNECTBREAK:
		{
			XLOG("发邮件时候连接中断");
			restartprocess(call,tasklet,taskresult);
		}
		break;
	case GT_GameUncontrollable:
		{
			XLOG("发邮件时候游戏崩溃");
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
		XLOG("来密保卡了");
		XLOG("密保卡数据%s",imagedata);
		XLOG("密保卡数据长度%d",size);
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
	XLOG("密保卡返回结果为%s",(char*)secret.c_str());
	return (char*)secret.c_str();
}

void JXSJ_Mailpost::checksendMailprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	查询背包金币
	*/
	returnvalue = call->apilist->QueryItemsInBag((Gt_GameItemT)JXSJ_ITEM_GOLD,&baggold,call);
	XLOG("邮件发送异常检测:背包金币%d",(int)baggold);
	if( baggold == sendmailgold )
	{
		XLOG("邮件发送异常检测:检测结果发邮件不成功");

		taskresult.result = GT_ERR_3120;
		return;
	}
	else
	{
		XLOG("邮件发送异常检测:检测结果发邮件成功");
		taskresult.result = GT_ERR_1000;
		return;
	}
}

bool JXSJ_Mailpost::loginprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int i;
	int returnvalue;

	/*
	选大区流程
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
			返回值大区无法连接,转人工
			*/
			taskresult.result = GT_ERR_3000;
			getLogger().Message("连接大区失败");
			return false;
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return false;
		}
	}

	XLOG("连接大区成功");

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
			/*
			返回值小区无法连接,转人工
			*/
			taskresult.result = GT_ERR_3020;
			XLOG("连接小区失败");
			return false;
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return false;
		}
	}

	XLOG("连接小区成功");

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
			return false;
		}
		else if ( returnvalue == GT_FALSE && i != login_trytimes -1 )
		{
			continue;
		}
		else if ( returnvalue == GT_FALSE && i == login_trytimes -1 )
		{
			XLOG("未知登陆错误");
			return false;
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return false;
		}
	}

	XLOG("账号登陆成功");

	/*
	角色登陆匹配流程
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
	角色登陆
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

			XLOG("无角色");
			return false;
		}
		else if ( returnvalue == GT_FALSE && i != selectrole_trytimes - 1 )
			continue;
		else if ( returnvalue == GT_FALSE && i == selectrole_trytimes - 1 )
		{
			taskresult.result = GT_ERR_2010;

			XLOG("无角色");
			return false;
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return false;
		}
	}

	XLOG("角色%s登陆成功",(char*)tasklet.post.sellerActor.c_str());

	return true;
}

void JXSJ_Mailpost::restartprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	call->apilist->End(call);

	/*
	启动游戏
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