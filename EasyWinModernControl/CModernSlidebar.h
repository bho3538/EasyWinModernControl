#pragma once

#include "CModernControl.h"

namespace EasyWinModernControl {

	typedef BOOL(__stdcall* _TEasyWinModernCtrl_SlidebarCallback)(DWORD id, DOUBLE currentValue, PVOID userData);

	class CModernSlidebar : public CModernControl
	{
	public:
		CModernSlidebar(LPCWSTR controlName, DWORD id, DOUBLE minVal, DOUBLE maxVal, DOUBLE step, DOUBLE defaultValue);
		~CModernSlidebar();

		void SetValueChangedCallback(_TEasyWinModernCtrl_SlidebarCallback callbackFunc, PVOID userData);
		//internal use
		void CallCB();

	protected:
		void SetTemplate();

	private:
		Windows::UI::Xaml::Controls::Slider _slider;
		
		DWORD _id = 0;
		_TEasyWinModernCtrl_SlidebarCallback _callbackFunc = NULL;
		PVOID _userData = NULL;

		LPCWSTR xml = LR"(
<StackPanel xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
</StackPanel>
)";
	};
}
