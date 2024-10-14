// Copy Constructor
#include <iostream>

using namespace std;

class clsEmployee 
{
public:
    string FullName;

    clsEmployee()
    {
        FullName = "Omar Bahaa";
        cout << "\nHi, I'm Constructor.";
    }

    ~clsEmployee()
    {
        cout << "\nHi, I'm Destructor";
    }
};

void Fun1()
{
    clsEmployee Person1;
}

void Fun2()
{
    clsEmployee *Person2 = new clsEmployee; // Not released by destructor
    delete Person2;
}

int main()
{
        Fun1();
        Fun2();
        return 0;
}