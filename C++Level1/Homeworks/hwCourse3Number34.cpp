// Using procedures and functions

#include <iostream>

using namespace std;

int MySumFunction()
{
    int num1, num2;
    cout << "Enter a number: ";
    cin >> num1;
    cout << "Enter another number: ";
    cin >> num2;
    return num1 + num2;
}

void MySumProcedure()
{
        int num1, num2;
    cout << "Enter a number: ";
    cin >> num1;
    cout << "Enter another number: ";
    cin >> num2;
    cout << "The sum is " << num1 + num2 << endl;
}

int main()
{
    MySumFunction;
    MySumProcedure;
    return 0;

}