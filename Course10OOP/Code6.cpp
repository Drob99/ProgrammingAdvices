// Properties Get/Set
# include <iostream>

using namespace std;

class clsEmployee
{
private:
    string _FirstName;
    string _LastName;

public:
    // Property Set
    void setFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    //Property Get
    string FirstName()
    {
        return _FirstName;
    }

    //Property Set
    void setLastName(string LastName)
    {
        _LastName = LastName;
    }

    //Property Get
    string LastName()
    {
        return _LastName;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

};

int main()
{
    clsEmployee Person1;
    Person1.setFirstName("Omar");
    Person1.setLastName("Abdalla");

    cout << "First Name: " << Person1.FirstName() << endl;
    cout << "Last Name: "  << Person1.LastName() << endl;
    cout << "Full Name: " << Person1.FullName() << endl;
    
    return 0;
}