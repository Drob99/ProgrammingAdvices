#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include "../Libraries/MyFiles.h"
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;
const string FILENAME = "../Files/BankRecords.txt";

void ShowATMMenu();
void LogIn();
void NormalWithdraw();
void PrintBalance();
void GoBackToMainMenu();
void QuickWithdraw();

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

sClient CurrentClient;

enum enAction
{
    enQuickWithdraw = 1,
    enNormalWithdraw = 2,
    enDeposit = 3,
    enCheckBalance = 4,
    enLogout = 5,
};

// General Methods

sClient ConvertLineToBankRecord(string Line, string Separator = "#//#")
{
    vector<string> vClientData = String::SplitString(Line, Separator);

    sClient stClientData;

    stClientData.AccountNumber = vClientData[0];
    stClientData.PinCode = vClientData[1];
    stClientData.Name = vClientData[2];
    stClientData.Phone = vClientData[3];
    stClientData.AccountBalance = stod(vClientData[4]);

    return stClientData;
}

string ConvertRecordToLine(sClient &ClientData, string Separator = "#//#")
{
    string Line = ClientData.AccountNumber + Separator;
    Line += ClientData.PinCode + Separator;
    Line += ClientData.Name + Separator;
    Line += ClientData.Phone + Separator;
    Line += to_string(ClientData.AccountBalance);

    return Line;
}

bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{

    fstream MyFile;
    MyFile.open(FileName, ios::in); // read Mode

    if (MyFile.is_open())
    {
        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLineToBankRecord(Line);
            if (Client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }
        }

        MyFile.close();
    }
    return false;
}

void ReadClientData(sClient &Client)
{
    Client.AccountNumber = MyInput::ReadString("Enter Account Number? ");
    while (ClientExistsByAccountNumber(Client.AccountNumber, FILENAME))
    {
        cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, Client.AccountNumber);
    }

    Client.PinCode = MyInput::ReadString("Enter PinCode? ");
    Client.Name = MyInput::ReadString("Enter Name? ");
    Client.Phone = MyInput::ReadString("Enter Phone? ");
    Client.AccountBalance = MyInput::ReadDouble("Enter AccountBalance? ");
}

void ReadLogInClient(sClient &Client)
{
    Client.AccountNumber = MyInput::ReadString("\nEnter Account Number? ");
    Client.PinCode = MyInput::ReadString("Enter Pin? ");
}

void FillVectorWithRecordsInFile(string FileName, vector<sClient> &vFileContent)
{
    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;

        while (getline(MyFile, Line))
        {
            vFileContent.push_back(ConvertLineToBankRecord(Line));
        }

        MyFile.close();
    }
}

void SaveVectorToFile(string FileName, vector<string> &vFileContent) // optional &
{
    fstream MyFile;
    MyFile.open(FileName, ios::out); // opens in write mode an thus clears the file

    if (MyFile.is_open())
    {
        for (string &Line : vFileContent)
        {
            if (Line != "")
                MyFile << Line << endl;
        }
        MyFile.close();
    }
}

void SaveBankRecordsToFile(string FileName, vector<sClient> vFileContent) // optional &
{
    fstream MyFile;
    MyFile.open(FileName, ios::out); // opens in write mode an thus clears the file
    string Line;

    if (MyFile.is_open())
    {
        for (sClient Client : vFileContent)
        {
            Line = ConvertRecordToLine(Client);
            if (Line != "")
                MyFile << Line << endl;
        }
        MyFile.close();
    }
}

void LoadFileLinesInVector(string FileName, vector<string> &vFileContent)
{
    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;

        while (getline(MyFile, Line))
        {
            vFileContent.push_back(Line);
        }

        MyFile.close();
    }
}

// 1 Quick Withdraw

void QuickWithdrawScreen()
{
    cout << "----------------------------------------------------\n";
    cout << "                 Quick Withdraw Screen                 ";
    cout << "\n----------------------------------------------------\n";
    cout << "        [1] 20                     [2] 50\n";
    cout << "        [3] 100                    [4] 200\n";
    cout << "        [5] 400                    [6] 600\n";
    cout << "        [7] 800                    [8] 1000\n";
    cout << "        [9] Exit                     ";
    cout << "\n----------------------------------------------------\n";
}

void GoBackToQuickWithdrawScreen()
{
    cout << "\n\nPress any key to continue...\n";
    system("pause>0");
    system("cls");
    QuickWithdraw();
}

enum enQuickWithdrawal
{
    en20 = 1,
    en50 = 2,
    en100 = 3,
    en200 = 4,
    en400 = 5,
    en600 = 6,
    en800 = 7,
    en1000 = 8,
    enExit = 9
};

