// DateToString
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>
#include <vector>

using namespace std;

namespace THIS
{
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
}

int main()
{
    string DateString = MyInput::ReadString("\nPlease Enter Date dd/mm/yyyy? ");

    DateLibrary::sDate Date = THIS::StringToDate(DateString);

    cout << "\nDay  : " << Date.Day;
    cout << "\nMonth: " << Date.Month;
    cout << "\nYear : " << Date.Year;

    cout << "\n\nYou entered: " << THIS::DateToString(Date);
}