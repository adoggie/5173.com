// GtrClientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "GtrClientDlg.h"
#include "winsock.h"

// GtrClientDlg 对话框

void showmsg(string msg)
{
	GtrClientDlg* pDlg = (GtrClientDlg*) AfxGetApp()->GetMainWnd();
	pDlg->setStatusMsg(msg.c_str());
}

void showlog(string log)
{
	log += "\r\n";
	GtrClientDlg* pDlg = (GtrClientDlg*) AfxGetApp()->GetMainWnd();
	pDlg->insertLog(log.c_str());
}

std::string getGTRCLog(){
	//return "game-core.log";
	time_t t;
	time(&t);
	struct tm *ptm = localtime(&t);
	char buffer[128] = {0};
	sprintf(buffer,"%s%d-%d-%d.log", "GTRC",ptm->tm_year+1900,ptm->tm_mon+1,ptm->tm_mday);
	//printf("%s",buffer);
	return std::string(buffer);
}

string ipaddr;

IMPLEMENT_DYNAMIC(GtrClientDlg, CDialog)

GtrClientDlg::GtrClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(GtrClientDlg::IDD, pParent)
{
	InitializeCriticalSection(&_cs);

	WSADATA wsaData;

	if ( WSAStartup(MAKEWORD(2, 2), &wsaData) == 0 )
	{
		char buf[255];
		gethostname(buf, 255);
		hostent *host = gethostbyname(buf);
		if(host)
		{
			if( host->h_addrtype == 2 && host->h_length == 4)
			{
				const char* ip = host->h_addr;
				ipaddr = inet_ntoa(*(struct in_addr*)host->h_addr);
			}

		}
		WSACleanup();

	}

	m_strStatus = "[";
	m_strStatus += ipaddr.c_str();
	m_strStatus += "]wait for start";
}

GtrClientDlg::~GtrClientDlg()
{
	fclose(_fp);
}

void GtrClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ROBOT_TYPE, m_RobotList);
	DDX_Control(pDX, IDC_GTRCLOG, m_LogView);
}


BEGIN_MESSAGE_MAP(GtrClientDlg, CDialog)
	ON_BN_CLICKED(IDOK, &GtrClientDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &GtrClientDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_TEST, &GtrClientDlg::OnBnClickedTest)
	ON_WM_TIMER()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_ROBOT_TYPE, &GtrClientDlg::OnLvnItemchangedRobotType)
	ON_BN_CLICKED(IDC_ABORT, &GtrClientDlg::OnBnClickedAbort)
END_MESSAGE_MAP()


// GtrClientDlg 消息处理程序
BOOL GtrClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	string fn = getGTRCLog();
	_fp = fopen(fn.c_str(),"a+");
	
//	_prompt.Create(IDD_PROMPT, this);

	// TODO:  在此添加额外的初始化
	m_RobotList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES |LVS_EX_GRIDLINES);
	m_RobotList.InsertColumn(0, "GameId", LVCFMT_LEFT, 100);
	m_RobotList.InsertColumn(1, "Status", LVCFMT_LEFT, 64);
	m_RobotList.InsertColumn(2, "Path", LVCFMT_LEFT, 255);

	DISPATCHER.Initialize();
	const map<string, Vendor*>& vendors = DISPATCHER.getVendors();
	map<string, Vendor*>::const_iterator it = vendors.begin();
	while(it != vendors.end())
	{
		Vendor* pVendor = (*it).second;
		int nRow = m_RobotList.InsertItem(0,pVendor->getGameName().c_str());
		m_RobotList.SetItemText(nRow, 1, pVendor->getStatusHint().c_str());
		m_RobotList.SetItemText(nRow, 2, pVendor->getGamePath().c_str());
		m_RobotList.SetCheck(nRow, pVendor->isEnable());
		m_RobotList.SetItemData(nRow, (DWORD_PTR)pVendor);
		it++;
	}

	SetTimer(100, 2000, NULL);
	SetTimer(102, 20, NULL);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

UINT HostServiceProc(LPVOID lpUser)
{
	GtrClientDlg *pDlg = (GtrClientDlg*) lpUser;
	pDlg->RunAsClient(NULL);
	return TRUE;
}

