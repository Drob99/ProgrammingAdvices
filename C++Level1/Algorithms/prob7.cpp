#include <iostream>

using namespace std;

int ReadNumber()
{
    cout << "Enter a number: ";
    int n;
    cin >> n;
    return n;
}

float CalculateHalfNumber(int Num) //any operation in separate function
{
    return (float) Num / 2;
}

void PrintResults(int Num)
{
    cout << "Half of " + to_string(Num) + " is " + to_string(CalculateHalfNumber(Num)) + ".";
}
int main()
{
    PrintResults(ReadNumber());

    return 0;
}