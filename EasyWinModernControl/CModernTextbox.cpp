#include "stdafx.h"
#include "CModernTextbox.h"

using namespace EasyWinModernControl;

CModernTextbox::CModernTextbox(LPCWSTR controlName, LPCWSTR headerTitle, LPCWSTR textPlaceholder, BOOL enableMultiLine, BOOL enableUserChangeLine) {

	this->_textbox.Name(controlName);
	this->_textbox.Header(winrt::box_value(headerTitle));
	this->_textbox.PlaceholderText(textPlaceholder);
	if (enableMultiLine) {
		this->_textbox.TextWrapping(winrt::Windows::UI::Xaml::TextWrapping::Wrap);
		this->_textbox.AcceptsReturn(enableUserChangeLine);

		Windows::UI::Xaml::Controls::ScrollViewer::SetVerticalScrollBarVisibility(this->_textbox, winrt::Windows::UI::Xaml::Controls::ScrollBarVisibility::Auto);
	}
}

CModernTextbox::~CModernTextbox() {

}


LPCWSTR CModernTextbox::GetText() {
	if (!this->ins) {
		return NULL;
	}

	hstring str = this->_textbox.Text();

	return str.c_str();
}

void CModernTextbox::SetText(LPCWSTR text) {
	if (!this->ins) {
		return;
	}
	
	this->_textbox.Text(text);
}


void CModernTextbox::SetReadonlyMode(BOOL enable) {
	if (!this->ins) {
		return;
	}
	
	this->_textbox.IsReadOnly(enable);
}

void CModernTextbox::SetTemplate() {
	hstring str(xml);
	this->ins = XamlReader::Load(str);
	if (!this->ins) {
		return;
	}

	Windows::UI::Xaml::Controls::StackPanel panel = this->ins.as<Windows::UI::Xaml::Controls::StackPanel>();

	panel.Children().InsertAt(0, this->_textbox);

	

	return;
}

void CModernTextbox::OnAdjustLayout() {
	this->_textbox.MaxHeight(_height);
}
