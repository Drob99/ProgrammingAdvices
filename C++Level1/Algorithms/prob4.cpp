#include <iostream>
using namespace std;

struct stInfo
{
    short age;
    bool has_driver_license;
};

stInfo ReadInfo(){
    stInfo info;
    cout << "Enter your age: ";
    cin >> info.age;

    cout << "Do you have a driver license? (1/0): ";
    cin >> info.has_driver_license;

    return info;
}

bool isAccepted(stInfo info)
{
    return (info.age > 21 && info.has_driver_license == true);
}

void printResult(stInfo info)
{
    if (isAccepted(info))
        cout << "\n Hired";
    else
        cout << "\n Rejected";
}

int main()
{
    printResult(ReadInfo());

    return 0;
}