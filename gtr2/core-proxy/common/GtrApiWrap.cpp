#include "GtrApiWrap.h"
#include "markup.h"
#include "general.h"

#define InitGtrParam(a) ParamInit(#a)
#define ValidateParam(a) set_param(#a);
#define BeginCore(a) begin_core(#a)
#define EndCore(a) if( end_core(#a) ) break


//Converting a WChar string to a Ansi string
std::string WChar2Ansi(LPCWSTR pwszSrc)
{
	int nLen = WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, NULL, 0, NULL, NULL);
	if (nLen<= 0) return std::string("");
	char* pszDst = new char[nLen];
	if (NULL == pszDst) return std::string("");
	WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, pszDst, nLen, NULL, NULL);
	pszDst[nLen -1] = 0;
	std::string strTemp(pszDst);
	delete [] pszDst;
	return strTemp;
}
string ws2s(wstring& inputws){ return WChar2Ansi(inputws.c_str()); }
//Converting a Ansi string to WChar string
std::wstring Ansi2WChar(LPCSTR pszSrc, int nLen)
{
	if (nLen == 0)
	{
		return std::wstring();
	}
	int nSize = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)pszSrc, nLen, 0, 0);
	if(nSize <= 0) return std::wstring();
	WCHAR *pwszDst = new WCHAR[nSize+1];
	if( NULL == pwszDst) return std::wstring();
	MultiByteToWideChar(CP_ACP, 0,(LPCSTR)pszSrc, nLen, pwszDst, nSize);
	pwszDst[nSize] = 0;
	if( pwszDst[0] == 0xFEFF) // skip Oxfeff
		for(int i = 0; i < nSize; i ++) 
			pwszDst[i] = pwszDst[i+1]; 
	wstring wcharString(pwszDst);
	delete pwszDst;
	return wcharString;
}
std::wstring s2ws(const string& s){ return Ansi2WChar(s.c_str(),s.size());}

GtrApiWrap::GtrApiWrap()
:_dbglogger(false)
{
	LOG_ADD_REGFILE_WRITER(_dbglogger,getDebugLogfile().c_str());
	LOG_ADD_UDP_WRITER(_dbglogger,"127.0.0.1",10010)	;

	_total_timeout = 180;

}

GtrApiWrap::~GtrApiWrap(void)
{
}

