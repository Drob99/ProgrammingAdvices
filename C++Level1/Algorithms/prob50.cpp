//ATM PIN
#include <iostream>

using namespace std;

string ReadPinCode(){
    string pin;

    cout << "Enter your PIN: ";
    cin >> pin;

    return pin;
}

bool Login(){
    string password = "1234";
    string pin;
    int trial = 3;

    do
    {
        trial--;
        pin = ReadPinCode();

        if (pin == password)
        {
            return 1;
        }
        else
        {
            cout << "\nWrong PIN, you have " << trial << " more tries." <<"\n";
            system("color 4F");
        }

    } while (pin != password && trial >= 1);

    return 0;
    
}

int main()
{
    if (Login())
    {
        system("color 2F");
        cout << "\nYour account balance is " << 7500 << ".\n";
    }

    else
        cout << "\nYour card has been blocked. Call the bank for help. \n";

    return 0;
}