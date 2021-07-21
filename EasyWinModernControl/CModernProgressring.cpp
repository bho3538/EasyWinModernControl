#include "stdafx.h"
#include "CModernProgressring.h"

using namespace EasyWinModernControl;

LPCWSTR CModernProgressring::xml = LR"(
<StackPanel xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
</StackPanel>)";

CModernProgressring::CModernProgressring(LPCWSTR controlName) {
	if (controlName) {
		this->_ring.Name(controlName);
	}
}
CModernProgressring::~CModernProgressring() {

}

void CModernProgressring::SetTemplate() {
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

void CModernProgressring::OnAdjustLayout() {
	this->_ring.Height(this->_height);
	this->_ring.Width(this->_width);
}