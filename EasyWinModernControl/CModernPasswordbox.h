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

		LPCWSTR xml = LR"(
<StackPanel xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
</StackPanel>
)";
	};
}

