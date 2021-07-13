#include "stdafx.h"

#include "CModernTextbox.h"

using namespace EasyWinModernControl;

HWND g_LabelHwnd = NULL;
HWND g_TextboxPlaceHwnd = NULL;
CModernTextbox* g_TextboxInfo = NULL;

LRESULT __stdcall _MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int main()
{
	WNDCLASSEX wClass = { 0 };
	wClass.cbSize = sizeof(wClass);

	wClass.style = 0;
	wClass.lpfnWndProc = (WNDPROC)_MainWindowProc;
	wClass.hIcon = 0;
	wClass.lpszClassName = L"MainWindow";
	RegisterClassEx(&wClass);

	HWND MainWindow = CreateWindowExW(0,
		L"MainWindow",
		L"MainWindow",
		WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS |
		WS_CLIPCHILDREN, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		0, 0, GetModuleHandle(0), (void*)0);

	ShowWindow(MainWindow, SW_SHOWMAXIMIZED);
	UpdateWindow(MainWindow);
	MSG msg;

	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}


	return 0;
}

LRESULT __stdcall _MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	switch (uMsg) {
		case WM_CREATE: {
			g_LabelHwnd = CreateWindowW(L"Button", L"Win32 Control", WS_CHILD, 5, 5, 140, 100, hwnd, NULL, NULL, NULL);
			ShowWindow(g_LabelHwnd, SW_SHOW);

			g_TextboxPlaceHwnd = CreateWindowW(L"static", L"", WS_CHILD, 150, 5, 200, 100, hwnd, NULL, NULL, NULL);
			ShowWindow(g_TextboxPlaceHwnd, SW_SHOW);

			g_TextboxInfo = new CModernTextbox(L"nameInput",L"awef",L"placeholder text",TRUE,TRUE);

			g_TextboxInfo->Show(g_TextboxPlaceHwnd);
			
			//

		}; break;
		case WM_SIZE: {
			if (g_TextboxInfo) {
				g_TextboxInfo->AdjustLayout();
			}
		}; break;
		case WM_COMMAND: {
			if (g_TextboxInfo) {
				MessageBox(hwnd, g_TextboxInfo->GetText(), L"EasyWinModernControl", 0);
				g_TextboxInfo->SetReadonlyMode(TRUE);
			}
		}; break;
	}

	return DefWindowProcW(hwnd, uMsg,wParam,lParam);
}
