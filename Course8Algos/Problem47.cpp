// Overload DayOfWeek Function
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

short DayOfWeekOrder(DateLibrary::sDate Date)
{
    return DateLibrary::DayNameOfWeek(Date.Day, Date.Month, Date.Year);
}

int main()
{
    DateLibrary::sDate Date = DateLibrary::GetSystemDate();

    cout << "\nToday is " << DateLibrary::DayNameGivenIndex(DayOfWeekOrder(Date)) << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year;
}