using System;
using System.Drawing;
using System.Collections;
using System.Windows.Forms;

namespace AlistWinForm
{
    class MyForm : MyContainerControl
    {
        public MyForm()
        {
            InitializeComponent();
        }

        public override void Show(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;

            /*
             * Draw boundary of form.
             */
            Pen p = new Pen(Color.Black, 1);
            g.DrawRectangle(p, this.Location.X, this.Location.Y,
                            this.Size.Width, this.Size.Height);

            /*
             * Draw title bar.
             */
            SolidBrush b1 = new SolidBrush(Color.FromArgb(67, 67, 67));
            g.FillRectangle(b1, this.Location.X, this.Location.Y,
                            this.TitleBarSize.Width,
                            this.TitleBarSize.Height);
            /*
             * Draw text of title bar.
             */
            Font font = new Font("Sans", 10, FontStyle.Bold);
            SolidBrush b2 = new SolidBrush(Color.White);
            StringFormat fmt = new StringFormat();
            fmt.Alignment = StringAlignment.Center;
            g.DrawString(this.Text, font, b2,
                         this.Location.X + this.Size.Width / 2,
                         this.Location.Y + 1, fmt);
            /*
             * Draw button of title bar.
             */

            /*
             * Draw all controls are contained by this form.
             */
            foreach (MyControl c in this.Controls)
            {
                c.Show(sender, e);
            }
        }

        public bool IsInTitleBar(MouseEventArgs e)
        {
            int x = this.Location.X;
            int y = this.Location.Y;

            if (e.X >= x && e.X <= x + this.Size.Width &&
                e.Y >= y && e.Y <= y + this.TitleBarSize.Height)
                return true;
            else
                return false;
        } 

        private void InitializeComponent()
        {
            int form_width = 200;
            int form_height = 200;
            int titlebar_width = form_width;
            int titlebar_height = 20;

            this.Text = "My Form";
            this.Size = new Size(form_width, form_height);
            this.Location = new Point(10, 10);
            this.TitleBarSize = new Size(titlebar_width, titlebar_height);
            this.Parent = null;
            this.Controls = new ArrayList();
        }

        private Size TitleBarSize;
    }
}
