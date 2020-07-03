#include <windows.h>
#include <tchar.h>

#include "UIlib.h"
using namespace DuiLib;
#ifdef _DEBUG
#   pragma comment(lib, "../lib/DuiLib/DuiLib_d.lib")
#else
#   pragma comment(lib, "DuiLib/DuiLib.lib")
#endif

#include "firstdemo.h"

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//::MessageBox(NULL, _T("Hello World!"), NULL, NULL);
	CPaintManagerUI::SetInstance(hInstance);//设置进程的实例句柄，这个值会在注册窗口类时使用

	test_show_first_window(true);

	return 0; 
}