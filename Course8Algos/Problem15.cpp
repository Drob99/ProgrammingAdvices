// Last Day, Last Month
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

int main()
{
    sDate Date = ReadDate();

    if (IsLastDayInMonth(Date))
        cout << "\nYes, Day is Last Day in Month.";

    else
        cout << "\nNo, Day is NOT Last Day in Month.";

    if (IsLastMonthInYear(Date))
        cout << "\nYes, Month is Last Month in Year.";

    else
        cout << "\nNo, Month is NOT Last Month in Year.";

    return 0;
}