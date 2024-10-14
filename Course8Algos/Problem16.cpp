// Increase Date by One

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

sDate ReadDate()
{
    sDate Date;
    Date.Day = MyInput::ReadShort("\nPlease enter a Day? ");
    Date.Month = MyInput::ReadShort("Please enter a Month? ");
    Date.Year = MyInput::ReadShort("Please enter a year? ");

    return Date;
}

bool IsLastDayInMonth(sDate Date)
{
    return Date.Day == DateLibrary::DaysInAMonth(Date.Year, Date.Month);
}

bool IsLastMonthInYear(sDate Date)
{
    return Date.Month == 12;
}

sDate IncreaseDateByOne(sDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date))
        {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }

        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }

    else
        Date.Day++;

    return Date;
}

int main()
{
    sDate Date = ReadDate();

    sDate DatePlusOne = IncreaseDateByOne(Date);
    printf("\nDate after adding one day is: %d/%d/%d", DatePlusOne.Day, DatePlusOne.Month, DatePlusOne.Year);
    return 0;
}