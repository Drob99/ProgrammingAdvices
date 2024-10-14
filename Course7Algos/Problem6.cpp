// 3x3 Ordered Matrix
#include "../Libraries/MyFunctions.h"
#include <iomanip>

using namespace std;

void FillOrderedMatrix(int Matrix[3][3], short Rows, short Cols)
{
    int Number = 1;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Matrix[i][j] = Number;
            Number++;
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
    int Matrix[3][3];

    FillOrderedMatrix(Matrix, 3, 3);
    cout << "The following is a 3x3 ordered matrix:\n";
    PrintMatrix(Matrix, 3, 3);

    // system("pause>0");

    return 0;
}