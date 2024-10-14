// Invert Character Case

#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>
#include <cctype>

using namespace std;

char InvertCharCase(char Character)
{
    return isupper(Character) ? tolower(Character) : toupper(Character);
}

int main()
{
    char Character = MyInput::ReadChar("Please Enter Your Character?");

    cout << "\nChar after inverting case:\n";
    cout << InvertCharCase(Character);
}