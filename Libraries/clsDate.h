#pragma once
#pragma warning(disable: 4996)

#include <iostream>
#include <vector>
#include "MyInput.h"
#include "clsString.h"
#include <string>

using namespace std;

class clsDate
{
private:
    short _Day;
    short _Month;
    short _Year;

public:

    clsDate()
    {
        time_t t = time(0);
        tm *now = localtime(&t);

        _Year = now->tm_year + 1900;
        _Month = now->tm_mon + 1;
        _Day = now->tm_mday;
    }

    clsDate(string Date)
    {
        vector<string> vDateString = clsString::Split(Date, "/");

        _Day = stoi(vDateString[0]);
        _Month = stoi(vDateString[1]);
        _Year = stoi(vDateString[2]);
    }

    clsDate(short Day, short Month, short Year)
    {
        _Day = Day;
        _Month = Month;
        _Year = Year;
    }

    clsDate(short DateOrderInYear, short Year)
    {
        clsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);

        _Day = Date1.GetDay();
        _Month = Date1.GetMonth();
        _Year = Date1.GetYear();
    }

    void SetDay(short Day)
    {
        _Day = Day;
    }

    short GetDay()
    {
        return _Day;
    }

    void SetMonth(short Month)
    {
        _Month = Month;
    }

    short GetMonth()
    {
        return _Month;
    }

    void SetYear(short Year)
    {
        _Year = Year;
    }

    short GetYear()
    {
        return _Year;
    }

    void Print()
    {
        cout << DateToString() << endl;
    }

    static bool IsValidDate(clsDate Date)
    {
        return Date.GetDay() <= DaysInAMonth(Date.GetYear(), Date.GetMonth()) && Date.GetDay() > 0 && Date.GetMonth() >= 1 && Date.GetMonth() <= 12;

        // if (Date._Day < 1 || Date._Day > 31)
        //     return false;
        // if (Date._Month < 1 || Date._Month > 12)
        //     return false;
        // if (Date._Month == 2)
        // {
        //     if (IsLeapYear(Date._Year))
        //     {
        //         if (Date._Day > 29)
        //             return false;
        //     }
        //     else
        //     {
        //         if (Date._Day > 28)
        //             return false;
        //     }
        // }
        // short DaysInMonth = DaysInAMonth(Date._Month, Date._Year);
        // if (Date._Day > DaysInMonth)
        //     return false;
        // return true;
    }

    bool IsValid()
    {
        return IsValidDate(*this);
    }

    static string DateToString(clsDate Date)
    {
        return to_string(Date.GetDay()) + "/" + to_string(Date.GetMonth()) + "/" + to_string(Date.GetYear());
    }

    string DateToString()
    {
        return DateToString(*this);
    }

    static bool IsLeapYear(short Year)
    {
        return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
    }

    bool IsLeapYear()
    {
        return IsLeapYear(_Year);
    }

    static short DaysInAYear(short Year)
    {
        const short DAYS_IN_A_LEAP_YEAR = 366;
        const short DAYS_IN_A_NORMAL_YEAR = 365;
        return (IsLeapYear(Year) ? DAYS_IN_A_LEAP_YEAR : DAYS_IN_A_NORMAL_YEAR);
    }

    short DaysInAYear()
    {
        return DaysInAYear(_Year);
    }

    static short HoursInAYear(short Year)
    {
        const short HOURS_IN_A_DAY = 24;

        return DaysInAYear(Year) * HOURS_IN_A_DAY;
    }

    short HoursInAYear()
    {
        return HoursInAYear(_Year);
    }

    static int MinutesInAYear(short Year)
    {
        const short MINS_IN_HOUR = 60;

        return HoursInAYear(Year) * MINS_IN_HOUR;
    }

    int MinutesInAYear()
    {
        return MinutesInAYear(_Year);
    }

    static int SecondsInAYear(short Year)
    {
        const short SECS_IN_MIN = 60;

        return MinutesInAYear(Year) * SECS_IN_MIN;
    }

    int SecondsInAYear()
    {
        return SecondsInAYear(_Year);
    }

    static short DayOfWeekOrder(short day, short month, short year)
    {
        short a = (14 - month) / 12;
        short y = year - a;
        short m = month + 12 * a - 2;

        short d = (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;

        return d;
    }

    short DayOfWeekOrder()
    {
        return DayOfWeekOrder(_Day, _Month, _Year);
    }

    static short DayOfWeekOrder(clsDate Date)
    {
        return DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
    }

    static string DayShortName(short index)
    {
        string DaysOfTheWeek[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        return DaysOfTheWeek[index];
    }

    static string DayShortName(short Day, short Month, short Year)
    {
        return DayShortName(DayOfWeekOrder(Day, Month, Year));
    }

    string DayShortName()
    {
        return DayShortName(_Day, _Month, _Year);
    }

    static short DaysInAMonth(short Year, short Month)
    {
        // return (Month < 1 || Month > 12) ? 0 : (Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : 31;

        if (Month < 1 || Month > 12)
            return 0;

        int NumOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumOfDays[Month - 1];
    }

    short DaysInAMonth()
    {
        return DaysInAMonth(_Year, _Month);
    }

    static short HoursInAMonth(short Year, short Month)
    {
        const short HOURS_IN_A_DAY = 24;

        return DaysInAMonth(Year, Month) * HOURS_IN_A_DAY;
    }

    short HoursInAMonth()
    {
        return HoursInAMonth(_Year, _Month);
    }

    static int MinutesInAMonth(short Year, short Month)
    {
        const short MINS_IN_HOUR = 60;

        return HoursInAMonth(Year, Month) * MINS_IN_HOUR;
    }

    int MinutesInAMonth()
    {
        return MinutesInAMonth(_Year, _Month);
    }

    static int SecondsInAMonth(short Year, short Month)
    {
        const short SECS_IN_MIN = 60;

        return MinutesInAMonth(Year, Month) * SECS_IN_MIN;
    }

    int SecondsInAMonth()
    {
        return SecondsInAMonth(_Year, _Month);
    }

    static string MonthShortName(short MonthNumber)
    {
        string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                             "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

        return months[MonthNumber - 1];
    }

    string MonthShortName()
    {
        return MonthShortName(_Month);
    }

    static void PrintMonthCalendar(short year, short month)
    {
        // Print Header
        printf("\n_______________%s_______________\n\n", MonthShortName(month).c_str());
        printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        short NewLineCount = 0;
        // Print Spaces
        short dayIndex = DayOfWeekOrder(1, month, year);
        for (short i = 0; i < dayIndex; i++)
        {
            cout << "     ";
            NewLineCount++;
        }

        // Print Numbers
        int NumberOfDays = DaysInAMonth(year, month);
        for (short i = 0; i < NumberOfDays; i++)
        {
            printf("%3d  ", i + 1);
            NewLineCount++;
            if (NewLineCount % 7 == 0)
                cout << "\n";
        }

        // Print Tail
        cout << "\n_________________________________" << endl;
    }

    void PrintMonthCalendar()
    {
        PrintMonthCalendar(_Year, _Month);
    }

    static void PrintYearCalendar(short year)
    {
        printf("\n_________________________________\n\n");
        printf("          Calendar - %4d               ", year);
        printf("\n_________________________________\n\n");

        for (short i = 0; i < 12; i++)
        {
            PrintMonthCalendar(year, i + 1);
        }
    }

    void PrintYearCalendar()
    {
        PrintYearCalendar(_Year);
    }

    static short DaysFromYearStart(short year, short month, short day)
    {
        short days = 0;

        // full months
        for (short i = 1; i < month; i++)
        {
            days += DaysInAMonth(year, i);
        }

        // rest of days
        days += day;

        return days;
    }

    short DaysFromYearStart()
    {
        return DaysFromYearStart(_Year, _Month, _Day);
    }

    static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short year)
    {
        clsDate Date;

        short RemainingDays = DateOrderInYear;

        Date._Year = year;

        Date._Month = 0;
        for (int i = 1; i < 12; i++)
        {
            short MonthDays = DaysInAMonth(year, i);
            Date._Month++;
            if (RemainingDays <= MonthDays)
            {
                Date._Day = RemainingDays;
                break;
            }
            else
            {
                RemainingDays -= DaysInAMonth(year, i);
            }
        }

        return Date;
    }

    void AddDays(short DaysToAdd)
    {
        // go back in time to year start
        short RemainingDays = DaysToAdd + DaysFromYearStart(_Year, _Month, _Day);
        short MonthDays = 0;
        _Month = 1;

        while (RemainingDays > 0)
        {
            MonthDays = DaysInAMonth(_Year, _Month);

            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                _Month++;

                if (_Month > 12)
                {
                    _Month = 1;
                    _Year++;
                }
            }

            else
            {
                _Day = RemainingDays;
                RemainingDays = 0;
            }
        }
    }

    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false)) : false);
    }

    bool IsDateBeforeDate2(clsDate Date2)
    {
        return IsDate1BeforeDate2(*this, Date2);
    }

    static bool IsDate1EqualToDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1._Year == Date2._Year && Date1._Month == Date2._Month && Date1._Day == Date2._Day);
    }

    bool IsDateEqualToDate2(clsDate Date2)
    {
        return IsDate1BeforeDate2(*this, Date2);
    }

    static bool IsLastDayInMonth(clsDate Date)
    {
        return Date._Day == DaysInAMonth(Date._Year, Date._Month);
    }

    bool IsLastDayInMonth()
    {
        return IsLastDayInMonth(*this);
    }

    static bool IsLastMonthInYear(clsDate Date)
    {
        return Date._Month == 12;
    }

    static bool IsLastMonthInYear(short Month)
    {
        return Month == 12;
    }

    bool IsLastMonthInYear()
    {
        return IsLastMonthInYear(*this);
    }

    static clsDate IncreaseDateByOne(clsDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date))
            {
                Date._Day = 1;
                Date._Month = 1;
                Date._Year++;
            }

            else
            {
                Date._Day = 1;
                Date._Month++;
            }
        }

        else
            Date._Day++;

        return Date;
    }

    void IncreaseDateByOne()
    {
        *this = IncreaseDateByOne(*this);
    }

    static void SwapDates(clsDate &Date1, clsDate &Date2)
    {
        // MAH swapped them using all struct vars. However, this seems just fine
        clsDate tempDate = Date1;
        Date1 = Date2;
        Date2 = tempDate;
    }

    static int DifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEnd = false)
    {
        int diff = 0;
        short SwapFlagValue = 1;

        if (!IsDate1BeforeDate2(Date1, Date2))
        {
            SwapDates(Date1, Date2);
            SwapFlagValue = -1;
        }

        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Date1 = IncreaseDateByOne(Date1);
            diff++;
        }

        return IncludeEnd ? ++diff * SwapFlagValue : diff * SwapFlagValue;
    }

    int DifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
    {
        return DifferenceInDays(*this, Date2, IncludeEndDay);
    }

    static short CalculateMyAgeInDays(clsDate DateOfBirth)
    {
        return DifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), true);
    }

    static clsDate GetSystemDate()
    {
        clsDate Date;

        time_t t = time(0);
        tm *now = localtime(&t);

        Date._Year = now->tm_year + 1900;
        Date._Month = now->tm_mon + 1;
        Date._Day = now->tm_mday;

        return Date;
    }

    static string GetSystemDateTimeString()
    {
        string LoginData = "";
        time_t t = time(0);
        tm *now = localtime(&t);

        vector <string> vString = {to_string(now->tm_mday), to_string(now->tm_mon + 1), to_string(now->tm_year + 1900)};
        string DateString = clsString::JoinString(vString, "/");

        vString = {to_string(now->tm_hour), to_string(now->tm_min), to_string(now->tm_sec)};
        string TimeString = clsString::JoinString(vString, ":");
        
        return DateString + " - " + TimeString;
    }

    static clsDate AddToDateByXDays(clsDate &Date, short Days)
    {
        for (short i = 0; i < Days; i++)
        {
            Date = IncreaseDateByOne(Date);
        }

        return Date;
    }

    void AddToDateByXDays(short Days)
    {
        AddToDateByXDays(*this, Days);
    }

    static clsDate AddToDateByOneWeek(clsDate &Date)
    {
        Date = AddToDateByXDays(Date, 7);
        return Date;
    }

    void AddToDateByOneWeek()
    {
        AddToDateByOneWeek(*this);
    }

    static clsDate AddToDateByXWeeks(clsDate &Date, short Weeks)
    {
        for (short i = 0; i < Weeks; i++)
        {
            Date = AddToDateByOneWeek(Date);
        }

        return Date;
    }

    void AddToDateByXWeeks(short Weeks)
    {
        AddToDateByXWeeks(*this, Weeks);
    }

    static clsDate AddToDateByOneMonth(clsDate &Date)
    {
        if (Date._Month == 12)
        {
            Date._Month = 1;
            Date._Year++;
        }

        else
            Date._Month++;

        // Check it falls in correct range of next month
        short NumOfDaysInCurrentMonth = DaysInAMonth(Date._Year, Date._Month);
        if (Date._Day > NumOfDaysInCurrentMonth)
            Date._Day = NumOfDaysInCurrentMonth;

        return Date;
    }

    void AddToDateByOneMonth()
    {
        AddToDateByOneMonth(*this);
    }

    static clsDate AddToDateByXMonths(clsDate &Date, short Months)
    {
        for (short i = 0; i < Months; i++)
            Date = AddToDateByOneMonth(Date);

        return Date;
    }

    void AddToDateByXMonths(short Months)
    {
        AddToDateByXMonths(*this, Months);
    }

    static clsDate AddToDateByOneYear(clsDate &Date)
    {
        Date._Year++;
        if (!IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 29)
            Date._Day--;

        if (IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 28)
            Date._Day++;

        return Date;
    }

    void AddToDateByOneYear()
    {
        AddToDateByOneYear(*this);
    }

    static clsDate AddToDateByXYears(clsDate &Date, short Years)
    {
        Date._Year += Years;

        if (!IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 29)
            Date._Day--;

        if (IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 28)
            Date._Day++;

        return Date;
    }

    void AddToDateByXYears(short Years)
    {
        AddToDateByXYears(*this, Years);
    }

    static clsDate AddToDateByOneDecade(clsDate &Date)
    {
        Date._Year += 10;

        if (!IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 29)
            Date._Day--;

        if (IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 28)
            Date._Day++;

        return Date;
    }

    void AddToDateByOneDecade()
    {
        AddToDateByOneDecade(*this);
    }

    static clsDate AddToDateByXDecades(clsDate &Date, short Decades)
    {
        Date._Year += Decades * 10;

        if (!IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 29)
            Date._Day--;

        if (IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 28)
            Date._Day++;

        return Date;
    }

    void AddToDateByXDecades(short Decades)
    {
        AddToDateByXDecades(Decades);
    }

    static clsDate AddToDateByOneCentury(clsDate &Date)
    {
        Date._Year += 100;

        if (!IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 29)
            Date._Day--;

        if (IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 28)
            Date._Day++;

        return Date;
    }

    void AddToDateByOneCentury()
    {
        AddToDateByOneCentury(*this);
    }

    static clsDate AddToDateByOneMillenium(clsDate &Date)
    {
        Date._Year += 1000;

        if (!IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 29)
            Date._Day--;

        if (IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 28)
            Date._Day++;

        return Date;
    }

    void AddToDateByOneMillenium()
    {
        AddToDateByOneMillenium(*this);
    }

    static clsDate SubtractDateByOne(clsDate &Date)
    {
        if (Date._Day == 1)
        {
            if (Date._Month == 1)
            {
                Date._Day = 31;
                Date._Month = 12;
                Date._Year--;
            }

            else
            {
                Date._Month--;
                Date._Day = DaysInAMonth(Date._Year, Date._Month);
            }
        }

        else
            Date._Day--;

        return Date;
    }

    void SubtractDateByOne()
    {
        SubtractDateByOne(*this);
    }

    static clsDate SubtractDateByXDays(clsDate &Date, short Days)
    {
        for (short i = 0; i < Days; i++)
        {
            Date = SubtractDateByOne(Date);
        }

        return Date;
    }

    void SubtractDateByXDays(short Days)
    {
        SubtractDateByXDays(*this, Days);
    }

    static clsDate SubtractDateByOneWeek(clsDate &Date)
    {
        Date = SubtractDateByXDays(Date, 7);
        return Date;
    }

    static clsDate SubtractDateByXWeeks(clsDate &Date, short Weeks)
    {
        for (short i = 0; i < Weeks; i++)
        {
            Date = SubtractDateByOneWeek(Date);
        }

        return Date;
    }

    void SubtractDateByXWeeks(short Weeks)
    {
        SubtractDateByXWeeks(Weeks);
    }

    static clsDate SubtractDateByOneMonth(clsDate &Date)
    {
        if (Date._Month == 1)
        {
            Date._Month = 12;
            Date._Year--;
        }

        else
            Date._Month--;

        // Check it falls in correct range of next month
        short NumOfDaysInCurrentMonth = DaysInAMonth(Date._Year, Date._Month);
        if (Date._Day > NumOfDaysInCurrentMonth)
            Date._Day = NumOfDaysInCurrentMonth;

        return Date;
    }

    void SubtractDateByOneMonth()
    {
        SubtractDateByOneMonth(*this);
    }

    static clsDate SubtractDateByXMonths(clsDate &Date, short Months)
    {
        for (short i = 0; i < Months; i++)
            Date = SubtractDateByOneMonth(Date);

        return Date;
    }

    void SubtractDateByXMonths(short Months)
    {
        SubtractDateByXMonths(*this, Months);
    }

    static clsDate SubtractDateByOneYear(clsDate &Date)
    {
        Date._Year--;
        if (!IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 29)
            Date._Day--;

        if (IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 28)
            Date._Day++;

        return Date;
    }

    void SubtractDateByOneYear()
    {
        SubtractDateByOneYear(*this);
    }

    static clsDate SubtractDateByXYears(clsDate &Date, short Years)
    {
        Date._Year -= Years;

        if (!IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 29)
            Date._Day--;

        if (IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 28)
            Date._Day++;

        return Date;
    }

    void SubtractDateByXYears(short Years)
    {
        SubtractDateByXYears(*this, Years);
    }

    static clsDate SubtractDateByOneDecade(clsDate &Date)
    {
        Date._Year -= 10;

        if (!IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 29)
            Date._Day--;

        if (IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 28)
            Date._Day++;

        return Date;
    }

    void SubtractDateByOneDecade()
    {
        SubtractDateByOneDecade(*this);
    }

    static clsDate SubtractDateByXDecades(clsDate &Date, short Decades)
    {
        Date._Year -= Decades * 10;

        if (!IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 29)
            Date._Day--;

        if (IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 28)
            Date._Day++;

        return Date;
    }

    void SubtractDateByXDecades(short Decades)
    {
        SubtractDateByXDecades(*this, Decades);
    }

    static clsDate SubtractDateByOneCentury(clsDate &Date)
    {
        Date._Year -= 100;

        if (!IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 29)
            Date._Day--;

        if (IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 28)
            Date._Day++;

        return Date;
    }

    void SubtractDateByOneCentury()
    {
        SubtractDateByOneCentury(*this);
    }

    static clsDate SubtractDateByOneMillenium(clsDate &Date)
    {
        Date._Year -= 1000;

        if (!IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 29)
            Date._Day--;

        if (IsLeapYear(Date._Year) && Date._Month == 2 && Date._Day == 28)
            Date._Day++;

        return Date;
    }

    void SubtractDateByOneMillenium()
    {
        SubtractDateByOneMillenium(*this);
    }

    static bool IsEndOfWeek(clsDate Date)
    {
        return DayShortName(DayOfWeekOrder(Date)) == "Sat";
    }

    bool IsEndOfWeek()
    {
        return IsEndOfWeek(*this);
    }

    static bool IsWeekEnd(clsDate Date)
    {
        string DayName = DayShortName(DayOfWeekOrder(Date));
        return DayName == "Fri" || DayName == "Sat";
    }

    bool IsWeekEnd()
    {
        return IsWeekEnd(*this);
    }

    static bool IsBusinessDay(clsDate Date)
    {
        return !IsWeekEnd(Date);
    }

    bool IsBusinessDay()
    {
        return IsBusinessDay(*this);
    }

    static short DaysUntilTheEndOfWeek(clsDate Date)
    {
        return 6 - DayOfWeekOrder(Date);
    }

    short DaysUntilTheEndOfWeek()
    {
        return DaysUntilTheEndOfWeek(*this);
    }

    static short DaysUntilTheEndOfMonth(clsDate Date)
    {
        return DaysInAMonth(Date._Year, Date._Month) - Date._Day + 1; // to include end

        // Mah's Way
        //  clsDate EndOfMonthDate = {DaysInAMonth(Date._Year, Date._Month), Date._Month, Date._Year};
        // return DifferenceInDays(Date, EndOfMonthDate, true);
    }

    short DaysUntilTheEndOfMonth()
    {
        return DaysUntilTheEndOfMonth(*this);
    }

    static short DaysUntilTheEndOfYear(clsDate Date)
    {
        return DifferenceInDays(Date, {31, 12, Date._Year}, true);
    }

    short DaysUntilTheEndOfYear()
    {
        return DaysUntilTheEndOfYear(*this);
    }

    static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
    {
        short BusinessDays = 0;
        while (IsDate1BeforeDate2(DateFrom, DateTo))
        {
            if (IsBusinessDay(DateFrom))
                BusinessDays++;

            DateFrom = IncreaseDateByOne(DateFrom);
        }

        return BusinessDays;
    }

    static short CalculateVacationDays(clsDate Start, clsDate End)
    {
        // short VacationDays = 0;
        // while ( IsDate1BeforeDate2(Start, End))
        // {
        //     if (!IsWeekEnd(Start))
        //         VacationDays ++;
        //     Start = IncreaseDateByOne(Start);

        // }

        // return VacationDays;

        return CalculateBusinessDays(Start, End);
    }

    static clsDate VacationReturnDate(clsDate Start, short VacationDays)
    {
        // Another idea is having a for loop (i < VacationDays + WeekEndCounter)
        while (VacationDays > 0)
        {

            if (!IsWeekEnd(Start))
                VacationDays--;
            Start = IncreaseDateByOne(Start);
        }

        // if it stops on a weekend
        while (IsWeekEnd(Start))
        {
            Start = IncreaseDateByOne(Start);
        }

        return Start;
    }

    static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
    {
        return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualToDate2(Date1, Date2);
    }

    bool IsDateAfterDate2(clsDate Date2)
    {
        return IsDate1AfterDate2(*this, Date2);
    }

    enum enDateCompare
    {
        Before = -1,
        Equal = 0,
        After = 1
    };

    static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
    {
        if (IsDate1BeforeDate2(Date1, Date2))
            return enDateCompare::Before;

        if (IsDate1EqualToDate2(Date1, Date2))
            return enDateCompare::Equal;

        return enDateCompare::After;
    }

    enDateCompare CompareDates(clsDate Date2)
    {
        return CompareDates(*this, Date2);
    }

    static clsDate StringToDate(string DateString)
    {
        clsDate Date;
        vector<string> vDateString = clsString::Split(DateString, "/");

        Date._Day = stoi(vDateString[0]);
        Date._Month = stoi(vDateString[1]);
        Date._Year = stoi(vDateString[2]);

        if (IsValidDate(Date))
            return Date;
        else
        {
            cout << "\nInvalidDate.";
            return StringToDate(MyInput::ReadString("\nPlease Enter Date dd/mm/yyyy? "));
        }
    }

    static string ManualFormatDate(clsDate Date, string DateFormat = "dd/mm/yyyy")
    {
        string FormattedDateString = "";
        FormattedDateString = clsString::ReplaceWordsInStringUsingBuiltInFunction(DateFormat, "dd", to_string(Date._Day));
        FormattedDateString = clsString::ReplaceWordsInStringUsingBuiltInFunction(FormattedDateString, "mm", to_string(Date._Month));
        FormattedDateString = clsString::ReplaceWordsInStringUsingBuiltInFunction(FormattedDateString, "yyyy", to_string(Date._Year));

        return FormattedDateString;
    }

    string ManualFormatDate(string DateFormat = "dd/mm/yyyy")
    {
        return ManualFormatDate(*this, DateFormat);
    }
};