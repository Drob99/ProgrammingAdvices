﻿using System;
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

        static void Main(string[] args)
        {
            DataTable EmployeesDataTable = new DataTable();
            EmployeesDataTable.Columns.Add("ID", typeof(int));
            EmployeesDataTable.Columns.Add("Name",  typeof(string));
            EmployeesDataTable.Columns.Add("Country",  typeof(string));
            EmployeesDataTable.Columns.Add("Salary", typeof(Double));
            EmployeesDataTable.Columns.Add("Date", typeof(DateTime));

            // Add Rows
            EmployeesDataTable.Rows.Add(1, "Mohammed Abu-Hadhoud", "Jordan", 5000, DateTime.Now);
            EmployeesDataTable.Rows.Add(2, "Ali Maher", "KSA", 525.5, DateTime.Now);
            EmployeesDataTable.Rows.Add(3, "Lina Kamal", "Jordan", 730.5, DateTime.Now);
            EmployeesDataTable.Rows.Add(4, "Fadi Jameel", "Egypt", 880, DateTime.Now);
            EmployeesDataTable.Rows.Add(5, "Omar Mahmoud", "Lebanon", 7000, DateTime.Now);

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


            Console.ReadKey();
        }
    }
}