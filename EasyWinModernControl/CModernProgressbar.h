#pragma once
#include "CModernControl.h"

namespace EasyWinModernControl {

	class CModernProgressbar : public CModernControl
	{
	public:
		CModernProgressbar(LPCWSTR controlName, DOUBLE minVal, DOUBLE maxVal);
		~CModernProgressbar();

		void SetValue(BOOL isIndeterminate, BOOL isPause, DOUBLE value);

	protected:
		void SetTemplate();
		void OnAdjustLayout();

	private:
		Windows::UI::Xaml::Controls::ProgressBar _progressbar;

		static LPCWSTR xml;
	};
}

