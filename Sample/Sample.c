#include <Windows.h>

#include <shlwapi.h>
#pragma comment(lib,"Shlwapi.lib")

#include <stdio.h>

#include "../EasyWinModernControl/EasyWinMdrnCtrlWrapper.h"

#if _WIN64
#pragma comment(lib,"..\\x64\\Debug\\EasyWinModernControl.lib")
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
HWND g_RadioBtnPlaceHwnd = NULL;
HWND g_RadioBtnPlaceHwnd2 = NULL;
HWND g_CalendarDatePickerPlaceHwnd = NULL;
HWND g_DateLabel = NULL;
HWND g_ProgressbarPlaceHwnd = NULL;
HWND g_ProgressbarPlaceHwnd2 = NULL;
HWND g_ProgressbarPlaceHwnd3 = NULL;
HWND g_HyperLinkPlaceHwnd = NULL;

PEASYMODERNTEXTBOX g_TextboxInfo = NULL;
PEASYMODERNBTN g_ButtonInfo = NULL;
PEASYMODERNBTN g_ButtonInfo2 = NULL;
PEASYMODERNSLIDEBAR g_SlidebarInfo = NULL;
PEASYMODERNPROGRESSRING g_ProgressringInfo = NULL;
PEASYMODERNTIMEPICKER g_TimePickerInfo = NULL;
PEASYMODERNPWDBOX g_PasswordBoxInfo = NULL;
PEASYMODERNRADIOBTN g_RadioBtnInfo = NULL;
PEASYMODERNRADIOBTN g_RadioBtnInfo2 = NULL;
PEASYMODERNCALENDARDATEPICKER g_CalendarDatePickerInfo = NULL;
PEASYMODERNPROGRESSBAR g_ProgressbarInfo = NULL;
PEASYMODERNPROGRESSBAR g_ProgressbarInfo2 = NULL;
PEASYMODERNPROGRESSBAR g_ProgressbarInfo3 = NULL;
PEASYMODERNHYPERLINK g_HyperLinkInfo = NULL;

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

BOOL __stdcall _RadioBtnChanged(LPCWSTR groupName, DWORD selectedIdx, PVOID userData) {

	return TRUE;
}

BOOL __stdcall _CalendarDateChanged(FILETIME selectedDate, PVOID userData) {
	WCHAR buffer[64];
	DWORD dwFlags = FDTF_SHORTDATE | FDTF_NOAUTOREADINGORDER;

	SHFormatDateTime(&selectedDate, &dwFlags, buffer, 64);

	SetWindowTextW(g_DateLabel, buffer);

	return TRUE;
}

