#pragma once

using namespace winrt;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Hosting;
using namespace winrt::Windows::UI::Xaml::Markup;

namespace EasyWinModernControl {
	class CModernControl
	{
	public:
		static HRESULT Initialize(BOOL useMTA, BOOL useWinUI);
		static void UnInitialize();
		static BOOL IsSupportSystem();

		CModernControl();
		~CModernControl();

		// 0 : system default
		// 1 : Light
		// 2 : Dark
		void SetTheme(DWORD dwFlags);
		HRESULT Show(HWND hwnd);
		void AdjustLayout();
		void Close();
		void Hide(BOOL reShow);
		HWND GetRawControlHwnd();
		HWND GetParentHwnd();

	protected:

		virtual void SetTemplate();
		virtual void OnAdjustLayout();


		DesktopWindowXamlSource xs;

		winrt::Windows::Foundation::IInspectable ins = NULL;

		winrt::Windows::UI::Xaml::ElementTheme _theme = winrt::Windows::UI::Xaml::ElementTheme::Default;

		HWND _parentHwnd = NULL;
		HWND _uwpHwnd = NULL;
		DOUBLE _height = 0;
		DOUBLE _width = 0;
	};
}
