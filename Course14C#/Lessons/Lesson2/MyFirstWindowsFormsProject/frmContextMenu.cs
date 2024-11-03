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
    public partial class frmContextMenu : Form
    {
        public frmContextMenu()
        {
            InitializeComponent();
        }

        private void tsmClear_Click(object sender, EventArgs e)
        {
            textBox1.Clear();
        }

        private void tsmChangeFont_Click(object sender, EventArgs e)
        {
            fontDialog1.ShowApply = true;
            fontDialog1.ShowEffects = true;
            fontDialog1.ShowColor = true;

            if (fontDialog1.ShowDialog() == DialogResult.OK) 
            {
                textBox1.Font = fontDialog1.Font;
                textBox1.ForeColor = fontDialog1.Color;
            }
        }

        private void tsmChangeColor_Click(object sender, EventArgs e)
        {
            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {
                textBox1.BackColor = colorDialog1.Color;
            }
        }
    }
}
