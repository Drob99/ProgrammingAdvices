// What is a Pointer?
# include <iostream>
using namespace std;

int main()
{
    int a = 10;

    cout << "a value         : " <<  a << endl;
    cout << "a address       : " << &a << endl;

    int* p;
    p = &a;

    cout << "Pointer value   : " <<  p << endl;
    cout << "Pointer address : " << &p << endl;

    return 0;
}