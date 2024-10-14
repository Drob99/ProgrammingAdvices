// Period Length In Days
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

namespace THIS
{
    struct Period
    {
        DateLibrary::sDate StartDate;
        DateLibrary::sDate EndDate;
    };

    void ReadPeriod(Period &Period)
    {

        cout << "\nEnter Start Date:\n";
        Period.StartDate = DateLibrary::ReadDate();

        cout << "\nEnter End Date:\n";
        Period.EndDate = DateLibrary::ReadDate();
    }

    bool IsDateWithinPeriod(Period Period, DateLibrary::sDate Date)
    {
        return (!(DateLibrary::CompareDates(Date, Period.StartDate) == DateLibrary::enDateCompare::Before ||
                  DateLibrary::CompareDates(Date, Period.EndDate) == DateLibrary::enDateCompare::After)); // Or distribute and change to ADD
    }

}

int main()
{
    THIS::Period Period;
    DateLibrary::sDate Date;

    cout << "\nEnter Period:\n";
    THIS::ReadPeriod(Period);

    cout << "\nEnter Date to check:\n";
    Date = DateLibrary::ReadDate();

    if (THIS::IsDateWithinPeriod(Period, Date))
        cout << "\nYes, Date is within period.";

    else
        cout << "\nNo, Date is NOT within period.";
}