// CDEMODlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CCDEMODlg �Ի���
class CCDEMODlg : public CDialog
{
// ����
public:
	CCDEMODlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
