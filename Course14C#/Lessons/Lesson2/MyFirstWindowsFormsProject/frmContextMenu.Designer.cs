namespace MyFirstWindowsFormsProject
{
    partial class frmContextMenu
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.TreeNode treeNode1 = new System.Windows.Forms.TreeNode("Node3");
            System.Windows.Forms.TreeNode treeNode2 = new System.Windows.Forms.TreeNode("Node0", new System.Windows.Forms.TreeNode[] {
            treeNode1});
            System.Windows.Forms.TreeNode treeNode3 = new System.Windows.Forms.TreeNode("Node1");
            System.Windows.Forms.TreeNode treeNode4 = new System.Windows.Forms.TreeNode("Node2");
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.treeView1 = new System.Windows.Forms.TreeView();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.fontDialog1 = new System.Windows.Forms.FontDialog();
            this.cmFormat = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.tsmChangeColor = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmChangeFont = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmClear = new System.Windows.Forms.ToolStripMenuItem();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.addNewToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.deleteToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.updateToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.contextMenuStrip1.SuspendLayout();
            this.cmFormat.SuspendLayout();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.ContextMenuStrip = this.cmFormat;
            this.textBox1.Location = new System.Drawing.Point(58, 47);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(366, 22);
            this.textBox1.TabIndex = 0;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(138, 142);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(171, 45);
            this.button1.TabIndex = 1;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // treeView1
            // 
            this.treeView1.ContextMenuStrip = this.contextMenuStrip1;
            this.treeView1.Location = new System.Drawing.Point(555, 27);
            this.treeView1.Name = "treeView1";
            treeNode1.Name = "Node3";
            treeNode1.Text = "Node3";
            treeNode2.Name = "Node0";
            treeNode2.Text = "Node0";
            treeNode3.Name = "Node1";
            treeNode3.Text = "Node1";
            treeNode4.Name = "Node2";
            treeNode4.Text = "Node2";
            this.treeView1.Nodes.AddRange(new System.Windows.Forms.TreeNode[] {
            treeNode2,
            treeNode3,
            treeNode4});
            this.treeView1.Size = new System.Drawing.Size(410, 470);
            this.treeView1.TabIndex = 2;
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.addNewToolStripMenuItem,
            this.deleteToolStripMenuItem,
            this.updateToolStripMenuItem});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(141, 76);
            // 
            // cmFormat
            // 
            this.cmFormat.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.cmFormat.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmChangeColor,
            this.tsmChangeFont,
            this.tsmClear});
            this.cmFormat.Name = "cmFormat";
            this.cmFormat.Size = new System.Drawing.Size(169, 76);
            // 
            // tsmChangeColor
            // 
            this.tsmChangeColor.Name = "tsmChangeColor";
            this.tsmChangeColor.Size = new System.Drawing.Size(168, 24);
            this.tsmChangeColor.Text = "Change Color";
            this.tsmChangeColor.Click += new System.EventHandler(this.tsmChangeColor_Click);
            // 
            // tsmChangeFont
            // 
            this.tsmChangeFont.Name = "tsmChangeFont";
            this.tsmChangeFont.Size = new System.Drawing.Size(168, 24);
            this.tsmChangeFont.Text = "Change Font";
            this.tsmChangeFont.Click += new System.EventHandler(this.tsmChangeFont_Click);
            // 
            // tsmClear
            // 
            this.tsmClear.Name = "tsmClear";
            this.tsmClear.Size = new System.Drawing.Size(168, 24);
            this.tsmClear.Text = "Clear";
            this.tsmClear.Click += new System.EventHandler(this.tsmClear_Click);
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(58, 94);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(366, 22);
            this.textBox2.TabIndex = 5;
            // 
            // addNewToolStripMenuItem
            // 
            this.addNewToolStripMenuItem.Name = "addNewToolStripMenuItem";
            this.addNewToolStripMenuItem.Size = new System.Drawing.Size(140, 24);
            this.addNewToolStripMenuItem.Text = "Add New";
            // 
            // deleteToolStripMenuItem
            // 
            this.deleteToolStripMenuItem.Name = "deleteToolStripMenuItem";
            this.deleteToolStripMenuItem.Size = new System.Drawing.Size(140, 24);
            this.deleteToolStripMenuItem.Text = "Delete";
            // 
            // updateToolStripMenuItem
            // 
            this.updateToolStripMenuItem.Name = "updateToolStripMenuItem";
            this.updateToolStripMenuItem.Size = new System.Drawing.Size(140, 24);
            this.updateToolStripMenuItem.Text = "Update";
            // 
            // frmContextMenu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1159, 537);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.treeView1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.textBox1);
            this.Name = "frmContextMenu";
            this.Text = "frmContextMenu";
            this.contextMenuStrip1.ResumeLayout(false);
            this.cmFormat.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TreeView treeView1;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ColorDialog colorDialog1;
        private System.Windows.Forms.FontDialog fontDialog1;
        private System.Windows.Forms.ContextMenuStrip cmFormat;
        private System.Windows.Forms.ToolStripMenuItem tsmChangeColor;
        private System.Windows.Forms.ToolStripMenuItem tsmChangeFont;
        private System.Windows.Forms.ToolStripMenuItem tsmClear;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.ToolStripMenuItem addNewToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem deleteToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem updateToolStripMenuItem;
    }
}