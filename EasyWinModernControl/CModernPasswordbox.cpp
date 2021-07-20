#include "stdafx.h"
#include "CModernPasswordbox.h"

using namespace EasyWinModernControl;

CModernPasswordbox::CModernPasswordbox(LPCWSTR controlName, LPCWSTR headerTitle, LPCWSTR textPlaceholder, DWORD maxLength) {

	this->_pwdbox.Name(controlName);
	this->_pwdbox.Header(winrt::box_value(headerTitle));
	this->_pwdbox.PlaceholderText(textPlaceholder);

	if (maxLength > 0) {
		this->_pwdbox.MaxLength(maxLength);
	}
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