#include <iostream>
#include <string>

using namespace std;

class clsA
{
public:
    
    static int Function1()
    {
        // Function2(); // Cannot be accessed bcz it is nonstatic
        return 10;
    }

    int Function2()
    {
        return 20;
    }
};

int main()
{
    clsA A1, A2, A3;

    cout << clsA::Function1() << endl;

    cout << A1.Function1() << endl;
    cout << A2.Function2() << endl;
    cout << A2.Function1() << endl;
}