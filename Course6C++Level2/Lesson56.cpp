// Load Data to Vector
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void SaveVectorToFile(string FileName, vector<string> &vFileContent) // optional &
{
    fstream MyFile;
    MyFile.open(FileName, ios::out); // read

    if (MyFile.is_open())
    {
        for (string &Line : vFileContent) // optional &
        {
            if (Line != "")
                MyFile << Line << endl;
        }
        MyFile.close();
    }
}

int main()
{
    vector<string> vFileContent{"Ali", "Shadi", "Maher", "Fadi"};

    SaveVectorToFile("../Files/MyFile.txt", vFileContent);

    return 0;
}