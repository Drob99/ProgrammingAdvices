// Month Calendar

#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

string MonthShortName(short MonthNumber)
{
    string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                       "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    return months[MonthNumber - 1];
}

void PrintMonthCalendar(short year, short month)
{
    // Print Header
    printf("\n_______________%s_______________\n\n", MonthShortName(month).c_str());
    printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    short NewLineCount = 0;
    // Print Spaces
    short dayIndex = DateLibrary::DayNameOfWeek(1, month, year);
    for (short i = 0; i < dayIndex; i++)
    {
        cout << "     ";
        NewLineCount++;
    }

    // Print Numbers
    int NumberOfDays = DateLibrary::DaysInAMonth(year, month);
    for (short i = 0; i < NumberOfDays; i++)
    {
        printf("%3d  ", i + 1);
        NewLineCount++;
        if (NewLineCount % 7 == 0)
            cout << "\n";
    }

    // Print Tail
    cout << "\n_________________________________" << endl;
}

int main()
{
    short year = MyInput::ReadShort("Please enter a year? ");
    short month = MyInput::ReadShort("\nPlease enter a Month? ");

    PrintMonthCalendar(year, month);
}