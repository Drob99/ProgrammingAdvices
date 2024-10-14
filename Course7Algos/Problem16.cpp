// Check Sparse Matrix

#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"

using namespace std;

bool IsSparseMatrix(int Matrix[3][3], short Rows, short Cols)
{
    // int Zeros = 0;
    // for (short i = 0; i < Rows; i++)
    // {
    //     for (short j = 0; j < Cols; j++)
    //     {
    //         if (Matrix[i][j] == 0)
    //             Zeros++;
    //         if (Zeros > (Rows * Cols / 2))
    //             return true;
    //     }
    // }

    return Matrix::CountNumberInMatrix(0, Matrix, 3, 3) >= (Rows * Cols / 2);
}

void PrintMatrixSparse(int Matrix[3][3], short Rows, short Cols)
{
    bool Sparse = IsSparseMatrix(Matrix, Rows, Cols);
    if (Sparse)
        cout << "\nYES: Matrix is Sparse.";
    else
        cout << "\nNO: Matrix is NOT sparse.";
}

int main()
{
    int Matrix1[3][3] =
        {
            {0, 0, 12},
            {0, 0, 1},
            {0, 0, 9}};

    int Matrix2[3][3] =
        {
            {10, 0, 12},
            {20, 15, 1},
            {0, 0, 9}};

    cout << "Matrix1:\n";
    Matrix::PrintMatrix(Matrix2, 3, 3);

    PrintMatrixSparse(Matrix2, 3, 3);
}