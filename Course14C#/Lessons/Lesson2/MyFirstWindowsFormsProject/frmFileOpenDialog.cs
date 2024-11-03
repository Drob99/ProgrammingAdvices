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
    public partial class frmFileOpenDialog : Form
    {
        public frmFileOpenDialog()
        {
            InitializeComponent();
        }

        private void btnFileOpenDialog_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                // openFileDialog1.InitialDirectory = @"D:\";
                // openFileDialog1.Title = "Omar";
                // openFileDialog1.DefaultExt = "txt";
                // openFileDialog1.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
                //openFileDialog1.FilterIndex = 2;

                MessageBox.Show(openFileDialog1.FileName);
            }
        }

        private void btnFileOpenDialogMulti_Click(object sender, EventArgs e)
        {
            openFileDialog1.Multiselect = true;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                foreach (string file in openFileDialog1.FileNames) 
                {
                    MessageBox.Show(file);
                }
            }
        }
    }
}
