using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Delete
{
    public class Program
    {
        static string connectionString = "Server=.;Database=ContactsDB;User Id = sa; Password = 0553481128obh";

        public struct stContact
        {
            public string FirstName { set; get; }
            public string LastName { set; get; }
            public string Email { set; get; }
            public string Phone { set; get; }
            public string Address { set; get; }
            public int CountryID { set; get; }
        }

        static public void DeleteContact(int ContactID)
        {
            SqlConnection connection = new SqlConnection(connectionString);

            string query = @"Delete from Contacts
            WHERE ContactID = @ContactID";

            SqlCommand command = new SqlCommand(query, connection);

            command.Parameters.AddWithValue("@ContactID", ContactID);

            try
            {
                connection.Open();
                int rowsAffected = command.ExecuteNonQuery();

                if (rowsAffected > 0)
                    Console.WriteLine($"Record Delete successfully.");
                else
                    Console.WriteLine("Record Delete Failed.");
            }

            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.Message);
            }

            connection.Close();
        }

        static public void DeleteContacts(string ContactIDs)
        {
            SqlConnection connection = new SqlConnection(connectionString);

            string query = @"Delete from Contacts
            WHERE ContactID in (" + ContactIDs + ")";

            SqlCommand command = new SqlCommand(query, connection);

            try
            {
                connection.Open();
                int rowsAffected = command.ExecuteNonQuery();

                if (rowsAffected > 0)
                    Console.WriteLine($"Records Delete successfully.");
                else
                    Console.WriteLine("Records Delete Failed.");
            }

            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.Message);
            }

            connection.Close();
        }
        public static void Main(string[] args)
        {
            // DeleteContact(7);

            DeleteContacts("2, 3, 4");

            Console.ReadKey();
        }
    }
}
