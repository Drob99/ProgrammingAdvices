// Count Each Word In String
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>

using namespace std;

vector<string> SplitString(string S1, string delimeter)
{
    vector<string> vSplittedString;
    string token;
    short pos = 0;

    while ((pos = S1.find(delimeter)) != std::string::npos)
    {
        token = S1.substr(0, pos);

        if (token != "")
        {
            vSplittedString.push_back(token);
        }

        S1.erase(0, pos + delimeter.length());
    }

    if (S1 != "")
        vSplittedString.push_back(S1);

    return vSplittedString;
}

int main()
{
    string S1 = MyInput::ReadString("Please Enter Your String?");

    vector<string> vWords = SplitString(S1, " ");
    cout << "\nTokens = " << vWords.size() << endl;
    MyVectors::PrintVector(vWords);
}