// Copy only prime numbers
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

void CopyArray(int OriginalArray[], int CopiedArray[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        CopiedArray[i] = OriginalArray[i];
    }
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

void CopyArrayOnlyPrime(int OriginalArray[], int TargetArray[], int arrLength, int& arr2Length)
{

    for (int i = 0; i < arrLength; i++)
        if (CheckPrime(OriginalArray[i]) == Prime){
            TargetArray[arr2Length] = OriginalArray[i];
            arr2Length++;
        }

}

int main()
{
    srand ((unsigned)time(NULL));

    int array[100], arrLength;
    FillArrayWithRandomNumber(array, arrLength);

    cout << "\nArray 1 elements:\n";
    PrintArray(array, arrLength);

    int array2[100], arr2Length = 0;
    CopyArrayOnlyPrime(array, array2, arrLength, arr2Length);

    cout << "\nPrime Numbers in Array2:\n";
    PrintArray(array2, arr2Length);
    cout << arr2Length;

    return 0;
}