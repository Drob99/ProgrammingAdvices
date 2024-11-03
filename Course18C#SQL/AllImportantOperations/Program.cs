using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AllImportantOperations
{
    internal class Program
    {
        // This is common in all operations. You will always need this line to establish a connection with your database server.
        static string connectionString = "Server=.;Database = ContactsDB; User ID = sa; Password = 0553481128obh";


        // Part 1 : Retrieve Data
        // This method uses Execute Reader to print all the contacts in the Contacts table.
        static void PrintAllContacts()
        {
            // establish a connection
            SqlConnection connection = new SqlConnection(connectionString);

            // The query you usually write in the SQL server.
            string query = "Select * from Contacts";

            // Fastest way to make a sql command
            SqlCommand command = new SqlCommand(query, connection);

            // The try is very important in case an exception occurs.
            try
            {
                // open the connection. Don't forget to close it later because there is a maximum of connections called connection pools.
                connection.Open();
                SqlDataReader reader = command.ExecuteReader(); // more than 1 row

                // print all columns until nothing is left.
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

        static void PrintAllContactsWithFirstName(string FirstName)
        {
            SqlConnection connection = new SqlConnection(connectionString);

            string query = "Select * from Contacts where FirstName = @FirstName";
            // normal concatenation has its own problems.

            SqlCommand command = new SqlCommand(query, connection);
            command.Parameters.AddWithValue("@FirstName", FirstName);

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

        static void PrintAllContactsWithFirstNameAndCountry(string FirstName, int CountryID)
        {
            SqlConnection connection = new SqlConnection(connectionString);

            string query = "Select * from Contacts where FirstName = @FirstName and CountryID = @CountryID";
            // normal concatenation has its own problems.

            SqlCommand command = new SqlCommand(query, connection);
            command.Parameters.AddWithValue("@FirstName", FirstName);
            command.Parameters.AddWithValue("@CountryID", CountryID);

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

        // Execute Scalar gets value of first row of first column after executing all queries.
        static String GetFirstName(int ContactID)
        {
            string FirstName = "";
            SqlConnection connection = new SqlConnection(connectionString);

            string query = "Select FirstName from Contacts where ContactID = @ContactID";
            // normal concatenation has its own problems.

            SqlCommand command = new SqlCommand(query, connection);
            command.Parameters.AddWithValue("@ContactID", ContactID);

            try
            {
                connection.Open();

                object result = command.ExecuteScalar();

                if (result != null)
                    FirstName = result.ToString();

                connection.Close();

            }

            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.ToString());
            }

            return FirstName;
        }

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
                    ContactInfo.ID = (int)reader["ContactID"];
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


        // Part 2: Insert Data -> Execute NonQuery.
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

        // Part 3: Update
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


        // Part 4: Delete
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

        // IN operator
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

        public struct stContact
        {
            public int ID { get; set; }
            public string FirstName { get; set; }

            public string LastName { get; set; }

            public string Email { get; set; }
            public string Phone { get; set; }
            public string Address { get; set; }

            public int CountryID { get; set; }
        }
        
        
        static void Main(string[] args)
        {
        }
    }
}
