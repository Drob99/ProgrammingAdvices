#include <iostream>
using namespace std;

struct stInfo{
    string FirstName;
    string LastName;
};

stInfo ReadInfo()
{
    stInfo info;
    cout << "Enter your first name: \n";
    cin >> info.FirstName;

    cout << "Enter your last name: \n";
    cin >> info.LastName;

    return info;
}

string GetFullName(stInfo Info)
{
    return Info.FirstName + " " + Info.LastName;
}

void PrintFullName(string FullName)
{
    cout << "\n Your full name is: " + FullName + ".\n";
}

int main()
{
    PrintFullName(GetFullName(ReadInfo()));

    return 0;
}