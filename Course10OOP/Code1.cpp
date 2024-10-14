# include <iostream>

using namespace std;

class clsEmployee
{
//private:

    int x;

public:
    string FirstName;
    string LastName;

    string FullName()
    {
        return FirstName + " " + LastName;
    }

};

int main()
{
    clsEmployee Person1;
    Person1.FirstName = "Omar";
    Person1.LastName = "Abdalla";

    cout << Person1.FullName() << endl;
    
};