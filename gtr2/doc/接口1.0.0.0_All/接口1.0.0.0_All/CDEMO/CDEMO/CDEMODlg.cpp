// CDEMODlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CDEMO.h"
#include "CDEMODlg.h"
#include "InterFace.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

PBYTE MappingReadA( PCHAR pszFileName, /*out*/ PDWORD pdwSize )
{
	PBYTE pbyMap = NULL;
	HANDLE hMap = INVALID_HANDLE_VALUE;
	HANDLE hFile = CreateFileA(pszFileName, 
		GENERIC_ALL, 
		FILE_SHARE_READ, NULL, 
		OPEN_EXISTING, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		goto Exit0;
	}
	*pdwSize = GetFileSize(hFile, NULL);
	//
	hMap = CreateFileMappingA(hFile, NULL, PAGE_READWRITE, 0, 0, NULL);
	CloseHandle(hFile);
	if (hMap == NULL)
	{
		goto Exit0;
	}

	pbyMap = (PBYTE)MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	CloseHandle(hMap);
Exit0:
	return pbyMap;
}

BOOL Unmapping(PBYTE pbyMap)
{
	return UnmapViewOfFile(pbyMap);
}

BOOL FileExistsA( PCHAR lpFileName )
{
	DWORD dwFileAttr = GetFileAttributesA(lpFileName);

	if ((dwFileAttr != MAXDWORD) &&
		!(dwFileAttr & FILE_ATTRIBUTE_DIRECTORY))
		return TRUE;
	else
		return FALSE;
}


// CCDEMODlg �Ի���
BOOL GetRel(char* sFile,char* sXY,int ixylen, int iType,char* cRel)
{
	BOOL bRel = FALSE;
    int i;
	DWORD dwFileSize = 0;
    PBYTE pFileBuff = NULL;
	TGetCardDataByCoordinate ParamInfo;
	TPicBuffInfo PicInfo;

	if (!FileExistsA(sFile))
	{
		::MessageBoxA(0,"�ļ�������","",0);
		goto Exit0;
	}
	pFileBuff = MappingReadA(sFile,&dwFileSize);
	GB_PROCESS_ERROR(pFileBuff);
	PicInfo.cPicBuff = (char*)pFileBuff;
	PicInfo.dwPicBuffLen = dwFileSize;
	ParamInfo.PicInfo = &PicInfo;
	ParamInfo.cCoordinateBuff = sXY;
	ParamInfo.dwCoordinateBuffLen = ixylen;
	ParamInfo.cRelBuff = cRel;
	ParamInfo.iType = iType;
	ParamInfo.iRel = 0;

	if (S_OK !=  g_AUTOPICAPI.GetCardDataByCoordinate(&ParamInfo))
	{
		
		goto Exit0;
	}
	bRel = TRUE;

Exit0:
	if (NULL != pFileBuff)
	{
		Unmapping(pFileBuff);
	}
	return bRel;
}

BOOL GetRelGetPicCoordinateTable(char* sFile, int iType,char* cRel)
{
	BOOL bRel = FALSE;
	int i;
	DWORD dwFileSize = 0;
	PBYTE pFileBuff = NULL;
	TGetCoordinateTable ParamInfo;
	TPicBuffInfo PicInfo;

	if (!FileExistsA(sFile))
	{
		::MessageBoxA(0,"�ļ�������","",0);
		goto Exit0;
	}
	pFileBuff = MappingReadA(sFile,&dwFileSize);
	GB_PROCESS_ERROR(pFileBuff);
	PicInfo.cPicBuff = (char*)pFileBuff;
	PicInfo.dwPicBuffLen = dwFileSize;
	ParamInfo.PicInfo = &PicInfo;
	ParamInfo.cRelBuff = cRel;
	ParamInfo.dwRelBuffLen = 6;
	ParamInfo.iType = iType;
	ParamInfo.iRel = 0;

	if (S_OK !=  g_AUTOPICAPI.GetCoordinateTable(&ParamInfo))
	{

		goto Exit0;
	}
	bRel = TRUE;

Exit0:
	if (NULL != pFileBuff)
	{
		Unmapping(pFileBuff);
	}
	return bRel;
}



CCDEMODlg::CCDEMODlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCDEMODlg::IDD, pParent)
//	, m_rb_qq(0)
//	, m_rb_ks(0)
//	, m_rb_wm(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCDEMODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_PICPATH, m_edipic);
	DDX_Control(pDX, IDC_EDIT_XY, m_edi_xy);
	DDX_Control(pDX, IDC_EDIT_REL, m_edi_rel);
}

BEGIN_MESSAGE_MAP(CCDEMODlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDCANCEL, &CCDEMODlg::OnBnClickedCancel)
	//ON_BN_CLICKED(IDC_BUTTON1, &CCDEMODlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BTN_DO, &CCDEMODlg::OnBnClickedBtnDo)
	ON_BN_CLICKED(IDC_BTN_INIT, &CCDEMODlg::OnBnClickedBtnInit)
	ON_BN_CLICKED(IDC_RADIO_WM, &CCDEMODlg::OnBnClickedRadioWm)
	ON_BN_CLICKED(IDC_BTN_DLGPIC, &CCDEMODlg::OnBnClickedBtnDlgpic)
	ON_BN_CLICKED(IDOK, &CCDEMODlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BTN_TEST, &CCDEMODlg::OnBnClickedBtnTest)
	ON_BN_CLICKED(IDC_BTN_test3, &CCDEMODlg::OnBnClickedBtntest3)
