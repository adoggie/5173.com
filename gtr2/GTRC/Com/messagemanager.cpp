#include "messagemanager.h"

#define MAX_TOSTRING_SIZE 2048

void parsestring(unsigned int stringsize, string& s, char* buffer)
{
	char* common = new char[stringsize+1];
	memset(common,0,stringsize+1);
	memcpy(common,(char*)buffer,stringsize);
	s = string(common);
	delete[] common;
}

//VerifyInfo
GtMessageType VerifyInfo::getType()
{
	return _type;
}

bool VerifyInfo::parse(GtByte* data,GtUInt32 size)
{
	if (data == NULL||size==0)
	{
		return false;
	}
	unsigned int len = 0;
	char* pTempBuffer = (char*)data;

	unsigned int packetsize = *((unsigned int*)pTempBuffer);	pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	if (packetsize!=size)
	{
		return false;
	}

	char type = *((char*)pTempBuffer);							pTempBuffer += sizeof(char);				len += sizeof(char);
	_type = (GtMessageType)type;

	unsigned int stringsize = *((unsigned int*)pTempBuffer);	pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,NO,(char*)pTempBuffer);				pTempBuffer += stringsize;					len += stringsize;

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,Account,(char*)pTempBuffer);			pTempBuffer += stringsize;					len += stringsize;

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,Password,(char*)pTempBuffer);		pTempBuffer += stringsize;					len += stringsize;

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,Area,(char*)pTempBuffer);			pTempBuffer += stringsize;					len += stringsize;

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,Server,(char*)pTempBuffer);			pTempBuffer += stringsize;					len += stringsize;

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,SellerActor,(char*)pTempBuffer);		pTempBuffer += stringsize;					len += stringsize;

	Level = *((int*)pTempBuffer);								pTempBuffer += sizeof(int);					len += sizeof(int);

	Money = *((UINT64*)pTempBuffer);							pTempBuffer += sizeof(UINT64);				len += sizeof(UINT64);

	Verifytime = *((int*)pTempBuffer);							pTempBuffer += sizeof(int);					len += sizeof(int);

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,SellerSecondPwd,(char*)pTempBuffer);	pTempBuffer += stringsize;					len += stringsize;

	SellerIndex = *((int*)pTempBuffer);							pTempBuffer += sizeof(int);					len += sizeof(int);

	SellerGroup = *((int*)pTempBuffer);							pTempBuffer += sizeof(int);					len += sizeof(int);

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,BankPwd,(char*)pTempBuffer);			pTempBuffer += stringsize;					len += stringsize;

	GameId = *((int*)pTempBuffer);								pTempBuffer += sizeof(int);					len += sizeof(int);
	return true;
}

string VerifyInfo::toString()
{
	char buffer[MAX_TOSTRING_SIZE];
	memset(buffer,0,MAX_TOSTRING_SIZE);
	sprintf(buffer,
		"��֤����NO:%s\n�����˺�Account:%s\n��������Pwd:%s\n���Ҵ���area:%s\n����С��:%s\n���ҽ�ɫ:%s\n��ɫ�ȼ�:%d\n���׽��:%lld\n��֤ʱ��:%d\n����2������:%s\n���ҽ�ɫ���:%d\n������Ӫ:%d\n����Ǯׯ����:%s\n��ǰ��ϷID:%d\n",
		NO.c_str(),
		Account.c_str(),
		Password.c_str(),
		Area.c_str(),
		Server.c_str(),
		SellerActor.c_str(),
		Level,
		Money,
		Verifytime,
		SellerSecondPwd.c_str(),
		SellerIndex,
		SellerGroup,
		BankPwd.c_str(),
		GameId
		);

	string str = string(buffer);
	return str;
}

//TransactionInfo

GtMessageType TransactionInfo::getType()
{
	return _type;
}

