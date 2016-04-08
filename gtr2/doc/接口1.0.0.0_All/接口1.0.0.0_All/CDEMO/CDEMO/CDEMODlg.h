// CDEMODlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CCDEMODlg 对话框
class CCDEMODlg : public CDialog
{
// 构造
public:
	CCDEMODlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedBtnDo();
	afx_msg void OnBnClickedBtnInit();
	CEdit m_edipic;
	CEdit m_edi_xy;
	CEdit m_edi_rel;
	//int m_rb_qq;
	//int m_rb_ks;
	afx_msg void OnBnClickedRadioWm();
	int m_rb_wm;
	afx_msg void OnBnClickedBtnDlgpic();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnTest();
	afx_msg void OnBnClickedBtntest3();
};
