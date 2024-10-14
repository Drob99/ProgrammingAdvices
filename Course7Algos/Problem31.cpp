// Count Letter in String Match case
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>
#include <cctype>

using namespace std;

short CountLetter(string S1, char Character, bool MatchCase = true)
{
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (MatchCase)
        {
            if (S1[i] == Character)
                Counter++;
        }

        else
        {
            if (tolower(S1[i]) == tolower(Character))
                Counter++;
        }
    }

    return Counter;
}

int main()
{
    string Sentence = MyInput::ReadString("Please Enter Your String?");

    char Character = MyInput::ReadChar("\nPlease Enter a Character?");

    cout << "\nLetter '" << Character << "' Count = " << CountLetter(Sentence, Character) << endl;
    cout << "Letter '" << Character << "' Or '" << String::InvertCharCase(Character) << "' Count = " << CountLetter(Sentence, Character, false) << endl;
}