#include "general.h"

#define XLOG getRobotApp().logmsg
//#define XLOG appLogger().Message

robot_error make_error( int returnvalue)
{
	assert ( returnvalue != GT_OK );

	if ( returnvalue == GT_FALSE )
	{
		return robot_error(GT_ERR_3120,"上一步操作失败导致无法继续");
	}
	else if ( returnvalue == GT_NOTEXISTED )
	{
		return robot_error(GT_ERR_2050,"上一步操作返回对象错误");
	}
	else if ( returnvalue == GT_MAIlBOXFULL )
	{
		return robot_error(GT_ERR_3070,"买家邮箱已满");
	}
	else if ( returnvalue == GT_MAIlBOXLOCKED )
	{
		return robot_error(GT_ERR_2100,"买家邮箱已冻结");
	}
	else if ( returnvalue == GT_ROLEKICK )
	{
		return robot_error(GT_ERR_3050, "卖家顶号");
	}
	else if ( returnvalue == GT_TIMEOUT )
	{
		return robot_error(GT_ERR_3120,"操作超时");
	}
	else if ( returnvalue == GT_CONNECTBREAK )
	{
		return robot_error(GT_ERR_3190,"连接中断");
	}
	else if ( returnvalue == GT_UNABLEMOVETO )
	{
		return robot_error(GT_ERR_3120,"无法到达目标NPC");
	}
	else if ( returnvalue == GT_UNABLETALKTO )
	{
		return robot_error(GT_ERR_3120,"无法对话目标NPC");
	}
	else if ( returnvalue == GT_INSAFETIME )
	{
		return robot_error(GT_ERR_3120,"在安全时间中,操作失败");
	}
	else if ( returnvalue == GT_ROLELOCK )
	{
		return robot_error(GT_ERR_3120,"账号被锁定");
	}
	else if( returnvalue == GT_VERIFYCODEERROR)
	{
		return robot_error(GT_ERR_3160, "验证码答题错误");
	}
	else
	{
		return robot_error(GT_ERR_3120,"未知的返回值");
	}

}

int Type2NpcType(int type)
{
	switch(type)
	{
	case WithDrawMethod::WD_BANK:
		return NPC_BANK;
		break;

	case WithDrawMethod::WD_EXCHANGE:
		return NPC_GUILDWAREHOUSE;
		break;

	case WithDrawMethod::WD_WAREHOUSE:
		return NPC_WAREHOUSE;
		break;

	case WithDrawMethod::WD_MAILBOX:
		return NPC_MAILBOX;
		break;

	}

}

AnswerStub::AnswerStub()
{
	_errors[1].name = "密保卡";
	_errors[2].name = "密保卡";
	_errors[3].name = "验证码";
}
void AnswerStub::setMask(int type, int max)
{
	AnswerError &error = _errors[type];
	error.timeouts = max;
}

void AnswerStub::doCheck(int type, string secret)
{
	if(secret=="1")
	{
		// 密保卡未上传
		setError(type, AUTH_NORMAL);
		
	}
	else if(secret=="2")
	{
		// 表示答题员取消答题
		setError(type, AUTH_ABORT);
	}
	else if(secret=="000000")
	{
		// 000000表示超时
		setError(type, AUTH_TIMEOUT);
	}
	else
	{
		// 未知的答题错误
		setError(type, AUTH_UNKNOWN);
	}

}

void AnswerStub::Do()
{
	checkException(1);
	checkException(2);
	checkException(3);

}

void AnswerStub::setError(int type, int ret)
{
	char buf[255];
	AnswerError &error = _errors[type];
	switch(ret)
	{
	case AUTH_NORMAL:
		error.code = -1;
		sprintf(buf, "%s未上传", error.name.c_str());	
		error.message = buf;
		break;

	case AUTH_ABORT:
		error.code = -2;
		sprintf(buf, "答题员放弃%s答题", error.name.c_str());		
		error.message = buf;
		break;

	case AUTH_TIMEOUT:
		error.code++;
		XLOG("第%d次%s答题超时", error.code, error.name.c_str());
		break;

	}

}