LRESULT __stdcall _MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int main()
{
	if (!EasyWinModernCtrl_IsSystemSupport()) {
		MessageBoxW(0, L"Not Supported OS.", L"Sample", 0);
		return -1;
	}

	EasyWinModernCtrl_InitializeApartment(0);

	WNDCLASSEX wClass = { 0 };
	wClass.cbSize = sizeof(wClass);
	wClass.style = 0;
	wClass.lpfnWndProc = (WNDPROC)_MainWindowProc;
	wClass.hIcon = 0;
	wClass.lpszClassName = L"MainWindow";
	wClass.hbrBackground = CreateSolidBrush(RGB(255,255,255));
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

	//must call
	EasyWinModernCtrl_UnInitialize();

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
		g_PasswordPlaceHwnd = CreateWindowW(L"static", L"", WS_CHILD, 5, 250, 300, 60, hwnd, NULL, NULL, NULL);
		ShowWindow(g_PasswordPlaceHwnd, SW_SHOW);

		//create uwp passwordbox
		g_PasswordBoxInfo = EasyWinModernCtrl_CreatePasswordBox(L"pwdbox_1", L"Enter Password", L"placeholder text", 0);
		EasyWinModernCtrl_ShowControl(g_PasswordBoxInfo, g_PasswordPlaceHwnd);

		//create uwp radio btn place
		g_RadioBtnPlaceHwnd = CreateWindowW(L"static", L"", WS_CHILD, 5, 350, 350, 60, hwnd, NULL, NULL, NULL);
		ShowWindow(g_RadioBtnPlaceHwnd, SW_SHOW);

		g_RadioBtnInfo = EasyWinModernCtrl_CreateRadioButton(L"sel_option", L"Select Options", FALSE);

		EasyWinModernCtrl_RadioBtnSetValueChangedCallback(g_RadioBtnInfo, &_RadioBtnChanged, NULL);

		EasyWinModernCtrl_RadioBtnInsertItem(g_RadioBtnInfo, 0, L"option1", FALSE, TRUE);
		EasyWinModernCtrl_RadioBtnInsertItem(g_RadioBtnInfo, 1, L"option2", FALSE, FALSE);
		EasyWinModernCtrl_RadioBtnInsertItem(g_RadioBtnInfo, 2, L"option3", FALSE, TRUE);

		EasyWinModernCtrl_RadioBtnSetCheckedItem(g_RadioBtnInfo, 0);

		EasyWinModernCtrl_ShowControl(g_RadioBtnInfo, g_RadioBtnPlaceHwnd);

		//create uwp radio btn place2
		g_RadioBtnPlaceHwnd2 = CreateWindowW(L"static", L"", WS_CHILD, 400, 350, 100, 350, hwnd, NULL, NULL, NULL);
		ShowWindow(g_RadioBtnPlaceHwnd2, SW_SHOW);

		//create uwp radio btn (vertical mode)
		g_RadioBtnInfo2 = EasyWinModernCtrl_CreateRadioButton(L"sel_option2", NULL, TRUE);
		EasyWinModernCtrl_RadioBtnSetValueChangedCallback(g_RadioBtnInfo2, &_RadioBtnChanged, NULL);

		EasyWinModernCtrl_RadioBtnInsertItem(g_RadioBtnInfo2, 0, L"option1", FALSE, TRUE);
		EasyWinModernCtrl_RadioBtnInsertItem(g_RadioBtnInfo2, 1, L"option2", FALSE, FALSE);
		EasyWinModernCtrl_RadioBtnInsertItem(g_RadioBtnInfo2, 2, L"option3", FALSE, TRUE);

		EasyWinModernCtrl_ShowControl(g_RadioBtnInfo2, g_RadioBtnPlaceHwnd2);

		//create uwp Calendar DatePicker place
		g_CalendarDatePickerPlaceHwnd = CreateWindow(L"static", L"", WS_CHILD, 600, 350, 200, 55, hwnd, NULL, NULL, NULL);
		ShowWindow(g_CalendarDatePickerPlaceHwnd, SW_SHOW);
		//create uwp Calendar DatePicker
		g_CalendarDatePickerInfo = EasyWinModernCtrl_CreateCalendarDatePicker(L"sel_option2",L"Select Date");
		EasyWinModernCtrl_ShowControl(g_CalendarDatePickerInfo, g_CalendarDatePickerPlaceHwnd);

		FILETIME now;
		GetSystemTimeAsFileTime(&now);
		//set current date for calendar date picker
		EasyWinModernCtrl_CalendarDatePickerSetDate(g_CalendarDatePickerInfo, now);
		EasyWinModernCtrl_CalendarDatePickerSetSelectedDateCallback(g_CalendarDatePickerInfo, &_CalendarDateChanged, NULL);

		//create uwp calender date picker callback window (optional)
		g_DateLabel = CreateWindowW(L"static", L"", WS_CHILD, 800, 350, 250, 30, hwnd, NULL, NULL, NULL);
		ShowWindow(g_DateLabel, SW_SHOW);

		//create uwp progress bar place
		g_ProgressbarPlaceHwnd = CreateWindowW(L"static", L"", WS_CHILD, 10, 450, 200, 5, hwnd, NULL, NULL, NULL);
		ShowWindow(g_ProgressbarPlaceHwnd, SW_SHOW);

		//create uwp progress bar
		g_ProgressbarInfo = EasyWinModernCtrl_CreateProgressbar(L"progress_1", 0, 10);
		EasyWinModernCtrl_ShowControl(g_ProgressbarInfo, g_ProgressbarPlaceHwnd);
		EasyWinModernCtrl_ProgressbarSetValue(g_ProgressbarInfo, FALSE, FALSE , 3);

		//create uwp progress bar place2
		g_ProgressbarPlaceHwnd2 = CreateWindowW(L"static", L"", WS_CHILD, 10, 470, 200, 5, hwnd, NULL, NULL, NULL);
		ShowWindow(g_ProgressbarPlaceHwnd2, SW_SHOW);

		//create uwp progress bar2
		g_ProgressbarInfo2 = EasyWinModernCtrl_CreateProgressbar(L"progress_2", 0, 10);
		EasyWinModernCtrl_ShowControl(g_ProgressbarInfo2, g_ProgressbarPlaceHwnd2);
		EasyWinModernCtrl_ProgressbarSetValue(g_ProgressbarInfo2, FALSE, TRUE , 3);

		//create uwp progress bar place2
		g_ProgressbarPlaceHwnd3 = CreateWindowW(L"static", L"", WS_CHILD, 10, 490, 200, 5, hwnd, NULL, NULL, NULL);
		ShowWindow(g_ProgressbarPlaceHwnd3, SW_SHOW);

		//create uwp progress bar2
		g_ProgressbarInfo3 = EasyWinModernCtrl_CreateProgressbar(L"progress_3", 0, 10);
		EasyWinModernCtrl_ShowControl(g_ProgressbarInfo3, g_ProgressbarPlaceHwnd3);
		EasyWinModernCtrl_ProgressbarSetValue(g_ProgressbarInfo3, TRUE, FALSE, 0);

		//create hyperlink place
		g_HyperLinkPlaceHwnd = CreateWindowW(L"static", L"", WS_CHILD, 500, 450, 250, 35, hwnd, NULL, NULL, NULL);
		ShowWindow(g_HyperLinkPlaceHwnd, SW_SHOW);

		g_HyperLinkInfo = EasyWinModernCtrl_CreateHyperlink(L"link1", L"Go to homepage");
		EasyWinModernCtrl_HyperlinkSetNavigateUri(g_HyperLinkInfo, L"https://github.com/bho3538");
		EasyWinModernCtrl_ShowControl(g_HyperLinkInfo, g_HyperLinkPlaceHwnd);

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
		EasyWinModernCtrl_AdjustLayout(g_RadioBtnInfo);
		EasyWinModernCtrl_AdjustLayout(g_RadioBtnInfo2);
		EasyWinModernCtrl_AdjustLayout(g_CalendarDatePickerInfo);
		EasyWinModernCtrl_AdjustLayout(g_ProgressbarInfo);
		EasyWinModernCtrl_AdjustLayout(g_ProgressbarInfo2);
		EasyWinModernCtrl_AdjustLayout(g_ProgressbarInfo3);
		EasyWinModernCtrl_AdjustLayout(g_HyperLinkInfo);
	}; break;
	case WM_CLOSE: {
		EasyWinModernCtrl_CloseControl(g_TextboxInfo);
		EasyWinModernCtrl_CleanupControl(g_TextboxInfo);

		EasyWinModernCtrl_CloseControl(g_PasswordBoxInfo);
		EasyWinModernCtrl_CleanupControl(g_PasswordBoxInfo);

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

		EasyWinModernCtrl_CloseControl(g_RadioBtnInfo);
		EasyWinModernCtrl_CleanupControl(g_RadioBtnInfo);
		EasyWinModernCtrl_CloseControl(g_RadioBtnInfo2);
		EasyWinModernCtrl_CleanupControl(g_RadioBtnInfo2);
		EasyWinModernCtrl_CloseControl(g_CalendarDatePickerInfo);
		EasyWinModernCtrl_CleanupControl(g_CalendarDatePickerInfo);

		EasyWinModernCtrl_CloseControl(g_ProgressbarInfo);
		EasyWinModernCtrl_CleanupControl(g_ProgressbarInfo);
		EasyWinModernCtrl_CloseControl(g_ProgressbarInfo2);
		EasyWinModernCtrl_CleanupControl(g_ProgressbarInfo2);
		EasyWinModernCtrl_CloseControl(g_ProgressbarInfo3);
		EasyWinModernCtrl_CleanupControl(g_ProgressbarInfo3);

		EasyWinModernCtrl_CloseControl(g_HyperLinkInfo);
		EasyWinModernCtrl_CleanupControl(g_HyperLinkInfo);

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
		DestroyWindow(hwnd);
	}; break;
	case WM_DESTROY: {
		PostQuitMessage(0);
		return 0;
	}; break;
	}

	return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}