void GtrApiWrap::Initialize(CALLCTX* ctx)
{
	_tmStart = time(NULL);
	_ctx = ctx;
	_sleep = -1;
	_tries = 1;

	InitGtrParam(GetRoleList)              ;
	InitGtrParam(SelectServer)             ;
	InitGtrParam(SelectArea)               ;
	InitGtrParam(SelectLineByName)         ;
	InitGtrParam(SelectLineByIndex)        ;
	InitGtrParam(Login)                    ;
	InitGtrParam(IsExistDynMB)             ;
	InitGtrParam(IsRightClass)             ;
	InitGtrParam(IsExistBackHomeSkill)     ;
	InitGtrParam(UseBackHomeSkill)         ;
	InitGtrParam(IsExistBackHomeItem)      ;
	InitGtrParam(UseBackHomeItem)          ;
	InitGtrParam(QueryRoleLevel)           ;
	InitGtrParam(SelectRoleByName)         ;
	InitGtrParam(SelectRoleByIndex)        ;
	InitGtrParam(IsExistRoleByName)        ;
	InitGtrParam(AddRoleToFriend)          ;
	InitGtrParam(QuerySafeTime)            ;
	InitGtrParam(IsExistNPC)               ;
	InitGtrParam(OpenWarehouse)            ;
	InitGtrParam(OpenMailBox)              ;
	InitGtrParam(OpenBank)                 ;
	InitGtrParam(OpenExchange)             ;
	InitGtrParam(OpenGrocer)               ;
	InitGtrParam(MoveToByNpcID)            ;
	InitGtrParam(Talk)                     ;
	InitGtrParam(QueryItemsInBag)          ;
	InitGtrParam(QueryItemsInWarehouse)    ;
	InitGtrParam(QueryItemsInBank)         ;
	InitGtrParam(QueryItemsInExchange)     ;
	InitGtrParam(IsEnoughItemsInMailbox)   ;
	InitGtrParam(WithdrawItemsInWarehouse) ;
	InitGtrParam(WithdrawItemsInBank)      ;
	InitGtrParam(WithdrawItemsInExchange)  ;
	InitGtrParam(WithdrawItemsInMailbox)   ;
	InitGtrParam(SendMail)                 ;
	InitGtrParam(SellItem)                 ;
	InitGtrParam(Transport)                ;
	InitGtrParam(IsUnlocked)               ;
	InitGtrParam(IsInMap)                  ;
	InitGtrParam(ReturnToSelectRole)       ;
	InitGtrParam(MoveTo)                   ;
	InitGtrParam(IsNearBy)                 ;
	InitGtrParam(GetAccountInfo)           ;
	InitGtrParam(Begin)                    ;
	InitGtrParam(End)                      ;

	CMarkup markup;
	markup.Load(_T("robot.xcfg"));
	markup.ResetChildPos();
	while( markup.FindChildElem(_T("CoreFunc")) )
	{
		wstring name = markup.GetChildAttrib(_T("name"));
		wstring timeout = markup.GetChildAttrib(_T("timeout"));
		wstring tries = markup.GetChildAttrib(_T("tries"));
		wstring sleep = markup.GetChildAttrib(_T("sleep"));
		wstring skip = markup.GetChildAttrib(_T("skip"));

		GtrMethod *param = _settings[ws2s(name)];
		if(param)
		{
			param->timeout = atoi(ws2s(timeout).c_str());
			param->tries = atoi(ws2s(tries).c_str());
			param->sleep = atoi(ws2s(sleep).c_str());
		}
	}
	markup.ResetChildPos();
	if(markup.FindChildElem(_T("Global")))
	{
		wstring total_timeout = markup.GetChildAttrib(_T("timeout"));
		if(total_timeout != _T(""))
		{
			_total_timeout = atoi(ws2s(total_timeout).c_str());
			if(_total_timeout<=0)
			{
				_total_timeout = 180;
			}

		}
	}
}

string GtrApiWrap::getDebugLogfile()
{
	time_t t;
	time(&t);
	struct tm *ptm = localtime(&t);
	char buffer[128] = {0};
	sprintf(buffer,"%s%d-%d-%d.log","debug",ptm->tm_year+1900,ptm->tm_mon+1,ptm->tm_mday);
	//printf("%s",buffer);
	return std::string(buffer);
}

void GtrApiWrap::ParamInit(string name)
{
	GtrMethod *param = new GtrMethod;
	param->timeout = 12000;
	param->tries = 1;
	param->sleep = -1;
	_settings.insert(make_pair(name, param));

}

void GtrApiWrap::addChecker(GtrChecker* checker)
{
	_checkers.push_back(checker);
}

void GtrApiWrap::set_param(string name)
{
	GtrMethod *param = _settings[name];
	if(param==NULL)
	{
		ParamInit(name);
		param = _settings[name];
	}

	_ctx->timeout = param->timeout;
	_tries = param->tries;
	_sleep = param->sleep;
	_lastReturn = GT_OK;
}

void GtrApiWrap::begin_core(string name)
{
	isTimeout();
	vector<GtrChecker*>::iterator it = _checkers.begin();
	while(it!=_checkers.end())
	{
		(*it)->Do();
		it++;
	}
	
	_dbglogger.Debug("Enter[%s]", name.c_str());
}

bool GtrApiWrap::end_core(string name)
{
	if(_lastReturn == GT_OK || _lastReturn == GT_TRUE)
	{
		_dbglogger.Debug("Leave[%s][TRUE]", name.c_str());
		if(_sleep>0)
		{
			Sleep(_sleep);
		}
		return true;
	}
	else
	{
		_dbglogger.Debug("Leave[%s][FALSE], Error Code [%d]", name.c_str(), _lastReturn);
		if(_sleep>0)
		{
			Sleep(_sleep);
		}
		return false;

	}
}

bool GtrApiWrap::isTimeout()
{
	time_t tmNow = time(NULL);
	double diff = difftime(tmNow, _tmStart);
	if(diff > _total_timeout)
	{
		char buf[255];
		sprintf(buf,"机器人运行超时(超时设置%d秒)",  _total_timeout);
		extern void _debug_loop();
		//_debug_loop();

		throw(robot_error(GT_ERR_3120, buf));
		return true;
	}
	return false;
}

