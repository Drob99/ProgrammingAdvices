// Set & Get through = 
// Read Only Property
# include <iostream>

using namespace std;

class clsEmployee
{
private:
    string _FirstName;

public:


    // Property Set
    void setFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    //Property Get
    string getFirstName()
    {
        return _FirstName;
    }

    // only for mic visual 
    // __declspec(property(get = getFirstName, put = setFirstName)) string FirstName;

};

int main()
{
    clsEmployee Person1;
    Person1.setFirstName("Omar");
    cout << "First Name: " << Person1.getFirstName() << endl;

    // Person1.FirstName = "Mohammed";
    // cout << Person1.FirstName;
    return 0;
}