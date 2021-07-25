#include "stdafx.h"
#include "CModernButton.h"

using namespace EasyWinModernControl;

LPCWSTR CModernButton::xml =  LR"(
<StackPanel xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
</StackPanel>)";

CModernButton::CModernButton(LPCWSTR controlName, DWORD id, LPCWSTR buttonLabel) {
	if (controlName) {
		this->_btn.Name(controlName);
	}

	if (buttonLabel) {
		this->_btn.Content(winrt::box_value(buttonLabel));
	}
	this->_id = id;
}

CModernButton::~CModernButton() {
	
}

void CModernButton::SetTemplate() {
	hstring str(xml);
	this->ins = XamlReader::Load(str);
	if (!this->ins) {
		return;
	}

	this->_btn.Click([this](const winrt::Windows::Foundation::IInspectable& sender, const RoutedEventArgs& args)
		{
			this->CallCB();
		});

	Windows::UI::Xaml::Controls::StackPanel panel = this->ins.as<Windows::UI::Xaml::Controls::StackPanel>();

	if (this->_useAccentColor) {
		auto resources = Application::Current().Resources().Lookup(winrt::box_value(L"AccentButtonStyle"));
		if (resources) {
			this->_btn.Style(resources.as< winrt::Windows::UI::Xaml::Style>());
		}
	}
	panel.Children().InsertAt(0, this->_btn);

	return;
}

void CModernButton::SetClickCallback(_TEasyWinModernCtrl_BtnCallback callbackFunc, PVOID userData) {
	this->_callbackFunc = callbackFunc;
	this->_userData = userData;
}

void CModernButton::CallCB() {
	if (this->_callbackFunc) {
		this->_callbackFunc(this->_id, this->_userData);
	}
}

void CModernButton::SetEnableControl(BOOL enable) {
	this->_btn.IsEnabled(enable);
}

void CModernButton::SetUseAccentColor(BOOL enable) {
	this->_useAccentColor = enable;
}

void CModernButton::OnAdjustLayout() {
	this->_btn.Height(this->_height);
	this->_btn.Width(this->_width);
}