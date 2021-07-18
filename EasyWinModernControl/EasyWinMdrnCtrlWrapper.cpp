#include "stdafx.h"
#include "EasyWinMdrnCtrlWrapper.h"

#include "CModernControl.h"
#include "CModernTextbox.h"
#include "CModernButton.h"
#include "CModernPasswordbox.h"
#include "CModernSlidebar.h"

using namespace EasyWinModernControl;

#define _EASYWINNOTY_TEXTBOX 1
#define _EASYWINNOTY_PWDBOX 2
#define _EASYWINNOTY_BUTTON 3
#define _EASYWINNOTY_SLIDEBAR 4

typedef struct _EasyModernBtnInt {
	int unused;
	CModernButton* pBtn;
} EASYMODERNBTNINT, * PEASYMODERNBTNINT;

typedef struct _EasyModernTextboxInt {
	int unused;
	CModernTextbox* pTextbox;
} EASYMODERNTEXTBOXINT, * PEASYMODERNTEXTBOXINT;

typedef struct _EasyModernPwdboxInt {
	int unused;
	CModernPasswordbox* pPwdbox;
} EASYMODERNPWDBOXINT, * PEASYMODERNPWDBOXINT;

typedef struct _EasyModernSlidebarInt {
	int unused;
	CModernSlidebar* pSlidebar;
} EASYMODERNSLIDEBARINT, *PEASYMODERNSLIDEBARINT;


__declspec(dllexport) BOOL __cdecl EasyWinModernCtrl_IsSystemSupport() {
	return CModernControl::IsSupportSystem();
}

__declspec(dllexport)  PEASYMODERNTEXTBOX __cdecl EasyWinModernCtrl_CreatePasswordBox(LPCWSTR controlName, LPCWSTR headerTitle, LPCWSTR textPlaceholder, DWORD maxLength) {
	PEASYMODERNPWDBOXINT pwdbox = (PEASYMODERNPWDBOXINT)malloc(sizeof(EASYMODERNPWDBOXINT));
	if (pwdbox) {
		pwdbox->unused = _EASYWINNOTY_PWDBOX;
		pwdbox->pPwdbox = new CModernPasswordbox(controlName, headerTitle, textPlaceholder,maxLength);
	}

	return (PEASYMODERNTEXTBOX)pwdbox;
}

__declspec(dllexport) LPCWSTR __cdecl EasyWinModernCtrl_PasswordboxGetPassword(PEASYMODERNPWDBOX pPwdboxInfo) {
	PEASYMODERNPWDBOXINT pInfo = (PEASYMODERNPWDBOXINT)pPwdboxInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_PWDBOX) {
		return pInfo->pPwdbox->GetPassword();
	}
	return NULL;
}
__declspec(dllexport) void __cdecl EasyWinModernCtrl_PasswordboxSetEnableControl(PEASYMODERNPWDBOX pPwdboxInfo, BOOL enable) {
	PEASYMODERNPWDBOXINT pInfo = (PEASYMODERNPWDBOXINT)pPwdboxInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_PWDBOX) {
		pInfo->pPwdbox->SetEnableControl(enable);
	}
}

__declspec(dllexport) PEASYMODERNTEXTBOX __cdecl EasyWinModernCtrl_CreateTextbox(LPCWSTR controlName, LPCWSTR headerTitle, LPCWSTR textPlaceholder, BOOL enableMultiLine, BOOL enableUserChangeLine, DWORD maxTextLength) {
	PEASYMODERNTEXTBOXINT txtbox = (PEASYMODERNTEXTBOXINT)malloc(sizeof(EASYMODERNTEXTBOXINT));
	if (txtbox) {
		txtbox->unused = _EASYWINNOTY_TEXTBOX;
		txtbox->pTextbox = new CModernTextbox(controlName, headerTitle, textPlaceholder, enableMultiLine, enableUserChangeLine, maxTextLength);
	}

	return (PEASYMODERNTEXTBOX)txtbox;
}

__declspec(dllexport) LPCWSTR __cdecl EasyWinModernCtrl_TextboxGetText(PEASYMODERNTEXTBOX pTextboxInfo) {
	PEASYMODERNTEXTBOXINT pInfo = (PEASYMODERNTEXTBOXINT)pTextboxInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_TEXTBOX) {
		return pInfo->pTextbox->GetText();
	}
	return NULL;
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_TextboxSetText(PEASYMODERNTEXTBOX pTextboxInfo, LPCWSTR text) {
	PEASYMODERNTEXTBOXINT pInfo = (PEASYMODERNTEXTBOXINT)pTextboxInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_TEXTBOX) {
		pInfo->pTextbox->SetText(text);
	}
}
__declspec(dllexport) void __cdecl EasyWinModernCtrl_TextboxSetReadonlyMode(PEASYMODERNTEXTBOX pTextboxInfo, BOOL enable) {
	PEASYMODERNTEXTBOXINT pInfo = (PEASYMODERNTEXTBOXINT)pTextboxInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_TEXTBOX) {
		pInfo->pTextbox->SetReadonlyMode(enable);
	}
}
__declspec(dllexport) void __cdecl EasyWinModernCtrl_TextboxSetEnableControl(PEASYMODERNTEXTBOX pTextboxInfo, BOOL enable) {
	PEASYMODERNTEXTBOXINT pInfo = (PEASYMODERNTEXTBOXINT)pTextboxInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_TEXTBOX) {
		pInfo->pTextbox->SetEnableControl(enable);
	}
}


