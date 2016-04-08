// ---------------------------------------------------------------------------

#ifndef mainH
#define mainH

// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "IdBaseComponent.hpp"
#include "IdComponent.hpp"
#include "IdUDPBase.hpp"
#include "IdUDPServer.hpp"
#include <ImgList.hpp>
#include <ShellAnimations.hpp>
#include "IdContext.hpp"
#include "IdCustomTCPServer.hpp"
#include "IdScheduler.hpp"
#include "IdSchedulerOfThread.hpp"
#include "IdSchedulerOfThreadPool.hpp"
#include "IdTCPServer.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
// ---------------------------------------------------------------------------
#include <string>
#include <vector>
#include "mutex.h"
#include "base.h"
#include <stdio.h>
#include <XMLDoc.hpp>
#include <map>

#include "IocpModeSvr.h"
#include "base64.h"
#include "Package.h"
#include "alert_form.h"
enum E_ServiceStatus {
	SS_NORMAL, SS_ALERT, SS_UNKNOWN
};

struct LogMessageT {
	AnsiString msg;
};

typedef std::list<LogMessageT>LogMessageList;

struct RegExEntry {
	AnsiString exs; // 表达式
	bool icase; // 大小写忽略
};

typedef std::vector<RegExEntry>RegExEntryList;

struct ServiceObject {
	AnsiString name; // 机器人名称
	AnsiString ip; // 机器人主机地址
	AnsiString logfile; // 日志记录文件名称
	int updatTime;
	E_ServiceStatus status;
	LogMessageList logs;
	// FILE * fpstore;
	HANDLE fpstore;
	RegExEntryList filter; // 报警检测条件
	bool alarming;

	//
	enum {
		SERVER, ROBOT
	};

	int objtype;

	ServiceObject() {
		updatTime = time(0); // 默认为系统当前时间
		alarming = false;
	}
};

struct GtrServer : public ServiceObject {
	GtrServer() {
		objtype = SERVER;
	}
};

struct GtrRobot : public ServiceObject {
	GtrRobot() {
		objtype = ROBOT;
	}

	AnsiString gamepath; // 游戏存储目录
};

/**
* chenlsh modified on 2010-03-13
* 为了更方便共享数据，采用堆heap存放数据代替stack存放
*/
typedef std::vector<GtrRobot*> GtrRobotList;

struct RobotGroup {
	AnsiString name;
	GtrRobotList robots;
};

typedef std::vector<RobotGroup>RobotGroupList;

class TForm1;

/**
* 完成端口回调函数的处理数据
*/
typedef struct tagProcessData
{
	AnsiString strIP;
	TBytes tcbData;
	TForm1* lpFormOwner;
	GtrRobot* lpRobot;
	tagProcessData(){ lpFormOwner = NULL; lpRobot = NULL; }
} PROCESSDATA, *LPPROCESSDATA;


struct LogGameMessageT{
	enum {
		GAME_MSG_DETAIL,  //游戏处理日志详细
		GAME_MSG_RESULT,	 //游戏交易结果明细
		GAME_MSG_MAX
	};

	int type;

	LogGameMessageT(){
		type = LogGameMessageT::GAME_MSG_MAX;
	}
	virtual ~LogGameMessageT(){}
};

struct LogGameDetailT: public LogGameMessageT {
	std::string no;
	std::string gameId;
	std::string ip;
	UINT timetick;
	std::string detail;
	LogGameDetailT(){
		type = GAME_MSG_DETAIL;
	}
};


typedef std::vector<std::string> UnknowMiscPacketBodyT;
struct LogPacketT{
	std::string sign;
	std::string ver;
	int	type;
	UINT persistMask;
	int timetick;	//时间 1970 ~
	UnknowMiscPacketBodyT body;		
	LogGameMessageT* getMessage();
};


/**
*
定义需要做IP关联的数据
*/
typedef struct ROBOTDATAMISC{
	GtrRobot* lpRobot;
	std::vector<unsigned char> buffer;		
	ROBOTDATAMISC(){
		lpRobot = NULL;
	}
	void reset();	//reset buffer	
	void queueIn(unsigned char * data ,size_t size);
	std::vector<LogPacketT*>  getPackets();	//获取接收到的日志消息包	
}  *LPROBOTDATAMISC ;





