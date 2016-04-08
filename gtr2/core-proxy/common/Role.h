#pragma once

#include "general.h"

class Role
{
	GtrApiWrap* _wrap;

public:
	INT64 baggold;
	INT64 _baglast;
	string _seller;
	int _level;

	Role(GtrApiWrap* wrap);   
	~Role();
	void BackHome();
	void Login(gtr::GameTaskletT& tasklet);
	void QueryBag();
	bool IsNearByNpc(int npc);
	void QuerySafeTime(int max);
	void QueryLevel();
	bool checkBag(int tries);

private:
	void BackHomeAux();

	GT_RESULT IsExistBackHomeSkill();					// 		��ѯ�سǼ���		��	��					IsExistBackHomeSkill		void
	GT_RESULT UseBackHomeSkill();							// 		ʹ�ûسǼ���		OK	ʧ��					UseBackHomeSkill		void
	GT_RESULT IsExistBackHomeItem();					// 		��ѯ�Ƿ���ڻس���Ʒ		��	��					
	GT_RESULT UseBackHomeItem();							// 		ʹ�ûس���Ʒ		OK	ʧ��		
	GT_RESULT QueryItemsInBag(Gt_GameItemT item,POUT INT64*);				//��ѯ������Ʒ���� ,  item - �������Ϸ�ɽ��׵Ķ���(��ҡ�Ԫ������ש������)
	GT_RESULT Transport( int mapid);	//���� ����GT_TRUE����ɹ���GT_FALSEû��ʧ��
};

