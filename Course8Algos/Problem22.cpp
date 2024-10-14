// IncreaseDateByXWeeks
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

DateLibrary::sDate IncreaseDateByXDays(DateLibrary::sDate Date, int Days)
{
    for (int i = 0; i < Days; i++)
    {
        Date = DateLibrary::IncreaseDateByOne(Date);
    }

    return Date;
}

DateLibrary::sDate IncreaseDateByOneWeek(DateLibrary::sDate Date)
{
    Date = IncreaseDateByXDays(Date, 7);
    return Date;
}

DateLibrary::sDate IncreaseDateByXWeeks(DateLibrary::sDate Date, int Weeks)
{
    for (int i = 0; i < Weeks; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }

    return Date;
}

int main()
{
    DateLibrary::sDate Date = DateLibrary::ReadDate();

    Date = DateLibrary::IncreaseDateByOne(Date);
    printf("\n01-Adding one day is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByXDays(Date, 10);
    printf("\n02-Adding 10 days is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByOneWeek(Date);
    printf("\n03-Adding one week is: %d/%d/%d", Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByXWeeks(Date, 10);
    printf("\n04-Adding 10 weeks is: %d/%d/%d", Date.Day, Date.Month, Date.Year);
}
