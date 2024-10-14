#include <iostream>
#include <string>

using namespace std;

void ReadNumbers(int& Num1, int& Num2, int& Num3)
{
    cout << "Enter number 1: ";
    cin >> Num1;

    cout << "Enter number 2: ";
    cin >> Num2;

    cout << "Enter number 3: "; 
    cin >> Num3;
}

int MaxOf3Numbers(int Num1, int Num2, int Num3)
{
    if (Num1 > Num2)
        if (Num1 > Num3)
            return Num1;
        else
            return Num3;
    else
        if (Num2 > Num3)
            return Num2;
        else
            return Num3;
}

void PrintResults(int Max)
{
    cout << "\n The maximum is " << Max << "." << endl;
}



int main()
{
    int Num1, Num2, Num3;
    ReadNumbers(Num1, Num2, Num3);
    PrintResults(MaxOf3Numbers(Num1, Num2, Num3));

    return 0;
}