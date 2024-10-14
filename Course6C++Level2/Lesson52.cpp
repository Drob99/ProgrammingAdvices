// Write Mode
# include <iostream>
# include <fstream>
# include "D:\Career\C++\AbuHadhoud\Libraries\MyFiles.h"

using namespace std;

int main()
{
    MyFiles::WriteLineToFile("D:/Career/C++/AbuHadhoud/Files/MyFile.txt", "Hi, this is the first line.\n");
    MyFiles::WriteLineToFile("D:/Career/C++/AbuHadhoud/Files/MyFile.txt", "Hi, this is the second line.\n");
    MyFiles::WriteLineToFile("D:/Career/C++/AbuHadhoud/Files/MyFile.txt", "Hi, this is the third line.\n"); 
    return 0;
}