__declspec(dllexport) PEASYMODERNBTN __cdecl EasyWinModernCtrl_CreateButton(LPCWSTR controlName, DWORD id, LPCWSTR buttonLabel) {
	PEASYMODERNBTNINT button = (PEASYMODERNBTNINT)malloc(sizeof(EASYMODERNBTNINT));
	if (button) {
		button->unused = _EASYWINNOTY_BUTTON;
		button->pBtn = new CModernButton(controlName, id, buttonLabel);
	}
	
	return (PEASYMODERNBTN)button;
}
__declspec(dllexport) void __cdecl EasyWinModernCtrl_ButtonSetClickCallback(PEASYMODERNBTN pBtnInfo, TEasyWinModernCtrl_BtnCallback cb, PVOID userData) {
	PEASYMODERNBTNINT pInfo = (PEASYMODERNBTNINT)pBtnInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_BUTTON) {
		pInfo->pBtn->SetClickCallback(cb, userData);
	}
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_ButtonSetUseAccentColor(PEASYMODERNBTN pBtnInfo, BOOL enable) {
	PEASYMODERNBTNINT pInfo = (PEASYMODERNBTNINT)pBtnInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_BUTTON) {
		pInfo->pBtn->SetUseAccentColor(enable);
	}
}


__declspec(dllexport) PEASYMODERNSLIDEBAR __cdecl EasyWinModernCtrl_CreateSlidebar(LPCWSTR controlName, DWORD id, DOUBLE minVal, DOUBLE maxVal, DOUBLE step, DOUBLE defaultValue) {
	PEASYMODERNSLIDEBARINT slidebar = (PEASYMODERNSLIDEBARINT)malloc(sizeof(EASYMODERNBTNINT));
	if (slidebar) {
		slidebar->unused = _EASYWINNOTY_SLIDEBAR;
		slidebar->pSlidebar = new CModernSlidebar(controlName, id, minVal, maxVal, step, defaultValue);
	}

	return (PEASYMODERNSLIDEBAR)slidebar;
}


__declspec(dllexport) void __cdecl EasyWinModernCtrl_ShowControl(PVOID pControl,HWND parentHwnd) {
	PEASYMODERNBTNINT pControlInfo = (PEASYMODERNBTNINT)pControl;
	if (pControlInfo) {
		((CModernControl*)(pControlInfo->pBtn))->Show(parentHwnd);
	}
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_AdjustLayout(PVOID pControl) {
	PEASYMODERNBTNINT pControlInfo = (PEASYMODERNBTNINT)pControl;
	if (pControlInfo) {
		((CModernControl*)(pControlInfo->pBtn))->AdjustLayout();
	}
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_SetTheme(PVOID pControl, DWORD dwFlags) {
	PEASYMODERNBTNINT pControlInfo = (PEASYMODERNBTNINT)pControl;
	if (pControlInfo) {
		((CModernControl*)(pControlInfo->pBtn))->SetTheme(dwFlags);
	}
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_HideControl(PVOID pControl, BOOL reShow) {
	PEASYMODERNBTNINT pControlInfo = (PEASYMODERNBTNINT)pControl;
	if (pControlInfo) {
		((CModernControl*)(pControlInfo->pBtn))->Hide(reShow);
	}
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_CloseControl(PVOID pControl) {
	PEASYMODERNBTNINT pControlInfo = (PEASYMODERNBTNINT)pControl;
	if (pControlInfo) {
		((CModernControl*)(pControlInfo->pBtn))->Close();
	}
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_CleanupControl(PVOID pControl) {
	PEASYMODERNBTNINT pControlInfo = (PEASYMODERNBTNINT)pControl;
	if (!pControlInfo) {
		return;
	}

	switch (pControlInfo->unused) {
		case _EASYWINNOTY_TEXTBOX: {
			delete (CModernTextbox*)(pControlInfo->pBtn);
		}; break;
		case _EASYWINNOTY_PWDBOX: {
			delete (CModernPasswordbox*)(pControlInfo->pBtn);
		}; break;
		case _EASYWINNOTY_BUTTON: {
			delete (CModernButton*)(pControlInfo->pBtn);
		}; break;
		case _EASYWINNOTY_SLIDEBAR: {
			delete (CModernSlidebar*)(pControlInfo->pBtn);
		}; break;
	}

	free(pControlInfo);
}