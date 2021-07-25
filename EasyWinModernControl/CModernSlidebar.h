#pragma once

#include "CModernControl.h"

namespace EasyWinModernControl {

	typedef BOOL(__stdcall* _TEasyWinModernCtrl_SlidebarCallback)(DWORD id, DOUBLE currentValue, PVOID userData);

	class CModernSlidebar : public CModernControl
	{
	public:
		CModernSlidebar(LPCWSTR controlName, DWORD id, DOUBLE minVal, DOUBLE maxVal, DOUBLE step, DOUBLE defaultValue);
		~CModernSlidebar();

		DOUBLE GetValue();
		void SetValueChangedCallback(_TEasyWinModernCtrl_SlidebarCallback callbackFunc, PVOID userData);
		void SetEnableControl(BOOL enable);

		//internal use
		void CallCB();

	protected:
		void SetTemplate();
		void OnAdjustLayout();

	private:
		Windows::UI::Xaml::Controls::Slider _slider;
		
		DWORD _id = 0;
		_TEasyWinModernCtrl_SlidebarCallback _callbackFunc = NULL;
		PVOID _userData = NULL;

		static LPCWSTR xml;
	};
}
