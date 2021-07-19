#include "stdafx.h"

#include "EasyWinMdrnCtrlWrapper.h"

#include "CModernSlidebar.h"
#include "CModernProgressring.h"
#include "CModernTimePicker.h"

HWND g_LabelHwnd = NULL;
HWND g_TextboxPlaceHwnd = NULL;
HWND g_ButtonPlaceHwnd = NULL;
HWND g_SlidebarPlaceHwnd = NULL;
HWND g_SlidebarValueLabel = NULL;
HWND g_ProgressRingPlaceHwnd = NULL;
HWND g_TimePickerPlaceHwnd = NULL;
HWND g_TimeLabel = NULL;

PEASYMODERNTEXTBOX g_TextboxInfo = NULL;
PEASYMODERNBTN g_ButtonInfo = NULL;
PEASYMODERNSLIDEBAR g_SlidebarInfo = NULL;
PEASYMODERNPROGRESSRING g_ProgressringInfo = NULL;
PEASYMODERNTIMEPICKER g_TimePickerInfo = NULL;

BOOL __stdcall _SlidebarChanged(DWORD id, DOUBLE currentValue, PVOID userData) {
	CHAR str[10];

	sprintf_s(str,10, "%0.lf", currentValue);

	SetWindowTextA(g_SlidebarValueLabel, str);

	return TRUE;
}

BOOL __stdcall _ButtonClicked(DWORD id, PVOID userData) {

	MessageBoxW((HWND)userData, L"Button Clicked", L"", 0);

	return TRUE;
}

BOOL __stdcall _TimeSelected(INT64 seconds, PVOID userData) {
	CHAR str[10];

	INT hour = seconds / 3600;
	INT minute = ((seconds - (hour * 3600)) / 60);

	sprintf_s(str, 10, "%d:%d",hour,minute);

	SetWindowTextA(g_TimeLabel, str);

	return TRUE;
}

LRESULT __stdcall _MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int main()
{
	if (!EasyWinModernCtrl_IsSystemSupport()) {
		MessageBoxW(0, L"Not Supported", L"", 0);
		return -1;
	}


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

	ShowWindow(MainWindow, SW_SHOW);
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
			g_LabelHwnd = CreateWindowW(L"Button", L"Get Textbox Text", WS_CHILD, 5, 5, 140, 100, hwnd, NULL, NULL, NULL);
			ShowWindow(g_LabelHwnd, SW_SHOW);

			g_TextboxPlaceHwnd = CreateWindowW(L"static", L"", WS_CHILD, 150, 5, 200, 100, hwnd, NULL, NULL, NULL);
			ShowWindow(g_TextboxPlaceHwnd, SW_SHOW);

			g_TextboxInfo = EasyWinModernCtrl_CreateTextbox(L"password", L"Enter Text", L"placeholder text", TRUE, TRUE, 0);

			EasyWinModernCtrl_ShowControl(g_TextboxInfo, g_TextboxPlaceHwnd);

			g_ButtonPlaceHwnd = CreateWindowW(L"static", L"", WS_CHILD, 360, 5, 200, 100, hwnd, NULL, NULL, NULL);
			ShowWindow(g_ButtonPlaceHwnd, SW_SHOW);
			
			g_ButtonInfo = EasyWinModernCtrl_CreateButton(L"btn_test",1, L"Click");

			EasyWinModernCtrl_ButtonSetClickCallback(g_ButtonInfo, &_ButtonClicked, hwnd);
			EasyWinModernCtrl_ButtonSetUseAccentColor(g_ButtonInfo, TRUE);
			EasyWinModernCtrl_ShowControl(g_ButtonInfo,g_ButtonPlaceHwnd);

			g_SlidebarPlaceHwnd = CreateWindowW(L"static", L"", WS_CHILD, 5, 150, 200, 30, hwnd, NULL, NULL, NULL);
			ShowWindow(g_SlidebarPlaceHwnd, SW_SHOW);

			g_SlidebarValueLabel = CreateWindowW(L"static", L"ff", WS_CHILD, 210, 150, 30, 30, hwnd, NULL, NULL, NULL);
			ShowWindow(g_SlidebarValueLabel, SW_SHOW);
			
			g_SlidebarInfo = EasyWinModernCtrl_CreateSlidebar(L"awef", 1, 0, 100, 10, 0);
			EasyWinModernCtrl_SlidebarSetValueChangedCallback(g_SlidebarInfo, &_SlidebarChanged, NULL);
			EasyWinModernCtrl_ShowControl(g_SlidebarInfo,g_SlidebarPlaceHwnd);

			g_ProgressRingPlaceHwnd = CreateWindowW(L"static", L"", WS_CHILD, 310, 150, 30, 30, hwnd, NULL, NULL, NULL);
			ShowWindow(g_ProgressRingPlaceHwnd, SW_SHOW);

			g_ProgressringInfo = EasyWinModernCtrl_CreateProgressring(L"loadingRing");
			EasyWinModernCtrl_ShowControl(g_ProgressringInfo, g_ProgressRingPlaceHwnd);

			g_TimePickerPlaceHwnd = CreateWindowW(L"static", L"", WS_CHILD, 350, 150, 250, 60, hwnd, NULL, NULL, NULL);
			ShowWindow(g_TimePickerPlaceHwnd, SW_SHOW);

			g_TimeLabel = CreateWindowW(L"static", L"", WS_CHILD, 600, 150, 250, 30, hwnd, NULL, NULL, NULL);
			ShowWindow(g_TimeLabel, SW_SHOW);

			g_TimePickerInfo = EasyWinModernCtrl_CreateTimePicker(L"SelTime", L"Select Time", FALSE);
			EasyWinModernCtrl_TimePickerSetTimeUsingSeconds(g_TimePickerInfo,56100);
			EasyWinModernCtrl_TimePickerSetValueChangedCallback(g_TimePickerInfo, &_TimeSelected, hwnd);
			EasyWinModernCtrl_ShowControl(g_TimePickerInfo, g_TimePickerPlaceHwnd);

		}; break;
		case WM_SIZE: {
			if (g_TextboxInfo) {
				EasyWinModernCtrl_AdjustLayout(g_TextboxInfo);
			}
		}; break;
		case WM_COMMAND: {
			if (g_TextboxInfo) {
				MessageBox(hwnd, EasyWinModernCtrl_TextboxGetText(g_TextboxInfo), L"EasyWinModernControl", 0);
			}
		}; break;
		case WM_DESTROY: {

			delete g_ButtonInfo;
			delete g_TextboxInfo;
		}; break;
	}

	return DefWindowProcW(hwnd, uMsg,wParam,lParam);
}
