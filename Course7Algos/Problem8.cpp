// Multiply 2 matrices
# include "D:\Career\C++\AbuHadhoud\Libraries\MyFunctions.h"

using namespace std;

    void PrintFormattedMatrix(int Matrix[3][3], short Rows, short Cols)
{
    
    for (short i = 0; i < Rows; i++)
    {
        printf(" ");
        for (short j = 0; j < Cols; j++)
        {
            printf("%02d\t", Matrix[i][j]);
        }
        cout << "\n";
    }
}

void MultiplyMatrices(int ResultMatrix[3][3], int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            ResultMatrix[i][j] = Matrix1[i][j] * Matrix2[i][j];
        }
    }
}


int main()
{
    MyFunctions::SeedRandom();

    int Matrix1[3][3], Matrix2[3][3];

    Matrix::FillRandomMatrix(Matrix1, 3, 3, 1, 10);
    Matrix::FillRandomMatrix(Matrix2, 3, 3, 1, 10);

    cout << "Matrix1:\n";
    PrintFormattedMatrix(Matrix1, 3, 3);

    cout << "\nMatrix2:\n";
    PrintFormattedMatrix(Matrix2, 3, 3);

    int ResultMatrix[3][3];

    MultiplyMatrices(ResultMatrix, Matrix1, Matrix2, 3, 3);
    cout << "\nResults:\n";
    PrintFormattedMatrix(ResultMatrix, 3, 3);

}