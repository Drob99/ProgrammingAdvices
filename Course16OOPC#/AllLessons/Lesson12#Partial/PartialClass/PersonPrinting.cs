using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public partial class Person
{
    partial void PrintAge()
    {
        // This method will be called once implemented. if not implemented, the compile
        // ignores it without errors.

        Console.WriteLine($"Current age: {Age}");

    }

}
