#include <iostream>

using namespace std;

int ReadPositiveNumber(string message)
{
    int num;
    do
    {
        cout << message << endl;
        cin >> num;
    } while (num < 0);
    
    return num;
}

int for_factorial(int num)
{
    int fact = 1;
    for (int i = num; i > 1; i--)
    {
        fact *= i;
    }
    return fact;
}

int while_factorial(int num)
{
    while (num < 0)
    {
        cout << "Please enter a positive number: ";
        cin >> num;
    }

    int fact = 1;
    int i = num;
    while (i > 1)
    {
        fact *= i;
        i--;
    }
    return fact;
}

int main()
{
    cout << while_factorial(ReadPositiveNumber("Please Enter a Positive Number???")) << endl;
    return 0;
}