int DoInsertBusPkgOperation(LogGameMessageT*  msg);


/*
int DoInsertBusPkgWithImageOperation(
	const BUSINESS_INFO & busInfo,
	unsigned char* lpData,
	int nSize);

*/

int DoLogMessage(LogGameMessageT*  msg, GtrRobot* lpRobot);


//---------------------------------



class TForm1 : public TForm {
__published: // IDE-managed Components
	TTimer *timerStatus;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TPanel *Panel2;
	TSplitter *Splitter2;
	TPanel *Panel3;
	TGroupBox *RobotList;
	TSplitter *Splitter3;
	TTreeView *treeRobotGroup;
	TPanel *Panel5;
	TButton *btnClear;
	TPanel *Panel4;
	TStatusBar *StatusBar1;
	TPanel *Panel1;
	TPanel *Panel6;
	TButton *Button1;
	TButton *Button2;
	TGroupBox *ServerList;
	TMemo *memoServer;
	TSplitter *Splitter1;
	TIdUDPServer *udpServer;
	TIdUDPServer *udpRobot;
	TImageList *il1;
	TImageList *il2;
	TListView *lsRobot;
	TButton *btn1;
	TMenuItem *N5;
	TTimer *tmr1;
	TTimer *tmr2;
	TButton *btnStopGame;
	TButton *btnStartGame;
	TButton *btnRestart;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TMemo *memoRobot;
	TPanel *Panel7;
	TMemo *memoSystem;
	TButton *Button6;
	TButton *Button3;
	TIdUDPServer *udpRobot2;
	TADOConnection *_lpAdoConn;
	TADOQuery *_lpAdoQuery;
	TTimer *timerRobotHeartbeat;

	void __fastcall FormShow(TObject *Sender);
	void __fastcall treeRobotGroupChange(TObject *Sender, TTreeNode *Node);
	void __fastcall lsRobotChange(TObject *Sender, TListItem *Item,
		TItemChange Change);
	void __fastcall btnClearClick(TObject *Sender);
	void __fastcall udpServerUDPRead(TIdUDPListenerThread *AThread,
		TBytes AData, TIdSocketHandle *ABinding);
	void __fastcall udpRobotUDPRead(TIdUDPListenerThread *AThread,
		TBytes AData, TIdSocketHandle *ABinding);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall timerStatusTimer(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall tmr1Timer(TObject *Sender);
	void __fastcall tmr2Timer(TObject *Sender);
	void __fastcall btn1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall btnStopGameClick(TObject *Sender);
	void __fastcall btnStartGameClick(TObject *Sender);
	void __fastcall btnRestartClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall udpRobot2UDPRead(TIdUDPListenerThread *AThread,
		TBytes AData, TIdSocketHandle *ABinding);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall timerRobotHeartbeatTimer(TObject *Sender);
	void __fastcall addAlert(
		const char* lpszLv,
		const char* lpszIP,
		const char* lpszReason );
public:
	void updateStatus();
	void initAlertFilter(RegExEntryList& filter, _di_IXMLNode node);
	int detectAlert(AnsiString & msg, RegExEntryList& filter);
	// 0 - ok, else is errcode
	void serverAlert(bool alert);
	void robotAlert(bool alert);
	FILE* getLogFileHandle(ServiceObject* svcobj);
	// get log file pointer handle
	void writeLogMsg(ServiceObject* svcobj, AnsiString& msg);

	// User declarations
	RobotGroupList _robotGroups;

	GtrServer _server;
	int _serverport;
	int _robotport;
	int _rebotport2;
	int _offline_interval;
	int _buffer_lines;

    /**
    * chenlsh modified on 2010-04-06
	* 建立<IP-机器人>的映射
    */
	std::map<AnsiString, LPROBOTDATAMISC> _robotMap;

	/**
    * 完成端口服务器操作
	*/
	CIocpModeSvr m_server;
	TAlertForm* _alertForm;
public: // User declarations
	__fastcall TForm1(TComponent* Owner);

	LPROBOTDATAMISC GetRobotMiscByIP(const char* lpszIP);
	/**
    * 完成端口回调函数
	*/
	static void __stdcall ProcessRecvData(unsigned long sIP, SOCKET sClient,
	const char*pData, unsigned long DataLength);
};



// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
// ---------------------------------------------------------------------------
#endif
