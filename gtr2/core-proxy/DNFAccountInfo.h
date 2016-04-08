#pragma once

#include "AccountInfo.h"

struct DNFItem
{
	string					m_name;						//物品
	int						m_num;						//叠加数目
	list<string>			m_toolTipInfos;				//物品ToolTip
};

class DNFAccountInfo : public AccountInfo
{
public:
	DNFAccountInfo()

	{
		m_packetGold = 0;
		m_ReliveMoney = 0;
		m_mailGold = 0;
	}
	~DNFAccountInfo()
	{

	}
	string					m_roleName;					//角色名字
	map<string,string>		m_CharacterAttributes;		//<属性名,属性值>
	map<string,int>			m_Skills;					//<技能名,技能等级>
	list<DNFItem>			m_Equipments;				//穿在身上的装备
	list<DNFItem>			m_PackItems;				//背包物品
	list<DNFItem>			m_WarehoseItems;			//仓库物品
	unsigned int			m_ReliveMoney;				//复活金币
	unsigned int			m_packetGold;				//背包金币
	unsigned int			m_mailGold;					//邮箱金币

	void createCharacterAttributes();
	void createSkillInfos();
	void createItemInfos();
	void createItemData(DNFItem& item);

	void saveitem( wxString type, wxString name, int count );

	virtual void parse(void *lpData ,int nSize);
	virtual void save();
};

inline RDataStream &operator>>( RDataStream &stream, DNFItem &val ){
	stream >> val.m_name >> val.m_num >> val.m_toolTipInfos;
	return stream;
}

inline RDataStream &operator>>( RDataStream &stream, DNFAccountInfo &val ){
	stream >> val.m_roleName >> val.m_CharacterAttributes >> val.m_Skills
		>> val.m_Equipments >> val.m_PackItems >> val.m_WarehoseItems
		>> val.m_ReliveMoney >> val.m_packetGold >> val.m_mailGold;
	return stream;
}