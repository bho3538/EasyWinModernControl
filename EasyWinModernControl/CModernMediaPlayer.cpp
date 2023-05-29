#include "stdafx.h"
#include "CModernMediaPlayer.h"

using namespace EasyWinModernControl;

LPCWSTR CModernMediaPlayer::xml = LR"(
<StackPanel xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
</StackPanel>)";

CModernMediaPlayer::CModernMediaPlayer() {
	this->_playerElement.SetMediaPlayer(this->_player);
	this->_playerElement.AreTransportControlsEnabled(true);
}

CModernMediaPlayer::~CModernMediaPlayer() {
	this->_player.Pause();
	this->_player.Close();
}

void CModernMediaPlayer::SetUriSource(LPCWSTR uriw) {
	if (!uriw || wcslen(uriw) == 0) {
		return;
	}

	Windows::Foundation::Uri uri(uriw);
	this->_player.SetUriSource(uri);
}

void CModernMediaPlayer::SetStreamSource(winrt::Windows::Storage::Streams::IRandomAccessStream randomStream) {
	if (!randomStream) {
		return;
	}

	this->_player.SetStreamSource(randomStream);
}

void CModernMediaPlayer::SetTemplate() {
	hstring str(xml);
	this->ins = XamlReader::Load(str);
	if (!this->ins) {
		return;
	}

	Windows::UI::Xaml::Controls::StackPanel panel = this->ins.as<Windows::UI::Xaml::Controls::StackPanel>();

	panel.Children().InsertAt(0, this->_playerElement);
}

void CModernMediaPlayer::OnAdjustLayout() {
	this->_playerElement.Height(_height - 30);
	this->_playerElement.Width(_width - 20);
}