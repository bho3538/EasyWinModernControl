#pragma once
#include "CModernControl.h"

namespace EasyWinModernControl {

	class CModernProgressring : public CModernControl
	{
	public:
		CModernProgressring(LPCWSTR controlName);
		~CModernProgressring();

	protected:
		void SetTemplate();
		void OnAdjustLayout();

	private:
		Windows::UI::Xaml::Controls::ProgressRing _ring;

		static LPCWSTR xml;
	};

}

