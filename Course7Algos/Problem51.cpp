// Update Client By Account Number
# include "D:\Career\C++\AbuHadhoud\Libraries\MyInput.h"
# include "D:\Career\C++\AbuHadhoud\Libraries\MyFunctions.h"
# include <string>
# include <cctype>
# include <iomanip>
# include <vector>
# include <fstream>

using namespace std;
const string FileName = "D:\\Career\\C++\\AbuHadhoud\\Files\\MyFile2.txt";

struct ClientData
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

ClientData UpdateClientData(ClientData ClientData)
{
    ClientData.PinCode = MyInput::ReadString("Enter PinCode? ");
    ClientData.Name = MyInput::ReadString("Enter Name? ");
    ClientData.Phone = MyInput::ReadString("Enter Phone? ");
    ClientData.AccountBalance = MyInput::ReadDouble("Enter AccountBalance? ");

    return ClientData;
}

ClientData ConvertLineToBankRecord(string Line, string Separator = "#//#")
{
    vector <string> vClientData = String::SplitString(Line, Separator);

    ClientData stClientData;

    stClientData.AccountNumber = vClientData[0];
    stClientData.PinCode = vClientData[1];
    stClientData.Name = vClientData[2];
    stClientData.Phone = vClientData[3];
    stClientData.AccountBalance = stod(vClientData[4]);

    return stClientData;
}

void LoadFileLinesInVector(string FileName, vector <string> &vFileContent)
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

void FillVectorWithRecordsInFile(string FileName, vector <ClientData> &vFileContent)
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

void SaveVectorToFile(string FileName, vector <string> &vFileContent) //optional &
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

void UpdateRecordToFile(string FileName, string Record, string UpdateTo)
{
    vector <string> vFileContent;

    LoadFileLinesInVector(FileName, vFileContent);

    for (string &Line : vFileContent) // since we modify we need the ref
    {
        if (Line == Record)
            Line = UpdateTo;
    }

    SaveVectorToFile(FileName, vFileContent);
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

bool FindClientByAccountNumber(vector<ClientData> &vClientData, string AccountNumber, ClientData &sClient)
{
    FillVectorWithRecordsInFile(FileName, vClientData);
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

void PrintClientData(ClientData stClientData)
{
    cout << "\nAccount Number : " << stClientData.AccountNumber;
    cout << "\nPin Code       : " << stClientData.PinCode;
    cout << "\nName           : " << stClientData.Name;
    cout << "\nPhone          : " << stClientData.Phone;
    cout << "\nAccount Balance: " << stClientData.AccountBalance;
}

void UpdateClient(string AccountNumber)
{
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
            UpdateRecordToFile(FileName, ConvertRecordToLine(TargetClient), ConvertRecordToLine(NewClient));
            cout << "\nClient Updated Successfully.";
        }

    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!\n";
    }

}

int main()
{
    string AccountNumber = MyInput::ReadString("Please Enter AccountNumber? ");
    UpdateClient(AccountNumber);
}