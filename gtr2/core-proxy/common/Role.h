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

	GT_RESULT IsExistBackHomeSkill();					// 		查询回城技能		是	否					IsExistBackHomeSkill		void
	GT_RESULT UseBackHomeSkill();							// 		使用回城技能		OK	失败					UseBackHomeSkill		void
	GT_RESULT IsExistBackHomeItem();					// 		查询是否存在回城物品		是	否					
	GT_RESULT UseBackHomeItem();							// 		使用回城物品		OK	失败		
	GT_RESULT QueryItemsInBag(Gt_GameItemT item,POUT INT64*);				//查询背包物品数量 ,  item - 具体的游戏可交易的对象(金币、元宝、金砖。。。)
	GT_RESULT Transport( int mapid);	//传送 返回GT_TRUE代表成功，GT_FALSE没有失败
};

