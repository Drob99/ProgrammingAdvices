// Find circle area given diameter

#include <iostream>
#include <cmath>

using namespace std;

float ReadDiameter(){
    float diameter;

    cout << "Enter the Diameter of a Circle: "; cin >> diameter ;

    return diameter;
}

float CircleAreaByDiameter(float D){
    const float PI = 3.141592653589793238;
    float area = (pow(D, 2) * PI ) / 4;
    return area;
}

void PrintResults(float Area){
    cout << "\nThe area is " << Area << ".";
}


int main()
{
        PrintResults(CircleAreaByDiameter(ReadDiameter()));
        return 0;
}