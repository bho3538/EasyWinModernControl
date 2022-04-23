#include "stdafx.h"
#include "CModernPasswordbox.h"

using namespace EasyWinModernControl;

LPCWSTR CModernPasswordbox::xml = LR"(
<StackPanel xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
</StackPanel>)";

CModernPasswordbox::CModernPasswordbox(LPCWSTR controlName, LPCWSTR headerTitle, LPCWSTR textPlaceholder, DWORD maxLength) {
	if (controlName) {
		this->_pwdbox.Name(controlName);
	}

	if (headerTitle) {
		this->_pwdbox.Header(winrt::box_value(headerTitle));
	}

	if (textPlaceholder) {
		this->_pwdbox.PlaceholderText(textPlaceholder);
	}

	if (maxLength > 0) {
		this->_pwdbox.MaxLength(maxLength);
	}

	//fix normal control focus issue
	this->_pwdbox.GettingFocus([this](const winrt::Windows::Foundation::IInspectable& sender, const RoutedEventArgs& args)
		{
			SendMessageW(this->GetParentHwnd(), WM_SETFOCUS, 0, 0);
		});
}

CModernPasswordbox::~CModernPasswordbox() {

}


LPCWSTR CModernPasswordbox::GetPassword() {
	if (!this->ins) {
		return NULL;
	}

	hstring str = this->_pwdbox.Password();

	return str.c_str();
}

void CModernPasswordbox::SetEnableControl(BOOL enable) {
	if (!this->ins) {
		return;
	}

	this->_pwdbox.IsEnabled(enable);
}

void CModernPasswordbox::SetTemplate() {
	hstring str(xml);
	this->ins = XamlReader::Load(str);
	if (!this->ins) {
		return;
	}

	Windows::UI::Xaml::Controls::StackPanel panel = this->ins.as<Windows::UI::Xaml::Controls::StackPanel>();

	panel.Children().InsertAt(0, this->_pwdbox);


	return;
}

void CModernPasswordbox::OnAdjustLayout() {
	//this->_pwdbox.MaxHeight(_height);
	this->_pwdbox.Height(_height);
	this->_pwdbox.Width(_width);
}