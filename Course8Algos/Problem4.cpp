// Number Of Days/Hours/Mins/Seconds in Year
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

bool IsDivisbleBy(int Number, int Divisor)
{
    return (Number % Divisor == 0);
}

bool IsLeapYear(int Year)
{
    return ((IsDivisbleBy(Year, 400)) || (IsDivisbleBy(Year, 4) && !IsDivisbleBy(Year, 100)));
}

int DaysInAYear(int Year)
{
    const int DAYS_IN_A_LEAP_YEAR = 366;
    const int DAYS_IN_A_NORMAL_YEAR = 365;
    return (IsLeapYear(Year) ? DAYS_IN_A_LEAP_YEAR : DAYS_IN_A_NORMAL_YEAR);
}

int HoursInAYear(int Year)
{
    const int HOURS_IN_A_DAY = 24;

    return DaysInAYear(Year) * HOURS_IN_A_DAY;
}

int MinutesInAYear(int Year)
{
    const int MINS_IN_HOUR = 60;

    return HoursInAYear(Year) * MINS_IN_HOUR;
}

int SecondsInAYear(int Year)
{
    const int SECS_IN_MIN = 60;

    return MinutesInAYear(Year) * SECS_IN_MIN;
}

int main()
{
    int Year = MyInput::ReadNumber("Please enter a year to check? ");

    cout << "\n\nNumber of Days     in Year [" << Year << "] is " << DaysInAYear(Year);
    cout << "\nNumber of Hours    in Year [" << Year << "] is " << HoursInAYear(Year);
    cout << "\nNumber of Minutes  in Year [" << Year << "] is " << MinutesInAYear(Year);
    cout << "\nNumber of Seconds  in Year [" << Year << "] is " << SecondsInAYear(Year);
}