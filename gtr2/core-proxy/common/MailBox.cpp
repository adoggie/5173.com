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
	发送邮件
	*/
	XLOG("金币数量足够，准备发邮件");
	returnvalue = _wrap->SendMail(tasklet.post.buyerActor,"youjian","youjian",tasklet.post.buyerMoney);
	if ( returnvalue == GT_OK )
	{
		appLogger().Message("邮件已发送");
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

bool MailBox::withdraw(gtr::GameTaskletT& tasklet, INT64 baggold)
{
	int returnvalue;
	/*
	判断邮箱中金币，从邮箱中取钱
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
		appLogger().Message("邮箱中有足够的钱");
		returnvalue = _wrap->WithdrawItemsInMailbox(_gold,&mailboxgold); 

		if ( returnvalue != GT_OK )
		{
			throw(make_error( returnvalue));
		}

		appLogger().Message("从邮箱取钱成功");
		return true;

	}
	else
	{
		appLogger().Message("邮箱中没有足够的钱");
	}

	return false;
}

