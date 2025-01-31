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
        static string connectionString = "Server=.;Database=ContactsDB;User Id =sa;Password=1234"; // Replace user and password

        static void PrintAllContacts()
        {
            // Create a connection with the DB server using the connection string
            SqlConnection connection = new SqlConnection(connectionString);

            // Write your SQL query
            string query = "Select * from Contacts";

            // Execute your query via your connection
            SqlCommand command = new SqlCommand(query, connection);

            // Always, use try and catch before dealing with databases.
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
