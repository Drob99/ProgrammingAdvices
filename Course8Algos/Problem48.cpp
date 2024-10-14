// IsEndOfWeek
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

namespace THIS
{
    bool IsEndOfWeek(DateLibrary::sDate Date)
    {
        return DateLibrary::DayNameGivenIndex(DateLibrary::DayNameOfWeek(Date)) == "Sat";
    }
}

int main()
{
    DateLibrary::sDate Date = DateLibrary::GetSystemDate();

    cout << "\nToday is " << DateLibrary::DayNameGivenIndex(DateLibrary::DayNameOfWeek(Date)) << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    cout << "\n\nIs it End of Week?";
    if (THIS::IsEndOfWeek(Date))
        cout << "\nYes, it is end of week.";
    else
        cout << "\nNo, it is NOT end of week.";
}