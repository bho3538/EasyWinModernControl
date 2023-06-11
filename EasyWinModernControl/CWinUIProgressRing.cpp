#include "stdafx.h"
#include "CWinUIProgressRing.h"

using namespace EasyWinModernControl;

LPCWSTR CWinUIProgressRing::xml = LR"(
<StackPanel xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
</StackPanel>)";

CWinUIProgressRing::CWinUIProgressRing(LPCWSTR controlName) {
	if (controlName) {
		this->_ring.Name(controlName);
	}
}
CWinUIProgressRing::~CWinUIProgressRing() {

}

void CWinUIProgressRing::SetTemplate() {
	hstring str(xml);
	this->ins = XamlReader::Load(str);
	if (!this->ins) {
		return;
	}

	this->_ring.IsActive(true);

	Windows::UI::Xaml::Controls::StackPanel panel = this->ins.as<Windows::UI::Xaml::Controls::StackPanel>();

	panel.Children().InsertAt(0, this->_ring);

	return;
}

void CWinUIProgressRing::OnAdjustLayout() {
	this->_ring.Height(this->_height);
	this->_ring.Width(this->_width);
}