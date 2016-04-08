#include <wx/file.h>
#include "service.h"
#include "util.h"
#include <wx/socket.h>
#include "base64.h"
#include <time.h>
using namespace std;
#if 0
#include <general.h>
#endif
#ifdef _DEBUG
#pragma comment(lib,"wxbase28ud_net.lib")
#else
#pragma comment(lib,"wxbase28u_net.lib")
#endif

#define InitGameFunc(func, symbol, protype) \
	GT_RESULT __stdcall default_##func##protype	\
	{	\
		appLogger().Message("[%s] is not implemented!", ##symbol);	\
		return GT_OK;	\
	}	

#if 0
InitGameFunc(SelectServer,"SelectServer",(char *,CALLCTX*));
InitGameFunc(SelectArea,"SelectArea",(char *,CALLCTX*));
InitGameFunc(SelectLineByName,"SelectLineByName",(char* line,CALLCTX*));
InitGameFunc(SelectLineByIndex,"SelectLineByIndex",(int line,CALLCTX*));
InitGameFunc(Login,"Login",(char* usr,char* passwd,CALLCTX*));
InitGameFunc(IsExistDynMB,"IsExistDynMB",(CALLCTX*));
InitGameFunc(IsRightClass,"IsRightClass",(int,CALLCTX* ));
InitGameFunc(IsExistBackHomeSkill,"IsExistBackHomeSkill",(CALLCTX*));
InitGameFunc(UseBackHomeSkill,"UseBackHomeSkill",(CALLCTX*));
InitGameFunc(IsExistBackHomeItem,"IsExistBackHomeItem",(CALLCTX*));
InitGameFunc(UseBackHomeItem,"UseBackHomeItem",(CALLCTX*));
InitGameFunc(QueryRoleLevel,"QueryRoleLevel",(char* ,POUT int *,CALLCTX*));
InitGameFunc(SelectRoleByName,"SelectRoleByName",(char*,CALLCTX*));
InitGameFunc(SelectRoleByIndex,"SelectRoleByIndex",(int,CALLCTX*));
InitGameFunc(IsExistRoleByName,"IsExistRoleByName",(char* ,CALLCTX*));
InitGameFunc(AddRoleToFriend,"AddRoleToFriend",(char*,CALLCTX*));
InitGameFunc(QuerySafeTime,"QuerySafeTime",(POUT int* ,CALLCTX*));
InitGameFunc(IsExistNPC,"IsExistNPC",(Gt_NPCID ,CALLCTX*));
InitGameFunc(OpenWarehouse,"OpenWarehouse",(char* passwd,CALLCTX*));
InitGameFunc(OpenMailBox,"OpenMailBox",(char* passwd,CALLCTX*));
InitGameFunc(OpenBank,"OpenBank",(char* passwd,CALLCTX*));
InitGameFunc(OpenExchange,"OpenExchange",(char* passwd,CALLCTX*));
InitGameFunc(OpenGrocer,"OpenGrocer",(char* passwd,CALLCTX*));
InitGameFunc(MoveToByNpcID,"MoveToByNpcID",(Gt_NPCID,CALLCTX*));
InitGameFunc(Talk,"Talk",(Gt_NPCID,CALLCTX*));	
InitGameFunc(QueryItemsInBag,"QueryItemsInBag",(Gt_GameItemT item,POUT INT64*,CALLCTX*));
InitGameFunc(QueryItemsInWarehouse,"QueryItemsInWarehouse",(Gt_GameItemT item,POUT INT64*,CALLCTX*));
InitGameFunc(QueryItemsInBank,"QueryItemsInBank",(Gt_GameItemT item,POUT INT64*,CALLCTX*));
InitGameFunc(QueryItemsInExchange,"QueryItemsInExchange",(Gt_GameItemT item,POUT INT64*,CALLCTX*));
InitGameFunc(IsEnoughItemsInMailbox,"IsEnoughItemsInMailbox",(Gt_GameItemT item,PINOUT INT64*,CALLCTX*));
InitGameFunc(WithdrawItemsInWarehouse,"WithdrawItemsInWarehouse",(Gt_GameItemT item,PINOUT INT64*,CALLCTX*));
InitGameFunc(WithdrawItemsInBank,"WithdrawItemsInBank",(Gt_GameItemT item,PINOUT INT64*,CALLCTX*));
InitGameFunc(WithdrawItemsInExchange,"WithdrawItemsInExchange",(Gt_GameItemT item,PINOUT INT64*,CALLCTX*));
InitGameFunc(WithdrawItemsInMailbox,"WithdrawItemsInMailbox",(Gt_GameItemT item,PINOUT  INT64*,CALLCTX*));
InitGameFunc(SendMail,"SendMail",(char* reciever,char* title,char* content,INT64,CALLCTX*));	
InitGameFunc(SellItem,"SellItem",(int item,int itemNum,CALLCTX*));
InitGameFunc(Transport,"Transport",( int mapid, CALLCTX* ));
InitGameFunc(IsUnlocked,"IsUnlocked",(CALLCTX*));
InitGameFunc(IsInMap,"IsInMap",( int mapid, CALLCTX* ));
InitGameFunc(ReturnToSelectRole,"ReturnToSelectRole",( CALLCTX* ));
InitGameFunc(MoveTo,"MoveTo",(int type, CALLCTX *ctx));
InitGameFunc(IsNearBy,"IsNearBy",(Gt_NPCID, CALLCTX *ctx));
InitGameFunc(GetAccountInfo,"GetAccountInfo",(char**,int*,CALLCTX* ctx));
InitGameFunc(GetRoleList,"GetRoleList",(char*,int,int*,CALLCTX* ctx));
InitGameFunc(GetBestNPC,"GetBestNPC",(int*,int*,CALLCTX* ctx));
InitGameFunc(SaveItemInfo,"SaveItemInfo",(int,CALLCTX* ctx));
InitGameFunc(Begin,"Begin",(CALLCTX*));
InitGameFunc(End,"End",(CALLCTX*));
#endif

#if 1
#define DefineGameFunc(func,symbol,protype)	\
	_gamectx.apilist->##func = (GT_RESULT (__stdcall *)protype)_dllloader.loadSymbol(symbol);
#else
#define DefineGameFunc(func,symbol,protype)	\
	_gamectx.apilist->##func = default_##func;	\
	_gamectx.apilist->##func = (GT_RESULT (__stdcall *)protype)_dllloader.loadSymbol(symbol);
#endif


#define DefineGameFunc2(func,symbol,protype)	\
	_gamectx.apilist->##func = (protype)_dllloader.loadSymbol(symbol);

//IMPLEMENT_APP(Userver)
//IMPLEMENT_APP_CONSOLE(GameRobotInstance)

/*
 void _stdcall _cb_log(Gt_CallContext* ctx,char* msg){
	GameRobotInstance* inst = (GameRobotInstance*)ctx->cookie;
	inst->core_log(ctx,msg);
}

_stdcall  void _cb_log2(Gt_CallContext* ctx,char* data,int size){
	GameRobotInstance* inst = (GameRobotInstance*)ctx->cookie;
	inst->core_log2(ctx,data,size);
}


_stdcall char* _cb_auth_coords(Gt_CallContext* ctx,char* coords){
	GameRobotInstance* inst = (GameRobotInstance*)ctx->cookie;
	return inst->core_auth_coords(ctx,coords);

}


_stdcall char* _cb_auth_image(Gt_CallContext* ctx,Gt_ImageTypeT imagetype,char* imagedata,int size,int width,int height){
	GameRobotInstance* inst = (GameRobotInstance*)ctx->cookie;
	return inst->core_auth_image(ctx,imagetype,imagedata,size,width,height);
}

_stdcall void  _cb_capture_image(Gt_CallContext* ctx,char* excName,char* imagedata,int size,int width,int height){
	GameRobotInstance* inst = (GameRobotInstance*)ctx->cookie;
	inst->core_capture_image(ctx,excName,imagedata,size,width,height);
}*/
//////////////////////////////////////////////////////////////////////////

//转换256色图像到传输字节流 
bool serialBitmap256(swByte* data,int width,int height,gtr::ImageDataT* oimage){
	wxFile ff;
	std::vector<unsigned char> buffer;
	buffer.assign(data,data+width*height);
	std::vector<unsigned char> colors;
	colors.resize(buffer.size()*3);
	for(size_t n=0;n<buffer.size();n++){
		colors[n*3] = buffer[n];
		colors[n*3+1] = buffer[n];
		colors[n*3+2] = buffer[n];
	}
	//unsigned char * final =(unsigned char*) malloc(colors.size());
	//memcpy(final,&colors[0],colors.size());

	wxImage image(width,height);
	char* imgdata = (char*) image.GetData();
	memcpy(imgdata, &colors[0], colors.size());
	//image.SetData(final);
	if(!image.IsOk()){
		return false;
	}
	wxString imagefile = wxString::Format(wxT("%d.png"),wxDateTime::Now().GetTicks());
	image.SaveFile(imagefile,wxBITMAP_TYPE_PNG);
	
	if(ff.Open(imagefile)){
		oimage->bytes.resize(ff.Length());		
		ff.Read(&oimage->bytes[0],oimage->bytes.size());
		oimage->width = width;
		oimage->height = height;
		oimage->type =0;
	}else{
		return false;
	}
	//////////////////////////////////////////////////////////////////////////		
	return true;
}

void _debug_loop()
{
	static int _debug_flag = 1;
	while(_debug_flag)
	{
		if(_debug_flag)
			_debug_flag = _debug_flag;
		Sleep(1000);
	}
}

bool	GameRobotInstance::mainloop(){
	std::string proxystr;
	int argc;	
	char* argv[]={"this","--Ice.Config=userver.ice.conf"};
	argc = 1;
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
#ifdef _DEBUG
	std::string sRolename;
	std::string sAccount;
	std::string sPwd;
	std::string sArea;
	std::string sServer;
#endif
	if( _confile.loadFromFile("game-proxy.txt"))
	{
		wxString clientip = wxString::FromUTF8(_confile.getProperty("gtrClientIp").c_str()).Trim().Trim(false);
		configdata.sGtrClientIp = std::string(clientip.mb_str());
		wxString clientport = wxString::FromUTF8(_confile.getProperty("gtrClientport").c_str()).Trim().Trim(false);
		configdata.sGtrClientPort = std::string(clientport.mb_str());
		wxString gamepath = wxString::FromUTF8(_confile.getProperty("gamepath").c_str()).Trim().Trim(false);
		configdata.sGamePath = std::string(gamepath.mb_str());
		wxString mailtitle = wxString::FromUTF8(_confile.getProperty("mailtitle").c_str()).Trim().Trim(false);
		configdata.sMailTitle = std::string(mailtitle.mb_str());
		wxString mailcontent = wxString::FromUTF8(_confile.getProperty("mailcontent").c_str()).Trim().Trim(false);
		configdata.sMailContent = std::string(mailcontent.mb_str());
		wxString logpath = wxString::FromUTF8(_confile.getProperty("logpath").c_str()).Trim().Trim(false);
		configdata.sLogPath = std::string(logpath.mb_str());

#ifdef _DEBUG
		wxString rolename = wxString::FromUTF8(_confile.getProperty("rolename").c_str()).Trim().Trim(false);
		sRolename = std::string(rolename.mb_str());
		wxString account = wxString::FromUTF8(_confile.getProperty("account").c_str()).Trim().Trim(false);
		sAccount = std::string(account.mb_str());
		wxString pwd = wxString::FromUTF8(_confile.getProperty("pwd").c_str()).Trim().Trim(false);
		sPwd = std::string(pwd.mb_str());
		wxString area = wxString::FromUTF8(_confile.getProperty("area").c_str()).Trim().Trim(false);
		sArea = std::string(area.mb_str());
		wxString server = wxString::FromUTF8(_confile.getProperty("server").c_str()).Trim().Trim(false);
		sServer = std::string(server.mb_str());
#endif
	}
	//////////////////////////////////////////////////////////////////////////
	LOG_ADD_UDP_WRITER(_logger,"127.0.0.1",10010)	;
	LOG_ADD_REGFILE_WRITER(_logger,getGameLogfile().c_str());
	getLogger().Debug("game-proxy started..");
	//////////////////////////////////////////////////////////////////////////
	_gamectx.auth_coords = GameRobotInstance::_cb_auth_coords;
	_gamectx.auth_image = GameRobotInstance::_cb_auth_image;
	_gamectx.capture_image = GameRobotInstance::_cb_capture_image;
	_gamectx.log = GameRobotInstance::_cb_log;
	_gamectx.log2 = GameRobotInstance::_cb_log2;
	_gamectx.auth_result = GameRobotInstance::_cb_auth_result;
	_gamectx.apilist = &_gameCoreApi;
	//////////////////////////////////////////////////////////////////////////
	wxInitAllImageHandlers();

	//////////////////////////////////////////////////////////////////////////
	if(!initGameCore()){
		exit();
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	try
	{
		_communicator = Ice::initialize(argc, argv);
		proxystr = "GameHost:tcp -p " + configdata.sGtrClientPort + " -h " + configdata.sGtrClientIp;
		_serverPrx = gtr::IGameHostPrx::uncheckedCast(_communicator->stringToProxy(proxystr));
	}
	catch (const Ice::Exception& e) 
	{
		const char* msg = e.what();
		msg = msg;
	} 
	catch (const char* msg) 
	{ 
		msg = msg;
	} 
 	gtr::GameTaskResultT result;

	//////////////////////////////////////////////////////////////////////////
 	try{
#ifdef _DEBUG
		//_tasklet.type = gtr::gwsPost;
		//_tasklet.account = "c5gqcu25f";
		//_tasklet.password = "GTR5173";
		//_tasklet.post.sellerActor = "丨劍緣丶盗钟掩耳";
		//_tasklet.post.buyerActor = "幻·百纵千随";
		//_tasklet.area = "吉祥区";
		//_tasklet.server = "踏青游";
		//_tasklet.post.buyerMoney = 100000;
		//_tasklet.post.money = 100000;

		_tasklet.type = 2;
		_tasklet.account = "jhsdwb01";
		_tasklet.password = "835143210";
		_tasklet.area = "四区(华东电信)";
		_tasklet.server = "巨蟹座";
		_tasklet.audit.sellerActor = "长的很勇敢";

		if(sRolename.size()!=0)
			_tasklet.audit.sellerActor = sRolename;
		if (sAccount.size()!=0)
			_tasklet.account = sAccount;
		if (sPwd.size()!=0)
			_tasklet.password = sPwd;
		if (sArea.size()!=0)
			_tasklet.area = sArea;
		if (sServer.size()!=0)
			_tasklet.server = sServer;

		//_tasklet.type = 2;
		//_tasklet.account = "jhsdwb01";
		//_tasklet.password = "835143210";
		//_tasklet.area = "四区(华东电信)";
		//_tasklet.server = "巨蟹座";
		//_tasklet.audit.sellerActor = "长的很勇敢";
		//_tasklet.account = "lx05541209";
		//_tasklet.password = "123520";
#else
		_tasklet =	_serverPrx->getTask();
#endif

#if 0
		wxString temp = wxString::FromUTF8(_tasklet.area.c_str());
		_tasklet.area = std::string(temp.mb_str());
		temp = wxString::FromUTF8(_tasklet.server.c_str());
		_tasklet.server = std::string(temp.mb_str());
		switch(_tasklet.type)
		{
		case gtr::gwsPost:
			temp = wxString::FromUTF8(_tasklet.post.sellerActor.c_str());
			_tasklet.post.sellerActor = std::string(temp.mb_str());
			temp = wxString::FromUTF8(_tasklet.post.buyerActor.c_str());
			_tasklet.post.buyerActor = std::string(temp.mb_str());
			break;
		case gtr::gwsVerify:
			temp = wxString::FromUTF8(_tasklet.verify.sellerActor.c_str());
			_tasklet.verify.sellerActor = std::string(temp.mb_str());
			break;
		case gtr::gwsAccountAudit:
			temp = wxString::FromUTF8(_tasklet.audit.sellerActor.c_str());
			_tasklet.audit.sellerActor = std::string(temp.mb_str());
			break;
		}
#endif
 		result.result = GT_FALSE;
 		result.id = _tasklet.id;
 		result.no = _tasklet.no;
 		if(_tasklet.type == gtr::gwsPost){
 			task_MailPost(result);
 		}else if(_tasklet.type == gtr::gwsVerify){
 			task_Verify(result);
 		}else if(_tasklet.type == gtr::gwsAccountAudit){
 			task_AccountAudit(result);
 		}
 		_serverPrx->completeTask(result);
 
 	}catch(const ::Ice::LocalException& __ex){
 		
 		getLogger().Error("Rpc::getTask() failed!");
		getLogger().Error("Rpc Exception[Ice]: %s", __ex.what());
 		
	}catch(...){

		getLogger().Error("Rpc::getTask() failed!");
		getLogger().Error("not ice exception");

 	}
 	
	//////////////////////////////////////////////////////////////////////////
	this->exit();
	return false;
}

void GameRobotInstance::exit(){
	getLogger().Message("exit");
 	if (_gamectx.apilist->CleanUp != NULL)
 	{
 		_gamectx.apilist->CleanUp(&_gamectx);
 	}
	stop();
	_dllloader.free();
}

GameRobotInstance& GameRobotInstance::instance(){
	static GameRobotInstance handle;
	return handle;
}

//邮寄处理
void	GameRobotInstance::task_MailPost(gtr::GameTaskResultT& result){
	
}

//
void	GameRobotInstance::task_Verify(gtr::GameTaskResultT& result){
}

void	GameRobotInstance::task_AccountAudit(gtr::GameTaskResultT& result){
}

std::string GameRobotInstance::getGameDll(){
	return "";
}

std::string GameRobotInstance::getGamePath(){
	return "";
}

//初始化游戏接口表 
void GameRobotInstance::initGameApi(){
	//Load Hook Dll	
	DefineGameFunc(SelectServer,"SelectServer",(char *,CALLCTX*));
	DefineGameFunc(SelectArea,"SelectArea",(char *,CALLCTX*));
	DefineGameFunc(SelectLineByName,"SelectLineByName",(char* line,CALLCTX*));
	DefineGameFunc(SelectLineByIndex,"SelectLineByIndex",(int line,CALLCTX*));
	DefineGameFunc(Login,"Login",(char* usr,char* passwd,CALLCTX*));
	DefineGameFunc(IsExistDynMB,"IsExistDynMB",(CALLCTX*));
	DefineGameFunc(IsRightClass,"IsRightClass",(int,CALLCTX* ));
	DefineGameFunc(IsExistBackHomeSkill,"IsExistBackHomeSkill",(CALLCTX*));
	DefineGameFunc(UseBackHomeSkill,"UseBackHomeSkill",(CALLCTX*));
	DefineGameFunc(IsExistBackHomeItem,"IsExistBackHomeItem",(CALLCTX*));
	DefineGameFunc(UseBackHomeItem,"UseBackHomeItem",(CALLCTX*));
	DefineGameFunc(QueryRoleLevel,"QueryRoleLevel",(char* ,POUT int *,CALLCTX*));
	DefineGameFunc(SelectRoleByName,"SelectRoleByName",(char*,CALLCTX*));
	DefineGameFunc(SelectRoleByIndex,"SelectRoleByIndex",(int,CALLCTX*));
	DefineGameFunc(IsExistRoleByName,"IsExistRoleByName",(char* ,CALLCTX*));
	DefineGameFunc(AddRoleToFriend,"AddRoleToFriend",(char*,CALLCTX*));
	DefineGameFunc(QuerySafeTime,"QuerySafeTime",(POUT int* ,CALLCTX*));
	DefineGameFunc(IsExistNPC,"IsExistNPC",(Gt_NPCID ,CALLCTX*));
	DefineGameFunc(OpenWarehouse,"OpenWarehouse",(char* passwd,CALLCTX*));
	DefineGameFunc(OpenMailBox,"OpenMailBox",(char* passwd,CALLCTX*));
	DefineGameFunc(OpenBank,"OpenBank",(char* passwd,CALLCTX*));
	DefineGameFunc(OpenExchange,"OpenExchange",(char* passwd,CALLCTX*));
	DefineGameFunc(OpenGrocer,"OpenGrocer",(char* passwd,CALLCTX*));
	DefineGameFunc(MoveToByNpcID,"MoveToByNpcID",(Gt_NPCID,CALLCTX*));
	DefineGameFunc(Talk,"Talk",(Gt_NPCID,CALLCTX*));	
	DefineGameFunc(QueryItemsInBag,"QueryItemsInBag",(Gt_GameItemT item,POUT INT64*,CALLCTX*));
	DefineGameFunc(QueryItemsInWarehouse,"QueryItemsInWarehouse",(Gt_GameItemT item,POUT INT64*,CALLCTX*));
	DefineGameFunc(QueryItemsInBank,"QueryItemsInBank",(Gt_GameItemT item,POUT INT64*,CALLCTX*));
	DefineGameFunc(QueryItemsInExchange,"QueryItemsInExchange",(Gt_GameItemT item,POUT INT64*,CALLCTX*));
	DefineGameFunc(IsEnoughItemsInMailbox,"IsEnoughItemsInMailbox",(Gt_GameItemT item,PINOUT INT64*,CALLCTX*));
	DefineGameFunc(WithdrawItemsInWarehouse,"WithdrawItemsInWarehouse",(Gt_GameItemT item,PINOUT INT64*,CALLCTX*));
	DefineGameFunc(WithdrawItemsInBank,"WithdrawItemsInBank",(Gt_GameItemT item,PINOUT INT64*,CALLCTX*));
	DefineGameFunc(WithdrawItemsInExchange,"WithdrawItemsInExchange",(Gt_GameItemT item,PINOUT INT64*,CALLCTX*));
	DefineGameFunc(WithdrawItemsInMailbox,"WithdrawItemsInMailbox",(Gt_GameItemT item,PINOUT  INT64*,CALLCTX*));
	DefineGameFunc(SendMail,"SendMail",(char* reciever,char* title,char* content,INT64,CALLCTX*));	
	DefineGameFunc(SellItem,"SellItem",(int item,int itemNum,CALLCTX*));
	DefineGameFunc(Transport,"Transport",( int mapid, CALLCTX* ));
	DefineGameFunc(IsUnlocked,"IsUnlocked",(CALLCTX*));
	DefineGameFunc(IsInMap,"IsInMap",( int mapid, CALLCTX* ));
	DefineGameFunc(ReturnToSelectRole,"ReturnToSelectRole",( CALLCTX* ));
	DefineGameFunc(MoveTo,"MoveTo",(int type, CALLCTX *ctx));
	DefineGameFunc(IsNearBy,"IsNearBy",(Gt_NPCID, CALLCTX *ctx));
	DefineGameFunc(GetAccountInfo,"GetAccountInfo",(char**,int*,CALLCTX* ctx));
	DefineGameFunc(GetRoleList,"GetRoleList",(char*,int,int*,CALLCTX* ctx));
	DefineGameFunc(GetBestNPC,"GetBestNPC",(int*,int*,CALLCTX* ctx));
	DefineGameFunc(GetRoleList,"GetRoleList",(char*,int,int*,CALLCTX* ctx));
	DefineGameFunc(GetBestNPC,"GetBestNPC",(int*,int*,CALLCTX* ctx));
	DefineGameFunc(SaveItemInfo,"SaveItemInfo",(int,CALLCTX* ctx));
	DefineGameFunc(IsNeedBackHome,"IsNeedBackHome",(CALLCTX* ctx));
	DefineGameFunc(Begin,"Begin",(CALLCTX*));
	DefineGameFunc(End,"End",(CALLCTX*));

	DefineGameFunc2(Init,"Init",GT_BOOL (__stdcall *)(char * gamedir,CALLCTX* ctx));
	DefineGameFunc2(CleanUp,"CleanUp",void	(__stdcall *)(CALLCTX* ctx));
}

bool GameRobotInstance::initGameCore(){
	if( _dllloader.load( wxString::FromUTF8(getGameDll().c_str())) == false){		
		getLogger().Error("Dll_loader(%s) failed!",getGameDll().c_str());
		return false;
	}

	initGameApi();

	_gamectx.cookie = (void*)this;
 	if( _gamectx.apilist->Init((char*)getGamePath().c_str(),&_gamectx)!=GT_OK){
 		getLogger().Error("Game-core:: Init() failed!");
 		return false;
 	}
	return true;
}


std::string encode_logmsg_base64(const char* s){
	std::string encmsg;
	char * buff;
	size_t ilen;
	ilen = strlen(s);
	size_t	size = base64_encode_alloc (s, ilen, &buff);
	encmsg.assign(buff,size);
	free(buff);
	return encmsg;
}


void GameRobotInstance::logmsg(const char * fmt,...){
	va_list marker;				
	char * buff = new char[1024*50];//LOG_MAX_BUFF_SIZE];
	if( !buff ) {
		return;
	}		
	va_start(marker,fmt);	
	vsprintf(buff,fmt,marker);
	va_end(marker); 	
	getLogger().Debug(buff);
	core_log(NULL,buff);
	delete [] buff ;	
}

/*
2010.4.20 zhangbin 
1. 包装日志消息格式
*/
void GameRobotInstance::core_log(Gt_CallContext* ctx,char* msg){
	wxIPV4address addr;	
	wxString computerName=::wxGetFullHostName();
	wxString username=::wxGetUserId();
	addr.Hostname(computerName);
	wxString ipaddr = addr.IPAddress(); 
	wxString logmsg;
	std::string no,gameid,ip,timetick,detail;
	no = encode_logmsg_base64(_tasklet.no.c_str());
	gameid = encode_logmsg_base64(_tasklet.gameId.c_str());
	ip = encode_logmsg_base64(ipaddr.ToUTF8().data());
	
	timetick = encode_logmsg_base64((wxString::Format(wxT("%d"),time(0)).ToUTF8().data()));
	detail = encode_logmsg_base64((const char*)msg);
	
	logmsg = wxString::Format(wxT("GRL,1.0,0,7,%d,0,"),time(0));
	logmsg+=wxString::FromUTF8(no.c_str())+wxT(",");
	
	logmsg+=wxString::FromUTF8(gameid.c_str())+wxT(",");
	logmsg+=wxString::FromUTF8(ip.c_str())+wxT(",");
	logmsg+=wxString::FromUTF8(timetick.c_str())+wxT(",");
	logmsg+=wxString::FromUTF8(detail.c_str());
														
	try{ 
		gtr::GameIdentifyT gid;
		gid.id = _tasklet.gameId; gid.tradeNo = _tasklet.no;
		gtr::LogMessageT log;
		log.msg = logmsg.ToUTF8().data();
		_serverPrx->gameMsg(gid,time(0),log);
	}catch(...){
		;
	}
}


int  GameRobotInstance::core_auth_result(Gt_CallContext* ctx,int succ) {

	//getLogger().Message("Verify Answer to Server");
	_serverPrx->verifyAnswer(0,succ);
	return 0;
}

void GameRobotInstance::core_log2(Gt_CallContext* ctx,char* data,int size){

}

void GameRobotInstance::auth_validate(int type, std::string secret){
}

std::string GameRobotInstance::core_auth(gtr::QuestionContentT &data){
	std::string secret;

	getLogger().Message("Auth Start");
	try{
		secret = _serverPrx->answer(data);
		auth_validate(data.type, secret);
	}	
	catch (const Ice::Exception& e) 
	{
		getLogger().Message("Auth Exception[Ice]: %s", e.what());
	} 
	catch (const char* msg) 
	{ 
		getLogger().Message("Auth Exception: %s", msg);
	} 
	catch(...)
	{
		getLogger().Message("Auth Exception");
	}

	getLogger().Message("Auth End %s", secret.c_str());

	return secret;
}

char* GameRobotInstance::core_auth_coords(Gt_CallContext* ctx,char* coords){
	static std::string secret;
	gtr::GameIdentifyT gid;
	gid.id = _tasklet.gameId; gid.tradeNo = _tasklet.no;
	gtr::QuestionContentT data;

	data.type = 2;	
	data.text = coords;

	secret = core_auth(data);

	return (char*)secret.c_str();
}

char* GameRobotInstance::core_auth_image(Gt_CallContext* ctx,Gt_ImageTypeT imagetype,char* imagedata,int size,int width,int height){
	static std::string secret;
	
	//gid.id = _tasklet.gameId; gid.tradeNo = _tasklet.no;
	gtr::QuestionContentT data;
//////////////////////////////////////////////////////////////////////////

	data.type = ctx->xtype;//(int)1;	
	data.image.width = width;
	data.image.height = height;
	if(imagetype==GT_IMAGENOHEAD)
	{
		getLogger().Message("Image Size[%d] : [Width]%d [Height]%d", size, width, height );
		data.image.type = GT_IMAGEPNG;
		data.image.type = GT_IMAGENOHEAD;
		serialBitmap256((swByte*)imagedata,width,height,&data.image);
	}
	else
	{
		getLogger().Message("ImageNormal");
		data.image.type = (int)imagetype;
		data.image.bytes.resize(size);
		memcpy(&data.image.bytes[0],imagedata,size);
	}

	secret = core_auth(data);

	return (char*)secret.c_str();
}

//
void 	GameRobotInstance::core_capture_image(Gt_CallContext* ctx,char* excName,char* imagedata,int size,int width,int height){
	 
	gtr::GameIdentifyT gid;
	gid.id = _tasklet.gameId; gid.tradeNo = _tasklet.no;
	gtr::ImageDataT data;
	//////////////////////////////////////////////////////////////////////////
	if( width*height*3 != size){
		return; // invalid data
	}
	// jpeg 压缩
	data.type = (int)GT_IMAGEJPEG;	
	data.width = width;
	data.height = height;
	//
	wxImage image;
	char * imgbuff =(char*) malloc(size);
	memcpy(imgbuff,imagedata,size);
	image.SetData((unsigned char*)imgbuff);
	image.SaveFile(wxT("capimage.jpg"),wxBITMAP_TYPE_JPEG);
	wxFile file;
	if(!file.Open(wxT("capimage.jpg"))){
		return ;
	}
	data.bytes.resize(file.Length());
	file.Read(&data.bytes[0],file.Length());
	file.Close();

	try{
		_serverPrx->gameImage(gid,time(0),excName,data);
	}	catch(...){
	}
	
}

void __stdcall GameRobotInstance::_cb_log(Gt_CallContext* ctx,char* msg){
	GameRobotInstance* inst = (GameRobotInstance*)ctx->cookie;
	inst->core_log(ctx,msg);
}

void GameRobotInstance::_cb_log2(Gt_CallContext* ctx,char* data,int size){
	GameRobotInstance* inst = (GameRobotInstance*)ctx->cookie;
	inst->core_log2(ctx,data,size);
}


char* GameRobotInstance::_cb_auth_coords(Gt_CallContext* ctx,char* coords){
	GameRobotInstance* inst = (GameRobotInstance*)ctx->cookie;
	return inst->core_auth_coords(ctx,coords);
	
}
 

char* GameRobotInstance::_cb_auth_image(Gt_CallContext* ctx,Gt_ImageTypeT imagetype,char* imagedata,int size,int width,int height){
	GameRobotInstance* inst = (GameRobotInstance*)ctx->cookie;
	return inst->core_auth_image(ctx,imagetype,imagedata,size,width,height);
}

void  GameRobotInstance::_cb_capture_image(Gt_CallContext* ctx,char* excName,char* imagedata,int size,int width,int height){
	GameRobotInstance* inst = (GameRobotInstance*)ctx->cookie;
	inst->core_capture_image(ctx,excName,imagedata,size,width,height);
}


int   GameRobotInstance::_cb_auth_result(Gt_CallContext* ctx,int succ){
	GameRobotInstance* inst = (GameRobotInstance*)ctx->cookie;
	inst->core_auth_result(ctx,succ);
	return 0;
}


void GameRobotInstance::run(){
	while(loop()){
		try{
			_serverPrx->heartbeat("game-core",_tasklet.id);
		}	catch(...){
		}
		Sleep(getHeartbeatInterval());
	}
}

int GameRobotInstance::getHeartbeatInterval(){
	
	return swlib::str2int(_confile.getProperty("heartbeat","2000"));
}
std::string GameRobotInstance::getGameLogfile(){
	//return "game-core.log";
	time_t t;
	time(&t);
	struct tm *ptm = localtime(&t);
	char buffer[128] = {0};
	sprintf(buffer,"%s%d-%d-%d.log",configdata.sLogPath.c_str(),ptm->tm_year+1900,ptm->tm_mon+1,ptm->tm_mday);
	//printf("%s",buffer);
	return std::string(buffer);
}


Gt_ReturnValueT GameRobotInstance::task_prepare(){
	Gt_ReturnValueT r = GT_OK;
	_gamectx.timeout = 1000*3;
	r = _gamectx.apilist->SelectServer((char*)_tasklet.area.c_str(),&_gamectx);
	if( r!=GT_OK ){
		return r;
	}

	return r;
}

Gt_ReturnValueT GameRobotInstance::task_finish(){
	Gt_ReturnValueT r = GT_OK;
	return r;
}

bool GameRobotInstance::rolematch(vector<std::string>& roles, int& result,string& _seller)
{
	if(roles.size()==0)
	{
		//无角色，直接取消订单（提示：无角色）
		logmsg("账号内无角色");

		result = GT_ERR_2010;
		return false;
	}
	else if(roles.size()==1)
	{
		if(roles[0].compare(_seller)==0)
		{
			//角色名匹配，直接走后续流程
			logmsg("账号内只有1个角色,并且匹配");
			logmsg("账号内角色名为%s",(char*)roles[0].c_str());
			return true;
		}
		else
		{
			//角色名不匹配，如金币足够则发货， 否则直接取消订单（提示：角色名不匹配，且金币数不足）
			logmsg("账号内只有1个角色,但是不匹配,选择了这个角色");
			logmsg("账号内角色名为%s",(char*)roles[0].c_str());

			_seller = roles[0];
			result = GT_ERR_2140;
			return true;
		}
	}
	else
	{
		for ( int i = 0; i < (int)roles.size(); ++i )
		{
			logmsg("账号内第%d角色名为%s",i+1,(char*)roles[i].c_str());
		}

		vector<string>::iterator itfind = std::find(roles.begin(), roles.end(), _seller);
		if(itfind != roles.end())
		{
			//有角色名匹配，直接走后续流程（ 注：角色名匹配后，不对该账号其他角色金币数进行判断）
			logmsg("账号内有多个角色,并且有1个角色匹配");
			return true;
		}
		else
		{
			//无角色名匹配，直接转人工
			logmsg("账号内有多个角色,并且无角色匹配");
			result = GT_ERR_3130;
			return false;
		}
	}
}
bool GameRobotInstance::parserolelist(vector<std::string>& roles)
{
	int returnvalue;

	char rolelist[1024] = {0};
	int bufsize = 1024;
	int rolenum;
	char* begin = rolelist;

	returnvalue = _gamectx.apilist->GetRoleList(begin,bufsize,&rolenum,&_gamectx);

	//logmsg("%s",rolelist);
	//logmsg("角色数量为%d",rolenum);

	if ( returnvalue != GT_OK )
	{
		return false;
	}

	string strTemp = string(rolelist);

	string SPLIT = "\r\n";

	string ::size_type pos;
	while((pos = strTemp.find(SPLIT)) != string::npos)
	{
		string strRole = strTemp.substr(0, pos);
		if(!strRole.empty())
			roles.push_back(strRole);
		strTemp = strTemp.substr(pos + 2);
	}
	if(!strTemp.empty())
		roles.push_back(strTemp);

	//assert(roles.size()==rolenum);
	return true;
}