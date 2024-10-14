// Num Exists in Matrix

#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"

using namespace std;

bool NumberExistsInMatrix(int Number, int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] == Number)
                return true;
        }
    }
    return false;
}

void PrintIfNumExistsInMatrix(int Number, int Matrix[3][3], short Rows, short Cols)
{
    bool Exists = NumberExistsInMatrix(Number, Matrix, Rows, Cols);
    if (Exists)
        cout << "\nYes it is there.";
    else
        cout << "\nNo, it is NOT there.";
}

int main()
{
    int Matrix[3][3] =
        {
            {77, 5, 12},
            {22, 20, 1},
            {1, 0, 9}};

    cout << "Matrix1:\n";
    Matrix::PrintMatrix(Matrix, 3, 3);

    int Number = MyInput::ReadNumber("\nEnter the number to look for in matrix? ");

    PrintIfNumExistsInMatrix(Number, Matrix, 3, 3);
}