// Find Client By Account Number
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

void PrintClientData(ClientData stClientData)
{
    cout << "\nAccount Number : " << stClientData.AccountNumber;
    cout << "\nPin Code       : " << stClientData.PinCode;
    cout << "\nName           : " << stClientData.Name;
    cout << "\nPhone          : " << stClientData.Phone;
    cout << "\nAccount Balance: " << stClientData.AccountBalance;
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

// receives vector & returns if found
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



int main()
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