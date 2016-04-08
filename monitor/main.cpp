/*
2010.1.6 zhangbin
1. 日志为每个ip单独存储一个文件
2. 添加启动游戏，停止游戏，重启机器的接口

 */
// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "LoggerImpl.h"
#include <XMLDoc.hpp>
#include <deque>
#include <iostream>
#include <algorithm>
#include <string>
#include<boost/regex.hpp>
#include <system.hpp>
#include <Dialogs.hpp>
#include <windows.h>
#include <time.h>
#include <ComObj.hpp>

#include <ice/ice.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "mutex.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IdBaseComponent"
#pragma link "IdComponent"
#pragma link "IdUDPBase"
#pragma link "IdUDPServer"
#pragma link "IdContext"
#pragma link "IdCustomTCPServer"
#pragma link "IdScheduler"
#pragma link "IdSchedulerOfThread"
#pragma link "IdSchedulerOfThreadPool"
#pragma link "IdTCPServer"
#pragma resource "*.dfm"

#ifdef _DEBUG
#pragma comment(lib, "iced.lib")
#pragma comment(lib, "iceutild.lib")
#else
#pragma comment(lib, "ice.lib")
#pragma comment(lib, "iceutil.lib")
#endif



TForm1 *Form1;

using namespace boost;
using namespace std;
// ---------------------------------------------------------------------------
#define WM_ROBOT_MONITOR	(WM_USER+1024)

//CRITICAL_SECTION g_cs;
DWORD WINAPI ThreadProc( LPVOID lpParameter );
swlib::Mutex mtx_db;
// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {

}

