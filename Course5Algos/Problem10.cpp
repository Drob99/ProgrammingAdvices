// Print Digits in Order

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

//Recursion
// void PrintNumber(int Number)
// {
//     if (Number == 0)
//         return;
//     PrintNumber(Number / 10);
//     cout << "\n" << Number % 10;
// }

void PrintDigits(int Number)
{
    while (Number > 0)
    {
        cout << Number % 10 << '\n';
        Number /= 10;
    }
}

int main()
{
    PrintDigits(ReverseNumber(ReadPositiveNumber("Enter a number: ")));
}