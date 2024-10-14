// Convert Line Data To Record
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>

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
    vector<string> vClientData = String::SplitString(Line, Separator);

    ClientData stClientData;

    stClientData.AccountNumber = vClientData[0];
    stClientData.PinCode = vClientData[1];
    stClientData.Name = vClientData[2];
    stClientData.Phone = vClientData[3];
    stClientData.AccountBalance = stod(vClientData[4]);

    return stClientData;
}

void PrintClientData(ClientData stClientData)
{
    cout << "\nAccount Number : " << stClientData.AccountNumber;
    cout << "\nPin Code       : " << stClientData.PinCode;
    cout << "\nName           : " << stClientData.Name;
    cout << "\nPhone          : " << stClientData.Phone;
    cout << "\nAccount Balance: " << stClientData.AccountBalance;
}

int main()
{
    ClientData stClientData;
    string LineRecord = "A150#//#1234#//#Omar Bahaeldin Abdalla#//#0570281148#//#5270.000000";

    cout << "\nLine Record is:\n";
    cout << LineRecord << endl;

    stClientData = ConvertLineToBankRecord(LineRecord);
    cout << "\nThe following is the extracted client record:\n";
    PrintClientData(stClientData);
}