#pragma once
#include "afxwin.h"
#include "resource.h"

// CPromptDlg �Ի���

class CPromptDlg : public CDialog
{
	DECLARE_DYNAMIC(CPromptDlg)

public:
	CPromptDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPromptDlg();

// �Ի�������
	enum { IDD = IDD_PROMPT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_Log;
	void insertLog(const char* szMsg);
};
