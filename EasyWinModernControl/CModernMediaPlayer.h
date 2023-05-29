#pragma once
#include "CModernControl.h"

namespace EasyWinModernControl {
	class CModernMediaPlayer : public CModernControl
	{
	public:
		CModernMediaPlayer();
		~CModernMediaPlayer();

		void SetUriSource(LPCWSTR uri);
		void SetStreamSource(winrt::Windows::Storage::Streams::IRandomAccessStream stream);


	protected:
		void SetTemplate();
		void OnAdjustLayout();

	private:
		Windows::UI::Xaml::Controls::MediaPlayerElement _playerElement;
		Windows::Media::Playback::MediaPlayer _player;

		static LPCWSTR xml;
	};
}

