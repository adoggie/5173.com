#pragma once
#include "afxwin.h"
#include "resource.h"

// CPromptDlg 对话框

class CPromptDlg : public CDialog
{
	DECLARE_DYNAMIC(CPromptDlg)

public:
	CPromptDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPromptDlg();

// 对话框数据
	enum { IDD = IDD_PROMPT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_Log;
	void insertLog(const char* szMsg);
};
