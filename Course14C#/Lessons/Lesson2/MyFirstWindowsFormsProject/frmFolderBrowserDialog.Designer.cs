namespace MyFirstWindowsFormsProject
{
    partial class frmFolderBrowserDialog
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
            this.btnFolderBrowsingDialog = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.folderBrowserDialog1 = new System.Windows.Forms.FolderBrowserDialog();
            this.SuspendLayout();
            // 
            // btnFolderBrowsingDialog
            // 
            this.btnFolderBrowsingDialog.Location = new System.Drawing.Point(62, 165);
            this.btnFolderBrowsingDialog.Name = "btnFolderBrowsingDialog";
            this.btnFolderBrowsingDialog.Size = new System.Drawing.Size(182, 45);
            this.btnFolderBrowsingDialog.TabIndex = 3;
            this.btnFolderBrowsingDialog.Text = "Folder Browser Dialog";
            this.btnFolderBrowsingDialog.UseVisualStyleBackColor = true;
            this.btnFolderBrowsingDialog.Click += new System.EventHandler(this.btnFolderBrowsingDialog_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(62, 67);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(253, 22);
            this.textBox1.TabIndex = 2;
            this.textBox1.Text = "This is a text";
            // 
            // frmFolderBrowserDialog
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(981, 532);
            this.Controls.Add(this.btnFolderBrowsingDialog);
            this.Controls.Add(this.textBox1);
            this.Name = "frmFolderBrowserDialog";
            this.Text = "frmFolderBrowserDialog";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnFolderBrowsingDialog;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.FolderBrowserDialog folderBrowserDialog1;
    }
}