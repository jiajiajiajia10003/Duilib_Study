#pragma once

#include <windows.h>
#include <tchar.h>

#include "UIlib.h"
using namespace DuiLib;

void test_my_main_wnd();


class CMainWnd : public WindowImplBase
{
public:
	CMainWnd(void);
	virtual ~CMainWnd(void);

public:
	virtual CDuiString GetSkinFile();
	virtual LPCTSTR GetWindowClassName(void) const;
	virtual CDuiString GetSkinFolder();

	void Notify(TNotifyUI& msg);

	void Minimize();
	void Maximize();
	void Restore();

};




