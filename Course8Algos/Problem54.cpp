// VacationDays Function
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

namespace THIS
{
    void ReadVacationPeriod(DateLibrary::sDate &Start, DateLibrary::sDate &End)
    {
        cout << "\nVacation Starts:";
        Start = DateLibrary::ReadDate();

        cout << "\nVacation Ends:";
        End = DateLibrary::ReadDate();
    }

    short ActualVacationDays(DateLibrary::sDate Start, DateLibrary::sDate End)
    {
        short VacationDays = 0;
        while (DateLibrary::IsDate1BeforeDate2(Start, End))
        {
            if (!DateLibrary::IsWeekEnd(Start))
                VacationDays++;
            Start = DateLibrary::IncreaseDateByOne(Start);
        }

        return VacationDays;
    }
}

int main()
{
    DateLibrary::sDate VacationStart;
    DateLibrary::sDate VacationEnd;

    THIS::ReadVacationPeriod(VacationStart, VacationEnd);

    cout << "\nVacation From: " << DateLibrary::DayNameGivenIndex(DateLibrary::DayNameOfWeek(VacationStart)) << " , " << VacationStart.Day << "/" << VacationStart.Month << "/" << VacationStart.Year;
    cout << "\nVacation To  : " << DateLibrary::DayNameGivenIndex(DateLibrary::DayNameOfWeek(VacationEnd)) << " , " << VacationEnd.Day << "/" << VacationEnd.Month << "/" << VacationEnd.Year;

    cout << "\n\nActual Vacation Days are: " << THIS::ActualVacationDays(VacationStart, VacationEnd);
}