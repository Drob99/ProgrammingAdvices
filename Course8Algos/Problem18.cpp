// Your Age In Days
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

DateLibrary::sDate ReadDate()
{
    DateLibrary::sDate Date;
    Date.Day = MyInput::ReadShort("\nPlease enter a Day? ");
    Date.Month = MyInput::ReadShort("Please enter a Month? ");
    Date.Year = MyInput::ReadShort("Please enter a year? ");

    return Date;
}

DateLibrary::sDate GetSystemDate()
{
    DateLibrary::sDate Date;

    time_t t = time(0);
    tm *now = localtime(&t);

    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;

    return Date;
}

int main()
{
    cout << "Please Enter Your Date of Birth:\n";

    DateLibrary::sDate Birthday = ReadDate();
    DateLibrary::sDate Today = GetSystemDate();

    cout << "\nYour Age is : " << DateLibrary::DifferenceInDays(Birthday, Today, true) << " Day(s).";
}