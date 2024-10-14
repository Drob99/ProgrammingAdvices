#include <iostream>

using namespace std;

int ReadNumber()
{
    int num;
    cout << "Please enter a number: ";
    cin >> num;
    return num;
}

void printForReverseLoop(int num)
{
    cout << "\nUsing For Loop\n";
    for (int i = num; i >= 1; i--)
    {
        cout << i << endl;
    }
}

void printWhileReverseLoop(int num)
{
    cout << "\nUsing While Loop\n";
    int i = num + 1;
    while (i > 1)
    {
        i--;
        cout << i << endl;
    }
}

void printDoWhileReverseLoop(int num)
{
    int count = num + 1;
    cout << "\nUsing Do While Loop\n";
    do
    {
        count--;
        cout << count << endl;
    } while (count > 1);
    
    
}

int main()
{
    int N = ReadNumber();

    printForReverseLoop(N);
    printWhileReverseLoop(N);
    printDoWhileReverseLoop(N);

    return 0;
}