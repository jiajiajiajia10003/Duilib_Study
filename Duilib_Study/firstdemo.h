#pragma once
#include <windows.h>
#include <tchar.h>

#include "UIlib.h"
using namespace DuiLib;

class CDuiFrameWnd : public CWindowWnd, public INotifyUI
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual void Notify(TNotifyUI& msg) {}
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;
		if (uMsg == WM_CREATE)
		{
			CControlUI *pWnd = new CButtonUI;
			pWnd->SetText(_T("Hello World")); // 设置文字
			pWnd->SetBkColor(0xFF00FF00); // 设置背景色
			m_PaintManager.Init(m_hWnd);
			m_PaintManager.AttachDialog(pWnd);
			return lRes;
		}
		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
		{
			return lRes;
		}
		return __super::HandleMessage(uMsg, wParam, lParam);
	}
protected:
	CPaintManagerUI m_PaintManager;
};


void test_show_first_window(bool isShowModal)
{
	if (isShowModal)
	{
		// 创建模态窗口
		CDuiFrameWnd wnd;;
		wnd.Create(NULL, _T("简单测试 Modal"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
		wnd.ShowModal();
	}
	else
	{
		// 创建非模态窗口
		CDuiFrameWnd* pFrame = new CDuiFrameWnd();
		if (pFrame == NULL)
			return;

		pFrame->Create(NULL, _T("简单测试 NoModal"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
		pFrame->CenterWindow();
		pFrame->ShowWindow(true);
		CPaintManagerUI::MessageLoop();
	}
}
