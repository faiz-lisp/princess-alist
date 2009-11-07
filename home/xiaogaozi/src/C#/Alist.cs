using System;
using System.Drawing;
using System.Windows.Forms;

namespace AlistWinForm
{
    public class Alist : Form
    {
        private MyForm f;
        private MyButton b;
        // private PictureBox p;
        private bool ismousedown;  // judge if mouse key is down
        private int mouse_to_left; // distance between mouse and form's left
        private int mouse_to_top;  // distance between mouse and form's top

        public Alist()
        {
            InitializeComponent();
        }

        private void InitializeComponent()
        {
            // /*
            //  * PictureBox p.
            //  */
            // this.p = new PictureBox();
            // this.p.Dock = DockStyle.Fill;
            // this.p.Location = new Point(0, 0);
            // this.p.Size = new Size(800, 600);
            // // this.Paint += new PaintEventHandler(this.p_Paint);

            /*
             * Form Alist.
             */
            this.Text = "Alist";
            this.Size = new Size(800, 600);
            // this.Controls.Add(this.p);
            this.Paint += new PaintEventHandler(this.Alist_Paint);
            this.MouseDown += new MouseEventHandler(this.Alist_MouseDown);
            this.MouseMove += new MouseEventHandler(this.Alist_MouseMove);
            this.MouseUp += new MouseEventHandler(this.Alist_MouseUp);

            this.f = new MyForm();

            this.b = new MyButton();
            this.b.Parent = this.f;
            this.f.Controls.Add(this.b);

            /*
             * Calculate position of button so that
             * it can be center of my awesome form.
             */
            int b_X = (this.b.Parent.Size.Width - this.b.Size.Width) / 2
                      + this.b.Parent.Location.X;
            int b_Y = this.b.Parent.Location.Y + this.b.Parent.Size.Height
                      - this.b.Size.Height - 10;
            this.b.Location = new Point(b_X, b_Y);
        }

        private void Alist_Paint(object sender, PaintEventArgs e)
        {
            /*
             * Show my form.
             */
            this.f.Show(sender, e);
        }

        private void Alist_MouseDown(object sender, MouseEventArgs e)
        {
            /*
             * Mouse in the title bar.
             */
            if (this.f.IsInTitleBar(e) == true)
            {
                ismousedown = true;
                mouse_to_left = e.X - this.f.Location.X;
                mouse_to_top = e.Y - this.f.Location.Y;
            }
        }

        private void Alist_MouseMove(object sender, MouseEventArgs e)
        {
            /*
             * Calculate new position of form.
             */
            if (true == ismousedown)
            {
                /*
                 * Calculate the distance of mouse movement;
                 */
                int hspace = e.X - mouse_to_left - this.f.Location.X;
                int vspace = e.Y - mouse_to_top - this.f.Location.Y;

                this.f.Location.X += hspace;
                this.f.Location.Y += vspace;
                this.b.Location.X += hspace;
                this.b.Location.Y += vspace;
                this.Refresh();
            }
        }

        private void Alist_MouseUp(object sender, MouseEventArgs e)
        {
            ismousedown = false;
        }

        static public void Main()
        {
            Application.EnableVisualStyles();
            Application.Run(new Alist());
        }
    }
}
