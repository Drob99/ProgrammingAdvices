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

void read_infos(strInfo info[100], int &Length)
{
    cout << "Enter the length of the array: ";
    cin >> Length;

    for (int i = 0; i < Length; i++)
    {
        cout << "Enter the info of person " << i + 1 << endl;
        read_info(info[i]);
    }
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

void print_infos(strInfo info_array[100], int Length)
{
    for (int i = 0; i < Length; i++)
    {
        print_info(info_array[i]);
    }
}

int main()
{
    strInfo info_array[100];
    int Length = 1;
    read_infos(info_array, Length);
    print_infos(info_array, Length);

    return 0;
}