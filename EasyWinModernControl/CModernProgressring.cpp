#include "stdafx.h"
#include "CModernProgressring.h"

using namespace EasyWinModernControl;

CModernProgressring::CModernProgressring() {

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