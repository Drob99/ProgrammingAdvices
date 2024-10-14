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
const string USERS = "../Files/Users.txt";

void ShowBankMenu();
void Transactions();
void UsersMenu();
void LogIn();

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

struct sUser
{
    string UserName;
    string Password;
    int Permissions;
};

sUser CurrentUser;

enum enAction
{
    enShowClient = 1,
    enAddClient = 2,
    enDeleteClient = 3,
    enUpdateClient = 4,
    enFindClient = 5,
    enTransactions = 6,
    enManageUsers = 7,
    enLogout = 8
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

sUser ConvertLineToUser(string Line, string Separator = "#//#")
{
    vector<string> vUser = String::SplitString(Line, Separator);

    sUser User;

    User.UserName = vUser[0];
    User.Password = vUser[1];
    User.Permissions = stoi(vUser[2]);

    return User;
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

string ConvertUserToLine(sUser &User, string Separator = "#//#")
{
    string Line = User.UserName + Separator;
    Line += User.Password + Separator;
    Line += to_string(User.Permissions);

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

bool UserExistsByUserName(string UserName, string FileName)
{

    fstream MyFile;
    MyFile.open(FileName, ios::in); // read Mode

    if (MyFile.is_open())
    {
        string Line;
        sUser User;

        while (getline(MyFile, Line))
        {
            User = ConvertLineToUser(Line);
            if (User.UserName == UserName)
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

int ReadUserPermissions()
{
    int Permissions = 1;
    char FullAccess = 'n';
    cout << "\n\nDo you want to give full access? y/n? ";
    cin >> FullAccess;

    if (tolower(FullAccess) == 'y')
        return -1;

    else
    {
        char Input = 'n';

        cout << "\nDo you want to give access to :\n";

        cout << "\nShow Client List? y/n? ";
        cin >> Input;
        if (tolower(Input) == 'y')
            Permissions = Permissions | 1;

        cout << "\nAdd New Client? y/n? ";
        cin >> Input;
        if (tolower(Input) == 'y')
            Permissions = Permissions | 2;

        cout << "\nDelete Client? y/n? ";
        cin >> Input;
        if (tolower(Input) == 'y')
            Permissions = Permissions | 4;

        cout << "\nUpdate Client? y/n? ";
        cin >> Input;
        if (tolower(Input) == 'y')
            Permissions = Permissions | 8;

        cout << "\nFind Client? y/n? ";
        cin >> Input;
        if (tolower(Input) == 'y')
            Permissions = Permissions | 16;

        cout << "\nTransactions? y/n? ";
        cin >> Input;
        if (tolower(Input) == 'y')
            Permissions = Permissions | 32;

        cout << "\nManage Users? y/n? ";
        cin >> Input;
        if (tolower(Input) == 'y')
            Permissions = Permissions | 64;

        return Permissions;
    }
}

void ReadUserData(sUser &User, bool CheckUnique = true)
{
    User.UserName = MyInput::ReadString("\nEnter Username? ");
    if (CheckUnique)
    {
        while (UserExistsByUserName(User.UserName, USERS))
        {
            cout << "\nUser with [" << User.UserName << "] already exists, Enter another Userame? ";
            getline(cin >> ws, User.UserName);
        }
    }

    User.Password = MyInput::ReadString("\nEnter Password? ");

    User.Permissions = ReadUserPermissions();
}

void ReadLogInUser(sUser &User)
{
    User.UserName = MyInput::ReadString("\nEnter Username? ");
    User.Password = MyInput::ReadString("Enter Password? ");
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

void FillVectorWithUsersInFile(string FileName, vector<sUser> &vFileContent)
{
    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;

        while (getline(MyFile, Line))
        {
            vFileContent.push_back(ConvertLineToUser(Line));
        }

        MyFile.close();
    }
}

void DisplayClientAsRow(sClient &stClientData)
{
    cout << "| " << setw(15) << left << stClientData.AccountNumber << " | ";
    cout << setw(9) << left << stClientData.PinCode << " | ";
    cout << setw(43) << left << stClientData.Name << " | ";
    cout << setw(15) << left << stClientData.Phone << " | ";
    cout << stClientData.AccountBalance << "\n";
}

void DisplayBalanceAsRow(sClient &stClientData)
{
    cout << "| " << setw(15) << left << stClientData.AccountNumber << " | ";
    cout << setw(50) << left << stClientData.Name << " | ";
    cout << stClientData.AccountBalance << "\n";
}

void DisplayUserAsRow(sUser &User)
{
    cout << "| " << setw(30) << left << User.UserName << " | ";
    cout << setw(43) << left << User.Password << " | ";
    cout << setw(15) << left << User.Permissions << "\n";
}

void PrintClientData(sClient stClientData)
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

void PrintUserData(sUser User)
{
    cout << "\n\n----------------------------------------------------\n";
    cout << "                    User Data";
    cout << "\n----------------------------------------------------";
    cout << "\nUsername       : " << User.UserName;
    cout << "\nPassword       : " << User.Password;
    cout << "\nPermissions    : " << User.Permissions;
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

void SaveUsersToFile(string FileName, vector<sUser> vFileContent) // optional &
{
    fstream MyFile;
    MyFile.open(FileName, ios::out); // opens in write mode an thus clears the file
    string Line;

    if (MyFile.is_open())
    {
        for (sUser User : vFileContent)
        {
            Line = ConvertUserToLine(User);
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
    vector<sClient> vClientData;
    FillVectorWithRecordsInFile(FILENAME, vClientData);

    ShowClientHeader(vClientData.size());

    for (sClient &ClientData : vClientData)
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
    sClient stClientData;
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

bool FindClientByAccountNumber(vector<sClient> &vClientData, string AccountNumber, sClient &Client)
{
    FillVectorWithRecordsInFile(FILENAME, vClientData);
    for (sClient &ClientData : vClientData)
    {
        if (ClientData.AccountNumber == AccountNumber)
        {
            Client = ClientData;
            return true;
        }
    }

    return false;
}

void FindClient()
{
    string AccountNumber = MyInput::ReadString("Please Enter AccountNumber? ");

    vector<sClient> vClientData;
    sClient TargetClient;

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

void DeleteRecordFromFile(string FileName, sClient Client)
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
    vector<sClient> vClientData;
    sClient TargetClient;

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

sClient UpdateClientData(sClient ClientData)
{
    ClientData.PinCode = MyInput::ReadString("Enter PinCode? ");
    ClientData.Name = MyInput::ReadString("Enter Name? ");
    ClientData.Phone = MyInput::ReadString("Enter Phone? ");
    ClientData.AccountBalance = MyInput::ReadDouble("Enter AccountBalance? ");

    return ClientData;
}

void UpdateBankRecordToFile(string FileName, sClient OldData, sClient UpdatedData)
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
    vector<sClient> vClientData;
    sClient TargetClient;

    char Update;

    if (FindClientByAccountNumber(vClientData, AccountNumber, TargetClient))
    {
        PrintClientData(TargetClient);
        cout << "\n\nAre you sure you want to update this client? y/n ? ";
        cin >> Update;

        if (tolower(Update) == 'y')
        {
            sClient NewClient = UpdateClientData(TargetClient);
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
    string AccountNumber = MyInput::ReadString("Plaese Enter Account Number? ");
    vector<sClient> vClientData;
    sClient TargetClient;

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
        sClient NewClient = DepositToClient(TargetClient, DepositAmount);
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

void ReadWithdrawAmount(sClient Client, double &Withdraw)
{
    Withdraw = MyInput::ReadDouble("\n\nPlease enter withdraw amount? ");

    while (Client.AccountBalance < Withdraw)
    {
        cout << "\n\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance;
        Withdraw = ReadDouble("\n\nPlease enter another amount? ");
    }
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

void Withdraw()
{
    WithdrawScreen();

    string AccountNumber = MyInput::ReadString("Plaese Enter Account Number? ");
    vector<sClient> vClientData;
    sClient TargetClient;

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
        sClient NewClient = WithdrawFromClient(TargetClient, WithdrawAmount);
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
    vector<sClient> vClientData;
    FillVectorWithRecordsInFile(FILENAME, vClientData);
    double TotalBalance = 0;

    TotalBalancesHeader(vClientData.size());

    for (sClient &ClientData : vClientData)
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

// User Methods

// 1 Show All Users Methods

void ShowUserHeader(short NumOfUsers)
{
    cout << "                                      User List (" << NumOfUsers << ") User(s).                                \n";
    cout << "___________________________________________________________________________________________________________________\n\n";
    cout << "| Username                       | Password                                    | Permissions            \n";
    cout << "___________________________________________________________________________________________________________________\n\n";
}

void ShowAllUsersInFile()
{
    vector<sUser> vUsers;
    FillVectorWithUsersInFile(USERS, vUsers);

    ShowUserHeader(vUsers.size());

    for (sUser &User : vUsers)
    {
        DisplayUserAsRow(User);
    }
    cout << "___________________________________________________________________________________________________________________\n\n";
}

// 2 Add User Methods

void AddUserScreen()
{
    cout << "\n----------------------------------------------------\n";
    cout << "                   Add User Screen                    ";
    cout << "\n----------------------------------------------------\n";
}

void AddUserToFile()
{
    sUser User;
    ReadUserData(User);
    string UserString = ConvertUserToLine(User) + "\n";
    MyFiles::WriteLineToFile(USERS, UserString);
}

void AddUsers()
{
    char AddMore = 'y';

    do
    {

        cout << "\nAdding New User:\n\n";

        AddUserToFile();

        cout << "\nUser Added Successfully, do you want to add more users? ";
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');
}

// 5 Find User Methods

void FindUserScreen()
{
    cout << "\n----------------------------------------------------\n";
    cout << "                  Find User Screen                    ";
    cout << "\n----------------------------------------------------\n";
}

bool FindUserByUserName(vector<sUser> &vUsers, string UserName, sUser &User)
{
    FillVectorWithUsersInFile(USERS, vUsers);
    for (sUser &UserData : vUsers)
    {
        if (UserData.UserName == UserName)
        {
            User = UserData;
            return true;
        }
    }

    return false;
}

void FindUser()
{
    string UserName = MyInput::ReadString("Please Enter Username? ");

    vector<sUser> vUserData;
    sUser TargetUser;

    if (FindUserByUserName(vUserData, UserName, TargetUser))
        PrintUserData(TargetUser);
    else
    {
        cout << "\nUser with Account Number (" << UserName << ") Not Found!\n";
    }
}

// 3 Delete User Methods

void DeleteUserScreen()
{
    cout << "\n----------------------------------------------------\n";
    cout << "                  Delete User Screen                    ";
    cout << "\n----------------------------------------------------\n";
}

void DeleteUserFromFile(string FileName, sUser User)
{
    if (User.UserName == "Admin")
    {
        cout << "\nCannot Delete Admin.";
        return;
    }
    vector<string> vFileContent;
    string UserString = ConvertUserToLine(User);

    LoadFileLinesInVector(FileName, vFileContent);

    for (string &Line : vFileContent) // since we modify we need the ref
    {
        if (Line == UserString)
            Line = "";
    }

    SaveVectorToFile(FileName, vFileContent);
    cout << "\nUser Deleted Successfully.";
}

void DeleteUser()
{
    string UserName = MyInput::ReadString("Plaese Enter Username? ");
    vector<sUser> vUserData;
    sUser TargetUser;

    char Delete;

    if (FindUserByUserName(vUserData, UserName, TargetUser))
    {
        PrintUserData(TargetUser);
        cout << "\n\nAre you sure you want to delete this user? y/n ? ";
        cin >> Delete;

        if (tolower(Delete) == 'y')
        {
            DeleteUserFromFile(USERS, TargetUser);
        }
    }
    else
    {
        cout << "\nUser with Username (" << UserName << ") Not Found!\n";
    }
}

// 4 Update User Methods

void UpdateUserScreen()
{
    cout << "\n----------------------------------------------------\n";
    cout << "              Update User Info Screen                 ";
    cout << "\n----------------------------------------------------\n";
}

sUser UpdateUserData(sUser UserData)
{
    ReadUserData(UserData);

    return UserData;
}

void UpdateUserToFile(string FileName, sUser OldData, sUser UpdatedData)
{
    vector<string> vFileContent;
    string Record = ConvertUserToLine(OldData);
    string UpdateTo = ConvertUserToLine(UpdatedData);

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

void UpdateUser()
{
    string UserName = MyInput::ReadString("Plaese Enter Username? ");
    vector<sUser> vUserData;
    sUser TargetUser;

    char Update;

    if (FindUserByUserName(vUserData, UserName, TargetUser))
    {
        PrintUserData(TargetUser);
        cout << "\n\nAre you sure you want to update this User? y/n ? ";
        cin >> Update;

        if (tolower(Update) == 'y')
        {
            sUser NewUser = UpdateUserData(TargetUser);
            UpdateUserToFile(USERS, TargetUser, NewUser);
            cout << "\nUser Updated Successfully.";
        }
    }
    else
    {
        cout << "\nUser with Username (" << UserName << ") Not Found!\n";
    }
}

void UserMenu()
{
    cout << "\n=================================================\n";
    cout << "                  User Menu                  ";
    cout << "\n=================================================\n";
    cout << "            [1] List Users.                        \n";
    cout << "            [2] Add New User.                      \n";
    cout << "            [3] Delete User.                       \n";
    cout << "            [4] Update User.                       \n";
    cout << "            [5] Find User.                         \n";
    cout << "            [6] Main Menu.                           ";
    cout << "\n=================================================\n";
}

enum enUserMenu
{
    enListUsers = 1,
    enAddUser = 2,
    enDeleteUser = 3,
    enUpdateUser = 4,
    enFindUser = 5,
    enReturnToMainMenu = 6
};

enUserMenu ReadUserMenuChoice()
{
    short choice;
    cout << "\nChoose what do you want to do? [1 to 6]? ";
    cin >> choice;
    return enUserMenu(choice);
}

void GoBackToUsersMenu()
{
    cout << "\n\nPress any key to go back to users menu...\n";
    system("pause>0");
    UsersMenu();
}

void DealWithUserChoice(enUserMenu choice)
{
    system("cls");
    switch (choice)
    {
    case enUserMenu::enListUsers:
    {
        ShowAllUsersInFile();
        GoBackToUsersMenu();
        break;
    }

    case enUserMenu::enAddUser:
    {
        AddUserScreen();
        AddUsers();
        GoBackToUsersMenu();
        break;
    }

    case enUserMenu::enDeleteUser:
    {
        DeleteUserScreen();
        DeleteUser();
        GoBackToUsersMenu();
        break;
    }

    case enUserMenu::enUpdateUser:
    {
        UpdateUserScreen();
        UpdateUser();
        GoBackToUsersMenu();
        break;
    }

    case enUserMenu::enFindUser:
    {
        FindUserScreen();
        FindUser();
        GoBackToUsersMenu();
        break;
    }

    case enUserMenu::enReturnToMainMenu:
    {
        ShowBankMenu();
    }
    }
}

void UsersMenu()
{
    enUserMenu choice;
    system("cls");
    UserMenu();
    choice = ReadUserMenuChoice();
    DealWithUserChoice(choice);
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
    cout << "\nChoose what do you want to do? [1 to 8]? ";
    cin >> choice;
    return enAction(choice);
}

void DealWithUserChoice(enAction choice)
{
    system("cls");
    int CheckAccess = (int)pow(2, choice - 1);

    if (((CheckAccess & CurrentUser.Permissions) != 0) || choice == enAction::enLogout)
    {
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

        case enAction::enManageUsers:
        {
            UsersMenu();
            break;
        }

        case enAction::enLogout:
        {
            LogIn();
        }
        }
    }

    else
    {
        system("cls");
        cout << "-----------------------------------------------\n";
        cout << "Access Denied,\n";
        cout << "You do NOT have Permission To Do this,\n";
        cout << "Please contact your admin.\n";
        cout << "-----------------------------------------------\n";

        GoBackToMainMenu();
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
    cout << "            [7] Manage Users.                      \n";
    cout << "            [8] Logout      .                      \n";
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

bool CheckUserToLogin(vector<sUser> &vUsers, sUser User)
{
    FillVectorWithUsersInFile(USERS, vUsers);
    for (sUser &UserData : vUsers)
    {
        if (UserData.UserName == User.UserName && UserData.Password == User.Password)
        {
            CurrentUser = UserData;
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

    sUser User;
    vector<sUser> vUsers;

    bool CorrectUser;

    do
    {
        ReadLogInUser(User);
        CorrectUser = CheckUserToLogin(vUsers, User);
        if (!CorrectUser)
        {
            system("cls");
            LogInScreen();
            cout << "\nInvalid Username/ Password!";
        }
    } while (!CorrectUser);

    ShowBankMenu();
}

int main()
{
    LogIn();
    return 0;
}