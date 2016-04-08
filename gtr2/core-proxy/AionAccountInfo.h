#pragma once

#include "AccountInfo.h"

struct AionSkillData
{
	string			m_SkillName;						//��������
	int				m_Skillful;							//������
};

struct AionItem
{
	string					m_name;						//��Ʒ
	int						m_num;						//������Ŀ
	string					m_ItemTip;					//��Ʒ��Tip;
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
	string					m_roleName;					//��ɫ��
	string					m_ranks;					//���εȼ�
	map<string,string>		m_CharacterAttributes;		//<������,����ֵ>
	vector<AionSkillData>	m_Skills;					//����
	vector<AionItem>		m_WarehoseItems;			//�ֿ���Ʒ
	vector<AionItem>		m_Equipments;				//������Ʒ
	vector<AionItem>		m_PackItems;				//������Ʒ
	vector<AionItem>		m_MailBoxItems;				//������Ʒ
	string					m_Gold;						//���

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