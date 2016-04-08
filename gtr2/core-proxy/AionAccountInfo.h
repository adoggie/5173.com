#pragma once

#include "AccountInfo.h"

struct AionSkillData
{
	string			m_SkillName;						//技能名字
	int				m_Skillful;							//熟练度
};

struct AionItem
{
	string					m_name;						//物品
	int						m_num;						//叠加数目
	string					m_ItemTip;					//物品的Tip;
};

class AionAccountInfo : public AccountInfo
{
public:
	AionAccountInfo()
	{
	}
	~AionAccountInfo()
	{
	}
	string					m_roleName;					//角色名
	string					m_ranks;					//军衔等级
	map<string,string>		m_CharacterAttributes;		//<属性名,属性值>
	vector<AionSkillData>	m_Skills;					//技能
	vector<AionItem>		m_WarehoseItems;			//仓库物品
	vector<AionItem>		m_Equipments;				//身上物品
	vector<AionItem>		m_PackItems;				//背包物品
	vector<AionItem>		m_MailBoxItems;				//邮箱物品
	string					m_Gold;						//金币

	virtual void parse(void *lpData ,int nSize);
	virtual void save();

	void createCharacterAttributes();
	void createSkillInfos();
	void createItemInfos();
	void createItemData(AionItem& item);

	void saveitem( wxString type, wxString name, int count );
	void saveitem( wxString type, wxString name, wxString count );
};


inline RDataStream &operator>>( RDataStream &stream, AionSkillData& val)
{
	stream >> val.m_SkillName >> val.m_Skillful;
	return stream;
}

inline RDataStream &operator>>( RDataStream &stream, AionItem& val)
{
	stream >> val.m_name >> val.m_num >> val.m_ItemTip;
	return stream;
}

inline RDataStream &operator>>( RDataStream &stream, AionAccountInfo &val ){
	stream >> val.m_roleName >> val.m_ranks >> val.m_CharacterAttributes
		>> val.m_Skills >> val.m_WarehoseItems >> val.m_Equipments
		>> val.m_PackItems >> val.m_MailBoxItems >> val.m_Gold;
	return stream;
}