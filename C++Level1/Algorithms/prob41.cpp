# include <iostream>

using namespace std;

float ReadPositiveNumber(string message)
{
    float num;
    do
    {
        cout << message << endl;
        cin >> num;
    } while (num < 0);
    
    return num;
}

float hoursToDays(float numOfHours)
{
    return numOfHours / 24;
}

float daysToWeeks(float numOfDays)
{
    return (float) numOfDays / 7;
}

float hoursToWeeks(float numOfHours)
{
    return (float) numOfHours / 24 / 7;
}
int main()
{
    float numOfHours = ReadPositiveNumber("Please enter number of hours: ");
    float numOfDays = hoursToDays(numOfHours);
    float numOfWeeks = daysToWeeks(numOfDays);

    cout << endl;
    cout << "Total Hours = " << numOfHours << endl;
    cout << "Total Days = " << numOfDays << endl;
    cout << "Total Weeks = " << hoursToWeeks(numOfHours) << endl;

    return 0;
}