bool TransactionInfo::parse(GtByte* data,GtUInt32 size)
{
	if (data == NULL||size==0)
	{
		return false;
	}
	unsigned int len = 0;
	char* pTempBuffer = (char*)data;

	unsigned int packetsize = *((unsigned int*)pTempBuffer);	pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	if (packetsize!=size)
	{
		return false;
	}

	char type = *((char*)pTempBuffer);							pTempBuffer += sizeof(char);				len += sizeof(char);
	_type = (GtMessageType)type;

	unsigned int stringsize = *((unsigned int*)pTempBuffer);	pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,NO,(char*)pTempBuffer);				pTempBuffer += stringsize;					len += stringsize;

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,Account,(char*)pTempBuffer);			pTempBuffer += stringsize;					len += stringsize;

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,Password,(char*)pTempBuffer);		pTempBuffer += stringsize;					len += stringsize;

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,Area,(char*)pTempBuffer);			pTempBuffer += stringsize;					len += stringsize;

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,Server,(char*)pTempBuffer);			pTempBuffer += stringsize;					len += stringsize;

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,SellerActor,(char*)pTempBuffer);		pTempBuffer += stringsize;					len += stringsize;

	SellerLevel = *((int*)pTempBuffer);							pTempBuffer += sizeof(int);					len += sizeof(int);

	Money = *((UINT64*)pTempBuffer);							pTempBuffer += sizeof(UINT64);				len += sizeof(UINT64);

	TransactionTime = *((int*)pTempBuffer);						pTempBuffer += sizeof(int);					len += sizeof(int);

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,SellerSecondPwd,(char*)pTempBuffer);	pTempBuffer += stringsize;					len += stringsize;

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,BuyerActor,(char*)pTempBuffer);		pTempBuffer += stringsize;					len += stringsize;

	BuyerLevel = *((int*)pTempBuffer);							pTempBuffer += sizeof(int);					len += sizeof(int);

	BuyerMoney = *((UINT64*)pTempBuffer);						pTempBuffer += sizeof(UINT64);				len += sizeof(UINT64);

	SellerIndex = *((int*)pTempBuffer);							pTempBuffer += sizeof(int);					len += sizeof(int);

	SellerGroup = *((int*)pTempBuffer);							pTempBuffer += sizeof(int);					len += sizeof(int);

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,BankPwd,(char*)pTempBuffer);			pTempBuffer += stringsize;					len += stringsize;

	GameId = *((int*)pTempBuffer);								pTempBuffer += sizeof(int);					len += sizeof(int);
	return true;
}

string TransactionInfo::toString()
{
	char buffer[MAX_TOSTRING_SIZE];
	memset(buffer,0,MAX_TOSTRING_SIZE);
	sprintf(buffer,
		"���׵���:%s\n�����˺�:%s\n��������:%s\n���Ҵ���:%s\n����С��:%s\n���ҽ�ɫ:%s\n���ҵȼ�:%d\n���׽��:%lld\n����ʱ��:%d\n����2������:%s\n��ҽ�ɫ:%s\n��ҵȼ�:%d\n��ҽ��׽��:%lld\n���ҽ�ɫ���:%d\n������Ӫ:%d\n����Ǯׯ����:%s\n��ǰ��ϷID:%d\n",
		NO.c_str(),
		Account.c_str(),
		Password.c_str(),
		Area.c_str(),
		Server.c_str(),
		SellerActor.c_str(),
		SellerLevel,
		Money,
		TransactionTime,
		SellerSecondPwd.c_str(),
		BuyerActor.c_str(),
		BuyerLevel,
		BuyerMoney,
		SellerIndex,
		SellerGroup,
		BankPwd.c_str(),
		GameId
		);

	string str = string(buffer);
	return str;
}

GtMessageType AccountVerifyInfo::getType()
{
	return _type;
}

