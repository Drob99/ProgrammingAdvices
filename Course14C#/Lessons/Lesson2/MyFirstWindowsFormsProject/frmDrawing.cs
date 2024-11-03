using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyFirstWindowsFormsProject
{
    public partial class frmDrawing : Form
    {
        public frmDrawing()
        {
            InitializeComponent();
        }

        private void frmDrawing_Paint(object sender, PaintEventArgs e)
        {
            Color Black = Color.FromArgb(255, 0, 0, 0);
            Pen Pen = new Pen(Black);
            Pen.Width = 10;

            Pen.DashStyle = System.Drawing.Drawing2D.DashStyle.Dash;
            Pen.StartCap = System.Drawing.Drawing2D.LineCap.Round;
            Pen.EndCap = System.Drawing.Drawing2D.LineCap.Round;

            e.Graphics.DrawLine(Pen, 100, 100, 100, 200);
            e.Graphics.DrawRectangle(Pen, 200, 200, 300, 300);
            e.Graphics.DrawEllipse(Pen, 200, 50, 100, 120);
        }
    }
}
