#pragma once
#include <iostream>
#include "clsScreen.h"
#include "../Libraries/clsInputValidate.h"
#include <iomanip>
#include "clsBankClient.h"

class clsTransferScreen : protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.GetFirstName();
        cout << "\nLastName    : " << Client.GetLastName();
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.GetEmail();
        cout << "\nPhone       : " << Client.GetPhone();
        cout << "\nAcc. Number : " << Client.GetAccountNumber();
        cout << "\nPassword    : " << Client.GetPinCode();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n___________________\n";
    }

    static string _ReadAccountNumber(string message)
    {
        string AccountNumber = "";
        cout << message;
        cin >> AccountNumber;
        return AccountNumber;
    }

    static string _ValidateAccountNumber(string message)
    {
        string AccountNumber = _ReadAccountNumber(message);

        while (!clsBankClient::IsClientExists(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber(message);
        }

        return AccountNumber;
    }

public:
    static void ShowTransferScreen()
    {
        clsScreen::_DrawScreenHeader("\t Transfer Screen");

        string SenderAccountNumber = _ValidateAccountNumber("\nPlease Account Number To Transfer From: ");
        clsBankClient SourceClient = clsBankClient::Find(SenderAccountNumber);
        _PrintClient(SourceClient);

        string ReceiverAccountNumber = _ValidateAccountNumber("\nPlease Account Number To Transfer To: ");
        clsBankClient DestinationClient = clsBankClient::Find(ReceiverAccountNumber);
        _PrintClient(DestinationClient);

        double Amount = 0;
        cout << "\nPlease Enter Transfer Amount? ";
        Amount = clsInputValidate::ReadDblNumberBetween(1, SourceClient.GetAccountBalance(), "Amount exceeds the available balance, Enter another Amount? ");

        cout << "\nAre you sure you want to perform this transcation [y/n]? ";
        char Answer = 'n';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.GetUserName()))
            {
                cout << "\nTransfer Done Successfully.\n";
            }
            else
            {
                cout << "\nTransfer Failed\n";
            }

            _PrintClient(SourceClient);
            _PrintClient(DestinationClient);
        }

        else
        {
            cout << "\nOperation was cancelled.\n";
        }
    }
};