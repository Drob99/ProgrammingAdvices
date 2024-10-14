#pragma once

#include <iostream>
#include <string>
#include "../Libraries/clsString.h"
#include <vector>
#include <fstream>

class clsCurrency
{
private:
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1
    }; // No AddNew
    enMode _Mode;

    string _Country;
    string _CurrencyCode;
    string _CurrencyName;
    float _Rate;

    static clsCurrency _ConvertLineToCurrencyObject(string Line, string Separator = "#//#")
    {
        vector<string> vCurrencyData = clsString::Split(Line, Separator);

        return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2],
                           stof(vCurrencyData[3]));
    }

    static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Separator = "#//#")
    {
        string strCurrencyRecord = "";
        strCurrencyRecord += Currency.Country() + Separator;
        strCurrencyRecord += Currency.CurrencyCode() + Separator;
        strCurrencyRecord += Currency.CurrencyName() + Separator;
        strCurrencyRecord += to_string(Currency.GetRate());

        return strCurrencyRecord;
    }

    static vector<clsCurrency> _LoadCurrencyDataFromFile()
    {
        vector<clsCurrency> vCurrencies;

        fstream MyFile;
        MyFile.open("../Course11OOP/Files/Currencies.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                vCurrencies.push_back(Currency);
            }

            MyFile.close();
        }
        return vCurrencies;
    }

    static void _SaveCurrencyDataToFile(vector<clsCurrency> vCurrencies)
    {
        fstream MyFile;
        MyFile.open("../Course11OOP/Files/Currencies.txt", ios::out);

        string DataLine;

        if (MyFile.is_open())
        {
            for (clsCurrency &C : vCurrencies)
            {
                DataLine = _ConvertCurrencyObjectToLine(C);
                MyFile << DataLine << endl;
            }

            MyFile.close();
        }
    }

    void _Update()
    {
        vector<clsCurrency> _vCurrencies;
        _vCurrencies = _LoadCurrencyDataFromFile();

        for (clsCurrency &C : _vCurrencies)
        {
            if (C.CurrencyCode() == this->CurrencyCode())
            {
                C = *this;
                break;
            }
        }

        _SaveCurrencyDataToFile(_vCurrencies);
    }

    static clsCurrency _GetEmptyCurrencyObject()
    {
        return clsCurrency(enMode::EmptyMode, "", "", "", 0);
    }

public:
    clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
    {
        _Mode = Mode;
        _Country = Country;
        _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrencyName;
        _Rate = Rate;
    }

    static vector<clsCurrency> GetAllUSDRates()
    {
        return _LoadCurrencyDataFromFile();
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    string Country()
    {
        return _Country;
    }

    string CurrencyCode()
    {
        return _CurrencyCode;
    }

    string CurrencyName()
    {
        return _CurrencyName;
    }

    float GetRate()
    {
        return _Rate;
    }

    void UpdateRate(float NewRate)
    {
        this->_Rate = NewRate;
        _Update();
    }

    static clsCurrency FindByCode(string CurrencyCode)
    {
        CurrencyCode = clsString::UpperAllString(CurrencyCode);

        fstream MyFile;

        MyFile.open("../Course11OOP/Files/Currencies.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                if (Currency.CurrencyCode() == CurrencyCode)
                {
                    MyFile.close();
                    return Currency;
                }
            }

            MyFile.close();
        }

        return _GetEmptyCurrencyObject();
    }

    static clsCurrency FindByCountry(string Country)
    {
        Country = clsString::UpperAllString(Country);

        fstream MyFile;

        MyFile.open("../Course11OOP/Files/Currencies.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                if (clsString::UpperAllString(Currency.Country()) == Country)
                {
                    MyFile.close();
                    return Currency;
                }
            }

            MyFile.close();
        }

        return _GetEmptyCurrencyObject();
    }

    static bool IsCurrencyExists(string CurrencyCode)
    {
        clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
        return (!C1.IsEmpty());
    }

    static vector<clsCurrency> GetCurrenciesList()
    {
        return _LoadCurrencyDataFromFile();
    }

    float ConvertToUSD(float Amount)
    {
        return (float)(Amount / GetRate());
    }

    float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
    {
        float AmountInUSD = ConvertToUSD(Amount);

        if (Currency2.CurrencyCode() == "USD")
            return AmountInUSD;

        return (float)(AmountInUSD * Currency2.GetRate());
    }
};