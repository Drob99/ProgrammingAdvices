// Diff In Days
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

DateLibrary::sDate ReadDate()
{
    DateLibrary::sDate Date;
    Date.Day = MyInput::ReadShort("\nPlease enter a Day? ");
    Date.Month = MyInput::ReadShort("Please enter a Month? ");
    Date.Year = MyInput::ReadShort("Please enter a year? ");

    return Date;
}

int DayDiffBetweenDates(DateLibrary::sDate Date1, DateLibrary::sDate Date2, bool IncludeEnd = false)
{
    int diff = 0;

    while (DateLibrary::IsDate1BeforeDate2(Date1, Date2))
    {
        Date1 = DateLibrary::IncreaseDateByOne(Date1);
        diff++;
    }

    return IncludeEnd ? ++diff : diff;
}

int main()
{
    DateLibrary::sDate Date1 = ReadDate();
    DateLibrary::sDate Date2 = ReadDate();

    cout << "\nDifference is: " << DayDiffBetweenDates(Date1, Date2) << " Day(s).";
    cout << "\nDifference (Including End Day) is: " << DayDiffBetweenDates(Date1, Date2, true) << " Day(s).";
}