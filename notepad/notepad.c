#include "stdafx.h"

#include "file.h"

#include "../EasyWinModernControl/EasyWinMdrnCtrlWrapper.h"


HWND g_MainWindow = NULL;
HWND g_TextAreaWindow = NULL;
HWND g_Statusbar = NULL;

//Menu
HMENU hMenu, hSubMenu = NULL;
#define NP_MENUID_OPEN 1
#define NP_MENUID_ABOUT 2


PEASYMODERNTEXTBOX g_Textbox = NULL;


LRESULT __stdcall _MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
	if (!EasyWinModernCtrl_IsSystemSupport()) {
		MessageBoxW(0, L"Not Supported OS.", L"Modern Notepad", 0);
		return -1;
	}

	EasyWinModernCtrl_InitializeApartment(0);

	WNDCLASSEX wClass = { 0 };
	wClass.cbSize = sizeof(wClass);
	wClass.style = 0;
	wClass.lpfnWndProc = (WNDPROC)_MainWindowProc;
	wClass.hIcon = 0;
	wClass.lpszClassName = L"MainWindow";
	wClass.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
	RegisterClassEx(&wClass);

	g_MainWindow = CreateWindowExW(0,
		L"MainWindow",
		L"Sample UWP Control Notepad (View only)",
		WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS |
		WS_CLIPCHILDREN, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		0, 0, NULL, NULL);

	g_TextAreaWindow = CreateWindowW(L"static", L"", WS_CHILD, 600, 350, 200, 55, g_MainWindow, NULL, NULL, NULL);

	g_Textbox = EasyWinModernCtrl_CreateTextbox(L"MainText", NULL, NULL, TRUE, TRUE, 0);
	EasyWinModernCtrl_TextboxSetSpellCheck(g_Textbox, FALSE);

	EasyWinModernCtrl_ShowControl(g_Textbox, g_TextAreaWindow);

	g_Statusbar = CreateStatusWindowW(WS_CHILD | WS_VISIBLE, L"Sample UWP Textbox notepad", g_MainWindow, 1000);

	ShowWindow(g_MainWindow, SW_SHOW);
	UpdateWindow(g_MainWindow);

	ShowWindow(g_TextAreaWindow, SW_SHOW);
	UpdateWindow(g_TextAreaWindow);



	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	//must call
	EasyWinModernCtrl_UnInitialize();

	return 0;
}

LRESULT __stdcall _MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
		case WM_CREATE: {
			hMenu = CreateMenu();

			hSubMenu = CreatePopupMenu();
			AppendMenuW(hSubMenu, MF_STRING, 1, L"O&pen");
			AppendMenuW(hSubMenu, MF_STRING, 1, L"A&bout");
			AppendMenuW(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, L"&File");

			SetMenu(hwnd, hMenu);

		}; break;
		case WM_SIZE: {
			RECT rect = { 0, };
			RECT statusbarRect = { 0, };

			GetClientRect(g_MainWindow, &rect);
			GetClientRect(g_Statusbar, &statusbarRect);
			SetWindowPos(g_TextAreaWindow, NULL, 0, 0, rect.right - rect.left, rect.bottom - rect.top - (statusbarRect.bottom - statusbarRect.top), SWP_SHOWWINDOW);

			EasyWinModernCtrl_AdjustLayout(g_Textbox);
			SendMessage(g_Statusbar, WM_SIZE, wParam, lParam);
		}; break;
		case WM_COMMAND: {
			switch (LOWORD(wParam)) {
				case NP_MENUID_OPEN: {
					OpenFileFromFileDialog();
					LPSTR data = NULL;
					ULONGLONG size = 0;
					GetFileData(&data, &size);

					if (size < 536870912) { //512mb
						LPWSTR test = NULL;
						INT dataSize = 0;
						ConvertUnicodeBuffer(data, (INT)size, &test, &dataSize);

						EasyWinModernCtrl_TextboxSetTextWithSize(g_Textbox, test, dataSize);
						free(test);
					}
					else {
						MessageBoxW(g_MainWindow,L"File is too large to open.", L"Error", 0);
					}

					free(data);
					
				}; break;
				case NP_MENUID_ABOUT: {
					MessageBoxW(g_MainWindow, L"Sample UWP Control notepad", L"https://github.com/bho3538/EasyWinModernControl", 0);
				}; break;
			}
		}; break;
		case WM_CLOSE: {
			EasyWinModernCtrl_CloseControl(g_Textbox);
			EasyWinModernCtrl_CleanupControl(g_Textbox);
			g_Textbox = NULL;

			DestroyMenu(hMenu);
			DestroyMenu(hSubMenu);
			CloseWindow(g_Statusbar);
			DestroyWindow(g_Statusbar);
			CloseWindow(g_TextAreaWindow);
			DestroyWindow(g_TextAreaWindow);
			CloseWindow(g_MainWindow);
			DestroyWindow(g_MainWindow);

			NPCloseFile();
		}; break;
		case WM_DESTROY: {
			PostQuitMessage(0);
			return 0;
		}; break;
	}

	return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}