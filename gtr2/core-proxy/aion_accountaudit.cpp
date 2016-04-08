
#include "aion_accountaudit.h"

extern string ws2s(wstring& inputws);
extern std::wstring s2ws(const string& s);

IMPLEMENT_APP_CONSOLE(Aion_AccountAudit)

const int selectserver_trytimes = 3;
const int selectarea_trytimes = 3;
const int login_trytimes = 1;
const int inputmb_trytimes = 3;
const int selectrole_trytimes = 3;

//#define XLOG logmsg
#define XLOG getLogger().Debug

void Aion_AccountAudit::task_AccountAudit(gtr::GameTaskResultT& result)
{
	XLOG("订单号为%s",(char*)_tasklet.no.c_str());
	XLOG("卖家姓名为%s",_tasklet.audit.sellerActor.c_str());
	XLOG("订单中大区信息为%s",_tasklet.area.c_str());
	XLOG("订单中小区信息为%s",_tasklet.server.c_str());
	XLOG("订单中账号信息为%s",_tasklet.account.c_str());

	_gamectx.timeout = 60000;
	/*
	预定义默认的返回结果
	*/
	result.result = GT_ERR_8050;

	/*
	中间的处理过程
	*/
	run(&_gamectx,_tasklet,result);

	XLOG("调用End接口");
	/*
	关闭游戏
	*/
	_gamectx.apilist->End(&_gamectx);

	XLOG("返回服务器的账号审核结果为%d",(int)result.result);
}