GT_RESULT GtrApiWrap::GetRoleList(vector<string>& roles)
{

	string strTemp;
	int bufsize = 1024;
	int rolenum = 0;
	strTemp.resize(1024);
	char* szbuf = (char*) strTemp.c_str();
	memset(szbuf, 0, 1024);

	ValidateParam(GetRoleList);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(GetRoleList);
		_lastReturn = _ctx->apilist->GetRoleList(szbuf,bufsize,&rolenum,_ctx);
		//strTemp = WChar2Ansi((TCHAR*)szbuf);
		EndCore(GetRoleList);
	}

#if 1
	//extern void _debug_loop();
	//_debug_loop();

	_dbglogger.Message("Role Num : %d", rolenum);

	string SPLIT = "\r\n";

	string ::size_type pos;
	while((pos = strTemp.find(SPLIT)) != string::npos)
	{
		string strRole = strTemp.substr(0, pos);
		strRole = strRole.c_str();
		if(!strRole.empty())
		{
			_dbglogger.Message("Role Name : %s", strRole.c_str());
			roles.push_back(strRole);
		}
		strTemp = strTemp.substr(pos + 2);
	}
	strTemp = strTemp.c_str();
	if(!strTemp.empty())
	{
		_dbglogger.Message("Role Name : %s", strTemp.c_str());
		roles.push_back(strTemp);
	}

	//assert(roles.size()==rolenum);
#else

	for(int i=0; i<6; i++)
	{
		string strRole = &szbuf[i*32];
		if(strRole!="")
		{
			roles.push_back(strRole);
			_dbglogger.Message("Role Name : %s", strRole.c_str());

		}
	}
#endif

	return _lastReturn;

}

//选大区	订单中大区信息	OK	无法连接					SelectServer		char*
GT_RESULT GtrApiWrap::SelectServer(string server)
{
	_dbglogger.Message("Server[%s]", server.c_str());
	ValidateParam(SelectServer);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(SelectServer);
		_lastReturn = _ctx->apilist->SelectServer((char*)server.c_str(), _ctx);
		EndCore(SelectServer);
	}
	return _lastReturn;
}

//选小区	订单中小区信息	OK	无法连接					SelectArea		char*
GT_RESULT GtrApiWrap::SelectArea(string area)
{
	_dbglogger.Message("Area[%s]", area.c_str());
	ValidateParam(SelectArea);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(SelectArea);
		_lastReturn = _ctx->apilist->SelectArea((char*)area.c_str(), _ctx);
		EndCore(SelectArea);
	}
	return _lastReturn;
}

//选线路	Ping值较低	OK	无法连接					SelectLine		void (null 自动选择线路)
GT_RESULT GtrApiWrap::SelectLineByName(string line)	
{
	ValidateParam(SelectLineByName);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(SelectLineByName);
		_lastReturn = _ctx->apilist->SelectLineByName((char*)line.c_str(), _ctx);
		EndCore(SelectLineByName);
	}
	return _lastReturn;
}

//选线路	Ping值较低	OK	无法连接					SelectLine		void// -1 自动选择线路
GT_RESULT GtrApiWrap::SelectLineByIndex(int line)
{
	ValidateParam(SelectLineByIndex);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(SelectLineByIndex);
		_lastReturn = _ctx->apilist->SelectLineByIndex(line, _ctx);
		EndCore(SelectLineByIndex);
	}
	return _lastReturn;
}

//账号密码输入	订单中账号密码信息	OK	账号密码错误	玩家在线		版本错误		Login		char* account, char* pwd
GT_RESULT GtrApiWrap::Login(string usr,string passwd)	
{
	_dbglogger.Message("login[%s, %s]", usr.c_str(), passwd.c_str());

	ValidateParam(Login);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(Login);
		_lastReturn = _ctx->apilist->Login((char*)usr.c_str(), (char*)passwd.c_str(), _ctx);
		EndCore(Login);
	}
	return _lastReturn;
}

