#include <iostream>

using namespace std;

int main()
{
    cout << "Please Enter string1: ";
    string st1;
    getline(cin, st1);

    cout << "Please Enter string2: ";
    string st2;
    cin >> st2;

    cout << "Please Enter string3: ";
    string st3;
    cin >> st3;

    cout << "The length of string1 is " << st1.length() << endl;
    cout << "Characters at 0, 2, 4, 7 are: " << st1[0] << " " << st1[2] << " " << st1[4] << " " << st1[7] << endl;
    cout << "Concatenating st2 and st3 = " << st2 + st3 << endl;
    cout << st2 << " * " << st3 << " = " << stoi(st2) * stoi(st3) << endl;
}