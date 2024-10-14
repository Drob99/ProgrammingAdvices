// Print all vowels in string
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

void PrintAllVowelsInString(string S1)
{
    cout << "\nVowels in string are:";
    for (short i = 0; i < S1.length(); i++)
    {
        if (String::IsVowel(S1.at(i)))
            cout << setw(4) << S1[i];
    }
}

int main()
{
    string S1 = MyInput::ReadString("Please Enter Your String?");

    PrintAllVowelsInString(S1);
}