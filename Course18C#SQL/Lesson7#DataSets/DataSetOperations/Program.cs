using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;

namespace DataSetOperations
{
    internal class Program
    {
        static void PrintEmployeeDataTable(DataTable dt)
        {
            foreach (DataRow RecordRow in dt.Rows)
            {
                // Using Index
                // Console.WriteLine($"ID: {RecordRow[0]}\t Name: {RecordRow[1]}\t\t Salary: {RecordRow[3]}\t Date: {RecordRow[4]}");

                // Using Field Name
                Console.WriteLine($"ID: {RecordRow["ID"],-2}\t Name: {RecordRow["Name"],-20}\t Country: {RecordRow["Country"],-7}\t Salary: {RecordRow["Salary"],-5}\t Date: {RecordRow["Date"],-20}");
            }
        }

        static void PrintDepartmentDataTable(DataTable dt)
        {
            foreach (DataRow RecordRow in dt.Rows)
            {
                // Using Index
                // Console.WriteLine($"ID: {RecordRow[0]}\t Name: {RecordRow[1]}\t\t Salary: {RecordRow[3]}\t Date: {RecordRow[4]}");

                // Using Field Name
                Console.WriteLine($"DepartmentID: {RecordRow["DepartmentID"],-2}\t Name: {RecordRow["Name"],-20}");
            }
        }

        static void Main(string[] args)
        {
            DataTable EmployeesDataTable = new DataTable("EmployeesDataTable");
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

            Console.WriteLine("\nEmployees List:\n");

            PrintEmployeeDataTable(EmployeesDataTable);

            DataTable DepartmentsDataTable = new DataTable("DepartmentsDataTable");
            DepartmentsDataTable.Columns.Add("DepartmentID", typeof(int));
            DepartmentsDataTable.Columns.Add("Name", typeof(string));

            // Add Rows (If AutoIncrement put null, else decide numbers)
            DepartmentsDataTable.Rows.Add(1, "Marketing");
            DepartmentsDataTable.Rows.Add(2, "IT");
            DepartmentsDataTable.Rows.Add(3, "HR");

            Console.WriteLine("\nDepartments List:\n");

            PrintDepartmentDataTable(DepartmentsDataTable);

            // Create DataSet
            DataSet dataSet1 = new DataSet();

            // Adding DataTables into DataSet
            dataSet1.Tables.Add(EmployeesDataTable);
            dataSet1.Tables.Add(DepartmentsDataTable);

            Console.WriteLine("\nPrinting Employees Data from the DataSet\n");
            PrintEmployeeDataTable(dataSet1.Tables["EmployeesDataTable"]); // by index [0]

            Console.WriteLine("\nPrinting Departments Data from the DataSet\n");
            PrintDepartmentDataTable(dataSet1.Tables["DepartmentsDataTable"]); // by index [1]

            Console.ReadKey();
        }
    }
}
