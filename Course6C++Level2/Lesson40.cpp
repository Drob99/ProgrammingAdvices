// Arrays and Pointers
# include <iostream>
using namespace std;

int main()
{
    int arr[4] = {10, 20, 30, 40};
    int *ptr;
    ptr = arr;

    // ptr is &arr[1]
    // ptr + i is &arr[1+i]

    cout << "Addresses are:\n";

    // cout << ptr << endl;
    // cout << ptr + 1 << endl;
    // cout << ptr + 2 << endl;
    // cout << ptr + 3 << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << ptr + i << endl;
    }

    cout << "\nValues are:\n";

    for (int i = 0; i < 4; i++)
    {
        cout << *(ptr + i) << endl;
    }

    // cout << *(ptr) << endl;
    // cout << *(ptr + 1) << endl;
    // cout << *(ptr + 2) << endl;
    // cout << *(ptr + 3) << endl;

    return 0;
}