#pragma once

#include "resource.h"

// GtrClientDlg 对话框
#include "HostService.h"
#include "Dispatcher.h"
#include "PromptDlg.h"
#include "afxcmn.h"
#include "afxwin.h"
using namespace client;

class GtrClientDlg : public CDialog
{
	DECLARE_DYNAMIC(GtrClientDlg)

	//CPromptDlg _prompt;
	FILE* _fp;
	
public:
	GtrClientDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~GtrClientDlg();
	CRITICAL_SECTION _cs;

// 对话框数据
	enum { IDD = IDD_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLvnItemchangedRobotType(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedAbort();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedTest();

	DECLARE_MESSAGE_MAP()
public:
	UINT RunAsClient(LPVOID lpUser);
	CListCtrl m_RobotList;
	CString m_strStatus;
	void insertLog(const char* szMsg);
	void setStatusMsg(const char* szMsg);
	CEdit m_LogView;
};
