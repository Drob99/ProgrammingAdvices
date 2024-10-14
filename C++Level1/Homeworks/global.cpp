#include <iostream>

using namespace std;

int x = 200;

void testing_variables()
{
    int x = 100;
    cout << "localX = " << x << endl;
    cout << "globalX = " << ::x << endl;

    // *Testing if changing global here works !!!!
    ::x++;
    cout << "Changed global x: " << ::x << endl;
}

int main()
{
    int x = 400;
    cout << "x in main class: " << x << endl;
    cout << "x in global scope: " << ::x << endl;
    testing_variables();
    return 0;
}

