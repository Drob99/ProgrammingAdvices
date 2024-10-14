#include <iostream>
#include <cmath>

using namespace std;


float ReadRadius(){
    float radius;

    cout << "Enter the Radius of a Circle: "; cin >> radius ;

    return radius;
}

float CircleArea(float R){
    const float PI = 3.141592653589793238;
    float area = pow(R, 2) * PI;
    return area;
}

void PrintResults(float Area){
    cout << "\nThe area is " << Area << ".";
}

int main()
{

    PrintResults(CircleArea(ReadRadius()));
    return 0;
}