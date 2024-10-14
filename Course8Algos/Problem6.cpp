// Number Of Days/Hours/Mins/Seconds in Month Short Logic

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

    // return (Month < 1 || Month > 12) ? 0 : (Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : 31;

    if (Month < 1 || Month > 12)
        return 0;

    int NumOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumOfDays[Month - 1];
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