
#include "dnf_accountaudit.h"

IMPLEMENT_APP_CONSOLE(Dnf_AccountAudit)

const int selectserver_trytimes = 3;
const int selectarea_trytimes = 3;
const int login_trytimes = 1;
const int inputmb_trytimes = 3;
const int selectrole_trytimes = 3;

extern std::string ws2s(wstring& inputws);
extern std::wstring s2ws(const string& s);

#define XLOG logmsg

void FormatAreaName( string &area )
{
	static string a[] = { "一区", "二区", "三区", "四区", "五区", "六区", "七区", "八区", "九区", "十区", 
		"十一区", "十二区", "十三区", "十四区", "十五区", "十六区", "十七区", "十八区", "十九区", "二十区" };
	static string b[] = { "1区", "2区", "3区", "4区", "5区", "6区", "7区", "8区", "9区", "10区",
		"11区", "12区", "13区", "14区", "15区", "16区", "17区", "18区", "19区", "20区"};

	for ( int i = sizeof(a)/sizeof(a[0]) - 1; i>=0; --i )
	{
		//area.replace( a[i].c_str(), b[i].c_str() );
	}
}

//void FormatServName( string &serv )
//{
//	wxRegEx reg(wxT("\\d+"));
//	if (reg.Matches(s2ws(serv).c_str()))
//	{
//		wxString s = reg.GetMatch(s2ws(serv),1);
//		serv = s.mb_str();
//	}
//	//serv.remove( QRegExp("\\d+") );
//	//serv.replace( "州","东" );//没有广州区，只有广东区
//}


void Dnf_AccountAudit::task_AccountAudit(gtr::GameTaskResultT& result)
{
	XLOG("订单号为%s",(char*)_tasklet.no.c_str());
	XLOG("卖家姓名为%s",_tasklet.audit.sellerActor.c_str());
	XLOG("订单中大区信息为%s",_tasklet.area.c_str());
	XLOG("订单中小区信息为%s",_tasklet.server.c_str());
	XLOG("订单中账号信息为%s",_tasklet.account.c_str());
	_gamectx.timeout = 100000;
	/*
	预定义默认的返回结果
	*/
	result.result = GT_ERR_8050;

	/*
	启动登陆器
	*/
	int returnvalue;
	returnvalue = _gamectx.apilist->Begin(&_gamectx);
	if ( returnvalue != GT_OK )
	{
		printf("%d",returnvalue);
		/*
		启动游戏失败
		*/
		_gamectx.apilist->End(&_gamectx);
		return;
	}

	/*
	中间的处理过程
	*/
	run(&_gamectx,_tasklet,result);

	/*
	关闭游戏
	*/
	_gamectx.apilist->End(&_gamectx);

	logmsg("返回服务器的账号审核结果为%d",(int)result.result);
}

