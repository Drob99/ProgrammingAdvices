using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RetrieveSingleValue
{
    public class Program
    {
        static string connectionString = "Server=.;Database = ContactsDB; User ID = sa; Password = 0553481128obh";

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
        static void Main(string[] args)
        {
            Console.WriteLine(GetFirstName(1));
            Console.ReadKey();
        }
    }
}
