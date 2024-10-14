#include <iostream>
#include <vector>

using namespace std;

class clsA
{
public:
    clsA(){}

    clsA (int value)
    {
        x = value;
    }

    int x;

    void Print()
    {
        cout << "The value of x = " << x << endl;
    }

};

int main()
{
    short NumberOfObjects = 5;

    clsA * arrA = new clsA[NumberOfObjects];

    for (int i = 0; i < NumberOfObjects; i++)
    {
        arrA[i] = clsA(i); // *(arrA + i) = clsA(i);
    }

    for (int i = 0; i < NumberOfObjects; i++)
    {
        arrA[i].Print(); // *(arrA + i).Print();
    }

    delete[] arrA;
    return 0;
}