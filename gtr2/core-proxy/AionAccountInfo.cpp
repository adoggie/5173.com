#include "AionAccountInfo.h"
#include <time.h>

extern std::string ws2s(wstring& inputws);
extern std::wstring s2ws(const string& s);

void AionAccountInfo::parse(void *lpData ,int nSize)
{
	RDataStream rds((const char*) lpData, nSize);
	AionAccountInfo &info = *this;
	rds >> info;
}

void AionAccountInfo::save()
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

void AionAccountInfo::createCharacterAttributes()
{
	m_markup.AddElem(_T("Attribute"),s2ws(m_ranks).c_str());
	m_markup.AddAttrib(_T("name"), _T("军衔等级"));
	map<string,string>::iterator it = m_CharacterAttributes.begin();
	while(it != m_CharacterAttributes.end())
	{
		m_markup.AddElem(_T("Attribute"),s2ws(it->second).c_str());
		m_markup.AddAttrib(_T("name"), s2ws(it->first).c_str());
		it++;
	}
}
void AionAccountInfo::createSkillInfos()
{
	vector<AionSkillData>::iterator it = m_Skills.begin();
	while(it != m_Skills.end())
	{
		m_markup.AddElem(_T("Skill"));
		m_markup.AddAttrib(_T("name"), s2ws((*it).m_SkillName).c_str());
		m_markup.AddAttrib(_T("level"), (*it).m_Skillful);
		it++;
	}
}
void AionAccountInfo::createItemInfos()
{
	/*
	背包物品
	*/
	m_markup.AddElem(_T("PlaceItems"));
	m_markup.AddAttrib(_T("name"), _T("背包"));
	m_markup.IntoElem();
	saveitem( wxT("金币"), wxT("游戏币"), s2ws(m_Gold) );
	vector<AionItem>::iterator it = m_PackItems.begin();
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
	vector<AionItem>::iterator it2 = m_Equipments.begin();
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
	vector<AionItem>::iterator it3 = m_WarehoseItems.begin();
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
	vector<AionItem>::iterator it4 = m_MailBoxItems.begin();
	while(it4 != m_MailBoxItems.end())
	{
		createItemData(*it4);
		it4++;
	}
	m_markup.OutOfElem();
}

void AionAccountInfo::saveitem( wxString type, wxString name, int count )
{
	m_markup.AddElem(_T("Item"));
	m_markup.AddAttrib(_T("type"), wstring(type).c_str());
	m_markup.AddAttrib(_T("name"), wstring(name).c_str());
	m_markup.AddAttrib(_T("count"), count);
}

void AionAccountInfo::saveitem( wxString type, wxString name, wxString count )
{
	m_markup.AddElem(_T("Item"));
	m_markup.AddAttrib(_T("type"), wstring(type).c_str());
	m_markup.AddAttrib(_T("name"), wstring(name).c_str());
	m_markup.AddAttrib(_T("count"), wstring(count).c_str());
}

void AionAccountInfo::createItemData( AionItem& item )
{
	wstring itemtype = reg.GetItemType(item.m_ItemTip);
	vector<RegItemData> itemdata;
	saveitem( itemtype, s2ws(item.m_name), item.m_num );
	m_markup.IntoElem();

	if ( IsSpecialType(itemtype) == false)
	{
		reg.GetItemAttr(item.m_ItemTip,itemdata);
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