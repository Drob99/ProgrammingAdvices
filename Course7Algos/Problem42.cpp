// Replace Words
# include "D:\Career\C++\AbuHadhoud\Libraries\MyInput.h"
# include "D:\Career\C++\AbuHadhoud\Libraries\MyFunctions.h"
# include <string>
# include <cctype>
# include <iomanip>
# include <vector>

using namespace std;



string ReplaceWordsInStringUsingBuiltInFunction(string S1, string OrigWord, string Replacement)
{
    short pos = S1.find(OrigWord);

    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, OrigWord.length(), Replacement);
        pos = S1.find(OrigWord);
    }

    return S1;
}

int main()
{
    string S1 = "Welcome to Jordan, Jordan is a nice country";
    string OriginalWord = "Jordan";
    string Replacement = "USA";

    cout << "\nOriginal String\n" << S1;

    cout << "\n\nString After Replace:\n";
    cout << ReplaceWordsInStringUsingBuiltInFunction(S1, "Jordan", "USA");

}