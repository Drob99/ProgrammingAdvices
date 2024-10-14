#pragma once

#include <iostream>
#include <cmath>
#include "MyInput.h"
#include <iomanip>
#include <string>
#include <cctype>
#include <vector>
using namespace std;
using namespace MyInput;

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
enum enDayOfWeek
{
    Sun = 1,
    Mon = 2,
    Tues = 3,
    Wed = 4,
    Thu = 5,
    Fri = 6,
    Sat = 7
};
enum enMonthOfYear
{
    Jan = 1,
    Feb = 2,
    Mar = 3,
    Apr = 4,
    May = 5,
    Jun = 6,
    Jul = 7,
    Aug = 8,
    Sep = 9,
    Oct = 10,
    Nov = 11,
    Dec = 12
};
enum enRandomElement
{
    SmallLetter = 1,
    CapitalLetter = 2,
    SpecialChar = 3,
    Digit = 4
};

namespace MyFunctions
{

    int MaxOf2Numbers(int Num1, int Num2)
    {
        return Num1 ? Num1 > Num2 : Num2;
    }

    int MaxOf3Numbers(int Num1, int Num2, int Num3)
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

    void SwapNumbers(int &num1, int &num2)
    {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    bool ValidateNumberInRange(int Number, int From, int To)
    {
        return Number >= From && Number <= To;
    }

    char GetGradeLetter(int grade)
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

    float Calculate(float num1, float num2, enOperationType opType)
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

    enOperationType ReadOpType()
    {
        char op = '+';

        cout << "Enter operator: \n";
        cin >> op;
        return (enOperationType)op;
    }

    enPrimeNotPrime CheckPrime(int num)
    {
        int M = round(num / 2);
        if (num == 0 || num == 1)
            return NotPrime;

        for (int i = 2; i <= M; i++)
        {
            if (num % i == 0)
                return NotPrime;
        }

        return Prime;
    }

    enDayOfWeek ReadDayOfWeek()
    {
        return (enDayOfWeek)ReadNumberInRange("Please enter day number (1-7): ", 1, 7);
    }

    string getDayOfWeek(enDayOfWeek day)
    {
        switch (day)
        {
        case Sun:
            return "Sunday";
        case Mon:
            return "Monday";
        case Tues:
            return "Tuesday";
        case Wed:
            return "Wednesday";
        case Thu:
            return "Thursday";
        case Fri:
            return "Friday";
        case Sat:
            return "Saturday";
        default:
            return "Invalid day number";
        }
    }

    enMonthOfYear ReadMonthOfYear()
    {
        return (enMonthOfYear)ReadNumberInRange("Please enter month number (1-12): ", 1, 12);
    }

    string getMonthOfYear(enMonthOfYear month)
    {
        switch (month)
        {
        case Jan:
            return "January";
        case Feb:
            return "February";
        case Mar:
            return "March";
        case Apr:
            return "April";
        case May:
            return "May";
        case Jun:
            return "June";
        case Jul:
            return "July";
        case Aug:
            return "August";
        case Sep:
            return "September";
        case Oct:
            return "October";
        case Nov:
            return "November";
        case Dec:
            return "December";
        default:
            return "Invalid month number";
        }
    }

    string ColumSeparator(int i)
    {
        if (i >= 10)
            return "     | ";
        else
        {
            return "      | ";
        }
    }

    bool IsDivisor(int dividend, int divisor)
    {
        return (dividend % divisor) == 0;
    }

    int SumOfDivisorsList(int Number)
    {
        int sum = 0;
        for (int i = 1; i <= Number / 2; i++)
        {
            if (IsDivisor(Number, i))
                sum += i;
        }
        return sum;
    }

    bool IsPerfectNumber(int Number)
    {
        return SumOfDivisorsList(Number) == Number;
    }

    void PrintPerfectNumbersFrom1ToN(int Number)
    {
        for (int i = 1; i <= Number; i++)
        {
            if (IsPerfectNumber(i))
                cout << i << endl;
        }
    }

    int SumOfDigits(int Number)
    {
        int sum = 0;
        while (Number > 0)
        {
            sum += Number % 10;
            Number /= 10;
        }
        return sum;
    }

    int ReverseNumber(int Number)
    {
        int result = 0;
        while (Number > 0)
        {
            result = result * 10 + Number % 10; // Wow !!
            Number /= 10;
        }
        return result;
    }

    void PrintDigitsInReverse(int Number)
    {
        cout << "\nReverse is:\n";
        cout << ReverseNumber(Number);
    }

    int CalculateDigitFrequency(int Number, int Digit)
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

    void PrintAllDigitFrequency(int Number)
    {
        for (int i = 0; i <= 9; i++)
        {
            short freq = CalculateDigitFrequency(Number, i);
            if (freq > 0)
                cout << "\nDigit " << i << " Frequency is " << freq << " Time(s).";
        }
    }

    bool CheckPalindrome(int Number)
    {
        return Number == ReverseNumber(Number);
    }

    string Encrypt(string word, short EncryptionKey)
    {
        for (int i = 0; i < word.length(); i++)
        {
            word[i] = word[i] + EncryptionKey;
        }
        return word;
    }

    string Decrypt(string word, short EncryptionKey)
    {
        for (int i = 0; i < word.length(); i++)
        {
            word[i] = word[i] - EncryptionKey;
        }
        return word;
    }

    int RandomNumber(int From, int To)
    {
        // Function to generate random number
        // cout << rand() << "\n";
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    char GetRandomCharacter(enRandomElement CharType)
    {
        // could be done using switch
        if (CharType == SmallLetter)
            return char(RandomNumber('a', 'z')); // 97, 122
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
            cout << "Key [" << i + 1 << "]: " << GenerateKey() << "\n";
        }
    }

    void SeedRandom()
    {
        srand((unsigned)time(NULL));
    }

    float myAbs(float Number)
    {
        if (Number < 0)
            Number *= -1;

        return Number;
    }

    float GetFractionPart(float Number)
    {
        int WholePart = (int)Number;
        return myAbs(Number - WholePart);
    }

    int myRound(float Number)
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

    int myFloor(float Number)
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

    int myCeil(float Number)
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

    int mySqrt(float Number)
    {
        return pow(Number, 0.5);
    }

}

namespace String
{
    void PrintFirstLetterOfEachWordInString(string Sentence)
    {
        bool isFirstLetter = true;

        cout << "\nFirst letters of this string:\n";

        for (short i = 0; i < Sentence.length(); i++)
        {
            if (Sentence.at(i) != ' ' && isFirstLetter)
                cout << Sentence.at(i) << "\n";

            isFirstLetter = (Sentence[i] == ' ' ? true : false);
        }
    }

