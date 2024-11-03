﻿using ContactsBusinessLayer;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ContactsWinForms
{
    public partial class frmAddEditContacts : Form
    {
        public enum enMode { AddNew, Update};
        private enMode _Mode;

        int _ContactID;
        clsContact _Contact;

        public frmAddEditContacts(int ContactID)
        {
            InitializeComponent();

            _ContactID = ContactID;

            _Mode = (_ContactID == -1) ? enMode.AddNew : enMode.Update;
        }

        private void _FillCountriesInComboBox()
        {
            DataTable dtCountries = clsCountry.GetAllCountries();
            foreach (DataRow row in  dtCountries.Rows) 
            {
                cbCountry.Items.Add(row["CountryName"]);
            }
        }

        private void _LoadData()
        {
            _FillCountriesInComboBox();
            cbCountry.SelectedIndex = 0;

            if (_Mode == enMode.AddNew) 
            {
                lblMode.Text = "Add New Contact";
                _Contact = new clsContact();
                return;
            }

            _Contact = clsContact.Find(_ContactID);

            if (_Contact == null)
            {
                MessageBox.Show("This form will be closed because No Contact with this ID found");
                this.Close();

                return;
            }

            lblMode.Text = "Edit Contact ID = " + _ContactID;
            lblContactID.Text = _Contact.ID.ToString();
            txtFirstName.Text = _Contact.FirstName;
            txtLastName.Text = _Contact.LastName;
            txtEmail.Text = _Contact.Email;
            txtPhone.Text = _Contact.Phone;
            txtAddress.Text = _Contact.Address;
            dtpDateOfBirth.Value = _Contact.DateOfBirth;

            if (_Contact.ImagePath != "")
            {
                try
                {
                    pictureBox1.Load(_Contact.ImagePath);
                }
                catch (Exception ex) 
                {
                    pictureBox1.ImageLocation = null;
                }
            }

            llRemoveImage.Visible = (_Contact.ImagePath != "");

            cbCountry.SelectedIndex = cbCountry.FindString(clsCountry.Find(_Contact.CountryID).Name);
        }

        private void frmAddEditContacts_Load(object sender, EventArgs e)
        {
            _LoadData();
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            int CountryID = clsCountry.Find(cbCountry.Text).ID;

            _Contact.FirstName = txtFirstName.Text;
            _Contact.LastName = txtLastName.Text;
            _Contact.Email = txtEmail.Text;
            _Contact.Phone = txtPhone.Text;
            _Contact.Address = txtAddress.Text;
            _Contact.DateOfBirth = dtpDateOfBirth.Value;
            _Contact.CountryID = CountryID;

            if (pictureBox1.ImageLocation != null)
                _Contact.ImagePath = pictureBox1.ImageLocation;
            else
                _Contact.ImagePath = "";

            if (_Contact.Save())
                MessageBox.Show("Data Saved Successfully.");
            else
                MessageBox.Show("Error: Data Is not Saved Successfully.");

            _Mode = enMode.Update;
            lblMode.Text = "Edit Contact ID = " + _Contact.ID.ToString();
            lblContactID.Text = _Contact.ID.ToString();

        }

        struct CountryItem
        {
            public string Text;
            public int Value;
            public CountryItem(string Text, int Value)
            {
                this.Text = Text;
                this.Value = Value;
            }
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void llOpenFileDialog_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            openFileDialog1.Filter = "Image Files|*.jpg;*.jpeg;*.png;*.gif;*.bmp";
            openFileDialog1.FilterIndex = 1;
            openFileDialog1.RestoreDirectory = true;

            if(openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                string selectedFilePath = openFileDialog1.FileName;

                pictureBox1.Load(selectedFilePath);
            }
        }

        private void llRemoveImage_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            pictureBox1.ImageLocation = null;
            llRemoveImage.Visible = false;
        }
    }
}
