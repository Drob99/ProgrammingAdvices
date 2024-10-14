# include "D:\Career\C++\AbuHadhoud\Libraries\MyInput.h"
# include "D:\Career\C++\AbuHadhoud\Libraries\MyFunctions.h"
# include <string>
# include <cctype>
# include <iomanip>
# include <vector>

using namespace std;

string ReplaceWordsInString(string S1, string OriginalWord, string Replacement, bool MatchCase = true)
{
    vector <string> vString = String::SplitString(S1, " ");

    for (string &s : vString)
    {
        if (MatchCase)
        {
            if (s == OriginalWord)
                s = Replacement;
        }
        
        else
        {
            if (String::LowerAllString(s) == String::LowerAllString(OriginalWord))
                s = Replacement;
        }
    }

    return String::JoinString(vString, " ");
}

int main()
{
    string S1 = "Welcome to Jordan , Jordan is a nice country";
    string OriginalWord = "jordan";
    string Replacement = "USA";

    cout << "\nOriginal String\n" << S1;

    cout << "\n\nReplace with match case:\n";
    cout << ReplaceWordsInString(S1, OriginalWord, Replacement);

    cout << "\n\nReplace without match case:\n";
    cout << ReplaceWordsInString(S1, OriginalWord, Replacement, false);

}