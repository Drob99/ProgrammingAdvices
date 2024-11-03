using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Properties
{
    class clsEmployee
    {
        // private fields
        private int _ID = 0;
        private string _Name = string.Empty;
        private double _Salary = double.NaN;

        // ID property declaration - ReadOnly property
        public int ID
        {
            // get for reading
            get
            {
                return _ID;
            }
        }

        // Name property declaration
        public string Name
        {
            get
            {
                return _Name;
            }

            set
            {
                _Name = value;
            }
        }

        public double Salary
        {
            get;
            set;
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            // create an object
            clsEmployee Employee1 = new clsEmployee();

            // Employee1.ID = 7; read only 

            Employee1.Name = "Omar Bahaeldin Abdalla";
            Employee1.Salary = 5000;

            Console.WriteLine($"Employee Id = {Employee1.ID}");
            Console.WriteLine($"Employee Name = {Employee1.Name}");

            Console.ReadKey();
        }
    }
}
