// Date1 After Date2 Function
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

namespace THIS
{
    void ReadTwoDates(DateLibrary::sDate &Date1, DateLibrary::sDate &Date2)
    {
        Date1 = DateLibrary::ReadDate();

        Date2 = DateLibrary::ReadDate();
    }

    bool IsDate1AfterDate2(DateLibrary::sDate Date1, DateLibrary::sDate Date2)
    {
        return !DateLibrary::IsDate1BeforeDate2(Date1, Date2) && !DateLibrary::IsDate1EqualToDate2(Date1, Date2);
    }
}

int main()
{
    DateLibrary::sDate Date1;
    DateLibrary::sDate Date2;

    THIS::ReadTwoDates(Date1, Date2);

    if (THIS::IsDate1AfterDate2(Date1, Date2))
        cout << "\nYes, Date1 is After Date2.";
    else
        cout << "\nNo, Date1 is NOT After Date2.";
}