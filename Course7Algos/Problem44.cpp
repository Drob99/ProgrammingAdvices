// Remove Puncts
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>

using namespace std;

string RemovePunctuations(string S1)
{
    string S2 = "";
    for (short i = 0; i < S1.length(); i++)
    {
        if (!ispunct(S1[i]))
            S2 += S1[i];
    }

    return S2;
}

int main()
{
    string S1 = "Welcome to Jordan, Jordan is a nice country; it's amazing.";

    cout << "\nOriginal String\n"
         << S1;

    cout << "\n\nPunctuations Removed:\n";
    cout << RemovePunctuations(S1);
}