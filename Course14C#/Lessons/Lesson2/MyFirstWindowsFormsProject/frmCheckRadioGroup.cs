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
    public partial class frmCheckRadioGroup : Form
    {
        public frmCheckRadioGroup()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show(chkReceiveEmails.Checked.ToString());
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            button1.Enabled = chkReceiveEmails.Checked;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            MessageBox.Show(rbSmall.Checked.ToString());
            rbSmall.Checked = chkReceiveEmails.Checked;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            gbSize.Visible = false;
        }
    }
}
