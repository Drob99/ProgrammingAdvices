// DateToString
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>
#include <vector>

using namespace std;

namespace THIS
{
    enum enDayFormat
    {
        ddmmyyyy = 1,
        yyyyddmm = 2,
        mmddyyyy = 3,
    };

    enum enDateSeparator
    {
        hyphen = 1,
        backslash = 2,
        separate = 3
    };

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

    string FormatDate(DateLibrary::sDate Date, enDayFormat DayFormat, enDateSeparator Separator = enDateSeparator::backslash)
    {
        string DateSeparator = "";

        if (Separator == enDateSeparator::backslash)
            DateSeparator = "/";
        else if (Separator == enDateSeparator::hyphen)
            DateSeparator = "-";

        if (DayFormat == enDayFormat::ddmmyyyy)
        {
            if (DateSeparator == "")
                return "Day:" + to_string(Date.Day) + ", Month:" + to_string(Date.Month) + ", Year:" + to_string(Date.Year);
            else
                return to_string(Date.Day) + DateSeparator + to_string(Date.Month) + DateSeparator + to_string(Date.Year);
        }

        else if (DayFormat == enDayFormat::mmddyyyy)
        {
            if (DateSeparator == "")
                return "Month:" + to_string(Date.Month) + ", Day:" + to_string(Date.Day) + ", Year:" + to_string(Date.Year);
            else
                return to_string(Date.Month) + DateSeparator + to_string(Date.Day) + DateSeparator + to_string(Date.Year);
        }

        else if (DayFormat == enDayFormat::yyyyddmm)
        {
            if (DateSeparator == "")
                return "Year:" + to_string(Date.Year) + ", Day:" + to_string(Date.Day) + ", Month:" + to_string(Date.Month);
            else
                return to_string(Date.Year) + DateSeparator + to_string(Date.Day) + DateSeparator + to_string(Date.Month);
        }
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

int main()
{
    string DateString = MyInput::ReadString("\nPlease Enter Date dd/mm/yyyy? ");

    DateLibrary::sDate Date = THIS::StringToDate(DateString);

    cout << "\n\n";
    cout << THIS::ManualFormatDate(Date, "dd/mm/yyyy");

    cout << "\n\n";
    cout << THIS::FormatDate(Date, THIS::enDayFormat::yyyyddmm);

    cout << "\n\n";
    cout << THIS::FormatDate(Date, THIS::enDayFormat::mmddyyyy);

    cout << "\n\n";
    cout << THIS::FormatDate(Date, THIS::enDayFormat::mmddyyyy, THIS::enDateSeparator::hyphen);

    cout << "\n\n";
    cout << THIS::FormatDate(Date, THIS::enDayFormat::ddmmyyyy, THIS::enDateSeparator::hyphen);

    cout << "\n\n";
    cout << THIS::FormatDate(Date, THIS::enDayFormat::ddmmyyyy, THIS::enDateSeparator::separate);
}