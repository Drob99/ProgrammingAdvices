// Change Record To Line
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

string ReadMyString(string message)
{
    string Sentence;
    cout << message;
    getline(cin, Sentence);
    return Sentence;
}

void ReadClientData(ClientData &ClientData)
{
    ClientData.AccountNumber = ReadMyString("Enter Account Number? ");
    ClientData.PinCode = ReadMyString("Enter PinCode? ");
    ClientData.Name = ReadMyString("Enter Name? ");
    ClientData.Phone = ReadMyString("Enter Phone? ");
    ClientData.AccountBalance = MyInput::ReadDouble("Enter AccountBalance? ");
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

int main()
{
    ClientData stClientData;
    cout << "Please Enter Client Data:\n\n";
    ReadClientData(stClientData);

    cout << "\nClient Record for Saving is:\n";
    cout << ConvertRecordToLine(stClientData);
}