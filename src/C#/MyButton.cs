using System;
using System.Drawing;
using System.Windows.Forms;

namespace AlistWinForm
{
    class MyButton : MyControl
    {
        public MyButton()
        {
            InitializeComponent();
        }

        public override void Show(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            
            /*
             * Draw button.
             */
            Pen p = new Pen(Color.Black, 2);
            g.DrawRectangle(p, this.Location.X, this.Location.Y,
                            this.Size.Width, this.Size.Height);

            /*
             * Draw text of button.
             */
            Font font = new Font("Sans", 10);
            SolidBrush b = new SolidBrush(Color.Black);
            StringFormat fmt = new StringFormat();
            fmt.Alignment = StringAlignment.Center;
            g.DrawString(this.Text, font, b,
                         this.Location.X + this.Size.Width / 2,
                         this.Location.Y + 1, fmt);
        }

        private void InitializeComponent()
        {
            this.Text = "Button";
            this.Size = new Size(50, 20);
            this.Location = new Point(10, 10);
            this.Parent = null;
        }
    }
}
