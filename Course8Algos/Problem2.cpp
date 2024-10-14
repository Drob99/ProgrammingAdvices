// IsLeapYear
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

bool IsDivisbleBy(int Number, int Divisor)
{
    return (Number % Divisor == 0);
}

bool IsLeapYear(short Year)
{
    if (IsDivisbleBy(Year, 400))
        return true;

    else if (IsDivisbleBy(Year, 4) && !IsDivisbleBy(Year, 100))
        return true;

    else
        return false;
}

int main()
{
    short Year = MyInput::ReadNumber("Please enter a year to check? ");

    if (IsLeapYear(Year))
        cout << "\nYes, [" << Year << "] is a leap year.";

    else
        cout << "\nNo, [" << Year << "] is NOT a leap year.";
}