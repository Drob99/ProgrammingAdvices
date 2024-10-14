// Sum of 2 arrays to a 3rd one

# include <iostream>
# include <cmath>
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

void CopyArray(int OriginalArray[], int CopiedArray[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        CopiedArray[i] = OriginalArray[i];
    }
}

void SumOf2Arrays(int array1[], int array2[], int array3[], int arr1Length, int arr2Length, int &arr3Length)
{
    if (arr1Length != arr2Length)
    {
        cout << "Cannot add due to different lengths.";
        return;
    }

    arr3Length = arr1Length;

    for (int i = 0; i < arr3Length; i++)
    {
        array3[i] = array1[i] + array2[i];
    }
}

int main()
{
    srand ((unsigned)time(NULL));

    int array1[100], arr1Length;
    FillArrayWithRandomNumber(array1, arr1Length);

    cout << "\nArray 1 elements:\n";
    PrintArray(array1, arr1Length);

    int array2[100], arr2Length = 0;
    FillArrayWithRandomNumber(array2, arr2Length);

    cout << "\nArray 2 elements:\n";
    PrintArray(array2, arr2Length);

    cout << "\nSum of array1 and array2 elements:\n";
    int array3[100], arr3Length;
    SumOf2Arrays(array1, array2, array3, arr1Length, arr2Length, arr3Length);
    PrintArray(array3, arr3Length);

    return 0;
}