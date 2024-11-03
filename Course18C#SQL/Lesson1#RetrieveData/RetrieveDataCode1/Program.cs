using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Net;
using System.Data.SqlClient;

namespace RetrieveDataCode1
{
    public class Program
    {
        static string connectionString = "Server=.;Database=ContactsDB;User Id =sa;Password=0553481128obh"; // Replace user and password

        static void PrintAllContacts()
        {
            SqlConnection connection = new SqlConnection(connectionString);

            string query = "Select * from Contacts";

            SqlCommand command = new SqlCommand(query, connection);

            try
            {
                connection.Open();
                SqlDataReader reader = command.ExecuteReader(); // more than 1 row

                while (reader.Read())
                {
                    int contactID = (int)reader["ContactID"];
                    string firstName = (string)reader["FirstName"];
                    string lastName = (string)reader["LastName"];
                    string email = (string)reader["Email"];
                    string phone = (string)reader["Phone"];
                    string address = (string)reader["Address"];
                    int countryID = (int)reader["CountryID"];

                    Console.WriteLine($"Contact ID : {contactID}");
                    Console.WriteLine($"Name : {firstName} {lastName}");
                    Console.WriteLine($"Email : {email}");
                    Console.WriteLine($"Phone : {phone}");
                    Console.WriteLine($"Address : {address}");
                    Console.WriteLine($"Country ID : {countryID}");
                    Console.WriteLine();
                }

                reader.Close();
                connection.Close(); // costly. You have a limited number of connections called connection pools.
            }

            catch (Exception ex) 
            { 
                Console.WriteLine("Error: " + ex.Message);
            }
        }
        static void Main(string[] args)
        {
            PrintAllContacts();

            Console.ReadKey();
        }
    }
}
