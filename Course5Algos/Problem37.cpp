// Resolve Copy Array Using AddNumberToArray
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

void AddNumberToArray(int array[], int &arrLength, int number)
{
    array[arrLength] = number;
    arrLength++;
}

void CopyArrayUsingAddArrayElement(int OriginalArray[], int CopiedArray[], int &arr2Length, int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        AddNumberToArray(CopiedArray, arr2Length, OriginalArray[i]);
    }
}


int main()
{
    srand ((unsigned)time(NULL));

    int array[100], arrLength = 0;
    FillArrayWithRandomNumber(array, arrLength);

    cout << "\nArray 1 elements:\n";
    PrintArray(array, arrLength);

    int array2[100], arr2Length = 0;
    CopyArrayUsingAddArrayElement(array, array2, arr2Length, arrLength);

    cout << "\nArray 2 elements after copy:\n";
    PrintArray(array2, arr2Length);

    return 0;
}