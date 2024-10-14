// Copy Prime Numbers

# include <iostream>
# include <cmath>
using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2};

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

enPrimeNotPrime CheckPrime(int num){
    int M = round(num / 2);
    if (num == 0  || num == 1)
        return NotPrime;

    for (int i = 2; i <= M; i++){
        if (num % i == 0)
            return NotPrime;
    }

    return Prime;
}

void CopyPrimeArrayElements(int OriginalArray[], int CopiedArray[], int &arr2Length, int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (CheckPrime(OriginalArray[i]) == Prime)
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
    CopyPrimeArrayElements(array, array2, arr2Length, arrLength);

    cout << "\nArray 2 Prime Numbers:\n";
    PrintArray(array2, arr2Length);

    return 0;
}