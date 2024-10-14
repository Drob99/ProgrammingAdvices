// Palindrome Matrix

# include "D:\Career\C++\AbuHadhoud\Libraries\MyInput.h"
# include "D:\Career\C++\AbuHadhoud\Libraries\MyFunctions.h"

using namespace std;

bool IsPalindromeMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j <= (Cols/2); j++)
        {
            if (Matrix[i][j] != Matrix[i][Cols-j-1])
                return false;
        }
    }
    return true;
}

void PrintPalindromeMatrix(int Matrix[3][3], short Rows, short Cols)
{
    bool Palindrome = IsPalindromeMatrix(Matrix, Rows, Cols);

    if (Palindrome)
        cout << "\nYes: Matrix is Palindrome";

    else
        cout << "\nNo: Matrix is NOT Palindrome";
}

int main()
{
    int Matrix1[3][3] = 
    {
        {1,  2, 1},
        {5, 5,  5},
        {7,  3,  7}
    };

    int Matrix2[3][3] = 
    {
        {1,  2,  1},
        {5,  5,  5},
        {7,  3,  8}
    };

    cout << "Matrix1:\n";
    Matrix::PrintMatrix(Matrix2, 3, 3);

    PrintPalindromeMatrix(Matrix2, 3, 3);

}