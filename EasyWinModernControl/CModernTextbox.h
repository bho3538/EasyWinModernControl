#pragma once
#include "CModernControl.h"

namespace EasyWinModernControl {
	class CModernTextbox : public CModernControl
	{
		public:
			CModernTextbox(LPCWSTR controlName,LPCWSTR headerTitle,LPCWSTR textPlaceholder, BOOL enableMultiLine, BOOL enableUserChangeLine, DWORD maxTextLength);
			~CModernTextbox();

			LPCWSTR GetText();
			void SetText(LPCWSTR text);
			void SetText(LPCWSTR text,DWORD size);
			void SetReadonlyMode(BOOL enable);
			void SetEnableControl(BOOL enable);
			void SetSpellCheck(BOOL enable);

		protected:
			void SetTemplate();
			void OnAdjustLayout();

		private:
			Windows::UI::Xaml::Controls::TextBox _textbox;

			static LPCWSTR xml;
	};
}
