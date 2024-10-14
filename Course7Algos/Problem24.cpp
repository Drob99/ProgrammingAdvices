// Upper First Letter of Each Word in String

# include "D:\Career\C++\AbuHadhoud\Libraries\MyInput.h"
# include "D:\Career\C++\AbuHadhoud\Libraries\MyFunctions.h"
# include <string>


using namespace std;

string UpperString(string Sentence)
{
    bool isFirstLetter = true;

    for (short i = 0; i < Sentence.length(); i++)
    {
        if (Sentence.at(i) != ' ' && isFirstLetter)
            Sentence[i] = toupper(Sentence[i]);
        
        isFirstLetter = (Sentence[i] == ' ' ? true : false);
    }

    return Sentence;
}

int main()
{
    string Sentence = MyInput::ReadString("Please Enter Your String?");

    Sentence = UpperString(Sentence);

    cout << "\nString after conversion:\n";
    cout << Sentence;
}