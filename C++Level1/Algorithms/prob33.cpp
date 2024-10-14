// grade letters

#include <iostream>

using namespace std;

int ReadNumberInRange(int From, int To)
{
    int num;
    do
    {
        cout <<  "Enter Number: ";
        cin >> num;
    }while(num < From || num > To);

    return num;
}

char GetGradeLetter(int grade)
{
    if (grade >= 90)
    {
        return 'A';
    }
    else if (grade >= 80)
    {
        return 'B';
    }
    else if (grade >= 70)
    {
        return 'C';
    }
    else if (grade >= 60)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }

}

int main()
{
    cout <<  GetGradeLetter(ReadNumberInRange(0, 100)) << endl;

    return 0;
}