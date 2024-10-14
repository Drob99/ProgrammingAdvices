// Loan Installment Months

#include <iostream>

using namespace std;

float ReadPositiveNumber(string message)
{
    float num = 0;
    do
    {
        cout << message << endl;
        cin >> num;
    } while (num < 0);
    
    return num;
}

float totalMonths(float loanAmount, float monthlyInstallment)
{
    return (float) loanAmount / monthlyInstallment;
}

int main()
{
    float loanAmount = ReadPositiveNumber("Please enter loan amount: ");
    float monthlyInstallment = ReadPositiveNumber("Please enter monthly installment: ");

    cout << "\nTotal months = " << totalMonths(loanAmount, monthlyInstallment);
    cout <<endl;
    return 0;
}