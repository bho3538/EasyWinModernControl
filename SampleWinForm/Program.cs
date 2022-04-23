using EasyWinModernControlWinForm;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace SampleWinForm
{
    static class Program
    {
        /// <summary>
        /// 해당 애플리케이션의 주 진입점입니다.
        /// </summary>
        [STAThread]
        static void Main()
        {
            CModernControl c = new CModernControl();
            c.Initialize(false);
            Console.WriteLine("");
            

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
