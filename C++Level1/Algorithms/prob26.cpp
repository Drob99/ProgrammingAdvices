#include <iostream>

using namespace std;

int ReadNumber()
{
    int num;
    cout << "Please enter a number: ";
    cin >> num;
    return num;
}

void printForLoop(int num)
{
    cout << "\nUsing For.\n";
    for (int i = 1; i <= num; i++)
    {
        cout << i << endl;
    }
}

void printWhileLoop(int num)
{
    cout << "\nUsing While.\n";
    int i = 0;
    while (i < num)
    {
        i++;
        cout << i << endl;
    }
}

void printDoWhileLoop(int num){
    int count = 0;

    cout << "\nUsing Do While.\n";

    do
    {
        count ++;
        cout << count << endl;
    } while (count < num);
    
}

int main()
{
    int N = ReadNumber();
    printForLoop(N);
    printWhileLoop(N);
    printDoWhileLoop(N);
    return 0;
}