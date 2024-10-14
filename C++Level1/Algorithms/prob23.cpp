// Circle area around arbitrary triangle

#include <iostream>
#include <cmath>

using namespace std;

void ReadTriangleSides(float &a, float &b, float &c)
{
    cout << "Enter 3 sides of a triangle inside a circle: ";
    cin >> a >> b >> c;
}

float CircleAreaByArbitaryTriangle(float a, float b, float c)
{
    const float PI = 3.141592653589793238;

    float p = (a + b + c) / 2;
    float area = PI * pow(((a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)))), 2);

    return area;
}

void PrintResult(float Area)
{
    cout << "\nCircle Area " << Area << ".";
}

int main()
{
    float a, b, c;
    ReadTriangleSides(a, b, c);
    PrintResult(CircleAreaByArbitaryTriangle(a, b, c));

    return 0;
}