void AnswerStub::checkException(int type)
{
	AnswerError &error = _errors[type];
	switch(error.code)
	{
	case -2:// 答题员放弃答题
		throw(robot_error(GT_ERR_3160, error.message.c_str()));
		break;

	case -1:// 密保卡未上传
		throw(robot_error(GT_ERR_3110, error.message.c_str()));
		break;

	case 0:
		break;

	default:
		if(error.code > 0)
		{
			if(error.code > error.timeouts)
			{
				// 答题超时
				char buf[255];
				sprintf(buf, "密保卡答题超时%d次", error.timeouts);
				throw(robot_error(GT_ERR_3230, buf));
			}
		}
		else
		{
			throw(robot_error(GT_ERR_3230, "未知的答题异常"));
		}
		break;

	}
}

NPC::NPC(GtrApiWrap* wrap, int npcType)
{
	_wrap = wrap;
	_npcType = (eNPCType)npcType;
}

GT_RESULT NPC::Open()
{
	switch(_npcType)
	{
	case NPC_BANK:
		return _wrap->OpenBank((char*)_password.c_str());
		break;

	case NPC_GUILDWAREHOUSE:
		return _wrap->OpenExchange((char*)_password.c_str());
		break;

	case NPC_WAREHOUSE:
		return _wrap->OpenWarehouse((char*)_password.c_str());
		break;

	case NPC_MAILBOX:
		return _wrap->OpenMailBox((char*)_password.c_str());
		break;

	case NPC_GROCER:
		return _wrap->OpenGrocer((char*)_password.c_str());
		break;
	}
}

void NPC::setActionMask(int mask)
{
	_maskAction = mask;
}

bool NPC::Create()
{
	int  returnvalue = GT_OK;

	if( !(_maskAction & MASK_ISEXIST) )
		returnvalue = _wrap->IsExistNPC(_npcType);

	if ( returnvalue == GT_OK )
	{
		XLOG("检测到仓库NPC");
		/*
		移动到NPC
		*/
		if(!(_maskAction & MASK_MOVETO))
		{
			returnvalue = _wrap->MoveToByNpcID(_npcType);
			if ( returnvalue != GT_OK )
			{
				XLOG("移动到仓库NPC失败");
				return GT_FALSE;
			}
		}
		/*
		与NPC对话
		*/
		if(!(_maskAction & MASK_TALK))
		{
			returnvalue = _wrap->Talk(_npcType);
			if ( returnvalue != GT_OK )
			{
				XLOG("与仓库NPC对话失败");
				return GT_FALSE;
			}
		}
		/*
		打开
		*/
		if(!(_maskAction & MASK_OPEN))
		{
			returnvalue = Open();
			if ( returnvalue == GT_OK )
			{
				XLOG("玩家提供的2级密码正确");
			}
			else
			{
			}
		}

	}

	return returnvalue==GT_OK;
}

void NPC::WaitUnLocked()
{
	/*
	判断是否解锁
	*/
	int returnvalue = GT_FALSE;
	while (!returnvalue)
	{
		returnvalue = _wrap->IsUnlocked(); 

		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			throw(make_error(returnvalue));
		}
		Sleep(1000);
	}

	XLOG("安全锁解锁成功");

}

WithDrawMethod::WithDrawMethod(GtrApiWrap* wrap, int type)
:NPC(wrap, Type2NpcType(type))
{
	_type = type;
}

void WithDrawMethod::Collect(ItemData &ingot, ItemData &bullion, ItemData &brick, INT64 &gold)
{

}

void WithDrawMethod::setName(string name)
{
	_name = name;
}

void WithDrawMethod::setWithdrawNum(INT64 withdraw)
{
	ItemData *data = &_items[GT_ITEM_1];
	data->num = withdraw;
}

INT64 WithDrawMethod::getNumber(Gt_GameItemT item)
{
	ItemData *data = &_items[item];
	return data->num;
}

