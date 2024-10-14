// calculate rectangle area given length and width

#include <iostream>

using namespace std;

void ReadNumbers(float& A, float& B)
{
    cout << "Enter length: ";
    cin >> A;

    cout << "Enter width: ";
    cin >> B;
}

float CalculateRectangleArea(float length, float width)
{
    return length * width;
}

void printRectangleArea(float area)
{
    cout << "The area is " << area << ".";
}

int main()
{
    float length, width;
    ReadNumbers(length, width);
    printRectangleArea(CalculateRectangleArea(length, width));
    return 0;
}