enQuickWithdrawal ReadQuickWithdrawChoice()
{
    short choice;
    do
    {
        cout << "\nChoose how much to withdraw ? [1 to 8]? ";
        cin >> choice;
    } while (choice < 1 || choice > 9);
    return enQuickWithdrawal(choice);
}

double ReadQuickWithdrawAmount(enQuickWithdrawal choice)
{
    double WithdrawAmount;
    switch (choice)
    {
    case enQuickWithdrawal::en20:
    {
        WithdrawAmount = 20;
        break;
    }

    case enQuickWithdrawal::en50:
    {
        WithdrawAmount = 50;
        break;
    }

    case enQuickWithdrawal::en100:
    {
        WithdrawAmount = 100;
        break;
    }

    case enQuickWithdrawal::en200:
    {
        WithdrawAmount = 200;
        break;
    }

    case enQuickWithdrawal::en400:
    {
        WithdrawAmount = 400;
    }

    case enQuickWithdrawal::en600:
    {
        WithdrawAmount = 600;
        break;
    }

    case enQuickWithdrawal::en800:
    {
        WithdrawAmount = 800;
        break;
    }

    case enQuickWithdrawal::en1000:
    {
        WithdrawAmount = 1000;
        break;
    }

    case enQuickWithdrawal::enExit:
    {
        WithdrawAmount = 0;
        GoBackToMainMenu();
        break;
    }
    }
    return WithdrawAmount;
}

sClient WithdrawFromClient(sClient Client, double Withdraw)
{

    Client.AccountBalance -= Withdraw;

    return Client;
}

void AfterWithdrawUpdateFile(string FileName, sClient OldData, sClient UpdatedData)
{
    vector<string> vFileContent;
    string Record = ConvertRecordToLine(OldData);
    string UpdateTo = ConvertRecordToLine(UpdatedData);

    LoadFileLinesInVector(FileName, vFileContent);

    for (string &Line : vFileContent) // since we modify we need the ref
    {
        if (Line == Record)
        {
            Line = UpdateTo;
            break;
        }
    }

    SaveVectorToFile(FileName, vFileContent);
}

void QuickWithdraw()
{
    QuickWithdrawScreen();
    cout << "\nYour Balance is " << CurrentClient.AccountBalance;
    enQuickWithdrawal choice = ReadQuickWithdrawChoice();
    double WithdrawAmount = ReadQuickWithdrawAmount(choice);

    char Withdraw = 'n';
    cout << "\n\nAre you sure you want this transaction? y/n ? ";
    cin >> Withdraw;

    if (tolower(Withdraw) == 'y')
    {
        if (CurrentClient.AccountBalance < WithdrawAmount)
        {
            cout << "\n\nThe amount exceeds your balance, make another choice.";
            GoBackToQuickWithdrawScreen();
            return;
        }

        sClient NewClient = WithdrawFromClient(CurrentClient, WithdrawAmount);
        AfterWithdrawUpdateFile(FILENAME, CurrentClient, NewClient);
        CurrentClient.AccountBalance = NewClient.AccountBalance;
        cout << "\nDone Successfully. New balance is " << CurrentClient.AccountBalance << endl;
    }
}

// 2 Normal Withdraw

void NormalWithdrawScreen()
{
    cout << "----------------------------------------------------\n";
    cout << "                 Normal Withdraw Screen                 ";
    cout << "\n----------------------------------------------------\n";
}

void GoBackToNormalWithdrawScreen()
{
    cout << "\n\nPress any key to continue...\n";
    system("pause>0");
    system("cls");
    NormalWithdraw();
}

void ReadWithdrawAmount(sClient Client, double &Withdraw)
{

    do
    {
        Withdraw = MyInput::ReadDouble("\nEnter an amount multiple of 5's ? ");
    } while (!DateLibrary::IsDivisbleBy(Withdraw, 5));
}

void NormalWithdraw()
{
    NormalWithdrawScreen();
    cout << "\nYour Balance is " << CurrentClient.AccountBalance;

    char Withdraw = 'n';

    double WithdrawAmount;
    ReadWithdrawAmount(CurrentClient, WithdrawAmount);

    cout << "\n\nAre you sure you want this transaction? y/n ? ";
    cin >> Withdraw;

    if (tolower(Withdraw) == 'y')
    {
        if (CurrentClient.AccountBalance < WithdrawAmount)
        {
            cout << "\n\nThe amount exceeds your balance, make another choice.";
            GoBackToNormalWithdrawScreen();
            return;
        }

        sClient NewClient = WithdrawFromClient(CurrentClient, WithdrawAmount);
        AfterWithdrawUpdateFile(FILENAME, CurrentClient, NewClient);
        CurrentClient.AccountBalance = NewClient.AccountBalance;
        cout << "\nDone Successfully. New balance is " << CurrentClient.AccountBalance << endl;
    }
}

// 3 Deposit

