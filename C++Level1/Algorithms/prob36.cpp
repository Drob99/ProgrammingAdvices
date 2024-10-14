//simple calc
#include <iostream>

using namespace std;

enum enOperationType { Add = '+', Subtract = '-', Multiply = '*', Divide = '/'};

float ReadNumber(string message){
    float num = 0;
    cout << message << endl;
    cin >> num;

    return num;
}

enOperationType ReadOpType(){
    char op = '+';

    cout << "Enter operator: \n";
    cin >> op;
    return (enOperationType) op;
}

float Calculate(float num1, float num2, enOperationType opType){
    switch (opType)
    {
    case Add:
        return num1 + num2;
    case Subtract:   
        return num1 - num2;
    case Multiply:   
        return num1 * num2;
    case Divide:
        return num1 / num2;
    default:
        cout << "Invalid operator";
        return -1;
    }
}

int main()
{
    float num1 = ReadNumber("Please enter the first number: ");
    float num2 = ReadNumber("Please enter the second number: ");

    enOperationType opType = ReadOpType();

    cout << endl << "Result = " << Calculate(num1, num2, opType) << endl;

    return 0;
}