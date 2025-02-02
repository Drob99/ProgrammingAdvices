using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParametrizedQueryWithLike
{
    public class Program
    {
        static string connectionString = "Server=.;Database=ContactsDB;User ID = sa; Password =1234";

        static void SearchContactsStartingWith(string StartsWith)
        {
            SqlConnection connection = new SqlConnection(connectionString);

            string query = "Select * from Contacts where FirstName like '' + @StartsWith + '%'";
            // normal concatenation has its own problems.

            SqlCommand command = new SqlCommand(query, connection);
            command.Parameters.AddWithValue("@StartsWith", StartsWith);

            try
            {
                connection.Open();

                SqlDataReader reader = command.ExecuteReader();

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
                connection.Close();

            }

            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.ToString());
            }
        }

        static void SearchContactsEndingWith(string EndsWith)
        {
            SqlConnection connection = new SqlConnection(connectionString);

            string query = "Select * from Contacts where FirstName like '%' + @EndsWith + ''";
            // normal concatenation has its own problems.

            SqlCommand command = new SqlCommand(query, connection);
            command.Parameters.AddWithValue("@EndsWith", EndsWith);

            try
            {
                connection.Open();

                SqlDataReader reader = command.ExecuteReader();

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
                connection.Close();

            }

            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.ToString());
            }
        }

        static void SearchContactsContaining(string Contains)
        {
            SqlConnection connection = new SqlConnection(connectionString);

            string query = "Select * from Contacts where FirstName like '%' +  @Contains + '%'";
            // normal concatenation has its own problems.

            SqlCommand command = new SqlCommand(query, connection);
            command.Parameters.AddWithValue("@Contains", Contains);

            try
            {
                connection.Open();

                SqlDataReader reader = command.ExecuteReader();

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
                connection.Close();

            }

            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.ToString());
            }
        }

        static void Main(string[] args)
        {
            Console.WriteLine("---------------Contacts starting with 'j'");

            SearchContactsStartingWith("j");

            Console.WriteLine("---------------Contacts ending with 'ne'");

            SearchContactsEndingWith("ne");

            Console.WriteLine("---------------Contacts conatining 'ae'");

            SearchContactsContaining("ae");

            Console.ReadKey();
        }
    }
}
