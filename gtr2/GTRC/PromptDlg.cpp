// PromptDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "GTRC.h"
#include "PromptDlg.h"


// CPromptDlg 对话框

IMPLEMENT_DYNAMIC(CPromptDlg, CDialog)

CPromptDlg::CPromptDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPromptDlg::IDD, pParent)
{

}

CPromptDlg::~CPromptDlg()
{
}

void CPromptDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LOG, m_Log);
}


BEGIN_MESSAGE_MAP(CPromptDlg, CDialog)
END_MESSAGE_MAP()


// CPromptDlg 消息处理程序
void CPromptDlg::insertLog(const char* szMsg)
{
	m_Log.SetSel(-1,-1);
	m_Log.ReplaceSel(szMsg);
}
