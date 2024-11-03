using ContactsBusinessLayer;
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
    public partial class frmListContacts : Form
    {
        public frmListContacts()
        {
            InitializeComponent();
        }

        private void _RefreshContactsList()
        {
            dgvAllContacts.DataSource = clsContact.GetAllContacts();
        }

        private void frmListContacts_Load(object sender, EventArgs e)
        {
            _RefreshContactsList();
        }

        private void dgvAllContacts_CellContentDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            //  MessageBox.Show(dgvAllContacts.CurrentRow.Cells[0].Value.ToString());
        }

        private void editToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int ContactID = (int)dgvAllContacts.CurrentRow.Cells[0].Value;
            frmAddEditContacts frm = new frmAddEditContacts(ContactID);
            frm.ShowDialog();

            _RefreshContactsList();
        }

        private void deleteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int ContactID = (int)dgvAllContacts.CurrentRow.Cells[0].Value;
            if (MessageBox.Show("Are you sure you want to delete contact [" + ContactID + "]", "Confirm Delete", MessageBoxButtons.OKCancel) == DialogResult.OK)
            {
                if (clsContact.DeleteContact(ContactID))
                {
                    MessageBox.Show("Contact Deleted Successfully.");
                    _RefreshContactsList();
                }
                else
                    MessageBox.Show("Contact is not deleted.");
            }
        }

        private void btnAddNewContact_Click(object sender, EventArgs e)
        {
            frmAddEditContacts frm = new frmAddEditContacts(-1);
            frm.ShowDialog();
            _RefreshContactsList();
        }
    }
}
