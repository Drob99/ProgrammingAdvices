using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;

namespace Example1
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

        static void PrintAggregateFunctions(DataTable dt) 
        {
            int EmployeesCount = 0;
            double TotalSalaries = 0;
            double MinSalary = 0;
            double MaxSalary = 0;
            double AverageSalaries = 0;

            EmployeesCount = dt.Rows.Count;
            TotalSalaries = Convert.ToDouble(dt.Compute("SUM(Salary)",string.Empty));
            AverageSalaries = Convert.ToDouble(dt.Compute("AVG(Salary)",string.Empty));
            MinSalary = Convert.ToDouble(dt.Compute("MIN(Salary)",string.Empty));
            MaxSalary = Convert.ToDouble(dt.Compute("MAX(Salary)",string.Empty));

            Console.WriteLine("\nCount of Employees = " + EmployeesCount);
            Console.WriteLine("Total Employees Salaries = " + TotalSalaries);
            Console.WriteLine("Average Employee Salaries = " + AverageSalaries);
            Console.WriteLine("Minimum Salary = " + MinSalary);
            Console.WriteLine("Maximum Salary = " + MaxSalary);
        }

        static void PrintAggregateFunctions(DataTable dt, string Filter)
        {
            int ResultCount = 0;
            DataRow[] ResultRows;
            double TotalSalaries = 0;
            double MinSalary = 0;
            double MaxSalary = 0;
            double AverageSalaries = 0;

            ResultRows = dt.Select(Filter);

            foreach (DataRow RecordRow in ResultRows)
            {
                // Using Index
                // Console.WriteLine($"ID: {RecordRow[0]}\t Name: {RecordRow[1]}\t\t Salary: {RecordRow[3]}\t Date: {RecordRow[4]}");

                // Using Field Name
                Console.WriteLine($"ID: {RecordRow["ID"],-2}\t Name: {RecordRow["Name"],-20}\t Country: {RecordRow["Country"],-7}\t Salary: {RecordRow["Salary"],-5}\t Date: {RecordRow["Date"],-20}");
            }

            ResultCount = ResultRows.Count();
            TotalSalaries = Convert.ToDouble(dt.Compute("SUM(Salary)", Filter));
            AverageSalaries = Convert.ToDouble(dt.Compute("AVG(Salary)", Filter));
            MinSalary = Convert.ToDouble(dt.Compute("MIN(Salary)", Filter));
            MaxSalary = Convert.ToDouble(dt.Compute("MAX(Salary)", Filter));

            Console.WriteLine("\nCount of Employees = " + ResultCount);
            Console.WriteLine("Total Employees Salaries = " + TotalSalaries);
            Console.WriteLine("Average Employee Salaries = " + AverageSalaries);
            Console.WriteLine("Minimum Salary = " + MinSalary);
            Console.WriteLine("Maximum Salary = " + MaxSalary);
        }

        static void PrintSortedDataTable(DataTable dt, string sorting)
        {
            dt.DefaultView.Sort = sorting;
            dt = dt.DefaultView.ToTable();

            Console.WriteLine($"\n\nEmployees List Sorted By {sorting}:\n");
            
            PrintDataTable(dt);
        }
        
        static void DeleteEmployeeGivenID(DataTable dt, int ID)
        {
            DataRow[] Results = dt.Select($"ID={ID}"); // filter for the ID

            foreach (var ResultRow in Results) 
            {
                ResultRow.Delete();
            }

            // dt.AcceptChanges(); // sync with database if I am online

            PrintDataTable(dt);
        }

        static void UpdateEmployeeGivenID(DataTable dt, int ID)
        {
            DataRow[] Results = dt.Select($"ID={ID}");

            foreach (var ResultsRow in Results)
            {
                ResultsRow["Name"] = "Omar Abdalla";
                ResultsRow["Country"] = "Kazakhstan";
            }

            // dt.AcceptChanges();

            PrintDataTable(dt);
        }

        static void Main(string[] args)
        {
            DataTable EmployeesDataTable = new DataTable();
            //EmployeesDataTable.Columns.Add("ID", typeof(int));
            //EmployeesDataTable.Columns.Add("Name",  typeof(string));
            //EmployeesDataTable.Columns.Add("Country",  typeof(string));
            //EmployeesDataTable.Columns.Add("Salary", typeof(Double));
            //EmployeesDataTable.Columns.Add("Date", typeof(DateTime));

            DataColumn dtColumn;

            // 1st column (ID)
            dtColumn = new DataColumn();
            dtColumn.DataType = typeof(int);
            dtColumn.ColumnName = "ID";
            dtColumn.AutoIncrement = true;
            dtColumn.AutoIncrementSeed = 1;
            dtColumn.AutoIncrementStep = 1;
            dtColumn.Caption = "Employee ID";
            dtColumn.ReadOnly = true;
            dtColumn.Unique = true;
            EmployeesDataTable.Columns.Add(dtColumn);

            // 2nd column Name
            dtColumn = new DataColumn();
            dtColumn.DataType = typeof(string);
            dtColumn.ColumnName = "Name";
            dtColumn.AutoIncrement = false;
            dtColumn.Caption = "Name";
            dtColumn.ReadOnly = false;
            dtColumn.Unique = false;
            EmployeesDataTable.Columns.Add(dtColumn);

            // 3rd column Country
            dtColumn = new DataColumn();
            dtColumn.DataType = typeof(string);
            dtColumn.ColumnName = "Country";
            dtColumn.AutoIncrement = false;
            dtColumn.Caption = "Country";
            dtColumn.ReadOnly = false;
            dtColumn.Unique = false;
            EmployeesDataTable.Columns.Add(dtColumn);

            // 4th column Salary
            dtColumn = new DataColumn();
            dtColumn.DataType = typeof(Double);
            dtColumn.ColumnName = "Salary";
            dtColumn.AutoIncrement = false;
            dtColumn.Caption = "Salary";
            dtColumn.ReadOnly = false;
            dtColumn.Unique = false;
            EmployeesDataTable.Columns.Add(dtColumn);

            // 5th column Date
            dtColumn = new DataColumn();
            dtColumn.DataType = typeof(DateTime);
            dtColumn.ColumnName = "Date";
            dtColumn.AutoIncrement = false;
            dtColumn.Caption = "Date";
            dtColumn.ReadOnly = false;
            dtColumn.Unique = false;
            EmployeesDataTable.Columns.Add(dtColumn);

            // Make the ID column the primary key column.
            DataColumn[] PrimaryKeyColumns = new DataColumn[1]; // array of data columns with number of primary keys 
            PrimaryKeyColumns[0] = EmployeesDataTable.Columns["ID"];
            EmployeesDataTable.PrimaryKey = PrimaryKeyColumns;

            // Add Rows (If AutoIncrement put null, else decide numbers)
            EmployeesDataTable.Rows.Add(null, "Mohammed Abu-Hadhoud", "Jordan", 5000, DateTime.Now);
            EmployeesDataTable.Rows.Add(null, "Ali Maher", "KSA", 525.5, DateTime.Now);
            EmployeesDataTable.Rows.Add(null, "Lina Kamal", "Jordan", 730.5, DateTime.Now);
            EmployeesDataTable.Rows.Add(null, "Fadi Jameel", "Egypt", 880, DateTime.Now);
            EmployeesDataTable.Rows.Add(null, "Omar Mahmoud", "Lebanon", 7000, DateTime.Now);

            //printing
            Console.WriteLine("\nEmployees List:\n");
            PrintDataTable(EmployeesDataTable);


            //Aggregate Functions
            PrintAggregateFunctions(EmployeesDataTable);

            // Filtering Data

            //Filter Country By Jordan
            Console.WriteLine("\n\nFilter \"Jordan\" Employees\n");
            PrintAggregateFunctions(EmployeesDataTable, "Country = 'Jordan'");


            //------------------------------------------------------
            //Filter By Country Jordan or Egypt
            
            Console.WriteLine("\n\nFilter \"Jordan\" or \"Egypt\" Employees\n");
            PrintAggregateFunctions(EmployeesDataTable, "Country = 'Jordan' or Country = 'Egypt'");


            //------------------------------------------------------------
            //Filter By ID = 1

            Console.WriteLine("\n\nFilter Employees with ID = 1\n");
            PrintAggregateFunctions(EmployeesDataTable, "ID = 1");

            //------------------------------------------------------------
            // Sort by ID desc

            PrintSortedDataTable(EmployeesDataTable, "ID Desc");

            //------------------------------------------------------------
            // Sort by name asc

            PrintSortedDataTable(EmployeesDataTable, "Name ASC");

            //------------------------------------------------------------
            // Delete ID = 4

            Console.WriteLine("\n\nEmployee List After Deleting ID = 4\n");
            DeleteEmployeeGivenID(EmployeesDataTable, 4);

            //------------------------------------------------------------
            // Update ID = 5 to name Omar Abdalla

            Console.WriteLine("\n\nUpdating Employee ID = 5 record:\n");
            UpdateEmployeeGivenID(EmployeesDataTable, 5);


            //------------------------------------------------------------
            // Clear all records

            Console.WriteLine("\n\nClearing All Records.\n");
            EmployeesDataTable.Clear();
            PrintDataTable(EmployeesDataTable);

            Console.ReadKey();
        }
    }
}
