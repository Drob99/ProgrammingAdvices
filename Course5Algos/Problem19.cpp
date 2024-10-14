// Random Numbers from 1 to 10
# include <iostream>
# include <cstdlib>
using namespace std;

int RandomNumber(int From, int To){
    // Function to generate random number
    // cout << rand() << "\n";
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    cout << rand() << endl; // 0 to max size of integer
    cout << rand() << endl;

    for (int i = 0; i < 3; i++)
        cout << RandomNumber(1, 10) << endl;

    return 0;
}