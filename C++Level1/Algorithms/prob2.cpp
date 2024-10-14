//print name on screen using procedure
#include <iostream>
#include <string>
using namespace std;

string ReadName()
{
    string name;
    cout << "Enter your name: \n";
    getline(cin, name);
    return name;
}

void printName(string name)
{
    cout << name << endl;
}

int main()
{
    printName(ReadName());
    return 0;
}