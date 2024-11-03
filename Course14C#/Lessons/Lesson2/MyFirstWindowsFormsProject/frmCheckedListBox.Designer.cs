namespace MyFirstWindowsFormsProject
{
    partial class frmCheckedListBox
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
            this.checkedListBox1 = new System.Windows.Forms.CheckedListBox();
            this.btnAddItems = new System.Windows.Forms.Button();
            this.btnShowCheckedItems = new System.Windows.Forms.Button();
            this.btnCheckAllItems = new System.Windows.Forms.Button();
            this.btnUncheckAllItems = new System.Windows.Forms.Button();
            this.btnRemoveThirdItem = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // checkedListBox1
            // 
            this.checkedListBox1.FormattingEnabled = true;
            this.checkedListBox1.Location = new System.Drawing.Point(227, 45);
            this.checkedListBox1.Name = "checkedListBox1";
            this.checkedListBox1.Size = new System.Drawing.Size(405, 225);
            this.checkedListBox1.TabIndex = 0;
            // 
            // btnAddItems
            // 
            this.btnAddItems.Location = new System.Drawing.Point(133, 383);
            this.btnAddItems.Name = "btnAddItems";
            this.btnAddItems.Size = new System.Drawing.Size(114, 54);
            this.btnAddItems.TabIndex = 1;
            this.btnAddItems.Text = "Add Items";
            this.btnAddItems.UseVisualStyleBackColor = true;
            this.btnAddItems.Click += new System.EventHandler(this.btnAddItems_Click);
            // 
            // btnShowCheckedItems
            // 
            this.btnShowCheckedItems.Location = new System.Drawing.Point(264, 383);
            this.btnShowCheckedItems.Name = "btnShowSelectedItems";
            this.btnShowCheckedItems.Size = new System.Drawing.Size(114, 54);
            this.btnShowCheckedItems.TabIndex = 2;
            this.btnShowCheckedItems.Text = "Show Selected Items";
            this.btnShowCheckedItems.UseVisualStyleBackColor = true;
            this.btnShowCheckedItems.Click += new System.EventHandler(this.btnShowCheckedItems_Click);
            // 
            // btnCheckAllItems
            // 
            this.btnCheckAllItems.Location = new System.Drawing.Point(395, 383);
            this.btnCheckAllItems.Name = "btnCheckAllItems";
            this.btnCheckAllItems.Size = new System.Drawing.Size(114, 54);
            this.btnCheckAllItems.TabIndex = 3;
            this.btnCheckAllItems.Text = "Check All Items";
            this.btnCheckAllItems.UseVisualStyleBackColor = true;
            this.btnCheckAllItems.Click += new System.EventHandler(this.btnCheckAllItems_Click);
            // 
            // btnUncheckAllItems
            // 
            this.btnUncheckAllItems.Location = new System.Drawing.Point(526, 383);
            this.btnUncheckAllItems.Name = "btnUncheckAllItems";
            this.btnUncheckAllItems.Size = new System.Drawing.Size(114, 54);
            this.btnUncheckAllItems.TabIndex = 4;
            this.btnUncheckAllItems.Text = "UnCheck All Items ";
            this.btnUncheckAllItems.UseVisualStyleBackColor = true;
            this.btnUncheckAllItems.Click += new System.EventHandler(this.btnUncheckAllItems_Click);
            // 
            // btnRemoveThirdItem
            // 
            this.btnRemoveThirdItem.Location = new System.Drawing.Point(657, 383);
            this.btnRemoveThirdItem.Name = "btnRemoveThirdItem";
            this.btnRemoveThirdItem.Size = new System.Drawing.Size(114, 54);
            this.btnRemoveThirdItem.TabIndex = 5;
            this.btnRemoveThirdItem.Text = "Remove Third Item";
            this.btnRemoveThirdItem.UseVisualStyleBackColor = true;
            this.btnRemoveThirdItem.Click += new System.EventHandler(this.btnRemoveThirdItem_Click);
            // 
            // frmCheckedListBox
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(942, 562);
            this.Controls.Add(this.btnRemoveThirdItem);
            this.Controls.Add(this.btnUncheckAllItems);
            this.Controls.Add(this.btnCheckAllItems);
            this.Controls.Add(this.btnShowCheckedItems);
            this.Controls.Add(this.btnAddItems);
            this.Controls.Add(this.checkedListBox1);
            this.Name = "frmCheckedListBox";
            this.Text = "frmCheckedListBox";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.CheckedListBox checkedListBox1;
        private System.Windows.Forms.Button btnAddItems;
        private System.Windows.Forms.Button btnShowCheckedItems;
        private System.Windows.Forms.Button btnCheckAllItems;
        private System.Windows.Forms.Button btnUncheckAllItems;
        private System.Windows.Forms.Button btnRemoveThirdItem;
    }
}