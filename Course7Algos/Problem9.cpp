// Print Middle Row and Col of Matrix
# include "D:\Career\C++\AbuHadhoud\Libraries\MyFunctions.h"

using namespace std;


void PrintMiddleRowOfMatrix(int Matrix[3][3], int Row, int Col)
{
    int MiddleRow = Row / 2;

    for (int i = 0; i < Col; i++)
    {
        printf(" %02d\t", Matrix[MiddleRow][i]);
    }
    cout << "\n";
}

void PrintMiddleColOfMatrix(int Matrix[3][3], int Row, int Col)
{
    int MiddleCol = Col / 2;

    for (int i = 0; i < Row; i++)
    {
        printf(" %02d\t", Matrix[i][MiddleCol]);
    }
    cout << "\n";
}

int main()
{
    MyFunctions::SeedRandom();

    int Matrix[3][3];

    Matrix::FillRandomMatrix(Matrix, 3, 3, 1, 10);

    cout << "Matrix1:\n";
    Matrix::PrintFormattedMatrix(Matrix, 3, 3);

    cout << "Middle Row of Matrix1 is:\n";
    PrintMiddleRowOfMatrix(Matrix, 3, 3);

    cout << "Middle Col of Matrix1 is:\n";
    PrintMiddleColOfMatrix(Matrix, 3, 3);
}