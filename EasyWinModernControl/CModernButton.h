#pragma once
#include "CModernControl.h"

namespace EasyWinModernControl {

	typedef BOOL(__stdcall* _TEasyWinModernCtrl_BtnCallback)(DWORD id, PVOID userData);

	class CModernButton : public CModernControl
	{
	public:
		CModernButton(LPCWSTR controlName, DWORD id, LPCWSTR buttonLabel);
		~CModernButton();

		void SetClickCallback(_TEasyWinModernCtrl_BtnCallback callbackFunc, PVOID userData);

		void SetUseAccentColor(BOOL enable);
		void SetEnableControl(BOOL enable);

		//internal use
		void CallCB();


	protected:
		void SetTemplate();
		void OnAdjustLayout();

	private:
		Windows::UI::Xaml::Controls::Button _btn;
		Windows::UI::Xaml::Controls::RadioButton _radio;


		DWORD _id;
		_TEasyWinModernCtrl_BtnCallback _callbackFunc = NULL;
		PVOID _userData = NULL;

		BOOL _useAccentColor = FALSE;

		//static void _InternalClicked(const winrt::Windows::Foundation::IInspectable& sender, const RoutedEventArgs& args);

		static LPCWSTR xml;
	};
}
