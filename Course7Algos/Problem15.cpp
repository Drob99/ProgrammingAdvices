// Count Num in Matrix
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"

using namespace std;

int CountNumberInMatrix(int Number, int Matrix[3][3], short Rows, short Cols)
{
    int count;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] == Number)
                count++;
        }
    }
    return count;
}

int main()
{
    int Matrix[3][3] =
        {
            {9, 1, 12},
            {0, 9, 1},
            {0, 9, 9}};

    cout << "Matrix1:\n";
    Matrix::PrintMatrix(Matrix, 3, 3);

    int Number = MyInput::ReadNumber("\nEnter the number to count in matrix? ");

    int TimesRepeated = CountNumberInMatrix(Number, Matrix, 3, 3);

    cout << "\nNumber " << Number << " count in matrix is " << TimesRepeated;
}