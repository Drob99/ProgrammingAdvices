// Write Mode
#include <iostream>
#include <fstream>
#include "../Libraries/MyFiles.h"

using namespace std;

int main()
{
    MyFiles::WriteLineToFile("../Files/MyFile.txt", "Hi, this is the first line.\n");
    MyFiles::WriteLineToFile("../Files/MyFile.txt", "Hi, this is the second line.\n");
    MyFiles::WriteLineToFile("../Files/MyFile.txt", "Hi, this is the third line.\n");
    return 0;
}