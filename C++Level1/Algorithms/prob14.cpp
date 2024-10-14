#include <iostream>

using namespace std;


void ReadNumbers(int& Num1, int& Num2)
{
    cout << "Enter number 1: ";
    cin >> Num1;

    cout << "Enter number 2: ";
    cin >> Num2;
}

//passing by reference
void SwapNumbers(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
    
}

void PrintNumbers(int num1, int num2)
{
    cout << "Number 1 is " << num1 << "." << endl;
    cout << "Number 2 is " << num2 << ".\n" << endl;
}
int main()
{
    int num1, num2;
    ReadNumbers(num1, num2);
    PrintNumbers(num1, num2);
    SwapNumbers(num1, num2);
    PrintNumbers(num1, num2);

    return 0;
}