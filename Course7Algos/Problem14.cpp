// Check Scalar Matrix
# include "D:\Career\C++\AbuHadhoud\Libraries\MyFunctions.h"

using namespace std;

bool IsScalarMatrix(int Matrix[3][3], short Rows, short Cols)
{
    int FirstDiagElement = Matrix[0][0];
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (i == j && Matrix[i][j] != FirstDiagElement)
            {
                return false;
            }
            else if (i != j && Matrix[i][j] != 0)
                return false;
        }
    }

    return true;
}

void PrintMatrixScalar(int Matrix[3][3], short Rows, short Cols)
{
    bool identity = IsScalarMatrix(Matrix, Rows, Cols);
    if (identity)
        cout << "\nYES: Matrix is scalar.";
    else
        cout << "\nNO: Matrix is NOT scalar.";
}


int main()
{
    MyFunctions::SeedRandom();

    int Matrix[3][3] = {    {7, 0, 0}, 
                            {0, 7, 0},
                            {0, 0, 7}
                        };

    // Matrix::FillRandomMatrix(Matrix, 3, 3, 1, 10);

    cout << "Matrix1:\n";
    Matrix::PrintMatrix(Matrix, 3, 3);

    PrintMatrixScalar(Matrix, 3, 3);

}