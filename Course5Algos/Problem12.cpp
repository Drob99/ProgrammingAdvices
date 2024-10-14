// Inverted pattern
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

void PrintInvertedPattern(int Number)
{
    cout << "\n";
    while (Number > 0)
    {
        for (int i = 0; i < Number; i++)
            cout << Number;
        cout << "\n";
        Number --;
    }
}

int main()
{
    PrintInvertedPattern(ReadPositiveNumber("Please enter positive number: "));

    return 0;
}