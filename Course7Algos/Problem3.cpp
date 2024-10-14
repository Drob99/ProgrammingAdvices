// Sum Each row in Matrix in Array
# include "D:\Career\C++\AbuHadhoud\Libraries\MyFunctions.h"

using namespace std;

const short Rows = 3;
const short Cols = 3;

int SumOfMatrixRow(int Matrix[Rows][Cols], short RowNumber, short Cols)
{
    int Sum = 0;
    for (short i = 0; i < Cols; i++)
    {
        Sum += Matrix[RowNumber][i];
    }
    return Sum;
}

void SaveRowSumstoArray(int array[Rows], int Matrix[Rows][Cols], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        array[i] = SumOfMatrixRow(Matrix, i, Cols);
    }
}

void PrintMatrixRowSumsFromArray(int array[Rows], short Rows)
{
    for (short i = 0; i < Rows; i++)
    {
        cout << " Row " << i+1 << " Sum = " << array[i] << endl;
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
    int array[Rows];
    SaveRowSumstoArray(array, Matrix, Rows, Cols);
    PrintMatrixRowSumsFromArray(array, Rows);


}