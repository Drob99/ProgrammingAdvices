// Reverse Word
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>

using namespace std;

string ReverseWords(string S1)
{
    vector<string> vString = String::SplitString(S1, " ");

    string Result = "";

    vector<string>::iterator iter = vString.end();

    while (iter != vString.begin())
    {
        --iter;

        Result += *iter + " ";
    }

    // for (short i = vString.size() - 1; i > 0; i--)
    // {
    //     Result += vString[i] + " ";
    // }

    // return Result + vString[0];

    return Result.substr(0, Result.length() - 1); // remove last space
}

int main()
{
    string S1 = MyInput::ReadString("Please Enter Your String?");

    cout << "\nString after reversing words:\n";
    cout << ReverseWords(S1);
}