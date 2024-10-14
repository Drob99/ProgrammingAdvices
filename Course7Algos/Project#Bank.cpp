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

void ShowBankMenu();
void Transactions();

struct ClientData
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

enum enAction
{
    enShowClient = 1,
    enAddClient = 2,
    enDeleteClient = 3,
    enUpdateClient = 4,
    enFindClient = 5,
    enTransactions = 6,
    enLogout = 7
};

// General Methods

ClientData ConvertLineToBankRecord(string Line, string Separator = "#//#")
{
    vector<string> vClientData = String::SplitString(Line, Separator);

    ClientData stClientData;

    stClientData.AccountNumber = vClientData[0];
    stClientData.PinCode = vClientData[1];
    stClientData.Name = vClientData[2];
    stClientData.Phone = vClientData[3];
    stClientData.AccountBalance = stod(vClientData[4]);

    return stClientData;
}

string ConvertRecordToLine(ClientData &ClientData, string Separator = "#//#")
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

    vector<ClientData> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in); // read Mode

    if (MyFile.is_open())
    {
        string Line;
        ClientData Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLineToBankRecord(Line);
            if (Client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }
            vClients.push_back(Client);
        }

        MyFile.close();
    }
    return false;
}

void ReadClientData(ClientData &Client)
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

void FillVectorWithRecordsInFile(string FileName, vector<ClientData> &vFileContent)
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

void DisplayClientAsRow(ClientData &stClientData)
{
    cout << "| " << setw(15) << left << stClientData.AccountNumber << " | ";
    cout << setw(9) << left << stClientData.PinCode << " | ";
    cout << setw(43) << left << stClientData.Name << " | ";
    cout << setw(15) << left << stClientData.Phone << " | ";
    cout << stClientData.AccountBalance << "\n";
}

void DisplayBalanceAsRow(ClientData &stClientData)
{
    cout << "| " << setw(15) << left << stClientData.AccountNumber << " | ";
    cout << setw(50) << left << stClientData.Name << " | ";
    cout << stClientData.AccountBalance << "\n";
}