UINT GtrClientDlg::RunAsClient(LPVOID lpUser)
{

	try
	{
		HostService::_instance.Start();

		int timeout = 400;
		while( timeout)
		{
			if( HostService::_instance.isStarted() )
				break;; 
			Sleep(100);
			timeout--;
		}

		if( HostService::_instance.isStarted() )
		{
			DISPATCHER.RunAsClient();
			//DISPATCHER.RunAsClientForIce();
		}
	}
	catch (...)
	{
	}

	SetTimer(101, 100, NULL);
	return TRUE;
}

void GtrClientDlg::OnBnClickedOk()
{
//	_prompt.ShowWindow(SW_SHOW);

	GetDlgItem(IDOK)->EnableWindow(FALSE);

	//HostService::_instance.Start();

	//AfxBeginThread(HostServiceProc, &HostService::_instance);
	AfxBeginThread(HostServiceProc, this);

}

void GtrClientDlg::OnBnClickedCancel()
{
	DISPATCHER.UnInitialize();

	OnCancel();
}

void GtrClientDlg::OnBnClickedTest()
{
	SHELLEXECUTEINFO   ShExecInfo   =   {0};  
	ShExecInfo.cbSize   =   sizeof(SHELLEXECUTEINFO);  
	ShExecInfo.fMask   =   SEE_MASK_NOCLOSEPROCESS;  
	ShExecInfo.hwnd   =   NULL;  
	ShExecInfo.lpVerb   =   NULL;  
	ShExecInfo.lpFile   =   "RpcClient.exe";  
	ShExecInfo.lpParameters   =   NULL;  
	ShExecInfo.lpDirectory   =   NULL;  
	ShExecInfo.nShow   =   SW_SHOW;  
	ShExecInfo.hInstApp   =   NULL;  

	ShellExecuteEx(&ShExecInfo);  
}


void GtrClientDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch(nIDEvent)
	{
	case 100:
		{
			int nCount = m_RobotList.GetItemCount();
			for(int nItem = 0; nItem < nCount; nItem++)
			{
				Vendor *pVendor = (Vendor*) m_RobotList.GetItemData(nItem);
				pVendor->timeOut();
				m_RobotList.SetItemText(nItem, 1, pVendor->getStatusHint().c_str());
			}
			m_RobotList.UpdateWindow();
		}
		break;

	case 102:
		{
			static int idx = 0;
			char *cur = "-\\|/";
			CString status;
			status.Format("%c %s", cur[idx], m_strStatus);
			SetDlgItemText(IDC_STATUS, status);
			GetDlgItem(IDC_STATUS)->Invalidate(TRUE);
			idx++;
			if(idx>=4)
				idx = 0;

		}
		break;

	case 101:
		{
			if(DISPATCHER.isStop())
			{
				KillTimer(101);
				GetDlgItem(IDOK)->EnableWindow(TRUE);
			}
		}
		break;
	}
	CDialog::OnTimer(nIDEvent);
}

void GtrClientDlg::OnLvnItemchangedRobotType(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	int nItem = pNMLV->iItem;
	Vendor* pVendor = (Vendor*)m_RobotList.GetItemData(nItem);

	if(pVendor)
	{
		m_RobotList.GetCheck(nItem) ? pVendor->Enable() : pVendor->Disable();

	}
	*pResult = 0;
}


void GtrClientDlg::OnBnClickedAbort()
{
	if( IDOK == AfxMessageBox("确认：是否要放弃机器人当前在做订单？", MB_OKCANCEL) )
	{
		DISPATCHER.Abort();
	}
}

// CPromptDlg 消息处理程序
void GtrClientDlg::insertLog(const char* szMsg)
{
	std::string msg;
	std::string format;
	char * mark;
	char * occur;

	time_t curtime = time(0);

	struct tm * ptm = localtime(&curtime);	
	if(ptm){
		char timebuff[32];
		sprintf(timebuff,"%d-%d-%d %d:%d:%d ",ptm->tm_year+1900,ptm->tm_mon+1,ptm->tm_mday,
			ptm->tm_hour,ptm->tm_min,ptm->tm_sec);		
		msg = timebuff;	
	}
	msg = msg +" "+szMsg;

	EnterCriticalSection(&_cs);
	fwrite(msg.c_str(), 1, msg.length(), _fp);
	fflush(_fp);
	LeaveCriticalSection(&_cs);

	m_LogView.SetSel(-1,-1);
	m_LogView.ReplaceSel(szMsg);
}

void GtrClientDlg::setStatusMsg(const char* szMsg)
{
	time_t now = time(0);
	m_strStatus = ctime(&now);
	m_strStatus += " [";
	m_strStatus += szMsg;
	m_strStatus += " ]";
}