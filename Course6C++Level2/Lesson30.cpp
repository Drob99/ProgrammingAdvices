// Vector of Structure

# include <iostream>
# include <vector>

using namespace std;

struct stEmployee
{
    string FirstName;
    string LastName;
    float Salary;
};

void ReadEmployeeVector(vector <stEmployee> &vEmployees)
{
    char input;
    do
    {
        stEmployee Employee;

        cout << endl;
        cout << "Enter Employee's First Name: ";
        cin >> Employee.FirstName;
        
        cout << "Enter Employee's Last Name : ";
        cin >> Employee.LastName;
        
        cout << "Enter Employee's Salary    : ";
        cin >> Employee.Salary;

        vEmployees.push_back(Employee);

        cout << "\nDo you want to add another employee? [Y/N] ";
        cin >> input;
    } while (input == 'y' || input == 'Y');
    
}

void PrintEmployeeVector(vector <stEmployee> &vEmployees)
{

    cout << "Employees Vector: \n\n";

    for (stEmployee & Employee : vEmployees)
    {
        cout << "First Name: " << Employee.FirstName << endl;
        cout << "Last Name : " << Employee.LastName  << endl;
        cout << "Salary    : " << Employee.Salary    << endl;
        cout << endl;
    }

    cout << endl;
}



int main()
{
    vector <stEmployee> vEmployees;
    ReadEmployeeVector(vEmployees);
    PrintEmployeeVector(vEmployees);


    // stEmployee tempEmployee;

    // tempEmployee.FirstName = "Mohamed";
    // tempEmployee.LastName = "Abu-Hadhoud";
    // tempEmployee.Salary = 5000;
    // vEmployees.push_back(tempEmployee);

    // tempEmployee.FirstName = "Ali";
    // tempEmployee.LastName = "Maher";
    // tempEmployee.Salary = 300;
    // vEmployees.push_back(tempEmployee);

    // tempEmployee.FirstName = "Aya";
    // tempEmployee.LastName = "Omran";
    // tempEmployee.Salary = 1000;
    // vEmployees.push_back(tempEmployee);


    return 0;
}