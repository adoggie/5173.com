
//

//////////////////////////////////////////////////////////////////////////
//
//太牛了,搞这个破东西搞到2点半,值不值啊???S?A?S?A?S?A?S?AS?
// 必须放置在system32/xxxxx
//
/*
测试脚本
import socket
s = socket.socket()
s.connect(('127.0.0.1',8877))
*/


#include "provider.h"
#pragma  comment(lib,"comsuppw.lib")

WSPUPCALLTABLE MainUpCallTable;
DWORD gLayerCatId = 0;
DWORD gChainId = 0;
DWORD gEntryCount = 0;
CRITICAL_SECTION gCriticalSection;
LPWSPDATA gWSPData = NULL;
WSPPROC_TABLE NextProcTable;
LPWSPPROC_TABLE gProcTable = NULL;
LPWSAPROTOCOL_INFOW gBaseInfo = NULL;
HINSTANCE HDllInstance = NULL;
HINSTANCE hProvider = NULL;
INT gLayerCount=0;                    // Number of base providers we're layered over

static TCHAR Msg[512];
//////////////////////////////////////////////////////////////////////////

#include <tchar.h>

#include "async.h"
#include "log.h"
swLogger logger;
swLogger::WindowWriter * w_win;

#include <comutil.h>
std::vector<_bstr_t> filterPrcoessList; //过滤进程列表
Mutex mtx_critical;
//////////////////////////////////////////////////////////////////////////
//以下变量需共享数据段 
#pragma data_seg("rdshare")
//Condition* g_cond=NULL;
//Condition* g_condFront=NULL;		//rdFront的同步锁
unsigned int g_destnaddr=0;	//目标主机地址
unsigned short g_destnport=0; //目标端口
#pragma data_seg()
#pragma comment(linker,"/SECTION:rdshare,RWS")
//////////////////////////////////////////////////////////////////////////


void loadFilterList(){
	FILE * pf = fopen("c:/rdfilter.txt","r");
	if(!pf){
		return;
	}
	filterPrcoessList.clear();
	char buff[1024*2];
	while( fgets(buff,sizeof(buff),pf)){
		if(strlen(buff)){
			if(buff[strlen(buff)-1] == '\r' ||buff[strlen(buff)-1] == '\n' ){
				buff[strlen(buff)-1] ='\0';
			}
		}
		filterPrcoessList.push_back( _bstr_t(buff)); //_strupr(
		logger.Debug("%s:len(%d)",buff,strlen(buff));
	}
}

BOOL WINAPI DllMain(IN HINSTANCE hinstDll, IN DWORD dwReason, LPVOID lpvReserved)
{
	switch (dwReason)
	{

	case DLL_PROCESS_ATTACH:
		HDllInstance = hinstDll;
		InitializeCriticalSection(&gCriticalSection);
		//            InitAsyncSelectCS();
	//	InitOverlappedCS();

		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;

	case DLL_PROCESS_DETACH:
		break;
	}



	return TRUE;
}

bool matchedProcess(SOCKET s){
	bool r = false;
	TCHAR buff[MAX_PATH];

	TCHAR driver[MAX_PATH];
	TCHAR dir[MAX_PATH];
	TCHAR fname[MAX_PATH];
	TCHAR ext[MAX_PATH];

	int sockType;
	int optlen,opterrno;
	optlen = 4;
	int optret = gProcTable->lpWSPGetSockOpt(s,SOL_SOCKET,SO_TYPE,(char*)&sockType,&optlen,&opterrno);
	if( optret || sockType !=SOCK_STREAM){
		logger.Debug("socket is not a tcp object,ignore!");
		return false;
	}


	GetModuleFileName(NULL,buff,MAX_PATH-1);
	_tsplitpath(buff,driver,dir,fname,ext);
	_bstr_t processName(fname);
	//processName+=L".";
	processName+=ext;
	//processName = _tcsupr((wchar_t*)processName);
	logger.Debug("Issue Connect Request Process:%s",(char*)processName);
	for(int n=0;n<filterPrcoessList.size();n++){
		logger.Debug("compare Name: (%s)==(%s)",(char*)filterPrcoessList[n],(char*)processName);
		if(_wcsicmp( (wchar_t*)filterPrcoessList[n] ,(wchar_t*)processName) == 0){
			r = true;
			logger.Debug("filter Matched!");
			break;
		}
	}
	return r;
}

