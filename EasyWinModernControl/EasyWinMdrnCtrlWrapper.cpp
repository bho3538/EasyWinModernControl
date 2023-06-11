#include "stdafx.h"
#include "EasyWinMdrnCtrlWrapper.h"

#include "CModernControl.h"
#include "CModernTextbox.h"
#include "CModernButton.h"
#include "CModernPasswordbox.h"
#include "CModernSlidebar.h"
#include "CModernProgressring.h"
#include "CModernTimePicker.h"
#include "CModernRadioBtn.h"
#include "CModernCalendarDatePicker.h"
#include "CModernProgressbar.h"
#include "CModernHyperlink.h"
#include "CModernSwitch.h"
#include "CModernCheckbox.h"
#include "CModernMediaPlayer.h"
#include "CWinUIProgressRing.h"
#include "CWinUIProgressbar.h"
#include "CWinUINumberBox.h"

using namespace EasyWinModernControl;

#define _EASYWINNOTY_TEXTBOX 1
#define _EASYWINNOTY_PWDBOX 2
#define _EASYWINNOTY_BUTTON 3
#define _EASYWINNOTY_SLIDEBAR 4
#define _EASYWINNOTY_PROGRESSRING 5
#define _EASYWINNOTY_TIMEPICKER 6
#define _EASYWINNOTY_RADIOBTN 7
#define _EASYWINNOTY_CALENDARPICKER 8
#define _EASYWINNOTY_PROGRESSBAR 9
#define _EASYWINNOTY_HYPERLINK 10
#define _EASYWINNOTY_SWITCH 11
#define _EASYWINNOTY_CHECKBOX 12
#define _EASYWINNOTY_MEDIAPLAYER 13
#define _EASYWINNOTY_WINUIPROGRESSRING 14
#define _EASYWINNOTY_WINUIPROGRESSBAR 15
#define _EASYWINNOTY_WINUINUMBERBOX 16

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

typedef struct _EasyModernProgressringInt {
	int unused;
	CModernProgressring* pRing;
} EASYMODERNPROGRESSRINGINT, * PEASYMODERNPROGRESSRINGINT;

typedef struct _EasyModernTimePickerInt {
	int unused;
	CModernTimePicker* pTimePicker;
} EASYMODERNTIMEPICKERINT, * PEASYMODERNTIMEPICKERINT;

typedef struct _EasyModernRadioBtnInt {
	int unused;
	CModernRadioBtn* pRadioBtn;
} EASYMODERNRADIOBTNINT, * PEASYMODERNRADIOBTNINT;

typedef struct _EasyModernCalendarDatePickerInt {
	int unused;
	CModernCalendarDatePicker* pDatePicker;
} EASYMODERNCALENDARDATEPICKERINT, * PEASYMODERNCALENDARDATEPICKERINT;

typedef struct _EasyModernProgressbarInt {
	int unused;
	CModernProgressbar* pProgressbar;
} EASYMODERNPROGRESSBARINT, * PEASYMODERNPROGRESSBARINT;

typedef struct _EasyModernHyperLinkInt {
	int unused;
	CModernHyperlink* pHyperLink;
} EASYMODERNHYPERLINKINT, * PEASYMODERNHYPERLINKINT;

typedef struct _EasyModernSwitchInt {
	int unused;
	CModernSwitch* pSwitch;
} EASYMODERNSWITCHINT, * PEASYMODERNSWITCHINT;

typedef struct _EasyModernCheckboxInt {
	int unused;
	CModernCheckbox* pCheckbox;
} EASYMODERNCHECKBOXINT, *PEASYMODERNCHECKBOXINT;

typedef struct _EasyModernMediaPlayerInt {
	int unused;
	CModernMediaPlayer* pPlayer;
} EASYMODERNMEDIAPLAYERINT, * PEASYMODERNMEDIAPLAYERINT;

typedef struct _EasyWinUIProgressRingInt {
	int unused;
	CWinUIProgressRing* pRing;
} EASYWINUIPROGRESSRINGINT, * PEASYWINUIPROGRESSRINGINT;

typedef struct _EasyWinUIProgressbarInt {
	int unused;
	CWinUIProgressbar* pProgressbar;
} EASYWINUIPROGRESSBARINT, * PEASYWINUIPROGRESSBARINT;

typedef struct _EasyWinUINumberBoxInt {
	int unused;
	CWinUINumberBox* pNumBox;
} EASYWINUINUMBERBOXINT, * PEASYWINUINUMBERBOXINT;

