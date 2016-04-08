#include "mhzx_mailpost.h"
#include <assert.h>

#define SAFE_TIME 120
#define MAX_GOLD 200000 * 10000

const int selectserver_trytimes = 2;
const int selectarea_trytimes = 2;
const int login_trytimes = 2;
const int inputmb_trytimes = 3;
const int selectrole_trytimes = 3;
const int sellitem_trytimes = 3;

IMPLEMENT_APP_CONSOLE(MHZX_Mailpost)

#define XLOG getLogger().Message
char buf[256];

void MHZX_Mailpost::task_MailPost(gtr::GameTaskResultT& result)
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

	XLOG("返回服务器的交易结果为%d",(int)result.result);
}

void MHZX_Mailpost::run(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
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

	int i;
	int returnvalue;

	/*
	选大区流程
	*/
	for ( i = 0; i < selectserver_trytimes; ++i )
	{
		returnvalue = call->apilist->SelectServer(const_cast<char*>(tasklet.server.c_str()),call);
		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_UNABLECONNECT && i != selectserver_trytimes - 1 )
			continue;
		else if ( returnvalue == GT_UNABLECONNECT && i == selectserver_trytimes - 1 )
		{
			/*
			返回值大区无法连接,转人工
			*/
			taskresult.result = GT_ERR_3000;
			getLogger().Message("连接大区失败");
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
	for ( i = 0; i < selectarea_trytimes; ++i )
	{
		returnvalue = call->apilist->SelectArea(const_cast<char*>(tasklet.area.c_str()),call);
		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_UNABLECONNECT && i != selectarea_trytimes - 1 )
			continue;
		else if ( returnvalue == GT_UNABLECONNECT && i == selectarea_trytimes - 1 )
		{
			/*
			返回值小区无法连接,转人工
			*/
			taskresult.result = GT_ERR_3020;
			getLogger().Message("连接小区失败");
			return;
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
	}

	getLogger().Message("连接小区成功");

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

			XLOG("账号密码无法认证");
			return;
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
	}

	/*
	角色登陆
	*/
}

void MHZX_Mailpost::checkReturnvalueprocess( int returnvalue, gtr::GameTaskResultT& taskresult )
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