// MyFloor

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

int myFloor(float Number)
{
    if (GetFractionPart(Number) > 0)
    {
        if (Number < 0)
            return (int) Number - 1;
        return (int) Number;
    }
    else
        return Number;
}

int main()
{
    float input = ReadNumber("Enter Number: ");

    cout << "\nMy floor Result: " << myFloor(input);
    cout << "\nC++ floor Result: " << floor(input);
}