//查询动态密保		有	无					IsExistDynMB		void	
GT_RESULT GtrApiWrap::IsExistDynMB()									
{
	ValidateParam(IsExistDynMB);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(IsExistDynMB);
		_lastReturn = _ctx->apilist->IsExistDynMB(_ctx);
		EndCore(IsExistDynMB);
	}
	return _lastReturn;
}

//查询角色阵营	订单中卖家阵营	是	否					IsRightClass		int	
GT_RESULT GtrApiWrap::IsRightClass(int cls )							
{
	ValidateParam(IsRightClass);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(IsRightClass);
		_lastReturn = _ctx->apilist->IsRightClass(cls, _ctx);
		EndCore(IsRightClass);
	}
	return _lastReturn;
}

// 		查询回城技能		是	否					IsExistBackHomeSkill		void
GT_RESULT GtrApiWrap::IsExistBackHomeSkill()					
{
	ValidateParam(IsExistBackHomeSkill);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(IsExistBackHomeSkill);
		_lastReturn = _ctx->apilist->IsExistBackHomeSkill(_ctx);
		EndCore(IsExistBackHomeSkill);
	}
	return _lastReturn;
}

// 		使用回城技能		OK	失败					UseBackHomeSkill		void
GT_RESULT GtrApiWrap::UseBackHomeSkill()							
{
	ValidateParam(UseBackHomeSkill);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(UseBackHomeSkill);
		_lastReturn = _ctx->apilist->UseBackHomeSkill(_ctx);
		EndCore(UseBackHomeSkill);
	}
	return _lastReturn;
}

// 		查询是否存在回城物品		是	否	
GT_RESULT GtrApiWrap::IsExistBackHomeItem()									
{
	ValidateParam(IsExistBackHomeItem);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(IsExistBackHomeItem);
		_lastReturn = _ctx->apilist->IsExistBackHomeItem(_ctx);
		EndCore(IsExistBackHomeItem);
	}
	return _lastReturn;
}

// 		使用回城物品		OK	失败	
GT_RESULT GtrApiWrap::UseBackHomeItem()												
{
	ValidateParam(UseBackHomeItem);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(UseBackHomeItem);
		_lastReturn = _ctx->apilist->UseBackHomeItem(_ctx);
		EndCore(UseBackHomeItem);
	}
	return _lastReturn;
}

// 		查询卖家角色等级		OK	失败					QuerySellerLevel		char*, int*
GT_RESULT GtrApiWrap::QueryRoleLevel(string role ,POUT int *level) 
{
	ValidateParam(QueryRoleLevel);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(QueryRoleLevel);
		_lastReturn = _ctx->apilist->QueryRoleLevel((char*)role.c_str(), level, _ctx);
		EndCore(QueryRoleLevel);
	}
	return _lastReturn;
}

// 		角色选择	订单中的角色名信息	OK	角色名不存在	角色需要修改名字（DNF合服）				SelectRoleByName		char*
GT_RESULT GtrApiWrap::SelectRoleByName(string role)				
{
	ValidateParam(SelectRoleByName);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(SelectRoleByName);
		_lastReturn = _ctx->apilist->SelectRoleByName((char*)role.c_str(), _ctx);
		EndCore(SelectRoleByName);
	}
	return _lastReturn;
}

// 		序号选择	订单中的角色序号信息	OK	无法登陆该序号角色					SelectRoleByIndex		int
GT_RESULT GtrApiWrap::SelectRoleByIndex(int role)					
{
	ValidateParam(SelectRoleByIndex);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(SelectRoleByIndex);
		_lastReturn = _ctx->apilist->SelectRoleByIndex(role, _ctx);
		EndCore(SelectRoleByIndex);
	}
	return _lastReturn;
}

// 		查询买家角色名	订单中买家角色名信息	有	无					IsExistBuyerByName		char*
GT_RESULT GtrApiWrap::IsExistRoleByName(string role )			
{
	ValidateParam(IsExistRoleByName);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(IsExistRoleByName);
		_lastReturn = _ctx->apilist->IsExistRoleByName((char*)role.c_str(), _ctx);
		EndCore(IsExistRoleByName);
	}
	return _lastReturn;
}

