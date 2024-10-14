#include <iostream>

using namespace std;

enum enPassFail {Pass = 1, Fail = 2};

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

enPassFail CheckAverage(float Average)
{
    if (Average >= 50)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;
}

void PrintResults(float average)
{
    cout << "The average is " << average << ".";
    
    if (CheckAverage(average) == enPassFail::Pass)
    {
        cout << "\n You passed." << endl;
    }
    else
    {
        cout << "\n You failed." << endl;
    }
}

int main()
{
    int Num1, Num2, Num3;
    ReadNumbers(Num1, Num2, Num3);
    PrintResults(CalculateAverage(Num1, Num2, Num3));
    return 0;
}