using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace EasyWinModernControlWinForm
{
    class NativeWrapper
    {
        private static IntPtr hModule = IntPtr.Zero;

        [DllImport("kernel32.dll")]
        private static extern IntPtr LoadLibrary(string dllToLoad);

        public const int WM_SHOWWINDOW = 0x0018;
        public const int WM_CLOSEWINDOW = 0x0010;
        public const int WM_SIZE = 0x0005;

        static NativeWrapper()
        {
            var myPath = new Uri(typeof(NativeWrapper).Assembly.CodeBase).LocalPath;
            var myFolder = Path.GetDirectoryName(myPath);

            var is64 = IntPtr.Size == 8;
            var subfolder = is64 ? "\\x64\\" : "\\x86\\";

            string dllPath = myFolder + subfolder + "EasyWinModernControl.dll";

            hModule = LoadLibrary(dllPath);
        }

        [DllImport("EasyWinModernControl.dll",CallingConvention = CallingConvention.Cdecl)]
        public static extern bool EasyWinModernCtrl_IsSystemSupport();

        [DllImport("EasyWinModernControl.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void EasyWinModernCtrl_InitializeApartment(bool useMTA);

        [DllImport("EasyWinModernControl.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void EasyWinModernCtrl_UnInitialize();

        [DllImport("EasyWinModernControl.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void EasyWinModernCtrl_ShowControl(IntPtr pItemInfo,IntPtr parentHwnd);

        public static void ShowControl(IntPtr pItemInfo,IntPtr parentHwnd)
        {
            if (hModule == IntPtr.Zero)
            {
                return;
            }
            EasyWinModernCtrl_ShowControl(pItemInfo, parentHwnd);
        }

        [DllImport("EasyWinModernControl.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void EasyWinModernCtrl_CloseControl(IntPtr pItemInfo);
        public static void CloseControl(IntPtr pItemInfo)
        {
            if (hModule == IntPtr.Zero)
            {
                return;
            }
            EasyWinModernCtrl_CloseControl(pItemInfo);
        }

        [DllImport("EasyWinModernControl.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void EasyWinModernCtrl_CleanupControl(IntPtr pItemInfo);
        public static void CleanupControl(IntPtr pItemInfo)
        {
            if (hModule == IntPtr.Zero)
            {
                return;
            }
            EasyWinModernCtrl_CleanupControl(pItemInfo);
        }

        //Textbox
        [DllImport("EasyWinModernControl.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr EasyWinModernCtrl_CreateTextbox([MarshalAs(UnmanagedType.LPWStr)] string controlName, [MarshalAs(UnmanagedType.LPWStr)] string headerTitle, [MarshalAs(UnmanagedType.LPWStr)] string textPlaceholder, bool enableMultiLine, bool enableUserChangeLine, int maxTextLength);

        public static IntPtr CreateTextbox(string controlName, string headerTitle, string textPlaceholder, bool enableMultiLine, bool enableUserChangeLine, int maxTextLength)
        {
            if (hModule == IntPtr.Zero)
            {
                return IntPtr.Zero;
            }
            return EasyWinModernCtrl_CreateTextbox(controlName, headerTitle, textPlaceholder, enableMultiLine, enableUserChangeLine, maxTextLength);
        }

        [DllImport("EasyWinModernControl.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr EasyWinModernCtrl_TextboxGetText(IntPtr pItemInfo);

        public static string GetTextboxText(IntPtr pItemInfo)
        {
            if (hModule == IntPtr.Zero)
            {
                return "";
            }
            IntPtr pStr = EasyWinModernCtrl_TextboxGetText(pItemInfo);
            if(pStr != IntPtr.Zero)
            {
                return Marshal.PtrToStringUni(pStr);
            }
            return "";
        }

        [DllImport("EasyWinModernControl.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void EasyWinModernCtrl_AdjustLayout(IntPtr pItemInfo);

        public static void AdjustLayout(IntPtr pItemInfo)
        {
            if (hModule == IntPtr.Zero)
            {
                return;
            }
            EasyWinModernCtrl_AdjustLayout(pItemInfo);
        }
    }
}
