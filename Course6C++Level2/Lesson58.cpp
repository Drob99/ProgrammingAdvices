// Update Record In File
# include <iostream>
# include <vector>
# include <string>
# include <fstream>

using namespace std;

void PrintFileContent(string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in); // read

    if (MyFile.is_open())
    {
        string Line;

        while(getline(MyFile, Line))
        {
            cout << Line << endl;
        }

        MyFile.close();
    }
}

void LoadDataFromFileToVector(string FileName, vector<string> & vFileContent)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in); // read

    if (MyFile.is_open())
    {
        string Line;

        while(getline(MyFile, Line))
        {
            vFileContent.push_back(Line);
        }

        MyFile.close();
    }
}

void SaveVectorToFile(string FileName, vector<string> & vFileContent)
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

void UpdateRecordToFile(string FileName, string Record, string UpdateTo)
{
    
    vector <string> vFileContent;
    LoadDataFromFileToVector(FileName, vFileContent);

    for (string &Line : vFileContent)
    {
        if (Line == Record)
            Line = UpdateTo;
    }

    SaveVectorToFile(FileName, vFileContent);
}

int main()
{
    cout << "File Content Before Delete.\n";
    PrintFileContent("D:/Career/C++/AbuHadhoud/Files/MyFile.txt");


    UpdateRecordToFile("D:/Career/C++/AbuHadhoud/Files/MyFile.txt", "Ali", "Omar");

    cout << "\n\nFile Content After Delete.\n";
    PrintFileContent("D:/Career/C++/AbuHadhoud/Files/MyFile.txt");  

    return 0;
}