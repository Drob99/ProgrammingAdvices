// Min & Max In Matrix

#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"

using namespace std;

int MinNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
{
    int Min = INT_MAX;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Min = (Matrix[i][j] < Min) ? Matrix[i][j] : Min;
        }
    }
    return Min;
}

int MaxNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
{
    int Max = INT_MIN;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Max = (Matrix[i][j] > Max) ? Matrix[i][j] : Max;
        }
    }

    return Max;
}

int main()
{
    int Matrix1[3][3] =
        {
            {77, 5, 12},
            {22, 20, 6},
            {14, 3, 9}};

    cout << "Matrix1:\n";
    Matrix::PrintMatrix(Matrix1, 3, 3);

    cout << "\nMinimum Number is: " << MinNumberInMatrix(Matrix1, 3, 3);
    cout << "\n\nMax Number is: " << MaxNumberInMatrix(Matrix1, 3, 3);
}