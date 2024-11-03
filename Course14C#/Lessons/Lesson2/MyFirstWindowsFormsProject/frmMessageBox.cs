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
    public partial class frmMessageBox : Form
    {
        public frmMessageBox()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Hi, this is a message!");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Hi, this is a message!", "Title");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if ((MessageBox.Show("Are you sure?", "Confirm!", MessageBoxButtons.OKCancel)) == DialogResult.OK)
            {
                // do sth
                MessageBox.Show("User pressed ok");
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if ((MessageBox.Show("Are you sure?", "Confirm!", MessageBoxButtons.OKCancel,MessageBoxIcon.Question)) == DialogResult.OK)
            {
                // do sth
                MessageBox.Show("User pressed ok");
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if ((MessageBox.Show("Are you sure?", "Confirm!", MessageBoxButtons.OKCancel, MessageBoxIcon.Question,MessageBoxDefaultButton.Button2)) == DialogResult.OK)
            {
                // do sth
                MessageBox.Show("User pressed ok");
            }
        }
    }
}
