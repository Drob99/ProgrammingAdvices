// Prints a number in reverse
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

int ReverseNumber(int Number)
{
    int result = 0;
    while (Number > 0)
    {
        result = result * 10 + Number % 10; // Wow !!
        Number /= 10;
    }
    return result;
}

void PrintDigitsInReverse(int Number)
{
    cout << "\nReverse is:\n";
    cout << ReverseNumber(Number);
}

int main()
{
    PrintDigitsInReverse(ReadPositiveNumber("Enter a number: "));
}