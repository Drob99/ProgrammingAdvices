#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsCurrency.h"
#include "../Libraries/clsInputValidate.h"

class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:
    static float _ReadRate()
    {
        cout << "\nEnter New Rate: ";
        return clsInputValidate::ReadFloatNumber();
    }
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:";
        cout << "\n____________________________";
        cout << "\nCountry   : " << Currency.Country();
        cout << "\nCode      : " << Currency.CurrencyCode();
        cout << "\nName      : " << Currency.CurrencyName();
        cout << "\nRate (1$) : " << Currency.GetRate();
        cout << "\n____________________________\n";
    }

public:
    static void ShowUpdateCurrencyRateScreen()
    {
        clsScreen::_DrawScreenHeader("\tUpdate Currency Screen");

        string CurrencyCode = "";
        CurrencyCode = clsInputValidate::ReadString("\nPlease Enter Currency Code: ");

        while (!clsCurrency::IsCurrencyExists(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);

        clsUpdateCurrencyRateScreen::_PrintCurrency(Currency1);

        cout << "\nAre your sure you want to update the rate of this Currency y/n? ";
        char Answer = 'n';
        cin >> Answer;

        if (tolower(Answer) == 'y')
        {
            cout << "\nUpdate Currency Rate:";
            cout << "\n____________________\n";

            Currency1.UpdateRate(_ReadRate());

            cout << "\nCurrency Rate Updates Successfully :-)";

            clsUpdateCurrencyRateScreen::_PrintCurrency(Currency1);
        }
    }
};