void Aion_AccountAudit::run(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int i;
	int returnvalue;

	/*
	选大区流程
	*/
	for ( i = 0; i < selectarea_trytimes; ++i )
	{
		returnvalue = call->apilist->SelectServer(const_cast<char*>(tasklet.area.c_str()),call);
		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_UNABLECONNECT && i != selectserver_trytimes - 1 )
			continue;
		else if ( returnvalue == GT_UNABLECONNECT && i == selectserver_trytimes - 1 )
		{
			/*
			返回值大区无法连接
			*/
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
	启动登陆器
	*/
	returnvalue = _gamectx.apilist->Begin(&_gamectx);
	if ( returnvalue != GT_OK )
	{
		XLOG("启动游戏失败");
		/*
		启动游戏失败
		*/
		_gamectx.apilist->End(&_gamectx);
		return;
	}

	XLOG("启动游戏成功");

	Sleep(6000);

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
			卖家密码错误
			*/
			taskresult.result = GT_ERR_8010;

			XLOG("卖家密码错误");
			return;
		}
		else if ( returnvalue == GT_DYNAMICMB )
		{
			/*
			动态密保或手机密保转人工
			*/
			taskresult.result = GT_ERR_8040;

			XLOG("动态密保或手机密保转人工");
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
	}

	XLOG("登陆成功");


	/*
	选小区流程
	*/
	for ( i = 0; i < selectarea_trytimes; ++i )
	{
		returnvalue = call->apilist->SelectArea(const_cast<char*>(tasklet.server.c_str()),call);
		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_UNABLECONNECT && i != selectarea_trytimes - 1 )
			continue;
		else if ( returnvalue == GT_UNABLECONNECT && i == selectarea_trytimes - 1 )
		{
			XLOG("小区无法连接");
			return;
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
	}

	XLOG("选小区成功");

	Sleep(2000);

	/*
	选角色流程
	*/
	XLOG("选择订单中的角色%s登陆",tasklet.audit.sellerActor.c_str());
	for ( i = 0; i < selectrole_trytimes; ++i )
	{
		returnvalue = call->apilist->SelectRoleByName((char*)_tasklet.audit.sellerActor.c_str(),call);
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

			taskresult.result = GT_ERR_8030;
			return;
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
	}

	XLOG("角色%s登陆成功",tasklet.post.sellerActor.c_str());

	/*
	看需要回城否
	*/

	returnvalue = call->apilist->IsNeedBackHome(call);

	if ( returnvalue == GT_OK )
	{
		XLOG("需要使用回城");
		if (backhomeItemprocess(call,tasklet,taskresult)==false)
			return;
	}
	else if( returnvalue == GT_FALSE )
	{
		XLOG("不需要使用回城");
	}
	else
	{
		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}

	/*
	获取最佳行走路线
	*/
	int npclist[16] = {0};
	int size = 16;
	int* begin = npclist;
	returnvalue = call->apilist->GetBestNPC(begin,&size,call);
	if ( returnvalue != GT_OK )
	{
		XLOG("获取最佳路线失败");
		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}
	for ( int i = 0; i < size; ++i )
	{
		int npctype = *(begin + i);

		XLOG("第%d个步骤是%d",i + 1, npctype);

		XLOG("开始移动到%d号NPC", npctype);
		call->timeout = 180000;
		returnvalue = call->apilist->MoveToByNpcID(npctype,call);
		if ( returnvalue != GT_OK )
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
		call->timeout = 60000;
		XLOG("移动到%d号NPC成功", npctype);
		XLOG("开始对话%d号NPC", npctype);
		returnvalue = call->apilist->Talk(npctype,call);
		if ( returnvalue != GT_OK )
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
		XLOG("对话%d号NPC成功", npctype);

		switch (npctype)
		{
		case AION_NPC_FLY:
		case AION_NPC_TRANSPORT:
			{
				XLOG("开始使用%d号NPC的传送和飞行功能", npctype);
				call->timeout = 120000;
				returnvalue = call->apilist->Transport(npctype,call);
				if ( returnvalue != GT_OK )
				{
					checkReturnvalueprocess(returnvalue,taskresult);
					return;
				}
				XLOG("传送或者飞行成功");
			}
			break;
		case AION_NPC_MAILBOX:
			{
				XLOG("开始打开邮箱");
				returnvalue = call->apilist->OpenMailBox("",call);
				if ( returnvalue != GT_OK )
				{
					checkReturnvalueprocess(returnvalue,taskresult);
					return;
				}
				XLOG("打开邮箱成功");
				XLOG("保存邮箱物品信息开始");
				call->timeout = 180000;
				returnvalue = call->apilist->SaveItemInfo(npctype,call);
				if ( returnvalue != GT_OK )
				{
					checkReturnvalueprocess(returnvalue,taskresult);
					return;
				}
				XLOG("保存邮箱物品信息成功");
			}
			break;
		case AION_NPC_WAREHOUSE:
			{
				XLOG("开始打开仓库");
				returnvalue = call->apilist->OpenWarehouse((char*)_tasklet.audit.sellerSecondPwd.c_str(),call);
				if ( returnvalue != GT_OK )
				{
					checkReturnvalueprocess(returnvalue,taskresult);
					return;
				}
				XLOG("打开仓库成功");
				XLOG("开始保存仓库物品信息");
				returnvalue = call->apilist->SaveItemInfo(npctype,call);
				if ( returnvalue != GT_OK )
				{
					checkReturnvalueprocess(returnvalue,taskresult);
					return;
				}
				XLOG("保存仓库物品信息成功");
			}
			break;
		case AION_NPC_EXCHANGE:
			{
				XLOG("开始打开交易所");
				returnvalue = call->apilist->OpenExchange("",call);
				if ( returnvalue != GT_OK )
				{
					checkReturnvalueprocess(returnvalue,taskresult);
					return;
				}
				XLOG("打开交易所成功");
				XLOG("开始保存交易所物品信息");
				returnvalue = call->apilist->SaveItemInfo(npctype,call);
				if ( returnvalue != GT_OK )
				{
					checkReturnvalueprocess(returnvalue,taskresult);
					return;
				}
				XLOG("保存交易所物品信息成功");
			}
			break;
		default:
			assert(0);
		}
	}

	call->timeout = 60000;

	XLOG("保存背包和身上物品信息开始");
	/*
	保存角色属性,背包物品信息等
	*/
	returnvalue = call->apilist->SaveItemInfo(AION_SELF,call);
	if ( returnvalue != GT_OK )
	{
		XLOG("保存背包和身上物品信息失败");
		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}
	XLOG("保存背包和身上物品信息成功");

	XLOG("开始获取角色账号信息");

	/*
	获取账号信息
	*/

	char* info = NULL;
	int infosize;
	returnvalue = call->apilist->GetAccountInfo(&info,&infosize,call);

	if ( returnvalue == GT_OK )
	{
		XLOG("获取角色账号信息成功");

		AddAionItemType();
		AddAionItemProperty();
		accountinfo.parse(info,infosize);
		accountinfo.save();
		std::wstring doc = accountinfo.m_markup.GetDoc();
		taskresult.textval = ws2s(doc);

		taskresult.result = GT_ERR_8000;
	}
	else
	{
		XLOG("获取角色账号信息失败");

		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}
}