// 		加买家为好友	订单中买家角色名信息	OK	无该玩家					AddBuyerToFriend		char*		
GT_RESULT GtrApiWrap::AddRoleToFriend(string role)				
{
	ValidateParam(AddRoleToFriend);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(AddRoleToFriend);
		_lastReturn = _ctx->apilist->AddRoleToFriend((char*)role.c_str(), _ctx);
		EndCore(AddRoleToFriend);
	}
	return _lastReturn;
}

// 		获取安全时间			安全时间					QuerySafeTime		int*		
GT_RESULT GtrApiWrap::QuerySafeTime(POUT int* safetime)						
{
	ValidateParam(QuerySafeTime);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(QuerySafeTime);
		_lastReturn = _ctx->apilist->QuerySafeTime(safetime, _ctx);
		EndCore(QuerySafeTime);
	}
	return _lastReturn;
}

// 		判定指定NPC是否在附近	NPCID	是	否					IsExistNPC		int	
GT_RESULT GtrApiWrap::IsExistNPC(Gt_NPCID npc)								
{
	ValidateParam(IsExistNPC);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(IsExistNPC);
		_lastReturn = _ctx->apilist->IsExistNPC(npc, _ctx);
		EndCore(IsExistNPC);
	}
	return _lastReturn;
}

// 		打开仓库	订单中的仓库密码信息	OK	密码错误					OpenWarehouse		char*
GT_RESULT GtrApiWrap::OpenWarehouse(string passwd)						
{
	ValidateParam(OpenWarehouse);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(OpenWarehouse);
		_lastReturn = _ctx->apilist->OpenWarehouse((char*)passwd.c_str(), _ctx);
		EndCore(OpenWarehouse);
	}
	return _lastReturn;
}

//邮箱  二级密码
GT_RESULT GtrApiWrap::OpenMailBox(string passwd)						
{
	ValidateParam(OpenMailBox);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(OpenMailBox);
		_lastReturn = _ctx->apilist->OpenMailBox((char*)passwd.c_str(), _ctx);
		EndCore(OpenMailBox);
	}
	return _lastReturn;
}

//银行 二级密码
GT_RESULT GtrApiWrap::OpenBank(string passwd)							
{
	ValidateParam(OpenBank);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(OpenBank);
		_lastReturn = _ctx->apilist->OpenBank((char*)passwd.c_str(), _ctx);
		EndCore(OpenBank);
	}
	return _lastReturn;
}

//交易所 二级密码	
GT_RESULT GtrApiWrap::OpenExchange(string passwd) 					
{
	ValidateParam(OpenExchange);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(OpenExchange);
		_lastReturn = _ctx->apilist->OpenExchange((char*)passwd.c_str(), _ctx);
		EndCore(OpenExchange);
	}
	return _lastReturn;
}

//杂货商 二级密码
GT_RESULT GtrApiWrap::OpenGrocer(string passwd) 					
{
	ValidateParam(OpenGrocer);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(OpenGrocer);
		_lastReturn = _ctx->apilist->OpenGrocer((char*)passwd.c_str(), _ctx);
		EndCore(OpenGrocer);
	}
	return _lastReturn;
}

// 		跑地图	NPCID	OK	无法到达					MoveToByNpcID		int NPCID
GT_RESULT GtrApiWrap::MoveToByNpcID(Gt_NPCID npc)							
{
	ValidateParam(MoveToByNpcID);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(MoveToByNpcID);
		_lastReturn = _ctx->apilist->MoveToByNpcID(npc, _ctx);
		EndCore(MoveToByNpcID);
	}
	return _lastReturn;
}

// 		与邮箱NPC对话	NPCID	OK	无法对话					Talk		int NPCID
GT_RESULT GtrApiWrap::Talk(Gt_NPCID npc)											
{
	ValidateParam(Talk);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(Talk);
		_lastReturn = _ctx->apilist->Talk(npc, _ctx);
		EndCore(Talk);
	}
	return _lastReturn;
}

//查询背包物品数量 ,  item - 具体的游戏可交易的对象(金币、元宝、金砖。。。)
GT_RESULT GtrApiWrap::QueryItemsInBag(Gt_GameItemT item,POUT INT64* num)				
{
	ValidateParam(QueryItemsInBag);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(QueryItemsInBag);
		_lastReturn = _ctx->apilist->QueryItemsInBag(item,num, _ctx);
		EndCore(QueryItemsInBag);
	}
	return _lastReturn;
}

