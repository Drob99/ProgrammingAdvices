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
    public partial class frmTreeView : Form
    {
        public frmTreeView()
        {
            InitializeComponent();
        }

        private void treeView1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            MessageBox.Show(((TreeView)sender).SelectedNode.Text);
        }

        private void treeView1_AfterCheck(object sender, TreeViewEventArgs e)
        {
            CheckTreeViewNode(e.Node, e.Node.Checked);
        }

        private void CheckTreeViewNode(TreeNode node, Boolean isChecked)
        {
            foreach (TreeNode childNode in  node.Nodes) 
            { 
                childNode.Checked = isChecked;
                if (childNode.Nodes.Count > 0) 
                {
                    this.CheckTreeViewNode(childNode, isChecked);
                }
            }
        }
    }
}
