#pragma once

#if __cplusplus
extern "C" {
#endif
	typedef BOOL(__stdcall* TEasyWinModernCtrl_BtnCallback)(DWORD id, PVOID userData);
	typedef BOOL(__stdcall* TEasyWinModernCtrl_SlidebarCallback)(DWORD id, DOUBLE currentValue, PVOID userData);
	typedef BOOL(__stdcall* TEasyWinModernCtrl_TimePickerCallback)(INT64 seconds, PVOID userData);
	typedef BOOL(__stdcall* TEasyWinModernCtrl_RadioBtnCallback)(LPCWSTR groupName, DWORD selectedIdx, PVOID userData);
	typedef BOOL(__stdcall* TEasyWinModernCtrl_CalendarDatePickerCallback)(FILETIME selectedDate, PVOID userData);
	typedef BOOL(__stdcall* TEasyWinModernCtrl_HyperLinkCallback)(PVOID userData);
	typedef BOOL(__stdcall* TEasyWinModernCtrl_SwitchCallback)(BOOL status, PVOID userData);
	typedef BOOL(__stdcall* TEasyWinModernCtrl_CheckboxCallback)(DWORD id, BOOL isChecked, BOOL Indeterminate);


	typedef struct _EasyModernBtn {
		int unused;
	} EASYMODERNBTN, *PEASYMODERNBTN;

	typedef struct _EasyModernTextbox {
		int unused;
	} EASYMODERNTEXTBOX, * PEASYMODERNTEXTBOX;

	typedef struct _EasyModernPwdbox {
		int unused;
	} EASYMODERNPWDBOX, * PEASYMODERNPWDBOX;

	typedef struct _EasyModernSlidebar {
		int unused;
	} EASYMODERNSLIDEBAR, * PEASYMODERNSLIDEBAR;

	typedef struct _EasyModernProgressring {
		int unused;
	} EASYMODERNPROGRESSRING, * PEASYMODERNPROGRESSRING;

	typedef struct _EasyModernTimePicker {
		int unused;
	} EASYMODERNTIMEPICKER,*PEASYMODERNTIMEPICKER;

	typedef struct _EasyModernRadioBtn {
		int unused;
	} EASYMODERNRADIOBTN, *PEASYMODERNRADIOBTN;

	typedef struct _EasyModernCalendarDatePicker {
		int unused;
	} EASYMODERNCALENDARDATEPICKER, * PEASYMODERNCALENDARDATEPICKER;

	typedef struct _EasyModernProgressbar {
		int unused;
	} EASYMODERNPROGRESSBAR, * PEASYMODERNPROGRESSBAR;

	typedef struct _EasyModernHyperLink {
		int unused;
	} EASYMODERNHYPERLINK, * PEASYMODERNHYPERLINK;

	typedef struct _EasyModernSwitch {
		int unused;
	} EASYMODERNSWITCH, *PEASYMODERNSWITCH;

	typedef struct _EasyModernCheckbox {
		int unused;
	} EASYMODERNCHECKBOX, * PEASYMODERNCHECKBOX;

	typedef struct _EasyModernMediaPlayer {
		int unused;
	} EASYMODERNMEDIAPLAYER, * PEASYMODERNMEDIAPLAYER;

	__declspec(dllexport) void __cdecl EasyWinModernCtrl_InitializeApartment(BOOL useMTA);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_UnInitialize();
	__declspec(dllexport) BOOL __cdecl EasyWinModernCtrl_IsSystemSupport();

	//Textbox
	__declspec(dllexport) PEASYMODERNTEXTBOX __cdecl EasyWinModernCtrl_CreateTextbox(LPCWSTR controlName, LPCWSTR headerTitle, LPCWSTR textPlaceholder, BOOL enableMultiLine, BOOL enableUserChangeLine, DWORD maxTextLength);
	__declspec(dllexport) LPCWSTR __cdecl EasyWinModernCtrl_TextboxGetText(PEASYMODERNTEXTBOX pTextboxInfo);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_TextboxSetText(PEASYMODERNTEXTBOX pTextboxInfo,LPCWSTR text);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_TextboxSetTextWithSize(PEASYMODERNTEXTBOX pTextboxInfo, LPCWSTR text,DWORD size);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_TextboxSetReadonlyMode(PEASYMODERNTEXTBOX pTextboxInfo, BOOL enable);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_TextboxSetEnableControl(PEASYMODERNTEXTBOX pTextboxInfo, BOOL enable);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_TextboxSetSpellCheck(PEASYMODERNTEXTBOX pTextboxInfo, BOOL enable);

	
	//Passwordbox
	__declspec(dllexport) PEASYMODERNPWDBOX __cdecl EasyWinModernCtrl_CreatePasswordBox(LPCWSTR controlName, LPCWSTR headerTitle, LPCWSTR textPlaceholder, DWORD maxLength);
	__declspec(dllexport) LPCWSTR __cdecl EasyWinModernCtrl_PasswordboxGetPassword(PEASYMODERNPWDBOX pPwdboxInfo);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_PasswordboxSetEnableControl(PEASYMODERNPWDBOX pPwdboxInfo, BOOL enable);

	//Button
	__declspec(dllexport) PEASYMODERNBTN __cdecl EasyWinModernCtrl_CreateButton(LPCWSTR controlName,DWORD id, LPCWSTR buttonLabel);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_ButtonSetClickCallback(PEASYMODERNBTN pBtnInfo, TEasyWinModernCtrl_BtnCallback cb, PVOID userData);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_ButtonSetUseAccentColor(PEASYMODERNBTN pBtnInfo, BOOL enable);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_ButtonSetEnableControl(PEASYMODERNBTN pBtnInfo, BOOL enable);

	//Slidebar
	__declspec(dllexport) PEASYMODERNSLIDEBAR __cdecl EasyWinModernCtrl_CreateSlidebar(LPCWSTR controlName, DWORD id, DOUBLE minVal, DOUBLE maxVal, DOUBLE step, DOUBLE defaultValue);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_SlidebarSetValueChangedCallback(PEASYMODERNSLIDEBAR pSlidebarInfo, TEasyWinModernCtrl_SlidebarCallback cb, PVOID userData);
	__declspec(dllexport) DOUBLE __cdecl EasyWinModernCtrl_SlidebarGetValue(PEASYMODERNSLIDEBAR pSlidebarInfo);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_SlidebarSetEnableControl(PEASYMODERNSLIDEBAR pSlidebarInfo, BOOL enable);


	//Progressring
	__declspec(dllexport) PEASYMODERNPROGRESSRING __cdecl EasyWinModernCtrl_CreateProgressring(LPCWSTR controlName);

	//TimePicker
	__declspec(dllexport) PEASYMODERNTIMEPICKER __cdecl EasyWinModernCtrl_CreateTimePicker(LPCWSTR controlName,LPCWSTR headerText,BOOL use24hours);
	__declspec(dllexport) INT64 __cdecl EasyWinModernCtrl_TimePickerGetSelectedTimeAsSeconds(PEASYMODERNTIMEPICKER pTimePickerInfo);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_TimePickerSetTimeUsingSeconds(PEASYMODERNTIMEPICKER pTimePickerInfo, INT64 seconds);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_TimePickerSetValueChangedCallback(PEASYMODERNTIMEPICKER pTimePickerInfo, TEasyWinModernCtrl_TimePickerCallback cb, PVOID userData);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_TimePickerEnableControl(PEASYMODERNTIMEPICKER pTimePickerInfo, BOOL enable);


	//RadioButton
	__declspec(dllexport) PEASYMODERNRADIOBTN __cdecl EasyWinModernCtrl_CreateRadioButton(LPCWSTR groupName, LPCWSTR headerText, BOOL useVerticalMode);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_RadioBtnInsertItem(PEASYMODERNRADIOBTN pRadioBtn,DWORD idx, LPCWSTR text, BOOL defaultChecked, BOOL enabled);
	__declspec(dllexport) DWORD __cdecl EasyWinModernCtrl_RadioBtnGetCheckedItem(PEASYMODERNRADIOBTN pRadioBtn);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_RadioBtnSetCheckedItem(PEASYMODERNRADIOBTN pRadioBtn, DWORD idx);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_RadioBtnSetValueChangedCallback(PEASYMODERNRADIOBTN pRadioBtn, TEasyWinModernCtrl_RadioBtnCallback cb,PVOID userData);

	//CalendarDatePicker
	__declspec(dllexport) PEASYMODERNCALENDARDATEPICKER __cdecl EasyWinModernCtrl_CreateCalendarDatePicker(LPCWSTR controlName,LPCWSTR headerText);
	__declspec(dllexport) BOOL __cdecl EasyWinModernCtrl_CalendarDatePickerGetSelectedDate(PEASYMODERNCALENDARDATEPICKER pCalendarDatePicker,PFILETIME pSelectedTime);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_CalendarDatePickerSetDate(PEASYMODERNCALENDARDATEPICKER pCalendarDatePicker, FILETIME date);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_CalendarDatePickerSetMinDate(PEASYMODERNCALENDARDATEPICKER pCalendarDatePicker, FILETIME date);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_CalendarDatePickerSetMaxDate(PEASYMODERNCALENDARDATEPICKER pCalendarDatePicker, FILETIME date);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_CalendarDatePickerSetSelectedDateCallback(PEASYMODERNCALENDARDATEPICKER pCalendarDatePicker, TEasyWinModernCtrl_CalendarDatePickerCallback cb, PVOID userData);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_CalendarDatePickerEnableControl(PEASYMODERNCALENDARDATEPICKER pCalendarDatePicker, BOOL enable);

	//Progressbar
	__declspec(dllexport) PEASYMODERNPROGRESSBAR __cdecl EasyWinModernCtrl_CreateProgressbar(LPCWSTR controlName, DOUBLE minVal, DOUBLE maxVal);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_ProgressbarSetValue(PEASYMODERNPROGRESSBAR pProgressInfo, BOOL isIndeterminate, BOOL isPause, DOUBLE value);

	//Hyperlink
	__declspec(dllexport) PEASYMODERNHYPERLINK __cdecl EasyWinModernCtrl_CreateHyperlink(LPCWSTR controlName, LPCWSTR textLabel);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_HyperlinkSetNavigateUri(PEASYMODERNHYPERLINK pHyperlinkInfo,LPCWSTR uri);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_HyperlinkSetCustomClickCallback(PEASYMODERNHYPERLINK pHyperlinkInfo, TEasyWinModernCtrl_HyperLinkCallback cb, PVOID userData);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_HyperlinkEnableControl(PEASYMODERNHYPERLINK pHyperlinkInfo, BOOL enable);

	//ToggleSwitch
	__declspec(dllexport) PEASYMODERNSWITCH __cdecl EasyWinModernCtrl_CreateToggleSwitch(LPCWSTR controlName, LPCWSTR headerTitle, LPCWSTR onContent, LPCWSTR offContent, BOOL defaultValue);
	__declspec(dllexport) BOOL __cdecl EasyWinModernCtrl_ToggleSwitchGetStatus(PEASYMODERNSWITCH pSwitch);
	__declspec(dllexport) void EasyWinModernCtrl_ToggleSwitchSetChangedCallback(PEASYMODERNSWITCH pSwitch,TEasyWinModernCtrl_SwitchCallback callbackFunc, PVOID userData);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_ToggleSwitchEnableControl(PEASYMODERNSWITCH pSwitch, BOOL enable);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_ToggleSwitchSetStatus(PEASYMODERNSWITCH pSwitch, BOOL status);

	//Checkbox
	__declspec(dllexport) PEASYMODERNCHECKBOX __cdecl EasyWinModernCtrl_CreateCheckbox(LPCWSTR controlName,DWORD id, LPCWSTR label, BOOL allowIndeterminate);
	__declspec(dllexport) BOOL __cdecl EasyWinModernCtrl_CheckboxGetStatus(PEASYMODERNCHECKBOX pCheckbox, PBOOL pIsIndeterminate);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_CheckboxSetStatus(PEASYMODERNCHECKBOX pCheckbox, BOOL isChecked, BOOL isIndeterminate);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_CheckboxSetEnableControl(PEASYMODERNCHECKBOX pCheckbox, BOOL enable);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_CheckboxSetChangedCallback(PEASYMODERNCHECKBOX pCheckbox, TEasyWinModernCtrl_CheckboxCallback callbackFunc, PVOID userData);

	//MediaPlayer
	__declspec(dllexport) PEASYMODERNMEDIAPLAYER __cdecl EasyWinModernCtrl_CreateMediaPlayer(LPCWSTR controlName);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_MediaPlayerSetUriSource(PEASYMODERNMEDIAPLAYER pMediaPlayer, LPCWSTR uri);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_MediaPlayerSetStreamSource(PEASYMODERNMEDIAPLAYER pMediaPlayer, PVOID randomStream);

	//Common
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_ShowControl(PVOID pControl, HWND parentHwnd);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_AdjustLayout(PVOID pControl);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_AdjustLayout(PVOID pControl);
	__declspec(dllexport) HWND __cdecl EasyWinModernCtrl_GetRawControlHwnd(PVOID pControl);

	// 0 : system default
	// 1 : Light
	// 2 : Dark
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_SetTheme(PVOID pControl,DWORD dwFlags);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_HideControl(PVOID pControl,BOOL reShow);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_CloseControl(PVOID pControl);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_CleanupControl(PVOID pControl);

#if __cplusplus
}
#endif
