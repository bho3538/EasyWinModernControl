#include "stdafx.h"
#include "CModernProgressring.h"

using namespace EasyWinModernControl;

CModernProgressring::CModernProgressring(LPCWSTR controlName) {

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