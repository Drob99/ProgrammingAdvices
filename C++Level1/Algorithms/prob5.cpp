#include <iostream>
using namespace std;

struct stInfo
{
    short age;
    bool has_driver_license;
    bool has_recommendation;
};

stInfo ReadInfo(){
    stInfo info;
    cout << "Enter your age: \n";
    cin >> info.age;

    cout << "Do you have a driver license? (1/0): \n";
    cin >> info.has_driver_license;

    cout << "Do you have a recommendation? (1/0): \n";
    cin >> info.has_recommendation;

    return info;
}

bool isAccepted(stInfo info)
{

    return (info.has_recommendation || info.age > 21 && info.has_driver_license);
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