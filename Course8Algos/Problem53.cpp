// DaysUntilTheEndOfYear Function
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

namespace THIS
{
    bool IsWeekEnd(DateLibrary::sDate Date)
    {
        string DayName = DateLibrary::DayNameGivenIndex(DateLibrary::DayNameOfWeek(Date));
        return DayName == "Fri" || DayName == "Sat";
    }

    bool IsBusinessDay(DateLibrary::sDate Date)
    {
        return !THIS::IsWeekEnd(Date);
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

}

int main()
{
    DateLibrary::sDate Date = DateLibrary::GetSystemDate();

    cout << "\nToday is " << DateLibrary::DayNameGivenIndex(DateLibrary::DayNameOfWeek(Date)) << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    cout << "\n\nIs it End of Week?";
    if (DateLibrary::IsEndOfWeek(Date))
        cout << "\nYes, it is Saturday, it's end of week.";
    else
        cout << "\nNo, it is NOT end of week.";

    cout << "\n\nIs it Weekend?";
    if (THIS::IsWeekEnd(Date))
        cout << "\nYes, it is a week end.";
    else
        cout << "\nNo, today is " << DateLibrary::DayNameGivenIndex(DateLibrary::DayNameOfWeek(Date)) << ", NOT a week end.";

    cout << "\n\nIs it Business Day?";
    if (THIS::IsBusinessDay(Date))
        cout << "\nYes, it is a business day.";
    else
        cout << "\nNo, it is NOT a business end.";

    cout << "\n\nDays until end of week   : " << THIS::DaysUntilTheEndOfWeek(Date) << " Days(s).";
    cout << "\nDays until end of month  : " << THIS::DaysUntilTheEndOfMonth(Date) << " Days(s).";
    cout << "\nDays until end of year   : " << THIS::DaysUntilTheEndOfYear(Date) << " Days(s).";
}