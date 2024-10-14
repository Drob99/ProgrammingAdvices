#include <iostream>

using namespace std;


void ReadNumbers( int& Num1, int& Num2, int& Num3)
{
    cout << "Enter a number: ";
    cin >> Num1;

    cout << "Enter a number: ";
    cin >> Num2;

    cout << "Enter a number: ";
    cin >> Num3;
}

int SumOf3Numbers(int Num1, int Num2, int Num3)
{
    return Num1 + Num2 + Num3;
}

void PrintResults(int Total)
{
    cout << "The sum of the 3 numbers is " << Total << ".";
}
int main()
{
    int Num1, Num2, Num3;
    ReadNumbers(Num1, Num2, Num3);
    PrintResults(SumOf3Numbers(Num1, Num2, Num3));
    return 0;
}