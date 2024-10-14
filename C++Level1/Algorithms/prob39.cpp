// pay remainder

#include <iostream>

using namespace std;

float ReadPositiveNumber(string message)
{
    float num;
    do
    {
        cout << message << endl;
        cin >> num;
    } while (num < 0);
    
    return num;
}

float CalculateChange(float totalBill, float totalCashPaid){
    return totalCashPaid - totalBill;
}

int main()
{
    float totalBill = ReadPositiveNumber("Please enter total bill: ");
    float totalCashPaid = ReadPositiveNumber("Please Enter Total Cash Paid: ");

    cout << endl;
    cout << "Total Bill = " << totalBill << endl;
    cout << "Total Cash Paid = " << totalCashPaid << endl;

    cout << "******************************\n";
    cout << "Remainder = " << CalculateChange(totalBill, totalCashPaid) << endl;
    return 0;
}