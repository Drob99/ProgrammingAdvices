#include <iostream>

using namespace std;

struct strInfo
{
    string first_name;
    string last_name;
    int age;
    string phone;
};

void read_info(strInfo &info)
{
    cout << "Enter your first name: ";
    cin >> info.first_name;

    cout << "Enter your last name: ";
    cin >> info.last_name;

    cout << "Enter your age: ";
    cin >> info.age;

    cout << "Enter your phone number (05--):";
    cin >> info.phone;
}

void print_info(strInfo info)
{
    cout << " \n ************************************************ \n";
    cout << "First name: " << info.first_name << endl;
    cout << "Last name: " << info.last_name << endl;
    cout << "Age: " << info.age << endl;
    cout << "Phone: " << info.phone << endl;
    cout << " \n ************************************************ \n";
}

int main()
{
    strInfo strInfo1;
    read_info(strInfo1);
    print_info(strInfo1);
}