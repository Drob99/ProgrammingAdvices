// Print Digit Frequency
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

int ReadDigit(string message)
{
    int digit;
    do 
    {
        cout << message << endl;
        cin >> digit;
    } while (digit < 0 || digit > 9);

    return digit;
}

int CalculateDigitFrequency(int Number, int Digit)
{
    int freq = 0;
    while (Number > 0)
    {
        if (Number % 10 == Digit) freq ++;
        Number /= 10;
    }

    return freq;
}

void PrintResults()
{
    int Number = ReadPositiveNumber("Please enter positive number: ");
    short Digit = ReadDigit("Please enter a digit (0-9): ");
    cout << "\nDigit " << Digit << " Frequency is " << CalculateDigitFrequency(Number, Digit) << " Time(s)";
}

int main()
{
    PrintResults();
}