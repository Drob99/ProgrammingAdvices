#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
#include "clsString.h"

using namespace std;

class clsInputValidate
{
public:

    template <typename T> static bool IsNumberBetween (T Num, T From, T To)
    {
        return  Num >= From && Num <= To; 
    }

    static bool IsNumberBetween (short Num, short From, short To)
    {
        return  Num >= From && Num <= To; 
    }

    static bool IsNumberBetween (int Num, int From, int To)
    {
        return  Num >= From && Num <= To; 
    }

    static bool IsNumberBetween (float Num, float From, float To)
    {
        return  Num >= From && Num <= To; 
    }

    static bool IsNumberBetween (double Num, double From, double To)
    {
        return  Num >= From && Num <= To; 
    }

    static bool IsDateBetween (clsDate Date, clsDate From, clsDate To)
    {
        if (!clsDate::IsDate1BeforeDate2(Date, From) && !clsDate::IsDate1AfterDate2(Date, To))
            return true;
        if (!clsDate::IsDate1BeforeDate2(Date, To) && !clsDate::IsDate1AfterDate2(Date, From))
            return true;
        return false;
    }

    template <typename T> static T ReadNumber (string ErrorMessage = "Invalid Number, Enter again:\n")
    {
        T Number;

        while (!(cin >> Number)) // cin.fail()
        {
            // user didn't input a number
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n'); // std::numeric_limts<std::streamsize>::max()
            cout << ErrorMessage;
        }

        return Number;
    }

    template <typename T> static T ReadNumberBetween (T From, T To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        T Number = ReadNumber();

        while (!IsNumberBetween<T>(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadNumber();
        }

        return Number;
    }

    static short ReadShortNumber (string ErrorMessage = "Invalid Number, Enter again:\n")
    {
        short Number;

        while (!(cin >> Number)) // cin.fail()
        {
            // user didn't input a number
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n'); // std::numeric_limts<std::streamsize>::max()
            cout << ErrorMessage;
        }

        return Number;
    }

    static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        short Number = ReadShortNumber();

        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadShortNumber();
        }

        return Number;
    }

    static int ReadIntNumber (string ErrorMessage = "Invalid Number, Enter again:\n")
    {
        int Number;

        while (!(cin >> Number)) // cin.fail()
        {
            // user didn't input a number
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n'); // std::numeric_limts<std::streamsize>::max()
            cout << ErrorMessage;
        }

        return Number;
    }

    static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        int Number = ReadIntNumber();

        while (!IsNumberBetween(Number, From, To))
        {
            
            cout << ErrorMessage;
            Number = ReadIntNumber();
        }

        return Number;
    }

	static double ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		float Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadFloatNumberBetween(float From, float To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		float Number = ReadFloatNumber();

		while (!IsNumberBetween(Number, From, To)) 
        {
			cout << ErrorMessage;
			Number = ReadFloatNumber();
		}
		return Number;
	}


    static double ReadDblNumber (string ErrorMessage = "Invalid Number, Enter again:\n")
    {
        double Number;

        while (!(cin >> Number)) // cin.fail()
        {
            // user didn't input a number
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n'); // std::numeric_limts<std::streamsize>::max()
            cout << ErrorMessage;
        }

        return Number;
    }

    static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        double Number = ReadDblNumber();

        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadDblNumber();
        }

        return Number;
    }

    static bool IsValidDate (clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }

    static string ReadString(string message = "")
    {
        string Sentence;
        cout << message ;
        getline(cin >> ws, Sentence);
        return Sentence;
    }

};