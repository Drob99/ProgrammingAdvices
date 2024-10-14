#include <iostream>

using namespace std;

enum married {single, married};
enum gender {M, F};

struct Person 
{
    string name;
    unsigned short age;
    string city;
    string country;
    float monthlySalary;
    float yearlySalary;
    short gender; // M=Male, F=Female.
    short married;
};

void read_person_info (Person &person)
{
    cout << "Enter your name: ";
    cin.ignore(1, '\n');
    getline(cin, person.name);

    cout << "Enter your age: ";
    cin >> person.age;

    cout << "Enter your city: ";
    cin >> person.city;

    cout << "Enter your country: ";
    cin >> person.country;

    cout << "Enter your monthly salary: ";
    cin >> person.monthlySalary;

    person.yearlySalary = person.monthlySalary * 12;

    cout << "Enter Gender (M/F): ";
    char gend;
    cin >> gend;
    if (gend == 'M')
    {
        person.gender = gender::M;
    }
    else
        person.gender = gender::F;


    cout << "Enter married status (1/0): ";
    char marr;
    cin >> marr;
    if (marr == '0')
    {
        person.married = married::single;
    }
    else
        person.married = married::married;
}


void print_person_info(Person person)
{

    cout << "\n*******************************\n";
    cout << "Name: " << person.name << "." << endl;
    cout << "Age: " << person.age << " Years." << endl;
    cout << "City: " << person.city << "." << endl;
    cout << "Country: " << person.country << "." << endl;
    cout << "Monthly Salary: " << person.monthlySalary << endl;
    cout << "Yearly Salary: " << person.yearlySalary << endl;
    cout << "Gender: " << person.gender << endl;
    cout << "Married: " << person.married << endl;
    cout << "\n*******************************\n" << endl;
}

int main()
{
    Person person;
    read_person_info(person);
    print_person_info(person);
}