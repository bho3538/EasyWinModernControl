#pragma once

#if __cplusplus
extern "C" {
#endif
	typedef BOOL(__stdcall* TEasyWinModernCtrl_BtnCallback)(DWORD id, PVOID userData);
	typedef BOOL(__stdcall* TEasyWinModernCtrl_SlidebarCallback)(DWORD id, DOUBLE currentValue, PVOID userData);


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

	__declspec(dllexport) BOOL __cdecl EasyWinModernCtrl_IsSystemSupport();

	//Textbox
	__declspec(dllexport) PEASYMODERNTEXTBOX __cdecl EasyWinModernCtrl_CreateTextbox(LPCWSTR controlName, LPCWSTR headerTitle, LPCWSTR textPlaceholder, BOOL enableMultiLine, BOOL enableUserChangeLine, DWORD maxTextLength);
	__declspec(dllexport) LPCWSTR __cdecl EasyWinModernCtrl_TextboxGetText(PEASYMODERNTEXTBOX pTextboxInfo);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_TextboxSetText(PEASYMODERNTEXTBOX pTextboxInfo,LPCWSTR text);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_TextboxSetReadonlyMode(PEASYMODERNTEXTBOX pTextboxInfo, BOOL enable);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_TextboxSetEnableControl(PEASYMODERNTEXTBOX pTextboxInfo, BOOL enable);

	
	//Passwordbox
	__declspec(dllexport) PEASYMODERNTEXTBOX __cdecl EasyWinModernCtrl_CreatePasswordBox(LPCWSTR controlName, LPCWSTR headerTitle, LPCWSTR textPlaceholder, DWORD maxLength);
	__declspec(dllexport) LPCWSTR __cdecl EasyWinModernCtrl_PasswordboxGetPassword(PEASYMODERNPWDBOX pPwdboxInfo);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_PasswordboxSetEnableControl(PEASYMODERNPWDBOX pPwdboxInfo, BOOL enable);

	//Button
	__declspec(dllexport) PEASYMODERNBTN __cdecl EasyWinModernCtrl_CreateButton(LPCWSTR controlName,DWORD id, LPCWSTR buttonLabel);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_ButtonSetClickCallback(PEASYMODERNBTN pBtnInfo, TEasyWinModernCtrl_BtnCallback cb, PVOID userData);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_ButtonSetUseAccentColor(PEASYMODERNBTN pBtnInfo, BOOL enable);

	//Slidebar
	__declspec(dllexport) PEASYMODERNSLIDEBAR __cdecl EasyWinModernCtrl_CreateSlidebar(LPCWSTR controlName, DWORD id, DOUBLE minVal, DOUBLE maxVal, DOUBLE step, DOUBLE defaultValue);


	//Common
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_ShowControl(PVOID pControl, HWND parentHwnd);
	__declspec(dllexport) void __cdecl EasyWinModernCtrl_AdjustLayout(PVOID pControl);
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