//Day of Week
#include <iostream>

using namespace std;

enum enDayOfWeek {Sun = 1, Mon = 2, Tues = 3, Wed = 4, Thu = 5, Fri = 6, Sat = 7};

int ReadNumberInRange(string message, int From, int To)
{
    int num;
    do
    {
        cout <<  "Enter Number: ";
        cin >> num;
    }while(num < From || num > To);

    return num;
}

enDayOfWeek ReadDayOfWeek(){
    return (enDayOfWeek) ReadNumberInRange("Please enter day number (1-7): ", 1, 7);
}

string getDayOfWeek(enDayOfWeek day){
    switch (day)
    {
        case Sun:
            return "Sunday";
        case Mon:   
            return "Monday";
        case Tues:   
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
            return "Invalid day number";
    }
}

int main()
{
    cout << getDayOfWeek(ReadDayOfWeek()) << endl;
    return 0;
    
    
    return 0;
}