// Count Overlap Days
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

    short PeriodLengthInDays(Period Period, bool IncludeEnd = false)
    {
        return DateLibrary::DifferenceInDays(Period.StartDate, Period.EndDate, IncludeEnd);
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

    int OverlapDaysCount(Period Period1, Period Period2)
    {
        if (!IsOverlapPeriods(Period1, Period2))
            return 0;

        // if end of period2 is after beg of period1 and beg of period2 before beg of period1
        else if (DateLibrary::CompareDates(Period2.EndDate, Period1.StartDate) == DateLibrary::enDateCompare::After && DateLibrary::CompareDates(Period2.StartDate, Period1.StartDate) == DateLibrary::enDateCompare::Before)
        {
            int FirstRange = abs(DateLibrary::DifferenceInDays(Period2.EndDate, Period1.StartDate));
            int SecondRange = abs(DateLibrary::DifferenceInDays(Period1.EndDate, Period1.StartDate));
            return (FirstRange >= SecondRange ? SecondRange : FirstRange);
        }

        // if beg of period2 before end of period1 and beg of period2 after beg of period1
        else if (DateLibrary::CompareDates(Period2.StartDate, Period1.EndDate) == DateLibrary::enDateCompare::Before && DateLibrary::CompareDates(Period2.StartDate, Period1.StartDate) == DateLibrary::enDateCompare::After)
        {
            int FirstRange = abs(DateLibrary::DifferenceInDays(Period1.EndDate, Period2.StartDate));
            int SecondRange = abs(DateLibrary::DifferenceInDays(Period2.EndDate, Period2.StartDate));
            return (FirstRange >= SecondRange ? SecondRange : FirstRange);
        }

        else
            return 1;
    }

    int CountOverlapDays(Period Period1, Period Period2)
    {
        int Period1Length = PeriodLengthInDays(Period1, true);
        int Period2Length = PeriodLengthInDays(Period2, true);
        int OverlapDays = 0;
        if (!IsOverlapPeriods(Period1, Period2))
            return 0;
        if (Period1Length < Period2Length)
        {
            while (DateLibrary::IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
            {
                if (THIS::IsDateWithinPeriod(Period2, Period1.StartDate))
                    OverlapDays++;
                Period1.StartDate = DateLibrary::IncreaseDateByOne(Period1.StartDate);
            }
        }
        else
        {
            while (DateLibrary::IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
            {
                if (THIS::IsDateWithinPeriod(Period1, Period2.StartDate))
                    OverlapDays++;
                Period2.StartDate = DateLibrary::IncreaseDateByOne(Period2.StartDate);
            }
        }
        return OverlapDays;
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

    short DaysCount = THIS::OverlapDaysCount(Period1, Period2);
    cout << "\n\nOverlap Days Count Is: " << DaysCount;
}