void PrintClientData(ClientData stClientData)
{
    cout << "\n\n----------------------------------------------------\n";
    cout << "                    Client Data";
    cout << "\n----------------------------------------------------";
    cout << "\nAccount Number : " << stClientData.AccountNumber;
    cout << "\nPin Code       : " << stClientData.PinCode;
    cout << "\nName           : " << stClientData.Name;
    cout << "\nPhone          : " << stClientData.Phone;
    cout << "\nAccount Balance: " << stClientData.AccountBalance;
    cout << "\n----------------------------------------------------\n";
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

void SaveBankRecordsToFile(string FileName, vector<ClientData> vFileContent) // optional &
{
    fstream MyFile;
    MyFile.open(FileName, ios::out); // opens in write mode an thus clears the file
    string Line;

    if (MyFile.is_open())
    {
        for (ClientData Client : vFileContent)
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

// Show All Clients Methods

void ShowClientHeader(short NumOfClients)
{
    cout << "                                      Client List (" << NumOfClients << ") Client(s).                                \n";
    cout << "___________________________________________________________________________________________________________________\n\n";
    cout << "| Account Number  | Pin Code  | Client Name                                 | Phone           | Balance            \n";
    cout << "___________________________________________________________________________________________________________________\n\n";
}

void ShowAllClientsInFile()
{
    vector<ClientData> vClientData;
    FillVectorWithRecordsInFile(FILENAME, vClientData);

    ShowClientHeader(vClientData.size());

    for (ClientData &ClientData : vClientData)
    {
        DisplayClientAsRow(ClientData);
    }
    cout << "___________________________________________________________________________________________________________________\n\n";
}

// Add Client Methods

void AddClientScreen()
{
    cout << "\n----------------------------------------------------\n";
    cout << "                   Add Client Screen                    ";
    cout << "\n----------------------------------------------------\n";
}

void AddClientToFile()
{
    ClientData stClientData;
    ReadClientData(stClientData);
    string Client = ConvertRecordToLine(stClientData) + "\n";
    MyFiles::WriteLineToFile(FILENAME, Client);
}

void AddClients()
{
    char AddMore = 'y';

    do
    {

        cout << "\nAdding New Client:\n\n";

        AddClientToFile();

        cout << "\nClient Added Successfully, do you want to add more clients? ";
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');
}

// Find Client Methods

void FindClientScreen()
{
    cout << "\n----------------------------------------------------\n";
    cout << "                  Find Client Screen                    ";
    cout << "\n----------------------------------------------------\n";
}

bool FindClientByAccountNumber(vector<ClientData> &vClientData, string AccountNumber, ClientData &sClient)
{
    FillVectorWithRecordsInFile(FILENAME, vClientData);
    for (ClientData &ClientData : vClientData)
    {
        if (ClientData.AccountNumber == AccountNumber)
        {
            sClient = ClientData;
            return true;
        }
    }

    return false;
}

void FindClient()
{
    string AccountNumber = MyInput::ReadString("Please Enter AccountNumber? ");

    vector<ClientData> vClientData;
    ClientData TargetClient;

    if (FindClientByAccountNumber(vClientData, AccountNumber, TargetClient))
        PrintClientData(TargetClient);
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!\n";
    }
}

// Delete Client Methods

void DeleteClientScreen()
{
    cout << "\n----------------------------------------------------\n";
    cout << "                  Delete Client Screen                    ";
    cout << "\n----------------------------------------------------\n";
}

void DeleteRecordFromFile(string FileName, ClientData Client)
{
    vector<string> vFileContent;
    string Record = ConvertRecordToLine(Client);

    LoadFileLinesInVector(FileName, vFileContent);

    for (string &Line : vFileContent) // since we modify we need the ref
    {
        if (Line == Record)
            Line = "";
    }

    SaveVectorToFile(FileName, vFileContent);
}

void DeleteClient()
{
    string AccountNumber = MyInput::ReadString("Plaese Enter Account Number? ");
    vector<ClientData> vClientData;
    ClientData TargetClient;

    char Delete;

    if (FindClientByAccountNumber(vClientData, AccountNumber, TargetClient))
    {
        PrintClientData(TargetClient);
        cout << "\n\nAre you sure you want to delete this client? y/n ? ";
        cin >> Delete;

        if (tolower(Delete) == 'y')
        {
            DeleteRecordFromFile(FILENAME, TargetClient);
            cout << "\nClient Deleted Successfully.";
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!\n";
    }
}

// Update Client Methods

void UpdateClientScreen()
{
    cout << "\n----------------------------------------------------\n";
    cout << "              Update Client Info Screen                 ";
    cout << "\n----------------------------------------------------\n";
}

ClientData UpdateClientData(ClientData ClientData)
{
    ClientData.PinCode = MyInput::ReadString("Enter PinCode? ");
    ClientData.Name = MyInput::ReadString("Enter Name? ");
    ClientData.Phone = MyInput::ReadString("Enter Phone? ");
    ClientData.AccountBalance = MyInput::ReadDouble("Enter AccountBalance? ");

    return ClientData;
}

void UpdateBankRecordToFile(string FileName, ClientData OldData, ClientData UpdatedData)
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

void UpdateClient()
{
    string AccountNumber = MyInput::ReadString("Plaese Enter Account Number? ");
    vector<ClientData> vClientData;
    ClientData TargetClient;

    char Update;

    if (FindClientByAccountNumber(vClientData, AccountNumber, TargetClient))
    {
        PrintClientData(TargetClient);
        cout << "\n\nAre you sure you want to update this client? y/n ? ";
        cin >> Update;

        if (tolower(Update) == 'y')
        {
            ClientData NewClient = UpdateClientData(TargetClient);
            UpdateBankRecordToFile(FILENAME, TargetClient, NewClient);
            cout << "\nClient Updated Successfully.";
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!\n";
    }
}

// Transactions Methods

void TransactionMenu()
{
    cout << "\n=================================================\n";
    cout << "                  Transactions Menu                  ";
    cout << "\n=================================================\n";
    cout << "            [1] Deposit.                           \n";
    cout << "            [2] Withdraw.                          \n";
    cout << "            [3] Total Balances.                    \n";
    cout << "            [4] Main Menu.                           ";
    cout << "\n=================================================\n";
}

enum enTransactionMenu
{
    enDeposit = 1,
    enWithdraw = 2,
    enTotalBalances = 3,
    enMainMenu = 4
};

// Deposit Methods

void DepositScreen()
{
    cout << "\n----------------------------------------------------\n";
    cout << "                     Deposit Screen                     ";
    cout << "\n----------------------------------------------------\n";
}

ClientData DepositToClient(ClientData ClientData, double DepositAmount)
{
    ClientData.AccountBalance += DepositAmount;

    return ClientData;
}

void AfterDepositUpdateFile(string FileName, ClientData OldData, ClientData UpdatedData)
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
    string AccountNumber = MyInput::ReadString("Plaese Enter Account Number? ");
    vector<ClientData> vClientData;
    ClientData TargetClient;

    while (!FindClientByAccountNumber(vClientData, AccountNumber, TargetClient))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = MyInput::ReadString("Please Enter AccountNumber? ");
    }

    char Deposit = 'n';

    PrintClientData(TargetClient);
    double DepositAmount = MyInput::ReadDouble("\nPlease enter deposit amount? ");

    cout << "\n\nAre you sure you want this transaction? y/n ? ";
    cin >> Deposit;

    if (tolower(Deposit) == 'y')
    {
        ClientData NewClient = DepositToClient(TargetClient, DepositAmount);
        UpdateBankRecordToFile(FILENAME, TargetClient, NewClient);
        cout << "\nNew balance for account number: " << NewClient.AccountNumber << " is " << NewClient.AccountBalance << endl;
    }
}

// Withdraw Methods

void WithdrawScreen()
{
    cout << "\n----------------------------------------------------\n";
    cout << "                  Withdraw Screen                       ";
    cout << "\n----------------------------------------------------\n";
}

void ReadWithdrawAmount(ClientData Client, double &Withdraw)
{
    Withdraw = MyInput::ReadDouble("\n\nPlease enter withdraw amount? ");

    while (Client.AccountBalance < Withdraw)
    {
        cout << "\n\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance;
        Withdraw = ReadDouble("\n\nPlease enter another amount? ");
    }
}

ClientData WithdrawFromClient(ClientData Client, double Withdraw)
{
    Client.AccountBalance -= Withdraw;

    return Client;
}

void AfterWithdrawUpdateFile(string FileName, ClientData OldData, ClientData UpdatedData)
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

void Withdraw()
{
    WithdrawScreen();

    string AccountNumber = MyInput::ReadString("Plaese Enter Account Number? ");
    vector<ClientData> vClientData;
    ClientData TargetClient;

    while (!FindClientByAccountNumber(vClientData, AccountNumber, TargetClient))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = MyInput::ReadString("Please Enter AccountNumber? ");
    }

    char Withdraw = 'n';

    PrintClientData(TargetClient);

    double WithdrawAmount;
    ReadWithdrawAmount(TargetClient, WithdrawAmount);

    cout << "\n\nAre you sure you want this transaction? y/n ? ";
    cin >> Withdraw;

    if (tolower(Withdraw) == 'y')
    {
        ClientData NewClient = WithdrawFromClient(TargetClient, WithdrawAmount);
        UpdateBankRecordToFile(FILENAME, TargetClient, NewClient);
        cout << "\nNew balance for account number: " << NewClient.AccountNumber << " is " << NewClient.AccountBalance << endl;
    }
}

// TotalBalances Methods

void TotalBalancesHeader(short NumOfClients)
{
    cout << "___________________________________________________________________________________________________________________\n\n";
    cout << "                                Balances List (" << NumOfClients << ") Client(s).                                \n";
    cout << "___________________________________________________________________________________________________________________\n\n";
    cout << "| " << setw(15) << left << "Account Number  | ";
    cout << setw(50) << left << "Client Name  ";
    cout << " | Balance\n";
}

void ShowTotalBalances()
{
    vector<ClientData> vClientData;
    FillVectorWithRecordsInFile(FILENAME, vClientData);
    double TotalBalance = 0;

    TotalBalancesHeader(vClientData.size());

    for (ClientData &ClientData : vClientData)
    {
        DisplayBalanceAsRow(ClientData);
        TotalBalance += ClientData.AccountBalance;
    }
    cout << "___________________________________________________________________________________________________________________\n";
    cout << setw(50) << "Total Balances = " << TotalBalance;
}

// Transactions

enTransactionMenu ReadTransactionChoice()
{
    short choice;
    cout << "\nChoose what do you want to do? [1 to 4]? ";
    cin >> choice;
    return enTransactionMenu(choice);
}

void GoBackToTransactionsMenu()
{
    cout << "\n\nPress any key to go back to transactions menu...\n";
    system("pause>0");
    Transactions();
}

void DealWithTransactionChoice(enTransactionMenu choice)
{

    switch (choice)
    {
    case enTransactionMenu::enDeposit:
        system("cls");
        Deposit();
        GoBackToTransactionsMenu();
        break;

    case enTransactionMenu::enWithdraw:
        system("cls");
        Withdraw();
        GoBackToTransactionsMenu();
        break;

    case enTransactionMenu::enTotalBalances:
        system("cls");
        ShowTotalBalances();
        GoBackToTransactionsMenu();
        break;

    case enTransactionMenu::enMainMenu:
        ShowBankMenu();
    }
}

void Transactions()
{
    enTransactionMenu choice;
    system("cls");
    TransactionMenu();
    choice = ReadTransactionChoice();
    DealWithTransactionChoice(choice);
}

// End Methods

void EndScreen()
{
    cout << "\n----------------------------------------------------\n";
    cout << "                   Program Ends :-)                     ";
    cout << "\n----------------------------------------------------\n";
}

// Main Menu and Project Handling

void GoBackToMainMenu()
{
    cout << "\n\nPress any key to go back to main menu...\n";
    system("pause>0");
    ShowBankMenu();
}

enAction ReadUserChoice()
{
    short choice;
    cout << "\nChoose what do you want to do? [1 to 7]? ";
    cin >> choice;
    return enAction(choice);
}

void DealWithUserChoice(enAction choice)
{
    system("cls");
    switch (choice)
    {
    case enAction::enShowClient:
    {
        ShowAllClientsInFile();
        GoBackToMainMenu();
        break;
    }

    case enAction::enAddClient:
    {
        AddClientScreen();
        AddClients();
        GoBackToMainMenu();
        break;
    }

    case enAction::enDeleteClient:
    {
        DeleteClientScreen();
        DeleteClient();
        GoBackToMainMenu();
        break;
    }

    case enAction::enUpdateClient:
    {
        UpdateClientScreen();
        UpdateClient();
        GoBackToMainMenu();
        break;
    }

    case enAction::enFindClient:
    {
        FindClientScreen();
        FindClient();
        GoBackToMainMenu();
        break;
    }

    case enAction::enTransactions:
    {
        Transactions();
        break;
    }

    case enAction::enLogout:
    {
        EndScreen();
        break;
    }
    }
}

void ShowMainMenuScreen()
{
    cout << "\n=================================================\n";
    cout << "                    Main Menu Screen                 ";
    cout << "\n=================================================\n";
    cout << "            [1] Show Client List.                  \n";
    cout << "            [2] Add New Client.                    \n";
    cout << "            [3] Delete Client.                     \n";
    cout << "            [4] Update Client Info.                \n";
    cout << "            [5] Find Client.                       \n";
    cout << "            [6] Transactions.                      \n";
    cout << "            [7] Exit.                                ";
    cout << "\n=================================================\n";
}

void ShowBankMenu()
{
    enAction choice;
    system("cls");
    ShowMainMenuScreen();
    choice = ReadUserChoice();
    DealWithUserChoice(choice);
}

int main()
{
    ShowBankMenu();
    return 0;
}
