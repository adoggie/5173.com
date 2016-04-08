#pragma once

#include "general.h"

class Grocer	:	public NPC
{
	ItemData	_item[3];
	gtr::GameTaskletT _tasklet;

public:
	Grocer(GtrApiWrap* wrap);
	void sellItemprocess();

private:
	inline INT64 calculate_buyermoney()
	{
		return (_tasklet.post.buyerMoney * 10000);
	}
	bool sellItem(Gt_GameItemT type);

};

