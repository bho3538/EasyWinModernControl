#include "stdafx.h"
#include "CModernSlidebar.h"

using namespace EasyWinModernControl;

CModernSlidebar::CModernSlidebar(LPCWSTR controlName, DWORD id, DOUBLE minVal, DOUBLE maxVal, DOUBLE step, DOUBLE defaultValue) {
	this->_slider.Minimum(minVal);
	this->_slider.Maximum(maxVal);
	this->_slider.Value(defaultValue);
	this->_slider.StepFrequency(step);

	//if (useVerticalMode) {
	//	this->_slider.Orientation(winrt::Windows::UI::Xaml::Controls::Orientation::Vertical);
	//}

	this->_id = id;
}

CModernSlidebar::~CModernSlidebar() {

}

void CModernSlidebar::SetTemplate() {
	hstring str(xml);
	this->ins = XamlReader::Load(str);
	if (!this->ins) {
		return;
	}

	this->_slider.ValueChanged([this](const winrt::Windows::Foundation::IInspectable& sender, const RoutedEventArgs& args)
		{
			this->CallCB();
		});

	Windows::UI::Xaml::Controls::StackPanel panel = this->ins.as<Windows::UI::Xaml::Controls::StackPanel>();

	panel.Children().InsertAt(0, this->_slider);

	return;
}

void CModernSlidebar::SetValueChangedCallback(_TEasyWinModernCtrl_SlidebarCallback callbackFunc, PVOID userData) {
	this->_callbackFunc = callbackFunc;
	this->_userData = userData;
}

void CModernSlidebar::CallCB() {
	if (this->_callbackFunc) {
		DOUBLE currentVal = this->_slider.Value();
		this->_callbackFunc(this->_id, currentVal, this->_userData);
	}
}

DOUBLE CModernSlidebar::GetValue() {
	return this->_slider.Value();
}