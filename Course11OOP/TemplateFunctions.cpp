#include <iostream>
using namespace std;

template <typename T> T myMax(T Number1, T Number2)
{
    return (Number1 > Number2) ? Number1 : Number2;
}

int main()
{
    cout << myMax<int> (3, 7) << endl;

    cout << myMax<double> (5.3, 4.2) << endl;

    cout << myMax<char> ('a', 'b') << endl;

    return 0;
}