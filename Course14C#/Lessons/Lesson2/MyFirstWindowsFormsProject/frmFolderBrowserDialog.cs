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
    public partial class frmFolderBrowserDialog : Form
    {
        public frmFolderBrowserDialog()
        {
            InitializeComponent();
        }

        private void btnFolderBrowsingDialog_Click(object sender, EventArgs e)
        {
            folderBrowserDialog1.ShowNewFolderButton = true;

            if (folderBrowserDialog1.ShowDialog() == DialogResult.OK) 
            {
                MessageBox.Show(folderBrowserDialog1.SelectedPath);
            }
        }
    }
}
