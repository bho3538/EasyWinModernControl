#include "stdafx.h"
#include "CModernSwitch.h"

using namespace EasyWinModernControl;

LPCWSTR CModernSwitch::xml = LR"(
<StackPanel xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
</StackPanel>)";

CModernSwitch::CModernSwitch(LPCWSTR controlName, LPCWSTR headerTitle, LPCWSTR onContent, LPCWSTR offContent, BOOL defaultValue)
{
    if (controlName) {
        this->_switch.Name(controlName);
    }

    if (headerTitle) {
        this->_switch.Header(winrt::box_value(headerTitle));
    }

    if (onContent) {
        this->_switch.OnContent(winrt::box_value(onContent));
    }

    if (offContent) {
        this->_switch.OffContent(winrt::box_value(offContent));
    }

    //this->_switch.IsOn(defaultValue);
    SetStatus(defaultValue);
}


CModernSwitch::~CModernSwitch()
{

}

BOOL CModernSwitch::GetStatus() {
    BOOL status = this->_switch.IsOn();

    return status;
}

void CModernSwitch::SetEnableControl(BOOL enable) {
    this->_switch.IsEnabled(enable);
}
void CModernSwitch::SetStatus(BOOL status) {
    this->_switch.IsOn(status);
}

void CModernSwitch::SetValueChangedCallback(_TEasyWinModernCtrl_SwitchCallback callbackFunc, PVOID userData) {
    this->_cb = callbackFunc;
    this->_userData = userData;
}

void CModernSwitch::CallCB() {
    if (this->_cb) {
        this->_cb(GetStatus(), this->_userData);
    }
}

void CModernSwitch::SetTemplate() {
	hstring str(xml);
	this->ins = XamlReader::Load(str);
	if (!this->ins) {
		return;
	}

    this->_switch.Toggled([this](const winrt::Windows::Foundation::IInspectable& sender, const RoutedEventArgs& args)
        {
            this->CallCB();
        });

	Windows::UI::Xaml::Controls::StackPanel panel = this->ins.as<Windows::UI::Xaml::Controls::StackPanel>();

	panel.Children().InsertAt(0, this->_switch);

	return;
}

void CModernSwitch::OnAdjustLayout() {
    this->_switch.Height(_height);
    this->_switch.Width(_width);
}