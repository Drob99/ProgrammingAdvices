// Decrease Date Functions

#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

DateLibrary::sDate DecreaseDateByOne(DateLibrary::sDate Date)
{
    if (Date.Day == 1)
    {
        if (Date.Month == 1)
        {
            Date.Day = 31;
            Date.Month = 12;
            Date.Year--;
        }

        else
        {
            Date.Month--;
            Date.Day = DateLibrary::DaysInAMonth(Date.Year, Date.Month);
        }
    }

    else
        Date.Day--;

    return Date;
}

DateLibrary::sDate DecreaseDateByXDays(DateLibrary::sDate Date, int Days)
{
    for (int i = 0; i < Days; i++)
    {
        Date = DecreaseDateByOne(Date);
    }

    return Date;
}

DateLibrary::sDate DecreaseDateByOneWeek(DateLibrary::sDate Date)
{
    Date = DecreaseDateByXDays(Date, 7);
    return Date;
}

DateLibrary::sDate DecreaseDateByXWeeks(DateLibrary::sDate Date, int Weeks)
{
    for (int i = 0; i < Weeks; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }

    return Date;
}

DateLibrary::sDate DecreaseDateByOneMonth(DateLibrary::sDate Date)
{
    if (Date.Month == 1)
    {
        Date.Month = 12;
        Date.Year--;
    }

    else
        Date.Month--;

    // Check it falls in correct range of next month
    short NumOfDaysInCurrentMonth = DateLibrary::DaysInAMonth(Date.Year, Date.Month);
    if (Date.Day > NumOfDaysInCurrentMonth)
        Date.Day = NumOfDaysInCurrentMonth;

    return Date;
}

DateLibrary::sDate DecreaseDateByXMonths(DateLibrary::sDate Date, int Months)
{
    for (int i = 0; i < Months; i++)
        Date = DecreaseDateByOneMonth(Date);

    return Date;
}

DateLibrary::sDate DecreaseDateByOneYear(DateLibrary::sDate Date)
{
    Date.Year--;
    if (!DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
        Date.Day--;

    if (DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 28)
        Date.Day++;

    return Date;
}

DateLibrary::sDate DecreaseDateByXYears(DateLibrary::sDate Date, int Years)
{
    for (int i = 0; i < Years; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }

    return Date;
}

DateLibrary::sDate DecreaseDateByXYearsFaster(DateLibrary::sDate Date, int Years)
{
    Date.Year -= Years;

    if (!DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
        Date.Day--;

    if (DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 28)
        Date.Day++;

    return Date;
}

DateLibrary::sDate DecreaseDateByOneDecade(DateLibrary::sDate Date)
{
    Date.Year -= 10;

    if (!DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
        Date.Day--;

    if (DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 28)
        Date.Day++;

    return Date;
}

DateLibrary::sDate DecreaseDateByXDecades(DateLibrary::sDate Date, int Decades)
{
    for (int i = 0; i < Decades; i++)
    {
        Date = DecreaseDateByOneDecade(Date);
    }
    return Date;
}

DateLibrary::sDate DecreaseDateByXDecadesFaster(DateLibrary::sDate Date, int Decades)
{
    Date.Year -= Decades * 10;

    if (!DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
        Date.Day--;

    if (DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 28)
        Date.Day++;

    return Date;
}

DateLibrary::sDate DecreaseDateByOneCentury(DateLibrary::sDate Date)
{
    Date.Year -= 100;

    if (!DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
        Date.Day--;

    if (DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 28)
        Date.Day++;

    return Date;
}

DateLibrary::sDate DecreaseDateByOneMillenium(DateLibrary::sDate Date)
{
    Date.Year -= 1000;

    if (!DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
        Date.Day--;

    if (DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 28)
        Date.Day++;

    return Date;
}

int main()
{
    DateLibrary::sDate Date = DateLibrary::ReadDate();

    Date = DecreaseDateByOne(Date);
    printf("\n01-Subtracting one day is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByXDays(Date, 10);
    printf("\n02-Subtracting 10 days is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByOneWeek(Date);
    printf("\n03-Subtracting one week is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByXWeeks(Date, 10);
    printf("\n04-Subtracting 10 weeks is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByOneMonth(Date);
    printf("\n05-Subtracting one month is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByXMonths(Date, 5);
    printf("\n06-Subtracting 5 months is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByOneYear(Date);
    printf("\n07-Subtracting one year is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByXYears(Date, 10);
    printf("\n08-Subtracting 10 Years is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByXYearsFaster(Date, 10);
    printf("\n09-Subtracting 10 Years (Faster) is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByOneDecade(Date);
    printf("\n10-Subtracting One Decade is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByXDecades(Date, 10);
    printf("\n11-Subtracting 10 Decades is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByXDecadesFaster(Date, 10);
    printf("\n12-Subtracting 10 Decades (Faster) is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByOneCentury(Date);
    printf("\n13-Subtracting One Century is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByOneMillenium(Date);
    printf("\n14-Subtracting One Millenium is: %d/%d/%d", Date.Day, Date.Month, Date.Year);
}
