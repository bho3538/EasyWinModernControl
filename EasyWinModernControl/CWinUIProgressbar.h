#pragma once
#include "CModernControl.h"

namespace EasyWinModernControl {

	class CWinUIProgressbar : public CModernControl
	{
	public:
		CWinUIProgressbar(LPCWSTR controlName, DOUBLE minVal, DOUBLE maxVal);
		~CWinUIProgressbar();

		void SetValue(BOOL isIndeterminate, BOOL isPause, DOUBLE value);

	protected:
		void SetTemplate();
		void OnAdjustLayout();

	private:
		Microsoft::UI::Xaml::Controls::ProgressBar _progressbar;

		static LPCWSTR xml;
	};

}