using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FindSingleContact
{
    public class Program
    {
        static string connectionString = "Server=.;Database = ContactsDB; User ID = sa; Password = 1234";

        static bool FindContactByID(int ContactID, ref stContact ContactInfo)
        {
            bool isFound = false;
            SqlConnection connection = new SqlConnection(connectionString);

            string query = "Select * from Contacts where ContactID = @ContactID";
            

            SqlCommand command = new SqlCommand(query, connection);
            command.Parameters.AddWithValue("@ContactID", ContactID);

            try
            {
                connection.Open();

                SqlDataReader reader = command.ExecuteReader();

                if (reader.Read())
                {
                    isFound = true;
                    ContactInfo.ID =  (int)reader["ContactID"];
                    ContactInfo.FirstName = (string)reader["FirstName"];
                    ContactInfo.LastName = (string)reader["LastName"];
                    ContactInfo.Email = (string)reader["Email"];
                    ContactInfo.Phone = (string)reader["Phone"];
                    ContactInfo.Address = (string)reader["Address"];
                    ContactInfo.CountryID = (int)reader["CountryID"];
                }

                reader.Close();
                connection.Close();

            }

            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.ToString());
            }

            return isFound;
        }

        public struct stContact
        {
            public int ID {  get; set; }
            public string FirstName { get; set; }

            public string LastName { get; set; }

            public string Email { get; set; }
            public string Phone { get; set; }
            public string Address { get; set; }

            public int CountryID { get; set; }
        }
        static void Main(string[] args)
        {
            stContact ContactInfo = new stContact();

            if (FindContactByID(1, ref ContactInfo))
            {
                Console.WriteLine($"\nContact ID: {ContactInfo.ID}");
                Console.WriteLine($"\nName: {ContactInfo.FirstName} {ContactInfo.LastName}");
                Console.WriteLine($"\nEmail: {ContactInfo.Email}");
                Console.WriteLine($"\nPhone: {ContactInfo.Phone}");
                Console.WriteLine($"\nAddress: {ContactInfo.Address}");
                Console.WriteLine($"\nCountry ID: {ContactInfo.CountryID}");
            }
            else
            {
                Console.WriteLine("Contact is not found");
            }

            Console.ReadKey();
        }
    }
}