// return: 0 - succ,else failed
int waitRedirectDestination(unsigned int *naddr,unsigned short * nport){
	//logger.Debug("waitRedirectDestination...");
	// 	if(!g_condFront->wait(2000*1)){
	// 		return -1;
	// 	}
	*naddr = g_destnaddr;
	*nport = g_destnport;
	//	g_condFront->set(false);
	//g_cond->set(true);
	logger.Debug("waitRedirectDestination:: got it!");
	return 0;
}

int WSPAPI WSPConnect (
											 SOCKET s,                           
											 const struct sockaddr FAR * name,
											 int namelen,                        
											 LPWSABUF lpCallerData,
											 LPWSABUF lpCalleeData,              
											 LPQOS lpSQOS,
											 LPQOS lpGQOS,                       
											 LPINT lpErrno
											 )
{
	SOCK_INFO *SocketContext;
	INT ret;
	struct sockaddr_in *saddr;
	saddr = (sockaddr_in*)name;

	UINT rdr_addr = 0x0100007f;  // 127.0.0.1 network order
	USHORT rdr_port = 0xd859 ; // 23000


	TCHAR* geventName1=L"Global\\{8b4a1f95-3f13-4b50-b53f-a94ad165c2b2}";
	TCHAR* geventName2=L"Global\\{dd16ab23-8f4e-43d1-bfcb-750a2b35922e}";
	// 	TCHAR* geventName1=L"Global{8b4a1f95-3f13-4b50-b53f-a94ad165c2b2}";
	// 	TCHAR* geventName2=L"Global{dd16ab23-8f4e-43d1-bfcb-750a2b35922e}";
	//修改目标ip
	if(matchedProcess(s)){
		ScopeLocker l(mtx_critical);
		g_destnaddr = saddr->sin_addr.s_addr;
		g_destnport = saddr->sin_port;

		logger.Debug("set flag and wait rdFront  pick !");

		HANDLE event1 = ::OpenEvent(EVENT_MODIFY_STATE|SYNCHRONIZE, FALSE,geventName1);
		HANDLE event2 = ::OpenEvent(EVENT_MODIFY_STATE|SYNCHRONIZE, FALSE,geventName2);

		if(event1 && event2){
			//g_cond->set(false);   //准备等待
			//g_condFront->set(true); //通知rdFront可以来取了
			ResetEvent(event1);
			SetEvent(event2);
			logger.Debug("waiting...");

			//if(!g_cond->wait(1000*5)){   //rdfront取完必须设置为有信号
			if( WaitForSingleObject(event1,1000*5) ==WAIT_TIMEOUT){
				logger.Debug("wait timeout,ignore...");
			}else{
				logger.Debug("switch destination to (127.0.0.1:23000)...");
				saddr->sin_addr.s_addr = rdr_addr;
				saddr->sin_port = htons(23000);
			}
		}else{
			logger.Debug("open Events failed!");
		}

	}else{
		//logger.Debug("no filter matched!");
	}

	//     if (MainUpCallTable.lpWPUQuerySocketHandleContext(s, (LPDWORD) &SocketContext, lpErrno) == SOCKET_ERROR)
	//     {
	//         return SOCKET_ERROR;
	//     }

	ret =  NextProcTable.lpWSPConnect(s, name, namelen, lpCallerData, lpCalleeData,
		lpSQOS, lpGQOS, lpErrno);

	return ret;
}