BOOL g_UseWinUI = FALSE;

__declspec(dllexport) BOOL __cdecl EasyWinModernCtrl_IsSystemSupport() {
	return CModernControl::IsSupportSystem();
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_InitializeApartment(BOOL useMTA, BOOL useWinUI) {
	CModernControl::Initialize(useMTA, useWinUI);
	g_UseWinUI = useWinUI;
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_UnInitialize() {
	CModernControl::UnInitialize();
}

__declspec(dllexport)  PEASYMODERNPWDBOX __cdecl EasyWinModernCtrl_CreatePasswordBox(LPCWSTR controlName, LPCWSTR headerTitle, LPCWSTR textPlaceholder, DWORD maxLength) {
	PEASYMODERNPWDBOXINT pwdbox = (PEASYMODERNPWDBOXINT)malloc(sizeof(EASYMODERNPWDBOXINT));
	if (pwdbox) {
		pwdbox->unused = _EASYWINNOTY_PWDBOX;
		pwdbox->pPwdbox = new CModernPasswordbox(controlName, headerTitle, textPlaceholder,maxLength);
	}

	return (PEASYMODERNPWDBOX)pwdbox;
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

__declspec(dllexport) void __cdecl EasyWinModernCtrl_TextboxSetTextWithSize(PEASYMODERNTEXTBOX pTextboxInfo, LPCWSTR text,DWORD size) {
	PEASYMODERNTEXTBOXINT pInfo = (PEASYMODERNTEXTBOXINT)pTextboxInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_TEXTBOX) {
		pInfo->pTextbox->SetText(text,size);
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

__declspec(dllexport) void __cdecl EasyWinModernCtrl_TextboxSetSpellCheck(PEASYMODERNTEXTBOX pTextboxInfo, BOOL enable) {
	PEASYMODERNTEXTBOXINT pInfo = (PEASYMODERNTEXTBOXINT)pTextboxInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_TEXTBOX) {
		pInfo->pTextbox->SetSpellCheck(enable);
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

__declspec(dllexport) void __cdecl EasyWinModernCtrl_ButtonSetEnableControl(PEASYMODERNBTN pBtnInfo, BOOL enable) {
	PEASYMODERNBTNINT pInfo = (PEASYMODERNBTNINT)pBtnInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_BUTTON) {
		pInfo->pBtn->SetEnableControl(enable);
	}
}


__declspec(dllexport) PEASYMODERNSLIDEBAR __cdecl EasyWinModernCtrl_CreateSlidebar(LPCWSTR controlName, DWORD id, DOUBLE minVal, DOUBLE maxVal, DOUBLE step, DOUBLE defaultValue) {
	PEASYMODERNSLIDEBARINT slidebar = (PEASYMODERNSLIDEBARINT)malloc(sizeof(EASYMODERNSLIDEBARINT));
	if (slidebar) {
		slidebar->unused = _EASYWINNOTY_SLIDEBAR;
		slidebar->pSlidebar = new CModernSlidebar(controlName, id, minVal, maxVal, step, defaultValue);
	}

	return (PEASYMODERNSLIDEBAR)slidebar;
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_SlidebarSetValueChangedCallback(PEASYMODERNSLIDEBAR pSlidebarInfo, TEasyWinModernCtrl_SlidebarCallback cb, PVOID userData) {
	PEASYMODERNSLIDEBARINT pInfo = (PEASYMODERNSLIDEBARINT)pSlidebarInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_SLIDEBAR) {
		pInfo->pSlidebar->SetValueChangedCallback(cb, userData);
	}
}

__declspec(dllexport) DOUBLE __cdecl EasyWinModernCtrl_SlidebarGetValue(PEASYMODERNSLIDEBAR pSlidebarInfo) {
	PEASYMODERNSLIDEBARINT pInfo = (PEASYMODERNSLIDEBARINT)pSlidebarInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_SLIDEBAR) {
		return pInfo->pSlidebar->GetValue();
	}

	return 0;
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_SlidebarSetEnableControl(PEASYMODERNSLIDEBAR pSlidebarInfo, BOOL enable) {
	PEASYMODERNSLIDEBARINT pInfo = (PEASYMODERNSLIDEBARINT)pSlidebarInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_SLIDEBAR) {
		pInfo->pSlidebar->SetEnableControl(enable);
	}
}

__declspec(dllexport) PEASYMODERNPROGRESSRING __cdecl EasyWinModernCtrl_CreateProgressring(LPCWSTR controlName) {
	PEASYMODERNPROGRESSRINGINT slidebar = (PEASYMODERNPROGRESSRINGINT)malloc(sizeof(EASYMODERNPROGRESSRINGINT));
	if (slidebar) {
		slidebar->unused = _EASYWINNOTY_PROGRESSRING;
		slidebar->pRing = new CModernProgressring(controlName);
	}

	return (PEASYMODERNPROGRESSRING)slidebar;
}

__declspec(dllexport) PEASYMODERNTIMEPICKER __cdecl EasyWinModernCtrl_CreateTimePicker(LPCWSTR controlName, LPCWSTR headerText, BOOL use24hours) {
	PEASYMODERNTIMEPICKERINT timePicker = (PEASYMODERNTIMEPICKERINT)malloc(sizeof(EASYMODERNTIMEPICKERINT));
	if (timePicker) {
		timePicker->unused = _EASYWINNOTY_TIMEPICKER;
		timePicker->pTimePicker = new CModernTimePicker(controlName,headerText,use24hours);
	}

	return (PEASYMODERNTIMEPICKER)timePicker;
}

__declspec(dllexport) INT64 __cdecl EasyWinModernCtrl_TimePickerGetSelectedTimeAsSeconds(PEASYMODERNTIMEPICKER pTimePickerInfo) {
	PEASYMODERNTIMEPICKERINT pInfo = (PEASYMODERNTIMEPICKERINT)pTimePickerInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_TIMEPICKER) {
		return pInfo->pTimePicker->GetSelectedTimeAsSeconds();
	}

	return 0;
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_TimePickerSetTimeUsingSeconds(PEASYMODERNTIMEPICKER pTimePickerInfo, INT64 seconds) {
	PEASYMODERNTIMEPICKERINT pInfo = (PEASYMODERNTIMEPICKERINT)pTimePickerInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_TIMEPICKER) {
		pInfo->pTimePicker->SetTimeUsingSeconds(seconds);
	}
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_TimePickerSetValueChangedCallback(PEASYMODERNTIMEPICKER pTimePickerInfo, TEasyWinModernCtrl_TimePickerCallback cb, PVOID userData) {
	PEASYMODERNTIMEPICKERINT pInfo = (PEASYMODERNTIMEPICKERINT)pTimePickerInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_TIMEPICKER) {
		pInfo->pTimePicker->SetTimeCallback(cb, userData);
	}
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_TimePickerEnableControl(PEASYMODERNTIMEPICKER pTimePickerInfo, BOOL enable) {
	PEASYMODERNTIMEPICKERINT pInfo = (PEASYMODERNTIMEPICKERINT)pTimePickerInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_TIMEPICKER) {
		pInfo->pTimePicker->SetEnableControl(enable);
	}
}

__declspec(dllexport) PEASYMODERNRADIOBTN __cdecl EasyWinModernCtrl_CreateRadioButton(LPCWSTR groupName, LPCWSTR headerText, BOOL useVerticalMode) {
	PEASYMODERNRADIOBTNINT radioBtn = (PEASYMODERNRADIOBTNINT)malloc(sizeof(EASYMODERNRADIOBTNINT));
	if (radioBtn) {
		radioBtn->unused = _EASYWINNOTY_RADIOBTN;
		radioBtn->pRadioBtn = new CModernRadioBtn(groupName, headerText, useVerticalMode);
	}

	return (PEASYMODERNRADIOBTN)radioBtn;
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_RadioBtnInsertItem(PEASYMODERNRADIOBTN pRadioBtn, DWORD idx, LPCWSTR text, BOOL defaultChecked, BOOL enabled) {
	PEASYMODERNRADIOBTNINT pInfo = (PEASYMODERNRADIOBTNINT)pRadioBtn;
	if (pInfo && pInfo->unused == _EASYWINNOTY_RADIOBTN) {
		pInfo->pRadioBtn->InsertItem(idx, text, defaultChecked, enabled);
	}
}

__declspec(dllexport) DWORD __cdecl EasyWinModernCtrl_RadioBtnGetCheckedItem(PEASYMODERNRADIOBTN pRadioBtn) {
	PEASYMODERNRADIOBTNINT pInfo = (PEASYMODERNRADIOBTNINT)pRadioBtn;
	if (pInfo && pInfo->unused == _EASYWINNOTY_RADIOBTN) {
		return pInfo->pRadioBtn->GetCheckedItem();
	}
	return MAXDWORD;
}
__declspec(dllexport) void __cdecl EasyWinModernCtrl_RadioBtnSetCheckedItem(PEASYMODERNRADIOBTN pRadioBtn, DWORD idx) {
	PEASYMODERNRADIOBTNINT pInfo = (PEASYMODERNRADIOBTNINT)pRadioBtn;
	if (pInfo && pInfo->unused == _EASYWINNOTY_RADIOBTN) {
		pInfo->pRadioBtn->SetCheckedItem(idx);
	}
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_RadioBtnSetValueChangedCallback(PEASYMODERNRADIOBTN pRadioBtn, TEasyWinModernCtrl_RadioBtnCallback cb, PVOID userData) {
	PEASYMODERNRADIOBTNINT pInfo = (PEASYMODERNRADIOBTNINT)pRadioBtn;
	if (pInfo && pInfo->unused == _EASYWINNOTY_RADIOBTN) {
		pInfo->pRadioBtn->SetValueChangedCallback(cb, userData);
	}
}

__declspec(dllexport) PEASYMODERNCALENDARDATEPICKER __cdecl EasyWinModernCtrl_CreateCalendarDatePicker(LPCWSTR controlName, LPCWSTR headerText) {
	PEASYMODERNCALENDARDATEPICKERINT pDatePicker = (PEASYMODERNCALENDARDATEPICKERINT)malloc(sizeof(EASYMODERNCALENDARDATEPICKERINT));
	if (pDatePicker) {
		pDatePicker->unused = _EASYWINNOTY_CALENDARPICKER;
		pDatePicker->pDatePicker = new CModernCalendarDatePicker(controlName, headerText);
	}

	return (PEASYMODERNCALENDARDATEPICKER)pDatePicker;
}

__declspec(dllexport) BOOL __cdecl EasyWinModernCtrl_CalendarDatePickerGetSelectedDate(PEASYMODERNCALENDARDATEPICKER pCalendarDatePicker, PFILETIME pSelectedTime) {
	PEASYMODERNCALENDARDATEPICKERINT pInfo = (PEASYMODERNCALENDARDATEPICKERINT)pCalendarDatePicker;
	if (pInfo && pInfo->unused == _EASYWINNOTY_CALENDARPICKER) {
		return pInfo->pDatePicker->GetSelectedDate(pSelectedTime);
	}
	return FALSE;
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_CalendarDatePickerSetDate(PEASYMODERNCALENDARDATEPICKER pCalendarDatePicker, FILETIME date) {
	PEASYMODERNCALENDARDATEPICKERINT pInfo = (PEASYMODERNCALENDARDATEPICKERINT)pCalendarDatePicker;
	if (pInfo && pInfo->unused == _EASYWINNOTY_CALENDARPICKER) {
		pInfo->pDatePicker->SetDate(date);
	}
}
__declspec(dllexport) void __cdecl EasyWinModernCtrl_CalendarDatePickerSetMinDate(PEASYMODERNCALENDARDATEPICKER pCalendarDatePicker, FILETIME date) {
	PEASYMODERNCALENDARDATEPICKERINT pInfo = (PEASYMODERNCALENDARDATEPICKERINT)pCalendarDatePicker;
	if (pInfo && pInfo->unused == _EASYWINNOTY_CALENDARPICKER) {
		pInfo->pDatePicker->SetMinDate(date);
	}
}
__declspec(dllexport) void __cdecl EasyWinModernCtrl_CalendarDatePickerSetMaxDate(PEASYMODERNCALENDARDATEPICKER pCalendarDatePicker, FILETIME date) {
	PEASYMODERNCALENDARDATEPICKERINT pInfo = (PEASYMODERNCALENDARDATEPICKERINT)pCalendarDatePicker;
	if (pInfo && pInfo->unused == _EASYWINNOTY_CALENDARPICKER) {
		pInfo->pDatePicker->SetMaxDate(date);
	}
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_CalendarDatePickerSetSelectedDateCallback(PEASYMODERNCALENDARDATEPICKER pCalendarDatePicker, TEasyWinModernCtrl_CalendarDatePickerCallback cb, PVOID userData) {
	PEASYMODERNCALENDARDATEPICKERINT pInfo = (PEASYMODERNCALENDARDATEPICKERINT)pCalendarDatePicker;
	if (pInfo && pInfo->unused == _EASYWINNOTY_CALENDARPICKER) {
		pInfo->pDatePicker->SetSelectedDateCallback(cb, userData);
	}
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_CalendarDatePickerEnableControl(PEASYMODERNCALENDARDATEPICKER pCalendarDatePicker, BOOL enable) {
	PEASYMODERNCALENDARDATEPICKERINT pInfo = (PEASYMODERNCALENDARDATEPICKERINT)pCalendarDatePicker;
	if (pInfo && pInfo->unused == _EASYWINNOTY_CALENDARPICKER) {
		pInfo->pDatePicker->SetEnableControl(enable);
	}
}

__declspec(dllexport) PEASYMODERNPROGRESSBAR __cdecl EasyWinModernCtrl_CreateProgressbar(LPCWSTR controlName, DOUBLE minVal, DOUBLE maxVal) {
	PEASYMODERNPROGRESSBARINT pProgressbar = (PEASYMODERNPROGRESSBARINT)malloc(sizeof(EASYMODERNPROGRESSBARINT));
	if (pProgressbar) {
		pProgressbar->unused = _EASYWINNOTY_PROGRESSBAR;
		pProgressbar->pProgressbar = new CModernProgressbar(controlName, minVal, maxVal);
	}

	return (PEASYMODERNPROGRESSBAR)pProgressbar;
}
__declspec(dllexport) void __cdecl EasyWinModernCtrl_ProgressbarSetValue(PEASYMODERNPROGRESSBAR pProgressInfo, BOOL isIndeterminate, BOOL isPause, DOUBLE value) {
	PEASYMODERNPROGRESSBARINT pInfo = (PEASYMODERNPROGRESSBARINT)pProgressInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_PROGRESSBAR) {
		pInfo->pProgressbar->SetValue(isIndeterminate, isPause, value);
	}
}

__declspec(dllexport) PEASYMODERNHYPERLINK __cdecl EasyWinModernCtrl_CreateHyperlink(LPCWSTR controlName, LPCWSTR textLabel) {
	PEASYMODERNHYPERLINKINT pHyperLink = (PEASYMODERNHYPERLINKINT)malloc(sizeof(EASYMODERNPROGRESSBARINT));
	if (pHyperLink) {
		pHyperLink->unused = _EASYWINNOTY_HYPERLINK;
		pHyperLink->pHyperLink = new CModernHyperlink(controlName, textLabel);
	}

	return (PEASYMODERNHYPERLINK)pHyperLink;
}
__declspec(dllexport) void __cdecl EasyWinModernCtrl_HyperlinkSetNavigateUri(PEASYMODERNHYPERLINK pHyperlinkInfo, LPCWSTR uri) {
	PEASYMODERNHYPERLINKINT pInfo = (PEASYMODERNHYPERLINKINT)pHyperlinkInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_HYPERLINK) {
		pInfo->pHyperLink->SetNavigateUri(uri);
	}
}
__declspec(dllexport) void __cdecl EasyWinModernCtrl_HyperlinkSetCustomClickCallback(PEASYMODERNHYPERLINK pHyperlinkInfo, TEasyWinModernCtrl_HyperLinkCallback cb, PVOID userData) {
	PEASYMODERNHYPERLINKINT pInfo = (PEASYMODERNHYPERLINKINT)pHyperlinkInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_HYPERLINK) {
		pInfo->pHyperLink->SetCustomClickCallback(cb, userData);
	}
}
__declspec(dllexport) void __cdecl EasyWinModernCtrl_HyperlinkEnableControl(PEASYMODERNHYPERLINK pHyperlinkInfo, BOOL enable) {
	PEASYMODERNHYPERLINKINT pInfo = (PEASYMODERNHYPERLINKINT)pHyperlinkInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_HYPERLINK) {
		pInfo->pHyperLink->SetEnableControl(enable);
	}
}


__declspec(dllexport) PEASYMODERNSWITCH __cdecl EasyWinModernCtrl_CreateToggleSwitch(LPCWSTR controlName, LPCWSTR headerTitle, LPCWSTR onContent, LPCWSTR offContent, BOOL defaultValue) {
	PEASYMODERNSWITCHINT pSwitch = (PEASYMODERNSWITCHINT)malloc(sizeof(EASYMODERNSWITCHINT));
	if (pSwitch) {
		pSwitch->unused = _EASYWINNOTY_SWITCH;
		pSwitch->pSwitch = new CModernSwitch(controlName, headerTitle,onContent,offContent,defaultValue);
	}

	return (PEASYMODERNSWITCH)pSwitch;
}

__declspec(dllexport) BOOL __cdecl EasyWinModernCtrl_ToggleSwitchGetStatus(PEASYMODERNSWITCH pSwitch) {
	PEASYMODERNSWITCHINT pInfo = (PEASYMODERNSWITCHINT)pSwitch;
	if (pInfo && pInfo->unused == _EASYWINNOTY_SWITCH) {
		return pInfo->pSwitch->GetStatus();
	}
	return FALSE;
}

__declspec(dllexport) void EasyWinModernCtrl_ToggleSwitchSetChangedCallback(PEASYMODERNSWITCH pSwitch, TEasyWinModernCtrl_SwitchCallback callbackFunc, PVOID userData) {
	PEASYMODERNSWITCHINT pInfo = (PEASYMODERNSWITCHINT)pSwitch;
	if (pInfo && pInfo->unused == _EASYWINNOTY_SWITCH) {
		pInfo->pSwitch->SetValueChangedCallback(callbackFunc, userData);
	}
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_ToggleSwitchEnableControl(PEASYMODERNSWITCH pSwitch, BOOL enable) {
	PEASYMODERNSWITCHINT pInfo = (PEASYMODERNSWITCHINT)pSwitch;
	if (pInfo && pInfo->unused == _EASYWINNOTY_SWITCH) {
		pInfo->pSwitch->SetEnableControl(enable);
	}
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_ToggleSwitchSetStatus(PEASYMODERNSWITCH pSwitch, BOOL status) {
	PEASYMODERNSWITCHINT pInfo = (PEASYMODERNSWITCHINT)pSwitch;
	if (pInfo && pInfo->unused == _EASYWINNOTY_SWITCH) {
		pInfo->pSwitch->SetStatus(status);
	}
}

__declspec(dllexport) PEASYMODERNCHECKBOX __cdecl EasyWinModernCtrl_CreateCheckbox(LPCWSTR controlName, DWORD id, LPCWSTR label, BOOL allowIndeterminate) {
	PEASYMODERNCHECKBOXINT pInfo = (PEASYMODERNCHECKBOXINT)malloc(sizeof(EASYMODERNCHECKBOXINT));
	if (pInfo) {
		pInfo->unused = _EASYWINNOTY_CHECKBOX;
		pInfo->pCheckbox = new CModernCheckbox(controlName, id, label, allowIndeterminate);
	}

	return (PEASYMODERNCHECKBOX)pInfo;
}

__declspec(dllexport) BOOL __cdecl EasyWinModernCtrl_CheckboxGetStatus(PEASYMODERNCHECKBOX pCheckbox, PBOOL pIsIndeterminate) {
	PEASYMODERNCHECKBOXINT pInfo = (PEASYMODERNCHECKBOXINT)pCheckbox;
	if (pInfo && pInfo->unused == _EASYWINNOTY_CHECKBOX) {
		return pInfo->pCheckbox->GetStatus(pIsIndeterminate);
	}
	return FALSE;
}
__declspec(dllexport) void __cdecl EasyWinModernCtrl_CheckboxSetStatus(PEASYMODERNCHECKBOX pCheckbox, BOOL isChecked, BOOL isIndeterminate) {
	PEASYMODERNCHECKBOXINT pInfo = (PEASYMODERNCHECKBOXINT)pCheckbox;
	if (pInfo && pInfo->unused == _EASYWINNOTY_CHECKBOX) {
		pInfo->pCheckbox->SetStatus(isChecked, isIndeterminate);
	}
}
__declspec(dllexport) void __cdecl EasyWinModernCtrl_CheckboxSetEnableControl(PEASYMODERNCHECKBOX pCheckbox, BOOL enable) {
	PEASYMODERNCHECKBOXINT pInfo = (PEASYMODERNCHECKBOXINT)pCheckbox;
	if (pInfo && pInfo->unused == _EASYWINNOTY_CHECKBOX) {
		pInfo->pCheckbox->SetEnableControl(enable);
	}
}
__declspec(dllexport) void __cdecl EasyWinModernCtrl_CheckboxSetChangedCallback(PEASYMODERNCHECKBOX pCheckbox, TEasyWinModernCtrl_CheckboxCallback callbackFunc, PVOID userData) {
	PEASYMODERNCHECKBOXINT pInfo = (PEASYMODERNCHECKBOXINT)pCheckbox;
	if (pInfo && pInfo->unused == _EASYWINNOTY_CHECKBOX) {
		pInfo->pCheckbox->SetValueChangedCallback(callbackFunc, userData);
	}
}

__declspec(dllexport) PEASYMODERNMEDIAPLAYER __cdecl EasyWinModernCtrl_CreateMediaPlayer(LPCWSTR controlName) {
	PEASYMODERNMEDIAPLAYERINT pSwitch = (PEASYMODERNMEDIAPLAYERINT)malloc(sizeof(EASYMODERNMEDIAPLAYERINT));
	if (pSwitch) {
		pSwitch->unused = _EASYWINNOTY_MEDIAPLAYER;
		pSwitch->pPlayer = new CModernMediaPlayer();
	}

	return (PEASYMODERNMEDIAPLAYER)pSwitch;
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_MediaPlayerSetUriSource(PEASYMODERNMEDIAPLAYER pMediaPlayer, LPCWSTR uri) {
	PEASYMODERNMEDIAPLAYERINT pInfo = (PEASYMODERNMEDIAPLAYERINT)pMediaPlayer;
	if (pInfo && pInfo->unused == _EASYWINNOTY_MEDIAPLAYER) {
		pInfo->pPlayer->SetUriSource(uri);
	}
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_MediaPlayerSetStreamSource(PEASYMODERNMEDIAPLAYER pMediaPlayer, PVOID pRandomStream) {
	PEASYMODERNMEDIAPLAYERINT pInfo = (PEASYMODERNMEDIAPLAYERINT)pMediaPlayer;
	if (pInfo && pInfo->unused == _EASYWINNOTY_MEDIAPLAYER) {

		winrt::Windows::Storage::Streams::IRandomAccessStream* randomStream = (winrt::Windows::Storage::Streams::IRandomAccessStream*)(pRandomStream);

		pInfo->pPlayer->SetStreamSource(*randomStream);
	}
}

__declspec(dllexport) PEASYWINUIPROGRESSRING __cdecl EasyWinModernCtrl_CreateWinUIProgressring(LPCWSTR controlName) {
	if (!g_UseWinUI) {
		return NULL;
	}

	PEASYWINUIPROGRESSRINGINT pRing = (PEASYWINUIPROGRESSRINGINT)malloc(sizeof(EASYWINUIPROGRESSRINGINT));
	if (pRing) {
		pRing->unused = _EASYWINNOTY_WINUIPROGRESSRING;
		pRing->pRing = new CWinUIProgressRing(controlName);
	}
	return (PEASYWINUIPROGRESSRING)pRing;
}

__declspec(dllexport) PEASYWINUIPROGRESSBAR __cdecl EasyWinModernCtrl_CreateWinUIProgressbar(LPCWSTR controlName, DOUBLE minVal, DOUBLE maxVal) {
	if (!g_UseWinUI) {
		return NULL;
	}

	PEASYWINUIPROGRESSBARINT pBar = (PEASYWINUIPROGRESSBARINT)malloc(sizeof(EASYWINUIPROGRESSBARINT));
	if (pBar) {
		pBar->unused = _EASYWINNOTY_WINUIPROGRESSBAR;
		pBar->pProgressbar = new CWinUIProgressbar(controlName, minVal, maxVal);
	}
	return (PEASYWINUIPROGRESSBAR)pBar;
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_WinUIProgressbarSetValue(PEASYWINUIPROGRESSBAR pProgressInfo, BOOL isIndeterminate, BOOL isPause, DOUBLE value) {
	PEASYWINUIPROGRESSBARINT pInfo = (PEASYWINUIPROGRESSBARINT)pProgressInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_WINUIPROGRESSBAR) {
		pInfo->pProgressbar->SetValue(isIndeterminate, isPause, value);
	}
}

__declspec(dllexport) PEASYWINUINUMBERBOX __cdecl EasyWinModernCtrl_CreateWinUINumberBox(LPCWSTR controlName, LPCWSTR headerTitle, LPCWSTR textPlaceholder) {
	if (!g_UseWinUI) {
		return NULL;
	}

	PEASYWINUINUMBERBOXINT pNum = (PEASYWINUINUMBERBOXINT)malloc(sizeof(EASYWINUINUMBERBOXINT));
	if (pNum) {
		pNum->unused = _EASYWINNOTY_WINUINUMBERBOX;
		pNum->pNumBox = new CWinUINumberBox(controlName, headerTitle, textPlaceholder);
	}
	return (PEASYWINUINUMBERBOX)pNum;
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_WinUINumberBoxSetButtonType(PEASYWINUINUMBERBOX pNumberBoxInfo, DWORD mode) {
	PEASYWINUINUMBERBOXINT pInfo = (PEASYWINUINUMBERBOXINT)pNumberBoxInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_WINUINUMBERBOX) {
		pInfo->pNumBox->SetButtonType(mode);
	}
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_WinUINumberBoxSetValue(PEASYWINUINUMBERBOX pNumberBoxInfo, DOUBLE value) {
	PEASYWINUINUMBERBOXINT pInfo = (PEASYWINUINUMBERBOXINT)pNumberBoxInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_WINUINUMBERBOX) {
		pInfo->pNumBox->SetValue(value);
	}
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_WinUINumberBoxSetMinValue(PEASYWINUINUMBERBOX pNumberBoxInfo, DOUBLE value) {
	PEASYWINUINUMBERBOXINT pInfo = (PEASYWINUINUMBERBOXINT)pNumberBoxInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_WINUINUMBERBOX) {
		pInfo->pNumBox->SetMinValue(value);
	}
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_WinUINumberBoxSetMaxValue(PEASYWINUINUMBERBOX pNumberBoxInfo, DOUBLE value) {
	PEASYWINUINUMBERBOXINT pInfo = (PEASYWINUINUMBERBOXINT)pNumberBoxInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_WINUINUMBERBOX) {
		pInfo->pNumBox->SetMaxValue(value);
	}
}

__declspec(dllexport) void __cdecl EasyWinModernCtrl_WinUINumberBoxSetChangeStep(PEASYWINUINUMBERBOX pNumberBoxInfo, DOUBLE step) {
	PEASYWINUINUMBERBOXINT pInfo = (PEASYWINUINUMBERBOXINT)pNumberBoxInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_WINUINUMBERBOX) {
		pInfo->pNumBox->SetChangeStep(step);
	}
}

__declspec(dllexport) DOUBLE __cdecl EasyWinModernCtrl_WinUINumberBoxGetValue(PEASYWINUINUMBERBOX pNumberBoxInfo) {
	PEASYWINUINUMBERBOXINT pInfo = (PEASYWINUINUMBERBOXINT)pNumberBoxInfo;
	if (pInfo && pInfo->unused == _EASYWINNOTY_WINUINUMBERBOX) {
		return pInfo->pNumBox->GetValue();
	}
	return 0;
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

__declspec(dllexport) HWND __cdecl EasyWinModernCtrl_GetRawControlHwnd(PVOID pControl) {
	PEASYMODERNBTNINT pControlInfo = (PEASYMODERNBTNINT)pControl;
	if (pControlInfo) {
		return ((CModernControl*)(pControlInfo->pBtn))->GetRawControlHwnd();
	}
	return 0;
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
		case _EASYWINNOTY_PROGRESSRING: {
			delete (CModernProgressring*)(pControlInfo->pBtn);
		}; break;
		case _EASYWINNOTY_TIMEPICKER: {
			delete (CModernTimePicker*)(pControlInfo->pBtn);
		}; break;
		case _EASYWINNOTY_RADIOBTN: {
			delete (CModernRadioBtn*)(pControlInfo->pBtn);
		}; break;
		case _EASYWINNOTY_CALENDARPICKER: {
			delete (CModernCalendarDatePicker*)(pControlInfo->pBtn);
		}; break;
		case _EASYWINNOTY_PROGRESSBAR: {
			delete (CModernProgressbar*)(pControlInfo->pBtn);
		}; break;
		case _EASYWINNOTY_HYPERLINK: {
			delete (CModernHyperlink*)(pControlInfo->pBtn);
		}; break;
		case _EASYWINNOTY_SWITCH: {
			delete (CModernSwitch*)(pControlInfo->pBtn);
		}; break;
		case _EASYWINNOTY_CHECKBOX: {
			delete (CModernCheckbox*)(pControlInfo->pBtn);
		}; break;
		case _EASYWINNOTY_MEDIAPLAYER: {
			delete (CModernMediaPlayer*)(pControlInfo->pBtn);
		}; break;
		case _EASYWINNOTY_WINUIPROGRESSRING: {
			delete (CWinUIProgressRing*)(pControlInfo->pBtn);
		}; break;
		case _EASYWINNOTY_WINUIPROGRESSBAR: {
			delete (CWinUIProgressbar*)(pControlInfo->pBtn);
		}; break;
		case _EASYWINNOTY_WINUINUMBERBOX: {
			delete (CWinUINumberBox*)(pControlInfo->pBtn);
		}; break;
	}

	free(pControlInfo);
}