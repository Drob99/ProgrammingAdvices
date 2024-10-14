// IsLeapYear (One Line Of Code)
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
    return ((IsDivisbleBy(Year, 400)) || (IsDivisbleBy(Year, 4) && !IsDivisbleBy(Year, 100)));
}

int main()
{
    short Year = MyInput::ReadNumber("Please enter a year to check? ");

    if (IsLeapYear(Year))
        cout << "\nYes, [" << Year << "] is a leap year.";

    else
        cout << "\nNo, [" << Year << "] is NOT a leap year.";
}