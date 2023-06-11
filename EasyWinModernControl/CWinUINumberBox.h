#pragma once
#include "CModernControl.h"

namespace EasyWinModernControl {

	class CWinUINumberBox : public CModernControl
	{
	public:
		CWinUINumberBox(LPCWSTR controlName, LPCWSTR headerTitle , LPCWSTR textPlaceholder);

		~CWinUINumberBox();

		void SetButtonType(DWORD mode);

		void SetValue(DOUBLE value);

		void SetMinValue(DOUBLE val);

		void SetMaxValue(DOUBLE val);

		void SetChangeStep(DOUBLE step);

		DOUBLE GetValue();

	protected:
		void SetTemplate();
		void OnAdjustLayout();

	private:
		Microsoft::UI::Xaml::Controls::NumberBox _numBox;
		
		static LPCWSTR xml;
	};
}

