// Copy Array In Reverse Order

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

int RandomNumber(int From, int To)
{
    return rand() % (To-From+1) + From;
}

void PrintArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";

    }

    cout << "\n";
}

void FillArrayWithRandomNumber(int array[], int &arrLength)
{
    arrLength = ReadPositiveNumber("Enter number of elements: ");
    for (int i = 0; i < arrLength; i++)
    {
        array[i] = RandomNumber(1, 100);
    }
}

void CopyArrayInReverseOrder(int OriginalArray[], int CopiedArray[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        CopiedArray[i] = OriginalArray[arrLength-1-i];
    }
}


int main()
{
    srand ((unsigned)time(NULL));

    int array[100], arrLength;
    FillArrayWithRandomNumber(array, arrLength);

    cout << "\nArray 1 elements:\n";
    PrintArray(array, arrLength);

    int array2[100];
    CopyArrayInReverseOrder(array, array2, arrLength);
    cout << "\nArray 2 elements after copying array 1 in reversed order:\n";
    PrintArray(array2, arrLength);

    return 0;
}