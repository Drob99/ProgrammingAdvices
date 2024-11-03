using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MyFirstClassLibrary;

namespace TestClassLibraryForm
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            clsMyMath myMath1 = new clsMyMath();
            MessageBox.Show(myMath1.Sum(10, 20).ToString());

        }
    }
}
