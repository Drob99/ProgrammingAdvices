#include <iostream>
#include "../Libraries/clsString.h"
using namespace std;

int main()
{
    clsString String1;
    clsString String2("Mohammed");

    String1.SetValue("Ali");

    cout << "String1 = " << String1.GetValue() << endl;
    cout << "String2 = " << String2.GetValue() << endl;

    cout << "Number of words: " << String1.CountEachWordInString();
    cout << "\nNumber of words: " << clsString::CountEachWordInString("Omar Bahaeldin Abdalla");
    return 0;
}
