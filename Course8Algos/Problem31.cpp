// IncreaseDateByOneCentury
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

DateLibrary::sDate IncreaseDateByXDays(DateLibrary::sDate Date, int Days)
{
    for (int i = 0; i < Days; i++)
    {
        Date = DateLibrary::IncreaseDateByOne(Date);
    }

    return Date;
}

DateLibrary::sDate IncreaseDateByOneWeek(DateLibrary::sDate Date)
{
    Date = IncreaseDateByXDays(Date, 7);
    return Date;
}

DateLibrary::sDate IncreaseDateByXWeeks(DateLibrary::sDate Date, int Weeks)
{
    for (int i = 0; i < Weeks; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }

    return Date;
}

DateLibrary::sDate IncreaseDateByOneMonth(DateLibrary::sDate Date)
{
    if (Date.Month == 12)
    {
        Date.Month = 1;
        Date.Year++;
    }

    else
        Date.Month++;

    // Check it falls in correct range of next month
    short NumOfDaysInCurrentMonth = DateLibrary::DaysInAMonth(Date.Year, Date.Month);
    if (Date.Day > NumOfDaysInCurrentMonth)
        Date.Day = NumOfDaysInCurrentMonth;

    return Date;
}

DateLibrary::sDate IncreaseDateByXMonths(DateLibrary::sDate Date, int Months)
{
    for (int i = 0; i < Months; i++)
        Date = IncreaseDateByOneMonth(Date);

    return Date;
}

DateLibrary::sDate IncreaseDateByOneYear(DateLibrary::sDate Date)
{
    Date.Year++;
    if (!DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
        Date.Day--;

    if (DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 28)
        Date.Day++;

    return Date;
}

DateLibrary::sDate IncreaseDateByXYears(DateLibrary::sDate Date, int Years)
{
    for (int i = 0; i < Years; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }

    return Date;
}

DateLibrary::sDate IncreaseDateByXYearsFaster(DateLibrary::sDate Date, int Years)
{
    Date.Year += Years;

    if (!DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
        Date.Day--;

    if (DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 28)
        Date.Day++;

    return Date;
}

DateLibrary::sDate IncreaseDateByOneDecade(DateLibrary::sDate Date)
{
    Date.Year += 10;

    if (!DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
        Date.Day--;

    if (DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 28)
        Date.Day++;

    return Date;
}

DateLibrary::sDate IncreaseDateByXDecades(DateLibrary::sDate Date, int Decades)
{
    for (int i = 0; i < Decades; i++)
    {
        Date = IncreaseDateByOneDecade(Date);
    }
    return Date;
}

DateLibrary::sDate IncreaseDateByXDecadesFaster(DateLibrary::sDate Date, int Decades)
{
    Date.Year += Decades * 10;

    if (!DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
        Date.Day--;

    if (DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 28)
        Date.Day++;

    return Date;
}

DateLibrary::sDate IncreaseDateByOneCentury(DateLibrary::sDate Date)
{
    Date.Year += 100;

    if (!DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
        Date.Day--;

    if (DateLibrary::IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 28)
        Date.Day++;

    return Date;
}

int main()
{
    DateLibrary::sDate Date = DateLibrary::ReadDate();

    Date = DateLibrary::IncreaseDateByOne(Date);
    printf("\n01-Adding one day is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByXDays(Date, 10);
    printf("\n02-Adding 10 days is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByOneWeek(Date);
    printf("\n03-Adding one week is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByXWeeks(Date, 10);
    printf("\n04-Adding 10 weeks is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByOneMonth(Date);
    printf("\n05-Adding one month is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByXMonths(Date, 5);
    printf("\n06-Adding 5 months is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByOneYear(Date);
    printf("\n07-Adding one year is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByXYears(Date, 10);
    printf("\n08-Adding 10 Years is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByXYearsFaster(Date, 10);
    printf("\n09-Adding 10 Years (Faster) is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByOneDecade(Date);
    printf("\n10-Adding One Decade is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByXDecades(Date, 10);
    printf("\n11-Adding 10 Decades is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByXDecadesFaster(Date, 10);
    printf("\n12-Adding 10 Decades (Faster) is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByOneCentury(Date);
    printf("\n13-Adding One Century is: %d/%d/%d", Date.Day, Date.Month, Date.Year);
}
