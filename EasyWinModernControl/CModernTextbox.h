#pragma once
#include "CModernControl.h"

namespace EasyWinModernControl {
	class CModernTextbox : public CModernControl
	{
		public:
			CModernTextbox(LPCWSTR controlName,LPCWSTR headerTitle,LPCWSTR textPlaceholder, BOOL enableMultiLine, BOOL enableUserChangeLine);
			~CModernTextbox();

			LPCWSTR GetText();
			void SetText(LPCWSTR text);
			void SetReadonlyMode(BOOL enable);


		protected:
			void SetTemplate();
			void OnAdjustLayout();

		private:
			Windows::UI::Xaml::Controls::TextBox _textbox;

			//hstring _controlName;
			//hstring _headerTitle;
			//hstring _textPlaceholder;
			//BOOL _enableMultiLine;
			//BOOL _enableUserChangeLine;

			LPCWSTR xml = LR"(
<StackPanel xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
</StackPanel>
)";
			BOOL _useAltControl = FALSE;
	};
}
