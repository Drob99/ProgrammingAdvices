/* This is taken from a previous project about inheritance.
    The goal is to divide the classes and separate them to libraries.
*/

#include <iostream>
#include "../Libraries/clsPerson.h" // Already Included Down in Employee.h
#include "../Libraries/clsEmployee.h"

using namespace std;

int main()
{
    clsEmployee Employee1(10, "Omar", "Abdalla", "drob992004@gmail.com", "00966570281148", "Engineer", 1000, "SWE");
    Employee1.Print();

    Employee1.SendEmail("Hi", "How are you?");
    Employee1.SendSMS("How are you?");

    return 0;
}