    string UpperString(string Sentence)
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

    string LowerString(string Sentence)
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

    string LowerAllString(string Sentence)
    {

        for (short i = 0; i < Sentence.length(); i++)
        {
            Sentence[i] = tolower(Sentence[i]);
        }

        return Sentence;
    }

    string UpperAllString(string Sentence)
    {

        for (short i = 0; i < Sentence.length(); i++)
        {
            Sentence[i] = toupper(Sentence[i]);
        }

        return Sentence;
    }

    char InvertCharCase(char Character)
    {
        return isupper(Character) ? tolower(Character) : toupper(Character);
    }

    string InvertAllLettersCase(string Sentence)
    {
        for (short i = 0; i < Sentence.length(); i++)
        {
            Sentence[i] = InvertCharCase(Sentence[i]);
        }
        return Sentence;
    }

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

    short CountLetter(string S1, char Character, bool MatchCase = true)
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

    bool IsVowel(char Letter)
    {
        Letter = tolower(Letter);
        return (Letter == 'a' || Letter == 'e' || Letter == 'i' || Letter == 'o' || Letter == 'u');
    }

    short CountVowels(string S1)
    {
        short VowelCounter = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (String::IsVowel(S1[i]))
                VowelCounter++;
        }

        return VowelCounter;
    }

    void PrintAllVowelsInString(string S1)
    {
        cout << "\nVowels in string are:";
        for (short i = 0; i < S1.length(); i++)
        {
            if (String::IsVowel(S1.at(i)))
                cout << setw(4) << S1[i];
        }
    }

    void PrintEachWordInString(string S1)
    {
        string delimiter = " ";

        cout << "\nYour string words are:\n\n";
        short pos = 0;
        string sWord = "";

        // use find() to get pos of delims
        while ((pos = S1.find(delimiter)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store word
            if (sWord != "")
            {
                cout << sWord << endl;
            }

            S1.erase(0, pos + delimiter.length());
        }

        if (S1 != "")
            cout << S1 << endl;
    }

    short CountEachWordInString(string S1)
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

    vector<string> SplitString(string S1, string delimeter)
    {
        vector<string> vSplittedString;
        string token;
        short pos = 0;

        while ((pos = S1.find(delimeter)) != std::string::npos)
        {
            token = S1.substr(0, pos);

            if (token != "")
            {
                vSplittedString.push_back(token);
            }

            S1.erase(0, pos + delimeter.length());
        }

        if (S1 != "")
            vSplittedString.push_back(S1);

        return vSplittedString;
    }

    string TrimLeft(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ')
                return S1.substr(i, S1.length() - i);
        }
        return "";
    }

    string TrimRight(string S1)
    {
        for (short i = S1.length() - 1; i >= 0; i--)
        {
            if (S1[i] != ' ')
                return S1.substr(0, i + 1);
        }
        return "";
    }

    string Trim(string S1)
    {
        return TrimLeft(TrimRight(S1));
    }

    string JoinString(vector<string> &vWords, string delimiter)
    {
        string Result = "";

        for (string &s : vWords)
        {
            Result += s + delimiter;
        }
        return Result.substr(0, Result.length() - delimiter.length());
    }

    string JoinString(string array[], short length, string delimiter)
    {
        string Result = "";

        for (short i = 0; i < length - 1; i++)
        {
            Result += array[i] + delimiter;
        }

        return Result + array[length - 1];
    }

    string ReverseWords(string S1)
    {
        vector<string> vString = String::SplitString(S1, " ");

        string Result = "";

        vector<string>::iterator iter = vString.end();

        while (iter != vString.begin())
        {
            --iter;

            Result += *iter + " ";
        }

        // for (short i = vString.size() - 1; i > 0; i--)
        // {
        //     Result += vString[i] + " ";
        // }

        // return Result + vString[0];

        return Result.substr(0, Result.length() - 1); // remove last space
    }

    string ReplaceWordsInString(string S1, string OriginalWord, string Replacement, bool MatchCase = true)
    {
        vector<string> vString = String::SplitString(S1, " ");

        for (string &s : vString)
        {
            if (MatchCase)
            {
                if (s == OriginalWord)
                    s = Replacement;
            }

            else
            {
                if (String::LowerAllString(s) == String::LowerAllString(OriginalWord))
                    s = Replacement;
            }
        }

        return String::JoinString(vString, " ");
    }

    string ReplaceWordsInStringUsingBuiltInFunction(string S1, string OrigWord, string Replacement)
    {
        short pos = S1.find(OrigWord);

        while (pos != std::string::npos)
        {
            S1 = S1.replace(pos, OrigWord.length(), Replacement);
            pos = S1.find(OrigWord);
        }

        return S1;
    }

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

}

namespace DateLibrary
{
    struct sDate
    {
        short Day;
        short Month;
        short Year;
    };

    bool IsValidDate(sDate);

    DateLibrary::sDate ReadDate()
    {
        DateLibrary::sDate Date;
        Date.Day = MyInput::ReadShort("\nPlease enter a Day? ");
        Date.Month = MyInput::ReadShort("Please enter a Month? ");
        Date.Year = MyInput::ReadShort("Please enter a year? ");

        if (IsValidDate(Date))
            return Date;

        else
        {
            cout << "\nDate is NOT valid. Enter Again: ";
            return ReadDate();
        }
    }

    bool IsDivisbleBy(int Number, int Divisor)
    {
        return (Number % Divisor == 0);
    }

    bool IsLeapYear(short Year)
    {
        return ((IsDivisbleBy(Year, 400)) || (IsDivisbleBy(Year, 4) && !IsDivisbleBy(Year, 100)));
    }

