#include "stdafx.h"
#include "CModernRadioBtn.h"

using namespace EasyWinModernControl;

LPCWSTR CModernRadioBtn::xml = LR"(
<StackPanel xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
    <ScrollViewer HorizontalScrollBarVisibility = "Auto" VerticalScrollBarVisibility="Auto">
          <StackPanel></StackPanel>
    </ScrollViewer>
</StackPanel>)";


CModernRadioBtn::CModernRadioBtn(LPCWSTR groupName, LPCWSTR headerText , BOOL useVertical) {
    if (headerText) {
        this->_header.Text(headerText);
        _useHeader = TRUE;
    }

    this->_useVertical = useVertical;
    _groupName = groupName;
}

CModernRadioBtn::~CModernRadioBtn() {

}

void CModernRadioBtn::InsertItem(DWORD idx, LPCWSTR text, BOOL defaultChecked, BOOL enabled) {
    Windows::UI::Xaml::Controls::RadioButton _item;

    _item.GroupName(this->_groupName);
    _item.Content(winrt::box_value(text));

    if (defaultChecked) {
        _item.IsChecked(TRUE);
    }

    _item.IsEnabled(enabled);

    _item.Checked([this](const winrt::Windows::Foundation::IInspectable& sender, const RoutedEventArgs& args)
        {
            this->CallCB();
        });

    this->_radioBtns.push_back(_item);
}

DWORD CModernRadioBtn::GetCheckedItem() {
    int cnt = this->_radioBtns.size();

    for (int i = 0; i < cnt; i++) {
        bool re = this->_radioBtns[i].IsChecked().as<bool>();
        if (re) {
            return i;
        }
    }

    return MAXDWORD;
}

void CModernRadioBtn::SetCheckedItem(DWORD idx) {
    int cnt = this->_radioBtns.size();

    if (idx >= cnt) {
        return;
    }

    this->_radioBtns[idx].IsChecked(TRUE);
}

void CModernRadioBtn::SetTemplate() {
    hstring str(xml);
    this->ins = XamlReader::Load(str);
    if (!this->ins) {
        return;
    }

    Windows::UI::Xaml::Controls::StackPanel panel = this->ins.as<Windows::UI::Xaml::Controls::StackPanel>();
    if (_useHeader) {
        panel.Children().InsertAt(0, _header);
    }

    int cnt = this->_radioBtns.size();

    Windows::UI::Xaml::Controls::StackPanel itemPanel = panel.Children().GetAt(_useHeader).as<Windows::UI::Xaml::Controls::ScrollViewer>().Content().as< Windows::UI::Xaml::Controls::StackPanel>();

    if (!this->_useVertical) {
        itemPanel.Orientation(winrt::Windows::UI::Xaml::Controls::Orientation::Horizontal);
    }
    for (int i = 0; i < cnt; i++) {
        itemPanel.Children().InsertAt(i, this->_radioBtns[i]);
    }

}

void CModernRadioBtn::OnAdjustLayout() {
    if (this->ins) {
        Windows::UI::Xaml::Controls::StackPanel panel = this->ins.as<Windows::UI::Xaml::Controls::StackPanel>();
        
        Windows::UI::Xaml::Controls::ScrollViewer scrollViewer = panel.Children().GetAt(_useHeader).as<Windows::UI::Xaml::Controls::ScrollViewer>();

        DOUBLE scrollHeight = this->_height;

        if (_useHeader) {
            scrollHeight -= 20;
        }

        scrollViewer.Height(scrollHeight);
    }
}

void CModernRadioBtn::SetValueChangedCallback(_TEasyWinModernCtrl_RadioBtnCallback callbackFunc, PVOID userData) {
    this->_cb = callbackFunc;
    this->_userData = userData;
}
//Internal use
void CModernRadioBtn::CallCB() {
    if (this->_cb) {
        DWORD checkedIdx = this->GetCheckedItem();
        this->_cb(this->_groupName.c_str(),checkedIdx, this->_userData);
    }
}