bool AccountVerifyInfo::parse(GtByte* data,GtUInt32 size)
{
	if (data == NULL||size==0)
	{
		return false;
	}
	unsigned int len = 0;
	char* pTempBuffer = (char*)data;

	unsigned int packetsize = *((unsigned int*)pTempBuffer);	pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	if (packetsize!=size)
	{
		return false;
	}

	char type = *((char*)pTempBuffer);							pTempBuffer += sizeof(char);				len += sizeof(char);
	_type = (GtMessageType)type;

	unsigned int stringsize = *((unsigned int*)pTempBuffer);	pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,NO,(char*)pTempBuffer);				pTempBuffer += stringsize;					len += stringsize;

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,Account,(char*)pTempBuffer);			pTempBuffer += stringsize;					len += stringsize;

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,Password,(char*)pTempBuffer);		pTempBuffer += stringsize;					len += stringsize;

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,Area,(char*)pTempBuffer);			pTempBuffer += stringsize;					len += stringsize;

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,Server,(char*)pTempBuffer);			pTempBuffer += stringsize;					len += stringsize;

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,SellerActor,(char*)pTempBuffer);		pTempBuffer += stringsize;					len += stringsize;

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,SellerSecondPwd,(char*)pTempBuffer);	pTempBuffer += stringsize;					len += stringsize;

	SellerIndex = *((int*)pTempBuffer);							pTempBuffer += sizeof(int);					len += sizeof(int);

	SellerGroup = *((int*)pTempBuffer);							pTempBuffer += sizeof(int);					len += sizeof(int);

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,BankPwd,(char*)pTempBuffer);			pTempBuffer += stringsize;					len += stringsize;

	GameId = *((int*)pTempBuffer);								pTempBuffer += sizeof(int);					len += sizeof(int);

	return true;
}

string AccountVerifyInfo::toString()
{
	char buffer[MAX_TOSTRING_SIZE];
	memset(buffer,0,MAX_TOSTRING_SIZE);

	sprintf(buffer,
		"���׵���:%s\n�����˺�:%s\n��������:%s\n���Ҵ���:%s\n����С��:%s\n���ҽ�ɫ:%s\n����2������:%s\n��������:%d\n������Ӫ:%d\nǮׯ����:%s\n",
		NO.c_str(),
		Account.c_str(),
		Password.c_str(),
		Area.c_str(),
		Server.c_str(),
		SellerActor.c_str(),
		SellerSecondPwd.c_str(),
		SellerIndex,
		SellerGroup,
		BankPwd.c_str()
		);

	string str = string(buffer);
	return str;
}

//YZMContent
GtMessageType YZMContent::getType()
{
	return _type;
}

bool YZMContent::parse(GtByte* data,GtUInt32 size)
{
	if (data == NULL||size==0)
	{
		return false;
	}
	unsigned int len = 0;
	char* pTempBuffer = (char*)data;

	unsigned int packetsize = *((unsigned int*)pTempBuffer);	pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	if (packetsize!=size)
	{
		return false;
	}

	char type = *((char*)pTempBuffer);							pTempBuffer += sizeof(char);				len += sizeof(char);
	_type = (GtMessageType)type;

	unsigned int stringsize = *((unsigned int*)pTempBuffer);	pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,NO,(char*)pTempBuffer);				pTempBuffer += stringsize;					len += stringsize;

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,content,(char*)pTempBuffer);			pTempBuffer += stringsize;					len += stringsize;

	return true;
}

string YZMContent::toString()
{
	char buffer[MAX_TOSTRING_SIZE];
	memset(buffer,0,MAX_TOSTRING_SIZE);
	sprintf(buffer,
		"��֤���׵���:%s\n����Ϊ:%s\n",
		NO.c_str(),
		content.c_str());
	string str = string(buffer);
	return str;
}

//MBKContent
GtMessageType MBKContent::getType()
{
	return _type;
}

bool MBKContent::parse(GtByte* data,GtUInt32 size)
{
	if (data == NULL||size==0)
	{
		return false;
	}
	unsigned int len = 0;
	char* pTempBuffer = (char*)data;

	unsigned int packetsize = *((unsigned int*)pTempBuffer);	pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	if (packetsize!=size)
	{
		return false;
	}

	char type = *((char*)pTempBuffer);							pTempBuffer += sizeof(char);				len += sizeof(char);
	_type = (GtMessageType)type;

	unsigned int stringsize = *((unsigned int*)pTempBuffer);	pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,NO,(char*)pTempBuffer);				pTempBuffer += stringsize;					len += stringsize;

	stringsize = *((unsigned int*)pTempBuffer);					pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,content,(char*)pTempBuffer);			pTempBuffer += stringsize;					len += stringsize;

	return true;
}

