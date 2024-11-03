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
    public partial class frmMenuStrip : Form
    {
        public frmMenuStrip()
        {
            InitializeComponent();
        }

        private void findClientToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Find Client is here.");
        }

        private void addNewClientToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Add New Client is here.");
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Exit is here");
        }

        private Form frm2 = new frmContextMenu();

        private void form2ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            frm2.MdiParent = this;
            frm2.Show();
        }
    }
}
