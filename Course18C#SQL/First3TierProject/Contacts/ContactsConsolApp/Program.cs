using System;
using System.Data;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ContactsBusinessLayer;

namespace ContactsConsolApp
{
    internal class Program
    {
        static void testFindContact(int ID)
        {
            clsContact Contact1 = clsContact.Find(ID);

            if (Contact1 != null)
            {
                Console.WriteLine(Contact1.FirstName + " " + Contact1.LastName);
                Console.WriteLine(Contact1.Email);
                Console.WriteLine(Contact1.Phone);
                Console.WriteLine(Contact1.Address);
                Console.WriteLine(Contact1.DateOfBirth);
                Console.WriteLine(Contact1.CountryID);
                Console.WriteLine(Contact1.ImagePath);
            }

            else
                Console.WriteLine("Contact [" + ID + "] Not found!");
        }
        
        static void testAddNewContact()
        {
            clsContact Contact1 = new clsContact();

            Contact1.FirstName = "Abdulrahman";
            Contact1.LastName = "Chaabouni";
            Contact1.Email = "A@a.com";
            Contact1.Phone = "010010";
            Contact1.Address = "address1";
            Contact1.DateOfBirth = new DateTime(2002, 11, 6, 10, 30, 0);
            Contact1.CountryID = 1;
            Contact1.ImagePath = "";

            if (Contact1.Save())
            {
                Console.WriteLine("Contact Added Successfully with id = " + Contact1.ID);
            }
        }

        static void testUpdateContact(int ID)
        {
            clsContact Contact1 = clsContact.Find(ID);
            if (Contact1 == null)
            {
                Console.WriteLine("The contact you want to update is not found.");
                return;
            }

            Contact1.FirstName = "Abdullah";
            Contact1.LastName = "Sherif";
            Contact1.Email = "A@a.com";
            Contact1.Phone = "32222";
            Contact1.Address = "222";
            Contact1.DateOfBirth = new DateTime(1977, 11, 6, 10, 30, 0);
            Contact1.CountryID = 1;
            Contact1.ImagePath = "";

            if (Contact1.Save())
            {
                Console.WriteLine("Contact Updated Successfully");
            }
        }

        static void testDeleteContact(int ID)
        {
            if (!clsContact.IsContactExist(ID))
            {
                Console.WriteLine($"The contact with ID [{ID}] is not found.");
                return;
            }

            if (clsContact.DeleteContact(ID))
                Console.WriteLine("Record Deleted Succesfully.");
            else
                Console.WriteLine("Failed to delete contact.");
        }

        static void ListContacts()
        {
            DataTable dataTable = clsContact.GetAllContacts();

            Console.WriteLine("Contacts Data");

            foreach (DataRow row in dataTable.Rows)
            {
                Console.WriteLine($"{row["ContactID"]}: {row["FirstName"]} {row["LastName"]}");   
            }
        }

        static void testIsContactExist(int ID)
        {
            if (clsContact.IsContactExist(ID))
                Console.WriteLine("Yes, Contact [" + ID + "] Exists.");

            else
                Console.WriteLine("No, Contact [" + ID + "] Does Not Exist!");
        }

        // Countries Program

        static void testFindCountry(int ID)
        {
            clsCountry Country1 = clsCountry.Find(ID);

            if (Country1 != null)
            {
                Console.WriteLine("Country found with ID.");
                Console.WriteLine($"{Country1.Name}");
                Console.WriteLine(Country1.Code);
                Console.WriteLine(Country1.PhoneCode);
            }
            else
                Console.WriteLine("Country [" + ID + "] Not found!");
        }

        static void testFindCountry(string Name)
        {
            clsCountry Country1 = clsCountry.Find(Name);

            if (Country1 != null)
                Console.WriteLine("Country Found with name: " + Country1.ID + " " + Country1.Name + " " + Country1.Code + " " + Country1.PhoneCode);
            else
                Console.WriteLine("Country [" + Name + "] Not found!");
        }

        static void testAddNewCountry()
        {
            clsCountry Country1 = new clsCountry();

            Country1.Name = "Egypt";
            Country1.Code = "+20";
            Country1.PhoneCode = "+20";

            if (Country1.Save())
            {
                Console.WriteLine("Country Added Successfully with id = " + Country1.ID);
            }
        }

        static void testUpdateCountry(int ID)
        {
            clsCountry Country1 = clsCountry.Find(ID);

            if (Country1 == null)
            {
                Console.WriteLine("Country you want to update is Not found.");
                return;
            }

            Country1.Name = "Saudi Arabia";
            Country1.Code = "+30";
            Country1.PhoneCode = "966";

            if (Country1.Save())
            {
                Console.WriteLine("Country Updated Successfully");
            }
        }

        static void testDeleteCountry(int ID)
        {
            if (!clsCountry.IsCountryExist(ID))
            {
                Console.WriteLine($"The country with ID [{ID}] is not found.");
                return;
            }

            if (clsCountry.DeleteCountry(ID))
                Console.WriteLine("Record Deleted Succesfully.");
            else
                Console.WriteLine("Failed to delete country.");
        }

        static void ListCountries()
        {
            DataTable dataTable = clsCountry.GetAllCountries();

            Console.WriteLine("Countries Data");

            foreach (DataRow row in dataTable.Rows)
            {
                Console.WriteLine($"{row["CountryID"]}: {row["CountryName"]} {row["Code"]} {row["PhoneCode"]}");
            }
        }

        static void testIsCountryExist(int ID)
        {
            if (clsCountry.IsCountryExist(ID))
                Console.WriteLine("Yes, Country [" + ID + "] Exists.");

            else
                Console.WriteLine("No, Country [" + ID + "] Does Not Exist!");
        }

        static void testIsCountryExist(string Name)
        {
            if (clsCountry.IsCountryExist(Name))
                Console.WriteLine("Yes, Country [" + Name + "] Exists.");

            else
                Console.WriteLine("No, Country [" + Name + "] Does Not Exist!");
        }

        static void Main(string[] args)
        {
            // testFindContact(20);

            // testAddNewContact();

            // testUpdateContact(8);

            // testDeleteContact(60); // static method not object wise

            // ListContacts();

            // testIsContactExist(20);


            // testFindCountry(1);

            // testFindCountry("Germany");

            // testAddNewCountry();

            // testUpdateCountry(11);

            // testDeleteCountry(11); // static method not object wise

            // ListCountries();

            //testIsCountryExist(15);

            //testIsCountryExist("United Kingdom");
            //testIsCountryExist("Egypt");

            Console.ReadKey();
        }
    }
}