string MBKContent::toString()
{
	char buffer[MAX_TOSTRING_SIZE];
	memset(buffer,0,MAX_TOSTRING_SIZE);
	sprintf(buffer,
		"��֤���׵���:%s\n����Ϊ:%s\n",
		NO.c_str(),
		content.c_str());
	string str = string(buffer);
	return str;
}

//DecryptionKey
GtMessageType DecryptionKey::getType()
{
	return _type;
}
bool DecryptionKey::parse(GtByte* data,GtUInt32 size)
{
	if (data == NULL||size==0)
	{
		return false;
	}
	unsigned int len = 0;
	char* pTempBuffer = (char*)data;

	unsigned int packetsize = *((unsigned int*)pTempBuffer);	pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	if (packetsize!=size)
	{
		return false;
	}

	char type = *((char*)pTempBuffer);							pTempBuffer += sizeof(char);				len += sizeof(char);
	_type = (GtMessageType)type;

	unsigned int stringsize = *((unsigned int*)pTempBuffer);	pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	parsestring(stringsize,key,(char*)pTempBuffer);				pTempBuffer += stringsize;					len += stringsize;

	return true;
}

string DecryptionKey::toString()
{
	char buffer[MAX_TOSTRING_SIZE];
	memset(buffer,0,MAX_TOSTRING_SIZE);
	sprintf(buffer,
		"����Կ:%s\n",
		key.c_str());
	string str = string(buffer);
	return str;
}

//RobotStatus
GtMessageType RobotStatus::getType()
{
	return _type;
}
GtUInt32 RobotStatus::getSize()
{
	GtUInt32 length = 5;
	length += sizeof(char);//eRebotStatus
	length += sizeof(bool);
	length += sizeof(char);
	return length;
}
GtStreamBytes RobotStatus::encBytes()
{
	GtByte* buffer = new GtByte[getSize()];
	memset(buffer,0,getSize());
	GtByte* pTempBuffer = (GtByte*)buffer;
	*((unsigned int*)pTempBuffer) = getSize();				pTempBuffer += sizeof(unsigned int);

	*((char*)pTempBuffer) = (char)getType();				pTempBuffer += sizeof(char);

	*((char*)pTempBuffer) = (char)m_statusVal;				pTempBuffer += sizeof(char);

	*((bool*)pTempBuffer) = telecom;						pTempBuffer += sizeof(bool);

	*((char*)pTempBuffer) = gameversion;					pTempBuffer += sizeof(char);

	GtStreamBytes gtstr;
	gtstr.insert(gtstr.end(),buffer,buffer+getSize());
	delete[] buffer;
	return gtstr;
}

string RobotStatus::toString()
{
	char buffer[MAX_TOSTRING_SIZE];
	memset(buffer,0,MAX_TOSTRING_SIZE);
	sprintf(buffer,
		"������״̬:%d\n����״��:%d\n��Ϸ�汾:%d\n",
		m_statusVal,
		(int)telecom,
		(int)gameversion);
	string str = string(buffer);
	return str;
}

//VerifyResult
GtMessageType VerifyResult::getType()
{
	return _type;
}
GtUInt32 VerifyResult::getSize()
{
	GtUInt32 length = 5;
	length += (GtUInt32)(NO.size()+4);
	length += sizeof(int);
	return length;
}
GtStreamBytes VerifyResult::encBytes()
{
	GtByte* buffer = new GtByte[getSize()];
	GtByte* pTempBuffer = (GtByte*)buffer;
	*((unsigned int*)pTempBuffer) = getSize();						pTempBuffer += sizeof(unsigned int);

	*((char*)pTempBuffer) = (char)getType();						pTempBuffer += sizeof(char);

	*((unsigned int*)pTempBuffer) = (unsigned int)NO.size();		pTempBuffer += sizeof(unsigned int);
	memcpy(pTempBuffer,NO.c_str(),NO.size());						pTempBuffer += NO.size();

	*((int*)pTempBuffer) = (int)m_verifyResult;					pTempBuffer += sizeof(int);

	GtStreamBytes gtstr;
	gtstr.insert(gtstr.end(),buffer,buffer+getSize());
	delete[] buffer;
	return gtstr;
}

