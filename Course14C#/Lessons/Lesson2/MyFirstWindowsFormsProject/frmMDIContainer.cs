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
    public partial class frmMDIContainer : Form
    {
        public frmMDIContainer()
        {
            InitializeComponent();
        }

        private Form frm2 = new frmMain(); // single instance

        private void button1_Click(object sender, EventArgs e)
        {
            // Form frm2 = new frmMain();
            frm2.MdiParent = this;
            frm2.Show();
        }
    }
}
