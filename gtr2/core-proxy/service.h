
#ifndef _SERVICE_MAIN
#define _SERVICE_MAIN
 
#include <wx/wx.h>

#include <IceUtil/IceUtil.h>
#include <Ice/Ice.h>
#include <gtrc.h>
#include "../idl/gtr_api.h"
#include "thread.h"
#include "log.h"
#include "dll_loader.h"
#include "config.h"

struct configData
{
	std::string sGtrClientIp;
	std::string sGtrClientPort;
	std::string sGamePath;
	std::string sMailTitle;
	std::string sMailContent;
	std::string sLogPath;
};


class GameRobotInstance:public wxApp,public swlib::Thread{
	//DECLARE_EVENT_TABLE()
public:
	struct PropertiesT{
		std::string name;
	};
	bool	OnInit(){ return mainloop();}
	//int		OnExit(){	ret}
	virtual bool mainloop();
	virtual void exit();

	
	virtual Gt_ReturnValueT task_prepare();
	virtual Gt_ReturnValueT task_finish();

	virtual void	task_MailPost(gtr::GameTaskResultT& result);
	virtual void	task_Verify(gtr::GameTaskResultT& result);
	virtual void	task_AccountAudit(gtr::GameTaskResultT& result);
	
	virtual std::string getGameDll();
	virtual std::string getGamePath();
	virtual std::string getGameLogfile();
	virtual int getHeartbeatInterval();

	virtual bool initGameCore();
	virtual void initGameApi();

	virtual void core_log(Gt_CallContext* ctx,char* msg);
	virtual void core_log2(Gt_CallContext* ctx,char* data,int size); 
	
	virtual void auth_validate(int type, std::string secret);
	std::string core_auth(gtr::QuestionContentT &question);
	virtual char* core_auth_coords(Gt_CallContext* ctx,char* coords);
	virtual char* core_auth_image(Gt_CallContext* ctx,Gt_ImageTypeT imagetype,char* imagedata,int size,int width,int height);
	virtual void 	core_capture_image(Gt_CallContext* ctx,char* excName,char* imagedata,int size,int width,int height);
	virtual int  core_auth_result(Gt_CallContext* ctx,int succ) ;

	void logmsg(const char * fmt,...);

	virtual bool rolematch(std::vector<std::string>& roles, int& result,std::string& _seller);
	virtual bool parserolelist(std::vector<std::string>& roles);
private:
	virtual void run();
	static void __stdcall _cb_log(Gt_CallContext* ctx,char* msg);
	static void __stdcall _cb_log2(Gt_CallContext* ctx,char* data,int size); 
	static char* __stdcall _cb_auth_coords(Gt_CallContext* ctx,char* coords);
//	static char* _cb_auth_coordsx(Gt_CallContext* ctx,char* coords);
	static char* __stdcall _cb_auth_image(Gt_CallContext* ctx,Gt_ImageTypeT imagetype,char* imagedata,int size,int width,int height);
	static void  __stdcall _cb_capture_image(Gt_CallContext* ctx,char* excName,char* imagedata,int size,int width,int height);
	static int  __stdcall _cb_auth_result(Gt_CallContext* ctx,int succ);
public:
	static GameRobotInstance & instance();
	PropertiesT& getProps(){	return _props;}
	swlib::swLogger&		getLogger(){	return _logger;}
	CALLCTX& getGameContex(){	return _gamectx;}
private:
	PropertiesT	_props;
protected:
	 Ice::CommunicatorPtr _communicator;
	 gtr::IGameHostPrx _serverPrx;
	 gtr::GameTaskletT _tasklet;
	CALLCTX		_gamectx;
	swlib::swLogger	_logger;
	swlib::Dll_Loader _dllloader;
	//std::map<std::string,std::string> _stringProps;
	ConfigProperties _confile;
	Gt_ApiList _gameCoreApi;
	configData configdata;
};

extern GameRobotInstance& getRobotApp();

#endif
