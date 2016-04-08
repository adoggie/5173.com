#include "DNFAccountInfo.h"
#include <time.h>

extern std::string ws2s(wstring& inputws);
extern std::wstring s2ws(const string& s);

void DNFAccountInfo::saveitem( wxString type, wxString name, int count )
{
	m_markup.AddElem(_T("Item"));
	m_markup.AddAttrib(_T("type"), wstring(type).c_str());
	m_markup.AddAttrib(_T("name"), wstring(name).c_str());
	m_markup.AddAttrib(_T("count"), count);
}

void DNFAccountInfo::createItemData( DNFItem& item )
{
	wstring itemtype = reg.GetItemType(item.m_toolTipInfos);
	vector<RegItemData> itemdata;
	saveitem( itemtype, s2ws(item.m_name), item.m_num );
	m_markup.IntoElem();

	if ( IsSpecialType(itemtype) == false)
	{
		reg.GetItemAttr(item.m_toolTipInfos,itemdata);
		vector<RegItemData>::iterator it = itemdata.begin();
		while ( it!= itemdata.end() )
		{
			m_markup.AddElem(_T("Property"),it->ItemAttrValue);
			m_markup.AddAttrib(_T("name"), it->ItemPropertyName);
			it++;
		}
	}

	m_markup.OutOfElem();
}

void DNFAccountInfo::parse(void *lpData ,int nSize)
{
	RDataStream rds((const char*) lpData, nSize);
	DNFAccountInfo &info = *this;
	rds >> info;
}

void DNFAccountInfo::save()
{
	time_t t;
	time(&t);
	struct tm *ptm = localtime(&t);

	char buffer[128] = {0};
	sprintf(buffer,"AccountInfo-%04d-%02d-%02d(%02d-%02d-%02d).xml", ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
	wstring name = s2ws(string(buffer));

	m_markup.SetDoc(_T("<?xml version=\"1.0\" encoding=\"GB2312\"?>\r\n"));
	m_markup.AddElem(_T("AccountVerifyContents"));
	m_markup.IntoElem();
	m_markup.AddElem(_T("Rolers"));
	m_markup.IntoElem();
	m_markup.AddElem(_T("Role"));
	m_markup.AddAttrib(_T("name"), s2ws(m_roleName).c_str());
	m_markup.IntoElem();
	m_markup.AddElem(_T("CharacterAttributes"));
	m_markup.IntoElem();
	createCharacterAttributes();
	m_markup.OutOfElem();

	m_markup.AddElem(_T("Skills"));
	m_markup.IntoElem();
	createSkillInfos();
	m_markup.OutOfElem();

	m_markup.AddElem(_T("AllItems"));
	m_markup.IntoElem();
	createItemInfos();
	m_markup.OutOfElem();
	m_markup.OutOfElem();
	m_markup.OutOfElem();
	m_markup.OutOfElem();
	m_markup.Save(name);
}

void DNFAccountInfo::createCharacterAttributes()
{
	map<string,string>::iterator it = m_CharacterAttributes.begin();
	while(it != m_CharacterAttributes.end())
	{
		m_markup.AddElem(_T("Attribute"),s2ws(it->second).c_str());
		m_markup.AddAttrib(_T("name"), s2ws(it->first).c_str());
		it++;
	}
}
void DNFAccountInfo::createSkillInfos()
{
	map<string,int>::iterator it = m_Skills.begin();
	while(it != m_Skills.end())
	{
		m_markup.AddElem(_T("Skill"));
		m_markup.AddAttrib(_T("name"), s2ws(it->first).c_str());
		m_markup.AddAttrib(_T("level"), it->second);
		it++;
	}
}
void DNFAccountInfo::createItemInfos()
{
	/*
	背包物品
	*/
	m_markup.AddElem(_T("PlaceItems"));
	m_markup.AddAttrib(_T("name"), _T("背包"));
	m_markup.IntoElem();
	saveitem( wxT("金币"), wxT("游戏币"), m_packetGold );
	saveitem( wxT("金币"), wxT("复活币"), m_ReliveMoney );
	list<DNFItem>::iterator it = m_PackItems.begin();
	while(it != m_PackItems.end())
	{
		createItemData(*it);
		it++;
	}
	m_markup.OutOfElem();
	/*
	身上物品
	*/
	m_markup.AddElem(_T("PlaceItems"));
	m_markup.AddAttrib(_T("name"), _T("装备栏"));
	m_markup.IntoElem();
	list<DNFItem>::iterator it2 = m_Equipments.begin();
	while(it2 != m_Equipments.end())
	{
		createItemData(*it2);
		it2++;
	}
	m_markup.OutOfElem();
	/*
	仓库物品
	*/
	m_markup.AddElem(_T("PlaceItems"));
	m_markup.AddAttrib(_T("name"), _T("仓库"));
	m_markup.IntoElem();
	list<DNFItem>::iterator it3 = m_WarehoseItems.begin();
	while(it3 != m_WarehoseItems.end())
	{
		createItemData(*it3);
		it3++;
	}
	m_markup.OutOfElem();
	/*
	邮箱物品
	*/
	m_markup.AddElem(_T("PlaceItems"));
	m_markup.AddAttrib(_T("name"), _T("邮箱"));
	m_markup.IntoElem();
	saveitem( wxT("金币"), wxT("游戏币"), m_mailGold );
	m_markup.OutOfElem();
}