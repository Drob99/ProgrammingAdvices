// circle area inscribed in isosceles triangle

#include <iostream>
#include <cmath>

using namespace std;

void ReadTriangleSides(float &a, float &b){

    cout << "Enter the Sides of the Triangle: ";
    cin >> a >> b;
}

float CircleAreaByITriangle(float A, float B){
    const float PI = 3.141592653589793238;

    float area = PI * (pow(B, 2) / 4) * ((2 * A - B) / (2 * A + B));
    return area;
}

void PrintResult(float Area){
    cout << "\nThe area is " << Area << ".";
}


int main()
{
    float a, b;
    ReadTriangleSides(a, b);
    PrintResult(CircleAreaByITriangle(a, b));
    return 0;
}

void printCircleArea(float triangleSide1, float triangleSide2)
{
    float area = M_PI * ((triangleSide2 * triangleSide2) / 4) * ((2*triangleSide1 - triangleSide2) / (2*triangleSide1 + triangleSide2));
    area = floor(area);

    cout << "The area is " << area << ".";
}