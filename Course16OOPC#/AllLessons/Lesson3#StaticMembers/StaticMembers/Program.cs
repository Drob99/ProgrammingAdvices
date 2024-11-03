using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StaticMembers
{
    class clsA
    {
        public int x1;
        public static int x2; //shared because it's in the class level

        public int Method1()
        {
            // non-static can access static members
            return x1 + x2;
        }

        public static int Method2()
        {
            // static methods cannot access non-static members bcz there is no object
            // static methods are called at class level
            // return clsA.x1 + x2; error
            return x2;
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            clsA objA1 = new clsA();
            clsA objA2 = new clsA();

            objA1.x1 = 7;
            objA2.x1 = 10;

            clsA.x2 = 100; // only with class name
            // objA1.x2 = 100; Error unlike c++

            Console.WriteLine($"objA1.x1 = {objA1.x1}");
            Console.WriteLine($"objA2.x1 = {objA2.x1}");
            Console.WriteLine($"objA1.method1 = {objA1.Method1()}");
            Console.WriteLine($"objA2.method1 = {objA2.Method1()}");

            // method2 cannot be accessed throgh object name, only through class itself
            // Console.WriteLine(objA1.Method2());
            Console.WriteLine($"static method2 = {clsA.Method2()}");

            Console.WriteLine("statix x2 = " + clsA.x2);
            Console.ReadKey();
        }
    }
}
