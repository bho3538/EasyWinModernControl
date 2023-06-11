#include "stdafx.h"
#include "CWinUINumberBox.h"

using namespace EasyWinModernControl;

LPCWSTR CWinUINumberBox::xml = LR"(
<StackPanel xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
</StackPanel>)";

CWinUINumberBox::CWinUINumberBox(LPCWSTR controlName, LPCWSTR headerTitle, LPCWSTR textPlaceholder) {
	if (controlName) {
		this->_numBox.Name(controlName);
	}

	if (headerTitle) {
		this->_numBox.Header(winrt::box_value(headerTitle));
	}

	if (textPlaceholder) {
		this->_numBox.PlaceholderText(textPlaceholder);
	}

	//fix normal control focus issue
	this->_numBox.GettingFocus([this](const winrt::Windows::Foundation::IInspectable& sender, const RoutedEventArgs& args)
		{
			SendMessageW(this->GetParentHwnd(), WM_SETFOCUS, 0, 0);
		});
}

CWinUINumberBox::~CWinUINumberBox() {

}

void CWinUINumberBox::SetButtonType(DWORD mode) {
	if (mode == 1) {
		this->_numBox.SpinButtonPlacementMode(Microsoft::UI::Xaml::Controls::NumberBoxSpinButtonPlacementMode::Compact);
	}
	else if (mode == 2) {
		this->_numBox.SpinButtonPlacementMode(Microsoft::UI::Xaml::Controls::NumberBoxSpinButtonPlacementMode::Inline);
	}
	else {
		this->_numBox.SpinButtonPlacementMode(Microsoft::UI::Xaml::Controls::NumberBoxSpinButtonPlacementMode::Hidden);
	}
}

void CWinUINumberBox::SetValue(DOUBLE value) {
	this->_numBox.Value(value);
}


void CWinUINumberBox::SetMinValue(DOUBLE val) {
	this->_numBox.Minimum(val);
}

void CWinUINumberBox::SetMaxValue(DOUBLE val) {
	this->_numBox.Maximum(val);
}

DOUBLE CWinUINumberBox::GetValue() {
	return this->_numBox.Value();
}

void CWinUINumberBox::SetChangeStep(DOUBLE step) {
	this->_numBox.SmallChange(step);
}

void CWinUINumberBox::SetTemplate() {
	hstring str(xml);
	this->ins = XamlReader::Load(str);
	if (!this->ins) {
		return;
	}

	Windows::UI::Xaml::Controls::StackPanel panel = this->ins.as<Windows::UI::Xaml::Controls::StackPanel>();

	panel.Children().InsertAt(0, this->_numBox);

	return;
}

void CWinUINumberBox::OnAdjustLayout() {
	this->_numBox.Height(this->_height);
	this->_numBox.Width(this->_width);
}