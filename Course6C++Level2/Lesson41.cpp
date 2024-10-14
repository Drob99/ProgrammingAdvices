// Pointers and Structs

# include <iostream>
using namespace std;

struct stEmployee
{
    string Name;
    float Salary;
};

int main()
{
    stEmployee Employee1, *ptr;

    Employee1.Name = "Omar Bahaeldin Abdalla";
    Employee1.Salary = 5000;

    cout << Employee1.Name << endl;
    cout << Employee1.Salary << endl;

    ptr = &Employee1;

    cout << "\nUsing Pointer:\n";
    cout << (*ptr).Name << endl; // ptr ->
    cout << ptr->Salary << endl;

    return 0;
}