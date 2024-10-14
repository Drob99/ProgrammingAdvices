// Repeated Elements Count In Array
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

void ReadArray(int array[], int& length)
{
    length = ReadPositiveNumber("Enter array length: ");

    cout << "\nEnter array elements: \n";
    for (int i = 0; i < length; i++)
    {
        cout << "Element [" << i+1 << "]: "; 
        cin >> array[i];
    }
    cout << endl;
}

void PrintArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";

    }

    cout << "\n";
}

int TimesRepeated(int Number, int array[], int arrLength)
{
    int times = 0;
    for (int i = 0; i < arrLength; i++)
        if (array[i] == Number)
            times++;
    return times;
}

int main()
{
    int array[100], arrLength, NumberToCheck; 

    ReadArray(array, arrLength);

    NumberToCheck = ReadPositiveNumber("Enter the number you want to check: ");

    cout << "\nOriginal array: ";
    PrintArray(array, arrLength);

    cout << "\nNumber" << NumberToCheck;
    cout << " is repeated ";
    cout << TimesRepeated(NumberToCheck, array, arrLength) << " time(s)\n";

    return 0;
}