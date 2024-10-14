#include <iostream>

using namespace std;

enum enWeekDay {Sun  = 1, Mon = 2, Tue = 3, Wed = 4, Thu = 5, Fri = 6, Sat = 7};

void ShowWeekDayMenu()
{
    cout << "*****************************" << endl;
    cout << "          Week Days          " << endl;
    cout << "*****************************" << endl;
    cout << "1. Sunday" << endl;
    cout << "2. Monday" << endl;
    cout << "3. Tuesday" << endl;
    cout << "4. Wednesday" << endl;
    cout << "5. Thursday" << endl;
    cout << "6. Friday" << endl;
    cout << "7. Saturday" << endl;
    cout << "*****************************" << endl;
    cout << "Please enter the number of day? " << endl;
}

enWeekDay ReadWeekDay()
{
    int day;
    cin >> day;
    return (enWeekDay) day;
}

string GetWeekDayName(enWeekDay WeekDay)
{
    switch (WeekDay)
    {
        case Sun:
            return "Sunday";
        case Mon:
            return "Monday";
        case Tue:
            return "Tuesday";
        case Wed:
            return "Wednesday";
        case Thu:
            return "Thursday";
        case Fri:
            return "Friday";
        case Sat:
            return "Saturday";
        default:
            return "Invalid day";
    }
}

int main()
{
    ShowWeekDayMenu();

    cout << "The day is " << GetWeekDayName(ReadWeekDay()) << endl;

    return 0;
}