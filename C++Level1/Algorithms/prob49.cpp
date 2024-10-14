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

    do
    {
        pin = ReadPinCode();

        if (pin == password)
        {
            return 1;
        }
        else
        {
            cout << "\nWrong PIN\n";
            system("color 4F");
        }

    } while (pin != password);

    return 0;
    
}

int main()
{
    if (Login())
    {
        system("color 2F");
        cout << "\nYour account balance is " << 7500 << ".\n";
    }

    return 0;
}