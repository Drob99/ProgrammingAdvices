// piggy bank collector

#include <iostream>

using namespace std;

struct stPiggyBankContent {
    int pennies, nickels, dimes, quarters, halfDollars, dollars;
};

stPiggyBankContent ReadPiggyBankContent(){
    stPiggyBankContent piggyBank;

    cout << "Enter number of pennies: ";
    cin >> piggyBank.pennies;

    cout << "Enter number of nickels: ";
    cin >> piggyBank.nickels;

    cout << "Enter number of dimes: ";
    cin >> piggyBank.dimes;

    cout << "Enter number of quarters: ";
    cin >> piggyBank.quarters;

    cout << "Enter number of half dollars: ";
    cin >> piggyBank.halfDollars;

    cout << "Enter number of dollars: ";
    cin >> piggyBank.dollars;

    return piggyBank;
}

int CalculateTotalPennies(stPiggyBankContent piggyBank){
    return (piggyBank.pennies * 1 + 5 * piggyBank.nickels + 10 * piggyBank.dimes + 25 * piggyBank.quarters + 50 * piggyBank.halfDollars + piggyBank.dollars * 100);
}

int main()
{
    int totalPennies = CalculateTotalPennies(ReadPiggyBankContent());
    cout << endl << "Total pennies = " << totalPennies << endl;
    cout << endl << "Total Dollars = " << (float) totalPennies / 100 << endl;

    return 0;
}