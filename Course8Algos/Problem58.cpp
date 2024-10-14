// IsOverlapPeriods
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

    bool IsOverlapPeriods(Period Period1, Period Period2)
    {

        if (DateLibrary::CompareDates(Period2.EndDate, Period1.StartDate) == DateLibrary::enDateCompare::Before ||
            DateLibrary::CompareDates(Period2.StartDate, Period1.EndDate) == DateLibrary::enDateCompare::After)
            return false;

        return true;

        // return !DateLibrary::CompareDates(Period2.EndDate, Period1.StartDate) == DateLibrary::enDateCompare::Before
        //   &&   !DateLibrary::CompareDates(Period2.StartDate, Period1.EndDate) == DateLibrary::enDateCompare::After)
    }

}

int main()
{

    THIS::Period Period1;
    THIS::Period Period2;

    cout << "\nEnter Period1:\n";
    THIS::ReadPeriod(Period1);

    cout << "\nEnter Period2:\n";
    THIS::ReadPeriod(Period2);

    if (THIS::IsOverlapPeriods(Period1, Period2))
        cout << "\nYes, Periods Overlap.";
    else
        cout << "\nNo, Periods Do NOT Overlap.";
}