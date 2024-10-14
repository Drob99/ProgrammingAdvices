// Count Each Word In String
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

short CountEachWordInString(string S1)
{
    string delimeter = " ";
    short WordCounter = 0;
    string sWord;
    short pos = 0;

    while ((pos = S1.find(delimeter)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);

        if (sWord != "")
            WordCounter++;

        S1.erase(0, pos + delimeter.length());
    }

    if (S1 != "")
        WordCounter++;

    return WordCounter;
}

int main()
{
    string S1 = MyInput::ReadString("Please Enter Your String?");

    cout << "\nThe number of words in your string is: " << CountEachWordInString(S1);
}