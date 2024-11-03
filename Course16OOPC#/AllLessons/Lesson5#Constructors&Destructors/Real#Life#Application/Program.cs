using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Real_Life_Application
{
    class clsPerson
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public short Age { get; set; }
        public string Username { get; set; }
        public string Password { get; set; }

        public clsPerson(int Id, string Name, short Age)
        {
            this.Id = Id;
            this.Name = Name;
            this.Age = Age; 
        }

        public static clsPerson Find(int Id)
        {
            if (Id == 10)
                return new clsPerson(10, "Omar Abdalla", 19);
            else
                return null;
        }

        public static clsPerson Find(string Username, string Password)
        {
            if (Username == "user1" && Password == "p1234")
                return new clsPerson(10, "Omar Abdalla", 19);
            else
                return null;
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Finding Person1 by ID");
            clsPerson Person1 = clsPerson.Find(10);

            if (Person1 != null)
            {
                Console.WriteLine($"ID = {Person1.Id}");
                Console.WriteLine($"Name = {Person1.Name}");
                Console.WriteLine($"Age = {Person1.Age}");
            }
            else
                Console.WriteLine("Could not find the person by given ID");

            Console.WriteLine("\nFinding Person1 by Username and Password");
            clsPerson Person2 = clsPerson.Find("user1", "p1234");

            if (Person1 != null)
            {
                Console.WriteLine($"ID = {Person2.Id}");
                Console.WriteLine($"Name = {Person2.Name}");
                Console.WriteLine($"Age = {Person2.Age}");
            }
            else
                Console.WriteLine("Could not find the person by given username/password");
        }
    }
}
