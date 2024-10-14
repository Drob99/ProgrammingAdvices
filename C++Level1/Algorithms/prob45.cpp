//month of year
#include <iostream>

using namespace std;
//Day of Week

enum enMonthOfYear {Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6, 
                    Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, 
                    Dec = 12};

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

enMonthOfYear ReadMonthOfYear(){
    return (enMonthOfYear) ReadNumberInRange("Please enter month number (1-12): ", 1, 12);
}

string getMonthOfYear(enMonthOfYear month){
    switch (month)
    {
        case Jan:
            return "January";
        case Feb:   
            return "February";
        case Mar:   
            return "March";
        case Apr:
            return "April";
        case May:   
            return "May";
        case Jun:   
            return "June";
        case Jul:
            return "July";
        case Aug:
            return "August";
        case Sep:
            return "September";
        case Oct:
            return "October";
        case Nov:
            return "November";
        case Dec:
            return "December";
        default:
            return "Invalid month number";
    }
}

int main()
{
    cout << getMonthOfYear(ReadMonthOfYear()) << endl;
    return 0;
}