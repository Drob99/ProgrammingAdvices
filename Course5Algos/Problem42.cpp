// Count Odd Numbers in Array

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

void CopyOddArrayElements(int OriginalArray[], int CopiedArray[], int &arr2Length, int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (OriginalArray[i] % 2 == 1)
            AddNumberToArray(CopiedArray, arr2Length, OriginalArray[i]);
    }
}

int OddCount(int arr[], int arrLength)
{
    int count = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] % 2 == 1)
            count ++;
    }
    return count;
}


int main()
{
    srand ((unsigned)time(NULL));

    int array[100], arrLength = 0;
    FillArrayWithRandomNumber(array, arrLength);

    cout << "\nArray elements:\n";
    PrintArray(array, arrLength);

    cout << "\nOdd Numbers count is: " << OddCount(array, arrLength);
    

    return 0;
}