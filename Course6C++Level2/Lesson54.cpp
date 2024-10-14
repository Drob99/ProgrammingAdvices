// Read Mode
#include <iostream>
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

int main()
{

    PrintFileContent("../Files/MyFile.txt"); // Write Mode

    return 0;
}