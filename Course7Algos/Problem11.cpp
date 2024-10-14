// Equality Of Matrix

#include "../Libraries/MyFunctions.h"

using namespace std;

bool AreMatricesEqual(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
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

bool SumOfMatrixEqual(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    return MyFunctions::SumOfMatrix(Matrix1, 3, 3) == MyFunctions::SumOfMatrix(Matrix2, 3, 3);
}

void PrintMatrixEquality(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    bool equal = SumOfMatrixEqual(Matrix1, Matrix2, Rows, Cols);
    if (equal)
        cout << "\nYes: matrices are equal.";
    else
        cout << "\nNo: matrices are NOT equal.";
}

int main()
{
    MyFunctions::SeedRandom();

    int Matrix1[3][3], Matrix2[3][3];

    Matrix::FillRandomMatrix(Matrix1, 3, 3, 1, 10);
    Matrix::FillRandomMatrix(Matrix2, 3, 3, 1, 10);

    cout << "Matrix1:\n";
    Matrix::PrintFormattedMatrix(Matrix1, 3, 3);

    cout << "\nMatrix2:\n";
    Matrix::PrintFormattedMatrix(Matrix2, 3, 3);

    PrintMatrixEquality(Matrix1, Matrix2, 3, 3);
}