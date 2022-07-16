#pragma once

#include <Windows.h>
#include <commctrl.h>

#pragma comment(lib,"Comctl32.lib")

#if _WIN64
#pragma comment(lib,"..\\x64\\Debug\\EasyWinModernControl.lib")
#else
#pragma comment(lib,"..\\Release\\EasyWinModernControl.lib")
#endif