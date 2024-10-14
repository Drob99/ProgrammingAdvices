// Number Of Days/Hours/Mins/Seconds in Month
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

int DaysInAMonth(int Year, int Month)
{
    if (Month < 1 || Month > 12)
        return 0;

    if (Month == 2)
        return (IsLeapYear(Year) ? 29 : 28);

    short arr30Days[4] = {4, 6, 9, 11};

    for (short i = 0; i < 4; i++)
    {
        if (arr30Days[i] == Month)
            return 30;
    }

    return 31;
}

int HoursInAMonth(int Year, int Month)
{
    const int HOURS_IN_A_DAY = 24;

    return DaysInAMonth(Year, Month) * HOURS_IN_A_DAY;
}

int MinutesInAMonth(int Year, int Month)
{
    const int MINS_IN_HOUR = 60;

    return HoursInAMonth(Year, Month) * MINS_IN_HOUR;
}

int SecondsInAMonth(int Year, int Month)
{
    const int SECS_IN_MIN = 60;

    return MinutesInAMonth(Year, Month) * SECS_IN_MIN;
}

int ReadMonth(string message)
{
    int month;
    cout << message;
    cin >> month;
    return month;
}

int main()
{
    int Year = MyInput::ReadNumber("Please enter a year to check? ");

    int Month = ReadMonth("\nPlease enter a Month to check? ");

    cout << "\n\nNumber of Days     in Month [" << Month << "] is " << DaysInAMonth(Year, Month);
    cout << "\nNumber of Hours    in Month [" << Month << "] is " << HoursInAMonth(Year, Month);
    cout << "\nNumber of Minutes  in Month [" << Month << "] is " << MinutesInAMonth(Year, Month);
    cout << "\nNumber of Seconds  in Month [" << Month << "] is " << SecondsInAMonth(Year, Month);
}