void TForm1::initAlertFilter(RegExEntryList& filter, _di_IXMLNode node) {
	_di_IXMLNodeList nodes = node->ChildNodes;
	int n;
	for (n = 0; n < nodes->Count; n++) {
		node = nodes->Nodes[n];
		if (node->GetNodeName() == "regex") {

			nodes = node->ChildNodes;
			for (n = 0; n < nodes->Count; n++) {
				node = nodes->Nodes[n]; // 匹配正则表达式<r/>
				RegExEntry rex;
				rex.exs = node->GetNodeValue();
				filter.push_back(rex);
			}
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender) {
	// using namespace std;
	/*
	regex expression("\\s+href\\s*=\\s*\"([^\"]*)\"",regbase::normal|regbase::icase);
	std::string ss="<a href=\"index.html\"><img src=\"logo.gif\"></a>";
	std::deque<std::string> result;
	regex_split(std::back_inserter(result),ss,expression);
	 */
	/*
	copy(result.begin(),result.end(),ostream_iterator<string>(cout,"\n"));
	int c;
	cin>>c;
	 */
//	LogServerI lpLogserver;
//	char* lpszRunInfo = "null";
//	lpLogserver.main(0, &lpszRunInfo, "config.server");
	//
	AnsiString s;
	s = Now().CurrentDate().DateString();
	// 初始化  系统参数

	AnsiString strBakLogIP;
	AnsiString strBakLogDB;
	AnsiString strBakLogUid;
	AnsiString strBakLogPw;

	WideString filename = "./monitor.xml";
	TXMLDocument* xmldoc = new TXMLDocument(this);
	xmldoc->FileName = filename;
	xmldoc->Active = true;
	_di_IXMLNode node = xmldoc->DocumentElement;
	_di_IXMLNodeList nodes = node->ChildNodes;
	int n;
	_server.ip = "server";
	System::MkDir(_server.ip);
	_server.logfile = _server.ip + "/" + Now().CurrentDate().DateString()
	+ ".log";
	// _server.fpstore = fopen( _server.logfile.c_str(),"a+");
	_server.fpstore = CreateFile(_server.logfile.c_str(), GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);
	for (n = 0; n < nodes->Count; n++) {
		node = nodes->Nodes[n];

		if (node->GetNodeName() == "server") {
			s = node->GetAttribute("port");
			_serverport = s.ToInt();
			this->udpServer->DefaultPort = _serverport;
			udpServer->Active = true;
			initAlertFilter(_server.filter, node);
		}
		else if (node->GetNodeName() == "robot") {
			_robotport = node->GetAttribute("port");
			/**
			 * chenlsh modified on 2010-03-17
			 * for IOCP server initializing
			 */
			m_server.Init(TForm1::ProcessRecvData, _robotport);
			_rebotport2 = node->GetAttribute("port2");
			udpRobot2->DefaultPort = _rebotport2;
			udpRobot2->Active = true;
		}
		else if (node->GetNodeName() == "bakLogServer") {
			/**
			 * chenlsh modified on 2010-03-17
			 * for IOCP server initializing
			 */
			strBakLogIP = node->GetAttribute("ip");
			strBakLogDB = node->GetAttribute("catalog");
			strBakLogUid = node->GetAttribute("userId");
			strBakLogPw = node->GetAttribute("pw");

		}
		else if (node->GetNodeName() == "offline_interval") {
			_offline_interval = node->GetNodeValue();
		}
		else if (node->GetNodeName() == "buffer_lines") {
			_buffer_lines = node->GetNodeValue();
		}

		///初始化设备清单
		if (node->GetNodeName() == "robots") {
			_di_IXMLNodeList nodelist;
			nodelist = node->GetChildNodes();
			int count = nodelist->GetCount();
			for (int m = 0; m < nodelist->GetCount(); m++) {
				node = nodelist->Nodes[m];
				if (node->GetNodeName() == "group") {
					RobotGroup group;
					int ii;
					group.name = node->GetAttribute("name");
					_di_IXMLNodeList node_robots;
					node_robots = node->GetChildNodes();
					for (ii = 0; ii < node_robots->GetCount(); ii++) {
						_di_IXMLNode nodeRobot;
						nodeRobot = node_robots->Nodes[ii];
						GtrRobot* lpRobot = new GtrRobot();
						if (nodeRobot->GetNodeName() == "robot") {
							lpRobot->name = nodeRobot->GetAttribute("name");
							lpRobot->ip = nodeRobot->GetAttribute("ip");
							if (nodeRobot->HasAttribute("gamepath")) {
								lpRobot->gamepath = nodeRobot->GetAttribute
								("gamepath");
							}
							else {
								ShowMessage
								("错误：游戏主机" + lpRobot->ip +
									"未定义游戏目录!");
								// return;
							}
							System::MkDir(lpRobot->ip);
							// if (robot.ip == "192.168.67.19") {
							// int x = 0;
							// }

							lpRobot->logfile = lpRobot->ip + "\\" + Now()
							.CurrentDate().DateString() + ".log";
							// nodeRobot->GetAttribute("logfile");
							// robot.fpstore = fopen(robot.logfile.c_str(),"a+");
							lpRobot->fpstore = CreateFile
							(lpRobot->logfile.c_str(), GENERIC_WRITE,
								FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
								OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
							initAlertFilter(lpRobot->filter, nodeRobot);
							// regular express <regex/>

							/**
							 * Chenlsh added 2010-03-26
							 * ip地址对应机器人
							 */
							group.robots.push_back(lpRobot);
							LPROBOTDATAMISC lpRobotDataMisc = new ROBOTDATAMISC;
							lpRobotDataMisc->lpRobot = lpRobot;
							_robotMap.insert(std::map<AnsiString,
								LPROBOTDATAMISC>::value_type(lpRobot->ip,
									lpRobotDataMisc));
						}
					}
					_robotGroups.push_back(group);
				}
			}
		}
	}
	TTreeNode * treeroot = treeRobotGroup->Items->GetFirstNode();
	for (int n = 0; n < _robotGroups.size(); n++) {
		TTreeNode * newnode = treeRobotGroup->Items->AddChild(treeroot,
			_robotGroups[n].name); // _robotGroups
		newnode->Data = (void*) & _robotGroups[n];
	}

	/// Timer open
	timerStatus->Enabled = true;

	/**
	* 开启ICE LogServer
	*/
	DWORD dwThreadID = 0;
	CloseHandle( CreateThread(NULL, 0,ThreadProc, NULL, 0, &dwThreadID) );

	/**
	 * 定义数据库相关属性
	 */
	WideString strConn =
	"Provider=SQLOLEDB.1;Persist Security Info=False;User ID=";
	strConn += strBakLogUid;
	strConn += ";Password=";
	strConn += strBakLogPw;
	strConn += ";Initial Catalog=";
	strConn += strBakLogDB;
	strConn += ";Data Source=";
	strConn += strBakLogIP;

	this->_lpAdoConn->ConnectionString = strConn;
	this->_lpAdoConn->ConnectionTimeout = 30;
	this->_lpAdoConn->Connected = true;

  //	this->_alertForm = new TAlertForm(this);

  //  this->_alertForm->Show();

	/**
	 * 使用数据库时的互斥量初始化
	 */

	//InitializeCriticalSection(&g_cs);

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::treeRobotGroupChange(TObject *Sender, TTreeNode *Node) {
	//
	RobotGroup* group = (RobotGroup*)Node->Data;
	int n;
	if (group == NULL) {
		return;
	}
	lsRobot->Clear();
	TListItem * item;

	for (n = 0; n < group->robots.size(); n++) {
		// item = new TListItem(lsRobot->Items);
		item = lsRobot->Items->Add();

		GtrRobot* lpRobot = group->robots[n];
		assert(lpRobot);
		item->Caption = lpRobot->ip; // group->robots[n].ip;
		// lsRobot->Items->AddItem(item,0);
		item->Data = (void*)group->robots[n];
	}
	updateStatus();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::lsRobotChange(TObject *Sender, TListItem *Item,
	TItemChange Change) {
	//
	if (Item == NULL)
		return;
	memoRobot->Lines->Clear();
	GtrRobot * robot = (GtrRobot*)Item->Data;
	if (robot == NULL) {
		return;
	}
	int n;
	LogMessageList::iterator itr;
	for (itr = robot->logs.begin(); itr != robot->logs.end(); itr++) {
		memoRobot->Lines->Insert(0, itr->msg);
	}

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::btnClearClick(TObject *Sender) {
	memoRobot->Lines->Clear();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::udpServerUDPRead(TIdUDPListenerThread *AThread,
	TBytes AData, TIdSocketHandle *ABinding) {
	//
	// AnsiString msg;
	std::vector<char>msg;
	msg.resize(AData.Length + 1);
	int n;
	for (n = 0; n < AData.Length; n++) {
		msg[n] = (char)AData[n];
	}
	msg[msg.size() - 1] = 0;
	AnsiString line;
	line = (char*) & msg[0];
	line = Now().DateTimeString() + " " + line; // .TimeString() + " " + line;

	if (memoServer->Lines->Count > 200) {
		memoServer->Clear();
	}

	this->memoServer->Lines->Insert(0, line);

	writeLogMsg(&_server, line);

	_server.updatTime = time(0);
	// 检测报警状态
	if (detectAlert(line, _server.filter) != 0) {
		// 符合报警状态
		// serverAlert(true);
		_server.alarming = true;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::udpRobotUDPRead(TIdUDPListenerThread *AThread,
	TBytes AData, TIdSocketHandle *ABinding) {
	// AnsiString msg;

#if 0
	std::vector<char>msg;
	msg.resize(AData.Length + 1);
	int n;
	for (n = 0; n < AData.Length; n++) {
		msg[n] = (char)AData[n];
	}
	msg[msg.size() - 1] = 0;
	AnsiString line;
	line = (char*) & msg[0];
	line = Now().DateTimeString() + " " + line; // .TimeString() + " " + line;

	if (memoRobot->Lines->Count > 200) {
		// memoServer->Lines->Delete(memoServer->Lines->Count-1);
		memoRobot->Clear();
	}

	// 判别是否是当前选择的机器人
	TListItem* item;
	for (int n = 0; n < this->lsRobot->Items->Count; n++) {
		item = lsRobot->Items->Item[n];
		if (item->Selected) {
			GtrRobot* robot = (GtrRobot*)item->Data;
			if (robot->ip == ABinding->PeerIP) {
				this->memoRobot->Lines->Insert(0, line);
			}
		}
	}

	///
	int g;
	for (g = 0; g < _robotGroups.size(); g++) {
		int r;
		int size;
		size = _robotGroups[g].robots.size();
		for (r = 0; r < _robotGroups[g].robots.size(); r++) {
			GtrRobot& robot = _robotGroups[g].robots[r];
			AnsiString ip = ABinding->PeerIP;

			if (robot.ip == ABinding->PeerIP) { // 将消息分派到不同的日志文件存储
				robot.updatTime = time(0);
				LogMessageT msg;
				msg.msg = line;
				robot.logs.push_front(msg); // 缓冲记录为了切换时的消息显示，将最新的消息插入头部
				if (robot.logs.size() > _buffer_lines) {
					robot.logs.pop_back();
				}
				writeLogMsg(&robot, line);

				if (detectAlert(line, robot.filter) != 0) {
					// 符合报警状态
					// robotAlert(true);
					robot.alarming = true;
				}
				goto END;
			}
		}
	}
END:
	// reflash listview
	updateStatus();
	/*
	TListItem * item;
	for(n=0 ;n<this->lsRobot->Items->Count;n++){
	item = lsRobot->Items->Item[n];
	GtrRobot* robot = (GtrRobot*) item->Data;
	if( (time(0) - robot->updatTime) > this->_offline_interval){
	item->ImageIndex = 1;
	}else{
	item->ImageIndex = 0;
	}
	} */

	std::map<AnsiString, DWORD>::iterator it = _threadMap.find
		(ABinding->PeerIP);
	if (it != _threadMap.end()) {
		TBytes* lpcbData = new TBytes(AData);
		PostThreadMessage(it->second, WM_ROBOT_MONITOR, (WPARAM)lpcbData, 0);
	}
	else {
		/**
		 * 针对每个IP地址创建一个线程
		 */
		AnsiString* lpStrAddr = new AnsiString(ABinding->PeerIP);
		DWORD dwThreadId = 0;
		CloseHandle(CreateThread(NULL, 0, ThreadProc, (LPVOID)lpStrAddr, 0,
				&dwThreadId));

		_threadMap.insert(std::map<AnsiString, DWORD>::value_type(*lpStrAddr,
				dwThreadId));
		TBytes* lpcbData = new TBytes(AData);
		if (WaitForSingleObject(g_eCanSend, 200) == WAIT_OBJECT_0) {
			PostThreadMessage(dwThreadId, WM_ROBOT_MONITOR, 0, 0);
			PostThreadMessage(dwThreadId, WM_ROBOT_MONITOR, (WPARAM)lpcbData,
				0);
		}
		else {
			/**
			 * 线程创建了半天都没初始化完，麻烦
			 */
			Sleep(5);
			PostThreadMessage(dwThreadId, WM_ROBOT_MONITOR, 0, 0);
			PostThreadMessage(dwThreadId, WM_ROBOT_MONITOR, (WPARAM)lpcbData,
				0);
		}

	}
#endif
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	memoServer->Lines->Clear();
}
// ---------------------------------------------------------------------------

void TForm1::updateStatus() {
	TListItem * item;
	// 服务器超时离线
	if (time(0) - _server.updatTime > this->_offline_interval) {
		_server.alarming = true;
		//
	}
	if (_server.alarming) {
		serverAlert(true);
	}

	int n, k;
	bool roboterror = false;
	for (n = 0; n < _robotGroups.size(); n++) {
		for (k = 0; k < _robotGroups[n].robots.size(); k++) {
			if (time(0) - _robotGroups[n].robots[k]
				->updatTime > this->_offline_interval) {
				_robotGroups[n].robots[k]->alarming = true;
			}
			if (_robotGroups[n].robots[k]->alarming) {
				roboterror = true;
			}
		}
	}

	for (int n = 0; n < this->lsRobot->Items->Count; n++) {
		item = lsRobot->Items->Item[n];
		GtrRobot* robot = (GtrRobot*)item->Data;
		if (robot->alarming) {
			item->ImageIndex = 1;
		}
		else {
			item->ImageIndex = 0;
		}
	}
	if (roboterror) {
		return robotAlert(true);
	}
}

void __fastcall TForm1::timerStatusTimer(TObject *Sender) {
	updateStatus();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::N5Click(TObject *Sender) {
	AnsiString msg =
		"2009.12.24 zhangbin \n" "1.添加清除报警和报警提示\n"
		"2.每天产生一个新的日志文件\n" "3.添加正则表达式支持来检测报警状态\n"
		"4.版本升v0.2.0\n" "--------------------------------------\n"
		"2010.1.7 zhangbin v0.2.1\n" "1.设置信息输出最大记录数为200条，自动清除防止进行过高负荷？？\n"
		"2.增加启动、停止、重启机器接口,需外部创建endgame.bat,startgame.bat,restarthost.bat\n"
		"2010.1.27 v0.2.2\n" "1.增加第二个robot监听端口，用于接收日志服务程序处理之后的日志信息;\n"
		"bcb有50个文件打开数量的限制";

	ShowMessage(msg);
}

// ---------------------------------------------------------------------------
// 检测正则表达式条件是否符合报警
// 0 - 无报警
int TForm1::detectAlert(AnsiString & msg, RegExEntryList& filter) {
	int n;
	for (n = 0; n < filter.size(); n++) {
		regex e(filter[n].exs.c_str());
		if (regex_search(msg.c_str(), e)) {
			return 1;
		}
	}
	return 0;
}

void TForm1::serverAlert(bool alert) {
	if (alert) {
		// memoServer->Color= clRed ;
		tmr1->Enabled = true;
	}
	else {
		tmr1->Enabled = false;
		memoServer->Color = clWindow;
		// memoServer->Color = clWindow;
	}
}

void TForm1::robotAlert(bool alert) {
	if (alert) {
		tmr2->Enabled = true;
		// memoRobot->Color= clRed ;
	}
	else {
		tmr2->Enabled = false;
		// memoRobot->Color = clWindow;
		memoRobot->Color = clWindow;
		treeRobotGroup->Color = clWindow;
		lsRobot->Color = clWindow;
	}
}

// 服务器提示
void __fastcall TForm1::tmr1Timer(TObject *Sender) {
	static bool alert = true;

	if (alert) {
		memoServer->Color = clRed;
	}
	else {
		memoServer->Color = clWindow;
	}
	alert = !alert;
}

// ---------------------------------------------------------------------------
// 机器提示
void __fastcall TForm1::tmr2Timer(TObject *Sender) {
	static bool alert = true;

	if (alert) {
		memoRobot->Color = clRed;
		treeRobotGroup->Color = clRed;
		lsRobot->Color = clRed;
	}
	else {
		memoRobot->Color = clWindow;
		treeRobotGroup->Color = clWindow;
		lsRobot->Color = clWindow;
	}
	alert = !alert;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::btn1Click(TObject *Sender) {
	robotAlert(false);
	// lsRobot->SelCount
	TListItem * item;
	for (int n = 0; n < this->lsRobot->Items->Count; n++) {
		item = lsRobot->Items->Item[n];
		if (item->Selected) {
			GtrRobot* robot = (GtrRobot*)item->Data;
			if (robot->alarming) {
				robot->alarming = 0;
			}
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) {
	_server.alarming = false;
	serverAlert(false);
}
// ---------------------------------------------------------------------------

FILE* TForm1::getLogFileHandle(ServiceObject* svcobj) {
	return NULL;
}

void TForm1::writeLogMsg(ServiceObject* svcobj, AnsiString& msg) {
	// 切换时间存储
	AnsiString newlog;
	newlog = svcobj->ip + "/" + Now().CurrentDate().DateString() + ".log";
	if (svcobj->logfile != newlog) {
		// fclose(svcobj->fpstore);
		CloseHandle(svcobj->fpstore);
		svcobj->logfile = newlog;
		// svcobj->fpstore = fopen( svcobj->logfile.c_str(),"a+");
		svcobj->fpstore = CreateFile(svcobj->logfile.c_str(), GENERIC_WRITE,
			FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS,
			FILE_ATTRIBUTE_NORMAL, NULL);
	}
	DWORD writen;
	// fwrite(msg.c_str(),msg.Length(),1, svcobj->fpstore);
	msg += "\r\n";
	WriteFile(svcobj->fpstore, msg.c_str(), msg.Length(), &writen, NULL);

	// fwrite("\n",strlen("\n"),1,svcobj->fpstore);
	// WriteFile(svcobj->fpstore, "\r\n", strlen("\r\n"), &writen, NULL);
	// fflush(svcobj->fpstore);
	FlushFileBuffers(svcobj->fpstore);
}

void __fastcall TForm1::Button6Click(TObject *Sender) {
	memoSystem->Lines->Clear();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::btnStopGameClick(TObject *Sender) {
	// 停止游戏
	char psBuffer[128];
	FILE *pPipe;
	AnsiString cmd;
	TListItem * item;

	// PageControl1->ActivePage =  TabSheet2;
	if (lsRobot->SelCount == 0) {
		ShowMessage("请选择游戏主机!");
		return;
	}
	if (MessageDlg("确定【停止】游戏吗?", mtConfirmation,
			TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo) {
		return;
	}
	for (int n = 0; n < this->lsRobot->Items->Count; n++) {
		item = lsRobot->Items->Item[n];
		if (item->Selected) {
			GtrRobot* robot = (GtrRobot*)item->Data;
			cmd = "endgame.bat " + robot->ip + " " + robot->gamepath;
			system(cmd.c_str());
			// cmd = "dir" ;
			// if( (pPipe = popen( "dir", "r" )) ){
			// while(fgets(psBuffer, 128, pPipe)){
			// AnsiString s =psBuffer;
			// s += "\n";
			// memoSystem->Lines->Add(s);
			// }
			// fclose(pPipe);
			// }
		}
	}

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::btnStartGameClick(TObject *Sender) {
	char psBuffer[128];
	FILE *pPipe;
	AnsiString cmd;
	TListItem * item;
	if (lsRobot->SelCount == 0) {
		ShowMessage("请选择游戏主机!");
		return;
	}
	if (MessageDlg("确定【启动】游戏吗?", mtConfirmation,
			TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo) {
		return;
	}
	// PageControl1->ActivePage =  TabSheet2;
	for (int n = 0; n < this->lsRobot->Items->Count; n++) {
		item = lsRobot->Items->Item[n];
		if (item->Selected) {
			GtrRobot* robot = (GtrRobot*)item->Data;
			cmd = "startgame.bat " + robot->ip + " " + robot->gamepath;
			system(cmd.c_str());
			// if( (pPipe = _popen( cmd.c_str(), "rt" )) ){
			// while(fgets(psBuffer, 128, pPipe)){
			// AnsiString s =psBuffer;
			// s += "\n";
			// memoSystem->Lines->Add(s);
			// }
			// fclose(pPipe);
			// }
		}
	}

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::btnRestartClick(TObject *Sender) {
	char psBuffer[128];
	FILE *pPipe;
	AnsiString cmd;
	TListItem * item;
	if (lsRobot->SelCount == 0) {
		ShowMessage("请选择游戏主机!");
		return;
	}
	if (MessageDlg("确定【重启游戏主机】吗？", mtConfirmation,
			TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo) {
		return;
	}
	// PageControl1->ActivePage =  TabSheet2;
	for (int n = 0; n < this->lsRobot->Items->Count; n++) {
		item = lsRobot->Items->Item[n];
		if (item->Selected) {
			GtrRobot* robot = (GtrRobot*)item->Data;
			cmd = "restarthost.bat " + robot->ip;
			system(cmd.c_str());

			// if( (pPipe = _popen( cmd.c_str(), "rt" )) ){
			// while(fgets(psBuffer, 128, pPipe)){
			// AnsiString s =psBuffer;
			// s += "\n";
			// memoSystem->Lines->Add(s);
			// }
			// fclose(pPipe);
			// }
		}
	}

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action) {

	/**
	 * 由于退出时不要求严格的资源回收和状态检测
	 * 故没有用进行一些资源的释放
	 */
	Sleep(1000);
	udpServer->Active = false;
	m_server.UnInit();
	// udpRobot->Active = false;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender) {

	char psBuffer[128];
	FILE *pPipe;
	AnsiString cmd;
	TListItem * item;
	if (lsRobot->SelCount == 0) {
		ShowMessage("请选择游戏主机!");
		return;
	}
	if (MessageDlg("确定【重启游戏主机】吗？", mtConfirmation,
			TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo) {
		return;
	}
	// PageControl1->ActivePage =  TabSheet2;
	for (int n = 0; n < this->lsRobot->Items->Count; n++) {
		item = lsRobot->Items->Item[n];
		if (item->Selected) {
			GtrRobot* robot = (GtrRobot*)item->Data;
			cmd = "execute.bat " + robot->ip;
			system(cmd.c_str());

			// if( (pPipe = _popen( cmd.c_str(), "rt" )) ){
			// while(fgets(psBuffer, 128, pPipe)){
			// AnsiString s =psBuffer;
			// s += "\n";
			// memoSystem->Lines->Add(s);
			// }
			// fclose(pPipe);
			// }
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::udpRobot2UDPRead(TIdUDPListenerThread *AThread,
	TBytes AData, TIdSocketHandle *ABinding) {
	//
	std::vector<char>msg;
	msg.resize(AData.Length + 1);
	int n;
	for (n = 0; n < AData.Length; n++) {
		msg[n] = (char)AData[n];
	}
	msg[msg.size() - 1] = 0;
	AnsiString line;
	line = (char*) & msg[0];
	char* token = strtok(line.c_str(), ",");
	std::vector<std::string>linelist;
	while (token) {
		linelist.push_back(token);
		token = strtok(NULL, ",");
	}
	if (linelist.size() != 3 || linelist[0] != "GRL") {
		return;
	}
	// AnsiString ip = linelist[1];
	/////////////////////////////////
	// base64 decode
	size_t size;
	char * buff;
	if (!base64_decode_alloc(linelist[2].c_str(), linelist[2].size(), &buff,
			&size)) {
		return;
	}
	linelist[2].assign(buff, size);
	free(buff);
	///////////////////////////

	line = linelist[2].c_str();

	line = Now().DateTimeString() + " " + line; // .TimeString() + " " + line;

	if (memoRobot->Lines->Count > 200) {
		// memoServer->Lines->Delete(memoServer->Lines->Count-1);
		memoRobot->Clear();
	}

	// 判别是否是当前选择的机器人
	TListItem* item;
	for (int n = 0; n < this->lsRobot->Items->Count; n++) {
		item = lsRobot->Items->Item[n];
		if (item->Selected) {
			GtrRobot* robot = (GtrRobot*)item->Data;
			if (robot->ip == linelist[1].c_str()) {
				this->memoRobot->Lines->Insert(0, line);
			}
		}
	}

	///
	int g;
	for (g = 0; g < _robotGroups.size(); g++) {
		int r;
		int size;
		size = _robotGroups[g].robots.size();
		for (r = 0; r < _robotGroups[g].robots.size(); r++) {
			GtrRobot* lpRobot = _robotGroups[g].robots[r];
			assert(lpRobot);
			// AnsiString ip =ABinding->PeerIP;

			if (lpRobot->ip == linelist[1].c_str()) { // 将消息分派到不同的日志文件存储
				lpRobot->updatTime = time(0);
				LogMessageT msg;
				msg.msg = line;
				lpRobot->logs.push_front(msg); // 缓冲记录为了切换时的消息显示，将最新的消息插入头部
				if (lpRobot->logs.size() > _buffer_lines) {
					lpRobot->logs.pop_back();
				}
				writeLogMsg(lpRobot, line);

				if (detectAlert(line, lpRobot->filter) != 0) {
					// 符合报警状态
					// robotAlert(true);
					lpRobot->alarming = true;
				}
				goto END;
			}
		}
	}
END:
	// reflash listview
	updateStatus();

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::N3Click(TObject *Sender) {
	Close();
}
// ---------------------------------------------------------------------------

int DoInsertBusPkgOperation(LogGameMessageT*  msg) {
    swlib::ScopeLocker l(mtx_db);
	if( msg->type != LogGameDetailT::GAME_MSG_DETAIL){
		return 0;
	} 
	LogGameDetailT* msgdetail = (LogGameDetailT*) msg;
		
	unsigned int uTimeFix = msgdetail->timetick; //busInfo.uTimeElapsed + 8 * 3600;

	std::string strInsertText;
	strInsertText = "INSERT INTO "
					"GRL_UNKNOWN([no], [gameid], [detail], [ip], [time], [type]) ";
	strInsertText += "VALUES('" + msgdetail->no + "',";
	strInsertText += "'" + msgdetail->gameId + "',";
	strInsertText += ":detail,";

	strInsertText += " '" + msgdetail->ip + "',";
	char szBuf[64];
	sprintf_s(szBuf, sizeof(szBuf), "%u", uTimeFix);
	strInsertText += "dateadd(ss,";
	strInsertText += szBuf;
	strInsertText += ",'1970-01-01 08:00:00'), 0)";


	/**
	 * 对数据库的操作进行保护
	 */
	//EnterCriticalSection(&g_cs);
	try {
		Form1->_lpAdoQuery->SQL->Text = strInsertText.c_str();
		Form1->_lpAdoQuery->Parameters->ParamByName("detail")->DataType = ftString;
		//Form1->_lpAdoQuery->Parameters->ParamByName("detail")->Size = busInfo.lpBusPkg->strDetail.size();
		//Form1->_lpAdoQuery->Parameters->ParamByName("detail")->Value = busInfo.lpBusPkg->strDetail.c_str();
		Form1->_lpAdoQuery->Parameters->ParamByName("detail")->Size = msgdetail->detail.size();
		Form1->_lpAdoQuery->Parameters->ParamByName("detail")->Value = msgdetail->detail.c_str();

		Form1->_lpAdoQuery->ExecSQL();
	}
	catch(EOleException & e) {
		// MessageBox(GetDesktopWindow(), AnsiString(e.ToString()).c_str(), "", 0);
		if (e.ErrorCode == 0x80004005) {
			AnsiString strErrMsg = Now().DateTimeString()
				+ " " + msgdetail->ip.c_str() + " 连接数据库失败...尝试重连";
			Form1->memoRobot->Lines->Insert(0, strErrMsg);
			try {
				Form1->_lpAdoConn->Connected = false;
				Form1->_lpAdoConn->Connected = true;
				strErrMsg = Now().DateTimeString()
					+ " " + msgdetail->ip.c_str() + " 重连成功";
				Form1->memoRobot->Lines->Insert(0, strErrMsg);

			}
			catch(Exception & e) {
				strErrMsg = Now().DateTimeString()
					+ " " + msgdetail->ip.c_str() + " 重连失败";
				Form1->memoRobot->Lines->Insert(0, strErrMsg);
			}
		}
		else {
			AnsiString strErrMsg = Now().DateTimeString()
				+ " " + msgdetail->ip.c_str()
				+ " 数据库错误: " + e.ToString();
			Form1->memoRobot->Lines->Insert(0, strErrMsg);
		}

	}

   //	LeaveCriticalSection(&g_cs);

	return 0;
}


/*
int DoInsertBusPkgWithImageOperation(const BUSINESS_INFO & busInfo,
	unsigned char* lpData, int nSize) {
	assert(busInfo.lpBusPkg && lpData && nSize > 0);

	unsigned int uTimeFix = busInfo.uTimeElapsed + 8 * 3600;

	std::string strInsertText;
	strInsertText = "INSERT INTO ";
	// strInsertText += "GRL_UNKNOWN([no], [gameid], [detail], [ip], [time], [type], [image]) ";
	//strInsertText +="tBakLog([no], [gameid], [detail], [ip], [time], [type], [image]) ";
	strInsertText +="GRL_UNKNOWN([no], [gameid], [detail], [ip], [time], [type], [image]) ";
	strInsertText += "VALUES('" + busInfo.lpBusPkg->strOrderId + "',";
	strInsertText += "'" + busInfo.lpBusPkg->strGameId + "',";
	strInsertText += ":detail,";

	strInsertText += " '" + busInfo.lpBusPkg->strIP + "',";
	char szBuf[64] = {
		0
	};
	int nGid = atoi(busInfo.lpBusPkg->strGameId.c_str());
	sprintf_s(szBuf, sizeof(szBuf), "%u", uTimeFix);
	strInsertText += "dateadd(ss,";
	strInsertText += szBuf;
	strInsertText += ",'1970-01-01 00:00:00')";
	strInsertText += ",1";
	strInsertText += ", :image";
	strInsertText += ")";

	EnterCriticalSection(&g_cs);
	TMemoryStream* lpMs = new TMemoryStream();
	try {

		lpMs->WriteBuffer(lpData, nSize);
		Form1->_lpAdoQuery->SQL->Text = strInsertText.c_str();
		Form1->_lpAdoQuery->Parameters->ParamByName("detail")
			->DataType = ftString;
		Form1->_lpAdoQuery->Parameters->ParamByName("detail")
			->Size = busInfo.lpBusPkg->strDetail.size();
		Form1->_lpAdoQuery->Parameters->ParamByName("detail")
			->Value = busInfo.lpBusPkg->strDetail.c_str();
		Form1->_lpAdoQuery->Parameters->ParamByName("image")->LoadFromStream
			(lpMs, ftBlob);
		Form1->_lpAdoQuery->ExecSQL();
	}
	catch(EOleException & e) {
		// MessageBox(GetDesktopWindow(), AnsiString(e.ToString()).c_str(), "", 0);
		if (e.ErrorCode == 0x80004005) {
			AnsiString strErrMsg = Now().DateTimeString()
				+ " " + busInfo.lpBusPkg->strIP.c_str() + " 连接数据库失败...尝试重连";
			Form1->memoRobot->Lines->Insert(0, strErrMsg);
			try {
				Form1->_lpAdoConn->Connected = false;
				Form1->_lpAdoConn->Connected = true;
				strErrMsg = Now().DateTimeString()
					+ " " + busInfo.lpBusPkg->strIP.c_str() + " 重连成功";
				Form1->memoRobot->Lines->Insert(0, strErrMsg);
				Form1->_lpAdoQuery->ExecSQL();
			}
			catch(Exception & e) {
				strErrMsg = Now().DateTimeString()
					+ " " + busInfo.lpBusPkg->strIP.c_str() + " 重连失败";
				Form1->memoRobot->Lines->Insert(0, strErrMsg);
			}
		}
		else {
			AnsiString strErrMsg = Now().DateTimeString()
				+ " " + busInfo.lpBusPkg->strIP.c_str()
				+ " 数据库错误: " + e.ToString();
			Form1->memoRobot->Lines->Insert(0, strErrMsg);
		}

	}

	delete lpMs;
	LeaveCriticalSection(&g_cs);

	return 0;

}

*/

LPROBOTDATAMISC TForm1::GetRobotMiscByIP(const char* lpszIP) {

	if (!lpszIP) {
		return NULL;
	}

	std::map<AnsiString, LPROBOTDATAMISC>::iterator it;

	it = _robotMap.find(lpszIP);

	LPROBOTDATAMISC lpRobotDataMisc = NULL;
	if (it != _robotMap.end()) {
		lpRobotDataMisc = it->second;
	}

	return lpRobotDataMisc;
}

void __stdcall TForm1::ProcessRecvData(unsigned long sIP, SOCKET sClient,
	const char* pData, unsigned long DataLength) {
	TForm1* lpOwner = Form1;
	if( DataLength <= 0){
		return;	
	}	

	std::string strIP = inet_ntoa(*(in_addr*)(&sIP));

	LPROBOTDATAMISC lpRobotDataMisc = lpOwner->GetRobotMiscByIP(strIP.c_str());
	if ( !lpRobotDataMisc || !lpRobotDataMisc->lpRobot ) {
		return ;
	}
	GtrRobot* lpRobot = lpRobotDataMisc->lpRobot;
	lpRobotDataMisc->queueIn((unsigned char*)pData,DataLength);
	std::vector<LogPacketT*> packets = lpRobotDataMisc->getPackets();
	int n;

	for(n=0;n<packets.size();n++){
		LogGameMessageT* msg; 
		msg = packets[n]->getMessage();
		if( msg == NULL){
			continue;
		}

		DoLogMessage(msg, lpRobot);			
		//CoInitializeEx(NULL, 0);
		DoInsertBusPkgOperation(msg);
		//CoUninitialize();
		delete msg;
		delete packets[n];
	}
}

int DoLogMessage(LogGameMessageT*  msg,GtrRobot* lpRobot) {
	TForm1* lpOwner = Form1;
	if( msg->type != LogGameDetailT::GAME_MSG_DETAIL){
		return 0;
	}
	LogGameDetailT * detail =(LogGameDetailT*)msg;
	
	AnsiString line = " [单号] ";

	//line += busInfo.lpBusPkg->strOrderId.c_str();
	line += detail->no.c_str();	

	line += " [时间] ";
//	tm* lpStTime = localtime((const long*) & (busInfo.uTimeElapsed));
	tm* lpStTime = localtime((const long*) & (detail->timetick));
	char szTime[64] ;
	strftime(szTime, sizeof(szTime), "%Y-%m-%d %H:%M:%S", lpStTime);
	line += szTime;


	line += " [操作] ";
//	line += busInfo.lpBusPkg->strDetail.c_str();
	line += detail->detail.c_str();

	line = Now().DateTimeString() + " " + line;
	if (lpOwner->memoRobot->Lines->Count > 200) {
		// memoServer->Lines->Delete(memoServer->Lines->Count-1);
		lpOwner->memoRobot->Clear();
	}

	// 判别是否是当前选择的机器人
	TListItem* item;
	for (int n = 0; n < lpOwner->lsRobot->Items->Count; n++) {
		item = lpOwner->lsRobot->Items->Item[n];
		if (item->Selected) {
			GtrRobot* robot = (GtrRobot*)item->Data;
			if (robot->ip == detail->ip.c_str()) {
				lpOwner->memoRobot->Lines->Insert(0, line);
			}
		}
	}

	lpRobot->updatTime = time(0);
	LogMessageT lmsg;
	lmsg.msg = line;
	lpRobot->logs.push_front(lmsg);
	// 缓冲记录为了切换时的消息显示，将最新的消息插入头部
	if (lpRobot->logs.size() > lpOwner->_buffer_lines) {
		lpRobot->logs.pop_back();
	}
	lpOwner->writeLogMsg(lpRobot, line);
	if (lpOwner->detectAlert(line, lpRobot->filter) != 0) {
		// 符合报警状态
		// robotAlert(true);
		lpRobot->alarming = true;
	}
	return 0;
}


Ice::CommunicatorPtr communicator;
DWORD WINAPI ThreadProc( LPVOID lpParameter ){
  //	return 0;
/*
	LogServerI lpLogserver;
	char* lpszRunInfo = "null";
	lpLogserver.main(0, &lpszRunInfo, "config.server");
	return 0;
	*/
	char *argv[]={"this","--Ice.Config=config.server"};
	int argc =2;
    communicator = Ice::initialize(argc, argv);
    Ice::ObjectAdapterPtr adapter = communicator->createObjectAdapter(
							"LogServer");
	gtr::ILoggerPtr spLogger = new LoggerImpl;
	adapter->add(spLogger, communicator->stringToIdentity("logserver"));
	adapter->activate();
	try{
		communicator->waitForShutdown();
	}catch(...){
		int x=100;
	}

}


void __fastcall TForm1::timerRobotHeartbeatTimer(TObject *Sender)
{
   /*
	const unsigned int uTimeoutValue = 15000;
	std::map<AnsiString, LPROBOTDATAMISC>::iterator it = _robotMap.begin();
	while( it != _robotMap.end() ){
		AnsiString strIP = it->first;
		LPROBOTDATAMISC lpRobotMisc = it->second;
		if ( lpRobotMisc ) {
			unsigned int uTick = GetTickCount();
			if ( lpRobotMisc->uHeartbeat > 0 && (uTick - lpRobotMisc->uHeartbeat) > uTimeoutValue ) {
				addAlert("1", lpRobotMisc->lpRobot->ip.c_str(), "心跳超时");
				lpRobotMisc->uHeartbeat = 0;
			}
		}
		++it;
	}*/
}
//---------------------------------------------------------------------------
void __fastcall TForm1::addAlert(
		const char* lpszLv,
		const char* lpszIP,
		const char* lpszReason )  {

	TListItem* lpItem = this->_alertForm->_alertList->Items->Add();
	lpItem->SubItems->Add(lpszLv);

	lpItem->SubItems->Add(lpszIP);
	lpItem->SubItems->Add(lpszReason);

}

//--------------------------------------------------
void ROBOTDATAMISC::reset(){
	buffer.clear();
}

std::vector<LogPacketT*>  ROBOTDATAMISC::getPackets(){
	std::vector<LogPacketT*>  logpacklist;
	unsigned char * p,*p1,*p2;
	p1 = p = & buffer[0];
	std::vector<std::string> packlist;
	char * nexttok = NULL;
	unsigned int slmax = 1024*8;
	char* tok;

	while ( p< &buffer[buffer.size()]){
		if( *p=='\0'){
			if( *p1!='\0'){
				packlist.push_back((const char*)p1);
				p1 = p+1;
			}
		}
		p++;
	}
/*
	char* tok = strtok_s((char*)&buffer[0],&slmax,"\0",&nexttok);
	while(tok){
		packlist.push_back(tok);
		tok = strtok_s(NULL,&slmax,"\0",&nexttok);
	}*/
	char  endc = 'A';
	if(buffer.size()){
		endc = buffer[buffer.size()-1] ;
	}
	buffer.clear();
	
	if( packlist.size() ){		
		if( endc!=0 ){ //非完整包结尾，扔回队列
			std::string ends = packlist[packlist.size()-1];
			buffer.resize(ends.size());
//			buffer.assign( (unsigned char*)ends.c_str(),ends.size());
            memcpy(&buffer[0],ends.c_str(),ends.size());
			packlist.pop_back();
		}
		//开始将解析每个数据包
		for(int n=0;n<packlist.size();n++){
			std::vector<std::string> fields;
			tok = strtok_s((char*)&packlist[n][0],&slmax,",",&nexttok);
			while(tok){		
				fields.push_back(tok);
				tok = strtok_s(NULL,&slmax,",",&nexttok);
			}
			if(fields.size() < 5){
				continue;
			}
			LogPacketT * packet = new (LogPacketT);
			std::vector<std::string>::iterator itr;
			itr = fields.begin();
			std::advance(itr,5);
			packet->body.assign(itr,fields.end());
			logpacklist.push_back(packet);
			/*
			if( fields[5]=="0"){ //游戏日志信息
				if( fields.size()< 11 ){
					continue;
				}
				
			}*/
		}
	}

	return logpacklist;
	
}


void base64_decode_field(std::string& field){
	size_t size;
	char * buff;
	if (!base64_decode_alloc(field.c_str(), field.size(), &buff,&size)) {
		return;
	}
	field.assign(buff, size);
	free(buff);
}

LogGameMessageT* LogPacketT::getMessage(){
	LogGameMessageT* msg = NULL;
	if(body.size() ==0){
		return NULL;
	}
	std::for_each(body.begin(),body.end(),base64_decode_field);
	if( body[0] == "0"){
		if(body.size()< 6){
			return NULL;
		}
		LogGameDetailT* gamedetail = new LogGameDetailT;
		gamedetail->no = body[1];
		gamedetail->gameId = body[2];
		gamedetail->ip = body[3];
		gamedetail->timetick = atoi(body[4].c_str());
		gamedetail->detail = body[5];
		msg = gamedetail;
	}
	return msg;
}

void ROBOTDATAMISC::queueIn(unsigned char * data ,size_t size){
	size_t oldsize;
	oldsize = buffer.size();
	buffer.resize(buffer.size()+size);
	size_t newsize = buffer.size();
	memcpy( &buffer[oldsize],data,size);	
}




