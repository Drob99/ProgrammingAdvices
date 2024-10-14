#include <iostream>

using namespace std;

int main()
{
    string st1 = "43.22";
    int N1 = 20;
    double N2 = 33.5;
    float N3 = 55.23;

    cout << "String to double: " << stod(st1) << endl;
    cout << "String to float: " << stof(st1) << endl;
    cout << "String to integer: " << stoi(st1) << endl;

    cout << "Integer to string: " << to_string(N1) << endl;
    cout << "Double to string: " << to_string(N2) << endl;
    cout << "Float to string: " << to_string(N3) << endl;
}