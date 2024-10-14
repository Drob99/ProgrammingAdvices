// Convert Line Data To Record
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include "../Libraries/MyFiles.h"
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;
const string FileName = "../Files/MyFile2.txt";

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
    getline(cin >> ws, Sentence);
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

void AddClientToFile()
{
    ClientData stClientData;
    ReadClientData(stClientData);
    string Client = ConvertRecordToLine(stClientData);
    MyFiles::WriteLineToFile(FileName, Client + "\n");
}

void AddClients()
{
    char AddMore = 'y';

    do
    {
        system("cls");

        cout << "\nAdding New Client:\n\n";

        AddClientToFile();

        cout << "\nClient Added Successfully, do you want to add more clients? ";
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');
}

int main()
{
    AddClients();
    return 0;
}