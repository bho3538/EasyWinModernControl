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

	private:
		Windows::UI::Xaml::Controls::ProgressRing _ring;

		LPCWSTR xml = LR"(
<StackPanel xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
</StackPanel>
)";

	};

}

