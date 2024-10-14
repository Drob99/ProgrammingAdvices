// Monthly Loan Installment

#include <iostream>

using namespace std;

float ReadPositiveNumber(string message)
{
    int num = 0;
    do
    {
        cout << message << endl;
        cin >> num;
    } while (num < 0);
    
    return num;
}

float monthlyInstallment(float loanAmount, float numOfMonths)
{
    return (float) loanAmount / numOfMonths;
}

int main()
{
    float loanAmount = ReadPositiveNumber("Please enter loan amount: ");
    float numOfMonths = ReadPositiveNumber("Please enter number of months: ");

    cout << "\nMonthly Installment = " << monthlyInstallment(loanAmount, numOfMonths);
    cout <<endl;
    return 0;
}