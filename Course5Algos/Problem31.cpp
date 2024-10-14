// Shuffle Ordered Array
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

void FillArrayWith1ToN(int array[], int &arrLength)
{
    arrLength = ReadPositiveNumber("Enter number of elements: ");
    for (int i = 0; i < arrLength; i++)
    {
        array[i] = i+1;
    }
}

bool NumberIsInArray(int Number, int array[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        if (array[i] == Number)
            return true;
    return false;
}

int RandomNumberNotRepeatedInArray(int From, int To, int array[], int arrLength)
{
    int Number;
    do
    {
        Number = RandomNumber(From, To);
    } while (NumberIsInArray(Number, array, arrLength));
    return Number; 
}

void CopyArray(int OriginalArray[], int CopiedArray[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        CopiedArray[i] = OriginalArray[i];
    }
}

// my function
void ShuffleOrderedArray(int array[], int arrLength)
{
    int RandomIndices[arrLength];

    for (int i = 0; i < arrLength; i++)
    {
        RandomIndices[i] = RandomNumberNotRepeatedInArray(0, arrLength-1, RandomIndices, arrLength);
    }

    int ShuffledArray[arrLength];
    for (int i = 0; i < arrLength; i++)
    {
        ShuffledArray[i] = array[RandomIndices[i]]; 
    }

    CopyArray(ShuffledArray, array, arrLength);
}

void SwapNumbers(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
    
}

// MAH's Function
void ShuffleArray(int array[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        SwapNumbers(array[RandomNumber(0, arrLength-1)], array[RandomNumber(0, arrLength-1)]);
}

int main()
{
    srand ((unsigned)time(NULL));

    int array1[100], arr1Length;
    FillArrayWith1ToN(array1, arr1Length);

    cout << "\nArray elements before shuffle:\n";
    PrintArray(array1, arr1Length);

    ShuffleArray(array1, arr1Length);

    cout << "\n Array elements after shuffle:\n";
    PrintArray(array1, arr1Length);

    return 0;
}