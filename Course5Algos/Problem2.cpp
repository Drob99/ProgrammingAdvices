# include <iostream>
# include <cmath>
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

void printIfPrime(int num){
    for (int i = 1; i <= num; i++)
    {
        if (CheckPrime(i) == Prime)
            cout << i << "\n";
    }
}

int main(){
    printIfPrime(ReadPositiveNumber("Enter a number: "));
}