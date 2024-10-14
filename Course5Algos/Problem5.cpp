// Print Digits in Reversed Order
# include <iostream>

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

void PrintDigitsInReverse(int Number)
{
    while (Number > 0)
    {
        cout << Number % 10 << '\n';
        Number /= 10;
    }
}

int main()
{
    PrintDigitsInReverse(ReadPositiveNumber("Enter a number: "));
}