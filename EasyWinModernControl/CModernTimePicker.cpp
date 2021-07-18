#include "stdafx.h"
#include "CModernTimePicker.h"

using namespace EasyWinModernControl;

CModernTimePicker::CModernTimePicker(LPCWSTR headerText, BOOL use24Hours) {
	this->_picker.Header(winrt::box_value(headerText));
	this->_use24Hours = use24Hours;
}

CModernTimePicker::~CModernTimePicker() {

}

void CModernTimePicker::SetTemplate() {
	hstring str(xml);
	this->ins = XamlReader::Load(str);
	if (!this->ins) {
		return;
	}

	if (this->_use24Hours) {
		this->_picker.ClockIdentifier(L"24HourClock");
	}


	//this->_picker.TimeChanged([this](const winrt::Windows::Foundation::IInspectable& sender, const Windows::UI::Xaml::Controls::TimePickerValueChangedEventArgs& args)
	//	{
	//		this->CallCB();
	//	});

	this->_picker.SelectedTimeChanged([this](const winrt::Windows::Foundation::IInspectable& sender, const Windows::UI::Xaml::Controls::TimePickerSelectedValueChangedEventArgs& args)
		{
			this->CallCB();
		});

	Windows::UI::Xaml::Controls::StackPanel panel = this->ins.as<Windows::UI::Xaml::Controls::StackPanel>();

	panel.Children().InsertAt(0, this->_picker);

	return;
}

void CModernTimePicker::CallCB() {
	if (this->_callbackFunc) {
		this->_callbackFunc(this->GetSelectedTimeAsSeconds(), this->_userData);
	}
}

INT64 CModernTimePicker::GetSelectedTimeAsSeconds() {
	auto selTime = this->_picker.SelectedTime();
	if (!selTime) {
		return 0;
	}

	INT64 aa = selTime.GetTimeSpan().count();
	if (aa > 0) {
		std::chrono::nanoseconds ns(aa * 100);
		std::chrono::seconds s = std::chrono::duration_cast<std::chrono::seconds> (ns);
		aa = s.count();
	}

	return aa;
}

void CModernTimePicker::SetTimeUsingSeconds(INT64 seconds) {
	if (seconds < 0) return;

	std::chrono::seconds s(seconds);
	std::chrono::nanoseconds ns = std::chrono::duration_cast<std::chrono::nanoseconds>(s);

	Windows::Foundation::TimeSpan timeSpan((INT64)ns.count() / 100);

	this->_picker.SelectedTime(timeSpan);

}

void CModernTimePicker::SetTimeCallback(_TEasyWinModernCtrl_TimePickerCallback callbackFunc, PVOID userData) {
	this->_callbackFunc = callbackFunc;
	this->_userData = userData;
}