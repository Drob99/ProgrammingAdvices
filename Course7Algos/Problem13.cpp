// Check Identity Matrix
#include "../Libraries/MyFunctions.h"

using namespace std;

bool IsIdentityMatrix(int Matrix[3][3], short Rows, short Cols)
{
    //! Takes Storage
    // int IdentityMatrix[Rows][Cols];

    //  fill identity Matrix
    // for (short i = 0; i < Rows; i++)
    // {
    //     for (short j = 0; j < Cols; j++)
    //     {
    //         if (i==j)
    //             IdentityMatrix[i][j] = 1;
    //         else
    //             IdentityMatrix[i][j] = 0;
    //     }
    // }

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (i == j && Matrix[i][j] != 1)
            {
                return false;
            }
            else if (i != j && Matrix[i][j] != 0)
                return false;
        }
    }

    return true;
}

void PrintMatrixEqualToIdentity(int Matrix[3][3], short Rows, short Cols)
{
    bool identity = IsIdentityMatrix(Matrix, Rows, Cols);
    if (identity)
        cout << "\nYES: Matrix is identity.";
    else
        cout << "\nNO: Matrix is NOT identity.";
}

int main()
{
    MyFunctions::SeedRandom();

    int Matrix[3][3] = {{1, 0, 0},
                        {0, 1, 0},
                        {0, 0, 1}};

    // Matrix::FillRandomMatrix(Matrix, 3, 3, 1, 10);

    cout << "Matrix1:\n";
    Matrix::PrintMatrix(Matrix, 3, 3);

    PrintMatrixEqualToIdentity(Matrix, 3, 3);
}