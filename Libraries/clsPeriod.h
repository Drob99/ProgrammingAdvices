# pragma once
# include "clsDate.h"

class clsPeriod
{
private:
    clsDate _StartDate;
    clsDate _EndDate;

public:

    clsPeriod(clsDate StartDate, clsDate EndDate)
    {
        _StartDate = StartDate;
        _EndDate = EndDate;
    }

    clsDate GetStartDate()
    {
        return _StartDate;
    }

    void SetStartDate (clsDate StartDate)
    {
        _StartDate = StartDate;
    }

    clsDate GetEndDate()
    {
        return _EndDate;
    }

    void SetEndDate (clsDate EndDate)
    {
        _EndDate = EndDate;
    }

    static bool IsOverlapPeriods (clsPeriod Period1, clsPeriod Period2)
    {

        if (clsDate::CompareDates(Period2._EndDate, Period1._StartDate) == clsDate::enDateCompare::Before 
            || 
            clsDate::CompareDates(Period2._StartDate, Period1._EndDate) == clsDate::enDateCompare::After
            )
            return false;

        return true;

        // return !CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before 
        //   &&   !CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After)
    }

    bool IsOverlapWith (clsPeriod Period2)
    {
        return IsOverlapPeriods (*this, Period2);
    }

    static short PeriodLengthInDays(clsPeriod Period, bool IncludeEnd = false)
    {
        return clsDate::DifferenceInDays(Period._StartDate, Period._EndDate, IncludeEnd);
    }

    short PeriodLengthInDays ()
    {
        return PeriodLengthInDays (*this);
    }

    static bool IsDateWithinPeriod (clsPeriod Period, clsDate Date)
    {
        return (!(clsDate::CompareDates(Date, Period._StartDate) == clsDate::enDateCompare::Before
                || 
                  clsDate::CompareDates(Date, Period._EndDate) == clsDate::enDateCompare::After)
                ); // Or distribute and change to ADD
    }

    bool IsDateWithinPeriod (clsDate Date)
    {
        return IsDateWithinPeriod (*this, Date);
    }

    static short OverlapDaysCount(clsPeriod Period1, clsPeriod Period2)
    {
        if (!IsOverlapPeriods(Period1, Period2))
            return 0;

        // if end of period2 is after beg of period1 and beg of period2 before beg of period1
        else if (clsDate::CompareDates(Period2._EndDate, Period1._StartDate) == clsDate::enDateCompare::After && clsDate::CompareDates(Period2._StartDate, Period1._StartDate) == clsDate::enDateCompare::Before)
        {
            short FirstRange = abs(clsDate::DifferenceInDays(Period2._EndDate, Period1._StartDate));
            short SecondRange = abs(clsDate::DifferenceInDays(Period1._EndDate, Period1._StartDate));
            return (FirstRange >= SecondRange ? SecondRange : FirstRange);
        }

        // if beg of period2 before end of period1 and beg of period2 after beg of period1
        else if (clsDate::CompareDates(Period2._StartDate, Period1._EndDate) == clsDate::enDateCompare::Before && clsDate::CompareDates(Period2._StartDate, Period1._StartDate) == clsDate::enDateCompare::After)
        {
            int FirstRange = abs(clsDate::DifferenceInDays(Period1._EndDate, Period2._StartDate));
            int SecondRange = abs(clsDate::DifferenceInDays(Period2._EndDate, Period2._StartDate));
            return (FirstRange >= SecondRange ? SecondRange : FirstRange);       
        }

        else
            return 1;
        
    }

    short OverlapDaysCount (clsPeriod Period2)
    {
        return OverlapDaysCount (*this, Period2);
    }

    static short CountOverlapDays(clsPeriod Period1, clsPeriod Period2) 
    {
        short Period1Length = PeriodLengthInDays(Period1, true);
        short Period2Length = PeriodLengthInDays(Period2, true);
        short OverlapDays = 0;
        if (!IsOverlapPeriods(Period1, Period2))
            return 0;
        if (Period1Length < Period2Length)
        {
            while (clsDate::IsDate1BeforeDate2(Period1._StartDate, Period1._EndDate))
            {
                if (IsDateWithinPeriod(Period2, Period1._StartDate))
                    OverlapDays++;
                Period1._StartDate = clsDate::IncreaseDateByOne(Period1._StartDate);
            }
        }
        else
        {
            while (clsDate::IsDate1BeforeDate2(Period2._StartDate, Period2._EndDate))
            {
                if (IsDateWithinPeriod(Period1, Period2._StartDate))
                    OverlapDays++;
                Period2._StartDate = clsDate::IncreaseDateByOne(Period2._StartDate);
            }
        }
        return OverlapDays;
    }

    short CountOverlapDays(clsPeriod Period2)
    {
        return CountOverlapDays (*this, Period2);
    }


    void Print()
    {
        cout << "Period Start: ";
        _StartDate.Print();

        cout << "Period End: ";
        _EndDate.Print();
    }

};