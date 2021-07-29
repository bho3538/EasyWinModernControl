#pragma once
#include "CModernControl.h"

namespace EasyWinModernControl {

	typedef BOOL(__stdcall* _TEasyWinModernCtrl_CalendarDatePickerCallback)(FILETIME selectedDate, PVOID userData);

	class CModernCalendarDatePicker : public CModernControl
	{
	public:
		CModernCalendarDatePicker(LPCWSTR controlName, LPCWSTR headerText);
		~CModernCalendarDatePicker();

		BOOL GetSelectedDate(PFILETIME pSelectedTime);
		void SetDate(FILETIME date);
		void SetMinDate(FILETIME date);
		void SetMaxDate(FILETIME date);
		void SetSelectedDateCallback(_TEasyWinModernCtrl_CalendarDatePickerCallback cb,PVOID userData);
		void SetEnableControl(BOOL enable);

		//internal use
		void CallCB();

	protected:
		void SetTemplate();
		void OnAdjustLayout();

	private:
		Windows::UI::Xaml::Controls::CalendarDatePicker _datePicker;

		_TEasyWinModernCtrl_CalendarDatePickerCallback _cb = NULL;
		PVOID _userData = NULL;

		static LPCWSTR xml;
	};
}
