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
	�򿪲ֿ�
	*/
	returnvalue = _wrap->OpenWarehouse((char*)tasklet.post.sellerSecondPwd.c_str()); 

	/*
	�ÿյĲֿ��������³���һ��
	*/
	if ( returnvalue != GT_OK )
	{
		returnvalue = _wrap->OpenWarehouse(""); 

		appLogger().Message("��һ�δ򿪲ֿ�ʧ�ܣ�ʹ�ÿ������ٳ��Դ�1��");
	}

	if ( returnvalue == GT_OK )
	{
		appLogger().Message("�򿪲ֿ�ɹ�");
		/*
		��ѯ�ֿ��ڽ��
		*/
		INT64 warehousegold = 0;
		returnvalue = _wrap->QueryItemsInWarehouse(_gold,&warehousegold); 
		if ( returnvalue == GT_OK )
		{
			appLogger().Message("��ѯ�ֿ��ҳɹ�");
			/*
			�жϽ������
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
		appLogger().Message("�����ṩ��2���������");
	}

	return true;
}

