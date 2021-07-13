#pragma once

using namespace winrt;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Hosting;
using namespace winrt::Windows::UI::Xaml::Markup;

namespace EasyWinModernControl {
	class CModernControl
	{
	public:
		static HRESULT Initialize();

		CModernControl();
		~CModernControl();

		HRESULT Show(HWND hwnd);
		void AdjustLayout();

	protected:

		virtual void SetTemplate();
		virtual void OnAdjustLayout();


		DesktopWindowXamlSource xs;
		winrt::Windows::Foundation::IInspectable ins = NULL;

		HWND _parentHwnd = NULL;
		HWND _uwpHwnd = NULL;
		DOUBLE _height = 0;
	};
}
