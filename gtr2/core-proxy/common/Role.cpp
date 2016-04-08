#include "Role.h"
#include "service.h"


#define XLOG getRobotApp().logmsg
//#define XLOG appLogger().Message

Role::Role(GtrApiWrap* wrap):_wrap(wrap)
{
	_baglast = 0;
	baggold = 0;
}

Role::~Role(void)
{
}

bool Role::checkBag(int tries)
{
	do
	{
		QueryBag();
		Sleep(1000);
		tries--;

	}while(tries && _baglast == baggold);

	return _baglast != baggold;
}

void Role::BackHome()
{
	int returnvalue;

	/*
	检测回城技能
	*/
	returnvalue = _wrap->IsExistBackHomeSkill();
	if ( returnvalue == GT_TRUE )
	{
		XLOG("玩家存在回城技能");
		/*
		使用回城技能
		*/
		returnvalue = _wrap->UseBackHomeSkill();
		if( returnvalue == GT_TRUE )
		{
			XLOG("玩家使用回城技能成功");
		}
		else
		{
			if(returnvalue == GT_FALSE)
			{
				XLOG("玩家使用回城技能失败");
				/*
				使用回城物品
				*/
				BackHomeAux();
			}
			else
			{
				throw(make_error( returnvalue));
			}
		}
	}
	else
	{
#if 0
		if(returnvalue == GT_FALSE)
		{
			XLOG("玩家不存在回城技能");
			/*
			使用回城物品
			*/
			BackHomeAux();
		}
		else
		{
			throw(make_error( returnvalue));
		}
#else
		XLOG("玩家不存在回城技能");
		throw(make_error( returnvalue));

#endif
	}
}

void Role::BackHomeAux()
{
	int returnvalue;
	/*
	检测回城道具
	*/
	returnvalue = _wrap->IsExistBackHomeItem();
	if ( returnvalue == GT_TRUE )
	{
		XLOG("角色存在回城物品");
		/*
		使用回城道具
		*/
		returnvalue = _wrap->UseBackHomeItem();
		if ( returnvalue == GT_TRUE )
		{
			XLOG("角色使用回城物品成功");
		}
		else if ( returnvalue == GT_FALSE )
		{
			XLOG("角色使用回城物品失败");
			throw(robot_error(GT_ERR_3120, "回城失败"));
		}
		else
		{
			throw(make_error( returnvalue));
		}
	}
	else
	{
		if ( returnvalue == GT_FALSE )
		{
			XLOG("角色不存在回城物品");
			throw(robot_error(GT_ERR_3120, "回城失败"));
		}
		else
		{
			throw(make_error( returnvalue));
		}
	}
}

