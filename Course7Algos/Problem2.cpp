// Sum Each row in Matrix
#include "../Libraries/MyFunctions.h"

using namespace std;

const short Rows = 3;
const short Cols = 3;

int SumOfMatrixRow(int MatrixRow[Rows][Cols], short RowNumber, short Cols)
{
    int Sum = 0;
    for (short i = 0; i < Cols; i++)
    {
        Sum += MatrixRow[RowNumber][i];
    }
    return Sum;
}

void PrintMatrixRowSums(int Matrix[Rows][Cols], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        cout << " Row " << i + 1 << " Sum = " << SumOfMatrixRow(Matrix, i, Cols) << endl;
    }
}

int main()
{
    // seed random
    MyFunctions::SeedRandom();

    // declare a matrix
    int Matrix[Rows][Cols];

    // Filling with Random Numbers
    Matrix::FillRandomMatrix(Matrix, Rows, Cols, 1, 100);

    // Print the matrix
    cout << "The following is a 3x3 random matrix:\n";
    Matrix::PrintMatrix(Matrix, Rows, Cols);

    // Print each Row Sum
    cout << "\n\nThe following are the sum of each row in the matrix:\n";
    PrintMatrixRowSums(Matrix, Rows, Cols);
}