// Days Since Beg Of Year

#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

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

int main()
{
    short day = MyInput::ReadShort("Please enter a Day? ");
    short month = MyInput::ReadShort("\nPlease enter a Month? ");
    short year = MyInput::ReadShort("\nPlease enter a year? ");

    printf("\nNumber of Days from the beginning of the year is %d", DaysFromYearStart(year, month, day));
}