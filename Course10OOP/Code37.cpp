# include <iostream>

using namespace std;

class clsA
{
public:
    int x;

    void Print()
    {
        cout << "The value of x = " << x << "." << endl;
    }
};

// object sent by value, Orig values Not affected
void PassObjectByValue(clsA A1)
{
    A1.x = 100;
}

// By Ref
void PassObjectByRef(clsA &A1)
{
    A1.x = 200;
}

int main()
{
    clsA A1;

    A1.x = 50;
    cout << "\nA.x before passing by val: \n";
    A1.Print();

    PassObjectByValue(A1);
    cout << "\nA.x after passing by val: \n";
    A1.Print();

    PassObjectByRef(A1);
    cout << "\nA.x after passing by ref: \n";
    A1.Print();
}