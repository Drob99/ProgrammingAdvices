// Lower First Letter of Each Word in String

#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

string LowerString(string Sentence)
{
    bool isFirstLetter = true;

    for (short i = 0; i < Sentence.length(); i++)
    {
        if (Sentence.at(i) != ' ' && isFirstLetter)
            Sentence[i] = tolower(Sentence[i]);

        isFirstLetter = (Sentence[i] == ' ' ? true : false);
    }

    return Sentence;
}

int main()
{
    string Sentence = MyInput::ReadString("Please Enter Your String?");

    Sentence = LowerString(Sentence);

    cout << "\nString after conversion:\n";
    cout << Sentence;
}