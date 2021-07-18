//#pragma once
//
//#include <ShlObj_core.h>
//
//class IModernControl {
//public:
//	// 0 : system default
//	// 1 : Light
//	// 2 : Dark
//	virtual void SetTheme(DWORD dwFlags) = 0;
//	virtual HRESULT Show(HWND hwnd) = 0;
//	virtual void AdjustLayout() = 0;
//};
//
//class IModernButton : public IModernControl {
//public:
//	virtual void SetClickCallback(_TEasyWinModernCtrl_BtnCallback callbackFunc,PVOID userData) = 0;
//};
//
//class IModernTextbox : public IModernControl {
//public:
//	virtual LPCWSTR GetText() = 0;
//	virtual void SetText(LPCWSTR text) = 0;
//	virtual void SetReadonlyMode(BOOL enable) = 0;
//	virtual void SetEnableControl(BOOL enable) = 0;
//};
//
//class IModernPasswordbox : public IModernControl {
//public:
//	virtual LPCWSTR GetPassword() = 0;
//	virtual void SetEnableControl(BOOL enable) = 0;
//};