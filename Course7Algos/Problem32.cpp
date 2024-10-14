// Is Vowel
# include "D:\Career\C++\AbuHadhoud\Libraries\MyInput.h"
# include "D:\Career\C++\AbuHadhoud\Libraries\MyFunctions.h"
# include <string>
# include <cctype>

using namespace std;


bool IsVowel(char Letter)
{
    Letter = tolower(Letter);
    return (Letter == 'a' || Letter == 'e' || Letter == 'i' || Letter == 'o' || Letter == 'u');
}

void PrintIsVowel(char Letter)
{
    if (IsVowel(Letter))
        cout << "\nYES Letter '" << Letter << "' is vowel.";

    else
        cout << "\nNO Letter '" << Letter  << "' is NOT a vowel.";
}





int main()
{    
    char Character = MyInput::ReadChar("Please Enter a Character?");

    PrintIsVowel(Character);
}