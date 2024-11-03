namespace MyFirstWindowsFormsProject
{
    partial class frmFileOpenDialog
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
            this.btnFileOpenDialog = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.btnFileOpenDialogMulti = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnFileOpenDialog
            // 
            this.btnFileOpenDialog.Location = new System.Drawing.Point(72, 159);
            this.btnFileOpenDialog.Name = "btnFileOpenDialog";
            this.btnFileOpenDialog.Size = new System.Drawing.Size(182, 45);
            this.btnFileOpenDialog.TabIndex = 3;
            this.btnFileOpenDialog.Text = "Open File Dialog";
            this.btnFileOpenDialog.UseVisualStyleBackColor = true;
            this.btnFileOpenDialog.Click += new System.EventHandler(this.btnFileOpenDialog_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(72, 61);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(253, 22);
            this.textBox1.TabIndex = 2;
            this.textBox1.Text = "This is a text";
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // btnFileOpenDialogMulti
            // 
            this.btnFileOpenDialogMulti.Location = new System.Drawing.Point(291, 159);
            this.btnFileOpenDialogMulti.Name = "btnFileOpenDialogMulti";
            this.btnFileOpenDialogMulti.Size = new System.Drawing.Size(182, 45);
            this.btnFileOpenDialogMulti.TabIndex = 4;
            this.btnFileOpenDialogMulti.Text = "Open File Dialog Multi FIles";
            this.btnFileOpenDialogMulti.UseVisualStyleBackColor = true;
            this.btnFileOpenDialogMulti.Click += new System.EventHandler(this.btnFileOpenDialogMulti_Click);
            // 
            // frmFileOpenDialog
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1048, 538);
            this.Controls.Add(this.btnFileOpenDialogMulti);
            this.Controls.Add(this.btnFileOpenDialog);
            this.Controls.Add(this.textBox1);
            this.Name = "frmFileOpenDialog";
            this.Text = "frmFileOpenDialog";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnFileOpenDialog;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.Button btnFileOpenDialogMulti;
    }
}