// 3x3 Random Matrix
# include "D:\Career\C++\AbuHadhoud\Libraries\MyFunctions.h"
# include <iomanip>

using namespace std;

void FillRandomMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Matrix[i][j] = MyFunctions::RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
    
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << Matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main()
{
    MyFunctions::SeedRandom();

    int Matrix[3][3];

    FillRandomMatrix(Matrix, 3, 3);
    cout << "The following is a 3x3 random matrix:\n";
    PrintMatrix(Matrix, 3, 3);

    // system("pause>0");

    return 0;
}