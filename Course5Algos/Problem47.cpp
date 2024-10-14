// MyRound

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

int myRound(float Number)
{
    float fraction = GetFractionPart(Number);
    int WholePart = (int) Number;

    if (fraction >= 0.5)
    {
        if (Number > 0)
            return ++WholePart;
        else 
            return --WholePart;
        
    }
    else 
    {
        return WholePart;
    }
}

int main()
{
    float input = ReadNumber("Enter Number: ");

    cout << "\nMy Round Result: " << myRound(input);
    cout << "\nC++ Round Result: " << round(input);
}
