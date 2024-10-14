#include <iostream>

using namespace std;

int main()
{
    float grades[5];

    cout << "Please Enter Grade1 ?" << endl;
    cin >> grades[0];

    cout << "Please Enter Grade2 ?" << endl;
    cin >> grades[1];

    cout << "Please Enter Grade3 ?" << endl;
    cin >> grades[2];

    cout << "\n****************************\n";
    float sum = grades[0] + grades[1] + grades[2];
    cout << "The average of the grades is " << sum / 3;
    return 0;
}