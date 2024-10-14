// Invert All Letters Case

# include "D:\Career\C++\AbuHadhoud\Libraries\MyInput.h"
# include "D:\Career\C++\AbuHadhoud\Libraries\MyFunctions.h"
# include <string>
# include <cctype>

using namespace std;

char InvertCharCase(char Character)
{
    return isupper(Character) ? tolower(Character) : toupper(Character);
}

string InvertAllLettersCase(string Sentence)
{
    for (short i ; i < Sentence.length(); i++)
    {
        Sentence[i] = InvertCharCase(Sentence[i]);
    }
    return Sentence;
}

int main()
{
    string Sentence = MyInput::ReadString("Please Enter Your String?");
    
    cout << "\nString after Inverting All Letters Case:\n";
    cout << InvertAllLettersCase(Sentence);
}