// Sum Each Col in Matrix in Array
#include "../Libraries/MyFunctions.h"

using namespace std;

const short Rows = 3;
const short Cols = 3;

void SaveColSumstoArray(int array[3], int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Cols; i++)
    {
        array[i] = MyFunctions::SumOfMatrixCol(Matrix, Rows, i);
    }
}

void PrintMatrixColSumsFromArray(int array[3], short Cols)
{
    for (short i = 0; i < Cols; i++)
    {
        cout << " Col " << i + 1 << " Sum = " << array[i] << endl;
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
    int array[Cols];
    SaveColSumstoArray(array, Matrix, Rows, Cols);
    PrintMatrixColSumsFromArray(array, Cols);
}