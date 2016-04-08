#include "Grocer.h"

Grocer::Grocer(GtrApiWrap* wrap)
:NPC(wrap, NPC_GROCER)
{

}
bool Grocer::sellItem(Gt_GameItemT type)
{
	ItemData *curr;

	INT64 baggold;
	int returnvalue;

	INT64 num = 0;
	if ( baggold + curr->num * curr->price >= calculate_buyermoney() )
	{
		if ((calculate_buyermoney() - baggold)%curr->price == 0)
		{
			num = (calculate_buyermoney() - baggold)/curr->price;
		}
		else
		{
			num = (calculate_buyermoney() - baggold)/curr->price + 1;
		}
	}
	else
	{
		if (curr->num != 0)
		{
			num = curr->num;
		}
	}

	returnvalue = _wrap->SellItem(type,(int)num);

	/*
	查询卖完金块后背包金币
	*/
//	returnvalue = _wrap->QueryItemsInBag((Gt_GameItemT)WULIN2_GOLD,&baggold);

	/*
	判断卖完金块后背包金币是否够订单用
	*/
	if ( baggold >= calculate_buyermoney() )
	{
		return true;
	}

	return false;
}

void Grocer::sellItemprocess()
{
	int returnvalue;

	/*
	判断是否解锁
	*/
	returnvalue = GT_FALSE;
	while (!returnvalue)
	{
		returnvalue = _wrap->IsUnlocked();
		Sleep(100);
	}

	appLogger().Message("安全锁解锁成功");

#if 0
	/*
	先卖金块
	*/
	sellItem(WULIN2_GOLDBULLION);

	/*
	再卖金砖
	*/
	sellItem(WULIN2_GOLDBRICK);

	/*
	最后卖金条
	*/
	sellItem(WULIN2_GOLDINGOT);
#endif

}

