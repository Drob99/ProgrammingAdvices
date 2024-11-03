using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Constructors
{
    class clsPerson
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public int Age { get; set; }

        // parameterless constructor -> initialize fields
        public clsPerson()
        {
            Id = -1;
            Name = "Empty";
            Age = 0;
        }

        // parametrized constructor
        // If you write it without the parameterless, then you must provide parameters
        // overloading
        public clsPerson(int Id, string Name, int Age)
        {
            this.Id = Id;
            this.Name = Name;
            this.Age = Age;
        }

        // no parameters and no return type
        ~clsPerson()
        {
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            clsPerson Person1 = new clsPerson(); // immediately calls the parameterless constructor
            clsPerson Person2 = new clsPerson(7, "Omar Abdalla", 19);

            Console.WriteLine($"ID = {Person1.Id}");
            Console.WriteLine($"Name = {Person1.Name}");
            Console.WriteLine($"Age = {Person1.Age}");

            Console.WriteLine($"\nID = {Person2.Id}");
            Console.WriteLine($"Name = {Person2.Name}");
            Console.WriteLine($"Age = {Person2.Age}");

            Console.ReadKey();
        }
    }
}
