#include <iostream>

using namespace std;

class clsPerson
{

public:

    string FullName="Omar Bahaeldin Abdalla";
 
};

class clsEmployee : public clsPerson
{

public:
    string Title = "Software Engineer";

};

int main()

{

    clsEmployee Employee1;
  
    cout << Employee1.FullName << endl;

    // ! upcasting
    //this will convert employee to person.
    clsPerson * Person1 = &Employee1;
    cout << Person1->FullName << endl;
    // You cannot call the title.
   

    //clsPerson Person2;
    //cout << Person2.FullName << endl;

    // ! downcasting : you cannot convert person to employee
    //clsEmployee* Employee2 = &Person2;



    return 0;
}