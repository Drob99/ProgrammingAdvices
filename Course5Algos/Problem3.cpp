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

bool IsDivisor(int dividend, int divisor)
{
    return (dividend % divisor) == 0;
}

int SumOfDivisorsList (int Number){
    int sum = 0;
    for (int i = 1; i <= Number / 2; i++)
    {
        if (IsDivisor(Number, i))
            sum += i;
    }
    return sum;
}

bool IsPerfectNumber(int Number)
{
    return SumOfDivisorsList(Number) == Number;
}

void PrintResults(int Number)
{
    if (IsPerfectNumber(Number))
        cout << Number << " is perfect.";
    else
        cout << Number << " is not perfect.";
}

int main(){
    PrintResults(ReadPositiveNumber("Enter a number: "));
    return 0;
}