// Change seconds into days hours minutes and seconds

#include <iostream>
#include <cmath>

using namespace std;

struct stTaskDuration {
    int numOfDays, numOfHours, numOfMinutes, numOfSeconds;
};


int ReadPositiveNumber(string message)
{
    int num = 0;
    do
    {
        cout << message << endl;
        cin >> num;
    } while (num < 0);
    
    return num;
}

stTaskDuration ConvertSeconds(int seconds)
{

    
    stTaskDuration taskDuration;
    const int SecondsPerDay = 24 * 60 * 60;
    const int SecondsPerHour = 3600;
    const int SecondsPerMinute = 60;

    int remainder = 0;

    taskDuration.numOfDays = floor(seconds / SecondsPerDay);
    remainder = seconds % SecondsPerDay;

    taskDuration.numOfHours = floor(remainder / SecondsPerHour);
    remainder %= SecondsPerHour;

    taskDuration.numOfMinutes = floor(remainder / SecondsPerMinute);
    remainder %= SecondsPerMinute;

    taskDuration.numOfSeconds = remainder;

    return taskDuration;
}


void printTaskDurationDetails(stTaskDuration taskDuration)
{
    cout << "\n";
    cout << taskDuration.numOfDays << ":"
        << taskDuration.numOfHours << ":"
        << taskDuration.numOfMinutes << ":"
        << taskDuration.numOfSeconds << "\n";
}
int main()
{
    int totalSeconds = ReadPositiveNumber("Enter the number of seconds: ");
    printTaskDurationDetails(ConvertSeconds(totalSeconds));
    return 0;
}