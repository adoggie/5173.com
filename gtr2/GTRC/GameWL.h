// GameWL.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGameWLApp:
// �йش����ʵ�֣������ GameWL.cpp
//

class CGameWLApp : public CWinApp
{
	HANDLE m_hMutex;
public:
	CGameWLApp();

// ��д
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CGameWLApp theApp;