// Load Data to Vector
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void LoadDataFromFileToVector(string FileName, vector<string> &vFileContent) // & necessary
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

int main()
{
    vector<string> vFileContent;
    LoadDataFromFileToVector("../Files/MyFile.txt", vFileContent);

    for (string &Line : vFileContent) // optional & makes it faster
    {
        cout << Line << endl;
    }

    return 0;
}