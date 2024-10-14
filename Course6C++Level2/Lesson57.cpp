// Delete Record From File
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void PrintFileContent(string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in); // read

    if (MyFile.is_open())
    {
        string Line;

        while (getline(MyFile, Line))
        {
            cout << Line << endl;
        }

        MyFile.close();
    }
}

void LoadDataFromFileToVector(string FileName, vector<string> &vFileContent)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in); // read

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

void SaveVectorToFile(string FileName, vector<string> &vFileContent)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out); // read

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

void DeleteRecordFromFile(string FileName, string Record)
{

    vector<string> vFileContent;
    LoadDataFromFileToVector(FileName, vFileContent);

    for (string &Line : vFileContent)
    {
        if (Line == Record)
            Line = "";
    }

    SaveVectorToFile(FileName, vFileContent);
}

int main()
{
    cout << "File Content Before Delete.\n";
    PrintFileContent("../Files/MyFile.txt");

    DeleteRecordFromFile("../Files/MyFile.txt", "Shadi");

    cout << "\n\nFile Content After Delete.\n";
    PrintFileContent("../Files/MyFile.txt");

    return 0;
}