// return number index in array
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

int ReadNumber(string message)
{
    int num;
    cout << message << endl;
    cin >> num;
    return num;
}


int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
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

bool IsNumberInArray(int array[], int arrLength, int Number)
{
    
    cout << "\nNumber you are looking for is: " << Number << "\n";
    for (int i = 0; i < arrLength; i++)
    {
        if (array[i] == Number)
        {

            return true;
        }
    }
    
    return false; // not there
}


int main()
{
    srand((unsigned)time(NULL));

    int array[100], arrLength; 
    FillArrayWithRandomNumber(array, arrLength);

    cout << "\nArray elements:\n";

    PrintArray(array, arrLength);

    int Number = ReadNumber("\nPlease enter a number to search for: ");
    bool NumberPosition = IsNumberInArray(array, arrLength, Number);

    if (!NumberPosition)
        cout << "No, The number is not found :-(" << "\n";
    else
    {
        cout << "Yes, The number is found :-)" << "\n";
    }
    return 0;
}