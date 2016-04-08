#include "MailBox.h"

#define XLOG getRobotApp().logmsg

MailBox::MailBox(GtrApiWrap* wrap)
:WithDrawMethod( wrap, WithDrawMethod::WD_MAILBOX )
{
}

MailBox::~MailBox(void)
{
}

void MailBox::sendMail(gtr::GameTaskletT& tasklet)
{
	int returnvalue;
	/*
	�����ʼ�
	*/
	XLOG("��������㹻��׼�����ʼ�");
	returnvalue = _wrap->SendMail(tasklet.post.buyerActor,"youjian","youjian",tasklet.post.buyerMoney);
	if ( returnvalue == GT_OK )
	{
		appLogger().Message("�ʼ��ѷ���");
	}
	else if ( returnvalue == GT_NOTEXISTED )
	{
		throw(robot_error(GT_ERR_2050,"��ҽ�ɫ������"));
	}
	else if ( returnvalue == GT_MAIlBOXFULL )
	{
		throw(robot_error(GT_ERR_3070, "�����������"));
	}
	else if ( returnvalue == GT_MAIlBOXLOCKED )
	{
		throw(robot_error(GT_ERR_3070, "��������Ѷ���"));
	}
	else if ( returnvalue == GT_ROLEKICK )
	{
		throw(robot_error(GT_ERR_3050, "���Ҷ���"));
	}
	else if ( returnvalue == GT_TIMEOUT )
	{
		throw(robot_error(GT_ERR_3120, "ѡС����ʱ"));
	}
	else if ( returnvalue == GT_CONNECTBREAK )
	{
		throw(robot_error(GT_ERR_3120, "�����ж�"));
	}
	else
	{
		throw(robot_error(GT_ERR_3120, "����δ֪���ʼ�����"));
	}

}

bool MailBox::withdraw(gtr::GameTaskletT& tasklet, INT64 baggold)
{
	int returnvalue;
	/*
	�ж������н�ң���������ȡǮ
	*/
	INT64 mailboxgold = tasklet.post.buyerMoney - baggold;
	INT64 temp = mailboxgold;
	returnvalue = _wrap->IsEnoughItemsInMailbox(_gold,&temp); 
	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		throw(make_error( returnvalue));
	}
	if ( returnvalue == GT_TRUE )
	{
		appLogger().Message("���������㹻��Ǯ");
		returnvalue = _wrap->WithdrawItemsInMailbox(_gold,&mailboxgold); 

		if ( returnvalue != GT_OK )
		{
			throw(make_error( returnvalue));
		}

		appLogger().Message("������ȡǮ�ɹ�");
		return true;

	}
	else
	{
		appLogger().Message("������û���㹻��Ǯ");
	}

	return false;
}

