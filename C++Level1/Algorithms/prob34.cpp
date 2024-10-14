//commission percentage

#include <iostream>

using namespace std;

float ReadTotalSales()
{
    float sales;
    cout << "Enter your sales: ";
    cin >> sales;

    return sales;
}

float GetComissionPercentage(float sales)
{

    if (sales >= 1000000)
    {
        return 0.01;
    }
    else if (sales >= 500000)
    {
        return 0.02;   
    }
    else if (sales >= 100000)
    {
        return 0.03;
    }
    else if (sales >= 50000)
    {
        return 0.05;
    }
    else
        return 0.00;
}

float CalculateTotalComissions(float sales)
{
    return sales * GetComissionPercentage(sales);

}

int main()
{
    float sales = ReadTotalSales();
    cout << endl << "Comission Percentage = " << GetComissionPercentage(sales);
    cout << endl << "Total Comissions = " << CalculateTotalComissions(sales);
 


    return 0;
}