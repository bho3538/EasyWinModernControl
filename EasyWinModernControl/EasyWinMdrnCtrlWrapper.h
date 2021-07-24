#pragma once

#if __cplusplus
extern "C" {
#endif
	typedef BOOL(__stdcall* TEasyWinModernCtrl_BtnCallback)(DWORD id, PVOID userData);
	typedef BOOL(__stdcall* TEasyWinModernCtrl_SlidebarCallback)(DWORD id, DOUBLE currentValue, PVOID userData);
	typedef BOOL(__stdcall* TEasyWinModernCtrl_TimePickerCallback)(INT64 seconds, PVOID userData);
	typedef BOOL(__stdcall* TEasyWinModernCtrl_RadioBtnCallback)(LPCWSTR groupName, DWORD selectedIdx, PVOID userData);


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

	__declspec(dllexport) void __cdecl EasyWinModernCtrl_InitializeApartment(BOOL useMTA);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_UnInitialize();
	__declspec(dllexport) BOOL __cdecl EasyWinModernCtrl_IsSystemSupport();

	//Textbox
	__declspec(dllexport) PEASYMODERNTEXTBOX __cdecl EasyWinModernCtrl_CreateTextbox(LPCWSTR controlName, LPCWSTR headerTitle, LPCWSTR textPlaceholder, BOOL enableMultiLine, BOOL enableUserChangeLine, DWORD maxTextLength);
	__declspec(dllexport) LPCWSTR __cdecl EasyWinModernCtrl_TextboxGetText(PEASYMODERNTEXTBOX pTextboxInfo);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_TextboxSetText(PEASYMODERNTEXTBOX pTextboxInfo,LPCWSTR text);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_TextboxSetReadonlyMode(PEASYMODERNTEXTBOX pTextboxInfo, BOOL enable);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_TextboxSetEnableControl(PEASYMODERNTEXTBOX pTextboxInfo, BOOL enable);

	
	//Passwordbox
	__declspec(dllexport) PEASYMODERNPWDBOX __cdecl EasyWinModernCtrl_CreatePasswordBox(LPCWSTR controlName, LPCWSTR headerTitle, LPCWSTR textPlaceholder, DWORD maxLength);
	__declspec(dllexport) LPCWSTR __cdecl EasyWinModernCtrl_PasswordboxGetPassword(PEASYMODERNPWDBOX pPwdboxInfo);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_PasswordboxSetEnableControl(PEASYMODERNPWDBOX pPwdboxInfo, BOOL enable);

	//Button
	__declspec(dllexport) PEASYMODERNBTN __cdecl EasyWinModernCtrl_CreateButton(LPCWSTR controlName,DWORD id, LPCWSTR buttonLabel);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_ButtonSetClickCallback(PEASYMODERNBTN pBtnInfo, TEasyWinModernCtrl_BtnCallback cb, PVOID userData);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_ButtonSetUseAccentColor(PEASYMODERNBTN pBtnInfo, BOOL enable);

	//Slidebar
	__declspec(dllexport) PEASYMODERNSLIDEBAR __cdecl EasyWinModernCtrl_CreateSlidebar(LPCWSTR controlName, DWORD id, DOUBLE minVal, DOUBLE maxVal, DOUBLE step, DOUBLE defaultValue);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_SlidebarSetValueChangedCallback(PEASYMODERNSLIDEBAR pSlidebarInfo, TEasyWinModernCtrl_SlidebarCallback cb, PVOID userData);
	__declspec(dllexport) DOUBLE __cdecl EasyWinModernCtrl_SlidebarGetValue(PEASYMODERNSLIDEBAR pSlidebarInfo);

	//Progressring
	__declspec(dllexport) PEASYMODERNPROGRESSRING __cdecl EasyWinModernCtrl_CreateProgressring(LPCWSTR controlName);

	//TimePicker
	__declspec(dllexport) PEASYMODERNTIMEPICKER __cdecl EasyWinModernCtrl_CreateTimePicker(LPCWSTR controlName,LPCWSTR headerText,BOOL use24hours);
	__declspec(dllexport) INT64 __cdecl EasyWinModernCtrl_TimePickerGetSelectedTimeAsSeconds(PEASYMODERNTIMEPICKER pTimePickerInfo);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_TimePickerSetTimeUsingSeconds(PEASYMODERNTIMEPICKER pTimePickerInfo, INT64 seconds);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_TimePickerSetValueChangedCallback(PEASYMODERNTIMEPICKER pTimePickerInfo, TEasyWinModernCtrl_TimePickerCallback cb, PVOID userData);

	//RadioButton
	__declspec(dllexport) PEASYMODERNRADIOBTN __cdecl EasyWinModernCtrl_CreateRadioButton(LPCWSTR groupName, LPCWSTR headerText, BOOL useVerticalMode);
	__declspec(dllexport) void  EasyWinModernCtrl_RadioBtnInsertItem(PEASYMODERNRADIOBTN pRadioBtn,DWORD idx, LPCWSTR text, BOOL defaultChecked, BOOL enabled);
	__declspec(dllexport) DWORD  EasyWinModernCtrl_RadioBtnGetCheckedItem(PEASYMODERNRADIOBTN pRadioBtn);
	__declspec(dllexport) void  EasyWinModernCtrl_RadioBtnSetCheckedItem(PEASYMODERNRADIOBTN pRadioBtn, DWORD idx);
	__declspec(dllexport) void  EasyWinModernCtrl_RadioBtnSetValueChangedCallback(PEASYMODERNRADIOBTN pRadioBtn, TEasyWinModernCtrl_RadioBtnCallback cb,PVOID userData);

	//CalendarDatePicker
	__declspec(dllexport) PEASYMODERNCALENDARDATEPICKER __cdecl EasyWinModernCtrl_CreateCalendarDatePicker(LPCWSTR controlName,LPCWSTR headerText);
	__declspec(dllexport) BOOL __cdecl EasyWinModernCtrl_CalendarDatePickerGetSelectedDate(PEASYMODERNCALENDARDATEPICKER pCalendarDatePicker,PFILETIME pSelectedTime);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_CalendarDatePickerSetDate(PEASYMODERNCALENDARDATEPICKER pCalendarDatePicker, FILETIME date);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_CalendarDatePickerSetMinDate(PEASYMODERNCALENDARDATEPICKER pCalendarDatePicker, FILETIME date);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_CalendarDatePickerSetMaxDate(PEASYMODERNCALENDARDATEPICKER pCalendarDatePicker, FILETIME date);


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
