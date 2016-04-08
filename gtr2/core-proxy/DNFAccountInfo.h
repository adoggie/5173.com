#pragma once

#include "AccountInfo.h"

struct DNFItem
{
	string					m_name;						//��Ʒ
	int						m_num;						//������Ŀ
	list<string>			m_toolTipInfos;				//��ƷToolTip
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
	string					m_roleName;					//��ɫ����
	map<string,string>		m_CharacterAttributes;		//<������,����ֵ>
	map<string,int>			m_Skills;					//<������,���ܵȼ�>
	list<DNFItem>			m_Equipments;				//�������ϵ�װ��
	list<DNFItem>			m_PackItems;				//������Ʒ
	list<DNFItem>			m_WarehoseItems;			//�ֿ���Ʒ
	unsigned int			m_ReliveMoney;				//������
	unsigned int			m_packetGold;				//�������
	unsigned int			m_mailGold;					//������

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