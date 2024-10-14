// Two Dimensional Arrays
# include <iostream>
using namespace std;

void FillTable(int x[10][10], int Rows, int Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            x[i][j] = (i+1)  * (j+1);
        }
    }
}

void printTable(int x[10][10], int Rows, int Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            printf("%02d ", x[i][j]);
        }
        cout << endl;
    }
}

int main()
{
    // int x[Rows][Cols]
    int x[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%02d ", x[i][j]);
        }
        cout << endl;
    }

    cout << "--------------------------------\n\n";
    int MultiplicationTable[10][10], Rows = 10, Cols = 10;
    FillTable(MultiplicationTable, Rows, Cols);
    printTable(MultiplicationTable, Rows, Cols);

    return 0;
}