void Dnf_AccountAudit::run(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	//FormatServName(tasklet.area);
	//XLOG("订单中大区信息为%s",_tasklet.area.c_str());
	int i;
	int returnvalue;

	Sleep(2000);

	/*
	选大区流程
	*/
	for ( i = 0; i < selectarea_trytimes; ++i )
	{
		//returnvalue = call->apilist->SelectServer(const_cast<char*>(tasklet.area.c_str()),call);
		returnvalue = call->apilist->SelectServer("浙江区",call);
		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_UNABLECONNECT && i != selectserver_trytimes - 1 )
			continue;
		else if ( returnvalue == GT_UNABLECONNECT && i == selectserver_trytimes - 1 )
		{
			/*
			返回值大区无法连接
			*/
			logmsg("连接大区失败");
			return;
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
	}

	logmsg("连接大区成功");

	Sleep(2000);

	/*
	选小区流程
	*/
	for ( i = 0; i < selectarea_trytimes; ++i )
	{
		returnvalue = call->apilist->SelectArea(const_cast<char*>(tasklet.server.c_str()),call);
		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_FALSE && i != selectarea_trytimes - 1 )
			continue;
		else if ( returnvalue == GT_FALSE && i == selectarea_trytimes - 1 )
		{
			logmsg("小区无法连接");
			return;
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
	}

	logmsg("选小区成功");

	Sleep(5000);

	/*
	账号登陆流程
	*/
	for ( i = 0; i < login_trytimes; ++i )
	{
		returnvalue = call->apilist->Login(const_cast<char*>(tasklet.account.c_str()),const_cast<char*>(tasklet.password.c_str()),call);
		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_PASSWORDERROR && i != login_trytimes - 1 )
		{
			continue;
		}
		else if ( returnvalue == GT_PASSWORDERROR && i == login_trytimes - 1 )
		{
			/*
			卖家密码错误l
			*/
			taskresult.result = GT_ERR_8010;

			logmsg("卖家密码错误");
			return;
		}
		else if ( returnvalue == GT_MBERROR )
		{
			/*
			卖家密保上传错误
			*/
			taskresult.result = GT_ERR_8040;

			logmsg("卖家密保上传错误");
			return;
		}
		else if ( returnvalue == GT_VERIFYCODEERROR )
		{
			/*
			答题员放弃答题
			*/
			taskresult.result = GT_ERR_8040;

			logmsg("验证码输入多次错误，答题员放弃答题");
			return;
		}
		else if ( returnvalue == GT_UNABLECONNECT )
		{
			logmsg("无法连接账号密码验证");
			return;
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
	}

	logmsg("登陆成功");

	/*
	选线流程
	*/
	returnvalue = call->apilist->SelectLineByName("",call);

	if ( returnvalue != GT_OK )
	{
		logmsg("选线失败");

		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}

	logmsg("选线成功");

	Sleep(2000);

	/*
	选角色流程
	*/
	logmsg("选择订单中的角色%s登陆",tasklet.post.sellerActor.c_str());
	for ( i = 0; i < selectrole_trytimes; ++i )
	{
		returnvalue = call->apilist->SelectRoleByName((char*)_tasklet.audit.sellerActor.c_str(),call);
		if ( returnvalue == GT_OK )
		{
			break;
		}
		else if ( returnvalue == GT_NOTEXISTED && i != selectrole_trytimes -1 )
		{
		}
		else if ( returnvalue == GT_NOTEXISTED && i == selectrole_trytimes -1 )
		{
			logmsg("选角色失败");

			taskresult.result = GT_ERR_8030;
			return;
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
	}

	logmsg("角色%s登陆成功",tasklet.audit.sellerActor.c_str());

	/*
	获取账号信息
	*/

	char* info = NULL;
	int infosize;
	returnvalue = call->apilist->GetAccountInfo(&info,&infosize,call);

	if ( returnvalue == GT_OK )
	{
		AddDNFItemType();
		AddDNFItemProperty();
		accountinfo.parse(info,infosize);
		accountinfo.save();
		std::wstring doc = accountinfo.m_markup.GetDoc();
		taskresult.textval = ws2s(doc);

		taskresult.result = GT_ERR_8000;
	}
	else
	{
		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}
}

void Dnf_AccountAudit::checkReturnvalueprocess( int returnvalue, gtr::GameTaskResultT& taskresult )
{
	if ( returnvalue == GT_OK )
	{
		return;
	}
	else if ( returnvalue == GT_FALSE )
	{
		logmsg("上一步操作失败导致无法继续");
		return;
	}
	else if ( returnvalue == GT_ROLEKICK )
	{
		logmsg("上一步操作卖家顶号");
		return;
	}
	else if ( returnvalue == GT_TIMEOUT )
	{
		logmsg("上一步操作超时");
		return;
	}
	else if ( returnvalue == GT_CONNECTBREAK )
	{
		logmsg("上一步操作连接中断");
		return;
	}
	else if ( returnvalue == GT_PLAYERINLINE )
	{
		logmsg("玩家在线");
		return;
	}
	else if ( returnvalue == GT_ROLELOCK )
	{
		logmsg("玩家被封号");
		return;
	}
	else if ( returnvalue == GT_UNABLECONNECT )
	{
		logmsg("上一步操作返回错误");
		return;
	}
}

char* Dnf_AccountAudit::core_auth_image(Gt_CallContext* ctx,Gt_ImageTypeT imagetype,char* imagedata,int size,int width,int height)
{
	static std::string secret;
	gtr::QuestionContentT data;

	data.type = ctx->xtype;	
	data.image.type = (int)imagetype;
	data.image.width = width;
	data.image.height = height;
	data.image.bytes.resize(size);
	memcpy(&data.image.bytes[0],imagedata,size);

	try{
		secret = _serverPrx->answer(data);
	}	catch(...){

	}
	return (char*)secret.c_str();
}

void Dnf_AccountAudit::AddDNFItemType()
{
	accountinfo.AddItemType( wxT("消耗品") );
	accountinfo.AddItemType( wxT("材料") );
	accountinfo.AddItemType( wxT("投掷品") );
	accountinfo.AddItemType( wxT("任务") );
	accountinfo.AddItemType( wxT("宠物装备") );
	accountinfo.AddItemType( wxT("上衣") );
	accountinfo.AddItemType( wxT("头肩") );
	accountinfo.AddItemType( wxT("下装") );
	accountinfo.AddItemType( wxT("腰带") );
	accountinfo.AddItemType( wxT("鞋") );
	accountinfo.AddItemType( wxT("手镯") );
	accountinfo.AddItemType( wxT("项链") );
	accountinfo.AddItemType( wxT("戒指") );
	accountinfo.AddItemType( wxT("称号") );
	accountinfo.AddItemType( wxT("武器") );
	accountinfo.AddItemType( wxT("装扮") );

	accountinfo.AddItemSpecialType( wxT("消耗品") );
	accountinfo.AddItemSpecialType( wxT("材料") );
	accountinfo.AddItemSpecialType( wxT("投掷品") );
	accountinfo.AddItemSpecialType( wxT("任务") );
}
void Dnf_AccountAudit::AddDNFItemProperty()
{
	accountinfo.AddItemProperty( wxT("物理防御力"),	wxT("物理防御力 +([^@]+)") );
	accountinfo.AddItemProperty( wxT("魔法防御力"),	wxT("魔法防御力 +([^@]+)") );
	accountinfo.AddItemProperty( wxT("物理攻击力"),	wxT("物理攻击力 +([^@]+)") );
	accountinfo.AddItemProperty( wxT("无视防御的物理攻击力"),	wxT("无视防御的物理攻击力 +([^@]+)") );
	accountinfo.AddItemProperty( wxT("魔法攻击力"),	wxT("魔法攻击力 +([^@]+)") );
	accountinfo.AddItemProperty( wxT("无视防御的魔法攻击力"),	wxT("无视防御的魔法攻击力 +([^@]+)") );
	accountinfo.AddItemProperty( wxT("体力"),		wxT("体力 +([^@]+)") );
	accountinfo.AddItemProperty( wxT("智力"),		wxT("智力 +([^@]+)") );
	accountinfo.AddItemProperty( wxT("精神"),		wxT("精神 +([^@]+)") );
	accountinfo.AddItemProperty( wxT("力量"),		wxT("力量 +([^@]+)") );
}