#include <iostream>
using namespace std;

int main()
{
    cout << "Enter 5 numbers: \n";
    int num;
    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
        cin >> num;
        if (num >= 50)
        {
            continue;
        }
        sum += num;
    }

    cout << "Sum = " << sum << '\n';
}