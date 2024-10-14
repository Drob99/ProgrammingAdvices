// Sum Of Matrix
# include "D:\Career\C++\AbuHadhoud\Libraries\MyFunctions.h"

using namespace std;

int SumOfMatrix(int Matrix[3][3], short Rows, short Cols)
{
    int Sum = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Sum += Matrix[i][j];
        }
    }
    return Sum;
}


int main()
{
    MyFunctions::SeedRandom();

    int Matrix[3][3];

    Matrix::FillRandomMatrix(Matrix, 3, 3, 1, 10);

    cout << "Matrix1:\n";
    Matrix::PrintFormattedMatrix(Matrix, 3, 3);

    cout << "\nSum of Matrix1 is: " << SumOfMatrix(Matrix, 3, 3);

}