END_MESSAGE_MAP()


// CCDEMODlg ��Ϣ�������

BOOL CCDEMODlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//if (!Init_QJ_Update())
	//{
	//	AfxMessageBox("��ʼ��ʧ��!");
	//	::TerminateProcess(::GetCurrentProcess(),0);
	//}

	m_edipic.SetWindowText(L"D:\\5173pro\\D\\verification code\\DNFA.gif");
	m_edi_xy.SetWindowText(L"a1a2a3");

	
	((CButton *)GetDlgItem(IDC_RADIO_QQ))->SetCheck(TRUE);
	::EnableWindow(((CButton *)GetDlgItem(IDC_RADIO_QQ))->m_hWnd,FALSE);

	

    //((CButton *)GetDlgItem(IDC_RADIO_QQ))
	((CButton *)GetDlgItem(IDC_RADIO_WM))->SetCheck(FALSE);//
	::EnableWindow(((CButton *)GetDlgItem(IDC_RADIO_WM))->m_hWnd,FALSE);

	((CButton *)GetDlgItem(IDC_RADIO_KS))->SetCheck(FALSE);
	::EnableWindow(((CButton *)GetDlgItem(IDC_RADIO_KS))->m_hWnd,FALSE);
	//IDC_RADIO_QQ

//	m_rb_qq.setch

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCDEMODlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCDEMODlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCDEMODlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	//OnCancel();
}

void CCDEMODlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
}

void CCDEMODlg::OnBnClickedBtnDo()
{
	char cFile[1024] = {0};
	char cXY[1024] = {0};
	char cRel[256] = {0};
	CString sFile,sXY,sRel;
	int iType = 1;
    if (!g_AUTOPICAPI.PlatForm)
    {
		Init_AutoRecognizer(NULL);
    }

	m_edi_rel.SetWindowText(L"");
	m_edipic.GetWindowText(sFile);
	m_edi_xy.GetWindowText(sXY);

	wsprintfA(cFile,"%ls",sFile);
	wsprintfA(cXY,"%ls",sXY);
	if (GetRel(cFile,cXY,sXY.GetLength(),iType,cRel))
	{
		for (int i=0;i<sXY.GetLength();i++)
		{
			cRel[i] = (char)((BYTE)cRel[i] + 0x30);
		}
		sRel.Format(L"%S",cRel);
		m_edi_rel.SetWindowText(sRel);
	}
}

void CCDEMODlg::OnBnClickedBtnInit()
{
	if (Init_AutoRecognizer(NULL))
	{
		::MessageBoxA(0,"Init Ok","",0);
	}
	else
	{
		::MessageBoxA(0,"Init Err","",0);
	}
}

void CCDEMODlg::OnBnClickedRadioWm()
{
	// TODO: Add your control notification handler code here
}

void CCDEMODlg::OnBnClickedBtnDlgpic()
{
	CFileDialog dlgFileOpen(TRUE);

	int structsize=0; 
	DWORD dwVersion,dwWindowsMajorVersion,dwWindowsMinorVersion; 
	dwVersion = GetVersion(); 
	dwWindowsMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion))); 
	dwWindowsMinorVersion = (DWORD)(HIBYTE(LOWORD(dwVersion))); 
	if (dwVersion < 0x80000000)
		structsize =88;//��ʾ�µ��ļ��Ի��� 
	else 
		//���еĲ���ϵͳWindows 95/98
		structsize =76;//��ʾ�ϵ��ļ��Ի��� 
	dlgFileOpen.m_ofn.lStructSize=structsize; 
	TCHAR lpstrFilename[MAX_PATH] = L""; 
	dlgFileOpen.m_ofn.lpstrFile = lpstrFilename; 
	if(dlgFileOpen.DoModal()==IDOK) 
	{
		m_edipic.SetWindowText(dlgFileOpen.m_ofn.lpstrFile);
	}
	else 
	{
		m_edipic.SetWindowText(L"");
	}
}

void CCDEMODlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();


    
}

void CCDEMODlg::OnBnClickedBtnTest()
{
	CString sRel;
	CHAR cRel[1024] = {0};
	CHAR cFile[1024] = {0};
	CString sFile;

	m_edi_rel.SetWindowText(L"");
	if (!g_AUTOPICAPI.PlatForm)
	{
		Init_AutoRecognizer(NULL);
	}

	m_edipic.GetWindowText(sFile);
	wsprintfA(cFile,"%ls",sFile);

	//
	if (GetRelGetPicCoordinateTable(cFile,1,cRel))
	{

		sRel.Format(L"%S",cRel);
		m_edi_rel.SetWindowText(sRel);
	};

}

void CCDEMODlg::OnBnClickedBtntest3()
{
	int iLen = 0;
	PGetLinePic pbuff = NULL;
	// TODO: Add your control notification handler code here
	//OnOK();
	if (!g_AUTOPICAPI.PlatForm)
	{
		Init_AutoRecognizer(NULL);
	}
	pbuff = g_AUTOPICAPI.GetLinePicBuff();
	// TODO: Add your control notification handler code here
}
