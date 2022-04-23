using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace EasyWinModernControlWinForm
{
    public class CModernControl
    {
        public void Initialize(bool useMTA)
        {
            NativeWrapper.EasyWinModernCtrl_InitializeApartment(useMTA);
        }
    }
}
