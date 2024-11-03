using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyFirstWindowsFormsProject
{
    public partial class frmTimer : Form
    {
        public frmTimer()
        {
            InitializeComponent();
        }

        private int Counter = 0;

        private void timer1_Tick(object sender, EventArgs e)
        {
            Counter++;
            label1.Text = Counter.ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            timer1.Enabled = true;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            timer1.Enabled = false;
        }

        private void frmTimer_Load(object sender, EventArgs e)
        {
            label1.Text = "0";
        }
    }
}
