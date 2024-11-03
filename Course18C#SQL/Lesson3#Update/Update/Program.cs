using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Update
{
    public class Program
    {
        static string connectionString = "Server=.;Database=ContactsDB;User ID = sa;Password=0553481128obh";

        // string normalString = "Delete from Contacts\nWHERE ContactID = @ContactID";
        // string verbatimString = @"Delete from Contacts
        // WHERE ContactID = @ContactID";

        public struct stContact
        {
            public string FirstName { get; set; }
            public string LastName { get; set; }

            public string Email { get; set; }

            public string Phone { get; set; }

            public string Address { get; set; }

            public int CountryID { get; set; }
        }

        static public void UpdateContact(int ContactID, stContact contact)
        {
            SqlConnection connection = new SqlConnection(connectionString);

            string query = @"UPDATE Contacts
            SET
            FirstName = @FirstName
           ,LastName = @LastName
           ,Email = @Email
           ,Phone = @Phone
           ,Address = @Address
           ,CountryID = @CountryID
            WHERE ContactID = @ContactID";

            SqlCommand command = new SqlCommand(query, connection);

            command.Parameters.AddWithValue("@ContactID", ContactID);
            command.Parameters.AddWithValue("@FirstName", contact.FirstName);
            command.Parameters.AddWithValue("@LastName", contact.LastName);
            command.Parameters.AddWithValue("@Email", contact.Email);
            command.Parameters.AddWithValue("@Phone", contact.Phone);
            command.Parameters.AddWithValue("@Address", contact.Address);
            command.Parameters.AddWithValue("@CountryID", contact.CountryID);

            try
            {
                connection.Open();
                int rowsAffected = command.ExecuteNonQuery();

                if (rowsAffected > 0)
                    Console.WriteLine($"Record Update successfully.");
                else
                    Console.WriteLine("Record Update Failed.");
            }

            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.Message);
            }

            connection.Close();
        }

        static void Main(string[] args)
        {
            stContact ContactInfo = new stContact()
            {
                FirstName = "Mahmoud",
                LastName = "Ghadban",
                Email = "m@example.com",
                Phone = "123456789",
                Address = "123 Main Street",
                CountryID = 1
            };

            UpdateContact(1, ContactInfo);

            Console.ReadKey();
        }
    }
}
