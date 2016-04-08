#include "Warehouse.h"

Warehouse::Warehouse(GtrApiWrap* wrap)
:WithDrawMethod(wrap, WithDrawMethod::WD_WAREHOUSE)
{
}

Warehouse::~Warehouse(void)
{
}

bool Warehouse::withdraw(gtr::GameTaskletT& tasklet, INT64 baggold)
{
	int returnvalue;

	/*
	打开仓库
	*/
	returnvalue = _wrap->OpenWarehouse((char*)tasklet.post.sellerSecondPwd.c_str()); 

	/*
	用空的仓库密码重新尝试一次
	*/
	if ( returnvalue != GT_OK )
	{
		returnvalue = _wrap->OpenWarehouse(""); 

		appLogger().Message("第一次打开仓库失败，使用空密码再尝试打开1次");
	}

	if ( returnvalue == GT_OK )
	{
		appLogger().Message("打开仓库成功");
		/*
		查询仓库内金币
		*/
		INT64 warehousegold = 0;
		returnvalue = _wrap->QueryItemsInWarehouse(_gold,&warehousegold); 
		if ( returnvalue == GT_OK )
		{
			appLogger().Message("查询仓库金币成功");
			/*
			判断金币数量
			*/
			INT64 withdrawgold = tasklet.post.buyerMoney - baggold;
			if( warehousegold <= withdrawgold )
			{
				returnvalue = _wrap->WithdrawItemsInWarehouse(_gold,&warehousegold); 
			}
			else
			{
				returnvalue = _wrap->WithdrawItemsInWarehouse(_gold,&withdrawgold); 
			}

			if(returnvalue != GT_OK)
			{

			}
		}
	}
	else
	{
		appLogger().Message("卖家提供的2级密码错误");
	}

	return true;
}

