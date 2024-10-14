#include <iostream>
#include <cmath>

using namespace std;

float ReadCircumference(){
    float side;

    cout << "Enter the Circumference of the Circle: ";
    cin >> side ;

    return side;
}

float CircleAreaByCircumference(float A){
    const float PI = 3.141592653589793238;

    float area = pow(A, 2) / (4 * PI);
    return area;
}

void PrintResult(float Area){
    cout << "\nCircle Area " << Area << ".";
}


int main()
{
    PrintResult(CircleAreaByCircumference(ReadCircumference()));
    return 0;
}