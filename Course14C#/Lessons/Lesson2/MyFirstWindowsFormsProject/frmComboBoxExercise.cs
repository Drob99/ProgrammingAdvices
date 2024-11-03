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
    public partial class frmComboBoxExercise : Form
    {
        public frmComboBoxExercise()
        {
            InitializeComponent();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (((ComboBox)sender).SelectedItem.ToString().ToLower())
            {
                case "boy":
                    pictureBox1.Image = Resources.Boy;
                    lblImage.Text = "Boy";
                    break;

                case "girl":
                    pictureBox1.Image = Resources.Girl;
                    lblImage.Text = "Girl";
                    break;

                case "book":
                    pictureBox1.Image = Resources.Book;
                    lblImage.Text = "Book";
                    break;


                case "pen":
                    pictureBox1.Image = Resources.Pen;
                    lblImage.Text = "Pen";
                    break;

                default:
                    break;
            }
        }

        private void frmComboBoxExercise_Load(object sender, EventArgs e)
        {
            comboBox1.SelectedIndex = 0;
        }
    }
}
