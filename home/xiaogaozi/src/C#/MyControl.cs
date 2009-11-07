using System;
using System.Drawing;
using System.Windows.Forms;

namespace AlistWinForm
{
    abstract class MyControl
    {
        public abstract void Show(object sender, PaintEventArgs e);

        public string Text;
        public Size Size;
        public Point Location;
        public MyControl Parent;
    }
}
