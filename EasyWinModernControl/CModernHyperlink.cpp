#include "stdafx.h"
#include "CModernHyperlink.h"

using namespace EasyWinModernControl;

LPCWSTR CModernHyperlink::xml = LR"(
<StackPanel xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
</StackPanel>)";

CModernHyperlink::CModernHyperlink(LPCWSTR controlName, LPCWSTR textLabel) {
	if (controlName) {
		this->_hyperLink.Name(controlName);
	}

	if (textLabel) {
		this->_hyperLink.Content(winrt::box_value(textLabel));
	}
}

CModernHyperlink::~CModernHyperlink() {

}

void CModernHyperlink::SetNavigateUri(LPCWSTR uri) {
	if (uri) {
		winrt::Windows::Foundation::Uri _uri(uri);
		this->_hyperLink.NavigateUri(_uri);
	}
	this->_cb = NULL;
}

void CModernHyperlink::SetCustomClickCallback(_TEasyWinModernCtrl_HyperLinkCallback cb, PVOID userData) {
	this->_cb = cb;
	this->_userData = userData;

	this->_hyperLink.NavigateUri(NULL);

	this->_hyperLink.Click([this](const winrt::Windows::Foundation::IInspectable& sender, const RoutedEventArgs& args)
		{
			this->CallCB();
		});
}

void CModernHyperlink::SetEnableControl(BOOL enable) {
	this->_hyperLink.IsEnabled(enable);
}

void CModernHyperlink::CallCB() {
	if (this->_cb) {
		this->_cb(this->_userData);
	}
}

void CModernHyperlink::SetTemplate() {
	hstring str(xml);
	this->ins = XamlReader::Load(str);
	if (!this->ins) {
		return;
	}

	Windows::UI::Xaml::Controls::StackPanel panel = this->ins.as<Windows::UI::Xaml::Controls::StackPanel>();

	panel.Children().InsertAt(0, this->_hyperLink);

}

void CModernHyperlink::OnAdjustLayout() {
	this->_hyperLink.Height(_height);
	this->_hyperLink.Width(_width);
}
