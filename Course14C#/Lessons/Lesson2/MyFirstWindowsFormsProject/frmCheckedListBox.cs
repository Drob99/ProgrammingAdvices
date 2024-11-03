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
    public partial class frmCheckedListBox : Form
    {
        public frmCheckedListBox()
        {
            InitializeComponent();
        }

        private void btnAddItems_Click(object sender, EventArgs e)
        {
            for (short i = 0; i < 5; i++)
            {
                checkedListBox1.Items.Add("Item" + (i+1));
            }
        }

        private void btnShowCheckedItems_Click(object sender, EventArgs e)
        {
            for (short i = 0; i< checkedListBox1.CheckedItems.Count; i++)
            {
                MessageBox.Show(checkedListBox1.CheckedItems[i].ToString());
            }
        }

        private void btnCheckAllItems_Click(object sender, EventArgs e)
        {
            for (short i = 0; i < checkedListBox1.Items.Count; i++)
            {
                checkedListBox1.SetItemChecked(i, true);
            }
        }

        private void btnUncheckAllItems_Click(object sender, EventArgs e)
        {
            for (short i = 0; i < checkedListBox1.Items.Count; i++)
            {
                checkedListBox1.SetItemChecked(i, false);
            }
        }

        private void btnRemoveThirdItem_Click(object sender, EventArgs e)
        {
            if (checkedListBox1.Items.Count > 2)
            {
                checkedListBox1.Items.RemoveAt(2);
            }
        }
    }
}
