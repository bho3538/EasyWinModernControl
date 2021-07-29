#pragma once
#include "CModernControl.h"

namespace EasyWinModernControl {

	typedef BOOL(__stdcall* _TEasyWinModernCtrl_HyperLinkCallback)(PVOID userData);

	class CModernHyperlink : public CModernControl
	{
	public:
		CModernHyperlink(LPCWSTR controlName, LPCWSTR textLabel);
		~CModernHyperlink();

		void SetNavigateUri(LPCWSTR uri);
		void SetCustomClickCallback(_TEasyWinModernCtrl_HyperLinkCallback cb, PVOID userData);
		void SetEnableControl(BOOL enable);

		void CallCB();

	protected:
		void SetTemplate();
		void OnAdjustLayout();

	private:
		Windows::UI::Xaml::Controls::HyperlinkButton _hyperLink;

		_TEasyWinModernCtrl_HyperLinkCallback _cb = NULL;
		PVOID _userData = NULL;

		static LPCWSTR xml;
	};
}
