// Count All Small/Capital Letters in String
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>
#include <cctype>

using namespace std;

enum enWhatToCount
{
    SmallLetters = 0,
    CapitalLetters = 1,
    All = 2
};

short CountLetters(string S1, enWhatToCount WhatToCount = All)
{
    if (WhatToCount == All)
        return S1.length();

    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (WhatToCount == CapitalLetters && isupper(S1[i]))
            Counter++;

        else if (WhatToCount == SmallLetters && islower(S1[i]))
            Counter++;
    }

    return Counter;
}

short CountCapitalLetters(string Sentence)
{
    short CapitalCount = 0;
    for (short i = 0; i < Sentence.length(); i++)
    {
        if (isupper(Sentence[i]))
            CapitalCount++;
    }
    return CapitalCount;
}

short CountSmallLetters(string Sentence)
{
    short SmallCount = 0;
    for (short i = 0; i < Sentence.length(); i++)
    {
        if (islower(Sentence[i]))
            SmallCount++;
    }
    return SmallCount;
}

int main()
{
    string Sentence = MyInput::ReadString("Please Enter Your String?");

    cout << "\nString Length = " << Sentence.length() << endl;
    cout << "Capital Letters Count  = " << CountCapitalLetters(Sentence) << endl;
    cout << "Small Letters Count = " << CountSmallLetters(Sentence) << endl;
}