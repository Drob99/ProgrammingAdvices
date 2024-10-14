// Calculate Sum of Digits of a number.
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

int SumOfDigits(int Number)
{
    int sum = 0;
    while (Number > 0)
    {
        sum += Number % 10;
        Number /= 10;
    }
    return sum;
}

void PrintResults(int Number)
{
    cout << "\nSum Of Digits = " << Number;
}

int main(){
    PrintResults(SumOfDigits(ReadPositiveNumber("Please enter a positive number: ")));
}