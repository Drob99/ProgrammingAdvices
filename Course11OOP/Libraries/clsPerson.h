#pragma once
#include <iostream>
#include <string>
#include "InterfaceCommunication.h"
using namespace std;


class clsPerson : public InterfaceCommunication
{
private:

    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:

    clsPerson()
    {

    }
    // Parametrized Constructor
    clsPerson(string FirstName, string LastName, string Email, string Phone)
    {
        _FirstName = FirstName;
        _LastName  = LastName;
        _Email     = Email;
        _Phone     = Phone;
    }

    string GetFirstName()
    {
        return _FirstName;
    }

    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    string GetLastName()
    {
        return _LastName;
    }

    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    string GetEmail()
    {
        return _Email;
    }

    void SetEmail(string Email)
    {
        _Email = Email;
    }

    string GetPhone()
    {
        return _Phone;
    }

    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }

    // void Print()
    // {
    //     cout << "\nInfo:";
    //     cout << "\n___________________";
    //     cout << "\nFirstName: " << _FirstName;
    //     cout << "\nLastName : " << _LastName;
    //     cout << "\nFull Name: " << FullName();
    //     cout << "\nEmail    : " << _Email;
    //     cout << "\nPhone    : " << _Phone;
    //     cout << "\n___________________\n";
    // }

    void SendEmail(string Title, string Body)
    {

    }

    void SendFax(string Title, string Body)
    {

    }

    void SendSMS (string Title, string Body)
    {
        
    }
};