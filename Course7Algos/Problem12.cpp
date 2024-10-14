// check Typical Matrix

#include "../Libraries/MyFunctions.h"

using namespace std;

bool AreMatricesTypical(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] != Matrix2[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

void PrintMatrixTypical(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    bool equal = AreMatricesTypical(Matrix1, Matrix2, Rows, Cols);
    if (equal)
        cout << "\nYes: matrices are typical.";
    else
        cout << "\nNo: matrices are NOT typical.";
}

int main()
{
    MyFunctions::SeedRandom();

    int Matrix1[3][3], Matrix2[3][3];

    MyFunctions::FillRandomMatrix(Matrix1, 3, 3, 1, 10);
    MyFunctions::FillRandomMatrix(Matrix2, 3, 3, 1, 10);

    cout << "Matrix1:\n";
    MyFunctions::PrintFormattedMatrix(Matrix1, 3, 3);

    cout << "\nMatrix2:\n";
    MyFunctions::PrintFormattedMatrix(Matrix2, 3, 3);

    PrintMatrixTypical(Matrix1, Matrix2, 3, 3);
}