int WSPAPI WSPStartup(
											WORD wVersion,
											LPWSPDATA lpWSPData,
											LPWSAPROTOCOL_INFOW lpProtocolInfo,
											WSPUPCALLTABLE UpCallTable,
											LPWSPPROC_TABLE lpProcTable)
{

	INT      ReturnCode = 0;
	WCHAR    ProviderPath[MAX_PATH];
	INT      ProviderPathLen = MAX_PATH;
	WCHAR    LibraryPath[MAX_PATH];
	INT      i, j, x, y, z;
	INT      TotalProtocols, idx;
	INT      Error;
	DWORD    NextProviderCatId;
	UINT     iBaseId;

	LPWSAPROTOCOL_INFOW ProtocolInfo;
	LPWSAPROTOCOL_INFOW ProtoInfo = lpProtocolInfo;
	LPWSPSTARTUP    WSPStartupFunc = NULL;

	EnterCriticalSection(&gCriticalSection);


	MainUpCallTable = UpCallTable;

	// Load Next Provider in chain if this is the first time called
	//if (!gEntryCount)
	if(1)
	{
		OutputDebugString(L"Layered Service Provider\n");

		//  Get all protocol information in database
		if ((ProtocolInfo = GetProviders(&TotalProtocols)) == NULL)
		{
			return  WSAEPROVIDERFAILEDINIT;
		}

		// Find out what our layered protocol catalog ID entry is
		for (i = 0; i < TotalProtocols; i++)
			if (memcmp (&ProtocolInfo[i].ProviderId, &ProviderGuid, sizeof (GUID))==0)
			{
				gLayerCatId = ProtocolInfo[i].dwCatalogEntryId;
				break;
			}

			// Save our protocol chains catalog ID entry
			gChainId = lpProtocolInfo->dwCatalogEntryId;

			gLayerCount=0;
			for(x=0; x < TotalProtocols ;x++)
			{
				for(y=0; y < ProtocolInfo[x].ProtocolChain.ChainLen ;y++)
				{
					if (gLayerCatId == ProtocolInfo[x].ProtocolChain.ChainEntries[y])
					{
						gLayerCount++;
						break;
					}
				}
			}
			gBaseInfo = (LPWSAPROTOCOL_INFOW)GlobalAlloc(GPTR, sizeof(WSAPROTOCOL_INFOW)*gLayerCount);
			if (!gBaseInfo)
			{
				return WSAENOBUFS;
			}
			idx=0;
			for(x=0; x < TotalProtocols ;x++)
			{
				for(y=0; y < ProtocolInfo[x].ProtocolChain.ChainLen ;y++)
				{
					if (gLayerCatId == ProtocolInfo[x].ProtocolChain.ChainEntries[y])
					{
						// Our LSP exists in this entries chain
						//
						iBaseId = ProtocolInfo[x].ProtocolChain.ChainEntries[ProtocolInfo[x].ProtocolChain.ChainLen-1];
						for(z=0; z < TotalProtocols ;z++)
						{
							if (ProtocolInfo[z].dwCatalogEntryId == iBaseId)
							{
								memcpy(&gBaseInfo[idx++], &ProtocolInfo[z], sizeof(WSAPROTOCOL_INFOW));
								OutputDebugString(gBaseInfo[idx-1].szProtocol);
								OutputDebugString(L"\n");
							}
						}
					}
				}
			}

			// Find our layered catalog ID entry in the protocol chain
			for(j = 0; j < lpProtocolInfo->ProtocolChain.ChainLen; j++)
			{
				if (lpProtocolInfo->ProtocolChain.ChainEntries[j] == gLayerCatId)
				{

					NextProviderCatId = lpProtocolInfo->ProtocolChain.ChainEntries[j + 1];
					break;
				}
			}


			// Find next provider path to load
			for (i = 0; i < TotalProtocols; i++)
				if (NextProviderCatId == ProtocolInfo[i].dwCatalogEntryId)
				{
					if (WSCGetProviderPath(&ProtocolInfo[i].ProviderId, ProviderPath, &ProviderPathLen, &Error) == SOCKET_ERROR)
					{
						return  WSAEPROVIDERFAILEDINIT;
					}
					break;
				}

				if (!ExpandEnvironmentStrings(ProviderPath, LibraryPath, MAX_PATH))
				{
					return  WSAEPROVIDERFAILEDINIT;
				}

				if ((hProvider = LoadLibrary(LibraryPath)) == NULL)
				{
					return  WSAEPROVIDERFAILEDINIT;
				}


				if((WSPStartupFunc = (LPWSPSTARTUP) GetProcAddress(hProvider, "WSPStartup")) == NULL)
				{
					return  WSAEPROVIDERFAILEDINIT;
				}

				ReturnCode = (*WSPStartupFunc)(wVersion, lpWSPData, ProtoInfo, UpCallTable, lpProcTable);

				// Save the next providers procedure table
				memcpy(&NextProcTable, lpProcTable, sizeof WSPPROC_TABLE);

				// Remap service provider functions here

				//          lpProcTable->lpWSPAccept = WSPAccept;
				//          lpProcTable->lpWSPAddressToString = WSPAddressToString;
				//          lpProcTable->lpWSPAsyncSelect = WSPAsyncSelect;
				//          lpProcTable->lpWSPBind = WSPBind;
				//          lpProcTable->lpWSPCancelBlockingCall = WSPCancelBlockingCall;
				//          lpProcTable->lpWSPCleanup = WSPCleanup;
				//          lpProcTable->lpWSPCloseSocket = WSPCloseSocket;
				lpProcTable->lpWSPConnect = WSPConnect;
				//          lpProcTable->lpWSPDuplicateSocket = WSPDuplicateSocket;
				//          lpProcTable->lpWSPEnumNetworkEvents = WSPEnumNetworkEvents;
				//          lpProcTable->lpWSPEventSelect = WSPEventSelect;
				//          lpProcTable->lpWSPGetOverlappedResult = WSPGetOverlappedResult;
				//          lpProcTable->lpWSPGetPeerName = WSPGetPeerName;
				//          lpProcTable->lpWSPGetSockOpt = WSPGetSockOpt;
				//          lpProcTable->lpWSPGetSockName = WSPGetSockName;
				//          lpProcTable->lpWSPGetQOSByName = WSPGetQOSByName;
				//          lpProcTable->lpWSPIoctl = WSPIoctl;
				//          lpProcTable->lpWSPJoinLeaf = WSPJoinLeaf;
				//          lpProcTable->lpWSPListen = WSPListen;
				//          lpProcTable->lpWSPRecv = WSPRecv;
				//          lpProcTable->lpWSPRecvDisconnect = WSPRecvDisconnect;
				//          lpProcTable->lpWSPRecvFrom = WSPRecvFrom;
				//          lpProcTable->lpWSPSelect = WSPSelect;
				//          lpProcTable->lpWSPSend = WSPSend;
				//          lpProcTable->lpWSPSendDisconnect = WSPSendDisconnect;
				//          lpProcTable->lpWSPSendTo = WSPSendTo;
				//          lpProcTable->lpWSPSetSockOpt = WSPSetSockOpt;
				//          lpProcTable->lpWSPShutdown = WSPShutdown;
				//          lpProcTable->lpWSPSocket = WSPSocket;
				//          lpProcTable->lpWSPStringToAddress = WSPStringToAddress;

				gWSPData = lpWSPData;
				gProcTable = lpProcTable;

				w_win = new swLogger::WindowWriter(L"rdfilter");
				w_win->Open();
				logger.SetWriter(w_win);
				logger.Debug("lsp started!");

				loadFilterList();

				TCHAR buff[MAX_PATH];
				GetModuleFileName(NULL,buff,MAX_PATH-1);
				//	_tsplitpath(buff,driver,dir,fname,ext);
				_bstr_t processName(buff);
			
				logger.Debug("current Process:%s",(char*)processName);				
				logger.Debug("load rdfilter.text succ!");
				
    } else
    {
//         lpWSPData = gWSPData;
//         lpProcTable = gProcTable;
//         ReturnCode = 0;
    }

    gEntryCount++;


		


// 		if( g_cond == NULL){
// 			g_cond = new Condition;
// 			g_condFront = new Condition;
// 			logger.Debug("Init Event Objects!");
// 		}
    LeaveCriticalSection(&gCriticalSection);



    return(ReturnCode);
}