//仓库
GT_RESULT GtrApiWrap::QueryItemsInWarehouse(Gt_GameItemT item,POUT INT64* num)	
{
	ValidateParam(QueryItemsInWarehouse);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(QueryItemsInWarehouse);
		_lastReturn = _ctx->apilist->QueryItemsInWarehouse(item,num, _ctx);
		EndCore(QueryItemsInWarehouse);
	}
	return _lastReturn;
}

// 银行
GT_RESULT GtrApiWrap::QueryItemsInBank(Gt_GameItemT item,POUT INT64* num)				
{
	ValidateParam(QueryItemsInBank);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(QueryItemsInBank);
		_lastReturn = _ctx->apilist->QueryItemsInBank(item,num, _ctx);
		EndCore(QueryItemsInBank);
	}
	return _lastReturn;
}

//交易所
GT_RESULT GtrApiWrap::QueryItemsInExchange(Gt_GameItemT item,POUT INT64* num)		
{
	ValidateParam(QueryItemsInExchange);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(QueryItemsInExchange);
		_lastReturn = _ctx->apilist->QueryItemsInExchange(item,num, _ctx);
		EndCore(QueryItemsInExchange);
	}
	return _lastReturn;
}

// 邮箱金币是否满足差额//邮件特例处理
GT_RESULT GtrApiWrap::IsEnoughItemsInMailbox(Gt_GameItemT item,PINOUT INT64* num)		
{
	ValidateParam(IsEnoughItemsInMailbox);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(IsEnoughItemsInMailbox);
		_lastReturn = _ctx->apilist->IsEnoughItemsInMailbox(item,num, _ctx);
		EndCore(IsEnoughItemsInMailbox);
	}
	return _lastReturn;
}

//获得指定物品数量 // 		获取仓库金币信息			返回仓库中金币数额	无法获取				QueryGoldsInWarehouse		int64*
GT_RESULT GtrApiWrap::WithdrawItemsInWarehouse(Gt_GameItemT item,PINOUT INT64* num)	
{
	ValidateParam(WithdrawItemsInWarehouse);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(WithdrawItemsInWarehouse);
		_lastReturn = _ctx->apilist->WithdrawItemsInWarehouse(item,num, _ctx);
		EndCore(WithdrawItemsInWarehouse);
	}
	return _lastReturn;
}

// 		获取仓库金币信息			返回仓库中金币数额	无法获取				QueryGoldsInWarehouse		int64*
GT_RESULT GtrApiWrap::WithdrawItemsInBank(Gt_GameItemT item,PINOUT INT64* num)				
{
	ValidateParam(WithdrawItemsInBank);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(WithdrawItemsInBank);
		_lastReturn = _ctx->apilist->WithdrawItemsInBank(item,num, _ctx);
		EndCore(WithdrawItemsInBank);
	}
	return _lastReturn;
}

// 		获取仓库金币信息			返回仓库中金币数额	无法获取				QueryGoldsInWarehouse		int64*
GT_RESULT GtrApiWrap::WithdrawItemsInExchange(Gt_GameItemT item,PINOUT INT64* num)		
{
	ValidateParam(WithdrawItemsInExchange);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(WithdrawItemsInExchange);
		_lastReturn = _ctx->apilist->WithdrawItemsInExchange(item,num, _ctx);
		EndCore(WithdrawItemsInExchange);
	}
	return _lastReturn;
}

// 		邮箱金币是否满足差额
GT_RESULT GtrApiWrap::WithdrawItemsInMailbox(Gt_GameItemT item,PINOUT  INT64* num)		
{
	ValidateParam(WithdrawItemsInMailbox);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(WithdrawItemsInMailbox);
		_lastReturn = _ctx->apilist->WithdrawItemsInMailbox(item,num, _ctx);
		EndCore(WithdrawItemsInMailbox);
	}
	return _lastReturn;
}

