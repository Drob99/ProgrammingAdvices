// Copy Distinct Numbers to Array

# include <iostream>
# include <cmath>
using namespace std;



void PrintArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";

    }

    cout << "\n";
}

bool IsNumberInArray(int array[], int arrLength, int Number)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (array[i] == Number)
        {

            return true;
        }
    }
    
    return false; // not there
}


void AddNumberToArray(int array[], int &arrLength, int number)
{
        array[arrLength] = number;
        arrLength++;
}

void CopyDistinctNumbers(int OriginalArray[], int CopiedArray[], int &arr2Length, int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        if (!IsNumberInArray(CopiedArray, arr2Length, OriginalArray[i]))
            AddNumberToArray(CopiedArray, arr2Length, OriginalArray[i]);
}


int main()
{

    // You can make it in a separate method named FillArray
    int array[100] = {10, 10, 10, 50, 50, 70, 70, 70, 70, 90};
    int arrLength = 10;

    cout << "\nArray 1 elements:\n";
    PrintArray(array, arrLength);

    int array2[100], arr2Length = 0;
    CopyDistinctNumbers(array, array2, arr2Length, arrLength);

    cout << "\nArray 2 distinct elements:\n";
    PrintArray(array2, arr2Length);

    return 0;
}