void Role::Login(gtr::GameTaskletT& tasklet)
{
	int returnvalue;

	/*
	选大区流程
	*/
	returnvalue = _wrap->SelectArea(tasklet.area); 
	if ( returnvalue == GT_OK )
	{
		XLOG("连接大区成功");
	}
	else
	{
		if ( returnvalue == GT_UNABLECONNECT)
		{
			/*
			返回值大区无法连接,转人工
			*/
			throw(robot_error(GT_ERR_3000, "连接大区失败"));
		}
		else
		{

			throw(make_error(returnvalue));		
		}

	}

	/*
	选小区流程
	*/
	returnvalue = _wrap->SelectServer(tasklet.server);
	if ( returnvalue == GT_OK )
	{
		XLOG("连接小区成功");
	}
	else 
	{
		if ( returnvalue == GT_UNABLECONNECT)
		{
			/*
			返回值小区无法连接,转人工
			*/
			throw(robot_error(GT_ERR_3020,"连接小区失败"));
		}
		else if( returnvalue == GT_NOTEXISTED )
		{
			throw(robot_error(GT_ERR_3020, "小区不存在"));
		}
		else
		{
			throw(make_error(returnvalue));		
		}
	}

	/*
	账号登陆流程
	*/
	returnvalue = _wrap->Login(tasklet.account,tasklet.password);

	if ( returnvalue == GT_OK )
		XLOG("账号登陆成功");
	else
	{
		if ( returnvalue == GT_PASSWORDERROR)
		{
			/*
			卖家密码错误
			*/
			throw(robot_error(GT_ERR_2000,"卖家密码错误"));
		}
		else if ( returnvalue == GT_MBERROR)
		{
			/*
			卖家密保上传错误
			*/
			throw(robot_error(GT_ERR_2090,"卖家密保上传错误"));
		}
		else if ( returnvalue == GT_VERSIONERROR )
		{
			/*
			游戏版本错误
			*/
			throw(robot_error(GT_ERR_3120, "游戏版本错误"));
		}
		else if ( returnvalue == GT_PLAYERINLINE )
		{
			/*
			玩家在线
			*/
			throw(robot_error(GT_ERR_3120, "玩家在线"));
		}
		else if ( returnvalue == GT_FALSE)
		{
			throw(robot_error(GT_ERR_3120, "游戏服务器没开或者可能是密保输入多次错误账号被临时封停"));
		}
		else
		{
			throw(make_error(returnvalue));		
		}
	}

	/*
	选线流程
	*/
	returnvalue = _wrap->SelectLineByName("");
	//returnvalue = _wrap->SelectLineByName("12");
	//returnvalue = _wrap->SelectLineByIndex(12); 
	if ( returnvalue != GT_OK )
	{
		XLOG("选线失败");

		throw(make_error(returnvalue));		
	}
	XLOG("选择线路成功");

	/*
	１、无角色，直接取消订单（提示：无角色）；
	２、有一个角色，角色名匹配，直接走后续流程；
	３、有一个角色，角色名不匹配，金币足够发货；
	４、有一个角色，角色名不匹配，金币不足，直接取消订单（提示：角色名不匹配，且金币数不足）；
	５、多个角色名，有角色名匹配，直接走后续流程（ 注：角色名匹配后，不对该账号其他角色金币数进行判断）；
	６、多个角色名，无角色名匹配，直接转人工（提示：角色名不匹配）；
	*/
	_seller = tasklet.post.sellerActor;

#if 1
	vector<string> roles;
	returnvalue = _wrap->GetRoleList(roles);
	if( returnvalue == GT_OK )
	{
		XLOG("帐号角色数量为%d", roles.size());
		for(int i=0; i<roles.size(); i++)
		{
			XLOG("帐号角色%d: %s", i+1, roles[i].c_str());
		}

		if(roles.size()==0)
		{
			//无角色，直接取消订单（提示：无角色）
			throw(robot_error(GT_ERR_2010, "帐号内无角色"));
		}
		else if(roles.size()==1)
		{
			if(roles[0]==_seller)
			{
				//角色名匹配，直接走后续流程
			}
			else
			{
				//角色名不匹配，如金币足够则发货， 否则直接取消订单（提示：角色名不匹配，且金币数不足）
				//throw(robot_error(GT_ERR_2140, "角色名不匹配，且金币数不足"));
				XLOG("帐号内只有一个角色,但是角色名不匹配,选择唯一角色");
				_seller = roles[0];
			}
		}
		else
		{
			//extern void _debug_loop();
			//_debug_loop();
			vector<string>::iterator itbegin = roles.begin();
			vector<string>::iterator itend = roles.end();
			vector<string>::iterator itfind = itbegin;

			for(; itfind != itend; itfind++)
			{
				string pp = (*itfind);
				if(strcmp(pp.c_str(), _seller.c_str())==0)
					break;
			}


			//vector<string>::iterator itfind = std::find(roles.begin(), roles.end(), _seller);
			if(itfind != roles.end())
			{
				//有角色名匹配，直接走后续流程（ 注：角色名匹配后，不对该账号其他角色金币数进行判断）
			}
			else
			{
				//无角色名匹配，直接转人工
				throw(robot_error(GT_ERR_3130, "帐号内有多个角色,但是角色名不匹配"));
			}
		}
	}
	else
	{
		//无角色，直接取消订单（提示：无角色）
		throw(robot_error(GT_ERR_2010, "角色列表查询失败, 角色列表为空"));
	}
#endif

	/*
	选角色流程
	*/
	returnvalue = _wrap->SelectRoleByName(_seller); 
	if ( returnvalue == GT_OK )
	{
		XLOG("选择角色%s登陆成功",_seller.c_str());
	}
	else
	{
		// 判断角色列表是否为空， 空直接撤单， 名字不匹配转人工
		if ( returnvalue == GT_NOTEXISTED)
		{
			XLOG("登录角色%s失败",_seller.c_str());
			throw(robot_error(GT_ERR_2010, "选角色失败"));
		}
		else
		{
			throw(make_error(returnvalue));		
		}
	}
}

void Role::QueryLevel()
{
	int returnvalue;

	do 
	{
		returnvalue = _wrap->QueryRoleLevel(_seller, &_level);
		if(returnvalue == GT_TRUE )
		{
			XLOG("角色当前等级%d级", _level);
			Sleep(500);
		}
		else
		{
			Sleep(500);
			//throw(make_error(returnvalue));
		}
	} while (_level == 0);

}

void Role::QuerySafeTime(int max)
{
	int returnvalue;
	
	/*
	安全时间检测
	*/
	int safetime = 0;
	_wrap->QuerySafeTime(&safetime); 
	if ( safetime > max )
	{
		/*
		返回值安全时间大于2分钟,转人工
		*/
		char buf[255];
		sprintf(buf, "安全时间%d秒钟(大于%d秒钟)", safetime, max);
		throw(robot_error(GT_ERR_3030,buf));
	}

	XLOG("安全时间检测成功,安全时间%d秒钟", safetime);

}

void Role::QueryBag()
{
	static int queryid = 0;

	_baglast = baggold;

	queryid++;
	int returnvalue = _wrap->QueryItemsInBag((Gt_GameItemT)GT_ITEM_1,&baggold);
	if ( returnvalue != GT_OK )
	{
		XLOG("查询背包金币失败");
		baggold = _baglast;
		throw(make_error(returnvalue));

	}

	XLOG("第%d次查询背包金币为%d",queryid, (int)baggold);
}

bool Role::IsNearByNpc(int npc)
{
	int returnvalue = _wrap->IsNearBy(npc);
	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		throw(make_error( returnvalue));
	}

	return returnvalue==GT_TRUE ? true : false;
}