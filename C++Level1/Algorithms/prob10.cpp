#include <iostream>

using namespace std;


void ReadNumbers( int& Num1, int& Num2, int& Num3)
{
    cout << "Enter mark 1: ";
    cin >> Num1;

    cout << "Enter mark 2: ";
    cin >> Num2;

    cout << "Enter mark 3: ";
    cin >> Num3;
}

int SumOf3Marks(int Num1, int Num2, int Num3)
{
    return Num1 + Num2 + Num3;
}

float CalculateAverage(int  Num1, int Num2, int Num3)
{
    return (float) SumOf3Marks(Num1, Num2, Num3) / 3;
}
void PrintResults(float average)
{
    cout << "The average is " << average << ".";
}
int main()
{
    int Num1, Num2, Num3;
    ReadNumbers(Num1, Num2, Num3);
    PrintResults(CalculateAverage(Num1, Num2,  Num3));
    return 0;
}