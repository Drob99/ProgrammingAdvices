// Is Palindrome Array

# include <iostream>
# include <cmath>
using namespace std;

void FillArray(int array[], int &arrLength)
{
    arrLength = 6;
    array[0] = 10;
    array[1] = 20;
    array[2] = 30;
    array[3] = 30;
    array[4] = 20;
    array[5] = 10;
}


void PrintArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";

    }

    cout << "\n";
}



bool IsPalindromeArray(int array[], int arrLength)
{
    int i = 0;
    while (i < arrLength - 1 - i)
    {
        if (array[i] != array[arrLength - 1 - i])
            return false;
        i++ ;
    }

    return true;
}

int main()
{
    int array[100], arrLength = 0;
    FillArray(array, arrLength);

    cout << "\nArray Elements:\n";
    PrintArray(array, arrLength);

    if (IsPalindromeArray(array, arrLength))
        cout << "\nYes array is Palindrome";
    else 
        cout << "\nNo array is not Palindrome";

    return 0;
}