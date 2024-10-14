#pragma once

# include <iostream>
# include <string>
# include <vector>
# include <fstream>
# include "MyInput.h"
# include "MyFunctions.h"

using namespace std;
using namespace MyInput;
using namespace MyFunctions;

namespace MyFiles
{
    void WriteLineToFile(string FileName, string Line)
    {
        fstream MyFile;

        MyFile.open(FileName, ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << Line;

            MyFile.close();
        }
    }

    void PrintFileContent(string FileName)
    {
        fstream MyFile;

        MyFile.open(FileName, ios::in);

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

    void LoadDataFromFileToVector(string FileName, vector <string> &vFileContent)
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

    void DeleteRecordFromFile(string FileName, string Record)
    {
        vector <string> vFileContent;

        LoadDataFromFileToVector(FileName, vFileContent);

        for (string &Line : vFileContent) // since we modify we need the ref
        {
            if (Line == Record)
                Line = "";
        }

        SaveVectorToFile(FileName, vFileContent);
    }

    void UpdateRecordToFile(string FileName, string Record, string UpdateTo)
    {
        vector <string> vFileContent;

        LoadDataFromFileToVector(FileName, vFileContent);

        for (string &Line : vFileContent) // since we modify we need the ref
        {
            if (Line == Record)
                Line = UpdateTo;
        }

        SaveVectorToFile(FileName, vFileContent);
    }

    
}