//发送邮件
GT_RESULT GtrApiWrap::SendMail(string reciever,string title,string content,INT64 amount)	
{
	ValidateParam(SendMail);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(SendMail);
		_lastReturn = _ctx->apilist->SendMail((char*)reciever.c_str(), (char*)title.c_str(),(char*)content.c_str(),amount,_ctx);
		EndCore(SendMail);
	}
	return _lastReturn;
}

//兑换给Npc
// 		兑换银票，金砖	金币数额		返回兑换后金币数额	无法获取				SellItem		int64
GT_RESULT GtrApiWrap::SellItem(int item,int itemNum)							
{
	ValidateParam(SellItem);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(SellItem);
		_lastReturn = _ctx->apilist->SellItem(item, itemNum, _ctx);
		EndCore(SellItem);
	}
	return _lastReturn;
}


//传送 返回GT_TRUE代表成功，GT_FALSE没有失败
GT_RESULT GtrApiWrap::Transport( int mapid  )
{
	ValidateParam(Transport);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(Transport);
		_lastReturn = _ctx->apilist->Transport(mapid, _ctx);
		EndCore(Transport);
	}
	return _lastReturn;
}

//查询解锁与否 返回GT_TRUE代表解锁，GT_FALSE没有解锁
GT_RESULT GtrApiWrap::IsUnlocked()
{
	ValidateParam(IsUnlocked);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(IsUnlocked);
		_lastReturn = _ctx->apilist->IsUnlocked(_ctx);
		EndCore(IsUnlocked);
	}
	return _lastReturn;
}

//查询玩家是否在某某地图 返回GT_TRUE代表是，GT_FALSE否
GT_RESULT GtrApiWrap::IsInMap( int mapid  )
{
	ValidateParam(IsInMap);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(IsInMap);
		_lastReturn = _ctx->apilist->IsInMap(mapid, _ctx);
		EndCore(IsInMap);
	}
	return _lastReturn;
}

//返回选择角色画面
GT_RESULT GtrApiWrap::ReturnToSelectRole(  )
{
	ValidateParam(ReturnToSelectRole);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(ReturnToSelectRole);
		_lastReturn = _ctx->apilist->ReturnToSelectRole(_ctx);
		EndCore(ReturnToSelectRole);
	}
	return _lastReturn;
}

//使用走路脚本专用(暂时诛仙2专用)
GT_RESULT GtrApiWrap::MoveTo(int type)
{
	ValidateParam(MoveTo);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(MoveTo);
		_lastReturn = _ctx->apilist->MoveTo(type, _ctx);
		EndCore(MoveTo);
	}
	return _lastReturn;
}

//判断NPC是否在玩家可点击对话范围之内
GT_RESULT GtrApiWrap::IsNearBy(Gt_NPCID npc)
{
	ValidateParam(IsNearBy);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(IsNearBy);
		_lastReturn = _ctx->apilist->IsNearBy(npc, _ctx);
		EndCore(IsNearBy);
	}
	return _lastReturn;
}

//获取角色信息 参数1：数据 参数2：长度
GT_RESULT GtrApiWrap::GetAccountInfo(char** buf,int* len)
{
	ValidateParam(GetAccountInfo);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(GetAccountInfo);
		_lastReturn = _ctx->apilist->GetAccountInfo(buf, len, _ctx);
		EndCore(GetAccountInfo);
	}
	return _lastReturn;
}

//开单
GT_RESULT GtrApiWrap::Begin()				
{
	ValidateParam(Begin);
	for(int i=0; i<_tries; i++)
	{
		BeginCore(Begin);
		_lastReturn = _ctx->apilist->Begin(_ctx);
		if(_lastReturn == GT_UNABLEMOVETO)
		{
			Sleep(3000);
		}
		EndCore(Begin);
	}
	return _lastReturn;
}

//结单
GT_RESULT GtrApiWrap::End()					
{
	ValidateParam(End);
	for(int i=0; i<_tries; i++)
	{
		_dbglogger.Debug("Enter[End]");
		_lastReturn = _ctx->apilist->End(_ctx);
		EndCore(End);
	}
	return _lastReturn;
}


GT_BOOL GtrApiWrap::Init(char * gamedir)
{
	return _ctx->apilist->Init(gamedir, _ctx);
}

void		GtrApiWrap::CleanUp( )
{
	_ctx->apilist->CleanUp(_ctx);
}

