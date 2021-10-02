#pragma once
#include "CModernControl.h"

namespace EasyWinModernControl {

	typedef BOOL(__stdcall* _TEasyWinModernCtrl_SwitchCallback)(BOOL status, PVOID userData);

	class CModernSwitch : public CModernControl
	{
	public:
		CModernSwitch(LPCWSTR controlName, LPCWSTR headerTitle, LPCWSTR onContent,LPCWSTR offContent,BOOL defaultValue);
		~CModernSwitch();

		void SetValueChangedCallback(_TEasyWinModernCtrl_SwitchCallback callbackFunc, PVOID userData);
		void SetEnableControl(BOOL enable);
		void SetStatus(BOOL status);

		void CallCB();

		BOOL GetStatus();

	protected:
		void SetTemplate();
		void OnAdjustLayout();

	private:
		Windows::UI::Xaml::Controls::ToggleSwitch _switch;

		_TEasyWinModernCtrl_SwitchCallback _cb = NULL;
		PVOID _userData = NULL;

		static LPCWSTR xml;
	};
}
