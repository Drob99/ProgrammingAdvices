// Transpose Matrix
#include "../Libraries/MyFunctions.h"

using namespace std;

void TransposeMatrix(int TransposedMatrix[3][3], int Matrix[3][3], int Rows, int Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            TransposedMatrix[i][j] = Matrix[j][i];
        }
    }
}

int main()
{
    int Matrix[3][3];

    Matrix::FillOrderedMatrix(Matrix, 3, 3);
    cout << "The following is a 3x3 ordered matrix:\n";
    Matrix::PrintMatrix(Matrix, 3, 3);

    int TransposedMatrix[3][3];
    TransposeMatrix(TransposedMatrix, Matrix, 3, 3);
    cout << "\n\nThe following is the transposed matrix:\n";
    Matrix::PrintMatrix(TransposedMatrix, 3, 3);

    // system("pause>0");

    return 0;
}