    int DaysInAYear(int Year)
    {
        const int DAYS_IN_A_LEAP_YEAR = 366;
        const int DAYS_IN_A_NORMAL_YEAR = 365;
        return (IsLeapYear(Year) ? DAYS_IN_A_LEAP_YEAR : DAYS_IN_A_NORMAL_YEAR);
    }

    int HoursInAYear(int Year)
    {
        const int HOURS_IN_A_DAY = 24;

        return DaysInAYear(Year) * HOURS_IN_A_DAY;
    }

    int MinutesInAYear(int Year)
    {
        const int MINS_IN_HOUR = 60;

        return HoursInAYear(Year) * MINS_IN_HOUR;
    }

    int SecondsInAYear(int Year)
    {
        const int SECS_IN_MIN = 60;

        return MinutesInAYear(Year) * SECS_IN_MIN;
    }

    short DayNameOfWeek(short day, short month, short year)
    {
        short a = (14 - month) / 12;
        short y = year - a;
        short m = month + 12 * a - 2;

        short d = (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;

        return d;
    }

    short DayNameOfWeek(DateLibrary::sDate Date)
    {
        return DateLibrary::DayNameOfWeek(Date.Day, Date.Month, Date.Year);
    }

    string DayNameGivenIndex(short index)
    {
        string DaysOfTheWeek[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        return DaysOfTheWeek[index];
    }

    int DaysInAMonth(int Year, int Month)
    {

        // return (Month < 1 || Month > 12) ? 0 : (Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : 31;

        if (Month < 1 || Month > 12)
            return 0;

        int NumOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumOfDays[Month - 1];
    }

    int HoursInAMonth(int Year, int Month)
    {
        const int HOURS_IN_A_DAY = 24;

        return DaysInAMonth(Year, Month) * HOURS_IN_A_DAY;
    }

    int MinutesInAMonth(int Year, int Month)
    {
        const int MINS_IN_HOUR = 60;

        return HoursInAMonth(Year, Month) * MINS_IN_HOUR;
    }

    int SecondsInAMonth(int Year, int Month)
    {
        const int SECS_IN_MIN = 60;

        return MinutesInAMonth(Year, Month) * SECS_IN_MIN;
    }

    string MonthShortName(short MonthNumber)
    {
        string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                           "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

        return months[MonthNumber - 1];
    }

    void PrintMonthCalendar(short year, short month)
    {
        // Print Header
        printf("\n_______________%s_______________\n\n", MonthShortName(month).c_str());
        printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        short NewLineCount = 0;
        // Print Spaces
        short dayIndex = DateLibrary::DayNameOfWeek(1, month, year);
        for (short i = 0; i < dayIndex; i++)
        {
            cout << "     ";
            NewLineCount++;
        }

        // Print Numbers
        int NumberOfDays = DateLibrary::DaysInAMonth(year, month);
        for (short i = 0; i < NumberOfDays; i++)
        {
            printf("%3d  ", i + 1);
            NewLineCount++;
            if (NewLineCount % 7 == 0)
                cout << "\n";
        }

        // Print Tail
        cout << "\n_________________________________" << endl;
    }

    void PrintYearCalendar(short year)
    {
        printf("\n_________________________________\n\n");
        printf("          Calendar - %4d               ", year);
        printf("\n_________________________________\n\n");

        for (short i = 0; i < 12; i++)
        {
            DateLibrary::PrintMonthCalendar(year, i + 1);
        }
    }

    short DaysFromYearStart(short year, short month, short day)
    {
        short days = 0;

        // full months
        for (short i = 1; i < month; i++)
        {
            days += DateLibrary::DaysInAMonth(year, i);
        }

        // rest of days
        days += day;

        return days;
    }

    sDate ConvertDaysToDate(short RemainingDays, short year)
    {
        sDate Date;

        Date.Year = year;

        Date.Month = 0;
        for (int i = 1; i < 12; i++)
        {
            short MonthDays = DateLibrary::DaysInAMonth(year, i);
            Date.Month++;
            if (RemainingDays <= MonthDays)
            {
                Date.Day = RemainingDays;
                break;
            }
            else
            {
                RemainingDays -= DateLibrary::DaysInAMonth(year, i);
            }
        }

        return Date;
    }

    sDate DateAddDays(sDate Date, short DaysToAdd)
    {
        // go back in time to year start
        short RemainingDays = DaysToAdd + DateLibrary::DaysFromYearStart(Date.Year, Date.Month, Date.Day);
        short MonthDays = 0;
        Date.Month = 1;

        while (RemainingDays > 0)
        {
            MonthDays = DateLibrary::DaysInAMonth(Date.Year, Date.Month);

            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                Date.Month++;

                if (Date.Month > 12)
                {
                    Date.Month = 1;
                    Date.Year++;
                }
            }

            else
            {
                Date.Day = RemainingDays;
                RemainingDays = 0;
            }
        }

        return Date;
    }

    bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
    {
        return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
    }

    bool IsDate1EqualToDate2(sDate Date1, sDate Date2)
    {
        return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
    }

    bool IsLastDayInMonth(sDate Date)
    {
        return Date.Day == DateLibrary::DaysInAMonth(Date.Year, Date.Month);
    }

    bool IsLastMonthInYear(sDate Date)
    {
        return Date.Month == 12;
    }

    sDate IncreaseDateByOne(sDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date))
            {
                Date.Day = 1;
                Date.Month = 1;
                Date.Year++;
            }

