// Compare Dates
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

namespace THIS
{
    enum enDateCompare
    {
        Before = -1,
        Equal = 0,
        After = 1
    };

    void ReadTwoDates(DateLibrary::sDate &Date1, DateLibrary::sDate &Date2)
    {
        cout << "\nEnter Date1:";
        Date1 = DateLibrary::ReadDate();

        cout << "\nEnter Date2:";
        Date2 = DateLibrary::ReadDate();
    }

    enDateCompare CompareDates(DateLibrary::sDate Date1, DateLibrary::sDate Date2)
    {
        if (DateLibrary::IsDate1BeforeDate2(Date1, Date2))
            return enDateCompare::Before;

        if (DateLibrary::IsDate1EqualToDate2(Date1, Date2))
            return enDateCompare::Equal;

        return enDateCompare::After;
    }
}

int main()
{

    DateLibrary::sDate Date1;

    DateLibrary::sDate Date2;

    THIS::ReadTwoDates(Date1, Date2);

    cout << "\nCompare Result = " << (short)(THIS::CompareDates(Date1, Date2));
}