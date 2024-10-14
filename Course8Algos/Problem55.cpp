// VacationReturnDate Function
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

namespace THIS
{
    void ReadVacationStartAndDays(DateLibrary::sDate &Start, short &VacationDays)
    {
        cout << "\nVacation Starts:";
        Start = DateLibrary::ReadDate();

        VacationDays = MyInput::ReadShort("\nPlease enter vacation days? ");
    }

    DateLibrary::sDate VacationReturnDate(DateLibrary::sDate Start, short VacationDays)
    {
        // Another idea is having a for loop (i < VacationDays + WeekEndCounter)
        while (VacationDays > 0)
        {

            if (!DateLibrary::IsWeekEnd(Start))
                VacationDays--;
            Start = DateLibrary::IncreaseDateByOne(Start);
        }

        // if it stops on a weekend
        while (DateLibrary::IsWeekEnd(Start))
        {
            Start = DateLibrary::IncreaseDateByOne(Start);
        }

        return Start;
    }
}

int main()
{
    DateLibrary::sDate VacationStart;
    short VacationDays;

    THIS::ReadVacationStartAndDays(VacationStart, VacationDays);

    DateLibrary::sDate VacationEnd;
    VacationEnd = THIS::VacationReturnDate(VacationStart, VacationDays);
    cout << "\nReturn Date: " << DateLibrary::DayNameGivenIndex(DateLibrary::DayNameOfWeek(VacationEnd)) << " , " << VacationEnd.Day << "/" << VacationEnd.Month << "/" << VacationEnd.Year;
}