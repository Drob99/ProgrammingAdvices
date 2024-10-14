// What is a Pointer?
# include <iostream>
using namespace std;

int main()
{
    int a = 10;

    cout << "a value            : " <<  a << endl;
    cout << "a address          : " << &a << endl;

    int* p = &a;

    cout << "Pointer value      : " <<  p << endl;
    cout << "Pointer address    : " << &p << endl;
    cout << "a value by pointer : " << *p << endl;

    *p = 20;

    cout << "a value            : " <<  a << endl;
    cout << "a value by pointer : " << *p << endl;

    a = 30;

    cout << "a value            : " <<  a << endl;
    cout << "a value by pointer : " << *p << endl;

    return 0;
}