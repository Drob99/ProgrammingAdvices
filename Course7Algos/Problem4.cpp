// Sum Each Col in Matrix
# include "D:\Career\C++\AbuHadhoud\Libraries\MyFunctions.h"

using namespace std;

const short Rows = 3;
const short Cols = 3;

int SumOfMatrixCol(int Matrix[Rows][Cols], short Rows, short ColNumber)
{
    int Sum = 0;
    for (short i = 0; i < Rows; i++)
    {
        Sum += Matrix[i][ColNumber];
    }
    return Sum;
}

void PrintMatrixColSums(int Matrix[Rows][Cols], short Rows, short Cols)
{
    for (short i = 0; i < Cols; i++)
    {
        cout << " Col " << i+1 << " Sum = " << SumOfMatrixCol(Matrix, Rows, i) << endl;
    }
}

int main()
{
    //seed random
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
    PrintMatrixColSums(Matrix, Rows, Cols);


}