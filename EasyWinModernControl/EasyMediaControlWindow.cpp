#include "stdafx.h"
#include "EasyMediaControlWindow.h"

LRESULT __stdcall _MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
		case WM_CREATE: {
			if (lParam) {
				LPCREATESTRUCT pData = (LPCREATESTRUCT)lParam;

				EasyWinModernCtrl_ShowControl(pData->lpCreateParams, hwnd);
				SetWindowLongPtrW(hwnd, GWLP_USERDATA, (LONG_PTR)pData->lpCreateParams);
			}

		}; break;
		case WM_SIZE: {
			PEASYMODERNMEDIAPLAYER player = (PEASYMODERNMEDIAPLAYER)GetWindowLongPtrW(hwnd, GWLP_USERDATA);
			if (player) {
				EasyWinModernCtrl_AdjustLayout(player);
			}
		}; break;
		case WM_CLOSE: {
			PEASYMODERNMEDIAPLAYER player = (PEASYMODERNMEDIAPLAYER)GetWindowLongPtrW(hwnd, GWLP_USERDATA);
			if (player) {
				EasyWinModernCtrl_CloseControl(player);
				EasyWinModernCtrl_CleanupControl(player);
				SetWindowLongPtrW(hwnd, GWLP_USERDATA, (LONG_PTR)0);
				DestroyWindow(hwnd);
			}
		}; break;
		case WM_DESTROY: {
			return 0;
		}; break;
	}

	return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}


__declspec(dllexport) void __cdecl _ShowMediaWindow(PEASYMODERNMEDIAPLAYER player) {
	WNDCLASSEX wClass = { 0 };
	wClass.cbSize = sizeof(wClass);
	wClass.style = 0;
	wClass.lpfnWndProc = (WNDPROC)_MainWindowProc;
	wClass.hIcon = 0;
	wClass.lpszClassName = L"EZMODERNCTRLMEDIA";
	wClass.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
	RegisterClassEx(&wClass);

	HWND MainWindow = CreateWindowExW(0,
		L"EZMODERNCTRLMEDIA",
		L"aa",
		WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS |
		WS_CLIPCHILDREN, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		0, 0, NULL, player);

	if(MainWindow) {
		ShowWindow(MainWindow, SW_SHOW);
		UpdateWindow(MainWindow);
	}

}