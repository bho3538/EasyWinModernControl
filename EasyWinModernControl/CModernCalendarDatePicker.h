#pragma once
#include "CModernControl.h"

namespace EasyWinModernControl {

	class CModernCalendarDatePicker : CModernControl
	{
	public:
		CModernCalendarDatePicker(LPCWSTR controlName, LPCWSTR headerText);
		~CModernCalendarDatePicker();

		BOOL GetSelectedDate(PFILETIME pSelectedTime);
		void SetDate(FILETIME date);
		void SetMinDate(FILETIME date);
		void SetMaxDate(FILETIME date);


	protected:
		void SetTemplate();
		void OnAdjustLayout();

	private:
		Windows::UI::Xaml::Controls::CalendarDatePicker _datePicker;

		static LPCWSTR xml;
	};
}
