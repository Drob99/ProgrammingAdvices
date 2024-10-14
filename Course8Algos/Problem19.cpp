// Diff In Days (-ve Nums)
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

void SwapDates(DateLibrary::sDate &Date1, DateLibrary::sDate &Date2)
{
    // MAH swapped them using all struct vars. However, this seems just fine
    DateLibrary::sDate tempDate = Date1;
    Date1 = Date2;
    Date2 = tempDate;
}

int DayDiffBetweenDates(DateLibrary::sDate Date1, DateLibrary::sDate Date2, bool IncludeEnd = false)
{
    int diff = 0;
    short SwapFlageValue = 1;

    if (!DateLibrary::IsDate1BeforeDate2(Date1, Date2))
    {
        SwapDates(Date1, Date2);
        SwapFlageValue = -1;
    }

    while (DateLibrary::IsDate1BeforeDate2(Date1, Date2))
    {
        Date1 = DateLibrary::IncreaseDateByOne(Date1);
        diff++;
    }

    return IncludeEnd ? ++diff * SwapFlageValue : diff * SwapFlageValue;
}

int main()
{
    DateLibrary::sDate Date1 = ReadDate();
    DateLibrary::sDate Date2 = ReadDate();

    cout << "\nDifference is: " << DayDiffBetweenDates(Date1, Date2) << " Day(s).";
    cout << "\nDifference (Including End Day) is: " << DayDiffBetweenDates(Date1, Date2, true) << " Day(s).";
}