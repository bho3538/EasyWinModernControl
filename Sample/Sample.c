﻿#include <Windows.h>

#include <shlwapi.h>
#pragma comment(lib,"Shlwapi.lib")

#include <stdio.h>

#include "../EasyWinModernControl/EasyWinMdrnCtrlWrapper.h"
#include "..\EasyWinModernControl\EasyMediaControlWindow.h"

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

HWND g_Win32Textbox = NULL;

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
HWND g_ToggleSwitchPlaceHwnd = NULL;
HWND g_CheckboxPlaceHwnd = NULL;
HWND g_MediaPlayerPlaceHwnd = NULL;
HWND g_NumberBoxPlaceHwnd = NULL;

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
//PEASYMODERNPROGRESSBAR g_ProgressbarInfo = NULL;
//PEASYMODERNPROGRESSBAR g_ProgressbarInfo2 = NULL;
//PEASYMODERNPROGRESSBAR g_ProgressbarInfo3 = NULL;
PEASYMODERNHYPERLINK g_HyperLinkInfo = NULL;
PEASYMODERNSWITCH g_ToggleSwitchInfo = NULL;
PEASYMODERNCHECKBOX g_CheckboxInfo = NULL;
PEASYMODERNMEDIAPLAYER g_PlayerInfo = NULL;

PEASYWINUIPROGRESSRING g_WinUIProgressringInfo = NULL;

PEASYWINUIPROGRESSBAR g_ProgressbarInfo = NULL;
PEASYWINUIPROGRESSBAR g_ProgressbarInfo2 = NULL;
PEASYWINUIPROGRESSBAR g_ProgressbarInfo3 = NULL;

PEASYWINUINUMBERBOX g_NumberBoxInfo = NULL;

BOOL __stdcall _SlidebarChanged(DWORD id, DOUBLE currentValue, PVOID userData) {
	CHAR str[10] = { 0, };

	sprintf_s(str, 10, "%0.lf", currentValue);

	SetWindowTextA(g_SlidebarValueLabel, str);

	return TRUE;
}

