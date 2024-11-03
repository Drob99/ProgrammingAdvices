using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SealedMethod
{
    public class Person
    {
        public virtual void Greet()
        {
            Console.WriteLine("The person says hello.");
        }
    }


    public class Employee : Person
    {
        public sealed override void Greet()
        {
            Console.WriteLine("The employee greets you.");
        }
    }

    public class Manager : Employee
    {
        //This will produce a compile-time error because the Greet method in Employee is
        //sealed and cannot be overridden. But you can shadow it.
        //public override void Greet()
        //{
        //    Console.WriteLine("The manager greets you warmly.");
        //}
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            Person person = new Person();
            person.Greet(); // outputs "The person says hello."

            Employee employee = new Employee();
            employee.Greet(); // outputs "The employee greets you."

            Manager manager = new Manager();
            manager.Greet(); // outputs "The employee greets you."

            Console.ReadKey();
        }
    }
}
