// Count Letter in String
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>
#include <cctype>

using namespace std;

short CountLetter(string S1, char Character)
{
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] == Character)
            Counter++;
    }

    return Counter;
}

int main()
{
    string Sentence = MyInput::ReadString("Please Enter Your String?");

    char Character = MyInput::ReadChar("\nPlease Enter a Character?");

    cout << "\nLetter '" << Character << "' Count = " << CountLetter(Sentence, Character) << endl;
}