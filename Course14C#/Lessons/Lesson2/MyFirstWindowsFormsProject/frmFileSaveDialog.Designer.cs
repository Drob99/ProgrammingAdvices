﻿namespace MyFirstWindowsFormsProject
{
    partial class frmFileSaveDialog
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
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.btnFileSaveDialog = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(60, 54);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(253, 22);
            this.textBox1.TabIndex = 0;
            this.textBox1.Text = "This is a text";
            // 
            // btnFileSaveDialog
            // 
            this.btnFileSaveDialog.Location = new System.Drawing.Point(60, 152);
            this.btnFileSaveDialog.Name = "btnFileSaveDialog";
            this.btnFileSaveDialog.Size = new System.Drawing.Size(182, 45);
            this.btnFileSaveDialog.TabIndex = 1;
            this.btnFileSaveDialog.Text = "Save File Dialog";
            this.btnFileSaveDialog.UseVisualStyleBackColor = true;
            this.btnFileSaveDialog.Click += new System.EventHandler(this.btnFileSaveDialog_Click);
            // 
            // frmFileSaveDialog
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(875, 481);
            this.Controls.Add(this.btnFileSaveDialog);
            this.Controls.Add(this.textBox1);
            this.Name = "frmFileSaveDialog";
            this.Text = "frmFileSaveDialog";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button btnFileSaveDialog;
    }
}