#include <iostream>

using namespace std;

int ReadAge()
{
    short unsigned age;
    cout << "Enter your age: ";
    cin >> age;

    return age;

}

bool ValidateNumberInRange(int Number, int From, int To)
{
    return Number >= From && Number <= To;
}

int ReadUntilAgeBetween(int From, int To){
    int age = 0;

    do
    {
        age = ReadAge();
    } while (!ValidateNumberInRange(age, From, To));
    
}

void PrintResult(int Age)
{
    if (ValidateNumberInRange(Age, 18, 45))
        cout << "Valid";

    else
        cout << "Invalid";
}

int main()
{
    PrintResult(ReadUntilAgeBetween(18, 45));

    return 0;
}