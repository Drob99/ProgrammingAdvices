// Local/UTC Time

#pragma warning(disable : 4996)

# include <ctime>
# include <iostream>

using namespace std;

int main()
{
    time_t t = time(0); // get time now

    char* dt = ctime(&t); // convert in string form
    cout << "Local date and time is: " << dt << "\n";

    tm* gmtm = gmtime(&t); // convert to struct for UTC date/time
    dt = asctime(gmtm);
    cout << "UTC data and time is: " << dt;
}