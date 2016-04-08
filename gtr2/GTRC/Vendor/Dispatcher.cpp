#include "StdAfx.h"
#include "Dispatcher.h"
#include "communicator.h"
#include "MessageManager.h"
#include <assert.h>
#include <sstream>
#include "markup.h"
#include "gtrc.h"
#include "HostService.h"
#include <fstream>
using namespace std;
using namespace client;

Dispatcher Dispatcher::_dispatcher;
Vendor* Dispatcher::_vendor = NULL;
extern void showlog(string msg);
extern void showmsg(string msg);


ServerGtCommunicator _comm;

Dispatcher::Dispatcher(void)
{
	//_server.ip= std::string("192.168.133.54");
	//_server.port = 12000;
	_bBusy = false;
	InitializeCriticalSection(&_cs);

}

Dispatcher::Dispatcher(const Dispatcher& disp)
{
	assert(false);
	delete this;
}

Dispatcher::~Dispatcher(void)
{
	assert(_vendors.empty());
}

struct gmp
{
	int id;
	const char* sid;
	const char* sname;
} ;

struct gmp _games[6] = 
{
	{01,	"DNF",		"地下城勇士"},
	{02,	"Wangmei",	"完美国际"},
	{03,	"Zhuxian",	"诛仙2"},
	{04,	"Wulin",	"武林外传"},
	{05,	"Aion",		"永恒之塔"},
	{06,	"Zhengtu",	"征途"},
};

//////////////////////////////////////////////////////////////////////////
//运行批处理文件
bool RunCmdFile(const char *lpstrFileName)
{
	char path[MAX_PATH];
	GetModuleFileNameA( NULL, path, sizeof(path) );
	char *p = strrchr( path, '\\' );
	if( p==NULL )
		p = strrchr( path, '/' );
	if( p==NULL )
		return false;
	strcpy( p+1, lpstrFileName );

	SHELLEXECUTEINFOA ShExecInfo = {0};
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = path; 
	ShExecInfo.lpParameters = ""; 
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_SHOW;
	ShExecInfo.hInstApp = NULL; 
	if( !ShellExecuteExA(&ShExecInfo) )
		return false;
	WaitForSingleObject(ShExecInfo.hProcess,INFINITE); 

	CloseHandle(ShExecInfo.hProcess);
	return true;
}

bool GetGateWay( string &gateWare )
{
	string gatewayname("GateWay.ini");

	//if ( QFile::exists(gatewayname) && !QFile::remove(gatewayname) )
	//{
	//	showlog( "获取网关错误: 不能够删除文件 GateWay.ini" );
	//	return false;
	//}

	if( !RunCmdFile("GetGateWay.bat") )
	{
		showlog( "获取网关错误: 不能够运行文件GetGateWay.bat");
		return false;
	}

	Sleep( 1000 );

	ifstream ifs;
	ifs.open( gatewayname.c_str(), ios::binary);
	if( ifs.fail())
	{
		showlog( "获取网关错误: 不能够打开文件  GateWay.ini" );
		return false;
	}

	string buf;
	buf.resize(255);

	while(!ifs.eof())
	{
		ifs.getline((char*) buf.c_str(),255);
		string line = buf;
		int pos = line.find("Default Gateway");
		if(pos==-1)
			continue;
		pos = line.find("192.168");
		if(pos==-1)
			continue;

		gateWare = line.substr(pos);
		break;
	}
	
	//
	//QRegExp rx("Default Gateway.*192\\.168\\.( \\d+)\\.(\\d+)");//内网网关,192.168.*.*
	//if( rx.indexIn(all)==-1 )
	//{
	//	showlog( "获取网关错误: 不能从文件中匹配到网关地址" );
	//	return false;
	//}
	//string a1 = rx.cap(1);
	//string a2 = rx.cap(2);

	//gateWare = string("192.168.%1.%2").arg(a1).arg(a2);

	return true;
}

