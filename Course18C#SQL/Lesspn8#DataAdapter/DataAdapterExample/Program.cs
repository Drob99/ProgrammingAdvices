using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.SqlClient;

namespace DataAdapterExample
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string connectionString = "Server=.;Database=HR_Database;User Id=sa;Password=1234";

            // create new DataSet
            DataSet dataSet = new DataSet();

            // create new DataAdapter with a SELECT Query and connection string
            string query = "SELECT * FROM Employees;";
            SqlDataAdapter dataAdapter = new SqlDataAdapter(query, connectionString);

            // open connection
            SqlConnection connection = new SqlConnection(connectionString);
            connection.Open();

            // set the select command of dataAdapter to connection
            dataAdapter.SelectCommand.Connection = connection;

            // Fill the DataSet with data from data source
            dataAdapter.Fill(dataSet, "Employees");

            connection.Close();

            // Display data from DataSet
            DataTable customersTable = dataSet.Tables["Employees"];
            foreach (DataRow row in customersTable.Rows)
            {
                Console.WriteLine($"Customer ID: {row["ID"], -4}| Name: {row["FirstName"], -11}| LastName: {row["LastName"], -15}");
            }

            // Make Changes to DataSet

            // Update data source
            connection.Open();

            // set update command
            dataAdapter.UpdateCommand.Connection = connection;

            // update data source
            dataAdapter.Update(dataSet, "Employees");

            connection.Close();

            Console.ReadKey();
        }
    }
}
