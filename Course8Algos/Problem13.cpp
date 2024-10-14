// Check if Date1 is less than Date2
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

struct sDate
{
    short Day;
    short Month;
    short Year;
};

sDate ReadDate()
{
    sDate Date;
    Date.Day = MyInput::ReadShort("\nPlease enter a Day? ");
    Date.Month = MyInput::ReadShort("Please enter a Month? ");
    Date.Year = MyInput::ReadShort("Please enter a year? ");

    return Date;
}

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

int main()
{
    sDate Date1 = ReadDate();
    sDate Date2 = ReadDate();

    if (IsDate1BeforeDate2(Date1, Date2))
        cout << "\nYes, Date1 is Less than Date2.";

    else
        cout << "\nNo, Date1 is NOT Less than Date2.";

    return 0;
}