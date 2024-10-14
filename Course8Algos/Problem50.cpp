// IsBusinessDay Function
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

}

int main()
{
    DateLibrary::sDate Date = DateLibrary::GetSystemDate();

    cout << "\nToday is " << DateLibrary::DayNameGivenIndex(DateLibrary::DayNameOfWeek(Date)) << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    cout << "\n\nIs it End of Week?";
    if (DateLibrary::IsEndOfWeek(Date))
        cout << "\nYes, it is end of week.";
    else
        cout << "\nNo, it is NOT end of week.";

    cout << "\n\nIs it Weekend?";
    if (THIS::IsWeekEnd(Date))
        cout << "\nYes, it is a week end.";
    else
        cout << "\nNo, it is NOT a week end.";

    cout << "\n\nIs it Business Day?";
    if (THIS::IsBusinessDay(Date))
        cout << "\nYes, it is a business day.";
    else
        cout << "\nNo, it is NOT a business end.";
}