void Dispatcher::Initialize()
{
	_isdianxin = true;
	string gateWare;
	if( GetGateWay(gateWare) )
	{
		string a3, a4;
		showlog(string("Gateway:") + gateWare);
		showlog("\r\n");

		string line = gateWare;
		int pos = line.find_last_of('.');
		a4 = line.substr(pos + 1);

		line = line.substr(0, pos);
		pos = line.find_last_of('.');
		a3 = line.substr(pos + 1);

		// 电信
		if(a4=="254")
			_isdianxin = true;
		else// 网通 (253)
			_isdianxin = false;		
	}

	CMarkup markup;
	markup.Load("gtrc.xcfg");

	_VendorInfo vi;

	while( markup.FindChildElem("game") )
	{
		vi.gameID = markup.GetChildAttrib("id");
		string sid = markup.GetChildAttrib("sid");
		vi.gameName = markup.GetChildAttrib("name");
		vi.robotPath = markup.GetChildAttrib("path");

		Vendor* pVendor = AddVendor(atoi(vi.gameID.c_str()), vi);
	}

	markup.ResetChildPos();
	if( markup.FindChildElem("server") )
	{
		_server.id = markup.GetChildAttrib("id");
		_server.ip = markup.GetChildAttrib("ip");
		_server.port = atoi(markup.GetChildAttrib("port"));
	}
}

void Dispatcher::UnInitialize()
{
	map<string, Vendor*>::iterator it = _vendors.begin();
	while(it != _vendors.end())
	{
		delete (*it).second;
		it++;
	}
	_vendors.clear();
}

Vendor* Dispatcher::AddVendor(int nId, const _VendorInfo& vi)
{
	Vendor* pVendor = new Vendor(vi);
	_vendors[vi.gameID] = pVendor;
	_mapsid[nId] = vi.gameID;
	return pVendor;

}

Vendor* Dispatcher::taskAssign(int gameId, GtMessageBase *pmsg)
{
	showlog("get a task!");

	if(_vendor!=NULL)
	{
		assert(false);
		showlog("exception : not empty vendor");
	}

	string gameSid = _mapsid[gameId];
	map<string, Vendor*>::iterator it = _vendors.find(gameSid);
	if(it != _vendors.end())
	{
		Vendor* pVendor = (*it).second;
		if(pVendor->isIdle())
		{
			pVendor->assign(pmsg);

			_vendor = pVendor;
		}
	}

	assert(_vendor!=NULL);

	return _vendor;
}

Vendor* Dispatcher::taskAssign(gtr::GameTaskletT task)
{
	showlog("get a task!");

	if(_vendor!=NULL)
	{
		assert(false);
		showlog("exception : not empty vendor");
	}

	int gameId = atoi(task.gameId.c_str());
	string gameSid = _mapsid[gameId];
	map<string, Vendor*>::iterator it = _vendors.find(gameSid);
	if(it != _vendors.end())
	{
		Vendor* pVendor = (*it).second;
		if(pVendor->isIdle())
		{
			pVendor->assign(task);

			_vendor = pVendor;
		}
	}

	assert(_vendor!=NULL);

	return _vendor;
}

void Dispatcher::Abort()
{
	if(_vendor)
	{
		_vendor->setResultFeedback(3020);
		_vendor->setFinished(true);
		_vendor = NULL;
	}

}

// 扫描Vendor表
void Dispatcher::Scan()
{
	map<string, Vendor*>::iterator it = _vendors.begin();
	while(it != _vendors.end())
	{
		it++;
	}
}

Vendor* Dispatcher::find(string gameId)
{
	if(gameId=="")
	{
		map<string, Vendor*>::iterator it = _vendors.begin();
		while(it!=_vendors.end())
		{
			if(!(*it).second->isIdle())
				return (*it).second;
			it++;
		}

		return NULL;
	}
	else
	{
		map<string, Vendor*>::iterator it = _vendors.find(gameId);
		if(it != _vendors.end())
		{
			return (*it).second;
		}
	}

	return NULL;
}

