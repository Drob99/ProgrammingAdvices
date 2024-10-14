// Print Letter Pattern
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

void PrintLetterPattern(int Number)
{
    cout << "\n";
    for (int i = 'A'; i <= 'A' + Number - 1; i++)
    {
        for (int j = 1; j <=  i - 'A' + 1; j++)
        {
            cout << char(i);

        }
        cout << "\n";
    }
}

int main()
{
    int Number = ReadPositiveNumber("Enter a positive number: ");
    PrintLetterPattern(Number);
}