#pragma once

#include "CModernControl.h"

namespace EasyWinModernControl {

	typedef BOOL(__stdcall* _TEasyWinModernCtrl_TimePickerCallback)(INT64 seconds, PVOID userData);

	class CModernTimePicker : public CModernControl
	{
	public:
		CModernTimePicker(LPCWSTR controlName,LPCWSTR headerText, BOOL use24Hours);
		~CModernTimePicker();

		INT64 GetSelectedTimeAsSeconds();
		void SetTimeUsingSeconds(INT64 seconds);
		void SetTimeCallback(_TEasyWinModernCtrl_TimePickerCallback callbackFunc, PVOID userData);
		void SetEnableControl(BOOL enable);

		//internal use
		void CallCB();
		
	protected:
		void SetTemplate();
		void OnAdjustLayout();

	private:
		Windows::UI::Xaml::Controls::TimePicker _picker;

		BOOL _use24Hours = FALSE;

		_TEasyWinModernCtrl_TimePickerCallback _callbackFunc = NULL;
		PVOID _userData = NULL;

		LPCWSTR xml = LR"(
<StackPanel xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
</StackPanel>
)";
	};
}

