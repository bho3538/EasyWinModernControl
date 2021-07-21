#include <Windows.h>

#include "../EasyWinModernControl/EasyWinMdrnCtrlWrapper.h"

#if _WIN64
#pragma comment(lib,"..\\x64\\Release\\EasyWinModernControl.lib")
#else
#pragma comment(lib,"..\\Release\\EasyWinModernControl.lib")
#endif

HWND g_LabelHwnd = NULL;
HWND g_TextboxPlaceHwnd = NULL;
HWND g_PasswordPlaceHwnd = NULL;
HWND g_ButtonPlaceHwnd = NULL;
HWND g_ButtonPlaceHwnd2 = NULL;

HWND g_SlidebarPlaceHwnd = NULL;
HWND g_SlidebarValueLabel = NULL;
HWND g_ProgressRingPlaceHwnd = NULL;
HWND g_TimePickerPlaceHwnd = NULL;
HWND g_TimeLabel = NULL;

PEASYMODERNTEXTBOX g_TextboxInfo = NULL;
PEASYMODERNBTN g_ButtonInfo = NULL;
PEASYMODERNBTN g_ButtonInfo2 = NULL;
PEASYMODERNSLIDEBAR g_SlidebarInfo = NULL;
PEASYMODERNPROGRESSRING g_ProgressringInfo = NULL;
PEASYMODERNTIMEPICKER g_TimePickerInfo = NULL;
PEASYMODERNPWDBOX g_PasswordBoxInfo = NULL;

BOOL __stdcall _SlidebarChanged(DWORD id, DOUBLE currentValue, PVOID userData) {
	CHAR str[10] = { 0, };

	sprintf_s(str, 10, "%0.lf", currentValue);

	SetWindowTextA(g_SlidebarValueLabel, str);

	return TRUE;
}

BOOL __stdcall _ButtonClicked(DWORD id, PVOID userData) {

	MessageBoxW((HWND)userData, L"Button Clicked", L"", 0);

	return TRUE;
}

BOOL __stdcall _TimeSelected(INT64 seconds, PVOID userData) {
	CHAR str[10] = { 0, };

	INT hour = seconds / 3600;
	INT minute = ((seconds - (hour * 3600)) / 60);

	sprintf_s(str, 10, "%d:%d", hour, minute);

	SetWindowTextA(g_TimeLabel, str);

	return TRUE;
}

