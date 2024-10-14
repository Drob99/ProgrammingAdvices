// Days Since Beg Of Year & Convert Back To Date

#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

struct sDate
{
    short Day;
    short Month;
    short Year;
};

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
            RemainingDays -= MonthDays;
        }
    }

    return Date;
}

int main()
{
    short day = MyInput::ReadShort("Please enter a Day? ");
    short month = MyInput::ReadShort("\nPlease enter a Month? ");
    short year = MyInput::ReadShort("\nPlease enter a year? ");

    short days = DaysFromYearStart(year, month, day);
    printf("\nNumber of Days from the beginning of the year is %d", days);

    sDate Date = ConvertDaysToDate(days, year);
    cout << "\n\nDate for [" << days << "] is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}