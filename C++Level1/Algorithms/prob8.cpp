#include <iostream>

using namespace std;

enum enPassFail {Pass = 1, Fail = 2};

int ReadMark()
{
    int mark;

    cout << "Enter your mark: ";
    cin >> mark;

    return mark;
}

enPassFail CheckMark(int Mark)
{
    if (Mark >= 50)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;
}

void PrintResult(int Mark)
{
    if (CheckMark(Mark) == enPassFail::Pass)
    {
        cout << "\n You passed." << endl;
    }
    else
    {
        cout << "\n You failed." << endl;
    }
}

int main()
{
    PrintResult(ReadMark());
    return 0;    
}