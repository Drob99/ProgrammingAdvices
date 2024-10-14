// Try Catch

# include <iostream>
# include <vector>

using namespace std;

int main()
{
    vector <int> num {1, 2, 3, 4, 5};

    // cout << num.at(5); // error due to range

    try
    {
        cout << num.at(5);
    }
    catch(...)
    {
        cout << "Out Of Bounds\n";
    }

    return 0;
}