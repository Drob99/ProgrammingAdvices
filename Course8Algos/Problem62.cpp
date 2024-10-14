// Validate Date
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

namespace THIS
{
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
}

int main()
{
    DateLibrary::sDate Date = DateLibrary::ReadDate();

    if (THIS::IsValidDate(Date))
        cout << "\nYes, Date is a valid date.";

    else
        cout << "\nNo, Date is NOT valid date.";
}