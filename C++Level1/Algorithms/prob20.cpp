//Circle area inscribed in square

#include <iostream>
#include <cmath>

using namespace std;

float ReadSquareSide(){
    float side;

    cout << "Enter the Side of the Square: ";
    cin >> side ;

    return side;
}

float CircleAreaInscribedInSquare(float A){
    const float PI = 3.141592653589793238;

    float area = (PI * pow(A, 2) ) / 4;
    return area;
}

void PrintResults(float Area){
    cout << "\nThe area is " << Area << ".";
}


int main()
{
    PrintResults(CircleAreaInscribedInSquare(ReadSquareSide()));
    return 0;
}