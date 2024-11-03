using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PizzaProject
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        void UpdateSize()
        {
            UpdateTotalPrice();

            if (rbSmall.Checked)
            {
                inpSize.Text = rbSmall.Text;
            }
            if (rbMedium.Checked)
            {
                inpSize.Text = rbMedium.Text;
            }
            if (rbLarge.Checked) 
            {
                inpSize.Text = rbLarge.Text;
            }
        }

        void UpdateCrust()
        {
            UpdateTotalPrice();

            if (rbThin.Checked) 
            {
                inpCrustType.Text = rbThin.Text;
                return;
            }

            if (rbThick.Checked)
            {
                inpCrustType.Text = rbThick.Text;
                return;
            }
        }

        void UpdateToppings()
        {
            UpdateTotalPrice();
            string sToppings = "";

            if (chkExtraCheese.Checked)
                sToppings = chkExtraCheese.Text;
            if (chkOnion.Checked)
                sToppings += ", " + chkOnion.Text;
            if (chkMushrooms.Checked)
                sToppings += ", " + chkMushrooms.Text;
            if (chkOlives.Checked)
                sToppings += ", " + chkOlives.Text;
            if (chkTomatoes.Checked)
                sToppings += ", " + chkTomatoes.Text;
            if (chkGreenPeppers.Checked)
                sToppings += ", " + chkGreenPeppers.Text;

            if (sToppings.StartsWith(","))
                sToppings = sToppings.Substring(1, sToppings.Length - 1).Trim();
            if (sToppings == "")
                sToppings = "No Toppings";

            inpToppings.Text = sToppings;
        }
        
        void UpdateWhereToEat()
        {
            if (rbEatIn.Checked)
            {
                inpWhereToEat.Text = rbEatIn.Text;
                return;
            }
            if (rbTakeOut.Checked)
            {
                inpWhereToEat.Text = rbTakeOut.Text;
            }
        }

        float GetSelectedSizePrice()
        {
            if (rbSmall.Checked)
                return Convert.ToSingle(rbSmall.Tag);
            else if (rbMedium.Checked)
                return Convert.ToSingle(rbMedium.Tag);
            else
                return Convert.ToSingle(rbLarge.Tag);
        }

        float CalculateToppingsPrice()
        {
            float ToppingsTotalPrice = 0;
            if (chkExtraCheese.Checked)
                ToppingsTotalPrice += Convert.ToSingle(chkExtraCheese.Tag);
            if (chkOnion.Checked)
                ToppingsTotalPrice += Convert.ToSingle(chkOnion.Tag);
            if (chkOlives.Checked)
                ToppingsTotalPrice += Convert.ToSingle(chkOlives.Tag);
            if (chkGreenPeppers.Checked)
                ToppingsTotalPrice += Convert.ToSingle(chkGreenPeppers.Tag);
            if (chkMushrooms.Checked)
                ToppingsTotalPrice += Convert.ToSingle(chkMushrooms.Tag);
            if (chkTomatoes.Checked)
                ToppingsTotalPrice += Convert.ToSingle(chkTomatoes.Tag);

            return ToppingsTotalPrice;
        }

        float GetSelectedCrustPrice()
        {
            if (rbThin.Checked)
                return Convert.ToSingle(rbThin.Tag);
            else
                return Convert.ToSingle(rbThick.Tag);
        }
        
        float CalculateTotalPrice()
        {
            return Convert.ToSingle(nudNumberOfPizzas.Value) * (GetSelectedSizePrice() + CalculateToppingsPrice() + GetSelectedCrustPrice());
        }

        void UpdateTotalPrice() 
        {
            inpTotalPrice.Text = "$" + CalculateTotalPrice().ToString();
        }

        void UpdateOrderSummary()
        {
            UpdateSize();
            UpdateToppings();
            UpdateCrust();
            UpdateWhereToEat();
            UpdateTotalPrice();
        }

        private void rbSmall_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }

        private void rbMedium_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }

        private void rbLarge_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }

        private void chkExtraCheese_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
            
        }

        private void chkMushrooms_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chkTomatoes_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chkOnion_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chkOlives_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chkGreenPeppers_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void rbThin_CheckedChanged(object sender, EventArgs e)
        {
            UpdateCrust();
        }

        private void rbThick_CheckedChanged(object sender, EventArgs e)
        {
            UpdateCrust();
        }

        private void rbEatIn_CheckedChanged(object sender, EventArgs e)
        {
            if (rbEatIn.Checked == true)
            {
                inpWhereToEat.Text = rbEatIn.Text;
            }
        }

        private void rbTakeOut_CheckedChanged(object sender, EventArgs e)
        {
            if (rbTakeOut.Checked == true)
            {
                inpWhereToEat.Text = rbTakeOut.Text;
            }
        }

        private void btnOrderPizza_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Confirm Order", "Confirm", MessageBoxButtons.OKCancel, MessageBoxIcon.Question, MessageBoxDefaultButton.Button2) == DialogResult.OK)
            {
                MessageBox.Show("Order Placed Successfully", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                btnOrderPizza.Enabled = false;
                gbCrust.Enabled = false;
                gbSize.Enabled = false;
                gbToppings.Enabled = false;
                gbWhereToEat.Enabled = false;
                nudNumberOfPizzas.Enabled = false;
                label1.Enabled = false;
            }
            else

                MessageBox.Show("Update your order", "Update",
                    MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
        }

        private void btnResetForm_Click(object sender, EventArgs e)
        {
            gbCrust.Enabled = true;
            gbSize.Enabled = true;
            gbToppings.Enabled = true;
            gbWhereToEat.Enabled = true;

            rbMedium.Checked = true;

            chkExtraCheese.Checked = false;
            chkOlives.Checked = false;
            chkOnion.Checked = false;
            chkMushrooms.Checked = false;
            chkTomatoes.Checked = false;
            chkGreenPeppers.Checked = false;

            rbThin.Checked = true;

            rbEatIn.Checked = true;

            btnOrderPizza.Enabled = true;

            nudNumberOfPizzas.Value = 1;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            UpdateOrderSummary();
        }

        private void nudNumberOfPizzas_ValueChanged(object sender, EventArgs e)
        {
            UpdateTotalPrice();
        }
    }
}
