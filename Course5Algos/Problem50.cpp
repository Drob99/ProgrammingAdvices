// MySqrt

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


int mySqrt(float Number)
{
    return pow(Number, 0.5);
}

int main()
{
    float input = ReadNumber("Enter Number: ");

    cout << "\nMy Sqrt Result: " << mySqrt(input);
    cout << "\nC++ Sqrt Result: " << sqrt(input);
}