void Aion_AccountAudit::checkReturnvalueprocess( int returnvalue, gtr::GameTaskResultT& taskresult )
{
	if ( returnvalue == GT_OK )
	{
		return;
	}
	else if ( returnvalue == GT_FALSE )
	{
		XLOG("上一步操作失败导致无法继续");
		return;
	}
	else if ( returnvalue == GT_ROLEKICK )
	{
		XLOG("上一步操作卖家顶号");
		return;
	}
	else if ( returnvalue == GT_TIMEOUT )
	{
		XLOG("上一步操作超时");
		return;
	}
	else if ( returnvalue == GT_CONNECTBREAK )
	{
		XLOG("上一步操作连接中断");
		return;
	}
	else if ( returnvalue == GT_PLAYERINLINE )
	{
		XLOG("玩家在线");
		return;
	}
	else if ( returnvalue == GT_ROLELOCK )
	{
		XLOG("玩家被封号");
		return;
	}
	else if ( returnvalue == GT_UNABLEMOVETO )
	{
		XLOG("无法到达目的地");
		return;
	}
	else if ( returnvalue == GT_UNABLETALKTO )
	{
		XLOG("无法对话NPC");
		return;
	}
	else
	{
		XLOG("未知的返回值%d",returnvalue);
		return;
	}
}

bool Aion_AccountAudit::backhomeSkillprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	检测回城技能
	*/
	returnvalue = call->apilist->IsExistBackHomeSkill(call);
	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return false;
	}
	else if ( returnvalue == GT_TRUE )
	{
		XLOG("玩家存在回城技能");
		returnvalue = call->apilist->UseBackHomeSkill(call);
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return false;
		}
		else if( returnvalue == GT_TRUE )
		{
			XLOG("玩家使用回城技能成功");
			return true;
		}
		else
		{
			XLOG("玩家使用回城技能失败");
			return false;
		}
	}
	else
	{
		XLOG("玩家不存在回城技能");
		return false;
	}
}
bool Aion_AccountAudit::backhomeItemprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	检测回城物品
	*/
	returnvalue = call->apilist->IsExistBackHomeItem(call);
	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return false;
	}
	else if ( returnvalue == GT_TRUE )
	{
		XLOG("玩家存在回城物品");
		returnvalue = call->apilist->UseBackHomeItem(call);
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return false;
		}
		else if( returnvalue == GT_TRUE )
		{
			XLOG("玩家使用回城物品成功");
			return true;
		}
		else
		{
			XLOG("玩家使用回城物品失败");
			if (backhomeSkillprocess(call,tasklet,taskresult))
				return true;
			else
				return false;
		}
	}
	else
	{
		XLOG("玩家不存在回城物品");
		if (backhomeSkillprocess(call,tasklet,taskresult))
			return true;
		else
			return false;
	}
}

void Aion_AccountAudit::AddAionItemType()
{
	accountinfo.AddItemType( wxT("消耗品") );

	accountinfo.AddItemSpecialType( wxT("消耗品") );
}
void Aion_AccountAudit::AddAionItemProperty()
{
	accountinfo.AddItemProperty( wxT("物理防御力"),	wxT("物理防御力 +([^@]+)") );
}