﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AbstractClasses
{
    // No instantiation
    public abstract class Person
    {
        public string FirstName { get; set; }
        public string LastName { get; set; }

        // abstract method must be implemented in the children
        public abstract void Introduce();

        public void SayGoodbye()
        {
            Console.WriteLine("Goodbye!");
        }

    }

    public class Employee : Person
    {
        public int EmployeeId { get; set; }

        public override void Introduce()
        {
            Console.WriteLine($"Hi, my name is {FirstName} {LastName}, and my employee ID is {EmployeeId}.");
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            // You cannot create object from abstract class
            // Person Person1 = new Person();

            Employee employee = new Employee();
            employee.FirstName = "Mohammed";
            employee.LastName = "Abu-Hadhoud";
            employee.EmployeeId = 123;
            employee.Introduce(); // Output: "Hi, my name is John Doe, and my employee ID is 123."
            employee.SayGoodbye(); // Output: "Goodbye!"

            Console.ReadKey();
        }
    }
}