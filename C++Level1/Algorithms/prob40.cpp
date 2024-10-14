// service tax

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

float totalBillAfterServiceAndTax(float totalBill){
    totalBill *= 1.1;
    totalBill *= 1.16;

    return totalBill;
}



int main()
{
    float totalBill = ReadPositiveNumber("Enter the amount of money: ");

    cout << endl;
    cout << "Total Bill = " << totalBill << endl;
    cout << "Total Bill After Service Fee and Sales Tax = " << totalBillAfterServiceAndTax(totalBill) << endl;
    return 0;
}