namespace PizzaProject
{
    partial class Form1
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
            this.Title = new System.Windows.Forms.Label();
            this.gbSize = new System.Windows.Forms.GroupBox();
            this.rbLarge = new System.Windows.Forms.RadioButton();
            this.rbMedium = new System.Windows.Forms.RadioButton();
            this.rbSmall = new System.Windows.Forms.RadioButton();
            this.gbWhereToEat = new System.Windows.Forms.GroupBox();
            this.rbTakeOut = new System.Windows.Forms.RadioButton();
            this.rbEatIn = new System.Windows.Forms.RadioButton();
            this.gbCrust = new System.Windows.Forms.GroupBox();
            this.rbThick = new System.Windows.Forms.RadioButton();
            this.rbThin = new System.Windows.Forms.RadioButton();
            this.gbToppings = new System.Windows.Forms.GroupBox();
            this.chkGreenPeppers = new System.Windows.Forms.CheckBox();
            this.chkOlives = new System.Windows.Forms.CheckBox();
            this.chkOnion = new System.Windows.Forms.CheckBox();
            this.chkTomatoes = new System.Windows.Forms.CheckBox();
            this.chkMushrooms = new System.Windows.Forms.CheckBox();
            this.chkExtraCheese = new System.Windows.Forms.CheckBox();
            this.gbOrderSummary = new System.Windows.Forms.GroupBox();
            this.inpTotalPrice = new System.Windows.Forms.Label();
            this.inpWhereToEat = new System.Windows.Forms.Label();
            this.inpCrustType = new System.Windows.Forms.Label();
            this.inpToppings = new System.Windows.Forms.Label();
            this.inpSize = new System.Windows.Forms.Label();
            this.txtToppings = new System.Windows.Forms.Label();
            this.txtTotalPrice = new System.Windows.Forms.Label();
            this.txtWhereToEat = new System.Windows.Forms.Label();
            this.txtCrustType = new System.Windows.Forms.Label();
            this.lbToppings = new System.Windows.Forms.Label();
            this.txtSize = new System.Windows.Forms.Label();
            this.btnOrderPizza = new System.Windows.Forms.Button();
            this.btnResetForm = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.nudNumberOfPizzas = new System.Windows.Forms.NumericUpDown();
            this.gbSize.SuspendLayout();
            this.gbWhereToEat.SuspendLayout();
            this.gbCrust.SuspendLayout();
            this.gbToppings.SuspendLayout();
            this.gbOrderSummary.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudNumberOfPizzas)).BeginInit();
            this.SuspendLayout();
            // 
            // Title
            // 
            this.Title.AutoSize = true;
            this.Title.Font = new System.Drawing.Font("Showcard Gothic", 30F);
            this.Title.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.Title.Location = new System.Drawing.Point(282, 9);
            this.Title.Name = "Title";
            this.Title.Size = new System.Drawing.Size(470, 62);
            this.Title.TabIndex = 0;
            this.Title.Text = "MAKE YOUR PIZZA";
            // 
            // gbSize
            // 
            this.gbSize.Controls.Add(this.rbLarge);
            this.gbSize.Controls.Add(this.rbMedium);
            this.gbSize.Controls.Add(this.rbSmall);
            this.gbSize.Location = new System.Drawing.Point(55, 91);
            this.gbSize.Name = "gbSize";
            this.gbSize.Size = new System.Drawing.Size(188, 157);
            this.gbSize.TabIndex = 0;
            this.gbSize.TabStop = false;
            this.gbSize.Text = "Size";
            // 
            // rbLarge
            // 
            this.rbLarge.AutoSize = true;
            this.rbLarge.Location = new System.Drawing.Point(43, 111);
            this.rbLarge.Name = "rbLarge";
            this.rbLarge.Size = new System.Drawing.Size(63, 20);
            this.rbLarge.TabIndex = 2;
            this.rbLarge.TabStop = true;
            this.rbLarge.Tag = "40";
            this.rbLarge.Text = "Large";
            this.rbLarge.UseVisualStyleBackColor = true;
            this.rbLarge.CheckedChanged += new System.EventHandler(this.rbLarge_CheckedChanged);
            // 
            // rbMedium
            // 
            this.rbMedium.AutoSize = true;
            this.rbMedium.Checked = true;
            this.rbMedium.Location = new System.Drawing.Point(43, 74);
            this.rbMedium.Name = "rbMedium";
            this.rbMedium.Size = new System.Drawing.Size(76, 20);
            this.rbMedium.TabIndex = 0;
            this.rbMedium.TabStop = true;
            this.rbMedium.Tag = "30";
            this.rbMedium.Text = "Medium";
            this.rbMedium.UseVisualStyleBackColor = true;
            this.rbMedium.CheckedChanged += new System.EventHandler(this.rbMedium_CheckedChanged);
            // 
            // rbSmall
            // 
            this.rbSmall.AutoSize = true;
            this.rbSmall.Location = new System.Drawing.Point(43, 37);
            this.rbSmall.Name = "rbSmall";
            this.rbSmall.Size = new System.Drawing.Size(62, 20);
            this.rbSmall.TabIndex = 1;
            this.rbSmall.TabStop = true;
            this.rbSmall.Tag = "20";
            this.rbSmall.Text = "Small";
            this.rbSmall.UseVisualStyleBackColor = true;
            this.rbSmall.CheckedChanged += new System.EventHandler(this.rbSmall_CheckedChanged);
            // 
            // gbWhereToEat
            // 
            this.gbWhereToEat.Controls.Add(this.rbTakeOut);
            this.gbWhereToEat.Controls.Add(this.rbEatIn);
            this.gbWhereToEat.Location = new System.Drawing.Point(312, 263);
            this.gbWhereToEat.Name = "gbWhereToEat";
            this.gbWhereToEat.Size = new System.Drawing.Size(297, 81);
            this.gbWhereToEat.TabIndex = 2;
            this.gbWhereToEat.TabStop = false;
            this.gbWhereToEat.Text = "Where To Eat";
            // 
            // rbTakeOut
            // 
            this.rbTakeOut.AutoSize = true;
            this.rbTakeOut.Location = new System.Drawing.Point(164, 40);
            this.rbTakeOut.Name = "rbTakeOut";
            this.rbTakeOut.Size = new System.Drawing.Size(83, 20);
            this.rbTakeOut.TabIndex = 2;
            this.rbTakeOut.TabStop = true;
            this.rbTakeOut.Text = "Take Out";
            this.rbTakeOut.UseVisualStyleBackColor = true;
            this.rbTakeOut.CheckedChanged += new System.EventHandler(this.rbTakeOut_CheckedChanged);
            // 
            // rbEatIn
            // 
            this.rbEatIn.AutoSize = true;
            this.rbEatIn.Checked = true;
            this.rbEatIn.Location = new System.Drawing.Point(18, 40);
            this.rbEatIn.Name = "rbEatIn";
            this.rbEatIn.Size = new System.Drawing.Size(61, 20);
            this.rbEatIn.TabIndex = 1;
            this.rbEatIn.TabStop = true;
            this.rbEatIn.Text = "Eat In";
            this.rbEatIn.UseVisualStyleBackColor = true;
            this.rbEatIn.CheckedChanged += new System.EventHandler(this.rbEatIn_CheckedChanged);
            // 
            // gbCrust
            // 
            this.gbCrust.Controls.Add(this.rbThick);
            this.gbCrust.Controls.Add(this.rbThin);
            this.gbCrust.Location = new System.Drawing.Point(55, 308);
            this.gbCrust.Name = "gbCrust";
            this.gbCrust.Size = new System.Drawing.Size(188, 157);
            this.gbCrust.TabIndex = 1;
            this.gbCrust.TabStop = false;
            this.gbCrust.Text = "Crust Type";
            // 
            // rbThick
            // 
            this.rbThick.AutoSize = true;
            this.rbThick.Location = new System.Drawing.Point(43, 91);
            this.rbThick.Name = "rbThick";
            this.rbThick.Size = new System.Drawing.Size(94, 20);
            this.rbThick.TabIndex = 1;
            this.rbThick.TabStop = true;
            this.rbThick.Tag = "10";
            this.rbThick.Text = "Thick Crust";
            this.rbThick.UseVisualStyleBackColor = true;
            this.rbThick.CheckedChanged += new System.EventHandler(this.rbThick_CheckedChanged);
            // 
            // rbThin
            // 
            this.rbThin.AutoSize = true;
            this.rbThin.Checked = true;
            this.rbThin.Location = new System.Drawing.Point(43, 48);
            this.rbThin.Name = "rbThin";
            this.rbThin.Size = new System.Drawing.Size(87, 20);
            this.rbThin.TabIndex = 0;
            this.rbThin.TabStop = true;
            this.rbThin.Tag = "0";
            this.rbThin.Text = "Thin Crust";
            this.rbThin.UseVisualStyleBackColor = true;
            this.rbThin.CheckedChanged += new System.EventHandler(this.rbThin_CheckedChanged);
            // 
            // gbToppings
            // 
            this.gbToppings.Controls.Add(this.chkGreenPeppers);
            this.gbToppings.Controls.Add(this.chkOlives);
            this.gbToppings.Controls.Add(this.chkOnion);
            this.gbToppings.Controls.Add(this.chkTomatoes);
            this.gbToppings.Controls.Add(this.chkMushrooms);
            this.gbToppings.Controls.Add(this.chkExtraCheese);
            this.gbToppings.Location = new System.Drawing.Point(312, 91);
            this.gbToppings.Name = "gbToppings";
            this.gbToppings.Size = new System.Drawing.Size(297, 157);
            this.gbToppings.TabIndex = 2;
            this.gbToppings.TabStop = false;
            this.gbToppings.Text = "Toppings";
            // 
            // chkGreenPeppers
            // 
            this.chkGreenPeppers.AutoSize = true;
            this.chkGreenPeppers.Location = new System.Drawing.Point(170, 111);
            this.chkGreenPeppers.Name = "chkGreenPeppers";
            this.chkGreenPeppers.Size = new System.Drawing.Size(121, 20);
            this.chkGreenPeppers.TabIndex = 5;
            this.chkGreenPeppers.Tag = "5";
            this.chkGreenPeppers.Text = "Green Peppers";
            this.chkGreenPeppers.UseVisualStyleBackColor = true;
            this.chkGreenPeppers.CheckedChanged += new System.EventHandler(this.chkGreenPeppers_CheckedChanged);
            // 
            // chkOlives
            // 
            this.chkOlives.AutoSize = true;
            this.chkOlives.Location = new System.Drawing.Point(170, 73);
            this.chkOlives.Name = "chkOlives";
            this.chkOlives.Size = new System.Drawing.Size(67, 20);
            this.chkOlives.TabIndex = 4;
            this.chkOlives.Tag = "5";
            this.chkOlives.Text = "Olives";
            this.chkOlives.UseVisualStyleBackColor = true;
            this.chkOlives.CheckedChanged += new System.EventHandler(this.chkOlives_CheckedChanged);
            // 
            // chkOnion
            // 
            this.chkOnion.AutoSize = true;
            this.chkOnion.Location = new System.Drawing.Point(170, 36);
            this.chkOnion.Name = "chkOnion";
            this.chkOnion.Size = new System.Drawing.Size(64, 20);
            this.chkOnion.TabIndex = 3;
            this.chkOnion.Tag = "5";
            this.chkOnion.Text = "Onion";
            this.chkOnion.UseVisualStyleBackColor = true;
            this.chkOnion.CheckedChanged += new System.EventHandler(this.chkOnion_CheckedChanged);
            // 
            // chkTomatoes
            // 
            this.chkTomatoes.AutoSize = true;
            this.chkTomatoes.Location = new System.Drawing.Point(6, 112);
            this.chkTomatoes.Name = "chkTomatoes";
            this.chkTomatoes.Size = new System.Drawing.Size(91, 20);
            this.chkTomatoes.TabIndex = 2;
            this.chkTomatoes.Tag = "5";
            this.chkTomatoes.Text = "Tomatoes";
            this.chkTomatoes.UseVisualStyleBackColor = true;
            this.chkTomatoes.CheckedChanged += new System.EventHandler(this.chkTomatoes_CheckedChanged);
            // 
            // chkMushrooms
            // 
            this.chkMushrooms.AutoSize = true;
            this.chkMushrooms.Location = new System.Drawing.Point(6, 74);
            this.chkMushrooms.Name = "chkMushrooms";
            this.chkMushrooms.Size = new System.Drawing.Size(99, 20);
            this.chkMushrooms.TabIndex = 1;
            this.chkMushrooms.Tag = "5";
            this.chkMushrooms.Text = "Mushrooms";
            this.chkMushrooms.UseVisualStyleBackColor = true;
            this.chkMushrooms.CheckedChanged += new System.EventHandler(this.chkMushrooms_CheckedChanged);
            // 
            // chkExtraCheese
            // 
            this.chkExtraCheese.AutoSize = true;
            this.chkExtraCheese.Location = new System.Drawing.Point(6, 37);
            this.chkExtraCheese.Name = "chkExtraCheese";
            this.chkExtraCheese.Size = new System.Drawing.Size(109, 20);
            this.chkExtraCheese.TabIndex = 0;
            this.chkExtraCheese.Tag = "5";
            this.chkExtraCheese.Text = "Extra Cheese";
            this.chkExtraCheese.UseVisualStyleBackColor = true;
            this.chkExtraCheese.CheckedChanged += new System.EventHandler(this.chkExtraCheese_CheckedChanged);
            // 
            // gbOrderSummary
            // 
            this.gbOrderSummary.Controls.Add(this.inpTotalPrice);
            this.gbOrderSummary.Controls.Add(this.inpWhereToEat);
            this.gbOrderSummary.Controls.Add(this.inpCrustType);
            this.gbOrderSummary.Controls.Add(this.inpToppings);
            this.gbOrderSummary.Controls.Add(this.inpSize);
            this.gbOrderSummary.Controls.Add(this.txtToppings);
            this.gbOrderSummary.Controls.Add(this.txtTotalPrice);
            this.gbOrderSummary.Controls.Add(this.txtWhereToEat);
            this.gbOrderSummary.Controls.Add(this.txtCrustType);
            this.gbOrderSummary.Controls.Add(this.lbToppings);
            this.gbOrderSummary.Controls.Add(this.txtSize);
            this.gbOrderSummary.Location = new System.Drawing.Point(678, 91);
            this.gbOrderSummary.Name = "gbOrderSummary";
            this.gbOrderSummary.Size = new System.Drawing.Size(323, 364);
            this.gbOrderSummary.TabIndex = 2;
            this.gbOrderSummary.TabStop = false;
            this.gbOrderSummary.Text = "Order Summary";
            // 
            // inpTotalPrice
            // 
            this.inpTotalPrice.AutoSize = true;
            this.inpTotalPrice.Font = new System.Drawing.Font("Corbel", 25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.inpTotalPrice.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.inpTotalPrice.Location = new System.Drawing.Point(112, 283);
            this.inpTotalPrice.Name = "inpTotalPrice";
            this.inpTotalPrice.Size = new System.Drawing.Size(85, 51);
            this.inpTotalPrice.TabIndex = 10;
            this.inpTotalPrice.Text = "$30";
            // 
            // inpWhereToEat
            // 
            this.inpWhereToEat.AutoSize = true;
            this.inpWhereToEat.Location = new System.Drawing.Point(118, 217);
            this.inpWhereToEat.Name = "inpWhereToEat";
            this.inpWhereToEat.Size = new System.Drawing.Size(40, 16);
            this.inpWhereToEat.TabIndex = 9;
            this.inpWhereToEat.Text = "Eat In";
            // 
            // inpCrustType
            // 
            this.inpCrustType.AutoSize = true;
            this.inpCrustType.Location = new System.Drawing.Point(118, 156);
            this.inpCrustType.Name = "inpCrustType";
            this.inpCrustType.Size = new System.Drawing.Size(66, 16);
            this.inpCrustType.TabIndex = 8;
            this.inpCrustType.Text = "Thin Crust";
            // 
            // inpToppings
            // 
            this.inpToppings.AutoSize = true;
            this.inpToppings.Location = new System.Drawing.Point(72, 98);
            this.inpToppings.MaximumSize = new System.Drawing.Size(242, 61);
            this.inpToppings.Name = "inpToppings";
            this.inpToppings.Size = new System.Drawing.Size(86, 16);
            this.inpToppings.TabIndex = 7;
            this.inpToppings.Text = "No Toppings";
            // 
            // inpSize
            // 
            this.inpSize.AutoSize = true;
            this.inpSize.Location = new System.Drawing.Point(72, 36);
            this.inpSize.Name = "inpSize";
            this.inpSize.Size = new System.Drawing.Size(55, 16);
            this.inpSize.TabIndex = 6;
            this.inpSize.Text = "Medium";
            // 
            // txtToppings
            // 
            this.txtToppings.AutoSize = true;
            this.txtToppings.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtToppings.Location = new System.Drawing.Point(21, 73);
            this.txtToppings.Name = "txtToppings";
            this.txtToppings.Size = new System.Drawing.Size(77, 16);
            this.txtToppings.TabIndex = 5;
            this.txtToppings.Text = "Toppings:";
            // 
            // txtTotalPrice
            // 
            this.txtTotalPrice.AutoSize = true;
            this.txtTotalPrice.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtTotalPrice.Location = new System.Drawing.Point(22, 257);
            this.txtTotalPrice.Name = "txtTotalPrice";
            this.txtTotalPrice.Size = new System.Drawing.Size(87, 16);
            this.txtTotalPrice.TabIndex = 4;
            this.txtTotalPrice.Text = "Total Price:";
            // 
            // txtWhereToEat
            // 
            this.txtWhereToEat.AutoSize = true;
            this.txtWhereToEat.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtWhereToEat.Location = new System.Drawing.Point(22, 191);
            this.txtWhereToEat.Name = "txtWhereToEat";
            this.txtWhereToEat.Size = new System.Drawing.Size(100, 16);
            this.txtWhereToEat.TabIndex = 3;
            this.txtWhereToEat.Text = "Where to Eat:";
            // 
            // txtCrustType
            // 
            this.txtCrustType.AutoSize = true;
            this.txtCrustType.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtCrustType.Location = new System.Drawing.Point(22, 156);
            this.txtCrustType.Name = "txtCrustType";
            this.txtCrustType.Size = new System.Drawing.Size(86, 16);
            this.txtCrustType.TabIndex = 2;
            this.txtCrustType.Text = "Crust Type:";
            // 
            // lbToppings
            // 
            this.lbToppings.AutoSize = true;
            this.lbToppings.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbToppings.Location = new System.Drawing.Point(33, 77);
            this.lbToppings.Name = "lbToppings";
            this.lbToppings.Size = new System.Drawing.Size(0, 16);
            this.lbToppings.TabIndex = 1;
            // 
            // txtSize
            // 
            this.txtSize.AutoSize = true;
            this.txtSize.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtSize.Location = new System.Drawing.Point(21, 36);
            this.txtSize.Name = "txtSize";
            this.txtSize.Size = new System.Drawing.Size(45, 16);
            this.txtSize.TabIndex = 0;
            this.txtSize.Text = "Size: ";
            // 
            // btnOrderPizza
            // 
            this.btnOrderPizza.Location = new System.Drawing.Point(318, 420);
            this.btnOrderPizza.Name = "btnOrderPizza";
            this.btnOrderPizza.Size = new System.Drawing.Size(116, 35);
            this.btnOrderPizza.TabIndex = 3;
            this.btnOrderPizza.Text = "Order Pizza";
            this.btnOrderPizza.UseVisualStyleBackColor = true;
            this.btnOrderPizza.Click += new System.EventHandler(this.btnOrderPizza_Click);
            // 
            // btnResetForm
            // 
            this.btnResetForm.Location = new System.Drawing.Point(506, 420);
            this.btnResetForm.Name = "btnResetForm";
            this.btnResetForm.Size = new System.Drawing.Size(116, 35);
            this.btnResetForm.TabIndex = 4;
            this.btnResetForm.Text = "Reset  Form";
            this.btnResetForm.UseVisualStyleBackColor = true;
            this.btnResetForm.Click += new System.EventHandler(this.btnResetForm_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(308, 371);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(143, 20);
            this.label1.TabIndex = 5;
            this.label1.Text = "Number of Pizzas";
            // 
            // nudNumberOfPizzas
            // 
            this.nudNumberOfPizzas.Cursor = System.Windows.Forms.Cursors.Hand;
            this.nudNumberOfPizzas.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.nudNumberOfPizzas.Location = new System.Drawing.Point(476, 364);
            this.nudNumberOfPizzas.Maximum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.nudNumberOfPizzas.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.nudNumberOfPizzas.Name = "nudNumberOfPizzas";
            this.nudNumberOfPizzas.ReadOnly = true;
            this.nudNumberOfPizzas.Size = new System.Drawing.Size(133, 32);
            this.nudNumberOfPizzas.TabIndex = 6;
            this.nudNumberOfPizzas.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.nudNumberOfPizzas.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.nudNumberOfPizzas.ValueChanged += new System.EventHandler(this.nudNumberOfPizzas_ValueChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1023, 501);
            this.Controls.Add(this.nudNumberOfPizzas);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.btnResetForm);
            this.Controls.Add(this.btnOrderPizza);
            this.Controls.Add(this.gbWhereToEat);
            this.Controls.Add(this.gbCrust);
            this.Controls.Add(this.gbToppings);
            this.Controls.Add(this.gbOrderSummary);
            this.Controls.Add(this.gbSize);
            this.Controls.Add(this.Title);
            this.Name = "Form1";
            this.Text = "Pizza Order";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.gbSize.ResumeLayout(false);
            this.gbSize.PerformLayout();
            this.gbWhereToEat.ResumeLayout(false);
            this.gbWhereToEat.PerformLayout();
            this.gbCrust.ResumeLayout(false);
            this.gbCrust.PerformLayout();
            this.gbToppings.ResumeLayout(false);
            this.gbToppings.PerformLayout();
            this.gbOrderSummary.ResumeLayout(false);
            this.gbOrderSummary.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudNumberOfPizzas)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label Title;
        private System.Windows.Forms.GroupBox gbSize;
        private System.Windows.Forms.GroupBox gbWhereToEat;
        private System.Windows.Forms.GroupBox gbCrust;
        private System.Windows.Forms.RadioButton rbLarge;
        private System.Windows.Forms.RadioButton rbMedium;
        private System.Windows.Forms.RadioButton rbSmall;
        private System.Windows.Forms.RadioButton rbTakeOut;
        private System.Windows.Forms.RadioButton rbEatIn;
        private System.Windows.Forms.RadioButton rbThick;
        private System.Windows.Forms.RadioButton rbThin;
        private System.Windows.Forms.GroupBox gbToppings;
        private System.Windows.Forms.CheckBox chkGreenPeppers;
        private System.Windows.Forms.CheckBox chkOlives;
        private System.Windows.Forms.CheckBox chkOnion;
        private System.Windows.Forms.CheckBox chkTomatoes;
        private System.Windows.Forms.CheckBox chkMushrooms;
        private System.Windows.Forms.CheckBox chkExtraCheese;
        private System.Windows.Forms.GroupBox gbOrderSummary;
        private System.Windows.Forms.Label txtToppings;
        private System.Windows.Forms.Label txtTotalPrice;
        private System.Windows.Forms.Label txtWhereToEat;
        private System.Windows.Forms.Label txtCrustType;
        private System.Windows.Forms.Label lbToppings;
        private System.Windows.Forms.Label txtSize;
        private System.Windows.Forms.Label inpTotalPrice;
        private System.Windows.Forms.Label inpWhereToEat;
        private System.Windows.Forms.Label inpCrustType;
        private System.Windows.Forms.Label inpToppings;
        private System.Windows.Forms.Label inpSize;
        private System.Windows.Forms.Button btnOrderPizza;
        private System.Windows.Forms.Button btnResetForm;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown nudNumberOfPizzas;
    }
}

