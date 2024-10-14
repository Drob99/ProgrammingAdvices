// display powers of 2, 3, and 4

#include <iostream>
#include <cmath>

using namespace std;

int ReadNumber()
{
    cout << "Please Enter a number: ";
    int number;
    cin >> number;
    return number;
}
void printPowers(int number)
{
    cout << "Powers of 2, 3, and 4 are: " << endl;
    int a,b,c;
    a = number * number;
    b = number * number * number;
    c = number * number * number * number;
    cout << a << " " << b << " " << c << endl;
}

int main()
{
    printPowers(ReadNumber());
    return 0;
}