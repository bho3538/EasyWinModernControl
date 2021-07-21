#pragma once
#include "CModernControl.h"

namespace EasyWinModernControl {

	class CModernPasswordbox : public CModernControl
	{
	public:
		CModernPasswordbox(LPCWSTR controlName, LPCWSTR headerTitle, LPCWSTR textPlaceholder,DWORD maxLength);
		~CModernPasswordbox();

		LPCWSTR GetPassword();
		void SetEnableControl(BOOL enable);

	protected:
		void SetTemplate();
		void OnAdjustLayout();

	private:
		Windows::UI::Xaml::Controls::PasswordBox _pwdbox;

		static LPCWSTR xml;
	};
}