void Dispatcher::completeTask()
{
	_vendor = NULL;
	requestTask();
}

void Dispatcher::requestTask()
{
	if(_vendor)
		return ;

	RobotStatus* second = new RobotStatus;
	second->m_statusVal = RS_FREE;
	second->telecom = _isdianxin;
	second->gameversion = (char)0;
	_comm.sendMessage(second);

	delete second;

}


void Dispatcher::notifySupportedGames()
{
	string idarr = getGameIdArr();
	RobotGameId* robotgameid = new RobotGameId;
	robotgameid->gameidstream = idarr;
	robotgameid->gamename = string("地下城与勇士");	
	_comm.sendMessage(robotgameid);

	delete robotgameid;

	Sleep(1000);

}

string Dispatcher::getGameIdArr()
{
	string idarr;

	stringstream ss;
	map<int, string>::iterator it = _mapsid.begin();
	while(it != _mapsid.end())
	{
		Vendor* pV = _vendors[(*it).second];
		if(pV->isEnable())
		{
			ss << (*it).first << ";";
		}
		it++;
	}
	idarr = ss.str();

	int pos = (int) idarr.find_last_of(";");
	if(pos!=-1)
		idarr = idarr.substr(0, pos);
	return idarr;
}

void Dispatcher::setFeedback(string no, GtMessageBase* pFD)
{
	EnterCriticalSection(&_cs);
	_feedback[no] = pFD;
	LeaveCriticalSection(&_cs);
}

GtMessageBase* Dispatcher::SendToServer(GtMessageBase* pMsg, string taskNo, int nFeedBack)
{
	_comm.sendMessage(pMsg);

	GtMessageBase* fd = NULL;

	if(nFeedBack > 0)
	{
		EnterCriticalSection(&_cs);
		_feedback[taskNo] = NULL;
		LeaveCriticalSection(&_cs);

		int timeout = 40;
		while(timeout)
		{
			Sleep(1000);
			timeout--;

			EnterCriticalSection(&_cs);
			bool hasfeedback = (_feedback[taskNo]!=NULL);
			LeaveCriticalSection(&_cs);

			if(hasfeedback)
			{
				break;
			}
		}

		EnterCriticalSection(&_cs);
		fd = _feedback[taskNo];
		_feedback.erase( _feedback.find(taskNo) );
		LeaveCriticalSection(&_cs);
	}
	return fd;
}

gtr::GameRobotInfoT Dispatcher::getRobot()
{
	gtr::GameRobotInfoT robot;
	robot.id = "aaabbbb";
	robot.ip = "";
	robot.network = _isdianxin ? 1 : 0;

	stringstream ss;
	map<int, string>::iterator it = _mapsid.begin();
	while(it != _mapsid.end())
	{
		Vendor* pV = _vendors[(*it).second];
		if(pV->isEnable())
		{
			gtr::GameInfoT gi;
			gi.id = (*it).first;
			gi.name = pV->getGameName();
			gi.version = "0";
			
			robot.supportGames.push_back(gi);
		}
		it++;
	}
	return robot;
}

#include "Crypt.h"
string _decrypt(string key, string src)
{
	char buf[256];
	int size = 256;
	memset(buf, 0, 256);
	if( decrypt(key.c_str(),src.c_str(),buf,size) )
		return buf;
	return "";
}

