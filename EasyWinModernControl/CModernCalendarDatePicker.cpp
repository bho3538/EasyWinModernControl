#include "stdafx.h"
#include "CModernCalendarDatePicker.h"

#include <shlwapi.h>
#pragma comment(lib,"Shlwapi.lib")

using namespace EasyWinModernControl;

LPCWSTR CModernCalendarDatePicker::xml = LR"(
<StackPanel xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
</StackPanel>)";

typedef union _XFILETIME {
	FILETIME fileTime;
	UINT64 totalTime;
} XFILETIME,*PXFILETIME;

CModernCalendarDatePicker::CModernCalendarDatePicker(LPCWSTR controlName, LPCWSTR headerText) {
	if (controlName) {
		this->_datePicker.Name(controlName);
	}

	if (headerText) {
		this->_datePicker.Header(winrt::box_value(headerText));
	}
}

CModernCalendarDatePicker::~CModernCalendarDatePicker() {

}

BOOL CModernCalendarDatePicker::GetSelectedDate(PFILETIME pSelectedTime) {
	XFILETIME selectedDate;

	if (!pSelectedTime) {
		return FALSE;
	}

	auto date = _datePicker.Date();
	if (!date) {
		return FALSE;
	}

	selectedDate.totalTime = date.as<winrt::Windows::Foundation::DateTime>().time_since_epoch().count();

	pSelectedTime->dwLowDateTime = selectedDate.fileTime.dwLowDateTime;
	pSelectedTime->dwHighDateTime = selectedDate.fileTime.dwHighDateTime;

	return TRUE;
}

void CModernCalendarDatePicker::SetDate(FILETIME date) {
	XFILETIME selectedDate;

	selectedDate.fileTime = date;

	winrt::Windows::Foundation::TimeSpan a(selectedDate.totalTime);

	winrt::Windows::Foundation::DateTime time(a);

	_datePicker.Date(time);
}

void CModernCalendarDatePicker::SetMinDate(FILETIME date) {
	XFILETIME selectedDate;

	selectedDate.fileTime = date;

	winrt::Windows::Foundation::TimeSpan a(selectedDate.totalTime);

	winrt::Windows::Foundation::DateTime time(a);

	_datePicker.MinDate(time);
}

void CModernCalendarDatePicker::SetMaxDate(FILETIME date) {
	XFILETIME selectedDate;

	selectedDate.fileTime = date;

	winrt::Windows::Foundation::TimeSpan a(selectedDate.totalTime);

	winrt::Windows::Foundation::DateTime time(a);

	_datePicker.MaxDate(time);
}

void CModernCalendarDatePicker::SetTemplate() {
	hstring str(xml);
	this->ins = XamlReader::Load(str);
	if (!this->ins) {
		return;
	}

	Windows::UI::Xaml::Controls::StackPanel panel = this->ins.as<Windows::UI::Xaml::Controls::StackPanel>();

	panel.Children().InsertAt(0, this->_datePicker);

}
void CModernCalendarDatePicker::OnAdjustLayout() {
	this->_datePicker.Height(_height);
	this->_datePicker.Width(_width);
}