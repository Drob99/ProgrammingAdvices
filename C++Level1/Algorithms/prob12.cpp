#include <iostream>
#include <string>

using namespace std;

void ReadNumbers(int& Num1, int& Num2)
{
    cout << "Enter number 1: ";
    cin >> Num1;

    cout << "Enter number 2: ";
    cin >> Num2;
}

int MaxOf2Numbers(int Num1, int Num2)
{
    return Num1 ? Num1 > Num2 : Num2;
}

void PrintResults(int Max)
{
    cout << "\n The maximum is " << Max << "." << endl;
}



int main()
{
    int Num1, Num2;
    ReadNumbers(Num1, Num2);
    PrintResults(MaxOf2Numbers(Num1, Num2));

    return 0;
}