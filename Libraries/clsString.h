# pragma once

#include <iostream>
#include <vector>

using namespace std;

class clsString
{
private:
    string _Value;

public:
    clsString()
    {
        _Value = "";
    }

    clsString(string Value)
    {
        _Value = Value;
    }

    void SetValue (string Value)
    {
        _Value = Value;
    }

    string GetValue()
    {
        return _Value;
    }

    // All Functions
    
    static short Length(string S1)
    {
        return S1.length();
    }

    short Length()
    {
        return _Value.length();
    }

    static short CountEachWordInString (string S1)
    {
    string delimeter = " ";
    short WordCounter = 0;
    string sWord;
    short pos = 0;

    while ((pos = S1.find(delimeter)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);

        if (sWord != "")
            WordCounter++;
        
        S1.erase(0, pos + delimeter.length());
    }

    if (S1 != "")
        WordCounter++;
    
    return WordCounter;
    }

    short CountEachWordInString()
    {
        return CountEachWordInString(_Value);
    }
   
    static string UpperFirstLetterOfEachWord(string Sentence)
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

    void UpperFirstLetterOfEachWord()
    {
        _Value = UpperFirstLetterOfEachWord(_Value);
    }

    static string LowerFirstLetterOfEachWord(string Sentence)
    {
    bool isFirstLetter = true;

    for (short i = 0; i < Sentence.length(); i++)
    {
        if (Sentence.at(i) != ' ' && isFirstLetter)
            Sentence[i] = tolower(Sentence[i]);
        
        isFirstLetter = (Sentence[i] == ' ' ? true : false);
    }

    return Sentence;
}

    void LowerFirstLetterOfEachWord()
    {
        _Value = LowerFirstLetterOfEachWord(_Value);
    }

    static string LowerAllString(string Sentence)
    {

    for (short i = 0; i < Sentence.length(); i++)
    {
        Sentence[i] = tolower(Sentence[i]);
    }

    return Sentence;
}

    void LowerAllString()
    {
        _Value = LowerAllString(_Value);
    }
    
    static string UpperAllString(string Sentence)
{

    for (short i = 0; i < Sentence.length(); i++)
    {
        Sentence[i] = toupper(Sentence[i]);
    }

    return Sentence;
}

    void UpperAllString()
    {
        _Value = UpperAllString(_Value);
    }

    static char InvertCharCase(char Character)
{
    return isupper(Character) ? tolower(Character) : toupper(Character);
}

    static string InvertAllLettersCase(string Sentence)
{
    for (short i = 0; i < Sentence.length(); i++)
    {
        Sentence[i] = InvertCharCase(Sentence[i]);
    }
    return Sentence;
}

    void InvertAllLettersCase ()
    {
        _Value = InvertAllLettersCase(_Value);
    }

    enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 2};

    static short CountLetters(string S1, enWhatToCount WhatToCount = All)
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

    static short CountCapitalLetters(string Sentence)
    {
        short CapitalCount = 0;
        for (short i  = 0; i < Sentence.length(); i++)
        {
            if (isupper(Sentence[i]))
                CapitalCount++;
        }
        return CapitalCount;
    }

    short CountCapitalLetters()
    {
        return CountCapitalLetters(_Value);
    }

    static short CountSmallLetters(string Sentence)
    {
        short SmallCount = 0;
        for (short i  = 0; i < Sentence.length(); i++)
        {
            if (islower(Sentence[i]))
                SmallCount++;
        }
        return SmallCount;
    }

    short CountSmallLetters()
    {
        return CountSmallLetters(_Value);
    }

    static short CountSpecificLetter(string S1, char Character, bool MatchCase = true)
    {
        short Counter = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (MatchCase)
            {
                if (S1[i] == Character)
                    Counter++;
            }

            else
            {
                if (tolower(S1[i]) == tolower(Character))
                    Counter++;
            }
        }

        return Counter;
    }

    short CountSpecificLetter (char Letter, bool MatchCase = true)
    {
        return CountSpecificLetter(_Value, Letter, MatchCase);
    }

    static bool IsVowel(char Letter)
    {
        Letter = tolower(Letter);
        return (Letter == 'a' || Letter == 'e' || Letter == 'i' || Letter == 'o' || Letter == 'u');
    }

    static short CountVowels(string S1)
{
    short VowelCounter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (IsVowel(S1[i]))
            VowelCounter++;
    }

    return VowelCounter;
}

    short CountVowels()
    {
        return CountVowels(_Value);
    }

    static vector <string> Split(string S1, string delimeter)
{
    vector <string> vSplittedString;
    string token;
    short pos = 0;

    while((pos = S1.find(delimeter)) != std::string::npos)
    {
        token = S1.substr(0, pos);

        //if (token != "")
        //{
            vSplittedString.push_back(token);
        //}

        S1.erase(0, pos + delimeter.length());
    }

    if (S1 != "")
        vSplittedString.push_back(S1);

    return vSplittedString;
}

    vector <string> Split (string delimeter)
    {
        return Split(_Value, delimeter);
    }


    static string TrimLeft(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ')
            return S1.substr(i, S1.length()-i);
    }
    return "";
}

    void TrimLeft()
    {
        _Value = TrimLeft(_Value);
    }

    static string TrimRight(string S1)
{
    for (short i = S1.length() - 1; i >= 0; i--)
    {
        if (S1[i] != ' ')
            return S1.substr(0, i + 1);
    }
    return "";
}

    void TrimRight()
    {
        _Value = TrimRight(_Value);
    }

    static string Trim(string S1)
{
    return TrimLeft(TrimRight(S1));
}

    void Trim()
    {
        _Value = Trim(_Value);
    }

    static string JoinString(vector <string> &vWords, string delimiter)
{
    string Result = "";

    for (string &s : vWords)
    {
        Result += s + delimiter;
    }
    return Result.substr(0, Result.length() - delimiter.length());
}

    static string JoinString( string array[], short length, string delimiter)
{
    string Result = "";

    for (short i = 0; i < length-1; i++)
    {
        Result += array[i] + delimiter;
    }

    return Result + array[length - 1];
}

    static string ReverseWordsInString(string S1)
{
    vector <string> vString = Split(S1, " ");

    string Result = "";

    vector <string>::iterator iter = vString.end();

    while(iter != vString.begin())
    {
        -- iter;

        Result += *iter + " ";
    }

    // for (short i = vString.size() - 1; i > 0; i--)
    // {
    //     Result += vString[i] + " "; 
    // }

    // return Result + vString[0];

    return Result.substr(0, Result.length() - 1); // remove last space
}

    void ReverseWordsInString()
    {
        _Value = ReverseWordsInString(_Value);
    }

    static string ReplaceWord(string S1, string OriginalWord, string Replacement, bool MatchCase = true)
{
    vector <string> vString = Split(S1, " ");

    for (string &s : vString)
    {
        s = RemovePunctuations(s);
        if (MatchCase)
        {
            if (s == OriginalWord)
                s = Replacement;
        }
        
        else
        {
            if (LowerAllString(s) == LowerAllString(OriginalWord))
                s = Replacement;
        }
    }

    return JoinString(vString, " ");
}

    string ReplaceWord(string OriginalWord, string Replacement, bool MatchCase = true)
    {
        return ReplaceWord(_Value, OriginalWord, Replacement, MatchCase);
    }

    static string ReplaceWordsInStringUsingBuiltInFunction(string S1, string OrigWord, string Replacement)
{
    short pos = S1.find(OrigWord);

    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, OrigWord.length(), Replacement);
        pos = S1.find(OrigWord);
    }

    return S1;
}

    string ReplaceWordsInStringUsingBuiltInFunction(string OrigWord, string Replacement)
    {
        return ReplaceWordsInStringUsingBuiltInFunction(_Value, OrigWord, Replacement);
    }

    static string RemovePunctuations(string S1)
    {
        string S2 = "";

        for (short i = 0; i < S1.length(); i++)
        {
            if (!ispunct(S1[i]))
            {
                S2 += S1[i];
            }
        }

        return S2;    
    }

    void RemovePunctuations()
    {
        _Value = RemovePunctuations(_Value);
    }


};