// CCTYPE functions

# include <iostream>
# include <string>
# include <cctype>

using namespace std;

int main()
{
    char x;
    char w;

    x = toupper('a');
    w = tolower('A');

    cout << "converting a to A: " << x << endl;
    cout << "converting A to a: " << w << endl;

    // Upper Case (A to Z)
    // returns zero if not, and not zero if yes
    cout << "isupper('A') " << isupper('A') << endl;

    cout << "islower('a') " << islower('a') << endl;

    cout << "isdigit('9') " << isdigit('9') << endl;

    cout << "ispunct(';') " << ispunct(';') << endl; 

    return 0;
}