// Fibonacci Series Recursion

# include "D:\Career\C++\AbuHadhoud\Libraries\MyInput.h"
# include "D:\Career\C++\AbuHadhoud\Libraries\MyFunctions.h"

using namespace std;

void PrintFibonacciSeriesUsingRecursion(short Number, int Prev1, int Prev2)
{
    if (Number < 1)
        return;
    else if (Number == 1)
        cout << setw(5) << Prev1 + Prev2;
    else
    {
        cout << setw(5) << Prev1 + Prev2;
        PrintFibonacciSeriesUsingRecursion(--Number, Prev1 + Prev2, Prev1);
    }
}

int main()
{
    PrintFibonacciSeriesUsingRecursion(10, 0, 1);

    return 0;
}