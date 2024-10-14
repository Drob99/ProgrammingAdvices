# include <iostream>
using namespace std;

int main()
{
    int *ptrX;

    float *ptrY;

    ptrX = new int;
    ptrY = new float;

    *ptrX = 45;
    *ptrY = 58.35f;

    cout << *ptrX << endl;
    cout << *ptrY << endl;

    delete ptrX;
    delete ptrY;

    return 0; 

}