// GameWL.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "GameWL.h"

#include "GtrClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGameWLApp

BEGIN_MESSAGE_MAP(CGameWLApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CGameWLApp ����

CGameWLApp::CGameWLApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CGameWLApp ����

CGameWLApp theApp;


// CGameWLApp ��ʼ��

class RobotCommandLineInfo :	public CCommandLineInfo
{
	int m_nFlag;
public:
	CString m_strOrder;
	int m_nPort;
	RobotCommandLineInfo()
	{
		m_nFlag = 0;
		m_strOrder = "";
		m_nPort = 0;
	}
	virtual void ParseParam(const TCHAR* pszParam, BOOL bFlag, BOOL bLast)
	{
		switch(m_nFlag)
		{
		case 0:
			m_strOrder = pszParam;
			break;

		case 1:
			m_nPort = atoi(pszParam);
			break;
		}

		if(bLast)
			m_nFlag = 0;
		else
			m_nFlag++;
	}

};

int CGameWLApp::ExitInstance()
{
	CloseHandle(m_hMutex);

	return CWinApp::ExitInstance();
}

BOOL CGameWLApp::InitInstance()
{

	m_hMutex = CreateMutex(NULL, FALSE, "GTRC");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		AfxMessageBox("GTRC�������еڶ���ʵ��������������ֹ");
		CloseHandle(m_hMutex);
		m_hMutex = NULL;
		return FALSE;
	}

	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	RobotCommandLineInfo   cmdInfo;   
	ParseCommandLine(cmdInfo);
	
	GtrClientDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˴����ô����ʱ�á�ȷ�������ر�
		//  �Ի���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ�á�ȡ�������ر�
		//  �Ի���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}
