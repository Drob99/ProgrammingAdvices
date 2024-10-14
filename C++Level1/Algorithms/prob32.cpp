#include <iostream>

using namespace std;


int ReadNumber()
{
    int num;
    cout << "Please enter a number: ";
    cin >> num;
    return num;
}

int ReadPower()
{
    int power;
    cout << "Please enter a power: ";
    cin >> power;
    return power;
}

float for_power(int number, int power)
{
    if (power == 0) {return 1;}

    int orig = number;

    for (int i = 1; i < power; i++)
    {
        number *= orig;
    }
    return number;
}

float while_power(float number, int power)
{
    if (power == 0) {return 1;}

    int orig = number;
    int i = 1;

    while (i < power)
    {
        number *= orig;
        i++;
    }
    return number;
}

int main() // call stack starts from right to left
{
    cout << endl << "Result = " <<  for_power(ReadNumber() , ReadPower());
    return 0;
}