BOOL __stdcall _ButtonClicked(DWORD id, PVOID userData) {

	MessageBoxW((HWND)userData, L"Button Clicked", L"", 0);

	SetFocus(g_LabelHwnd);

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

BOOL __stdcall _ToggleSwitchChanged(BOOL status, PVOID userData) {

	if (status) {
		MessageBoxW(0, L"Switch On", L"OnSwitchChanged", 0);
	}
	else {
		MessageBoxW(0, L"Switch Off", L"OnSwitchChanged", 0);
	}

	return TRUE;
}

BOOL __stdcall _CheckboxChanged(DWORD id, BOOL isChecked, BOOL Indeterminate) {

	if (Indeterminate) {
		MessageBoxW(0, L"On Indeterminate", L"Checkbox", 0);
	}
	else {
		if (isChecked) {
			MessageBoxW(0, L"On Checked", L"Checkbox", 0);
		}
		else {
			MessageBoxW(0, L"On Unchecked", L"Checkbox", 0);
		}
	}



	return TRUE;
}

LRESULT __stdcall _MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int main()
{
	if (!EasyWinModernCtrl_IsSystemSupport()) {
		MessageBoxW(0, L"Not Supported OS.", L"Sample", 0);
		return -1;
	}

	BOOL useWinUI = TRUE;
	EasyWinModernCtrl_InitializeApartment(0, useWinUI);

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
		L"EasyWinModernControl With WinUI",
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

		g_Win32Textbox = CreateWindowW(L"Edit", NULL, WS_CHILD | WS_BORDER | ES_MULTILINE, 600, 100, 200, 30, hwnd, NULL, NULL, NULL);
		ShowWindow(g_Win32Textbox,SW_SHOW);

		//create uwp button place
		g_ButtonPlaceHwnd = CreateWindowW(L"static", L"", WS_CHILD, 360, 5, 55, 35, hwnd, NULL, NULL, NULL);
		ShowWindow(g_ButtonPlaceHwnd, SW_SHOW);

		//create uwp button
		g_ButtonInfo = EasyWinModernCtrl_CreateButton(L"btn_yes", 1, L"Yes");
		EasyWinModernCtrl_ButtonSetClickCallback(g_ButtonInfo, &_ButtonClicked, hwnd);
		EasyWinModernCtrl_ButtonSetUseAccentColor(g_ButtonInfo, TRUE);
		EasyWinModernCtrl_ShowControl(g_ButtonInfo, g_ButtonPlaceHwnd);

		//create uwp button place2
		g_ButtonPlaceHwnd2 = CreateWindowW(L"static", L"", WS_CHILD, 450, 5, 100, 35, hwnd, NULL, NULL, NULL);
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
		//g_ProgressringInfo = EasyWinModernCtrl_CreateProgressring(L"loadingRing");
		//EasyWinModernCtrl_ShowControl(g_ProgressringInfo, g_ProgressRingPlaceHwnd);
		g_WinUIProgressringInfo = EasyWinModernCtrl_CreateWinUIProgressring(L"loadingRing");
		EasyWinModernCtrl_ShowControl(g_WinUIProgressringInfo, g_ProgressRingPlaceHwnd);

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
		g_CalendarDatePickerPlaceHwnd = CreateWindow(L"static", L"", WS_CHILD, 600, 350, 200, 60, hwnd, NULL, NULL, NULL);
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
		g_ProgressbarInfo = EasyWinModernCtrl_CreateWinUIProgressbar(L"progress_1", 0, 10);
		EasyWinModernCtrl_ShowControl(g_ProgressbarInfo, g_ProgressbarPlaceHwnd);
		EasyWinModernCtrl_WinUIProgressbarSetValue(g_ProgressbarInfo, FALSE, FALSE , 3);

		//create uwp progress bar place2
		g_ProgressbarPlaceHwnd2 = CreateWindowW(L"static", L"", WS_CHILD, 10, 470, 200, 5, hwnd, NULL, NULL, NULL);
		ShowWindow(g_ProgressbarPlaceHwnd2, SW_SHOW);

		//create uwp progress bar2
		g_ProgressbarInfo2 = EasyWinModernCtrl_CreateWinUIProgressbar(L"progress_2", 0, 10);
		EasyWinModernCtrl_ShowControl(g_ProgressbarInfo2, g_ProgressbarPlaceHwnd2);
		EasyWinModernCtrl_WinUIProgressbarSetValue(g_ProgressbarInfo2, FALSE, TRUE , 3);

		//create uwp progress bar place2
		g_ProgressbarPlaceHwnd3 = CreateWindowW(L"static", L"", WS_CHILD, 10, 490, 200, 5, hwnd, NULL, NULL, NULL);
		ShowWindow(g_ProgressbarPlaceHwnd3, SW_SHOW);

		//create uwp progress bar2
		g_ProgressbarInfo3 = EasyWinModernCtrl_CreateWinUIProgressbar(L"progress_3", 0, 10);
		EasyWinModernCtrl_ShowControl(g_ProgressbarInfo3, g_ProgressbarPlaceHwnd3);
		EasyWinModernCtrl_WinUIProgressbarSetValue(g_ProgressbarInfo3, TRUE, FALSE, 0);

		//create hyperlink place
		g_HyperLinkPlaceHwnd = CreateWindowW(L"static", L"", WS_CHILD, 500, 450, 250, 35, hwnd, NULL, NULL, NULL);
		ShowWindow(g_HyperLinkPlaceHwnd, SW_SHOW);

		g_HyperLinkInfo = EasyWinModernCtrl_CreateHyperlink(L"link1", L"Go to homepage");
		EasyWinModernCtrl_HyperlinkSetNavigateUri(g_HyperLinkInfo, L"https://github.com/bho3538");
		EasyWinModernCtrl_ShowControl(g_HyperLinkInfo, g_HyperLinkPlaceHwnd);

		//create toggle switch place
		g_ToggleSwitchPlaceHwnd = CreateWindowW(L"static", L"", WS_CHILD, 800, 450, 150, 60, hwnd, NULL, NULL, NULL);
		ShowWindow(g_ToggleSwitchPlaceHwnd, SW_SHOW);

		//create uwp toggle switch
		g_ToggleSwitchInfo = EasyWinModernCtrl_CreateToggleSwitch(L"switch1", L"Switch Title", L"On Text", L"Off Text", 1);
		EasyWinModernCtrl_ToggleSwitchSetChangedCallback(g_ToggleSwitchInfo,&_ToggleSwitchChanged,NULL);
		EasyWinModernCtrl_ShowControl(g_ToggleSwitchInfo, g_ToggleSwitchPlaceHwnd);
		//EasyWinModernCtrl_ToggleSwitchSetStatus(g_ToggleSwitchInfo, FALSE);

		//create checkbox place
		g_CheckboxPlaceHwnd = CreateWindowW(L"static", L"", WS_CHILD, 800, 550, 150, 50, hwnd, NULL, NULL, NULL);
		ShowWindow(g_CheckboxPlaceHwnd, SW_SHOW);

		g_CheckboxInfo = EasyWinModernCtrl_CreateCheckbox(L"chk1", 1, L"checkbox", 1);
		EasyWinModernCtrl_CheckboxSetStatus(g_CheckboxInfo, 1, 1);
		
		EasyWinModernCtrl_CheckboxSetChangedCallback(g_CheckboxInfo, &_CheckboxChanged,NULL);

		EasyWinModernCtrl_ShowControl(g_CheckboxInfo, g_CheckboxPlaceHwnd);

		g_NumberBoxPlaceHwnd = CreateWindowW(L"static", L"", WS_CHILD, 1000, 450, 150, 60, hwnd, NULL, NULL, NULL);
		ShowWindow(g_NumberBoxPlaceHwnd, SW_SHOW);

		g_NumberBoxInfo = EasyWinModernCtrl_CreateWinUINumberBox(L"num1", L"NumberBox", L"Enter Number");
		EasyWinModernCtrl_WinUINumberBoxSetButtonType(g_NumberBoxInfo,1);
		EasyWinModernCtrl_ShowControl(g_NumberBoxInfo, g_NumberBoxPlaceHwnd);


		//create mediaplayer place
		//g_CheckboxPlaceHwnd = CreateWindowW(L"static", L"", WS_CHILD, 1000, 500, 500, 300, hwnd, NULL, NULL, NULL);
		//ShowWindow(g_CheckboxPlaceHwnd, SW_SHOW);

		//g_PlayerInfo = EasyWinModernCtrl_CreateMediaPlayer(L"player1");
		//EasyWinModernCtrl_MediaPlayerSetUriSource(g_PlayerInfo, L"");

	}; break;
	//case WM_COMMAND: {
	//	_ShowMediaWindow(g_PlayerInfo);
	//}; break; 
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
		EasyWinModernCtrl_AdjustLayout(g_ToggleSwitchInfo);
		EasyWinModernCtrl_AdjustLayout(g_CheckboxInfo);
		EasyWinModernCtrl_AdjustLayout(g_PlayerInfo);
		EasyWinModernCtrl_AdjustLayout(g_WinUIProgressringInfo);
		EasyWinModernCtrl_AdjustLayout(g_NumberBoxInfo);
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
		
		EasyWinModernCtrl_CloseControl(g_ToggleSwitchInfo);
		EasyWinModernCtrl_CleanupControl(g_ToggleSwitchInfo);

		EasyWinModernCtrl_CloseControl(g_CheckboxInfo);
		EasyWinModernCtrl_CleanupControl(g_CheckboxInfo);

		EasyWinModernCtrl_CloseControl(g_PlayerInfo);
		EasyWinModernCtrl_CleanupControl(g_PlayerInfo);

		EasyWinModernCtrl_CloseControl(g_WinUIProgressringInfo);
		EasyWinModernCtrl_CleanupControl(g_WinUIProgressringInfo);

		EasyWinModernCtrl_CloseControl(g_NumberBoxInfo);
		EasyWinModernCtrl_CleanupControl(g_NumberBoxInfo);

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
		
		CloseWindow(g_MediaPlayerPlaceHwnd);
		DestroyWindow(g_MediaPlayerPlaceHwnd);

		CloseWindow(g_NumberBoxPlaceHwnd);
		DestroyWindow(g_NumberBoxPlaceHwnd);

		DestroyWindow(hwnd);
	}; break;
	case WM_DESTROY: {
		PostQuitMessage(0);
		return 0;
	}; break;
	}

	return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}
