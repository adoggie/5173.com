#include "mac.h"

#include <Nb30.h>
#pragma comment (lib,"netapi32.lib")

typedef struct tagMAC_ADDRESS
{
	BYTE b1,b2,b3,b4,b5,b6;
}MAC_ADDRESS,*LPMAC_ADDRESS;

typedef struct tagASTAT
{
	ADAPTER_STATUS adapt;
	NAME_BUFFER    NameBuff [30];
}ASTAT,*LPASTAT;


UCHAR __GetAddressByIndex(int lana_num, ASTAT &Adapter)
{
	NCB ncb;
	UCHAR uRetCode;
	memset(&ncb, 0, sizeof(ncb) );
	ncb.ncb_command = NCBRESET;
	ncb.ncb_lana_num = lana_num;
	//指定网卡号,首先对选定的网卡发送一个NCBRESET命令,以便进行初始化
	uRetCode = Netbios(&ncb );
	memset(&ncb, 0, sizeof(ncb) );
	ncb.ncb_command = NCBASTAT;
	ncb.ncb_lana_num = lana_num;   //指定网卡号
	strcpy((char *)ncb.ncb_callname,"*      " );
	ncb.ncb_buffer = (unsigned char *)&Adapter;
	//指定返回的信息存放的变量
	ncb.ncb_length = sizeof(Adapter);
	//接着,可以发送NCBASTAT命令以获取网卡的信息
	uRetCode = Netbios(&ncb );
	return uRetCode;
}

int __GetMAC(LPMAC_ADDRESS pMacAddr)
{
	NCB ncb;
	UCHAR uRetCode;
	int num = 0;
	LANA_ENUM lana_enum;
	memset(&ncb, 0, sizeof(ncb) );
	ncb.ncb_command = NCBENUM;
	ncb.ncb_buffer = (unsigned char *)&lana_enum;
	ncb.ncb_length = sizeof(lana_enum);
	////向网卡发送NCBENUM命令,以获取当前机器的网卡信息,如有多少个网卡
	////每张网卡的编号等
	uRetCode = Netbios(&ncb);
	if (uRetCode == 0)
	{
		num = lana_enum.length;
		//对每一张网卡,以其网卡编号为输入编号,获取其MAC地址
		for (int i = 0; i < num; i++)
		{
			ASTAT Adapter;
			if(__GetAddressByIndex(lana_enum.lana[i],Adapter) == 0)
			{
				pMacAddr[i].b1 = Adapter.adapt.adapter_address[0];
				pMacAddr[i].b2 = Adapter.adapt.adapter_address[1];
				pMacAddr[i].b3 = Adapter.adapt.adapter_address[2];
				pMacAddr[i].b4 = Adapter.adapt.adapter_address[3];
				pMacAddr[i].b5 = Adapter.adapt.adapter_address[4];
				pMacAddr[i].b6 = Adapter.adapt.adapter_address[5];
			}
		}
	}
	return num;
}

std::string swlib::getMacByIndex(int index){
	std::string mac;

	MAC_ADDRESS m_MacAddr[10];        // 比如最多10个网卡
	int n = __GetMAC(m_MacAddr);        // 获得网卡数量

	char szAddr[128];
	sprintf(szAddr,"%02x:%02x:%02x:%02x:%02x:%02x",
		m_MacAddr[0].b1,m_MacAddr[0].b2,
		m_MacAddr[0].b3,m_MacAddr[0].b4,
		m_MacAddr[0].b5,m_MacAddr[0].b6);
	_strupr(szAddr);
	mac = szAddr;
	return mac;
}