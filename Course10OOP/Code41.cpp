// Objects with Parametrized Constructor and Array
# include <iostream>
# include <vector>

using namespace std;

class clsA
{
public:
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
    clsA obj[] = { clsA(10), clsA(20), clsA(30) };

    for (int i = 0; i < 3; i++)
    {
        obj[i].Print();
    }

    return 0;
}