string VerifyResult::toString()
{
	char buffer[MAX_TOSTRING_SIZE];
	memset(buffer,0,MAX_TOSTRING_SIZE);
	sprintf(buffer,
		"��֤����:%s\n��֤���:%d\n",
		NO.c_str(),
		m_verifyResult);
	string str = string(buffer);
	return str;
}

//TransactResult
GtMessageType TransactResult::getType()
{
	return _type;
}
GtUInt32 TransactResult::getSize()
{
	GtUInt32 length = 5;
	length += (GtUInt32)(NO.size()+4);
	length += sizeof(int);
	return length;
}
GtStreamBytes TransactResult::encBytes()
{
	GtByte* buffer = new GtByte[getSize()];
	GtByte* pTempBuffer = (GtByte*)buffer;
	*((unsigned int*)pTempBuffer) = getSize();						pTempBuffer += sizeof(unsigned int);

	*((char*)pTempBuffer) = (char)getType();						pTempBuffer += sizeof(char);

	*((unsigned int*)pTempBuffer) = (unsigned int)NO.size();		pTempBuffer += sizeof(unsigned int);
	memcpy(pTempBuffer,NO.c_str(),NO.size());						pTempBuffer += NO.size();

	*((int*)pTempBuffer) = (int)m_transactResult;					pTempBuffer += sizeof(int);

	GtStreamBytes gtstr;
	gtstr.insert(gtstr.end(),buffer,buffer+getSize());
	delete[] buffer;
	return gtstr;
}

string TransactResult::toString()
{
	char buffer[MAX_TOSTRING_SIZE];
	memset(buffer,0,MAX_TOSTRING_SIZE);
	sprintf(buffer,
		"���׵���:%s\n���׽��:%d\n",
		NO.c_str(),
		m_transactResult);
	string str = string(buffer);
	return str;
}
//YZMImage
GtMessageType YZMImage::getType()
{
	return _type;
}
GtUInt32 YZMImage::getSize()
{
	GtUInt32 length = 5;
	length += (GtUInt32)(NO.size()+4);
	length += (GtUInt32)(YZMPix.size()+4);
	return length;
}
GtStreamBytes YZMImage::encBytes()
{
	GtByte* buffer = new GtByte[getSize()];
	GtByte* pTempBuffer = (GtByte*)buffer;

	*((unsigned int*)pTempBuffer) = getSize();						pTempBuffer += sizeof(unsigned int);

	*((char*)pTempBuffer) = (char)getType();						pTempBuffer += sizeof(char);

	*((unsigned int*)pTempBuffer) = (unsigned int)NO.size();		pTempBuffer += sizeof(unsigned int);
	memcpy(pTempBuffer,NO.c_str(),NO.size());						pTempBuffer += NO.size();

	*((unsigned int*)pTempBuffer) = (unsigned int)YZMPix.size();	pTempBuffer += sizeof(unsigned int);
	for (int i = 0; i < (int)YZMPix.size(); ++i)
	{
		*((GtByte*)pTempBuffer) = YZMPix[i];
		pTempBuffer += 1;
	}

	GtStreamBytes gtstr;
	gtstr.insert(gtstr.end(),buffer,buffer+getSize());
	delete[] buffer;
	return gtstr;
}

string YZMImage::toString()
{
	char buffer[MAX_TOSTRING_SIZE];
	memset(buffer,0,MAX_TOSTRING_SIZE);
	sprintf(buffer,
		"��֤���׵���:%s\n",
		NO.c_str());
	string str = string(buffer);
	return str;
}

