// Intersected Numbers in Matrices

# include "D:\Career\C++\AbuHadhoud\Libraries\MyInput.h"
# include "D:\Career\C++\AbuHadhoud\Libraries\MyFunctions.h"

using namespace std;

void PrintIntersectedNumbersInMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    cout << "\n ";
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix::NumberExistsInMatrix(Matrix1[i][j], Matrix2, Rows, Cols))
                cout << Matrix1[i][j] << "\t";
        }
    }
    cout << "\n";
}

int main()
{
    int Matrix1[3][3] = 
    {
        {77, 5, 12},
        {22, 20, 1},
        {1, 0, 9}
    };

    int Matrix2[3][3] = 
    {
        {5, 80, 90},
        {22, 77, 1},
        {10, 8, 33}
    };
    
    cout << "Matrix1:\n";
    Matrix::PrintMatrix(Matrix1, 3, 3);

    cout << "\nMatrix2:\n";
    Matrix::PrintMatrix(Matrix2, 3, 3);

    cout << "\nIntersected Numbers are: \n";
    PrintIntersectedNumbersInMatrices(Matrix1, Matrix2, 3, 3);

}