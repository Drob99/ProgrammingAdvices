// Fibonacci Series

#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"

using namespace std;

void PrintFibonacciSeriesUsingLoop(short Number)
{
    int FebNum = 1;
    int Prev2 = 1;
    int Prev1 = 1;
    for (short i = 0; i < Number; i++)
    {
        if (i == 0)
            cout << setw(5) << 1;
        else if (i == 1)
            cout << setw(5) << 1;

        else
        {
            FebNum = Prev2 + Prev1;
            cout << setw(5) << FebNum;
            Prev2 = Prev1;
            Prev1 = FebNum;
        }
    }
}

int main()
{
    PrintFibonacciSeriesUsingLoop(10);

    return 0;
}