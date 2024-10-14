#pragma once
#include <iostream>
#include "clsDate.h"
#include <string>
#include <cmath>

using namespace std;

class clsUtil
{
public:
    enum enOperationType
    {
        Add = '+',
        Subtract = '-',
        Multiply = '*',
        Divide = '/'
    };
    enum enPrimeNotPrime
    {
        Prime = 1,
        NotPrime = 2
    };
    enum enCharType
    {
        SmallLetter = 1,
        CapitalLetter = 2,
        SpecialChar = 3,
        Digit = 4,
        MixChars = 5
    };

    static int MaxOf2Numbers(int Num1, int Num2)
    {
        return Num1 ? Num1 > Num2 : Num2;
    }

    static int MaxOf3Numbers(int Num1, int Num2, int Num3)
    {
        if (Num1 > Num2)
            if (Num1 > Num3)
                return Num1;
            else
                return Num3;
        else if (Num2 > Num3)
            return Num2;
        else
            return Num3;
    }

    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    static void Swap(int &num1, int &num2)
    {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    static void Swap(double &num1, double &num2)
    {
        double temp = num1;
        num1 = num2;
        num2 = temp;
    }

    static void Swap(bool &bool1, bool &bool2)
    {
        bool temp = bool1;
        bool1 = bool2;
        bool2 = temp;
    }

    static void Swap(char &char1, char &char2)
    {
        char temp = char1;
        char1 = char2;
        char2 = temp;
    }


    static void Swap(string &str1, string &str2)
    {
        string temp = str1;
        str1 = str2;
        str2 = temp;
    }

    static void Swap(clsDate &date1, clsDate &date2)
    {
        clsDate temp = date1;
        date1 = date2;
        date2 = temp;
    }

    static bool ValidateNumberInRange(int Number, int From, int To)
    {
        return Number >= From && Number <= To;
    }

    static char GetGradeLetter(int grade)
    {
        if (grade >= 90)
        {
            return 'A';
        }
        else if (grade >= 80)
        {
            return 'B';
        }
        else if (grade >= 70)
        {
            return 'C';
        }
        else if (grade >= 60)
        {
            return 'D';
        }
        else
        {
            return 'F';
        }
    }

    static float Calculate(float num1, float num2, enOperationType opType)
    {
        switch (opType)
        {
        case Add:
            return num1 + num2;
        case Subtract:
            return num1 - num2;
        case Multiply:
            return num1 * num2;
        case Divide:
            return num1 / num2;
        default:
            cout << "Invalid operator";
            return -1;
        }
    }

    static enPrimeNotPrime CheckPrime(int num)
    {
        int M = clsUtil::myRound(num / 2);
        if (num == 0 || num == 1)
            return NotPrime;

        for (int i = 2; i <= M; i++)
        {
            if (num % i == 0)
                return NotPrime;
        }

        return Prime;
    }

    static string ColumSeparator(int i)
    {
        if (i >= 10)
            return "     | ";
        else
        {
            return "      | ";
        }
    }

    static bool IsDivisor(int dividend, int divisor)
    {
        return (dividend % divisor) == 0;
    }

    static int SumOfDivisorsList(int Number)
    {
        int sum = 0;
        for (int i = 1; i <= Number / 2; i++)
        {
            if (IsDivisor(Number, i))
                sum += i;
        }
        return sum;
    }

    static bool IsPerfectNumber(int Number)
    {
        return SumOfDivisorsList(Number) == Number;
    }

    static void PrintPerfectNumbersFrom1ToN(int Number)
    {
        for (int i = 1; i <= Number; i++)
        {
            if (IsPerfectNumber(i))
                cout << i << endl;
        }
    }

    static int SumOfDigits(int Number)
    {
        int sum = 0;
        while (Number > 0)
        {
            sum += Number % 10;
            Number /= 10;
        }
        return sum;
    }

    static int ReverseNumber(int Number)
    {
        int result = 0;
        while (Number > 0)
        {
            result = result * 10 + Number % 10; // Wow !!
            Number /= 10;
        }
        return result;
    }

    static void PrintDigitsInReverse(int Number)
    {
        cout << "\nReverse is:\n";
        cout << ReverseNumber(Number);
    }

    static int CalculateDigitFrequency(int Number, int Digit)
    {
        int freq = 0;
        while (Number > 0)
        {
            if (Number % 10 == Digit)
                freq++;
            Number /= 10;
        }

        return freq;
    }

    static void PrintAllDigitFrequency(int Number)
    {
        for (int i = 0; i <= 9; i++)
        {
            short freq = CalculateDigitFrequency(Number, i);
            if (freq > 0)
                cout << "\nDigit " << i << " Frequency is " << freq << " Time(s).";
        }
    }

    static bool CheckPalindrome(int Number)
    {
        return Number == ReverseNumber(Number);
    }

    static string EncryptText(string word, short EncryptionKey = 2)
    {
        for (int i = 0; i < word.length(); i++)
        {
            word[i] = char((int)word[i] + EncryptionKey);
        }
        return word;
    }

    static string DecryptText(string word, short EncryptionKey = 2)
    {
        for (int i = 0; i < word.length(); i++)
        {
            word[i] = char((int)word[i] - EncryptionKey);
        }
        return word;
    }

    static int RandomNumber(int From, int To)
    {
        // Function to generate random number
        // cout << rand() << "\n";
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static char GetRandomCharacter(enCharType CharType)
    {
        if (CharType == MixChars)
        {
            CharType = (enCharType)RandomNumber (1, 3);
        }
        // could be done using switch
        if (CharType == SmallLetter)
            return char(RandomNumber('a', 'z')); // 97, 122
        else if (CharType == CapitalLetter)
            return char(RandomNumber('A', 'Z')); // 65, 90
        else if (CharType == SpecialChar)
            return char(RandomNumber(33, 47)); // '!', '/'
        else if (CharType == Digit)
            return char(RandomNumber(48, 57)); // '0', '9'
        else
            return char (RandomNumber ('A', 'Z'));
    }

    static string GenerateWord(enCharType CharType, short Length)
    {
        string word = "";
        for (int i = 1; i <= Length; i++)
        {
            word += GetRandomCharacter(CharType);
        }
        return word;
    }

    static string GenerateKey(enCharType CharType = CapitalLetter)
    {
        string Key = "";
        for (int i = 0; i < 4; i++)
        {
            Key += GenerateWord(CharType, 4);
            if (i < 3)
                Key += '-';
        }

        return Key;
    }

    static void GenerateKeys(short Number, enCharType CharType = CapitalLetter)
    {
        cout << "\n";
        for (short i = 0; i < Number; i++)
        {
            cout << "Key [" << i + 1 << "]: " << GenerateKey(CharType) << "\n";
        }
    }

    static float myAbs(float Number)
    {
        if (Number < 0)
            Number *= -1;

        return Number;
    }

    static float GetFractionPart(float Number)
    {
        int WholePart = (int)Number;
        return myAbs(Number - WholePart);
    }

    static int myRound(float Number)
    {
        float fraction = GetFractionPart(Number);
        int WholePart = (int)Number;

        if (fraction >= 0.5)
        {
            if (Number > 0)
                return ++WholePart;
            else
                return --WholePart;
        }
        else
        {
            return WholePart;
        }
    }

    static int myFloor(float Number)
    {
        if (GetFractionPart(Number) > 0)
        {
            if (Number < 0)
                return (int)Number - 1;
            return (int)Number;
        }
        else
            return Number;
    }

    static int myCeil(float Number)
    {
        if (GetFractionPart(Number) > 0)
        {
            if (Number < 0)
                return (int)Number;
            return (int)Number + 1;
        }
        else
            return Number;
    }

    static int mySqrt(float Number)
    {
        return pow(Number, 0.5);
    }

    static void FillArrayWithRandomNumbers(int array[100], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
        {
            array[i] = clsUtil::RandomNumber(From, To);
        }
    }

    static void FillArrayWithRandomWords(string array[100], int arrLength, enCharType CharType, short Wordlength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            array[i] = clsUtil::GenerateWord(CharType, Wordlength);
        }
    }

    static void FillArrayWithRandomKeys(string array[], int arrLength, enCharType CharType = CapitalLetter)
    {
        for (int i = 0; i < arrLength; i++)
        {
            array[i] = clsUtil::GenerateKey(CharType);
        }
    }

    static void ShuffleArray(int array[], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            clsUtil::Swap(array[clsUtil::RandomNumber(0, arrLength - 1)], array[clsUtil::RandomNumber(0, arrLength - 1)]);
    }

    static void ShuffleArray(string array[], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            clsUtil::Swap(array[clsUtil::RandomNumber(0, arrLength - 1)], array[clsUtil::RandomNumber(0, arrLength - 1)]);
    }

    static string Tabs (short NumberOfTabs)
    {
        string t = "";
        for (short i = 0; i < NumberOfTabs; i++)
        {
            t += "\t";
            // cout << t;
        }
        return t;
    }

   static string NumberToText(int Number)
   {

       if (Number == 0)
       {
           return "";
       }

       if (Number >= 1 && Number <= 19)
       {
           string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
       "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
         "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

           return  arr[Number] + " ";

       }

       if (Number >= 20 && Number <= 99)
       {
           string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
           return  arr[Number / 10] + " " + NumberToText(Number % 10);
       }

       if (Number >= 100 && Number <= 199)
       {
           return  "One Hundred " + NumberToText(Number % 100);
       }

       if (Number >= 200 && Number <= 999)
       {
           return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
       }

       if (Number >= 1000 && Number <= 1999)
       {
           return  "One Thousand " + NumberToText(Number % 1000);
       }

       if (Number >= 2000 && Number <= 999999)
       {
           return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
       }

       if (Number >= 1000000 && Number <= 1999999)
       {
           return  "One Million " + NumberToText(Number % 1000000);
       }

       if (Number >= 2000000 && Number <= 999999999)
       {
           return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
       }

       if (Number >= 1000000000 && Number <= 1999999999)
       {
           return  "One Billion " + NumberToText(Number % 1000000000);
       }
       else
       {
           return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
       }

   } 


};