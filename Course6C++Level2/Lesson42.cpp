// Pointer & Void
# include <iostream>
using namespace std;

int main()
{
    void *ptr; // generic pointer

    int x = 50;
    float f1 = 10.5;

    ptr = &f1;

    // cout << *ptr; // gives error needs casting

    // cout << *((float*)ptr) << endl; // C style casting || less safe
    cout << *(static_cast<float*>(ptr)) << endl; // C++ safer

    ptr = &x;

    cout << *(static_cast<int*>(ptr)) << endl;

    return 0;
}