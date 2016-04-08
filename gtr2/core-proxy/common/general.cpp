#include "general.h"

#define XLOG getRobotApp().logmsg
//#define XLOG appLogger().Message

robot_error make_error( int returnvalue)
{
	assert ( returnvalue != GT_OK );

	if ( returnvalue == GT_FALSE )
	{
		return robot_error(GT_ERR_3120,"��һ������ʧ�ܵ����޷�����");
	}
	else if ( returnvalue == GT_NOTEXISTED )
	{
		return robot_error(GT_ERR_2050,"��һ���������ض������");
	}
	else if ( returnvalue == GT_MAIlBOXFULL )
	{
		return robot_error(GT_ERR_3070,"�����������");
	}
	else if ( returnvalue == GT_MAIlBOXLOCKED )
	{
		return robot_error(GT_ERR_2100,"��������Ѷ���");
	}
	else if ( returnvalue == GT_ROLEKICK )
	{
		return robot_error(GT_ERR_3050, "���Ҷ���");
	}
	else if ( returnvalue == GT_TIMEOUT )
	{
		return robot_error(GT_ERR_3120,"������ʱ");
	}
	else if ( returnvalue == GT_CONNECTBREAK )
	{
		return robot_error(GT_ERR_3190,"�����ж�");
	}
	else if ( returnvalue == GT_UNABLEMOVETO )
	{
		return robot_error(GT_ERR_3120,"�޷�����Ŀ��NPC");
	}
	else if ( returnvalue == GT_UNABLETALKTO )
	{
		return robot_error(GT_ERR_3120,"�޷��Ի�Ŀ��NPC");
	}
	else if ( returnvalue == GT_INSAFETIME )
	{
		return robot_error(GT_ERR_3120,"�ڰ�ȫʱ����,����ʧ��");
	}
	else if ( returnvalue == GT_ROLELOCK )
	{
		return robot_error(GT_ERR_3120,"�˺ű�����");
	}
	else if( returnvalue == GT_VERIFYCODEERROR)
	{
		return robot_error(GT_ERR_3160, "��֤��������");
	}
	else
	{
		return robot_error(GT_ERR_3120,"δ֪�ķ���ֵ");
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
	_errors[1].name = "�ܱ���";
	_errors[2].name = "�ܱ���";
	_errors[3].name = "��֤��";
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
		// �ܱ���δ�ϴ�
		setError(type, AUTH_NORMAL);
		
	}
	else if(secret=="2")
	{
		// ��ʾ����Աȡ������
		setError(type, AUTH_ABORT);
	}
	else if(secret=="000000")
	{
		// 000000��ʾ��ʱ
		setError(type, AUTH_TIMEOUT);
	}
	else
	{
		// δ֪�Ĵ������
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
		sprintf(buf, "%sδ�ϴ�", error.name.c_str());	
		error.message = buf;
		break;

	case AUTH_ABORT:
		error.code = -2;
		sprintf(buf, "����Ա����%s����", error.name.c_str());		
		error.message = buf;
		break;

	case AUTH_TIMEOUT:
		error.code++;
		XLOG("��%d��%s���ⳬʱ", error.code, error.name.c_str());
		break;

	}

}

void AnswerStub::checkException(int type)
{
	AnswerError &error = _errors[type];
	switch(error.code)
	{
	case -2:// ����Ա��������
		throw(robot_error(GT_ERR_3160, error.message.c_str()));
		break;

	case -1:// �ܱ���δ�ϴ�
		throw(robot_error(GT_ERR_3110, error.message.c_str()));
		break;

	case 0:
		break;

	default:
		if(error.code > 0)
		{
			if(error.code > error.timeouts)
			{
				// ���ⳬʱ
				char buf[255];
				sprintf(buf, "�ܱ������ⳬʱ%d��", error.timeouts);
				throw(robot_error(GT_ERR_3230, buf));
			}
		}
		else
		{
			throw(robot_error(GT_ERR_3230, "δ֪�Ĵ����쳣"));
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
		XLOG("��⵽�ֿ�NPC");
		/*
		�ƶ���NPC
		*/
		if(!(_maskAction & MASK_MOVETO))
		{
			returnvalue = _wrap->MoveToByNpcID(_npcType);
			if ( returnvalue != GT_OK )
			{
				XLOG("�ƶ����ֿ�NPCʧ��");
				return GT_FALSE;
			}
		}
		/*
		��NPC�Ի�
		*/
		if(!(_maskAction & MASK_TALK))
		{
			returnvalue = _wrap->Talk(_npcType);
			if ( returnvalue != GT_OK )
			{
				XLOG("��ֿ�NPC�Ի�ʧ��");
				return GT_FALSE;
			}
		}
		/*
		��
		*/
		if(!(_maskAction & MASK_OPEN))
		{
			returnvalue = Open();
			if ( returnvalue == GT_OK )
			{
				XLOG("����ṩ��2��������ȷ");
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
	�ж��Ƿ����
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

	XLOG("��ȫ�������ɹ�");

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
		XLOG("���Դ�%sȡ���", _name.c_str());
	else
		XLOG("���Դ�%sȡ%lld���", _name.c_str(), data->num);

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
		//XLOG("��%sȡ��ҳɹ�[%lld]",_name.c_str(), data->num);
		XLOG("��%sȡ��ҳɹ�",_name.c_str());
	}
	else
	{
		XLOG("��%sȡ���ʧ��",_name.c_str());
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
		XLOG("%s�������Ϊ%lld",_name.c_str(), data->num);
		//XLOG("��Ұ��ɲֿ��ڽ�������Ϊ%d",(int)_item[0].itemnum);
		//XLOG("��Ұ��ɲֿ��ڽ������Ϊ%d",(int)_item[1].itemnum);
		//XLOG("��Ұ��ɲֿ��ڽ�ש����Ϊ%d",(int)_item[2].itemnum);
	}
	else
	{
		XLOG("��ѯ%s���ʧ��",_name.c_str());
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

	XLOG("ȡ����ɲֿ�����Ʒ����ұ����ڽ�������Ϊ%d",(int)_item[0].itemnum);
	XLOG("ȡ����ɲֿ�����Ʒ����ұ����ڽ������Ϊ%d",(int)_item[1].itemnum);
	XLOG("ȡ����ɲֿ�����Ʒ����ұ����ڽ�ש����Ϊ%d",(int)_item[2].itemnum);
#endif

}

