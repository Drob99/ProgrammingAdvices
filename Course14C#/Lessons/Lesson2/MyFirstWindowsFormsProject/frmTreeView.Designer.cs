namespace MyFirstWindowsFormsProject
{
    partial class frmTreeView
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmTreeView));
            System.Windows.Forms.TreeNode treeNode1 = new System.Windows.Forms.TreeNode("Boy", 1, 1);
            System.Windows.Forms.TreeNode treeNode2 = new System.Windows.Forms.TreeNode("Girl");
            System.Windows.Forms.TreeNode treeNode3 = new System.Windows.Forms.TreeNode("Boy", 1, 1);
            System.Windows.Forms.TreeNode treeNode4 = new System.Windows.Forms.TreeNode("Boy", 1, 1, new System.Windows.Forms.TreeNode[] {
            treeNode1,
            treeNode2,
            treeNode3});
            System.Windows.Forms.TreeNode treeNode5 = new System.Windows.Forms.TreeNode("Girl");
            System.Windows.Forms.TreeNode treeNode6 = new System.Windows.Forms.TreeNode("Boy", 1, 1);
            System.Windows.Forms.TreeNode treeNode7 = new System.Windows.Forms.TreeNode("Girl");
            System.Windows.Forms.TreeNode treeNode8 = new System.Windows.Forms.TreeNode("Boy", 1, 1);
            System.Windows.Forms.TreeNode treeNode9 = new System.Windows.Forms.TreeNode("Girl", new System.Windows.Forms.TreeNode[] {
            treeNode6,
            treeNode7,
            treeNode8});
            System.Windows.Forms.TreeNode treeNode10 = new System.Windows.Forms.TreeNode("Boy", 1, 1);
            this.imageList1 = new System.Windows.Forms.ImageList(this.components);
            this.treeView1 = new System.Windows.Forms.TreeView();
            this.SuspendLayout();
            // 
            // imageList1
            // 
            this.imageList1.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList1.ImageStream")));
            this.imageList1.TransparentColor = System.Drawing.Color.Transparent;
            this.imageList1.Images.SetKeyName(0, "Girl.png");
            this.imageList1.Images.SetKeyName(1, "Boy.png");
            // 
            // treeView1
            // 
            this.treeView1.CheckBoxes = true;
            this.treeView1.ImageIndex = 0;
            this.treeView1.ImageList = this.imageList1;
            this.treeView1.Location = new System.Drawing.Point(86, 12);
            this.treeView1.Name = "treeView1";
            treeNode1.ImageIndex = 1;
            treeNode1.Name = "Node4";
            treeNode1.SelectedImageIndex = 1;
            treeNode1.Text = "Boy";
            treeNode2.Name = "Node5";
            treeNode2.Text = "Girl";
            treeNode3.ImageIndex = 1;
            treeNode3.Name = "Node6";
            treeNode3.SelectedImageIndex = 1;
            treeNode3.Text = "Boy";
            treeNode4.ImageIndex = 1;
            treeNode4.Name = "Node0";
            treeNode4.SelectedImageIndex = 1;
            treeNode4.Text = "Boy";
            treeNode5.Name = "Node1";
            treeNode5.Text = "Girl";
            treeNode6.ImageIndex = 1;
            treeNode6.Name = "Node7";
            treeNode6.SelectedImageIndex = 1;
            treeNode6.Text = "Boy";
            treeNode7.Name = "Node8";
            treeNode7.Text = "Girl";
            treeNode8.ImageIndex = 1;
            treeNode8.Name = "Node9";
            treeNode8.SelectedImageIndex = 1;
            treeNode8.Text = "Boy";
            treeNode9.Name = "Node2";
            treeNode9.Text = "Girl";
            treeNode10.ImageIndex = 1;
            treeNode10.Name = "Node3";
            treeNode10.SelectedImageIndex = 1;
            treeNode10.Text = "Boy";
            this.treeView1.Nodes.AddRange(new System.Windows.Forms.TreeNode[] {
            treeNode4,
            treeNode5,
            treeNode9,
            treeNode10});
            this.treeView1.SelectedImageIndex = 0;
            this.treeView1.Size = new System.Drawing.Size(588, 477);
            this.treeView1.TabIndex = 0;
            this.treeView1.AfterCheck += new System.Windows.Forms.TreeViewEventHandler(this.treeView1_AfterCheck);
            this.treeView1.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.treeView1_MouseDoubleClick);
            // 
            // frmTreeView
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(875, 551);
            this.Controls.Add(this.treeView1);
            this.Name = "frmTreeView";
            this.Text = "frmTreeView";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ImageList imageList1;
        private System.Windows.Forms.TreeView treeView1;
    }
}