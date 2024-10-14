// Task Duration

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

stTaskDuration ReadTaskDuration()
{
    stTaskDuration taskDuration;
    taskDuration.numOfDays = ReadPositiveNumber("Enter the number of days: ");
    taskDuration.numOfHours = ReadPositiveNumber("Enter the number of hours: ");
    taskDuration.numOfMinutes = ReadPositiveNumber("Enter the number of minutes: ");
    taskDuration.numOfSeconds = ReadPositiveNumber("Enter the number of seconds: ");

    return taskDuration;
}

int TaskDurationInSeconds(stTaskDuration taskDuration)
{
    int durationInSeconds = 0;

    durationInSeconds = taskDuration.numOfDays * 24 * 60 * 60;
    durationInSeconds += taskDuration.numOfHours * 60 * 60;
    durationInSeconds += taskDuration.numOfMinutes * 60;
    durationInSeconds += taskDuration.numOfSeconds;

    return durationInSeconds;
}

int main()
{
    cout << "\nTask Duration In Seconds: " << TaskDurationInSeconds(ReadTaskDuration());
    cout << endl;
    return 0;
}