LRESULT __stdcall _MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int main()
{
	if (!EasyWinModernCtrl_IsSystemSupport()) {
		MessageBoxW(0, L"Not Supported OS.", L"", 0);
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
		L"EasyWinModernControl",
		WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS |
		WS_CLIPCHILDREN, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		0, 0, NULL, NULL);

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
		//create win32 button
		g_LabelHwnd = CreateWindowW(L"Button", L"Get Textbox Text", WS_CHILD, 5, 5, 140, 100, hwnd, NULL, NULL, NULL);
		ShowWindow(g_LabelHwnd, SW_SHOW);

		//create uwp textbox place
		g_TextboxPlaceHwnd = CreateWindowW(L"static", L"", WS_CHILD, 150, 5, 200, 100, hwnd, NULL, NULL, NULL);
		ShowWindow(g_TextboxPlaceHwnd, SW_SHOW);

		//create uwp textbox
		g_TextboxInfo = EasyWinModernCtrl_CreateTextbox(L"testbox_1", L"Enter Text", L"placeholder text", TRUE, TRUE, 0);
		EasyWinModernCtrl_ShowControl(g_TextboxInfo, g_TextboxPlaceHwnd);

		//create uwp button place
		g_ButtonPlaceHwnd = CreateWindowW(L"static", L"", WS_CHILD, 360, 5, 40, 30, hwnd, NULL, NULL, NULL);
		ShowWindow(g_ButtonPlaceHwnd, SW_SHOW);

		//create uwp button
		g_ButtonInfo = EasyWinModernCtrl_CreateButton(L"btn_yes", 1, L"Yes");
		EasyWinModernCtrl_ButtonSetClickCallback(g_ButtonInfo, &_ButtonClicked, hwnd);
		EasyWinModernCtrl_ButtonSetUseAccentColor(g_ButtonInfo, TRUE);
		EasyWinModernCtrl_ShowControl(g_ButtonInfo, g_ButtonPlaceHwnd);

		//create uwp button place2
		g_ButtonPlaceHwnd2 = CreateWindowW(L"static", L"", WS_CHILD, 450, 5, 40, 30, hwnd, NULL, NULL, NULL);
		ShowWindow(g_ButtonPlaceHwnd2, SW_SHOW);

		//create uwp button2 (no accent color)
		g_ButtonInfo2 = EasyWinModernCtrl_CreateButton(L"btn_no", 2, L"No");
		EasyWinModernCtrl_ButtonSetClickCallback(g_ButtonInfo2, &_ButtonClicked, hwnd);
		EasyWinModernCtrl_ShowControl(g_ButtonInfo2, g_ButtonPlaceHwnd2);

		//create uwp slidebar place
		g_SlidebarPlaceHwnd = CreateWindowW(L"static", L"", WS_CHILD, 5, 150, 200, 30, hwnd, NULL, NULL, NULL);
		ShowWindow(g_SlidebarPlaceHwnd, SW_SHOW);
		//create uwp slidebar
		g_SlidebarInfo = EasyWinModernCtrl_CreateSlidebar(L"slidebar1", 1, 0, 100, 10, 0);
		EasyWinModernCtrl_SlidebarSetValueChangedCallback(g_SlidebarInfo, &_SlidebarChanged, NULL);
		EasyWinModernCtrl_ShowControl(g_SlidebarInfo, g_SlidebarPlaceHwnd);

		//create slidebar value callback window (optional)
		g_SlidebarValueLabel = CreateWindowW(L"static", L"0", WS_CHILD, 210, 150, 30, 30, hwnd, NULL, NULL, NULL);
		ShowWindow(g_SlidebarValueLabel, SW_SHOW);

		//create uwp loading progress ring place
		g_ProgressRingPlaceHwnd = CreateWindowW(L"static", L"", WS_CHILD, 310, 150, 30, 30, hwnd, NULL, NULL, NULL);
		ShowWindow(g_ProgressRingPlaceHwnd, SW_SHOW);

		//create uwp loading progress ring
		g_ProgressringInfo = EasyWinModernCtrl_CreateProgressring(L"loadingRing");
		EasyWinModernCtrl_ShowControl(g_ProgressringInfo, g_ProgressRingPlaceHwnd);

		//create uwp time picker place
		g_TimePickerPlaceHwnd = CreateWindowW(L"static", L"", WS_CHILD, 350, 150, 250, 60, hwnd, NULL, NULL, NULL);
		ShowWindow(g_TimePickerPlaceHwnd, SW_SHOW);

		//create uwp time picker
		g_TimePickerInfo = EasyWinModernCtrl_CreateTimePicker(L"SelTime", L"Select Time", FALSE);
		//EasyWinModernCtrl_TimePickerSetTimeUsingSeconds(g_TimePickerInfo, 56100);
		EasyWinModernCtrl_TimePickerSetValueChangedCallback(g_TimePickerInfo, &_TimeSelected, hwnd);
		EasyWinModernCtrl_ShowControl(g_TimePickerInfo, g_TimePickerPlaceHwnd);

		//create uwp time picker callback window (optional)
		g_TimeLabel = CreateWindowW(L"static", L"", WS_CHILD, 600, 150, 250, 30, hwnd, NULL, NULL, NULL);
		ShowWindow(g_TimeLabel, SW_SHOW);

		//create uwp passwordbox place
		g_PasswordPlaceHwnd = CreateWindowW(L"static", L"", WS_CHILD, 5, 250, 200, 100, hwnd, NULL, NULL, NULL);
		ShowWindow(g_PasswordPlaceHwnd, SW_SHOW);

		//create uwp passwordbox
		g_PasswordBoxInfo = EasyWinModernCtrl_CreatePasswordBox(L"pwdbox_1", L"Enter Password", L"placeholder text", 0);
		EasyWinModernCtrl_ShowControl(g_PasswordBoxInfo, g_PasswordPlaceHwnd);

	}; break;
	case WM_COMMAND: {
		if (g_TextboxInfo) {
			MessageBox(hwnd, EasyWinModernCtrl_TextboxGetText(g_TextboxInfo), L"EasyWinModernControl", 0);
		}
	}; break;
	case WM_SIZE: {
		EasyWinModernCtrl_AdjustLayout(g_TextboxInfo);
		EasyWinModernCtrl_AdjustLayout(g_ButtonInfo);
		EasyWinModernCtrl_AdjustLayout(g_ButtonInfo2);
		EasyWinModernCtrl_AdjustLayout(g_SlidebarInfo);
		EasyWinModernCtrl_AdjustLayout(g_ProgressringInfo);
		EasyWinModernCtrl_AdjustLayout(g_TimePickerInfo);
	}; break;
	case WM_DESTROY: {
		EasyWinModernCtrl_CloseControl(g_TextboxInfo);
		EasyWinModernCtrl_CleanupControl(g_TextboxInfo);

		EasyWinModernCtrl_CloseControl(g_ButtonInfo);
		EasyWinModernCtrl_CleanupControl(g_ButtonInfo);

		EasyWinModernCtrl_CloseControl(g_ButtonInfo2);
		EasyWinModernCtrl_CleanupControl(g_ButtonInfo2);

		EasyWinModernCtrl_CloseControl(g_SlidebarInfo);
		EasyWinModernCtrl_CleanupControl(g_SlidebarInfo);

		EasyWinModernCtrl_CloseControl(g_ProgressringInfo);
		EasyWinModernCtrl_CleanupControl(g_ProgressringInfo);

		EasyWinModernCtrl_CloseControl(g_TimePickerInfo);
		EasyWinModernCtrl_CleanupControl(g_TimePickerInfo);

		CloseWindow(g_LabelHwnd);
		DestroyWindow(g_LabelHwnd);

		CloseWindow(g_TextboxPlaceHwnd);
		DestroyWindow(g_TextboxPlaceHwnd);

		CloseWindow(g_ButtonPlaceHwnd);
		DestroyWindow(g_ButtonPlaceHwnd);

		CloseWindow(g_ButtonPlaceHwnd2);
		DestroyWindow(g_ButtonPlaceHwnd2);

		CloseWindow(g_SlidebarPlaceHwnd);
		DestroyWindow(g_SlidebarPlaceHwnd);

		CloseWindow(g_SlidebarValueLabel);
		DestroyWindow(g_SlidebarValueLabel);

		CloseWindow(g_ProgressRingPlaceHwnd);
		DestroyWindow(g_ProgressRingPlaceHwnd);

		CloseWindow(g_TimePickerPlaceHwnd);
		DestroyWindow(g_TimePickerPlaceHwnd);

		CloseWindow(g_TimeLabel);
		DestroyWindow(g_TimeLabel);

		PostQuitMessage(0);
	}; break;
	}

	return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}
