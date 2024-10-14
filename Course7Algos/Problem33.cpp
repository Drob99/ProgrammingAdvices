// Count Vowel
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>
#include <cctype>

using namespace std;

short CountVowels(string S1)
{
    int VowelCounter = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (String::IsVowel(S1[i]))
            VowelCounter++;
    }

    return VowelCounter;
}

int main()
{
    string S1 = MyInput::ReadString("Please Enter Your String?");

    cout << "\nNumber of vowels is: " << CountVowels(S1);
}