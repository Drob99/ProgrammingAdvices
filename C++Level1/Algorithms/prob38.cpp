#include <iostream>
#include <string>
#include <math.h>

using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2};

int ReadPositiveNumber(string message)
{
    int num;
    do
    {
        cout << message << endl;
        cin >> num;
    } while (num < 0);
    
    return num;
}

enPrimeNotPrime CheckPrime(int num){
    int M = round(num / 2);
    if (num == 0  || num == 1)
        return NotPrime;

    for (int i = 2; i <= M; i++){
        if (num % i == 0)
            return NotPrime;
    }

    return Prime;
}

void printNumberType(int num){
    switch (CheckPrime(num))
    {
        case Prime:
            cout << "The number is prime.\n";
            break;
        case NotPrime:
            cout << "The number is not prime.\n";
            break;
    }
}

int main()
{
    printNumberType(ReadPositiveNumber("Please enter a positive number: "));
    return 0;
}