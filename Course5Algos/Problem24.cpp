// Max of Random Array

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

void FillArrayWithRandomNumber(int array[100], int &arrLength)
{
    arrLength = ReadPositiveNumber("Enter number of elements: ");
    for (int i = 0; i < arrLength; i++)
    {
        array[i] = RandomNumber(1, 100);
    }
}

int MaxNumberInArray(int array[100], int arrLength)
{
    int max = INT_MIN;

    for (int i = 0; i < arrLength; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

void SeedRandom()
{
    srand ((unsigned)time(NULL));
}

int main()
{
    srand ((unsigned)time(NULL));

    int array[100], arrLength;
    FillArrayWithRandomNumber(array, arrLength);

    cout << "\nArray Elements: ";
    PrintArray(array, arrLength);
    
    cout << "\nMax Number is: " << MaxNumberInArray(array, arrLength) << endl;

    return 0;
}