#pragma once
#include <iostream>
using namespace std;

#include "../Libraries/clsPerson.h"

class clsEmployee : public clsPerson
{
private:
    string _Title;
    float _Salary;
    string _Department;

public:
    // Parametrized Constructor
    clsEmployee(int ID, string FirstName, string LastName, string Email, string Phone, string Title, float Salary, string Department)
        : clsPerson(ID, FirstName, LastName, Email, Phone)
    {
        _Title = Title;
        _Salary = Salary;
        _Department = Department;
    }

    string Title()
    {
        return _Title;
    }

    void setTitle(string Title)
    {
        _Title = Title;
    }

    float Salary()
    {
        return _Salary;
    }

    void setSalary(float Salary)
    {
        _Salary = Salary;
    }

    string Department()
    {
        return _Department;
    }

    void setDepartment(string Department)
    {
        _Department = Department;
    }

    // Overriden Method
    void Print()
    {
        // clsPerson::Print();
        cout << "\nInfo:";
        cout << "\n----------------------\n";
        cout << "ID         : " << ID() << "\n";
        cout << "FirstName  : " << FirstName() << "\n";
        cout << "LastName   : " << LastName() << "\n";
        cout << "Full Name  : " << FullName() << "\n";
        cout << "Email      : " << Email() << "\n";
        cout << "Phone      : " << Phone() << "\n";
        cout << "Title      : " << Title() << "\n";
        cout << "Salary     : " << Salary() << "\n";
        cout << "Department : " << Department();
        cout << "\n----------------------\n";
    }
};
