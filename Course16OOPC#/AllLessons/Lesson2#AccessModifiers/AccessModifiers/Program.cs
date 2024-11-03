using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AccessModifiers
{
    class clsA
    {
        public int x1 = 10;
        private int x2 = 20;
        protected int x3 = 30;

        public int fun1()
        {
            return 100;
        }

        private int fun2() 
        { 
            return 200;
        }

        protected int fun3() 
        {
            return 300;        
        }
    }

    class clsB : clsA 
    { 
        public int fun4()
        {
            // x1 is publuc and x3 is protected in base class, so both are accessible
            return x1 + x3;
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            // create object from class
            clsA A = new clsA();

            // all public members are accessible and internal
            Console.WriteLine("All public members are accessible");
            Console.WriteLine($"x1:{A.x1}");
            Console.WriteLine($"result of fun1 = {A.fun1()}");

            // you cannot access private members in the following line
            // Console.WriteLine($"x2 = {A.x2}");
            // Console.WriteLine($"result of fun2 = {A.fun2()}");

            // you cannot access protected members in the following line
            // Console.WriteLine($"x3 = {A.x3}");
            // Console.WriteLine($"result of fun3 = {A.fun3()}");

            clsB B = new clsB();
            Console.WriteLine("\nObjects from class B expose all public members from base class.");
            Console.WriteLine($"x1:{B.x1}");
            Console.WriteLine($"result of fun1 = {B.fun1()}");

            // you cannot access private members in the following line
            // Console.WriteLine($"x2 = {B.x2}");
            // Console.WriteLine($"result of fun2 = {B.fun2()}");

            // you cannot access protected members in the following line
            // Console.WriteLine($"x3 = {B.x3}");
            // Console.WriteLine($"result of fun3 = {B.fun3()}");

            Console.ReadKey();

        }
    }
}
