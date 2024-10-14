# include <iostream>
# include "MyLib.h" // bcz it's local

using namespace std;
using namespace MyLib;

int main()
{
    Test();
    cout << Sum2Numbers(10, 20);

    return 0;
}