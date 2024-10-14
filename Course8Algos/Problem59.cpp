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

    short PeriodLengthInDays(Period Period, bool IncludeEnd = false)
    {
        return DateLibrary::DifferenceInDays(Period.StartDate, Period.EndDate, IncludeEnd);
    }

}

int main()
{
    THIS::Period Period;

    cout << "\nEnter Period:\n";
    THIS::ReadPeriod(Period);

    cout << "\nPeriod Length is: " << THIS::PeriodLengthInDays(Period);
    cout << "\nPeriod Length (Including End Date) is: " << THIS::PeriodLengthInDays(Period, true);
}