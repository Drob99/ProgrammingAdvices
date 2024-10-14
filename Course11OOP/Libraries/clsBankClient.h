#pragma once
#include <iostream>
#include <string>
#include "../Course11OOP/Libraries/clsPerson.h"
#include "../Libraries/clsString.h"
#include "../Libraries/clsUtil.h"
#include <vector>
#include <fstream>

using namespace std;

class clsBankClient : public clsPerson
{
private:
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,
        AddNewMode = 2
    };
    enMode _Mode;

    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkedForDelete = false;

public:
    struct stTransferLogRecord;

private:
    static clsBankClient _ConvertLinetoClientObject(string Line, string Separator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Separator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1],
                             vClientData[2], vClientData[3], vClientData[4], clsUtil::DecryptText(vClientData[5]), stof(vClientData[6]));
    }

    static string _ConvertClientObjectToLine(clsBankClient Client, string Separator = "#//#")
    {
        string stClientRecord = "";
        stClientRecord += Client.GetFirstName() + Separator;
        stClientRecord += Client.GetLastName() + Separator;
        stClientRecord += Client.GetEmail() + Separator;
        stClientRecord += Client.GetPhone() + Separator;
        stClientRecord += Client.GetAccountNumber() + Separator;
        stClientRecord += clsUtil::EncryptText(Client.GetPinCode()) + Separator;
        stClientRecord += to_string(Client.GetAccountBalance());

        return stClientRecord;
    }

    static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Separator = "#//#")
    {
        stTransferLogRecord TransferLogRecord;

        vector<string> TransferLogDataLine = clsString::Split(Line, Separator);
        TransferLogRecord.DateTime = TransferLogDataLine[0];
        TransferLogRecord.SourceAccountNumber = TransferLogDataLine[1];
        TransferLogRecord.DestinationAccountNumber = TransferLogDataLine[2];
        TransferLogRecord.Amount = stod(TransferLogDataLine[3]);
        TransferLogRecord.SourceAccountBalance = stod(TransferLogDataLine[4]);
        TransferLogRecord.DestinationAccountBalance = stod(TransferLogDataLine[5]);
        TransferLogRecord.UserName = TransferLogDataLine[6];

        return TransferLogRecord;
    }

    static vector<clsBankClient> _LoadClientsDataFromFile()
    {

        vector<clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("../Course11OOP/Files/Clients.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();
        }

        return vClients;
    }

    static void _SaveClientsDataToFile(vector<clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("../Course11OOP/Files/Clients.txt", ios::out); // overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if (!C.GetMarkedForDelete())
                {
                    DataLine = _ConvertClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();
        }
    }

    void _Update()
    {
        vector<clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient &C : _vClients)
        {
            if (C.GetAccountNumber() == GetAccountNumber())
            {
                C = *this;
                break;
            }
        }

        _SaveClientsDataToFile(_vClients);
    }

    void _AddDataLineToFile(string stDataLine)
    {
        fstream MyFile;
        MyFile.open("../Course11OOP/Files/Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }

    string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient, string UserName, string Separator = "#//#")
    {
        string TransferLogRecord = "";
        vector<string> vString = {clsDate::GetSystemDateTimeString(), this->GetAccountNumber(), DestinationClient.GetAccountNumber(),
                                  to_string(Amount), to_string(this->GetAccountBalance()), to_string(DestinationClient.GetAccountBalance()), UserName};

        TransferLogRecord = clsString::JoinString(vString, Separator);

        return TransferLogRecord;
    }

    void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
    {
        fstream TransferLogFile;
        TransferLogFile.open("../Course11OOP/Files/TransferLog.txt", ios::app | ios::out);

        string DataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

        if (TransferLogFile.is_open())
        {
            TransferLogFile << DataLine << endl;
            TransferLogFile.close();
        }
    }

public:
    struct stTransferLogRecord
    {
        string DateTime;
        string SourceAccountNumber;
        string DestinationAccountNumber;
        float Amount;
        float SourceAccountBalance;
        float DestinationAccountBalance;
        string UserName;
    };

    clsBankClient(enMode Mode, string FirstName, string LastName,
                  string Email, string Phone, string AccountNumber, string PinCode,
                  float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    string GetAccountNumber()
    {
        return _AccountNumber;
    }

    bool GetMarkedForDelete()
    {
        return _MarkedForDelete;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }

    // No UI related code inside object
    // void Print()
    // {
    //     cout << "\nClient Card:";
    //     cout << "\n___________________";
    //     cout << "\nFirstName   : " << GetFirstName();
    //     cout << "\nLastName    : " << GetLastName();
    //     cout << "\nFull Name   : " << FullName();
    //     cout << "\nEmail       : " << GetEmail();
    //     cout << "\nPhone       : " << GetPhone();
    //     cout << "\nAcc. Number : " << _AccountNumber;
    //     cout << "\nPassword    : " << _PinCode;
    //     cout << "\nBalance     : " << _AccountBalance;
    //     cout << "\n___________________\n";

    // }

    static clsBankClient Find(string AccountNumber)
    {

        fstream MyFile;
        MyFile.open("../Course11OOP/Files/Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.GetAccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
            }

            MyFile.close();
        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        fstream MyFile;
        MyFile.open("../Course11OOP/Files/Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.GetAccountNumber() == AccountNumber && Client.GetPinCode() == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
            }

            MyFile.close();
        }

        return _GetEmptyClientObject();
    }

    enum enSaveResults
    {
        svFailedEmptyObject = 0,
        svSucceeded = 1,
        svFailedAccountNumberExists = 2
    };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
                return enSaveResults::svFailedEmptyObject;
        }

        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;
            break;
        }

        case enMode::AddNewMode:
        {
            if (clsBankClient::IsClientExists(_AccountNumber))
            {
                return enSaveResults::svFailedAccountNumberExists;
            }

            else
            {
                _AddNew();

                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }

        default:
            return enSaveResults::svFailedEmptyObject;
        }
    }

    static bool IsClientExists(string AccountNumber)
    {
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    bool Delete()
    {
        vector<clsBankClient> vClients;
        vClients = _LoadClientsDataFromFile();

        for (clsBankClient &C : vClients)
        {
            if (C.GetAccountNumber() == _AccountNumber)
            {
                C._MarkedForDelete = true;
                break;
            }
        }

        _SaveClientsDataToFile(vClients);

        *this = _GetEmptyClientObject();

        return true;
    }

    static vector<clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    static float GetTotalBalances()
    {
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();

        float TotalBalances = 0;

        for (clsBankClient Client : vClients)
        {
            TotalBalances += Client.GetAccountBalance();
        }

        return TotalBalances;
    }

    void Deposit(float Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    bool Withdraw(float Amount)
    {
        if (Amount > _AccountBalance)
            return false;
        else
        {
            _AccountBalance -= Amount;
            Save();
        }
        return true;
    }

    bool Transfer(float Amount, clsBankClient &DestinationClient, string UserName)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }

        Withdraw(Amount);
        DestinationClient.Deposit(Amount);
        _RegisterTransferLog(Amount, DestinationClient, UserName);
        return true;
    }

    static vector<stTransferLogRecord> GetTransferLogList()
    {
        vector<stTransferLogRecord> vTransferLogRecord;

        fstream MyFile;

        MyFile.open("../Course11OOP/Files/TransferLog.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            stTransferLogRecord TransferLogRecord;

            while (getline(MyFile, Line))
            {
                TransferLogRecord = _ConvertTransferLogLineToRecord(Line);
                vTransferLogRecord.push_back(TransferLogRecord);
            }

            MyFile.close();
        }

        return vTransferLogRecord;
    }
};
