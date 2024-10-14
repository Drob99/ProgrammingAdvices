// Friend Class
#include <iostream>
using namespace std;

class clsA
{
private:
    int _Var1;

public:
    int Var2;

    clsA()
    {
        _Var1 = 10;
        Var2 = 20;
    }

    // friend class
    friend class clsB;
};

class clsB
{
public:
    void display (clsA A1)
    {
        cout << endl << "The value of Var1 = " << A1._Var1;
        cout << endl << "The value of Var2 = " << A1.Var2;
    }
};

int main()
{
    clsA A1;
    clsB B1;

    B1.display(A1);

    return 0;

}