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
	//ָ��������,���ȶ�ѡ������������һ��NCBRESET����,�Ա���г�ʼ��
	uRetCode = Netbios(&ncb );
	memset(&ncb, 0, sizeof(ncb) );
	ncb.ncb_command = NCBASTAT;
	ncb.ncb_lana_num = lana_num;   //ָ��������
	strcpy((char *)ncb.ncb_callname,"*      " );
	ncb.ncb_buffer = (unsigned char *)&Adapter;
	//ָ�����ص���Ϣ��ŵı���
	ncb.ncb_length = sizeof(Adapter);
	//����,���Է���NCBASTAT�����Ի�ȡ��������Ϣ
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
	////����������NCBENUM����,�Ի�ȡ��ǰ������������Ϣ,���ж��ٸ�����
	////ÿ�������ı�ŵ�
	uRetCode = Netbios(&ncb);
	if (uRetCode == 0)
	{
		num = lana_enum.length;
		//��ÿһ������,�����������Ϊ������,��ȡ��MAC��ַ
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

	MAC_ADDRESS m_MacAddr[10];        // �������10������
	int n = __GetMAC(m_MacAddr);        // �����������

	char szAddr[128];
	sprintf(szAddr,"%02x:%02x:%02x:%02x:%02x:%02x",
		m_MacAddr[0].b1,m_MacAddr[0].b2,
		m_MacAddr[0].b3,m_MacAddr[0].b4,
		m_MacAddr[0].b5,m_MacAddr[0].b6);
	_strupr(szAddr);
	mac = szAddr;
	return mac;
}