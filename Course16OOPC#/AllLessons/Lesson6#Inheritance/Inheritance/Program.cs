using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritance
{
    public class clsPerson
    {
        public clsPerson(int iD, string firstName, string lastName, string title)
        {
            ID = iD;
            FirstName = firstName;
            LastName = lastName;
            Title = title;
        }

        public int ID { get; set; }
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string Title { get; set; }

        public string FullName
        {
            get
            {
                return FirstName + " " + LastName;
            }
        }
    }

    public class clsEmployee : clsPerson
    {
        public clsEmployee (int ID, string FirstName, string LastName, string Title,
                    float Salary, string DepartmentName) : base(ID, FirstName, LastName, Title)
        {
            this.Salary = Salary;
            this.DepartmentName = DepartmentName;
        }

        public float Salary { get; set; }
        public string DepartmentName { get; set; }

        public void IncreaseSalaryBy(float Amount)
        {
            Salary += Amount;
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            clsEmployee Employee1 = new clsEmployee(7, "Omar", "Abdalla", "Mr.", 5000, "IT");

            Console.WriteLine("Accessing Object (Employee1):\n");

            ////base class
            //Employee1.ID = 7;
            //Employee1.Title = "Mr.";
            //Employee1.FirstName = "Omar";
            //Employee1.LastName = "Abdalla";

            ////derived class
            //Employee1.DepartmentName = "IT";
            //Employee1.Salary = 5000;

            Console.WriteLine("Accessing Object 1 (Employee1):\n");
            Console.WriteLine("ID := {0}", Employee1.ID);
            Console.WriteLine("Title := {0}", Employee1.Title);
            Console.WriteLine("Full Name := {0}", Employee1.FullName);
            Console.WriteLine("Department Name := {0}", Employee1.DepartmentName);
            Console.WriteLine("Salary := {0}", Employee1.Salary);

            Employee1.IncreaseSalaryBy(100);
            Console.WriteLine("Salary after increase := {0}", Employee1.Salary);
            Console.ReadKey();
        }
    }
}
