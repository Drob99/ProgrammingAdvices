using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Class_Object
{
    class clsPerson
    {
        // Fields
        public string FirstName;
        public string LastName;

        //Method
        public string FullName()
        {
            return FirstName + ' ' + LastName;
        }
    
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            // create object from class
            clsPerson Person1 = new clsPerson();

            Console.WriteLine("Accessing Object 1 (Person1):");
            Person1.FirstName = "Omar";
            Person1.LastName = "Abdalla";
            Console.WriteLine(Person1.FullName());

            //create another object
            clsPerson Person2 = new clsPerson();
            Console.WriteLine("\nAccessing Object 2 (Person2):");
            Person2.FirstName = "Mohammad";
            Person2.LastName = "Abu-Hadhoud";
            Console.WriteLine(Person2.FullName());

            Console.ReadKey();
        }
    }
}
