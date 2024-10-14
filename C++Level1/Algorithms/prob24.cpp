#include <iostream>

using namespace std;

short ReadAge()
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

void PrintResult(int Age)
{
    if (ValidateNumberInRange(Age, 18, 45))
        cout << "Valid";

    else
        cout << "Invalid";
}

int main()
{
    PrintResult(ReadAge());

    return 0;
}