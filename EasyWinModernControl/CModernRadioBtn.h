#pragma once
#include "CModernControl.h"

namespace EasyWinModernControl {

	typedef BOOL(__stdcall* _TEasyWinModernCtrl_RadioBtnCallback)(LPCWSTR groupName, DWORD id, PVOID userData);

	class CModernRadioBtn : CModernControl
	{
	public:
		CModernRadioBtn(LPCWSTR groupName, LPCWSTR headerText, BOOL useVertical);
		~CModernRadioBtn();

		void InsertItem(DWORD idx, LPCWSTR text, BOOL defaultChecked, BOOL enabled);
		DWORD GetCheckedItem();
		void SetCheckedItem(DWORD idx);

		void SetValueChangedCallback(_TEasyWinModernCtrl_RadioBtnCallback callbackFunc, PVOID userData);
		//Internal use
		void CallCB();

	protected:
		void SetTemplate();
		void OnAdjustLayout();

	private:
		std::vector<Windows::UI::Xaml::Controls::RadioButton> _radioBtns;
		Windows::UI::Xaml::Controls::TextBlock _header;

		hstring _groupName;

		BOOL _useHeader = FALSE;
		BOOL _useVertical = FALSE;

		static LPCWSTR xml;

		_TEasyWinModernCtrl_RadioBtnCallback _cb = NULL;
		PVOID _userData = NULL;
	};

}