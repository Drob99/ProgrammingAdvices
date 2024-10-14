// Join String
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>

using namespace std;

string JoinString(vector<string> &vWords, string delimiter)
{
    string Result = "";

    for (string &s : vWords)
    {
        Result += s + delimiter;
    }
    return Result.substr(0, Result.length() - delimiter.length());
}

int main()
{
    vector<string> vString = {"Omar", "Bahaeldin", "Abdalla"};

    cout << "\nVector after join:\n";
    cout << JoinString(vString, " ");
}