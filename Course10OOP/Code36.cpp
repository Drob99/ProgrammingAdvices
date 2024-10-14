/*Summary of what I know about static 
1- Static means it is related to the class; thus, a static
member could be called independent of the objects.

2- To successfully achieve the previous rule, the static
member cannot have nonstatic members inside them.

3- If for any reason I want the static method to deal with
nonstatic members, I therefore need to include it as a parameter.

4- Static members could be called by name of class OR name
of objects.
*/

# include <iostream>

using namespace std;

class clsEmployee
{
public:
    int ID;
    string Name;
    float Salary;

    clsEmployee (int ID, string Name, float Salary)
    {
        this->ID = ID;
        this->Name = Name;
        this->Salary = Salary;
    }

    static void Func1 (clsEmployee Employee)
    {
        Employee.Print();
    }

    void Func2()
    {
        Func1(*this);
    }

    void Print()
    {
        // Compiler already includes this -> without telling you.
        cout << ID << " " << Name << " " << Salary << endl;
    }
};

int main(void)
{
    clsEmployee Employee1 (101, "Omar", 5000);
    Employee1.Print();

    Employee1.Func2();

    // The same function as before.
    // clsEmployee::Func1(Employee1);
    // Employee1.Func1(Employee1);
    return 0;
}