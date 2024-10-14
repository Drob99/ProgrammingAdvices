#include <iostream>

using namespace std;

void read_grades(float grades[3])
{
    cout << "Please Enter Grade1 ?" << endl;
    cin >> grades[0];

    cout << "Please Enter Grade2 ?" << endl;
    cin >> grades[1];

    cout << "Please Enter Grade3 ?" << endl;
    cin >> grades[2];
}

float calc_average(float grades[3])
{
    float sum = grades[0] + grades[1] + grades[2];
    return sum / 3;
}

int main()
{
    float grades[3];
    read_grades(grades);
    cout << "\n****************************\n";
    cout << "The average of the grades is " << calc_average(grades);
    return 0;
}