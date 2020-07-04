#include "StdAfx.h"
#include "CMainWnd.h"

#include "mycontrol/CSkinPikerPictureItemUI.h"

void test_my_main_wnd()
{
	// 程序实例
	//CPaintManagerUI::SetInstance(hInstance);//设置进程的实例句柄，这个值会在注册窗口类时使用

	// 配置资源路径
	// 资源路径
	CDuiString sRecoursePath;
	sRecoursePath.Format(_T("%s\\Skin"), CPaintManagerUI::GetCurrentPath());
	CPaintManagerUI::SetResourcePath(sRecoursePath);

	// 创建窗口
	CMainWnd* pMainWnd = new CMainWnd();
	pMainWnd->Create(NULL, _T("MainWndOfDuilib"), WS_POPUP | WS_VISIBLE, 0);
	//pMainWnd->CenterWindow();
	pMainWnd->ShowModal();

	// 启动消息循环
	//CPaintManagerUI::MessageLoop();
}

////////////////////////////////////////////////////
CMainWnd::CMainWnd(void)
{
}

CMainWnd::~CMainWnd(void)
{
}

CDuiString CMainWnd::GetSkinFile()
{
	return _T("main.xml");// 名字可以按照窗口类名字取
}

LPCTSTR CMainWnd::GetWindowClassName(void) const
{
	return _T("MainWnd"); // 名字可以按照窗口类名字取
}


DuiLib::CDuiString CMainWnd::GetSkinFolder()
{
	return _T("");
}

void CMainWnd::Notify(TNotifyUI& msg)
{
	if (msg.sType == _T("click"))
	{
		LPCTSTR pszCtrlName = msg.pSender->GetName().GetData();
		if (_tcscmp(pszCtrlName, _T("btn_sysmin")) == 0)
		{
			Minimize();
		}
		if (_tcscmp(pszCtrlName, _T("btn_sysmax")) == 0)
		{
			Maximize();
			CControlUI* pControl = static_cast<CControlUI*>(m_PaintManager.FindControl(_T("btn_sysmax")));
			if (pControl) pControl->SetVisible(false);
			pControl = static_cast<CControlUI*>(m_PaintManager.FindControl(_T("btn_restore")));
			if (pControl) pControl->SetVisible(true);
		}
		if (_tcscmp(pszCtrlName, _T("btn_restore")) == 0)
		{
			Restore();
			CControlUI* pControl = static_cast<CControlUI*>(m_PaintManager.FindControl(_T("btn_sysmax")));
			if (pControl) pControl->SetVisible(true);
			pControl = static_cast<CControlUI*>(m_PaintManager.FindControl(_T("btn_restore")));
			if (pControl) pControl->SetVisible(false);
		}
		else if (_tcscmp(pszCtrlName, _T("btn_sysclose")) == 0)
		{
			Close(IDOK);
		}
		else if (_tcscmp(pszCtrlName, _T("btn_ok")) == 0)
		{

		}
		else if (_tcscmp(pszCtrlName, _T("btn_back")) == 0)
		{
		}
		else if (_tcscmp(pszCtrlName, _T("btn_forward")) == 0)
		{
		}
		else if (_tcscmp(pszCtrlName, _T("btn_refresh")) == 0
			|| _tcscmp(pszCtrlName, _T("btn_refresh_new")) == 0)
		{
		}
		else if (_tcscmp(pszCtrlName, _T("btn_dev_tools")) == 0)
		{
		}
		else if (_tcscmp(pszCtrlName, _T("btn_stop")) == 0)
		{			
		}
	}
	WindowImplBase::Notify(msg);
}

void CMainWnd::Minimize()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
}

void CMainWnd::Maximize()
{
	SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE, 0);
}

void CMainWnd::Restore()
{
	SendMessage(WM_SYSCOMMAND, SC_RESTORE, 0);
}

CControlUI* CMainWnd::CreateControl(LPCTSTR pstrClass)
{
	if (_tcsicmp(pstrClass, _T("SkinPikerPictureItem")) == 0)
		return	new CSkinPikerPictureItemUI();

	return NULL;
}