// Join String Overloading
# include "D:\Career\C++\AbuHadhoud\Libraries\MyInput.h"
# include "D:\Career\C++\AbuHadhoud\Libraries\MyFunctions.h"
# include <string>
# include <cctype>
# include <iomanip>
# include <vector>

using namespace std;

string JoinString(vector <string> &vWords, string delimiter)
{
    string Result = "";

    for (string &s : vWords)
    {
        Result += s + delimiter;
    }
    return Result.substr(0, Result.length() - delimiter.length());
}

string JoinString( string array[], short length, string delimiter)
{
    string Result = "";

    for (short i = 0; i < length-1; i++)
    {
        Result += array[i] + delimiter;
    }

    return Result + array[length - 1];
}

int main()
{
    vector <string> vString = {"Omar", "Bahaeldin", "Abdalla"};
    string array[]          = {"Omar", "Bahaeldin", "Abdalla"};

    cout << "\nVector after join:\n";
    cout << JoinString(vString, " ");

    cout << "\n\nArray after join:\n";
    cout << JoinString(array, 3, " ");
}