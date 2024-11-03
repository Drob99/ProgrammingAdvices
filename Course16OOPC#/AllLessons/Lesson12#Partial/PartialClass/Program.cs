using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PartialClass
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Person person1 = new Person();
            person1.Age = 19;
            person1.Birthday(); // Output : "Current age: 20"

            // private bcz it's partial
            // person1.PrintAge();

            Console.ReadKey();
        }
    }
}