            else
            {
                Date.Day = 1;
                Date.Month++;
            }
        }

        else
            Date.Day++;

        return Date;
    }

    void GenericSwapDates(DateLibrary::sDate &Date1, DateLibrary::sDate &Date2)
    {
        // MAH swapped them using all struct vars. However, this seems just fine
        DateLibrary::sDate tempDate = Date1;
        Date1 = Date2;
        Date2 = tempDate;
    }

    int DifferenceInDays(DateLibrary::sDate Date1, DateLibrary::sDate Date2, bool IncludeEnd = false)
    {
        int diff = 0;
        short SwapFlageValue = 1;

        if (!DateLibrary::IsDate1BeforeDate2(Date1, Date2))
        {
            GenericSwapDates(Date1, Date2);
            SwapFlageValue = -1;
        }

        while (DateLibrary::IsDate1BeforeDate2(Date1, Date2))
        {
            Date1 = DateLibrary::IncreaseDateByOne(Date1);
            diff++;
        }

        return IncludeEnd ? ++diff * SwapFlageValue : diff * SwapFlageValue;
    }

    DateLibrary::sDate GetSystemDate()
    {
        DateLibrary::sDate Date;

        time_t t = time(0);
        tm *now = localtime(&t);

        Date.Year = now->tm_year + 1900;
        Date.Month = now->tm_mon + 1;
        Date.Day = now->tm_mday;

        return Date;
    }

    DateLibrary::sDate AddToDateByXDays(DateLibrary::sDate Date, int Days)
    {
        for (int i = 0; i < Days; i++)
        {
            Date = DateLibrary::IncreaseDateByOne(Date);
        }

        return Date;
    }

    DateLibrary::sDate AddToDateByOneWeek(DateLibrary::sDate Date)
    {
        Date = AddToDateByXDays(Date, 7);
        return Date;
    }

    DateLibrary::sDate AddToDateByXWeeks(DateLibrary::sDate Date, int Weeks)
    {
        for (int i = 0; i < Weeks; i++)
        {
            Date = AddToDateByOneWeek(Date);
        }

        return Date;
    }

    DateLibrary::sDate AddToDateByOneMonth(DateLibrary::sDate Date)
    {
        if (Date.Month == 12)
        {
            Date.Month = 1;
            Date.Year++;
        }

        else
            Date.Month++;

        // Check it falls in correct range of next month
        short NumOfDaysInCurrentMonth = DateLibrary::DaysInAMonth(Date.Year, Date.Month);
        if (Date.Day > NumOfDaysInCurrentMonth)
            Date.Day = NumOfDaysInCurrentMonth;

        return Date;
    }

    DateLibrary::sDate AddToDateByXMonths(DateLibrary::sDate Date, int Months)
    {
        for (int i = 0; i < Months; i++)
            Date = AddToDateByOneMonth(Date);

        return Date;
    }

    DateLibrary::sDate AddToDateByOneYear(DateLibrary::sDate Date)
    {
        Date.Year++;
        if (!DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
            Date.Day--;

        if (DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 28)
            Date.Day++;

        return Date;
    }

    DateLibrary::sDate AddToDateByXYears(DateLibrary::sDate Date, int Years)
    {
        for (int i = 0; i < Years; i++)
        {
            Date = AddToDateByOneYear(Date);
        }

        return Date;
    }

    DateLibrary::sDate AddToDateByXYearsFaster(DateLibrary::sDate Date, int Years)
    {
        Date.Year += Years;

        if (!DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
            Date.Day--;

        if (DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 28)
            Date.Day++;

        return Date;
    }

    DateLibrary::sDate AddToDateByOneDecade(DateLibrary::sDate Date)
    {
        Date.Year += 10;

        if (!DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
            Date.Day--;

        if (DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 28)
            Date.Day++;

        return Date;
    }

    DateLibrary::sDate AddToDateByXDecades(DateLibrary::sDate Date, int Decades)
    {
        for (int i = 0; i < Decades; i++)
        {
            Date = AddToDateByOneDecade(Date);
        }
        return Date;
    }

    DateLibrary::sDate AddToDateByXDecadesFaster(DateLibrary::sDate Date, int Decades)
    {
        Date.Year += Decades * 10;

        if (!DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
            Date.Day--;

        if (DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 28)
            Date.Day++;

        return Date;
    }

    DateLibrary::sDate AddToDateByOneCentury(DateLibrary::sDate Date)
    {
        Date.Year += 100;

        if (!DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
            Date.Day--;

        if (DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 28)
            Date.Day++;

        return Date;
    }

    DateLibrary::sDate AddToDateByOneMillenium(DateLibrary::sDate Date)
    {
        Date.Year += 1000;

        if (!DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
            Date.Day--;

        if (DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 28)
            Date.Day++;

        return Date;
    }

    DateLibrary::sDate SubtractDateByOne(DateLibrary::sDate Date)
    {
        if (Date.Day == 1)
        {
            if (Date.Month == 1)
            {
                Date.Day = 31;
                Date.Month = 12;
                Date.Year--;
            }

            else
            {
                Date.Month--;
                Date.Day = DateLibrary::DaysInAMonth(Date.Year, Date.Month);
            }
        }

        else
            Date.Day--;

        return Date;
    }

    DateLibrary::sDate SubtractDateByXDays(DateLibrary::sDate Date, int Days)
    {
        for (int i = 0; i < Days; i++)
        {
            Date = SubtractDateByOne(Date);
        }

        return Date;
    }

    DateLibrary::sDate SubtractDateByOneWeek(DateLibrary::sDate Date)
    {
        Date = SubtractDateByXDays(Date, 7);
        return Date;
    }

    DateLibrary::sDate SubtractDateByXWeeks(DateLibrary::sDate Date, int Weeks)
    {
        for (int i = 0; i < Weeks; i++)
        {
            Date = SubtractDateByOneWeek(Date);
        }

        return Date;
    }

    DateLibrary::sDate SubtractDateByOneMonth(DateLibrary::sDate Date)
    {
        if (Date.Month == 1)
        {
            Date.Month = 12;
            Date.Year--;
        }

        else
            Date.Month--;

        // Check it falls in correct range of next month
        short NumOfDaysInCurrentMonth = DateLibrary::DaysInAMonth(Date.Year, Date.Month);
        if (Date.Day > NumOfDaysInCurrentMonth)
            Date.Day = NumOfDaysInCurrentMonth;

        return Date;
    }

    DateLibrary::sDate SubtractDateByXMonths(DateLibrary::sDate Date, int Months)
    {
        for (int i = 0; i < Months; i++)
            Date = SubtractDateByOneMonth(Date);

        return Date;
    }

    DateLibrary::sDate SubtractDateByOneYear(DateLibrary::sDate Date)
    {
        Date.Year--;
        if (!DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
            Date.Day--;

        if (DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 28)
            Date.Day++;

        return Date;
    }

    DateLibrary::sDate SubtractDateByXYears(DateLibrary::sDate Date, int Years)
    {
        for (int i = 0; i < Years; i++)
        {
            Date = SubtractDateByOneYear(Date);
        }

        return Date;
    }

    DateLibrary::sDate SubtractDateByXYearsFaster(DateLibrary::sDate Date, int Years)
    {
        Date.Year -= Years;

        if (!DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
            Date.Day--;

        if (DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 28)
            Date.Day++;

        return Date;
    }

    DateLibrary::sDate SubtractDateByOneDecade(DateLibrary::sDate Date)
    {
        Date.Year -= 10;

        if (!DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
            Date.Day--;

        if (DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 28)
            Date.Day++;

        return Date;
    }

    DateLibrary::sDate SubtractDateByXDecades(DateLibrary::sDate Date, int Decades)
    {
        for (int i = 0; i < Decades; i++)
        {
            Date = SubtractDateByOneDecade(Date);
        }
        return Date;
    }

    DateLibrary::sDate SubtractDateByXDecadesFaster(DateLibrary::sDate Date, int Decades)
    {
        Date.Year -= Decades * 10;

        if (!DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
            Date.Day--;

        if (DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 28)
            Date.Day++;

        return Date;
    }

    DateLibrary::sDate SubtractDateByOneCentury(DateLibrary::sDate Date)
    {
        Date.Year -= 100;

        if (!DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
            Date.Day--;

        if (DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 28)
            Date.Day++;

        return Date;
    }

    DateLibrary::sDate SubtractDateByOneMillenium(DateLibrary::sDate Date)
    {
        Date.Year -= 1000;

        if (!DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
            Date.Day--;

        if (DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 28)
            Date.Day++;

        return Date;
    }

    bool IsEndOfWeek(DateLibrary::sDate Date)
    {
        return DateLibrary::DayNameGivenIndex(DateLibrary::DayNameOfWeek(Date)) == "Sat";
    }

    bool IsWeekEnd(DateLibrary::sDate Date)
    {
        string DayName = DateLibrary::DayNameGivenIndex(DateLibrary::DayNameOfWeek(Date));
        return DayName == "Fri" || DayName == "Sat";
    }

    bool IsBusinessDay(DateLibrary::sDate Date)
    {
        return !DateLibrary::IsWeekEnd(Date);
    }

    short DaysUntilTheEndOfWeek(DateLibrary::sDate Date)
    {
        return 6 - DateLibrary::DayNameOfWeek(Date);
    }

    short DaysUntilTheEndOfMonth(DateLibrary::sDate Date)
    {
        return DateLibrary::DaysInAMonth(Date.Year, Date.Month) - Date.Day;

        // Mah's Way
        // DateLibrary::sDate EndOfMonthDate = {DateLibrary::DaysInAMonth(Date.Year, Date.Month), Date.Month, Date.Year};
        // return DateLibrary::DifferenceInDays(Date, EndOfMonthDate, true);
    }

    short DaysUntilTheEndOfYear(DateLibrary::sDate Date)
    {
        return DateLibrary::DifferenceInDays(Date, {31, 12, Date.Year});
    }

    short ActualVacationDays(DateLibrary::sDate Start, DateLibrary::sDate End)
    {
        short VacationDays = 0;
        while (DateLibrary::IsDate1BeforeDate2(Start, End))
        {
            if (!DateLibrary::IsWeekEnd(Start))
                VacationDays++;
            Start = DateLibrary::IncreaseDateByOne(Start);
        }

        return VacationDays;
    }

    DateLibrary::sDate VacationReturnDate(DateLibrary::sDate Start, short VacationDays)
    {
        // Another idea is having a for loop (i < VacationDays + WeekEndCounter)
        while (VacationDays > 0)
        {

            if (!DateLibrary::IsWeekEnd(Start))
                VacationDays--;
            Start = DateLibrary::IncreaseDateByOne(Start);
        }

        // if it stops on a weekend
        while (DateLibrary::IsWeekEnd(Start))
        {
            Start = DateLibrary::IncreaseDateByOne(Start);
        }

        return Start;
    }

    bool IsDate1AfterDate2(DateLibrary::sDate Date1, DateLibrary::sDate Date2)
    {
        return !DateLibrary::IsDate1BeforeDate2(Date1, Date2) && !DateLibrary::IsDate1EqualToDate2(Date1, Date2);
    }

    enum enDateCompare
    {
        Before = -1,
        Equal = 0,
        After = 1
    };

    enDateCompare CompareDates(DateLibrary::sDate Date1, DateLibrary::sDate Date2)
    {
        if (DateLibrary::IsDate1BeforeDate2(Date1, Date2))
            return enDateCompare::Before;

        if (DateLibrary::IsDate1EqualToDate2(Date1, Date2))
            return enDateCompare::Equal;

        return enDateCompare::After;
    }

    struct Period
    {
        DateLibrary::sDate StartDate;
        DateLibrary::sDate EndDate;
    };

    void ReadPeriod(Period &Period)
    {

        cout << "\nEnter Start Date:\n";
        Period.StartDate = DateLibrary::ReadDate();

        cout << "\nEnter End Date:\n";
        Period.EndDate = DateLibrary::ReadDate();
    }

    bool IsOverlapPeriods(DateLibrary::Period Period1, DateLibrary::Period Period2)
    {

        if (DateLibrary::CompareDates(Period2.EndDate, Period1.StartDate) == DateLibrary::enDateCompare::Before ||
            DateLibrary::CompareDates(Period2.StartDate, Period1.EndDate) == DateLibrary::enDateCompare::After)
            return false;

        return true;

        // return !DateLibrary::CompareDates(Period2.EndDate, Period1.StartDate) == DateLibrary::enDateCompare::Before
        //   &&   !DateLibrary::CompareDates(Period2.StartDate, Period1.EndDate) == DateLibrary::enDateCompare::After)
    }

    short PeriodLengthInDays(Period Period, bool IncludeEnd = false)
    {
        return DateLibrary::DifferenceInDays(Period.StartDate, Period.EndDate, IncludeEnd);
    }

    bool IsDateWithinPeriod(Period Period, DateLibrary::sDate Date)
    {
        return (!(DateLibrary::CompareDates(Date, Period.StartDate) == DateLibrary::enDateCompare::Before ||
                  DateLibrary::CompareDates(Date, Period.EndDate) == DateLibrary::enDateCompare::After)); // Or distribute and change to ADD
    }

    int OverlapDaysCount(Period Period1, Period Period2)
    {
        if (!IsOverlapPeriods(Period1, Period2))
            return 0;

        // if end of period2 is after beg of period1 and beg of period2 before beg of period1
        else if (DateLibrary::CompareDates(Period2.EndDate, Period1.StartDate) == DateLibrary::enDateCompare::After && DateLibrary::CompareDates(Period2.StartDate, Period1.StartDate) == DateLibrary::enDateCompare::Before)
        {
            int FirstRange = abs(DateLibrary::DifferenceInDays(Period2.EndDate, Period1.StartDate));
            int SecondRange = abs(DateLibrary::DifferenceInDays(Period1.EndDate, Period1.StartDate));
            return (FirstRange >= SecondRange ? SecondRange : FirstRange);
        }

        // if beg of period2 before end of period1 and beg of period2 after beg of period1
        else if (DateLibrary::CompareDates(Period2.StartDate, Period1.EndDate) == DateLibrary::enDateCompare::Before && DateLibrary::CompareDates(Period2.StartDate, Period1.StartDate) == DateLibrary::enDateCompare::After)
        {
            int FirstRange = abs(DateLibrary::DifferenceInDays(Period1.EndDate, Period2.StartDate));
            int SecondRange = abs(DateLibrary::DifferenceInDays(Period2.EndDate, Period2.StartDate));
            return (FirstRange >= SecondRange ? SecondRange : FirstRange);
        }

        else
            return 1;
    }

    int CountOverlapDays(Period Period1, Period Period2)
    {
        int Period1Length = PeriodLengthInDays(Period1, true);
        int Period2Length = PeriodLengthInDays(Period2, true);
        int OverlapDays = 0;
        if (!IsOverlapPeriods(Period1, Period2))
            return 0;
        if (Period1Length < Period2Length)
        {
            while (DateLibrary::IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
            {
                if (DateLibrary::IsDateWithinPeriod(Period2, Period1.StartDate))
                    OverlapDays++;
                Period1.StartDate = DateLibrary::IncreaseDateByOne(Period1.StartDate);
            }
        }
        else
        {
            while (DateLibrary::IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
            {
                if (DateLibrary::IsDateWithinPeriod(Period1, Period2.StartDate))
                    OverlapDays++;
                Period2.StartDate = DateLibrary::IncreaseDateByOne(Period2.StartDate);
            }
        }
        return OverlapDays;
    }

    bool IsValidDate(DateLibrary::sDate Date)
    {
        return Date.Day <= DateLibrary::DaysInAMonth(Date.Year, Date.Month) && Date.Day > 0 && Date.Month >= 1 && Date.Month <= 12;

        // if (Date.Day < 1 || Date.Day > 31)
        //     return false;
        // if (Date.Month < 1 || Date.Month > 12)
        //     return false;
        // if (Date.Month == 2)
        // {
        //     if (DateLibrary::IsLeapYear(Date.Year))
        //     {
        //         if (Date.Day > 29)
        //             return false;
        //     }
        //     else
        //     {
        //         if (Date.Day > 28)
        //             return false;
        //     }
        // }
        // short DaysInMonth = DateLibrary::DaysInAMonth(Date.Month, Date.Year);
        // if (Date.Day > DaysInMonth)
        //     return false;
        // return true;
    }

    DateLibrary::sDate StringToDate(string DateString)
    {
        DateLibrary::sDate Date;
        vector<string> vDateString = String::SplitString(DateString, "/");

        Date.Day = stoi(vDateString[0]);
        Date.Month = stoi(vDateString[1]);
        Date.Year = stoi(vDateString[2]);

        if (DateLibrary::IsValidDate(Date))
            return Date;
        else
        {
            cout << "\nInvalidDate.";
            return StringToDate(MyInput::ReadString("\nPlease Enter Date dd/mm/yyyy? "));
        }
    }

    string DateToString(DateLibrary::sDate Date)
    {
        return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
    }

    string ManualFormatDate(DateLibrary::sDate Date, string DateFormat = "dd/mm/yyyy")
    {
        string FormattedDateString = "";
        FormattedDateString = String::ReplaceWordsInStringUsingBuiltInFunction(DateFormat, "dd", to_string(Date.Day));
        FormattedDateString = String::ReplaceWordsInStringUsingBuiltInFunction(FormattedDateString, "mm", to_string(Date.Month));
        FormattedDateString = String::ReplaceWordsInStringUsingBuiltInFunction(FormattedDateString, "yyyy", to_string(Date.Year));

        return FormattedDateString;
    }

}

namespace Matrix
{
    void FillRandomMatrix(int Matrix[3][3], short Rows, short Cols, int From, int To)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                Matrix[i][j] = MyFunctions::RandomNumber(From, To);
            }
        }
    }

    void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
    {

        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                cout << setw(3) << Matrix[i][j] << "\t";
            }
            cout << "\n";
        }
    }

    int SumOfMatrixRow(int MatrixRow[3][3], short RowNumber, short Cols)
    {
        int Sum = 0;
        for (short i = 0; i < Cols; i++)
        {
            Sum += MatrixRow[RowNumber][i];
        }
        return Sum;
    }

    void PrintMatrixRowSums(int Matrix[3][3], short Rows, short Cols)
    {
        for (short i = 0; i < Rows; i++)
        {
            cout << " Row " << i + 1 << " Sum = " << SumOfMatrixRow(Matrix, i, Cols) << endl;
        }
    }

    void SaveRowSumstoArray(int array[3], int Matrix[3][3], short Rows, short Cols)
    {
        for (short i = 0; i < Rows; i++)
        {
            array[i] = SumOfMatrixRow(Matrix, i, Cols);
        }
    }

    void PrintMatrixRowSumsFromArray(int array[3], short Rows)
    {
        for (short i = 0; i < Rows; i++)
        {
            cout << " Row " << i + 1 << " Sum = " << array[i] << endl;
        }
    }

    int SumOfMatrixCol(int Matrix[3][3], short Rows, short ColNumber)
    {
        int Sum = 0;
        for (short i = 0; i < Rows; i++)
        {
            Sum += Matrix[i][ColNumber];
        }
        return Sum;
    }

    void PrintMatrixColSums(int Matrix[3][3], short Rows, short Cols)
    {
        for (short i = 0; i < Cols; i++)
        {
            cout << " Col " << i + 1 << " Sum = " << SumOfMatrixCol(Matrix, Rows, i) << endl;
        }
    }

    void SaveColSumstoArray(int array[3], int Matrix[3][3], short Rows, short Cols)
    {
        for (short i = 0; i < Cols; i++)
        {
            array[i] = Matrix::SumOfMatrixCol(Matrix, Rows, i);
        }
    }

    void PrintMatrixColSumsFromArray(int array[3], short Cols)
    {
        for (short i = 0; i < Cols; i++)
        {
            cout << " Col " << i + 1 << " Sum = " << array[i] << endl;
        }
    }

    void FillOrderedMatrix(int Matrix[3][3], short Rows, short Cols)
    {
        int Number = 1;
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                Matrix[i][j] = Number;
                Number++;
            }
        }
    }

    void TransposeMatrix(int TransposedMatrix[3][3], int Matrix[3][3], int Rows, int Cols)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                TransposedMatrix[i][j] = Matrix[j][i];
            }
        }
    }

    void MultiplyMatrices(int ResultMatrix[3][3], int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                ResultMatrix[i][j] = Matrix1[i][j] * Matrix2[i][j];
            }
        }
    }

    void PrintFormattedMatrix(int Matrix[3][3], short Rows, short Cols)
    {

        for (short i = 0; i < Rows; i++)
        {
            printf(" ");
            for (short j = 0; j < Cols; j++)
            {
                printf("%02d\t", Matrix[i][j]);
            }
            cout << "\n";
        }
    }

    void PrintMiddleRowOfMatrix(int Matrix[3][3], int Row, int Col)
    {
        int MiddleRow = Row / 2;

        for (int i = 0; i < Col; i++)
        {
            printf(" %02d\t", Matrix[MiddleRow][i]);
        }
        cout << "\n";
    }

    void PrintMiddleColOfMatrix(int Matrix[3][3], int Row, int Col)
    {
        int MiddleCol = Col / 2;

        for (int i = 0; i < Row; i++)
        {
            printf(" %02d\t", Matrix[i][MiddleCol]);
        }
        cout << "\n";
    }

    int SumOfMatrix(int Matrix[3][3], short Rows, short Cols)
    {
        int Sum = 0;
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                Sum += Matrix[i][j];
            }
        }
        return Sum;
    }

    bool AreMatricesTypical(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                if (Matrix1[i][j] != Matrix2[i][j])
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool SumOfMatrixEqual(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
    {
        return Matrix::SumOfMatrix(Matrix1, 3, 3) == Matrix::SumOfMatrix(Matrix2, 3, 3);
    }

    bool IsIdentityMatrix(int Matrix[3][3], short Rows, short Cols)
    {

        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                if (i == j && Matrix[i][j] != 1)
                {
                    return false;
                }
                else if (i != j && Matrix[i][j] != 0)
                    return false;
            }
        }

        return true;
    }

    bool IsScalarMatrix(int Matrix[3][3], short Rows, short Cols)
    {
        int FirstDiagElement = Matrix[0][0];
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                if (i == j && Matrix[i][j] != FirstDiagElement)
                {
                    return false;
                }
                else if (i != j && Matrix[i][j] != 0)
                    return false;
            }
        }

        return true;
    }

    int CountNumberInMatrix(int Number, int Matrix[3][3], short Rows, short Cols)
    {
        int count = 0;
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                if (Matrix[i][j] == Number)
                    count++;
            }
        }
        return count;
    }

    bool NumberExistsInMatrix(int Number, int Matrix[3][3], short Rows, short Cols)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                if (Matrix[i][j] == Number)
                    return true;
            }
        }
        return false;
    }

    void PrintIntersectedNumbersInMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
    {
        cout << "\n ";
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                if (Matrix::NumberExistsInMatrix(Matrix1[i][j], Matrix2, Rows, Cols))
                    cout << Matrix1[i][j] << "\t";
            }
        }
        cout << "\n";
    }

    int MinNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
    {
        int Min = INT_MAX;

        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                Min = (Matrix[i][j] < Min) ? Matrix[i][j] : Min;
            }
        }
        return Min;
    }

    int MaxNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
    {
        int Max = INT_MIN;

        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                Max = (Matrix[i][j] > Max) ? Matrix[i][j] : Max;
            }
        }

        return Max;
    }

}

