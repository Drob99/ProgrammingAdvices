namespace MyFirstWindowsFormsProject
{
    partial class frmPictureBoxExercise
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
            this.rbBoyImage = new System.Windows.Forms.RadioButton();
            this.rbGirlImage = new System.Windows.Forms.RadioButton();
            this.rbBookImage = new System.Windows.Forms.RadioButton();
            this.rbPenImage = new System.Windows.Forms.RadioButton();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.lblImage = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // rbBoyImage
            // 
            this.rbBoyImage.AutoSize = true;
            this.rbBoyImage.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbBoyImage.Location = new System.Drawing.Point(173, 529);
            this.rbBoyImage.Name = "rbBoyImage";
            this.rbBoyImage.Size = new System.Drawing.Size(78, 33);
            this.rbBoyImage.TabIndex = 1;
            this.rbBoyImage.TabStop = true;
            this.rbBoyImage.Tag = "BOY";
            this.rbBoyImage.Text = "Boy";
            this.rbBoyImage.UseVisualStyleBackColor = true;
            this.rbBoyImage.CheckedChanged += new System.EventHandler(this.rbBoyImage_CheckedChanged);
            // 
            // rbGirlImage
            // 
            this.rbGirlImage.AutoSize = true;
            this.rbGirlImage.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbGirlImage.Location = new System.Drawing.Point(294, 529);
            this.rbGirlImage.Name = "rbGirlImage";
            this.rbGirlImage.Size = new System.Drawing.Size(73, 33);
            this.rbGirlImage.TabIndex = 2;
            this.rbGirlImage.TabStop = true;
            this.rbGirlImage.Tag = "GIRL";
            this.rbGirlImage.Text = "Girl";
            this.rbGirlImage.UseVisualStyleBackColor = true;
            this.rbGirlImage.CheckedChanged += new System.EventHandler(this.rbGirlImage_CheckedChanged);
            // 
            // rbBookImage
            // 
            this.rbBookImage.AutoSize = true;
            this.rbBookImage.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbBookImage.Location = new System.Drawing.Point(411, 529);
            this.rbBookImage.Name = "rbBookImage";
            this.rbBookImage.Size = new System.Drawing.Size(92, 33);
            this.rbBookImage.TabIndex = 3;
            this.rbBookImage.TabStop = true;
            this.rbBookImage.Tag = "BOOK";
            this.rbBookImage.Text = "Book";
            this.rbBookImage.UseVisualStyleBackColor = true;
            this.rbBookImage.CheckedChanged += new System.EventHandler(this.rbBookImage_CheckedChanged);
            // 
            // rbPenImage
            // 
            this.rbPenImage.AutoSize = true;
            this.rbPenImage.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbPenImage.Location = new System.Drawing.Point(540, 529);
            this.rbPenImage.Name = "rbPenImage";
            this.rbPenImage.Size = new System.Drawing.Size(79, 33);
            this.rbPenImage.TabIndex = 4;
            this.rbPenImage.TabStop = true;
            this.rbPenImage.Tag = "PEN";
            this.rbPenImage.Text = "Pen";
            this.rbPenImage.UseVisualStyleBackColor = true;
            this.rbPenImage.CheckedChanged += new System.EventHandler(this.rbPenImage_CheckedChanged);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::MyFirstWindowsFormsProject.Properties.Resources.Boy;
            this.pictureBox1.Location = new System.Drawing.Point(211, 86);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(377, 421);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 4;
            this.pictureBox1.TabStop = false;
            // 
            // lblImage
            // 
            this.lblImage.Font = new System.Drawing.Font("Showcard Gothic", 35F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblImage.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.lblImage.Location = new System.Drawing.Point(211, 9);
            this.lblImage.Name = "lblImage";
            this.lblImage.Size = new System.Drawing.Size(377, 74);
            this.lblImage.TabIndex = 6;
            this.lblImage.Text = "TITLE";
            this.lblImage.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // frmPictureBoxExercise
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(816, 583);
            this.Controls.Add(this.lblImage);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.rbPenImage);
            this.Controls.Add(this.rbBookImage);
            this.Controls.Add(this.rbGirlImage);
            this.Controls.Add(this.rbBoyImage);
            this.Name = "frmPictureBoxExercise";
            this.Text = "frmPictureBoxExercise";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RadioButton rbBoyImage;
        private System.Windows.Forms.RadioButton rbGirlImage;
        private System.Windows.Forms.RadioButton rbBookImage;
        private System.Windows.Forms.RadioButton rbPenImage;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label lblImage;
    }
}