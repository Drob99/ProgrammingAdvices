// MyAbs

#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber(string message)
{
    float Number;
    cout << message;
    cin >> Number;
    return Number;
}

float myAbs(float Number)
{
    if (Number < 0)
        Number *= -1;

    return Number;
}

int main()
{
    float input = ReadNumber("Enter Number: ");

    cout << "\nMy abs Result: " << myAbs(input);
    cout << "\nC++ abs Result: " << abs(input);
}
