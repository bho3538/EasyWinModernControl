#pragma once
#include "CModernControl.h"

namespace EasyWinModernControl {

	class CWinUIProgressRing : public CModernControl
	{
	public:
		CWinUIProgressRing(LPCWSTR controlName);
		~CWinUIProgressRing();

	protected:
		void SetTemplate();
		void OnAdjustLayout();

	private:
		Microsoft::UI::Xaml::Controls::ProgressRing _ring;

		static LPCWSTR xml;
	};

}