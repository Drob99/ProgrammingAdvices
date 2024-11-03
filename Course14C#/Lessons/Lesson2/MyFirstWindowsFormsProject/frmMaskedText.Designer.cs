namespace MyFirstWindowsFormsProject
{
    partial class frmMaskedText
    {
        /*
         MaskedTextBox1.Mask = "00/00/0000";  

        Here is a list and description of masking characters.

        0 – Digit, required. Value between 0 and 9.
        9 – Digit or space, optional.
        # - Digit or space, optional. If this position is blank in the mask, it will be rendered as a space in the Text property.
        L - Letter, required. Restricts input to the ASCII letters a-z and A-Z.
        ? - Letter, optional. Restricts input to the ASCII letters a-z and A-Z.
        & - Character, required.
        C - Character, optional. Any non-control character.
        A - Alphanumeric, required.
        a - Alphanumeric, optional.
        . - Decimal placeholder.
        , - Thousands placeholder.
        : - Time separator.
        / - Date separator.
        $ - Currency symbol.
        < - Shift down. Converts all characters that follow to lowercase.
        > - Shift up. Converts all characters that follow to uppercase.
        | - Disable a previous shift up or shift down.
        \ - Escape. Escapes a mask character, turning it into a literal. "\\" is the escape sequence for a backslash.
        All other characters - Literals. All non-mask elements will appear as themselves within MaskedTextBox. Literals always occupy a static position in the mask at run time, and cannot be moved or deleted by the user.
         
         */
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
            this.maskedTextBox1 = new System.Windows.Forms.MaskedTextBox();
            this.maskedTextBox2 = new System.Windows.Forms.MaskedTextBox();
            this.maskedTextBox3 = new System.Windows.Forms.MaskedTextBox();
            this.SuspendLayout();
            // 
            // maskedTextBox1
            // 
            this.maskedTextBox1.BeepOnError = true;
            this.maskedTextBox1.Location = new System.Drawing.Point(54, 35);
            this.maskedTextBox1.Mask = "00/00/0000";
            this.maskedTextBox1.Name = "maskedTextBox1";
            this.maskedTextBox1.Size = new System.Drawing.Size(234, 22);
            this.maskedTextBox1.TabIndex = 0;
            this.maskedTextBox1.ValidatingType = typeof(System.DateTime);
            // 
            // maskedTextBox2
            // 
            this.maskedTextBox2.Location = new System.Drawing.Point(54, 100);
            this.maskedTextBox2.Mask = "00000";
            this.maskedTextBox2.Name = "maskedTextBox2";
            this.maskedTextBox2.Size = new System.Drawing.Size(234, 22);
            this.maskedTextBox2.TabIndex = 1;
            this.maskedTextBox2.ValidatingType = typeof(int);
            // 
            // maskedTextBox3
            // 
            this.maskedTextBox3.Location = new System.Drawing.Point(54, 186);
            this.maskedTextBox3.Mask = "00000";
            this.maskedTextBox3.Name = "maskedTextBox3";
            this.maskedTextBox3.Size = new System.Drawing.Size(234, 22);
            this.maskedTextBox3.TabIndex = 2;
            this.maskedTextBox3.ValidatingType = typeof(int);
            // 
            // frmMaskedText
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1148, 587);
            this.Controls.Add(this.maskedTextBox3);
            this.Controls.Add(this.maskedTextBox2);
            this.Controls.Add(this.maskedTextBox1);
            this.Name = "frmMaskedText";
            this.Text = "fromMaskedText";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MaskedTextBox maskedTextBox1;
        private System.Windows.Forms.MaskedTextBox maskedTextBox2;
        private System.Windows.Forms.MaskedTextBox maskedTextBox3;
    }
}