#include <iostream>
using namespace std;

float ReadNumber(string message){
    cout << message << endl;
    float num;
    cin >> num;

    return num;
}
float addNumbers()
{
    float sum = 0.0, num = 0.0;
    int counter = 1;
    do
    {
        num = ReadNumber("Enter Number " + to_string(counter) + ": ");
        if (num == -99){
            cout << "\n";
            break;
        }
        
        sum += num;
        counter++;
    } while (num != -99);
    
    return sum;
}

int main()
{
    cout << addNumbers() << endl;
    return 0;
}