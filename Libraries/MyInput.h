#pragma once

# include <iostream>
# include <limits>
#include <string>

using namespace std;

namespace MyInput
{

    int ValidateNumber(istream& cin, string message)
    {
        int number;

        cout << message;
        cin >> number;
        while (cin.fail())
        {
            // user didn't input a number
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n'); // std::numeric_limts<std::streamsize>::max()
            cout << "Invalid Number, Enter a valid one: ";

            cin >> number;
        }

        return number;
    }
    
    string ReadName(string message)
    {
        string name;
        cout << message << "\n";
        getline(cin, name);
        return name;
    }

    string ReadString(string message)
    {
        string Sentence;
        cout << message ;
        getline(cin >> ws, Sentence);
        return Sentence;
    }
    
    char ReadChar(string message)
    {
        char Character;
        cout << message << "\n";
        cin >> Character;
        return Character;
    }

    int ReadNumber(string message = "Enter a number: ")
    {
        return ValidateNumber(cin, message);
    }

    short unsigned ReadAge()
    {
        short unsigned age;
        cout << "Enter your age: ";
        cin >> age;

        return age;

    }

    int ReadPositiveNumber(string message = "Enter a positive number: ")
    {
        int num;
        do
        {
            num = ValidateNumber(cin, message);
        } while (num < 0);
        
        return num;
    }

    float ReadPositiveFloatNumber(string message)
    {
        float num;
        do
        {
            cout << message << endl;
            cin >> num;
        } while (num < 0);
        
        return num;
    }

    int ReadNumberInRange(string message, int From, int To)
    {
        int num;
        do
        {
            cout <<  message;
            cin >> num;
        }while(num < From || num > To);

        return num;
    }

    string ReadPinCode(){
        string pin;

        cout << "Enter your PIN: ";
        cin >> pin;

        return pin;
    }

    double ReadDouble(string message)
{
    double Double;
    cout << message;
    cin >> Double;
    return Double;
}

    short ReadShort (string message)
{
    short input;
    cout << message;
    cin >> input;
    return input;
}

}