void DepositScreen()
{
    cout << "\n----------------------------------------------------\n";
    cout << "                     Deposit Screen                     ";
    cout << "\n----------------------------------------------------\n";
}

sClient DepositToClient(sClient ClientData, double DepositAmount)
{
    ClientData.AccountBalance += DepositAmount;

    return ClientData;
}

void AfterDepositUpdateFile(string FileName, sClient OldData, sClient UpdatedData)
{
    vector<string> vFileContent;
    string Record = ConvertRecordToLine(OldData);
    string UpdateTo = ConvertRecordToLine(UpdatedData);

    LoadFileLinesInVector(FileName, vFileContent);

    for (string &Line : vFileContent) // since we modify we need the ref
    {
        if (Line == Record)
        {
            Line = UpdateTo;
            break;
        }
    }

    SaveVectorToFile(FileName, vFileContent);
}

void Deposit()
{
    DepositScreen();
    cout << "\nYour Balance is " << CurrentClient.AccountBalance;

    char Deposit = 'n';
    double DepositAmount;
    do
    {
        DepositAmount = MyInput::ReadDouble("\nPlease enter positive deposit amount? ");
    } while (DepositAmount <= 0);

    cout << "\n\nAre you sure you want this transaction? y/n ? ";
    cin >> Deposit;

    if (tolower(Deposit) == 'y')
    {
        sClient NewClient = DepositToClient(CurrentClient, DepositAmount);
        AfterDepositUpdateFile(FILENAME, CurrentClient, NewClient);
        CurrentClient.AccountBalance = NewClient.AccountBalance;
        cout << "\nDone Successfully. New balance is: " << CurrentClient.AccountBalance << endl;
    }
}

// 4 Check Balance

void CheckBalanceScreen()
{
    cout << "\n----------------------------------------------------\n";
    cout << "                  Check Balance Screen                     ";
    cout << "\n----------------------------------------------------\n";
}

void PrintBalance()
{
    CheckBalanceScreen();
    cout << "\nYour Balance is " << CurrentClient.AccountBalance;
}

// Main Menu and Project Handling

void GoBackToMainMenu()
{
    cout << "\n\nPress any key to go back to main menu...\n";
    system("pause>0");
    ShowATMMenu();
}

enAction ReadUserChoice()
{
    short choice;
    do
    {
        cout << "\nChoose what do you want to do? [1 to 5]? ";
        cin >> choice;
    } while (choice < 1 || choice > 5);
    return enAction(choice);
}

void DealWithUserChoice(enAction choice)
{
    system("cls");

    switch (choice)
    {
    case enAction::enQuickWithdraw:
    {
        QuickWithdraw();
        GoBackToMainMenu();
        break;
    }

    case enAction::enNormalWithdraw:
    {
        NormalWithdraw();
        GoBackToMainMenu();
        break;
    }

    case enAction::enDeposit:
    {
        Deposit();
        GoBackToMainMenu();
        break;
    }

    case enAction::enCheckBalance:
    {
        PrintBalance();
        GoBackToMainMenu();
        break;
    }

    case enAction::enLogout:
    {
        LogIn();
    }
    }
}

void ShowMainMenuScreen()
{
    cout << "\n=================================================\n";
    cout << "                ATM Main Menu Screen                 ";
    cout << "\n=================================================\n";
    cout << "            [1] Quick Withdraw.                    \n";
    cout << "            [2] Normal Withdraw.                   \n";
    cout << "            [3] Deposit.                           \n";
    cout << "            [4] Check Balance.                     \n";
    cout << "            [5] Logout.                            \n";
    cout << "\n=================================================\n";
}

void ShowATMMenu()
{
    enAction choice;
    system("cls");
    ShowMainMenuScreen();
    choice = ReadUserChoice();
    DealWithUserChoice(choice);
}

bool CheckClientToLogin(vector<sClient> &vClients, sClient Client)
{
    FillVectorWithRecordsInFile(FILENAME, vClients);
    for (sClient &ClientData : vClients)
    {
        if (ClientData.AccountNumber == Client.AccountNumber && ClientData.PinCode == Client.PinCode)
        {
            CurrentClient = ClientData;
            return true;
        }
    }

    return false;
}

void LogInScreen()
{
    cout << "\n=================================================\n";
    cout << "                    LogIn Screen                     ";
    cout << "\n=================================================\n";
}

void LogIn()
{
    system("cls");
    LogInScreen();

    sClient Client;
    vector<sClient> vClients;

    bool CorrectClient;

    do
    {
        ReadLogInClient(Client);
        CorrectClient = CheckClientToLogin(vClients, Client);
        if (!CorrectClient)
        {
            system("cls");
            LogInScreen();
            cout << "\nInvalid Account Number/ Pin Code!";
        }
    } while (!CorrectClient);

    ShowATMMenu();
}

int main()
{
    LogIn();
    return 0;
}