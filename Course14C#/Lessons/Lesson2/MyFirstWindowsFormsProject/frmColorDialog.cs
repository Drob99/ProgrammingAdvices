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
    public partial class frmColorDialog : Form
    {
        public frmColorDialog()
        {
            InitializeComponent();
        }

        private void btnChangeBackColor_Click(object sender, EventArgs e)
        {
            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {
                textBox1.BackColor = colorDialog1.Color;
            }
            
        }

        private void btnChangeForeColor_Click(object sender, EventArgs e)
        {
            if (colorDialog1.ShowDialog()==DialogResult.OK) 
            {
                textBox1.ForeColor = colorDialog1.Color;
            }
        }
    }
}
