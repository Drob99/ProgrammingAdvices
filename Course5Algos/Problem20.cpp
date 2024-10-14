# include <iostream>
using namespace std;

int RandomNumber(int From, int To){
    // Function to generate random number
    // cout << rand() << "\n";
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

enum enRandomElement { SmallLetter = 1, CapitalLetter = 2, SpecialChar = 3, Digit = 4};

char GetRandomCharacter(enRandomElement CharType)
{
    // could be done using switch
    if (CharType == SmallLetter)
        return char(RandomNumber('a', 'z')); //97, 122
    else if (CharType == CapitalLetter)
        return char(RandomNumber('A', 'Z')); // 65, 90
    else if (CharType == SpecialChar)
        return char(RandomNumber(33, 47)); // '!', '/'
    else 
        return char(RandomNumber(48, 57)); // '0', '9'
}

int main()
{
    srand((unsigned)time(NULL));

    cout << GetRandomCharacter(enRandomElement::SmallLetter) << endl;
    cout << GetRandomCharacter(enRandomElement::CapitalLetter) << endl;
    cout << GetRandomCharacter(enRandomElement::SpecialChar) << endl;
    cout << GetRandomCharacter(enRandomElement::Digit) << endl;

    return 0;
}