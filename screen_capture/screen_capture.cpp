
// screen_capture.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "screen_capture.h"
#include "screen_captureDlg.h"
#include "CatchScreenDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cscreen_captureApp

BEGIN_MESSAGE_MAP(Cscreen_captureApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// Cscreen_captureApp ����

Cscreen_captureApp::Cscreen_captureApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
	m_hwndDlg=NULL;
}


// Ψһ��һ�� Cscreen_captureApp ����

Cscreen_captureApp theApp;


// Cscreen_captureApp ��ʼ��

BOOL Cscreen_captureApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	Cscreen_captureDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

//********************************************************************************
#define SHIFTED 0x8000 
//********************************************************************************

BOOL Cscreen_captureApp::ProcessMessageFilter(int code, LPMSG lpMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_hwndDlg!=NULL)
	{   //�ж���Ϣ�������Ϣ�ǴӶԻ��򷢳��Ļ������ӿؼ������ģ��ͽ��д���
		if((lpMsg->hwnd==m_hwndDlg) || ::IsChild(m_hwndDlg,lpMsg->hwnd))
		{
			//�����Ϣ��WM_KEYDOWN
			//�÷��������λ��
			if(lpMsg->message==WM_KEYDOWN)
			{
				CRect rect(0,0,0,0);
				CCatchScreenDlg * pDlg=(CCatchScreenDlg *)AfxGetMainWnd();
				
				rect=pDlg->m_rectTracker.m_rect;

				if(pDlg->m_bFirstDraw)
				{
					
					//���Shift�����������������С
					BOOL isShifeDowm=FALSE;
					int nVirtKey;
					nVirtKey = GetKeyState(VK_SHIFT); 
					if (nVirtKey & SHIFTED) 
						isShifeDowm=TRUE;

					switch(lpMsg->wParam)
					{
					case VK_UP:
						//�������Shift,��ֻ����һ��
						if(!isShifeDowm)
							rect.top-=1;
						rect.bottom-=1;
						pDlg->m_rectTracker.m_rect=rect;
						pDlg->PaintWindow();
						break;
					case VK_DOWN:
						if(!isShifeDowm)
							rect.top+=1;
						rect.bottom+=1;
						pDlg->m_rectTracker.m_rect=rect;
						pDlg->PaintWindow();
						break;
					case VK_LEFT:
						if(!isShifeDowm)
							rect.left-=1;
						rect.right-=1;
						pDlg->m_rectTracker.m_rect=rect;
						pDlg->PaintWindow();
						break;
					case VK_RIGHT:
						if(!isShifeDowm)
							rect.left+=1;
						rect.right+=1;
						pDlg->m_rectTracker.m_rect=rect;
						pDlg->PaintWindow();
						break;
					}
				}
			}
			
		}
	} 
	return CWinApp::ProcessMessageFilter(code, lpMsg);
}
//********************************************************************************