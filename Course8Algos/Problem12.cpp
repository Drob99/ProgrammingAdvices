// Add Days To Date
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
    Date.Day = MyInput::ReadShort("Please enter a Day? ");
    Date.Month = MyInput::ReadShort("\nPlease enter a Month? ");
    Date.Year = MyInput::ReadShort("\nPlease enter a year? ");

    return Date;
}

sDate AddDaysToDate(sDate Date, short DaysToAdd)
{
    while (DaysToAdd > 0)
    {
        short RemainingDaysForCurrentYear = DateLibrary::DaysInAYear(Date.Year) - DateLibrary::DaysFromYearStart(Date.Year, Date.Month, Date.Day);
        short RemainingDaysForCurrentMonth = DateLibrary::DaysInAMonth(Date.Year, Date.Month) - Date.Day;

        if (DaysToAdd > RemainingDaysForCurrentYear)
        {
            DaysToAdd -= RemainingDaysForCurrentYear;
            Date.Year++;
            Date.Month = 1;
            Date.Day = 1;
            DaysToAdd--;
        }

        else if (DaysToAdd > RemainingDaysForCurrentMonth)
        {
            DaysToAdd -= RemainingDaysForCurrentMonth;
            Date.Month++;
            Date.Day = 1;
            DaysToAdd--;
        }

        else
        {
            Date.Day += DaysToAdd;
            DaysToAdd = 0;
        }
    }

    return Date;
}

sDate DateAddDays(sDate Date, short DaysToAdd)
{
    // go back in time to year start
    short RemainingDays = DaysToAdd + DateLibrary::DaysFromYearStart(Date.Year, Date.Month, Date.Day);
    short MonthDays = 0;
    Date.Month = 1;

    while (RemainingDays > 0)
    {
        MonthDays = DateLibrary::DaysInAMonth(Date.Year, Date.Month);

        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;

            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }

        else
        {
            Date.Day = RemainingDays;
            RemainingDays = 0;
        }
    }

    return Date;
}

int main()
{

    sDate OldDate = ReadDate();

    short DaysToAdd = MyInput::ReadShort("\nHow many days to add? ");

    sDate NewDate = DateAddDays(OldDate, DaysToAdd);
    cout << "\nDays after adding [" << DaysToAdd << "] days is: " << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year;
}