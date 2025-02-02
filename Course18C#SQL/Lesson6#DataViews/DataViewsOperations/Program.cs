using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataViewsOperations
{
    internal class Program
    {
        static void PrintDataTable(DataTable dt)
        {
            foreach (DataRow RecordRow in dt.Rows)
            {
                // Using Index
                // Console.WriteLine($"ID: {RecordRow[0]}\t Name: {RecordRow[1]}\t\t Salary: {RecordRow[3]}\t Date: {RecordRow[4]}");

                // Using Field Name
                Console.WriteLine($"ID: {RecordRow["ID"],-2}\t Name: {RecordRow["Name"],-20}\t Country: {RecordRow["Country"],-7}\t Salary: {RecordRow["Salary"],-5}\t Date: {RecordRow["Date"],-20}");
            }
        }

        static void PrintDataView(DataView dv)
        {
            for (int i = 0; i < dv.Count; i++)
            {
                Console.WriteLine($"ID: {dv[i][0],-2}\t Name: {dv[i][1],-20}\t Country: {dv[i][2],-7}\t Salary: {dv[i][3],-5}\t Date: {dv[i][4],-20}");
            }
        }

        static void PrintFilteredDataView(DataView dv, String filter)
        {
            dv.RowFilter = filter;
            PrintDataView(dv);
        }

        static void PrintSortedDataView(DataView dv, String sort)
        {
            dv.Sort = sort;
            PrintDataView(dv);
        }

        static void Main(string[] args)
        {
            DataTable EmployeesDataTable = new DataTable();
            EmployeesDataTable.Columns.Add("ID", typeof(int));
            EmployeesDataTable.Columns.Add("Name", typeof(string));
            EmployeesDataTable.Columns.Add("Country", typeof(string));
            EmployeesDataTable.Columns.Add("Salary", typeof(Double));
            EmployeesDataTable.Columns.Add("Date", typeof(DateTime));

            // Add Rows (If AutoIncrement put null, else decide numbers)
            EmployeesDataTable.Rows.Add(1, "Mohammed Abu-Hadhoud", "Jordan", 5000, DateTime.Now);
            EmployeesDataTable.Rows.Add(2, "Ali Maher", "KSA", 525.5, DateTime.Now);
            EmployeesDataTable.Rows.Add(3, "Lina Kamal", "Jordan", 730.5, DateTime.Now);
            EmployeesDataTable.Rows.Add(4, "Fadi Jameel", "Egypt", 880, DateTime.Now);
            EmployeesDataTable.Rows.Add(5, "Omar Mahmoud", "Lebanon", 7000, DateTime.Now);

            //printing
            Console.WriteLine("\nEmployees List:\n");
            PrintDataTable(EmployeesDataTable);

            // change it to view
            DataView EmployeesDataView = EmployeesDataTable.DefaultView;

            //
            // Display all records in a view
            //
            Console.WriteLine("\nEmployees List from data view:\n");
            PrintDataView(EmployeesDataView);

            //
            // Display View Records after filtering "Jordan" or "Egypt"
            //
            Console.WriteLine("\nEmployees List from data view after filtering \"Jordan\" or \"Egypt\":\n");
            PrintFilteredDataView(EmployeesDataView, "Country = 'Jordan' or Country = 'Egypt'");

            //
            // Display after sorting
            //
            Console.WriteLine("\nEmployees List from data view after sorting by Name ASC:\n");
            PrintSortedDataView(EmployeesDataView, "Name ASC");

            Console.ReadKey();
        }
    }
}
