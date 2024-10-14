// Print Number Pattern
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

void PrintNumberPattern(int Number)
{
    cout << "\n";
    for (int i = 1; i <= Number; i++)
    {
        for (int j = 0; j < i; j++)
            cout << i;
        cout << "\n";
    }
}

int main()
{
    PrintNumberPattern(ReadPositiveNumber("Please enter positive number: "));

    return 0;
}