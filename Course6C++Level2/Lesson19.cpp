// Recursion
# include <iostream>

using namespace std;

void PrintNumbers(int N, int M)
{
    if (N <= M)
    {
        cout << N << endl;
        PrintNumbers (N+1, M);
    }
}

void PrintNumbersFromMtoN (int M, int N)
{
    if (N <= M)
    {
        cout << M << endl;
        PrintNumbersFromMtoN(M-1, N);
    }
}

int MyRecursivePower(int Base, int Power)
{
    if (Power == 0)
        return 1;
    if (Power == 1)
        return Base;

    return Base * MyRecursivePower(Base, Power-1);
}

int main()
{
    PrintNumbers(1, 4);
    cout << "\n";
    PrintNumbersFromMtoN(4, 1);
    cout << "\n";

    cout << MyRecursivePower(2, 3);
    return 0;
}
