// Count Even Numbers in array

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


int EvenCount(int arr[], int arrLength)
{
    int count = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] % 2 == 0)
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

    cout << "\nEven Numbers count is: " << EvenCount(array, arrLength);
    

    return 0;
}