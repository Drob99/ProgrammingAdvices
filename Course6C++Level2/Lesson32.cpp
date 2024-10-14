//Vector Functions
# include <iostream>
# include <vector>

using namespace std;

int main()
{
    vector <int> vNumbers = {10, 20, 30, 40, 50};


    if (!vNumbers.empty())
    {
    cout << "First Element : " << vNumbers.front()    << endl;
    cout << "Last  Element : " << vNumbers.back()     << endl;
    }
    
    cout << "Size          : " << vNumbers.size()     << endl;

    cout << "Capacity      : " << vNumbers.capacity() << endl;

    cout << "Empty         : " << vNumbers.empty()    << endl;
 
}