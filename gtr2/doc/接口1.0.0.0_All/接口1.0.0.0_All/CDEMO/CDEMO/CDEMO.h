// CDEMO.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCDEMOApp:
// �йش����ʵ�֣������ CDEMO.cpp
//

class CCDEMOApp : public CWinApp
{
public:
	CCDEMOApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCDEMOApp theApp;