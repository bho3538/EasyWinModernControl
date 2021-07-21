#include "stdafx.h"
#include "CModernControl.h"

using namespace EasyWinModernControl;

typedef NTSTATUS(__stdcall* TRtlGetVersion)(OSVERSIONINFOEXW* ovf);
TRtlGetVersion _RtlGetVersion = NULL;

HRESULT CModernControl::Initialize(BOOL useMTA) {
	if (useMTA) {
		winrt::init_apartment(apartment_type::multi_threaded);
	}
	else {
		winrt::init_apartment(apartment_type::single_threaded);
	}

	return 0;
}

BOOL CModernControl::IsSupportSystem() {
	OSVERSIONINFOEXW verInfo = { 0, };
	NTSTATUS status = 0;

	if (!_RtlGetVersion) {
		_RtlGetVersion = (TRtlGetVersion)GetProcAddress(LoadLibraryW(L"ntdll.dll"), "RtlGetVersion");
		if (!_RtlGetVersion) {
			return FALSE;
		}
	}

	_RtlGetVersion(&verInfo);

	//Windows 10 RS5
	if (verInfo.dwBuildNumber >= 17763) {
		return TRUE;
	}

	return FALSE;
}

CModernControl::CModernControl() {

}

CModernControl::~CModernControl() {

}


HRESULT CModernControl::Show(HWND parentHwnd) {
	HRESULT hr = S_OK;
	RECT rect;
	winrt::impl::com_ref<IDesktopWindowXamlSourceNative> pXamlSource = NULL;

	if (!parentHwnd) {
		hr = E_INVALIDARG;
		goto escapeArea;
	}
	this->_parentHwnd = parentHwnd;

	pXamlSource = this->xs.as<IDesktopWindowXamlSourceNative>();
	if (!pXamlSource) {
		hr = E_FAIL;
		goto escapeArea;
	}

	if (!this->ins) {
		this->SetTemplate();
		if (!this->ins) {
			hr = E_FAIL;
			goto escapeArea;
		}
	}
	hr = pXamlSource->AttachToWindow(parentHwnd);
	if (FAILED(hr)) {
		goto escapeArea;
	}

	hr = pXamlSource->get_WindowHandle(&this->_uwpHwnd);
	if (FAILED(hr)) {
		goto escapeArea;
	}

	xs.Content(ins.as<UIElement>());

	ins.as< Windows::UI::Xaml::Controls::StackPanel>().RequestedTheme(this->_theme);

	//show uwp window at win32 window.
	GetWindowRect(parentHwnd, &rect);
	SetWindowPos(_uwpHwnd, 0, 0, 0, rect.right - rect.left, rect.bottom - rect.top, SWP_SHOWWINDOW);
	ShowWindow(_uwpHwnd, SW_SHOW);

escapeArea:

	return hr;
}

void CModernControl::Close() {
	CloseWindow(this->_uwpHwnd);
	DestroyWindow(this->_uwpHwnd);

	this->_uwpHwnd = NULL;
}

void CModernControl::Hide(BOOL reShow) {
	if (reShow) {
		ShowWindow(this->_uwpHwnd, SW_SHOW);
	}
	else {
		ShowWindow(this->_uwpHwnd, SW_HIDE);
	}
}
HWND CModernControl::GetRawControlHwnd() {
	return this->_uwpHwnd;
}

void CModernControl::AdjustLayout() {
	RECT windowRect = { 0, };
	if (this->_parentHwnd && this->_uwpHwnd) {
		GetWindowRect(this->_parentHwnd, &windowRect);
		SetWindowPos(this->_uwpHwnd, NULL, 0, 0, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, SWP_SHOWWINDOW);
	
		this->_height = windowRect.bottom - windowRect.top;
		this->_width = windowRect.right - windowRect.left;
	}

	OnAdjustLayout();
}

void CModernControl::SetTemplate() {
	return;
}

void CModernControl::OnAdjustLayout() {
	return;
}

void CModernControl::SetTheme(DWORD dwFlags) {
	if (dwFlags == 1) {
		this->_theme = winrt::Windows::UI::Xaml::ElementTheme::Light;
	}
	else if (dwFlags == 2) {
		this->_theme = winrt::Windows::UI::Xaml::ElementTheme::Dark;
	}
	else {
		this->_theme = winrt::Windows::UI::Xaml::ElementTheme::Default;
	}
}