namespace MyArrays
{
    void ReadArray(int Arr1[100], int &Length)
    {
        cout << "Enter the length of the array: ";
        cin >> Length;

        for (int i = 0; i <= Length - 1; i++)
        {
            cout << "Enter number " << i + 1 << ": ";
            cin >> Arr1[i];
        }
    }

    void PrintArray(int array[], int length)
    {
        for (int i = 0; i < length; i++)
        {
            cout << array[i] << " ";
        }

        cout << "\n";
    }

    int TimesRepeated(int Number, int array[], int arrLength)
    {
        int times = 0;
        for (int i = 0; i < arrLength; i++)
            if (array[i] == Number)
                times++;
        return times;
    }

    void FillArrayWithRandomNumber(int array[100], int &arrLength)
    {
        arrLength = ReadPositiveNumber("Enter number of elements: ");
        for (int i = 0; i < arrLength; i++)
        {
            array[i] = MyFunctions::RandomNumber(1, 100);
        }
    }

    int MaxNumberInArray(int array[100], int arrLength)
    {
        int max = INT_MIN;

        for (int i = 0; i < arrLength; i++)
        {
            if (array[i] > max)
                max = array[i];
        }

        return max;
    }

    int MinNumberInArray(int array[100], int arrLength)
    {
        int min = INT_MAX;
        for (int i = 0; i < arrLength; i++)
        {
            if (array[i] < min)
                min = array[i];
        }

        return min;
    }

