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
    public partial class frmPictureBoxExercise : Form
    {
        public frmPictureBoxExercise()
        {
            InitializeComponent();
        }

        private void rbBoyImage_CheckedChanged(object sender, EventArgs e)
        {
            pictureBox1.Image = Properties.Resources.Boy;
            lblImage.Text = ((RadioButton) sender).Tag.ToString();
        }

        private void rbGirlImage_CheckedChanged(object sender, EventArgs e)
        {
            pictureBox1.Image = Properties.Resources.Girl;
            lblImage.Text = ((RadioButton)sender).Tag.ToString();
        }

        private void rbBookImage_CheckedChanged(object sender, EventArgs e)
        {
            pictureBox1.Image = Properties.Resources.Book;
            lblImage.Text = ((RadioButton)sender).Tag.ToString();
        }

        private void rbPenImage_CheckedChanged(object sender, EventArgs e)
        {
            pictureBox1.Image = Properties.Resources.Pen;
            lblImage.Text = ((RadioButton)sender).Tag.ToString();
        }
    }
}
