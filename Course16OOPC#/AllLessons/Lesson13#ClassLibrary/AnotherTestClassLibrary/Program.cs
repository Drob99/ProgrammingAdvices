using System;
using MyFirstClassLibrary;

namespace AnotherTestClassLibrary
{
    internal class Program
    {
        static void Main(string[] args)
        {
            clsMyMath MyMath1 = new clsMyMath();
            Console.WriteLine(MyMath1.Sum(10, 20));
            Console.ReadKey();
        }
    }
}
