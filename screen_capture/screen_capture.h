
// screen_capture.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cscreen_captureApp:
// �йش����ʵ�֣������ screen_capture.cpp
//

class Cscreen_captureApp : public CWinAppEx
{

	public:
//*******************************
	HWND m_hwndDlg;
//*******************************
public:
	Cscreen_captureApp();

// ��д
	public:
	virtual BOOL InitInstance();
	virtual BOOL ProcessMessageFilter(int code, LPMSG lpMsg);
// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cscreen_captureApp theApp;