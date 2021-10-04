#include "stdafx.h"
#include "CModernCheckbox.h"

using namespace EasyWinModernControl;

LPCWSTR CModernCheckbox::xml = LR"(
<StackPanel xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
</StackPanel>)";

CModernCheckbox::CModernCheckbox(LPCWSTR controlName,DWORD id, LPCWSTR label, BOOL allowIndeterminate) {
	this->_id = id;

	if (controlName) {
		this->_checkbox.Name(controlName);
	}

	if (label) {
		this->_checkbox.Content(winrt::box_value(label));
	}

	if (allowIndeterminate) {
		this->_checkbox.IsThreeState(allowIndeterminate);
	}
}

CModernCheckbox::~CModernCheckbox() {

}

BOOL CModernCheckbox::GetStatus(PBOOL isIndeterminate) {
	BOOL isChecked = FALSE;
	Windows::Foundation::IReference<bool> re = this->_checkbox.IsChecked();

	if (re) {
		isChecked = re.GetBoolean();
	}

	if (isIndeterminate) {
		*isIndeterminate = this->_checkbox.IsThreeState();
	}

	return isChecked;
}
void CModernCheckbox::SetStatus(BOOL isChecked, BOOL isIndeterminate) {
	if (isIndeterminate) {
		if (this->_checkbox.IsThreeState()) {
			this->_checkbox.IsChecked(nullptr);
		}
	}
	else {
		this->_checkbox.IsChecked(isChecked);
	}
}

void CModernCheckbox::SetEnableControl(BOOL enable) {
	this->_checkbox.IsEnabled(enable);
}

void CModernCheckbox::CallCB(BOOL isChecked, BOOL isIndeterminate) {
	if (this->_cb) {
		this->_cb(this->_id, isChecked, isIndeterminate);
	}
}

void CModernCheckbox::SetTemplate() {
	hstring str(xml);
	this->ins = XamlReader::Load(str);
	if (!this->ins) {
		return;
	}

	this->_checkbox.Checked([this](const winrt::Windows::Foundation::IInspectable& sender, const RoutedEventArgs& args)
		{
			this->CallCB(TRUE,FALSE);
		});

	this->_checkbox.Unchecked([this](const winrt::Windows::Foundation::IInspectable& sender, const RoutedEventArgs& args)
		{
			this->CallCB(FALSE,FALSE);
		});

	this->_checkbox.Indeterminate([this](const winrt::Windows::Foundation::IInspectable& sender, const RoutedEventArgs& args)
		{
			this->CallCB(TRUE,TRUE);
		});

	Windows::UI::Xaml::Controls::StackPanel panel = this->ins.as<Windows::UI::Xaml::Controls::StackPanel>();

	panel.Children().InsertAt(0, this->_checkbox);

	return;
}
void CModernCheckbox::OnAdjustLayout() {
	this->_checkbox.Height(_height);
	this->_checkbox.Width(_width);
}