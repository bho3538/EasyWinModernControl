using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows.Forms;

namespace EasyWinModernControlWinForm
{
    public partial class CModernTextbox : UserControl
    {
        private IntPtr pItemInfo = IntPtr.Zero;

        public CModernTextbox()
        {
            InitializeComponent();
        }

        public string Title { get; set; }

        public override string Text
        {
            get
            {
                return NativeWrapper.GetTextboxText(this.pItemInfo);
            }
            set
            {

            }
        }

        protected override void WndProc(ref Message m)
        {
            switch (m.Msg)
            {
                case NativeWrapper.WM_SHOWWINDOW:
                    {
                        pItemInfo = NativeWrapper.CreateTextbox(this.Name, "Title Text", "placeholder text", true, true, 0);
                        NativeWrapper.ShowControl(pItemInfo, this.Handle);
                        NativeWrapper.AdjustLayout(pItemInfo);
                    }; break;
                case NativeWrapper.WM_CLOSEWINDOW:
                    {
                        NativeWrapper.CloseControl(pItemInfo);
                        NativeWrapper.CleanupControl(pItemInfo);
                        pItemInfo = IntPtr.Zero;
                    }; break;
                case NativeWrapper.WM_SIZE:
                    {
                        NativeWrapper.AdjustLayout(pItemInfo);
                    }; break;
            }

            base.WndProc(ref m);
        }

    }
}
