#include <iostream>

using namespace std;

enum enNumberType {Odd = 1, Even = 2};

int ReadNumber(){
    int number;
    cout << "Enter a number: \n";
    cin >> number;
    return number;
}

enNumberType CheckNumberType(int number){
    if (number % 2 == 0)
        return enNumberType::Even;
    else
        return enNumberType::Odd;
}

void PrintNumberType(enNumberType numberType){
    if (numberType == enNumberType::Even)
        cout << "The number is even.\n";
    else
        cout << "The number is odd.\n";
}

int main()
{
    PrintNumberType(CheckNumberType(ReadNumber()));
    return 0;
}