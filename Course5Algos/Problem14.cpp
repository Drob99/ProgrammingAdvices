// Inverted Letter Pattern
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

void PrintInvertedLetterPattern(int Number)
{
    cout << "\n";
    for (int i = 'A' + Number - 1; i >= 'A'; i--)
    {
        for (int j = 1; j <=  Number - (Number + 'A' - 1 - i); j++)
        {
            cout << char(i);

        }
        cout << "\n";
    }
}

int main()
{
    int Number = ReadPositiveNumber("Enter a positive number: ");
    PrintInvertedLetterPattern(Number);
}