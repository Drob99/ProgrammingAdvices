# pragma once

# include <iostream>
using namespace std;

class clsPerson
{
private:
    int _ID;
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:

    clsPerson()
    {

    }
    // Parametrized Constructor
    clsPerson(int ID, string FirstName, string LastName, string Email, string Phone)
    {
        _ID        = ID;
        _FirstName = FirstName;
        _LastName  = LastName;
        _Email     = Email;
        _Phone     = Phone;
    }

    // getters and setters
    int ID() // Read Only Property
    {
        return _ID;
    }

    string FirstName()
    {
        return _FirstName;
    }

    void setFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    string LastName()
    {
        return _LastName;
    }

    void setLastName(string LastName)
    {
        _LastName = LastName;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }


    string Email()
    {
        return _Email;
    }

    void setEmail(string Email)
    {
        _Email = Email;
    }

    string Phone()
    {
        return _Phone;
    }

    void setPhone(string Phone)
    {
        _Phone = Phone;
    }

    // methods

    void Print()
    {
        cout << "\nInfo:";
        cout << "\n----------------------\n";
        cout << "ID         : " << _ID << "\n";
        cout << "FirstName  : " << _FirstName << "\n";
        cout << "LastName   : " << _LastName << "\n";
        cout << "Full Name  : " << FullName() << "\n";
        cout << "Email      : " << _Email   << "\n";
        cout << "Phone      : " << _Phone;
        cout << "\n----------------------\n";
    }

    void SendEmail(string Subject, string Body)
    {
        cout << "\nThe following message sent successfully to email: " << _Email;
        cout << "\nSubject: " << Subject;
        cout << "\nBody: " << Body << endl;
    }

    void SendSMS(string SMS)
    {
        cout << "\nThe following SMS sent successfully to phone: " << _Phone;
        cout << "\n" << SMS << endl;
    }

};
