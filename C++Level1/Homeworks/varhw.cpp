#include <iostream>

using namespace std;

int main()
{
    string name = "Omar Abdalla";
    int age = 18;
    string city = "Khobar";
    string country = "Saudi Arabia";
    float monthlySalary = 5000;
    float yearlySalary = monthlySalary * 12;
    char gender = 'M';
    bool married = 1;

    cout << "*******************************\n";
    cout << "Name: " << name << "." << endl;
    cout << "Age: " << age << " Years." << endl;
    cout << "City: " << city << "." << endl;
    cout << "Country: " << country << "." << endl;
    cout << "Monthly Salary: " << monthlySalary << endl;
    cout << "Yearly Salary: " << yearlySalary << endl;
    cout << "Gender: " << gender << endl;
    cout << "Married: " << married << endl;
    cout << "*******************************" << endl;
}