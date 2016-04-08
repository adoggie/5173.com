#pragma once

#include "general.h"

class Warehouse	:	public WithDrawMethod
{
	Gt_GameItemT _gold;
public:
	Warehouse(GtrApiWrap* wrap);
	~Warehouse(void);
	bool withdraw(gtr::GameTaskletT& tasklet, INT64 baggold);
};
