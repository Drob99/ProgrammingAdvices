#include <iostream>
#include <cmath>

using namespace std;

void ReadNumbers(float& A, float& D){
    cout << "Enter the diagonal: ";
    cin >> D;
    cout << "Enter a side of rectangle: ";
    cin >> A;
}

float RectangleAreaBySideAndDiagonal(float diagonal, float side)
{
    float side2 = sqrt(pow(diagonal, 2) - pow(side, 2));

    float area = side * side2;

    return area;
}

void PrintResults(float area)
{
    cout << "The area is " << area << ".";
}

int main()
{
    float diagonal, side;
    ReadNumbers(side, diagonal);
    PrintResults(RectangleAreaBySideAndDiagonal(side, diagonal));
}