//MBKImage
GtMessageType MBKImage::getType()
{
	return _type;
}
GtUInt32 MBKImage::getSize()
{
	GtUInt32 length = 5;
	length += (GtUInt32)(NO.size()+4);
	length += (GtUInt32)(MBKPix.size()+4);
	return length;
}

GtStreamBytes MBKImage::encBytes()
{
	GtByte* buffer = new GtByte[getSize()];
	GtByte* pTempBuffer = (GtByte*)buffer;

	*((unsigned int*)pTempBuffer) = getSize();						pTempBuffer += sizeof(unsigned int);

	*((char*)pTempBuffer) = (char)getType();						pTempBuffer += sizeof(char);

	*((unsigned int*)pTempBuffer) = (unsigned int)NO.size();		pTempBuffer += sizeof(unsigned int);
	memcpy(pTempBuffer,NO.c_str(),NO.size());						pTempBuffer += NO.size();

	*((unsigned int*)pTempBuffer) = (unsigned int)MBKPix.size();	pTempBuffer += sizeof(unsigned int);
	for (int i = 0; i < (int)MBKPix.size(); ++i)
	{
		*((GtByte*)pTempBuffer) = MBKPix[i];
		pTempBuffer += 1;
	}

	GtStreamBytes gtstr;
	gtstr.insert(gtstr.end(),buffer,buffer+getSize());
	delete[] buffer;
	return gtstr;
}

string MBKImage::toString()
{
	char buffer[MAX_TOSTRING_SIZE];
	memset(buffer,0,MAX_TOSTRING_SIZE);
	sprintf(buffer,
		"��֤���׵���:%s\n",
		NO.c_str());
	string str = string(buffer);
	return str;
}

//RobotHeart

GtMessageType RobotHeart::getType()
{
	return _type;
}

GtUInt32 RobotHeart::getSize()
{
	GtUInt32 length = 5;
	return length;
}

GtStreamBytes RobotHeart::encBytes()
{
	GtByte* buffer = new GtByte[getSize()];
	GtByte* pTempBuffer = (GtByte*)buffer;

	*((unsigned int*)pTempBuffer) = getSize();						pTempBuffer += sizeof(unsigned int);

	*((char*)pTempBuffer) = (char)getType();						pTempBuffer += sizeof(char);

	GtStreamBytes gtstr;
	gtstr.insert(gtstr.end(),buffer,buffer+getSize());
	delete[] buffer;
	return gtstr;
}

bool RobotHeart::parse(GtByte* data,GtUInt32 size)
{
	if (data == NULL||size==0)
	{
		return false;
	}
	unsigned int len = 0;
	char* pTempBuffer = (char*)data;

	unsigned int packetsize = *((unsigned int*)pTempBuffer);	pTempBuffer += sizeof(unsigned int);		len += sizeof(unsigned int);
	if (packetsize!=size)
	{
		return false;
	}

	char type = *((char*)pTempBuffer);							pTempBuffer += sizeof(char);				len += sizeof(char);
	_type = (GtMessageType)type;

	return true;
}

//RobotGameId

GtMessageType RobotGameId::getType()
{
	return _type;
}

GtUInt32 RobotGameId::getSize()
{
	GtUInt32 length = 5;
	length += (GtUInt32)(gameidstream.size()+4);
	length += (GtUInt32)(gamename.size()+4);
	return length;
}

GtStreamBytes RobotGameId::encBytes()
{
	GtByte* buffer = new GtByte[getSize()];
	GtByte* pTempBuffer = (GtByte*)buffer;

	*((unsigned int*)pTempBuffer) = getSize();							pTempBuffer += sizeof(unsigned int);

	*((char*)pTempBuffer) = (char)getType();							pTempBuffer += sizeof(char);

	*((unsigned int*)pTempBuffer) = (unsigned int)gameidstream.size();	pTempBuffer += sizeof(unsigned int);
	memcpy(pTempBuffer,gameidstream.c_str(),gameidstream.size());		pTempBuffer += gameidstream.size();

	*((unsigned int*)pTempBuffer) = (unsigned int)gamename.size();		pTempBuffer += sizeof(unsigned int);
	memcpy(pTempBuffer,gamename.c_str(),gamename.size());				pTempBuffer += gamename.size();

	GtStreamBytes gtstr;
	gtstr.insert(gtstr.end(),buffer,buffer+getSize());
	delete[] buffer;
	return gtstr;
}

