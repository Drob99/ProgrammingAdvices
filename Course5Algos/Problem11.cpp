// Checks palindrome
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

bool CheckPalindrome(int Number)
{
    return Number == ReverseNumber(Number);
}

void PrintResults(int Number)
{
    if (CheckPalindrome(Number))
        cout << "\nYes, it is a Palindrome number.";
    else
        cout << "\nNo, it is NOT a Palindrome number.";
}
int main()
{
    PrintResults(ReadPositiveNumber("Enter a positive number: "));
}
