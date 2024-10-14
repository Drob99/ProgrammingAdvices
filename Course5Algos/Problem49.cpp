// MyCeil

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

float GetFractionPart(float Number)
{
    int WholePart = (int) Number;
    return myAbs(Number - WholePart); 
}


int myCeil(float Number)
{
    if (GetFractionPart(Number) > 0)
    {
        if (Number < 0)
            return (int) Number;
        return (int) Number + 1;
    }
    else
        return Number;
}

int main()
{
    float input = ReadNumber("Enter Number: ");

    cout << "\nMy Ceil Result: " << myCeil(input);
    cout << "\nC++ Ceil Result: " << ceil(input);
}
