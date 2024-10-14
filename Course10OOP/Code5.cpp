# include <iostream>

using namespace std;

class clsEmployee
{
private:
    //only accessible inside class
    int Variable1 = 5;

    int Function1()
    {
        return 40;
    }

protected:
    // only accesssible inside class and all inherited classes
    int Variable2 = 100;
    
    int Function2()
    {
        return 50;
    }

public:
    // accessible for everyone
    string FirstName;
    string LastName;

    string FullName()
    {
        return FirstName + " " + LastName;
    }

    float Function3()
    {
        return Function1() * Variable1 * Variable2;
    }

};

int main()
{
    clsEmployee Person1;
    Person1.FirstName = "Omar";
    Person1.LastName = "Abdalla";

    cout << Person1.FullName() << endl;
    cout << Person1.Function3() << endl;
    
}