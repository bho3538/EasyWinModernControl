#include "stdafx.h"
#include "CModernControl.h"

using namespace EasyWinModernControl;

HRESULT CModernControl::Initialize() {
	winrt::init_apartment(apartment_type::single_threaded);

	return 0;
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

	//show uwp window at win32 window.
	GetWindowRect(parentHwnd, &rect);
	SetWindowPos(_uwpHwnd, 0, 0, 0, rect.right - rect.left, rect.bottom - rect.top, SWP_SHOWWINDOW);
	ShowWindow(_uwpHwnd, SW_SHOW);

escapeArea:

	return hr;
}

void CModernControl::AdjustLayout() {
	RECT windowRect = { 0, };
	if (this->_parentHwnd && this->_uwpHwnd) {
		GetWindowRect(this->_parentHwnd, &windowRect);
		SetWindowPos(this->_uwpHwnd, NULL, 0, 0, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, SWP_SHOWWINDOW);
	
		this->_height = windowRect.bottom - windowRect.top;
	}

	OnAdjustLayout();
}

void CModernControl::SetTemplate() {
	return;
}

void CModernControl::OnAdjustLayout() {
	return;
}