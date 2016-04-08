#pragma once

#include "general.h"

class MailBox	:	public WithDrawMethod
{
	Gt_GameItemT _gold;

public:
	MailBox(GtrApiWrap* wrap);
	~MailBox(void);
	void sendMail(gtr::GameTaskletT& tasklet);
	bool withdraw(gtr::GameTaskletT& tasklet, INT64 baggold);
};
