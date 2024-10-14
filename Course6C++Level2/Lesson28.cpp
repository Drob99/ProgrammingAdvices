// vectors
# include <vector>
# include <iostream>

using namespace std;

int main()
{
     // std::vector<T> vector_name

    vector <int> vNumbers = {10, 20, 30, 40, 50};

    cout << "Numbers Vector = ";

    // ranged loop
    for (int &Number: vNumbers) // & makes the access faster and no copying
    {
        cout << Number << " ";
    }

    cout << endl;

    return 0;
}