/* Simply, if I want to write a class about an Employee,
I inherit from Person Class. This practice follows the 3rd 
concept of OOP: Inheritance.
*/

# include <iostream>
using namespace std;

class clsPerson
{
private:
    int _ID;
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:

    clsPerson()
    {

    }
    // Parametrized Constructor
    clsPerson(int ID, string FirstName, string LastName, string Email, string Phone)
    {
        _ID        = ID;
        _FirstName = FirstName;
        _LastName  = LastName;
        _Email     = Email;
        _Phone     = Phone;
    }

    // getters and setters
    int ID() // Read Only Property
    {
        return _ID;
    }

    string FirstName()
    {
        return _FirstName;
    }

    void setFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    string LastName()
    {
        return _LastName;
    }

    void setLastName(string LastName)
    {
        _LastName = LastName;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }


    string Email()
    {
        return _Email;
    }

    void setEmail(string Email)
    {
        _Email = Email;
    }

    string Phone()
    {
        return _Phone;
    }

    void setPhone(string Phone)
    {
        _Phone = Phone;
    }

    // methods

    void Print()
    {
        cout << "\nInfo:";
        cout << "\n----------------------\n";
        cout << "ID         : " << _ID << "\n";
        cout << "FirstName  : " << _FirstName << "\n";
        cout << "LastName   : " << _LastName << "\n";
        cout << "Full Name  : " << FullName() << "\n";
        cout << "Email      : " << _Email   << "\n";
        cout << "Phone      : " << _Phone;
        cout << "\n----------------------\n";
    }

    void SendEmail(string Subject, string Body)
    {
        cout << "\nThe following message sent successfully to email: " << _Email;
        cout << "\nSubject: " << Subject;
        cout << "\nBody: " << Body << endl;
    }

    void SendSMS(string SMS)
    {
        cout << "\nThe following SMS sent successfully to phone: " << _Phone;
        cout << "\n" << SMS << endl;
    }

};

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
        _Title      = Title;
        _Salary     = Salary;
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
        cout << "Email      : " << Email()   << "\n";
        cout << "Phone      : " << Phone()  << "\n";
        cout << "Title      : " << Title()  << "\n";
        cout << "Salary     : " << Salary() << "\n";
        cout << "Department : " << Department();
        cout << "\n----------------------\n";
    }

};

class clsDeveloper : public clsEmployee
{
private:
    string _MainProgrammingLanguage;

public:
    clsDeveloper(int ID, string FirstName, string LastName, string Email, string Phone, string Title, float Salary, string Department, string MainProgrammingLanguage)
    : clsEmployee(ID, FirstName, LastName, Email, Phone, Title, Salary, Department)
    {
        _MainProgrammingLanguage = MainProgrammingLanguage;
    }

    void setMainProgrammingLanguage (string MainProgrammingLanguage)
    {
        _MainProgrammingLanguage = MainProgrammingLanguage;
    }

    string MainProgrammingLanguage()
    {
        return _MainProgrammingLanguage;
    }


    void Print()
    {
        cout << "\nInfo:";
        cout << "\n----------------------------------------------\n";
        cout << "ID                        : " << ID() << "\n";
        cout << "FirstName                 : " << FirstName() << "\n";
        cout << "LastName                  : " << LastName() << "\n";
        cout << "Full Name                 : " << FullName() << "\n";
        cout << "Email                     : " << Email()   << "\n";
        cout << "Phone                     : " << Phone()  << "\n";
        cout << "Title                     : " << Title()  << "\n";
        cout << "Salary                    : " << Salary() << "\n";
        cout << "Department                : " << Department() << "\n";
        cout << "Main Programming Language : " << MainProgrammingLanguage();
        cout << "\n----------------------------------------------\n";
    }
};

int main()
{
    clsDeveloper Developer1 (10, "Omar", "Abdalla", "drob992004@gmail.com", "00966570281148", "Engineer", 1000, "SWE", "C++");
    Developer1.Print();

    Developer1.SendEmail("Hi", "How are you?");
    Developer1.SendSMS ("How are you?");

    return 0;
}