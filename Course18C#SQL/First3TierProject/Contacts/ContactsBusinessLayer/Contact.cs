using System;
using System.Data;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ContactsDataAccessLayer;

namespace ContactsBusinessLayer
{
    public class clsContact
    {
        public enum enMode { AddNew, Update};
        public enMode Mode = enMode.AddNew;

        public int ID {  get; set; }
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string Email { get; set; }
        public string Phone { get; set; }
        public string Address { get; set; }
        public DateTime DateOfBirth { get; set; }
        public string ImagePath { get; set; }
        public int CountryID { get; set; }

        public clsContact()
        {
            this.ID = -1;
            this.FirstName = "";
            this.LastName = "";
            this.Email = "";
            this.Phone = "";
            this.Address = "";
            this.DateOfBirth = DateTime.Now;
            this.CountryID = -1;
            this.ImagePath = "";

            Mode = enMode.AddNew;
        }

        private clsContact(int ID, string FirstName, string LastName,
            string Email, string Phone, string Address, DateTime DateOfBirth, string ImagePath, int CountryID)
        {
            this.ID = ID;
            this.FirstName = FirstName;
            this.LastName = LastName;
            this.Email = Email;
            this.Phone = Phone;
            this.Address = Address;
            this.DateOfBirth = DateOfBirth;
            this.ImagePath = ImagePath;
            this.CountryID = CountryID;

            Mode = enMode.Update;
        }


        private bool _AddNewContact()
        {
            // call Data Access Layer
            this.ID = clsContactDataAccess.AddNewContact(this.FirstName, this.LastName, this.Email, 
                this.Phone, this.Address, this.DateOfBirth, this.ImagePath, this.CountryID);

            return (this.ID != -1);
        }

        private bool _UpdateContact()
        {
            return clsContactDataAccess.UpdateContact(this.ID, this.FirstName, this.LastName, this.Email,
            this.Phone, this.Address, this.DateOfBirth, this.ImagePath, this.CountryID);
        }
        
        public static clsContact Find(int ID)
        {
            string FirstName = "", LastName = "", Email = "", Phone = "", Address = "", ImagePath = "";
            DateTime DateOfBirth = DateTime.Now;
            int CountryID = -1;

            if (clsContactDataAccess.GetContactInfoByID(ID, ref FirstName, ref LastName, ref Email,
                ref Phone, ref Address, ref DateOfBirth, ref CountryID, ref ImagePath))
                return new clsContact(ID, FirstName, LastName, Email, Phone, Address, DateOfBirth, ImagePath, CountryID);
            else
                return null;
        }
    
        public static bool DeleteContact(int ID)
        {
            return clsContactDataAccess.DeleteContact(ID);
        }
        
        public bool Save()
        {
            switch (Mode)
            {
                case enMode.AddNew:
                    if(_AddNewContact())
                    {
                        Mode = enMode.Update;
                        return true;
                    }
                    else
                        return false;

                case enMode.Update:
                    return _UpdateContact();
            }
            return false;
        }
    
        public static DataTable GetAllContacts()
        {
            return clsContactDataAccess.GetAllContacts();
        }
    
        public static bool IsContactExist(int ID)
        {
            return clsContactDataAccess.IsContactExist(ID);
        }

    }
}
