using MyFirstWindowsFormsProject.Properties;
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
    public partial class frmPictureBox : Form
    {
        public frmPictureBox()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Resources.MeKash7_aCloser;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Resources.Helal;
            pictureBox1.Image.RotateFlip(RotateFlipType.Rotate270FlipNone);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Image.FromFile(@"D:\omar_\Pictures\253889.png");
        }
    }
}
