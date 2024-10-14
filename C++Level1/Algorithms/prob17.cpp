//Find area of triangle

#include <iostream>

using namespace std;

void ReadNumbers(float& A, float& H){
    cout << "Enter base and height: ";
    cin >> A >> H;
}

float TriangleArea(float A, float H){
    float area = (A / 2) * H;
    return area;
}

void PrintResults(float Area){
    cout << "\nThe area is " << Area << ".";
}

int main()
{

    float base, height;
    ReadNumbers(base, height);
    PrintResults(TriangleArea(base, height));

    return 0;
}