GT_RESULT WithDrawMethod::WithdrawItems(Gt_GameItemT item, ICheck *check)
{
	GT_RESULT returnvalue = GT_TRUE;

	ItemData *data = &_items[item];

	if( data->num < 0)
		XLOG("尝试从%s取金币", _name.c_str());
	else
		XLOG("尝试从%s取%lld金币", _name.c_str(), data->num);

	switch(_type)
	{
	case WithDrawMethod::WD_BANK:
		returnvalue = _wrap->WithdrawItemsInBank(item, &data->num);
		break;

	case WithDrawMethod::WD_EXCHANGE:
		returnvalue = _wrap->WithdrawItemsInExchange(item, &data->num);
		break;

	case WithDrawMethod::WD_WAREHOUSE:
		returnvalue = _wrap->WithdrawItemsInWarehouse(item, &data->num);
		break;

	case WithDrawMethod::WD_MAILBOX:
		returnvalue = _wrap->WithdrawItemsInMailbox(item, &data->num);
		break;

	}

	if(check)
	{
		returnvalue = check->Do(returnvalue, _type);
	}

	if(returnvalue == GT_OK)
	{
		//XLOG("从%s取金币成功[%lld]",_name.c_str(), data->num);
		XLOG("从%s取金币成功",_name.c_str());
	}
	else
	{
		XLOG("从%s取金币失败",_name.c_str());
	}

	return returnvalue;

}

GT_RESULT WithDrawMethod::QueryItems(Gt_GameItemT item)
{
	GT_RESULT returnvalue = GT_TRUE;

	ItemData *data = &_items[item];

	data->num = 0;

	switch(_type)
	{
	case WithDrawMethod::WD_BANK:
		returnvalue = _wrap->QueryItemsInBank(item, &data->num);
		break;

	case WithDrawMethod::WD_EXCHANGE:
		returnvalue = _wrap->QueryItemsInExchange(item, &data->num);
		break;

	case WithDrawMethod::WD_WAREHOUSE:
		returnvalue = _wrap->QueryItemsInWarehouse(item, &data->num);
		break;

	case WithDrawMethod::WD_MAILBOX:
		//returnvalue = _wrap->QueryItemsInMailbox(item, &data->num);
		break;

	}

	if(returnvalue == GT_OK)
	{
		XLOG("%s金币数量为%lld",_name.c_str(), data->num);
		//XLOG("玩家帮派仓库内金条数量为%d",(int)_item[0].itemnum);
		//XLOG("玩家帮派仓库内金块数量为%d",(int)_item[1].itemnum);
		//XLOG("玩家帮派仓库内金砖数量为%d",(int)_item[2].itemnum);
	}
	else
	{
		XLOG("查询%s金币失败",_name.c_str());
	}
	return returnvalue;
}

void WithDrawMethod::Do(INT64 delta)
{
#if 0
	for(int i=0; i< _items.size(); i++)
	{
		QueryItems((Gt_GameItemT)_items[i].type);
	}

	WithdrawItems((Gt_GameItemT)_item[0].itemtype,	&guildgoldingot		);
	WithdrawItems((Gt_GameItemT)_item[1].itemtype,	&guildgoldbullion		);
	WithdrawItems((Gt_GameItemT)_item[2].itemtype,	&guildgoldbrick		);

	_wrap->QueryItemsInBag((Gt_GameItemT)_item[0].itemtype,	&_item[0].itemnum	);
	_wrap->QueryItemsInBag((Gt_GameItemT)_item[1].itemtype,	&_item[1].itemnum	);
	_wrap->QueryItemsInBag((Gt_GameItemT)_item[2].itemtype,	&_item[2].itemnum	);

	XLOG("取完帮派仓库内物品后玩家背包内金条数量为%d",(int)_item[0].itemnum);
	XLOG("取完帮派仓库内物品后玩家背包内金块数量为%d",(int)_item[1].itemnum);
	XLOG("取完帮派仓库内物品后玩家背包内金砖数量为%d",(int)_item[2].itemnum);
#endif

}

