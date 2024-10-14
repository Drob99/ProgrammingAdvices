// Add Number to Array Semi Dynamic
# include <iostream>
using namespace std;

int ReadNumber(string message)
{
    int num;
    cout << message;
    cin >> num;
    return num;
}

void PrintArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";

    }

    cout << "\n";
}

void AddNumberToArray(int array[], int &arrLength, int number)
{
    array[arrLength] = number;
    arrLength++;
}

void ReadArraySemiDynamic(int array[], int &arrLength, int MaxLength)
{
    int number; 
    bool input;
    do
    {
        number = ReadNumber("\nPlease enter Number? ");
        AddNumberToArray(array, arrLength, number);
        input = ReadNumber("Do you want to add more numbers?[0]:No,[1]:yes? ");
    } while (input && arrLength < MaxLength);
    
}

int main()
{

    int array[100], arrLength = 0; 
    ReadArraySemiDynamic(array, arrLength, 100);

    cout << "Array Length: " << arrLength << "\n";
    cout << "Array Elements: ";
    PrintArray(array, arrLength);
    
    return 0;
}