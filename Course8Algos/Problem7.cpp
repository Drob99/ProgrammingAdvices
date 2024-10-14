// Day Name of Week

#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

short DayNameOfWeek(short day, short month, short year)
{
    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + 12 * a - 2;

    short d = (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;

    return d;
}

string DayNameGivenIndex(short index)
{
    string DaysOfTheWeek[] = {"Sun", "Mon", "Tue", "Wed", "Thurs", "Fri", "Sat"};
    return DaysOfTheWeek[index];
}

int main()
{
    short year = MyInput::ReadShort("Please enter a year? ");
    short month = MyInput::ReadShort("\nPlease enter a Month? ");
    short day = MyInput::ReadShort("\nPlease enter a Day? ");

    cout << "\nDate         : " << day << "/" << month << "/" << year;

    short index = DayNameOfWeek(day, month, year);
    cout << "\nDay Order    : " << index;
    cout << "\nDay Name     : " << DayNameGivenIndex(index);
}