using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InsertDataCode1
{
    public class Program
    {
        static string connectionString = "Server=.;Database=ContactsDB;User Id = sa; Password = 1234";

        public struct stContact
        {
            public string FirstName { set; get; }
            public string LastName { set; get; }
            public string Email { set; get; }
            public string Phone { set; get; }
            public string Address { set; get; }
            public int CountryID { set; get; } 
        }
        

        static void AddNewContact(stContact newContact)
        {
            SqlConnection connection = new SqlConnection(connectionString);

            string query = @"INSERT INTO Contacts
           (FirstName
           ,LastName
           ,Email
           ,Phone
           ,Address
           ,CountryID)
     VALUES
           (@FirstName
           ,@LastName
           ,@Email
           ,@Phone
           ,@Address
           ,@CountryID)";

            SqlCommand command = new SqlCommand(query, connection);
            command.Parameters.AddWithValue("@FirstName", newContact.FirstName);
            command.Parameters.AddWithValue("@LastName", newContact.LastName);
            command.Parameters.AddWithValue("@Email", newContact.Email);
            command.Parameters.AddWithValue("@Phone", newContact.Phone);
            command.Parameters.AddWithValue("@Address", newContact.Address);
            command.Parameters.AddWithValue("@CountryID", newContact.CountryID);

            try
            {
                connection.Open();
                int rowsAffected = command.ExecuteNonQuery();

                if (rowsAffected > 0)
                    Console.WriteLine("Record inserted successfully.");
                else
                    Console.WriteLine("Record insertion failed.");
            }

            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.ToString());
            }

            connection.Close();

        }

        static void AddNewContactAndGetID(stContact newContact)
        {
            SqlConnection connection = new SqlConnection(connectionString);

            string query = @"INSERT INTO Contacts
           (FirstName
           ,LastName
           ,Email
           ,Phone
           ,Address
           ,CountryID)
     VALUES
           (@FirstName
           ,@LastName
           ,@Email
           ,@Phone
           ,@Address
           ,@CountryID);

            SELECT SCOPE_IDENTITY();";

            SqlCommand command = new SqlCommand(query, connection);
            command.Parameters.AddWithValue("@FirstName", newContact.FirstName);
            command.Parameters.AddWithValue("@LastName", newContact.LastName);
            command.Parameters.AddWithValue("@Email", newContact.Email);
            command.Parameters.AddWithValue("@Phone", newContact.Phone);
            command.Parameters.AddWithValue("@Address", newContact.Address);
            command.Parameters.AddWithValue("@CountryID", newContact.CountryID);

            try
            {
                connection.Open();
                object result = command.ExecuteScalar();

                if (result != null && int.TryParse(result.ToString(), out int insertedID))
                    Console.WriteLine($"Newly inserted ID: {insertedID}");
                else
                    Console.WriteLine("Failed to retrieve inserted ID.");
            }

            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.ToString());
            }

            connection.Close();
        }
        
        static void Main(string[] args)
        {
            stContact contact = new stContact()
            {
                FirstName = "Laila",
                LastName = "Maher",
                Email = "m@example.com",
                Phone = "123456789",
                Address = "123 Main Street",
                CountryID = 1
            };

            // AddNewContact(contact);
            AddNewContactAndGetID(contact);

            Console.ReadKey();
        }
    }
}
