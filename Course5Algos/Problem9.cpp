// Calculate all digit frequencies.
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


int CalculateDigitFrequency(int Number, short Digit)
{
    int freq = 0;
    while (Number > 0)
    {
        if (Number % 10 == Digit) freq ++;
        Number /= 10;
    }

    return freq;
}

void PrintAllDigitFrequency(int Number)
{
    for (int i = 0; i <= 9; i++)
    {
        short freq = CalculateDigitFrequency(Number, i);
        if (freq > 0)
            cout << "\nDigit " << i << " Frequency is " << freq << " Time(s).";
    }
}

int main()
{
    int Number = ReadPositiveNumber("Please enter a positive number: ");
    PrintAllDigitFrequency(Number);
}