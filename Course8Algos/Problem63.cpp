// StringToDate
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

        Date.Day = stod(vDateString[0]);
        Date.Month = stod(vDateString[1]);
        Date.Year = stod(vDateString[2]);

        if (DateLibrary::IsValidDate(Date))
            return Date;
        else
        {
            cout << "\nWrong Format.";
            return StringToDate(MyInput::ReadString("\nPlease Enter Date dd/mm/yyyy? "));
        }
    }
}

int main()
{
    string DateString = MyInput::ReadString("\nPlease Enter Date dd/mm/yyyy? ");

    DateLibrary::sDate Date = THIS::StringToDate(DateString);

    cout << "\nDay  : " << Date.Day;
    cout << "\nMonth: " << Date.Month;
    cout << "\nYear : " << Date.Year;
}