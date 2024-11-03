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
    public partial class frmFileSaveDialog : Form
    {
        public frmFileSaveDialog()
        {
            InitializeComponent();
        }

        private void btnFileSaveDialog_Click(object sender, EventArgs e)
        {
            // saveFileDialog1.InitialDirectory = @"D:\";
            // saveFileDialog1.Title = "Omar";
            // saveFileDialog1.DefaultExt = "txt";
            // saveFileDialog1.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
            //saveFileDialog1.FilterIndex = 2;
            
            if (saveFileDialog1.ShowDialog() == DialogResult.OK) 
            {
                MessageBox.Show(saveFileDialog1.FileName);
            }
        }
    }
}
