// Call By Ref Using Pointers

# include <iostream>
using namespace std;

// by ref
// void swap(int& n1, int& n2)
// {
//     int temp;
//     temp = n1;
//     n1 = n2;
//     n2 = temp;
// }

//by pointer
void swap(int* n1, int* n2)
{
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main()
{
    int a = 1, b =2;

    cout << "Before Swapping: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    swap(&a, &b);

    cout << "\nAfter Swapping: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}