// Print Each Word In String
# include "D:\Career\C++\AbuHadhoud\Libraries\MyInput.h"
# include "D:\Career\C++\AbuHadhoud\Libraries\MyFunctions.h"
# include <string>
# include <cctype>
# include <iomanip>

using namespace std;

void PrintEachWord(string Sentence)
{
    cout << "\nYour string words are:\n\n";
    bool isSpace = false;

    for (short i = 0; i < Sentence.length(); i++)
    {
        isSpace = (Sentence[i] == ' ' ? true : false);
        if (Sentence.at(i) != ' ' && !isSpace)
            cout << Sentence[i];
    
        if (isSpace)
            cout << "\n";
    }
}

void PrintEachWordInString(string S1)
{
    string delimiter = " ";

    cout << "\nYour string words are:\n\n";
    short pos = 0;
    string sWord = "";

    // use find() to get pos of delims
    while ((pos = S1.find(delimiter)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store word
        if (sWord != "")
        {
            cout << sWord << endl;
        }

        S1.erase(0, pos + delimiter.length());
    }

    if (S1 != "")
        cout << S1 << endl;

}


int main()
{    
    string S1 = MyInput::ReadString("Please Enter Your String?");

    PrintEachWordInString(S1);
}