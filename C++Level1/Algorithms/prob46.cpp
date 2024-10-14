#include <iostream>

using namespace std;

void printForLetters()
{
    for (int i = 65; i <= 90; i++)
    {
        cout << char(i) << endl;
    }
}

void printWhileLetters()
{
    int i = 65;
    while (i <= 90)
    {
        cout << char(i) << endl;
        i++;
    }
}

int main()
{
    printForLetters();
    return 0;
}