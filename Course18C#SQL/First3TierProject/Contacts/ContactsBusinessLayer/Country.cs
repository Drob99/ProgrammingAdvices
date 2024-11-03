using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ContactsDataAccessLayer;

namespace ContactsBusinessLayer
{
    public class clsCountry
    {
        public enum enMode { AddNew, Update };
        public enMode Mode = enMode.AddNew;

        public int ID { get; set; }
        public string Name { get; set; }

        public string Code { get; set; }

        public string PhoneCode { get; set; }

        public clsCountry()
        {
            this.ID = -1;
            this.Name = "";
            this.Code = "";
            this.PhoneCode = "";

            Mode = enMode.AddNew;
        }

        private clsCountry(int ID, string Name, string Code, string PhoneCode)
        {
            this.ID = ID;
            this.Name = Name;
            this.Code = Code;
            this.PhoneCode = PhoneCode;

            Mode = enMode.Update;
        }


        private bool _AddNewCountry()
        {
            // call Data Access Layer
            this.ID = clsCountryDataAccess.AddNewCountry(this.Name, this.Code, this.PhoneCode);

            return (this.ID != -1);
        }

        private bool _UpdateCountry()
        {
            return clsCountryDataAccess.UpdateCountry(this.ID, this.Name, this.Code, this.PhoneCode);
        }

        public static clsCountry Find(int ID)
        {
            string Name = "";
            string Code = "";
            string PhoneCode = "";

            if (clsCountryDataAccess.GetCountryInfoByID(ID, ref Name, ref Code, ref PhoneCode))
                return new clsCountry(ID, Name, Code, PhoneCode);
            else
                return null;
        }

        public static clsCountry Find(string Name)
        {
            int ID = -1;
            string Code = "";
            string PhoneCode = "";

            if (clsCountryDataAccess.GetCountryInfoByName(ref ID, Name, ref Code, ref PhoneCode))
                return new clsCountry(ID, Name, Code, PhoneCode);
            else
                return null;
        }

        public static bool DeleteCountry(int ID)
        {
            return clsCountryDataAccess.DeleteCountry(ID);
        }

        public bool Save()
        {
            switch (Mode)
            {
                case enMode.AddNew:
                    if (_AddNewCountry())
                    {
                        Mode = enMode.Update;
                        return true;
                    }
                    else
                        return false;

                case enMode.Update:
                    return _UpdateCountry();
            }
            return false;
        }

        public static DataTable GetAllCountries()
        {
            return clsCountryDataAccess.GetAllCountries();
        }

        public static bool IsCountryExist(int ID)
        {
            return clsCountryDataAccess.IsCountryExist(ID);
        }
    
        public static bool IsCountryExist(string Name)
        {
            return clsCountryDataAccess.IsCountryExist(Name);
        }
    
    }
}
