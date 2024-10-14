// Show Clients
# include "D:\Career\C++\AbuHadhoud\Libraries\MyInput.h"
# include "D:\Career\C++\AbuHadhoud\Libraries\MyFunctions.h"
# include <string>
# include <cctype>
# include <iomanip>
# include <vector>
# include <fstream>

using namespace std;

struct ClientData
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

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

void ShowClientHeader(short NumOfClients)
{
    cout << "                                      Client List (" << NumOfClients << ") Client(s).                                \n";
    cout << "___________________________________________________________________________________________________________________\n\n";
    cout << "| Account Number  | Pin Code  | Client Name                                 | Phone           | Balance            \n";
    cout << "___________________________________________________________________________________________________________________\n\n";
}

void DisplayClientAsRow(ClientData &stClientData)
{
    cout << "| " << setw(15) << left << stClientData.AccountNumber << " | ";
    cout << setw(9) << left << stClientData.PinCode << " | ";
    cout << setw(43) << left << stClientData.Name << " | ";
    cout << setw(15) << left << stClientData.Phone << " | ";
    cout << stClientData.AccountBalance << "\n";
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

void ShowAllClientsInFile()
{
    vector <ClientData> vClientData;
    FillVectorWithRecordsInFile("D:\\Career\\C++\\AbuHadhoud\\Files\\MyFile2.txt", vClientData);

    ShowClientHeader(vClientData.size());
    
    for (ClientData &ClientData : vClientData)
    {
        DisplayClientAsRow(ClientData);
    }
    cout << "___________________________________________________________________________________________________________________\n\n";
}

int main()
{
    ShowAllClientsInFile();

    return 0;
}