string RobotGameId::toString()
{
	char buffer[MAX_TOSTRING_SIZE];
	memset(buffer,0,MAX_TOSTRING_SIZE);
	sprintf(buffer,
		"��ϷId:%s\n��Ϸ����:%s\n",
		gameidstream.c_str(),
		gamename.c_str()
		);
	string str = string(buffer);
	return str;
}

//AnswerResult
GtMessageType AnswerResult::getType()
{
	return _type;
}

GtUInt32 AnswerResult::getSize()
{
	GtUInt32 length = 5;
	length += (GtUInt32)(NO.size()+4);
	length += sizeof(char);
	length += (GtUInt32)(UserName.size()+4);
	return length;
}

GtStreamBytes AnswerResult::encBytes()
{
	GtByte* buffer = new GtByte[getSize()];
	GtByte* pTempBuffer = (GtByte*)buffer;

	*((unsigned int*)pTempBuffer) = getSize();							pTempBuffer += sizeof(unsigned int);

	*((char*)pTempBuffer) = (char)getType();							pTempBuffer += sizeof(char);

	*((unsigned int*)pTempBuffer) = (unsigned int)NO.size();			pTempBuffer += sizeof(unsigned int);
	memcpy(pTempBuffer,NO.c_str(),NO.size());							pTempBuffer += NO.size();

	*((char*)pTempBuffer) = (char)Result;								pTempBuffer += sizeof(char);

	*((unsigned int*)pTempBuffer) = (unsigned int)UserName.size();		pTempBuffer += sizeof(unsigned int);
	memcpy(pTempBuffer,UserName.c_str(),UserName.size());				pTempBuffer += UserName.size();

	GtStreamBytes gtstr;
	gtstr.insert(gtstr.end(),buffer,buffer+getSize());
	delete[] buffer;
	return gtstr;
}

string AnswerResult::toString()
{
	char buffer[MAX_TOSTRING_SIZE];
	memset(buffer,0,MAX_TOSTRING_SIZE);
	sprintf(buffer,
		"��ϷId:%d\n��Ϸ����:%s\n",
		NO.c_str(),
		(int)Result,
		UserName.c_str()
		);
	string str = string(buffer);
	return str;
}

GtMessageType AccountVerifyResult::getType()
{
	return _type;
}
GtStreamBytes AccountVerifyResult::encBytes()
{
	GtByte* buffer = new GtByte[getSize()];
	GtByte* pTempBuffer = (GtByte*)buffer;

	*((unsigned int*)pTempBuffer) = getSize();							pTempBuffer += sizeof(unsigned int);

	*((char*)pTempBuffer) = (char)getType();							pTempBuffer += sizeof(char);

	*((unsigned int*)pTempBuffer) = (unsigned int)NO.size();			pTempBuffer += sizeof(unsigned int);
	memcpy(pTempBuffer,NO.c_str(),NO.size());							pTempBuffer += NO.size();

	*((int*)pTempBuffer) = (int)Result;									pTempBuffer += sizeof(int);

	*((unsigned int*)pTempBuffer) = (unsigned int)AccountInfo.size();	pTempBuffer += sizeof(unsigned int);
	memcpy(pTempBuffer,AccountInfo.c_str(),AccountInfo.size());			pTempBuffer += AccountInfo.size();

	GtStreamBytes gtstr;
	gtstr.insert(gtstr.end(),buffer,buffer+getSize());
	delete[] buffer;
	return gtstr;
}
GtUInt32 AccountVerifyResult::getSize()
{
	GtUInt32 length = 5;
	length += (GtUInt32)(NO.size()+4);
	length += sizeof(int);
	length += (GtUInt32)(AccountInfo.size()+4);
	return length;
}