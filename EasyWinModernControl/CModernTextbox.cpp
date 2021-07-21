#include "stdafx.h"
#include "CModernTextbox.h"

using namespace EasyWinModernControl;

LPCWSTR CModernTextbox::xml = LR"(
<StackPanel xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
</StackPanel>)";

CModernTextbox::CModernTextbox(LPCWSTR controlName, LPCWSTR headerTitle, LPCWSTR textPlaceholder, BOOL enableMultiLine, BOOL enableUserChangeLine, DWORD maxTextLength) {
	if (controlName) {
		this->_textbox.Name(controlName);
	}

	if (headerTitle) {
		this->_textbox.Header(winrt::box_value(headerTitle));
	}

	if (textPlaceholder) {
		this->_textbox.PlaceholderText(textPlaceholder);
	}

	if (enableMultiLine) {
		this->_textbox.TextWrapping(winrt::Windows::UI::Xaml::TextWrapping::Wrap);
		this->_textbox.AcceptsReturn(enableUserChangeLine);

		Windows::UI::Xaml::Controls::ScrollViewer::SetVerticalScrollBarVisibility(this->_textbox, winrt::Windows::UI::Xaml::Controls::ScrollBarVisibility::Auto);
	}

	if (maxTextLength > 0) {
		this->_textbox.MaxLength(maxTextLength);
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

void CModernTextbox::SetEnableControl(BOOL enable) {
	if (!this->ins) {
		return;
	}

	this->_textbox.IsEnabled(enable);
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
	this->_textbox.Height(_height);
	this->_textbox.Width(_width);
}