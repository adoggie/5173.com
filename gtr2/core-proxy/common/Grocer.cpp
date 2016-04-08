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
	��ѯ������󱳰����
	*/
//	returnvalue = _wrap->QueryItemsInBag((Gt_GameItemT)WULIN2_GOLD,&baggold);

	/*
	�ж�������󱳰�����Ƿ񹻶�����
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
	�ж��Ƿ����
	*/
	returnvalue = GT_FALSE;
	while (!returnvalue)
	{
		returnvalue = _wrap->IsUnlocked();
		Sleep(100);
	}

	appLogger().Message("��ȫ�������ɹ�");

#if 0
	/*
	�������
	*/
	sellItem(WULIN2_GOLDBULLION);

	/*
	������ש
	*/
	sellItem(WULIN2_GOLDBRICK);

	/*
	���������
	*/
	sellItem(WULIN2_GOLDINGOT);
#endif

}