    int SumOfArray(int array[100], int arrLength)
    {
        int sum = 0;

        for (int i = 0; i < arrLength; i++)
            sum += array[i];

        return sum;
    }

    float AverageOfArray(int array[100], int arrLength)
    {
        return (float)SumOfArray(array, arrLength) / arrLength;
    }

    void CopyArray(int OriginalArray[], int CopiedArray[], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            CopiedArray[i] = OriginalArray[i];
        }
    }

    void CopyArrayOnlyPrime(int OriginalArray[], int TargetArray[], int arrLength, int &arr2Length)
    {

        for (int i = 0; i < arrLength; i++)
            if (MyFunctions::CheckPrime(OriginalArray[i]) == Prime)
            {
                TargetArray[arr2Length] = OriginalArray[i];
                arr2Length++;
            }
    }

    void SumOf2Arrays(int array1[], int array2[], int array3[], int arr1Length, int arr2Length, int &arr3Length)
    {
        if (arr1Length != arr2Length)
        {
            cout << "Cannot add due to different lengths.";
            return;
        }

        arr3Length = arr1Length;

        for (int i = 0; i < arr3Length; i++)
        {
            array3[i] = array1[i] + array2[i];
        }
    }

    bool NumberIsInArray(int Number, int array[], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            if (array[i] == Number)
                return true;
        return false;
    }

    int RandomNumberNotRepeatedInArray(int From, int To, int array[], int arrLength)
    {
        int Number;
        do
        {
            Number = MyFunctions::RandomNumber(From, To);
        } while (NumberIsInArray(Number, array, arrLength));
        return Number;
    }

    void ShuffleArray(int array[], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            MyFunctions::SwapNumbers(array[MyFunctions::RandomNumber(0, arrLength - 1)], array[MyFunctions::RandomNumber(0, arrLength - 1)]);
    }

    void CopyArrayInReverseOrder(int OriginalArray[], int CopiedArray[], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            CopiedArray[i] = OriginalArray[arrLength - 1 - i];
        }
    }

    void FillArrayWithKeys(string array[], int &arrLength)
    {
        arrLength = ReadPositiveNumber("Enter number of keys: ");
        for (int i = 0; i < arrLength; i++)
        {
            array[i] = MyFunctions::GenerateKey();
        }
    }

    short FindNumberPositionInArray(int array[], int arrLength, int Number)
    {

        cout << "\nNumber you are looking for is: " << Number << "\n";
        for (int i = 0; i < arrLength; i++)
        {
            if (array[i] == Number)
            {

                return i;
            }
        }

        return -1; // not there
    }

    bool IsNumberInArray(int array[], int arrLength, int Number)
    {

        cout << "\nNumber you are looking for is: " << Number << "\n";
        for (int i = 0; i < arrLength; i++)
        {
            if (array[i] == Number)
            {

                return true;
            }
        }

        return false; // not there
    }

    void AddNumberToArray(int array[], int &arrLength, int number)
    {
        array[arrLength] = number;
        arrLength++;
    }

    void ReadArraySemiDynamic(int array[], int &arrLength, int MaxLength)
    {
        int number;
        bool input;
        do
        {
            number = ReadNumber("\nPlease enter Number? ");
            AddNumberToArray(array, arrLength, number);
            input = ReadNumber("Do you want to add more numbers?[0]:No,[1]:yes? ");
        } while (input && arrLength < MaxLength);
    }

    void CopyArrayUsingAddArrayElement(int OriginalArray[], int CopiedArray[], int &arr2Length, int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            AddNumberToArray(CopiedArray, arr2Length, OriginalArray[i]);
        }
    }

    void CopyOddArrayElements(int OriginalArray[], int CopiedArray[], int &arr2Length, int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (OriginalArray[i] % 2 == 1)
                AddNumberToArray(CopiedArray, arr2Length, OriginalArray[i]);
        }
    }

    void CopyPrimeArrayElements(int OriginalArray[], int CopiedArray[], int &arr2Length, int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (MyFunctions::CheckPrime(OriginalArray[i]) == Prime)
                AddNumberToArray(CopiedArray, arr2Length, OriginalArray[i]);
        }
    }

    void CopyDistinctNumbers(int OriginalArray[], int CopiedArray[], int &arr2Length, int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            if (!IsNumberInArray(CopiedArray, arr2Length, OriginalArray[i]))
                AddNumberToArray(CopiedArray, arr2Length, OriginalArray[i]);
    }

    bool IsPalindromeArray(int array[], int arrLength)
    {
        int i = 0;
        while (i < arrLength - 1 - i)
        {
            if (array[i] != array[arrLength - 1 - i])
                return false;
            i++;
        }

        return true;
    }

    int OddCount(int arr[], int arrLength)
    {
        int count = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] % 2 == 1)
                count++;
        }
        return count;
    }

    int EvenCount(int arr[], int arrLength)
    {
        int count = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] % 2 == 0)
                count++;
        }
        return count;
    }

    int PositiveCount(int arr[], int arrLength)
    {
        int count = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] >= 0)
                count++;
        }
        return count;
    }

    int NegativeCount(int arr[], int arrLength)
    {
        int count = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] < 0)
                count++;
        }
        return count;
    }

}

namespace MyVectors
{
    void ReadVector(vector<int> &vNumbers)
    {
        char input;
        do
        {
            int Number = ReadNumber("Enter number: ");
            vNumbers.push_back(Number);

            cout << "Do you want to add another number? [Y/N] ";
            cin >> input;
        } while (input == 'y' || input == 'Y');
    }

    void PrintVector(vector<int> &vNumbers)
    {
        cout << "Numbers Vector = ";

        for (int &Number : vNumbers)
        {
            cout << Number << " ";
        }

        cout << endl;
    }

    void PrintVector(vector<string> &vWords)
    {
        for (string &Word : vWords)
        {
            cout << Word << endl;
        }
    }

};