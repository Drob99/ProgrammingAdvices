// Print First Letter of Each Word in String
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

void PrintFirstLetterOfEachWordInString(string Sentence)
{
    bool isFirstLetter = true;

    cout << "\nFirst letters of this string:\n";

    for (short i = 0; i < Sentence.length(); i++)
    {
        if (Sentence.at(i) != ' ' && isFirstLetter)
            cout << Sentence.at(i) << "\n";

        isFirstLetter = (Sentence[i] == ' ' ? true : false);
    }
}

int main()
{
    string Sentence = MyInput::ReadString("Please Enter Your String?");

    PrintFirstLetterOfEachWordInString(Sentence);
}