// Year Calendar

#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

void PrintYearCalendar(short year)
{
    printf("\n_________________________________\n\n");
    printf("          Calendar - %4d               ", year);
    printf("\n_________________________________\n\n");

    for (short i = 0; i < 12; i++)
    {
        DateLibrary::PrintMonthCalendar(year, i + 1);
    }
}

int main()
{
    short year = MyInput::ReadShort("Please enter a year? ");

    PrintYearCalendar(year);
}