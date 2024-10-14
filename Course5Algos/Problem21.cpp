// Generate Keys
# include <iostream>
# include <string>

using namespace std;

int ReadPositiveNumber(string message)
{
    int num;
    do
    {
        cout << message << endl;
        cin >> num;
    } while (num < 0);
    
    return num;
}

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
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

string GenerateWord(enRandomElement CharType, short Length)
{
    string word = "";
    for (int i = 1; i <= Length; i++)
    {
        word += GetRandomCharacter(CharType);
    }
    return word;
}

string GenerateKey()
{
    string Key = "";
    for (int i = 0; i < 4; i++)
    {
        Key += GenerateWord(CapitalLetter, 4);
        if (i < 3)
            Key += '-';
    }

    return Key;
}

void GenerateKeys(int Number)
{
    cout << "\n";
    for (int i = 0; i < Number; i++)
    {
        cout << "Key [" << i+1 << "]: " << GenerateKey() << "\n";
    }
}

int main()
{
    srand((unsigned)time(NULL));

    GenerateKeys(ReadPositiveNumber("Enter how many keys to generate: "));
}