int Dispatcher::RunAsClientForIce()
{

	gtr::GameRobotInfoT robot = getRobot();
	while(1)
	{
		if(_vendor && !_vendor->isIdle())
		{
			Sleep(100);
		}
		else
		{
			gtr::GameTaskletT task = HostService::_instance._ServerWrap.getTask(robot);
			if(task.no=="")
			{
				Sleep(100);
			}
			else
			{
				task.password = _decrypt(task.secretKey, task.password);

				switch(task.type)
				{
				case gwsPost:
					task.post.bankPwd = _decrypt(task.secretKey, task.post.bankPwd);
					task.post.sellerSecondPwd = _decrypt(task.secretKey, task.post.sellerSecondPwd);
					break;
				case gwsAccountAudit:
					task.audit.bankPwd = _decrypt(task.secretKey, task.audit.bankPwd);
					task.audit.sellerSecondPwd = _decrypt(task.secretKey, task.audit.sellerSecondPwd);
					break;
				case gwsVerify:
					task.verify.bankPwd = _decrypt(task.secretKey, task.verify.bankPwd);
					task.verify.sellerSecondPwd  = _decrypt(task.secretKey, task.verify.sellerSecondPwd);
					break;
				default:
					;

				}

				Vendor* pVendor = taskAssign(task);
				if(pVendor)
				{
					pVendor->startRobot();
				}
			}
		}
	}
	return 1;
}

bool Dispatcher::isStop()
{
	return !_bBusy;
}

int Dispatcher::RunAsClient()
{
	GtCommProps prop;
	prop.server = _server.ip;
	prop.port = _server.port;

	if(!_comm.init(prop))
	{
		showlog("Warning: fail to connect gtr server");
		return 1;
	}
	if(!_comm.start())
	{
		showlog("Warning: fail to connect gtr server ");
		return 1;
	}
	showlog("Log: gtr server connected");

	_bBusy = true;
	while (1)
	{
		Sleep(500);

		GtCommMessageT* gt_comm = _comm.getMessage();
		if (gt_comm==NULL)
		{
			continue;
		}

		GtCommunicatorEvent gtevent = gt_comm->event;
		switch(gtevent)
		{
		case EVENT_COMM_DISCONNECTED:
			{
				printf("与服务器的连接断开了！！\n");
			}
			break;
		case EVENT_COMM_CONNECTED:
			{
				printf("与服务器连接上了！！\n");
			}
			break;
		case EVENT_COMM_MESSAGE:
			{
				if(gt_comm->msg==NULL)
				{
					showlog("收到了服务器发来的未知消息");
					break;
				}
				printf("收到了服务器发来的消息%d\n",(int)gt_comm->msg->getType());
				printf("%s\n",gt_comm->msg->toString().c_str());

				switch(gt_comm->msg->getType())
				{
				case VERIFYREQUEST:
					{
						// 启动Robot进程
						VerifyInfo* p = (VerifyInfo*)gt_comm->msg;
						Vendor* pVendor = taskAssign(p->GameId,p);
						if(pVendor)
							pVendor->startRobot();
					}
					break;
				case TRANSACTREQUEST:
					{
						// 启动Robot进程
						TransactionInfo* p = (TransactionInfo*)gt_comm->msg;
						Vendor* pVendor = taskAssign(p->GameId,p);
						if(pVendor)
							pVendor->startRobot();
					}
					break;
				case YZMCONTENT:
					{
						// 向Robot转发验证码内容
						YZMContent* p = (YZMContent*)gt_comm->msg;
						setFeedback(p->NO, p);
					}
					break;
				case MBKCONTENT:
					{
						// 向Robot转发秘保卡内容
						MBKContent* p = (MBKContent*)gt_comm->msg;
						setFeedback(p->NO, p);
					}
					break;
				case DECRYPTIONKEY:
					{
						// 向服务器回复本客户端支持的Game类别
						notifySupportedGames();
						requestTask();
					}
					break;
				case ROBOTHEART:
					{
						RobotHeart* heart = new RobotHeart;
						showmsg("Heart beat");
						_comm.sendMessage(heart);
					}
					break;
				case ACCOUNTVERIFYREQUEST:
					{
						AccountVerifyInfo* info = (AccountVerifyInfo*)gt_comm->msg;
						Vendor* pVendor = taskAssign(info->GameId,info);
						if(pVendor)
							pVendor->startRobot();
					}
					break;
				}
			}
			break;
		}
	}

	_bBusy = false;

	return 1;
}

client::Vendor* Dispatcher::findVendor(string gameId) 
{
	return _vendor;
	//return _dispatcher.find(gameId);
}
