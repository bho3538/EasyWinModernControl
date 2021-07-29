#include "stdafx.h"
#include "CModernProgressbar.h"

using namespace EasyWinModernControl;

LPCWSTR CModernProgressbar::xml = LR"(
<StackPanel xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
</StackPanel>)";

CModernProgressbar::CModernProgressbar(LPCWSTR controlName, DOUBLE minVal, DOUBLE maxVal) {
	if (controlName) {
		this->_progressbar.Name(controlName);
	}

	this->_progressbar.Minimum(minVal);
	this->_progressbar.Maximum(maxVal);
}

CModernProgressbar::~CModernProgressbar() {

}

void CModernProgressbar::SetValue(BOOL isIndeterminate, BOOL isPause, DOUBLE value) {
	this->_progressbar.IsIndeterminate(isIndeterminate);

	if (!isIndeterminate) {
		this->_progressbar.Value(value);
	}

	this->_progressbar.ShowPaused(isPause);
}

void CModernProgressbar::SetTemplate() {
	hstring str(xml);
	this->ins = XamlReader::Load(str);
	if (!this->ins) {
		return;
	}

	Windows::UI::Xaml::Controls::StackPanel panel = this->ins.as<Windows::UI::Xaml::Controls::StackPanel>();

	panel.Children().InsertAt(0, this->_progressbar);

}

void CModernProgressbar::OnAdjustLayout() {
	this->_progressbar.Height(_height);
	this->_progressbar.Width(_width);
}